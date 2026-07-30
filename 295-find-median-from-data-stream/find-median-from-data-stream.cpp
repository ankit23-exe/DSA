class MedianFinder {
public:
    priority_queue<int> pq1;   //max heap 
    priority_queue<int,vector<int>,greater<int>> pq2; //min heap 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
            return;
        }
       
        if(num>pq1.top()){
            pq2.push(num);
            if(pq2.size()>pq1.size()){
                int n = pq2.top();
                pq2.pop();
                pq1.push(n);
            }
        }else{
            if(pq2.empty()){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
                return;
            }
            pq1.push(num);
            if(pq1.size()>pq2.size()+1){
                pq2.push(pq1.top());
                pq1.pop();
                
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            return (1.0*pq1.top()+pq2.top())/2;
        }
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */