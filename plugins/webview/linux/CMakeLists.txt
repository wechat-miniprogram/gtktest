cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME "webview")
project(${PROJECT_NAME} LANGUAGES CXX)

# This value is used when generating builds using this plugin, so it must
# not be changed
set(PLUGIN_NAME "webview_plugin")

# include_directories("/home/yuhuihuang/webkit-installation/include/webkitgtk-4.0")
# link_directories("/home/yuhuihuang/webkit-installation/lib")

add_library(${PLUGIN_NAME} SHARED
  "web_view_plugin.cc"
  "web_view_platform_view.cc"
  "web_view_view_factory.cc"
)
apply_standard_settings(${PLUGIN_NAME})

pkg_check_modules(WebKitGTK REQUIRED IMPORTED_TARGET webkit2gtk-4.0)
# pkg_check_modules(Soup REQUIRED IMPORTED_TARGET libsoup-2.4)

set_target_properties(${PLUGIN_NAME} PROPERTIES
  CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(${PLUGIN_NAME} PRIVATE FLUTTER_PLUGIN_IMPL)
target_include_directories(${PLUGIN_NAME} INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PLUGIN_NAME} PRIVATE flutter)
target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::GTK PkgConfig::WebKitGTK)
# target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::Soup javascriptcoregtk-4.0 webkit2gtk-4.0)

# List of absolute paths to libraries that should be bundled with the plugin
set(webview_bundled_libraries
  ""
  PARENT_SCOPE
)
