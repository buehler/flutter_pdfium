import 'dart:async';

class Lazy<T> {
  static final _cache = Expando();

  final T Function() _factory;
  final void Function(T)? _valueDispose;

  const Lazy(this._factory, [this._valueDispose]);

  bool get isInitialized => _cache[this] != null;

  T call() {
    _cache[this] ??= _factory();
    return _cache[this] as T;
  }

  void dispose() {
    if (!isInitialized) {
      return;
    }

    _valueDispose?.call(this());
    _cache[this] = null;
  }
}

class AsyncLazy<T> {
  static final _cache = Expando();

  final FutureOr<T> Function() _factory;
  final FutureOr Function(T)? _valueDispose;

  const AsyncLazy(this._factory, [this._valueDispose]);

  bool get isInitialized => _cache[this] != null;

  FutureOr<T> call() async {
    _cache[this] ??= await _factory();
    return _cache[this] as T;
  }

  Future dispose() async {
    if (!isInitialized) {
      return;
    }

    await _valueDispose?.call(await this());
    _cache[this] = null;
  }
}
