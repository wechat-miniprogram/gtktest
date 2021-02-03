import 'platform_interface.dart';

/// A [WebViewPlatformController] that uses a method channel to control the webview.
class MethodChannelWebViewPlatform {
  static Map<String, dynamic> creationParamsToMap(
      CreationParams creationParams) {
    return <String, dynamic>{
      'uri': creationParams.uri,
    };
  }
}
