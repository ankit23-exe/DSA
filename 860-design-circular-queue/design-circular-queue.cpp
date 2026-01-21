class MyCircularQueue {
public:
    vector<int> q;
    int front = -1;
    int rear = -1;
    int k = 0;
    MyCircularQueue(int s) {
        q.resize(s, 0);
        k = s;
    }

    bool enQueue(int value) {
        if (front == rear && front == -1) { // no element alreadt
            front = 0;
            rear = 0;
            q[front] = value;
            
            return true;
        } else if ((rear + 1) % k == front) {
            return false;
        } else {
            q[(rear + 1) % k] = value;
            rear = (rear+1)%k;
            return true;
        }
    }

    bool deQueue() {
        if (front == rear && front == -1) {
            return false;
        } else if (front == rear) {
            front = -1;
            rear = -1;
            return true;
        } else {
            front = (front + 1) % k;
            return true;
        }
    }

    int Front() {
        if (front == rear && front == -1) {
            return -1;
        } else {
            return q[front];
        }
    }

    int Rear() {
        if (front == rear && front == -1) {
            return -1;
        } else {
            return q[rear];
        }
    }

    bool isEmpty() {
        if (front == rear && front == -1) {
            return true;
        } else {
            return false;
        }
    }

    bool isFull() {
        if ((rear + 1) % k == front) {
            return true;

        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */