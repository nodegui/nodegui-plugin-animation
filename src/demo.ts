import { QPropertyAnimation } from './index';
import { QPushButton, QMainWindow } from '@nodegui/nodegui';
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

const win2 = new QMainWindow();
win2.show();
(global as any).win2 = win2;
