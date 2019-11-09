import { NativeElement, BaseWidgetEvents, NObject } from '@nodegui/nodegui';
import addon from './utils/addon';
import { QAbstractAnimation } from './QAbstractAnimation';

export const QPropertyAnimationEvents = Object.freeze({
    ...BaseWidgetEvents,
});

export class QPropertyAnimation extends QAbstractAnimation {
    native: NativeElement;
    constructor(parent?: NObject) {
        let native;
        if (parent) {
            native = new addon.QPropertyAnimation(parent.native);
        } else {
            native = new addon.QPropertyAnimation();
        }
        super(native);
        this.native = native;
        this.nodeParent = parent;
    }
}
