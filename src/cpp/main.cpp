#include <napi.h>

#include "QPropertyAnimation/qpropertyanimation_wrap.h"
#include "QVariantAnimation/qvariantanimation_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QPropertyAnimationWrap::init(env, exports);
  QVariantAnimationWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
