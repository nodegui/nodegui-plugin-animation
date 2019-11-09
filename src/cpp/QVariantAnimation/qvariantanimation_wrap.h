#pragma once
#include <napi.h>
#include <stdlib.h>

#include <QPointer>

#include "nvariantanimation.hpp"
#include "qvariantanimation_macro.h"

class QVariantAnimationWrap : public Napi::ObjectWrap<QVariantAnimationWrap> {
 private:
  QPointer<NVariantAnimation> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QVariantAnimationWrap(const Napi::CallbackInfo &info);
  ~QVariantAnimationWrap();
  NVariantAnimation *getInternalInstance();
  static Napi::FunctionReference constructor;
  QVARIANTANIMATION_WRAPPED_METHODS_DECLARATION
};
