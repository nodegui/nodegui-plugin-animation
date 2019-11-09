# NodeGui plugin animation

[![npm version](https://img.shields.io/npm/v/@nodegui/plugin-animation.svg)](https://www.npmjs.com/package/@nodegui/plugin-animation)

Plugin you can use to create native animations in NodeGui

## Requirements

Requires NodeGui v0.5.0 and up

## Demo

```js
import { QPropertyAnimation } from '@nodegui/plugin-animation';
import { QPushButton } from '@nodegui/nodegui';

const animation = new QPropertyAnimation();

const button = new QPushButton();
button.setText('Animated Button');
button.show();

animation.setPropertyName('minimumHeight');
animation.setTargetObject(button);

animation.setDuration(5000);
animation.setStartValue(20);
animation.setEndValue(50);

animation.start();
setTimeout(() => {
    animation.stop();
}, 3000);

(global as any).button = button;
(global as any).animation = animation;
```
