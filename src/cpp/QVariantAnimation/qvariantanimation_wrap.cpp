#include "qvariantanimation_wrap.h"

#include <nodegui/Extras/Utils/nutils.h>
#include <nodegui/QtCore/QObject/qobject_wrap.h>

#include <QSharedPointer>
#include <QString>

Napi::FunctionReference QVariantAnimationWrap::constructor;

Napi::Object QVariantAnimationWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QVariantAnimation";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {QVARIANTANIMATION_WRAPPED_METHODS_EXPORT_DEFINE(QVariantAnimationWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NVariantAnimation *QVariantAnimationWrap::getInternalInstance() {
  return this->instance;
}

QVariantAnimationWrap::QVariantAnimationWrap(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<QVariantAnimationWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap *parentObjectWrap =
        Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance =
        new NVariantAnimation(parentObjectWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NVariantAnimation();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
}

QVariantAnimationWrap::~QVariantAnimationWrap() {
  extrautils::safeDelete(this->instance);
}
