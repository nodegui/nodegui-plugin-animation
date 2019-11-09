#include "qpropertyanimation_wrap.h"

#include <nodegui/Extras/Utils/nutils.h>
#include <nodegui/QtCore/QObject/qobject_wrap.h>

#include <QString>

Napi::FunctionReference QPropertyAnimationWrap::constructor;

Napi::Object QPropertyAnimationWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QPropertyAnimation";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("setPropertyName",
                      &QPropertyAnimationWrap::setPropertyName),
       InstanceMethod("setTargetObject",
                      &QPropertyAnimationWrap::setTargetObject),
       InstanceMethod("propertyName", &QPropertyAnimationWrap::propertyName),
       QVARIANTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(
           QPropertyAnimationWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NPropertyAnimation *QPropertyAnimationWrap::getInternalInstance() {
  return this->instance;
}

QPropertyAnimationWrap::QPropertyAnimationWrap(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<QPropertyAnimationWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap *parentObjectWrap =
        Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance =
        new NPropertyAnimation(parentObjectWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NPropertyAnimation();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
}

QPropertyAnimationWrap::~QPropertyAnimationWrap() {
  extrautils::safeDelete(this->instance);
}

Napi::Value QPropertyAnimationWrap::setPropertyName(
    const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Napi::String name = info[0].As<Napi::String>();
  std::string nameString = name.Utf8Value();
  QByteArray byteArray(nameString.c_str(), nameString.length());
  this->instance->setPropertyName(byteArray);
  return env.Null();
}
Napi::Value QPropertyAnimationWrap::propertyName(
    const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QString name = this->instance->propertyName();
  return Napi::String::From(env, name.toStdString());
}
Napi::Value QPropertyAnimationWrap::setTargetObject(
    const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object qobjectWrapObject = info[0].As<Napi::Object>();
  QObjectWrap *objectWrap =
      Napi::ObjectWrap<QObjectWrap>::Unwrap(qobjectWrapObject);
  this->instance->setTargetObject(objectWrap->getInternalInstance());

  return env.Null();
}
