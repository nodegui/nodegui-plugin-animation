import { QPropertyAnimation } from './index';
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
