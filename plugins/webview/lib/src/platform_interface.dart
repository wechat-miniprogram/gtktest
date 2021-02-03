import 'package:flutter/widgets.dart';

class CreationParams {
  CreationParams({
    this.uri,
  });

  final String uri;

  @override
  String toString() {
    return '$runtimeType(uri: $uri)';
  }
}

abstract class WebViewPlatform {
  Widget build({
    int id,
    BuildContext context,
    CreationParams creationParams,
  });
}
