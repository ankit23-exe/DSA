class MyCircularDeque {
public:
    vector<int> q;
    int front = -1;
    int rear = -1;
    int n ;
    MyCircularDeque(int k) {
        q.resize(k,-1);
        n = k;
    }
    
    bool insertFront(int value) {
        //checking empty 
        if(isEmpty()){
            front = 0;
            rear = 0;
            q[front]= value;
            return true;
        }else if((front+n-1)%n == rear){   // checking full 
            return false;
        }else{                          //insert
            front = (front+n-1)%n;
            q[front]=value;
            return true;
        }

    }
    
    bool insertLast(int value) {
        //checking empty 
        if(isEmpty()){
            front = 0;
            rear = 0;
            q[rear] = value;
            return true;
        }else if((rear+1)%n == front){
            return false;
        }else{
            rear = (rear+1)%n;
            q[rear]=value;
            return true;
        }
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else if(front == rear && front != -1){
            front = -1;
            rear = -1;
            return true;
        }else{
            front = (front+1)%n;
            return true;
        }
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else if(front == rear && front != -1){
            front = -1;
            rear = -1;
            return true;
        }else{
            rear = (rear+n-1)%n;
            return true;
        }
        
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return q[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return q[rear];
        
    }
    
    bool isEmpty() {
        if(front == rear && front == -1) return true;
        else{
            return false;
        }
    }
    
    bool isFull() {
        //if(isEmpty()){
        //    return false;
        //}
        if((rear+1)%n == front) return true;
        else return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */