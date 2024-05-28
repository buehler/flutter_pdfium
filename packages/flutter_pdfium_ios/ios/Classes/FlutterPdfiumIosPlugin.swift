import Flutter
import UIKit

public class FlutterPdfiumIosPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "flutter_pdfium_ios", binaryMessenger: registrar.messenger())
    let instance = FlutterPdfiumIosPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
    switch call.method {
    default:
      result(FlutterMethodNotImplemented)
    }
  }
}
