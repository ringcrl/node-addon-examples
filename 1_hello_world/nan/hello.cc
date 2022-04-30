#include <nan.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
               Nan::New("hello").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(hello, Init)

// void Initialize(Local<Object> exports);
// NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
// // NODE_MODULE 后面没有分号，因为它不是函数
// // 使用 node-gyp 构建插件时，使用宏 NODE_GYP_MODULE_NAME 作为 NODE_MODULE()
// 的第一个参数将确保最终二进制文件的名称将传给 NODE_MODULE()

// // NODE_MODULE() 用于围绕给定的 addon 初始化函数构造插件，而
// NODE_MODULE_INIT() 用作此类初始化器的声明，然后是函数体 extern "C"
// NODE_MODULE_EXPORT void NODE_MODULE_INITIALIZER(Local<Object> exports,
//                         Local<Value> module,
//                         Local<Context> context) {
//   /* 在此处执行插件初始化步骤。 */
// }
