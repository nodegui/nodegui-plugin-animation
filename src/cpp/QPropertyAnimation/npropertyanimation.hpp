#pragma once

#include <nodegui/core/Events/eventwidget.h>
#include <nodegui/core/Events/eventwidget_macro.h>

#include <QPropertyAnimation>

class NPropertyAnimation : public QPropertyAnimation, public EventWidget {
  Q_OBJECT
  EVENTWIDGET_IMPLEMENTATIONS(QPropertyAnimation)
 public:
  using QPropertyAnimation::QPropertyAnimation;
};
