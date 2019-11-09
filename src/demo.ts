import { QPropertyAnimation } from './index';
import { QPushButton } from '@nodegui/nodegui';
import { DeletionPolicy } from './lib/QAbstractAnimation';

const animation = new QPropertyAnimation();

const button = new QPushButton();
button.setText('Animated Button');
button.show();

animation.setPropertyName('minimumHeight');
animation.setTargetObject(button);

animation.setDuration(5000);
animation.setStartValue(20);
animation.setEndValue(50);

animation.start(DeletionPolicy.DeleteWhenStopped);
setTimeout(() => {
    animation.stop();
}, 3000);
