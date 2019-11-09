import { QObject } from '@nodegui/nodegui';

export abstract class QAbstractAnimation extends QObject {
    start(): void {
        this.native.start();
    }
    stop(): void {
        this.native.stop();
    }
}
