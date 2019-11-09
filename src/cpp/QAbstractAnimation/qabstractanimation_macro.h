
#pragma once
#include <nodegui/QtCore/QObject/qobject_macro.h>

#include <QAbstractAnimation>

/*

    This macro adds common QAbstractAnimation macro exported methods
    The exported methods are taken into this macro to avoid writing them in each
   and every time we export.
 */

#ifndef QABSTRACTANIMATION_WRAPPED_METHODS_DECLARATION
#define QABSTRACTANIMATION_WRAPPED_METHODS_DECLARATION                       \
  QOBJECT_WRAPPED_METHODS_DECLARATION                                        \
                                                                             \
  Napi::Value start(const Napi::CallbackInfo& info) {                        \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    if (info.Length() == 1) {                                                \
      Napi::Number deletionPolicy = info[0].As<Napi::Number>();              \
      this->instance->start(static_cast<QAbstractAnimation::DeletionPolicy>( \
          deletionPolicy.Int32Value()));                                     \
    } else {                                                                 \
      this->instance->start();                                               \
    }                                                                        \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value stop(const Napi::CallbackInfo& info) {                         \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    this->instance->stop();                                                  \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value currentLoop(const Napi::CallbackInfo& info) {                  \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int loop = this->instance->currentLoop();                                \
    return Napi::Value::From(env, loop);                                     \
  }                                                                          \
  Napi::Value currentLoopTime(const Napi::CallbackInfo& info) {              \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int time = this->instance->currentLoopTime();                            \
    return Napi::Value::From(env, time);                                     \
  }                                                                          \
  Napi::Value currentTime(const Napi::CallbackInfo& info) {                  \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int time = this->instance->currentTime();                                \
    return Napi::Value::From(env, time);                                     \
  }                                                                          \
  Napi::Value direction(const Napi::CallbackInfo& info) {                    \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int value = static_cast<int>(this->instance->direction());               \
    return Napi::Value::From(env, value);                                    \
  }                                                                          \
  Napi::Value duration(const Napi::CallbackInfo& info) {                     \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int duration = this->instance->duration();                               \
    return Napi::Value::From(env, duration);                                 \
  }                                                                          \
  Napi::Value loopCount(const Napi::CallbackInfo& info) {                    \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int loopCount = this->instance->loopCount();                             \
    return Napi::Value::From(env, loopCount);                                \
  }                                                                          \
  Napi::Value setDirection(const Napi::CallbackInfo& info) {                 \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    Napi::Number directionValue = info[0].As<Napi::Number>();                \
    int direction = directionValue.Int32Value();                             \
                                                                             \
    this->instance->setDirection(                                            \
        static_cast<QAbstractAnimation::Direction>(direction));              \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value setLoopCount(const Napi::CallbackInfo& info) {                 \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    Napi::Number loopCount = info[0].As<Napi::Number>();                     \
    this->instance->setLoopCount(loopCount.Int32Value());                    \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value state(const Napi::CallbackInfo& info) {                        \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int value = static_cast<int>(this->instance->state());                   \
    return Napi::Value::From(env, value);                                    \
  }                                                                          \
  Napi::Value totalDuration(const Napi::CallbackInfo& info) {                \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    int value = this->instance->totalDuration();                             \
    return Napi::Value::From(env, value);                                    \
  }                                                                          \
  Napi::Value pause(const Napi::CallbackInfo& info) {                        \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    this->instance->pause();                                                 \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value resume(const Napi::CallbackInfo& info) {                       \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    this->instance->resume();                                                \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value setCurrentTime(const Napi::CallbackInfo& info) {               \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    Napi::Number time = info[0].As<Napi::Number>();                          \
    this->instance->setCurrentTime(time.Int32Value());                       \
    return env.Null();                                                       \
  }                                                                          \
  Napi::Value setPaused(const Napi::CallbackInfo& info) {                    \
    Napi::Env env = info.Env();                                              \
    Napi::HandleScope scope(env);                                            \
    Napi::Boolean value = info[0].As<Napi::Boolean>();                       \
    this->instance->setPaused(value.Value());                                \
    return env.Null();                                                       \
  }
#endif

#ifndef QABSTRACTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE
#define QABSTRACTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName)   \
                                                                              \
  QOBJECT_WRAPPED_METHODS_EXPORT_DEFINE(ComponentWrapName)                    \
  InstanceMethod("start", &ComponentWrapName::start),                         \
      InstanceMethod("stop", &ComponentWrapName::stop),                       \
      InstanceMethod("currentLoop", &ComponentWrapName::currentLoop),         \
      InstanceMethod("currentLoopTime", &ComponentWrapName::currentLoopTime), \
      InstanceMethod("currentTime", &ComponentWrapName::currentTime),         \
      InstanceMethod("direction", &ComponentWrapName::direction),             \
      InstanceMethod("duration", &ComponentWrapName::duration),               \
      InstanceMethod("loopCount", &ComponentWrapName::loopCount),             \
      InstanceMethod("setDirection", &ComponentWrapName::setDirection),       \
      InstanceMethod("setLoopCount", &ComponentWrapName::setLoopCount),       \
      InstanceMethod("state", &ComponentWrapName::state),                     \
      InstanceMethod("totalDuration", &ComponentWrapName::totalDuration),     \
      InstanceMethod("pause", &ComponentWrapName::pause),                     \
      InstanceMethod("resume", &ComponentWrapName::resume),                   \
      InstanceMethod("setCurrentTime", &ComponentWrapName::setCurrentTime),   \
      InstanceMethod("setPaused", &ComponentWrapName::setPaused),

#endif
