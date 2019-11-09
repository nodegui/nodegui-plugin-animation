import { NativeElement, BaseWidgetEvents, NodeObject } from '@nodegui/nodegui';
import addon from './utils/addon';
import { QAbstractAnimation } from './QAbstractAnimation';

export const QVariantAnimationEvents = Object.freeze({
    ...BaseWidgetEvents,
});

export abstract class NodeVariantAnimation extends QAbstractAnimation {
    setDuration(duration: number): void {
        this.native.setDuration(duration);
    }
    setStartValue(value: any): void {
        this.native.setStartValue(value);
    }
    setEndValue(value: any): void {
        this.native.setEndValue(value);
    }
    setKeyValueAt(step: number, value: any): void {
        this.native.setKeyValueAt(step, value);
    }
}

export class QVariantAnimation extends NodeVariantAnimation {
    native: NativeElement;
    constructor(parent?: NodeObject) {
        let native;
        if (parent) {
            native = new addon.QVariantAnimation(parent.native);
        } else {
            native = new addon.QVariantAnimation();
        }
        super(native);
        this.native = native;
        this.nodeParent = parent;
    }
}
