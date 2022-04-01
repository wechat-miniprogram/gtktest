import 'package:flutter/foundation.dart';
import 'package:flutter/gestures.dart';
import 'package:flutter/services.dart';
import 'package:flutter/widgets.dart';

import 'method_channel.dart';
import 'platform_interface.dart';

class LinuxWebView implements WebViewPlatform {
  @override
  Widget build({
    int id,
    BuildContext context,
    CreationParams creationParams,
  }) {
    return GtkView(
      viewType: 'plugins.flutter.io/webview',
      creationParams:
          MethodChannelWebViewPlatform.creationParamsToMap(creationParams),
      creationParamsCodec: const StandardMessageCodec(),
    );
  }
}
