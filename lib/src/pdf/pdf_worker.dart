import 'dart:async';
import 'dart:isolate';

import 'package:flutter/foundation.dart';

import '../utils/lazy.dart';

class PdfWorker {
  PdfWorker._(this._receivePort, this._sendPort);
  final ReceivePort _receivePort;
  final SendPort _sendPort;
  bool _isDisposed = false;

  static Future<PdfWorker> create({String? debugName}) async {
    final receivePort = ReceivePort();
    await Isolate.spawn(
      _workerEntry,
      receivePort.sendPort,
      debugName: debugName,
    );
    return PdfWorker._(receivePort, await receivePort.first as SendPort);
  }

  static void _workerEntry(SendPort sendPort) {
    final receivePort = ReceivePort();
    sendPort.send(receivePort.sendPort);
    late final StreamSubscription sub;
    sub = receivePort.listen((message) async {
      switch (message) {
        case _ComputeCall(:final sendPort, :final callback):
          sendPort.send(await callback());
          break;
        default:
          sub.cancel();
          receivePort.close();
      }
    });
  }

  Future<R> compute<R>(FutureOr<R> Function() callback) async {
    if (_isDisposed) {
      throw StateError('Worker is already disposed');
    }
    final sendPort = ReceivePort();
    _sendPort.send(_ComputeCall(sendPort.sendPort, callback));
    return await sendPort.first as R;
  }

  void dispose() {
    try {
      _isDisposed = true;
      _sendPort.send(null);
      _receivePort.close();
    } catch (e) {
      debugPrint('Failed to dispose worker (possible double-dispose?): $e');
    }
  }
}

class _ComputeCall<R> {
  _ComputeCall(this.sendPort, this.callback);
  final SendPort sendPort;
  final FutureOr<R> Function() callback;
}

void _disposeWorker(PdfWorker worker) => worker.dispose();

const pdfWorker = AsyncLazy(PdfWorker.create, _disposeWorker);

extension PdfWorkerExtension on AsyncLazy<PdfWorker> {
  Future<R> compute<R>(FutureOr<R> Function() callback) async =>
      await (await this()).compute(callback);
}
