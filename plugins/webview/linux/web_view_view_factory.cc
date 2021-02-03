#include "web_view_view_factory.h"

#include "web_view_platform_view.h"

static void webview_view_factory_fl_platform_view_factory_iface_init(
    FlPlatformViewFactoryInterface* iface);

struct _WebViewViewFactory {
  GObject parent_instance;

  FlBinaryMessenger* messenger;
};

G_DEFINE_TYPE_WITH_CODE(
    WebViewViewFactory,
    webview_view_factory,
    G_TYPE_OBJECT,
    G_IMPLEMENT_INTERFACE(
        fl_platform_view_factory_get_type(),
        webview_view_factory_fl_platform_view_factory_iface_init))

static FlPlatformView* webview_view_factory_create_platform_view(
    FlPlatformViewFactory* factory,
    int64_t view_identifier,
    FlValue* args) {
  g_return_val_if_fail(WEBVIEW_IS_VIEW_FACTORY(factory), nullptr);
  WebViewViewFactory* self = WEBVIEW_VIEW_FACTORY(factory);
  return FL_PLATFORM_VIEW(
      webview_platform_view_new(self->messenger, view_identifier, args));
}

static FlMessageCodec* webview_view_factory_get_create_arguments_codec(
    FlPlatformViewFactory* self) {
  return FL_MESSAGE_CODEC(fl_standard_message_codec_new());
}

static void webview_view_factory_fl_platform_view_factory_iface_init(
    FlPlatformViewFactoryInterface* iface) {
  iface->create_platform_view = webview_view_factory_create_platform_view;
  iface->get_create_arguments_codec =
      webview_view_factory_get_create_arguments_codec;
}

static void webview_view_factory_class_init(WebViewViewFactoryClass* klass) {}

static void webview_view_factory_init(WebViewViewFactory* self) {}

WebViewViewFactory* webview_view_factory_new(FlBinaryMessenger* messenger) {
  WebViewViewFactory* view_factory = WEBVIEW_VIEW_FACTORY(
      g_object_new(webview_view_factory_get_type(), nullptr));
  view_factory->messenger = messenger;
  return view_factory;
}
