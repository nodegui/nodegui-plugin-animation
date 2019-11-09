#pragma once

#include <nodegui/core/Events/eventwidget.h>
#include <nodegui/core/Events/eventwidget_macro.h>

#include <QVariantAnimation>

class NVariantAnimation : public QVariantAnimation, public EventWidget {
  Q_OBJECT
  EVENTWIDGET_IMPLEMENTATIONS(QVariantAnimation)
 public:
  using QVariantAnimation::QVariantAnimation;
};
