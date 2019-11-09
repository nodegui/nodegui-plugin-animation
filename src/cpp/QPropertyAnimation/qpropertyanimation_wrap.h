#pragma once
#include <napi.h>
#include <stdlib.h>

#include <QPointer>

#include "QVariantAnimation/qvariantanimation_macro.h"
#include "npropertyanimation.hpp"

class QPropertyAnimationWrap : public Napi::ObjectWrap<QPropertyAnimationWrap> {
 private:
  QPointer<NPropertyAnimation> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QPropertyAnimationWrap(const Napi::CallbackInfo &info);
  ~QPropertyAnimationWrap();
  NPropertyAnimation *getInternalInstance();
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value setPropertyName(const Napi::CallbackInfo &info);
  Napi::Value propertyName(const Napi::CallbackInfo &info);
  Napi::Value setTargetObject(const Napi::CallbackInfo &info);

  QVARIANTANIMATION_WRAPPED_METHODS_DECLARATION
};
