#include "web_view_platform_view.h"

#include <webkit2/webkit2.h>

struct _WebViewPlatformView {
  FlPlatformView parent_instance;

  int64_t view_identifier;

  WebKitWebView* webview;
};

G_DEFINE_TYPE(WebViewPlatformView,
              webview_platform_view,
              fl_platform_view_get_type())

static void webview_platform_view_dispose(GObject* object) {
  WebViewPlatformView* self = WEBVIEW_PLATFORM_VIEW(object);

  g_clear_object(&self->webview);

  G_OBJECT_CLASS(webview_platform_view_parent_class)->dispose(object);
}

static GtkWidget* webview_platform_view_get_view(
    FlPlatformView* platform_view) {
  g_return_val_if_fail(WEBVIEW_IS_PLATFORM_VIEW(platform_view), nullptr);
  WebViewPlatformView* self = WEBVIEW_PLATFORM_VIEW(platform_view);
  return GTK_WIDGET(self->webview);
}

static void webview_platform_view_class_init(WebViewPlatformViewClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = webview_platform_view_dispose;

  FL_PLATFORM_VIEW_CLASS(klass)->get_view = webview_platform_view_get_view;
}

static void webview_platform_view_init(WebViewPlatformView* platform_view) {}

WebViewPlatformView* webview_platform_view_new(FlBinaryMessenger* messenger,
                                               int64_t view_identifier,
                                               FlValue* args) {
  if (fl_value_get_type(args) != FL_VALUE_TYPE_MAP) {
    g_error("WebView creation params expected a map");
    return nullptr;
  }

  WebKitSettings* settings = webkit_settings_new();
  webkit_settings_set_enable_developer_extras(settings, TRUE);
  WebKitWebView* webview = WEBKIT_WEB_VIEW(webkit_web_view_new_with_settings(settings));

  FlValue* uri = fl_value_lookup_string(args, "uri");
  if (uri && fl_value_get_type(uri) == FL_VALUE_TYPE_STRING) {
    printf("URI: %s\n", fl_value_get_string(uri));
    webkit_web_view_load_uri(webview, fl_value_get_string(uri));
  }

  WebViewPlatformView* view = WEBVIEW_PLATFORM_VIEW(
      g_object_new(webview_platform_view_get_type(), nullptr));
  view->webview = webview;

  WebKitWebInspector* inspector = webkit_web_view_get_inspector(webview);
  webkit_web_inspector_show(inspector);

  view->view_identifier = view_identifier;
  return view;
}
