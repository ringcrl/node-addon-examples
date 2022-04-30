#include <napi.h>

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init)

// node-addon-api 是 napi(node-api) 的封装简化版本

// node-addon-api 写法
// Object obj = Object::New(env);
// obj["foo"] = String::New(env, "bar");

// 等同于下面的 node-api 写法
// napi_status status;
// napi_value object, string;
// status = napi_create_object(env, &object);
// if (status != napi_ok) {
//   napi_throw_error(env, ...);
//   return;
// }
// status = napi_create_string_utf8(env, "bar", NAPI_AUTO_LENGTH, &string);
// if (status != napi_ok) {
//   napi_throw_error(env, ...);
//   return;
// }
// status = napi_set_named_property(env, object, "foo", string);
// if (status != napi_ok) {
//   napi_throw_error(env, ...);
//   return;
// }
