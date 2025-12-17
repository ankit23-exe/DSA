class MyCircularQueue {
public:
    vector<int> q;
    int front=-1;
    int rear=-1;
    int size;
    MyCircularQueue(int k) {
        q.resize(k,0);
        size=k;
        
    }
    
    bool enQueue(int value) {
        if(front==rear && front ==-1){
            q[0]=value;
            front=0;
            rear=0;
            return true;
        }else if((rear+1)%size==front){
            return false;
        }else{
            int idx= (rear+1)%size;
            q[idx]=value;
            rear=(rear+1)%size;
            return true;
        }
        
    }
    
    bool deQueue() {
        if(front==rear && front ==-1){
            return false;
        }else if(front==rear && front!=-1){
            front =-1;
            rear=-1;
            return true;
            
        }
        else{

            front=(front+1)%size;
            return true;
        }
        
    }
    
    int Front() {
        if(front==-1){
            return -1;
        }else{
            return q[front];
        }
        
    }
    
    int Rear() {
        if(rear==-1){
            return -1;
        }else{
            return q[rear];
        }
        
    }
    
    bool isEmpty() {
        if(front==rear && front ==-1){
            return true;
        }
        return false;
        
        
    }
    
    bool isFull() {
        if((rear+1)%size==front){
            return true;
        }
        return false;
        
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