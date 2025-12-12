class MinStack {
public:
    list<int> ll;
    int min=INT_MAX;
    MinStack() {
        
    }
    void minfinder(){
        min=INT_MAX;

        for(auto l:ll){
            if(min>l){
                min=l;
            }

        }
    }
    
    void push(int val) {
        ll.push_front(val);
        if(min>val){
            min=val;
        }   
    }
    
    void pop() {
        if(ll.front()==min){
            ll.erase(ll.begin());
            minfinder();
        }else{
            ll.erase(ll.begin());
        }
        
    }
    
    int top() {
        return ll.front();
        
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */