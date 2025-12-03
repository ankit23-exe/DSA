class MyHashSet {
public:
    vector<list<int>> bucket;
    int M;

    int getdx(int key){
        return key%M;
    }
    MyHashSet() {
        M=15000;
        bucket.resize(M,list<int>{});
    }
    
    void add(int key) {
        int idx =getdx(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);
        if(itr==bucket[idx].end()){
            bucket[idx].push_back(key);
        }
        
    }
    
    void remove(int key) {
        int idx =getdx(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);
        if(itr!=bucket[idx].end()){
            bucket[idx].erase(itr);
        }
        
    }
    
    bool contains(int key) {
        int idx =getdx(key);
        auto itr=find(bucket[idx].begin(),bucket[idx].end(),key);
        if(itr!=bucket[idx].end()){
            return true;
        }
        
    return false;   
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */