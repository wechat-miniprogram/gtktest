#ifndef WEBVIEW_VIEW_FACTORY_PRIVATE_H_
#define WEBVIEW_VIEW_FACTORY_PRIVATE_H_

#include <flutter_linux/flutter_linux.h>

G_BEGIN_DECLS

G_DECLARE_FINAL_TYPE(WebViewViewFactory,
                     webview_view_factory,
                     WEBVIEW,
                     VIEW_FACTORY,
                     GObject)

WebViewViewFactory* webview_view_factory_new(FlBinaryMessenger* messenger);

G_END_DECLS

#endif  // WEBVIEW_VIEW_FACTORY_PRIVATE_H_
