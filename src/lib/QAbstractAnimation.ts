import { QObject } from '@nodegui/nodegui';

export abstract class QAbstractAnimation extends QObject {
    start(policy: DeletionPolicy): void {
        this.native.start(policy);
    }
    stop(): void {
        this.native.stop();
    }
    currentLoop(): number {
        return this.native.currentLoop();
    }
    currentLoopTime(): number {
        return this.native.currentLoopTime();
    }
    currentTime(): number {
        return this.native.currentTime();
    }
    direction(): Direction {
        return this.native.direction();
    }
    duration(): number {
        return this.native.duration();
    }
    loopCount(): number {
        return this.native.loopCount();
    }
    setDirection(direction: Direction): void {
        return this.native.setDirection(direction);
    }
    setLoopCount(loopCount: number): void {
        return this.native.setLoopCount(loopCount);
    }
    state(): State {
        return this.native.state();
    }
    totalDuration(): number {
        return this.native.totalDuration();
    }
}

export enum DeletionPolicy {
    KeepWhenStopped = 0,
    DeleteWhenStopped = 1,
}
export enum Direction {
    Forward = 0,
    Backward = 1,
}
export enum State {
    Stopped = 0,
    Paused = 1,
    Running = 2,
}
