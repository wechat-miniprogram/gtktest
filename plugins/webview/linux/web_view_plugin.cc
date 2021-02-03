#include "include/webview/web_view_plugin.h"

#include "web_view_view_factory.h"

#include <flutter_linux/flutter_linux.h>

#define WEB_VIEW_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), web_view_plugin_get_type(), WebViewPlugin))

struct _WebViewPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(WebViewPlugin, web_view_plugin, g_object_get_type())

static void web_view_plugin_class_init(WebViewPluginClass* klass) {}

static void web_view_plugin_init(WebViewPlugin* self) {}

void web_view_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  WebViewPlugin* plugin =
      WEB_VIEW_PLUGIN(g_object_new(web_view_plugin_get_type(), nullptr));

  FlBinaryMessenger* messenger = fl_plugin_registrar_get_messenger(registrar);
  WebViewViewFactory* factory = webview_view_factory_new(messenger);
  fl_plugin_registrar_register_view_factory(registrar,
                                            FL_PLATFORM_VIEW_FACTORY(factory),
                                            "plugins.flutter.io/webview");

  g_object_unref(plugin);
}
