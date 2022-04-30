#include <assert.h>
#include <node_api.h>

// Node-API 是用于构建原生插件的 API。 它独立于底层 JavaScript 运行时（例如 V8），并作为 Node.js 自身的一部分进行维护。 
// 此 API 将在 Node.js 的各个版本中保持稳定的应用程序二进制接口 (ABI)。
// 它旨在将插件与底层 JavaScript 引擎中的更改隔离开来，并允许为一个版本编译的模块无需重新编译即可在更高版本的 Node.js 上运行。
// 插件是使用本文档中概述的相同方法/工具（node-gyp 等）构建/打包的。
// 唯一的区别是原生代码使用的 API 集。 使用 Node-API 中可用的函数，而不是使用 V8 或 Node.js 原生抽象的 API。

static napi_value HelloWorld(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;
  status = napi_create_string_utf8(env, "world1", 6, &world);
  assert(status == napi_ok);
  return world;
}

#define DECLARE_NAPI_METHOD(name, func) { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", HelloWorld);
  status = napi_define_properties(env, exports, 1, &desc);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
