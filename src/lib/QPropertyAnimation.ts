import { NativeElement, NodeObject } from '@nodegui/nodegui';
import addon from './utils/addon';
import { NodeVariantAnimation, QVariantAnimationEvents } from './QVariantAnimation';

export const QPropertyAnimationEvents = Object.freeze({
    ...QVariantAnimationEvents,
});
export class QPropertyAnimation extends NodeVariantAnimation {
    native: NativeElement;
    constructor(parent?: NodeObject) {
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
    setPropertyName(name: string): void {
        this.native.setPropertyName(name);
    }
    propertyName(): string {
        return this.native.propertyName();
    }
    setTargetObject(object: NodeObject): void {
        return this.native.setTargetObject(object.native);
    }
}
