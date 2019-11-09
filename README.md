# NodeGui plugin animation

[![npm version](https://img.shields.io/npm/v/@nodegui/plugin-animation.svg)](https://www.npmjs.com/package/@nodegui/plugin-animation)

Plugin you can use to create native animations in NodeGui

## Requirements

Requires NodeGui v0.5.0 and up

## Demo

```js
import { QPropertyAnimation } from './index';
import { QPushButton } from '@nodegui/nodegui';

const animation = new QPropertyAnimation();

const button = new QPushButton();
button.setText('Animated Button');
button.show();

animation.setPropertyName('windowOpacity');
animation.setTargetObject(button);

animation.setDuration(5000);
animation.setStartValue(0.4);
animation.setKeyValueAt(0.5, 1.0);
animation.setEndValue(0.4);

animation.start();

(global as any).button = button;
(global as any).animation = animation;
```
