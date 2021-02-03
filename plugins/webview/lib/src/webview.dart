import 'package:flutter/widgets.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/gestures.dart';

import 'platform_interface.dart';
import 'webview_linux.dart';

/// A web view widget for showing html content.
class WebView extends StatefulWidget {
  /// Creates a new web view.
  ///
  /// The web view can be controlled using a `WebViewController` that is passed to the
  /// `onWebViewCreated` callback once the web view is created.
  ///
  /// The `javascriptMode` and `autoMediaPlaybackPolicy` parameters must not be null.
  const WebView({
    Key key,
    this.uri,
  }) : super(key: key);

  static WebViewPlatform platform = LinuxWebView();

  final String uri;

  @override
  State<StatefulWidget> createState() => _WebViewState();
}

class _WebViewState extends State<WebView> {
  @override
  Widget build(BuildContext context) {
    return WebView.platform.build(
      context: context,
      creationParams: _creationParamsFromWidget(widget),
    );
  }
}

CreationParams _creationParamsFromWidget(WebView widget) {
  return CreationParams(
    uri: widget.uri,
  );
}
