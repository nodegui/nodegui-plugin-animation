
#pragma once
#include <nodegui/QtCore/QObject/qobject_macro.h>

#include <QAbstractAnimation>

/*

    This macro adds common QAbstractAnimation macro exported methods
    The exported methods are taken into this macro to avoid writing them in each
   and every time we export.
 */

#ifndef QABSTRACTANIMATION_WRAPPED_METHODS_DECLARATION
#define QABSTRACTANIMATION_WRAPPED_METHODS_DECLARATION \
  QOBJECT_WRAPPED_METHODS_DECLARATION                  \
                                                       \
  Napi::Value start(const Napi::CallbackInfo& info) {  \
    Napi::Env env = info.Env();                        \
    Napi::HandleScope scope(env);                      \
    this->instance->start();                           \
    return env.Null();                                 \
  }                                                    \
                                                       \
  Napi::Value stop(const Napi::CallbackInfo& info) {   \
    Napi::Env env = info.Env();                        \
    Napi::HandleScope scope(env);                      \
    this->instance->stop();                            \
    return env.Null();                                 \
  }                                                    \
#endif

#ifndef QABSTRACTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE
#define QABSTRACTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName) \
  QOBJECT_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName),                 \
                                                                            \
      InstanceMethod("setViewport", &ComponentWrapName::setViewport),       \
      InstanceMethod("viewport", &ComponentWrapName::viewport),

#endif
