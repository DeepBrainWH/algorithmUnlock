//
// Created by wangheng on 2018-12-25.
//

#ifndef ALGORITHMUNLOCK_MYCIRCLEQUEUE_HPP
#define ALGORITHMUNLOCK_MYCIRCLEQUEUE_HPP
class MyCircularQueue {
public:
    int max_size;
    int front;
    int rear;
    int* a;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    explicit MyCircularQueue(int k) {
        a = new int[k];
        max_size = k;
        front = 0;
        rear = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (rear + 1 == front){
            return false;
        }else{
            rear = rear % max_size;
            a[rear] = value;
            rear ++;
            return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    int deQueue() {
        if(front == rear || front == rear+1){
            return -9999;
        }else{
            front = front % max_size;
            int value = a[front];
            front ++;
            return value;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        return a[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return a[rear-1];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front==rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front==rear+1;
    }
};

#endif //ALGORITHMUNLOCK_MYCIRCLEQUEUE_HPP
