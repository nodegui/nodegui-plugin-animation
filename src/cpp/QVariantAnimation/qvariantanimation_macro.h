
#pragma once
#include <nodegui/Extras/Utils/nutils.h>

#include "QAbstractAnimation/qabstractanimation_macro.h"
/*

    This macro adds common QVariantAnimation macro exported methods
    The exported methods are taken into this macro to avoid writing them in each
   and every time we export.
 */

#ifndef QVARIANTANIMATION_WRAPPED_METHODS_DECLARATION
#define QVARIANTANIMATION_WRAPPED_METHODS_DECLARATION                   \
  QABSTRACTANIMATION_WRAPPED_METHODS_DECLARATION                        \
                                                                        \
  Napi::Value setDuration(const Napi::CallbackInfo &info) {             \
    Napi::Env env = info.Env();                                         \
    Napi::HandleScope scope(env);                                       \
    Napi::Number duration = info[0].As<Napi::Number>();                 \
    this->instance->setDuration(duration.Int32Value());                 \
    return env.Null();                                                  \
  }                                                                     \
                                                                        \
  Napi::Value setStartValue(const Napi::CallbackInfo &info) {           \
    Napi::Env env = info.Env();                                         \
    Napi::HandleScope scope(env);                                       \
    Napi::Value value = info[0];                                        \
    auto variant =                                                      \
        QSharedPointer<QVariant>(extrautils::convertToQVariant(value)); \
    this->instance->setStartValue(*variant);                            \
    return env.Null();                                                  \
  }                                                                     \
                                                                        \
  Napi::Value setEndValue(const Napi::CallbackInfo &info) {             \
    Napi::Env env = info.Env();                                         \
    Napi::HandleScope scope(env);                                       \
                                                                        \
    Napi::Value value = info[0];                                        \
    auto variant =                                                      \
        QSharedPointer<QVariant>(extrautils::convertToQVariant(value)); \
    this->instance->setEndValue(*variant);                              \
    return env.Null();                                                  \
  }

#endif

#ifndef QVARIANTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE
#define QVARIANTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName) \
                                                                           \
  QABSTRACTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName)      \
  InstanceMethod("setDuration", &ComponentWrapName::setDuration),          \
      InstanceMethod("setStartValue", &ComponentWrapName::setStartValue),  \
      InstanceMethod("setEndValue", &ComponentWrapName::setEndValue),

#endif
