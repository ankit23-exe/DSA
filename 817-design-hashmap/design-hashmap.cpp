class MyHashMap {
public:
    int size =10000;
    vector<list<pair<int,int>>> v;
    MyHashMap() {
        v.resize(size);
        
    }
    
    void put(int key, int value) {
        int idx = key%size;
        auto &chain =v[idx];
        for(auto &p:chain){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        chain.emplace_back(key,value);
        
    }
    
    int get(int key) {
         int idx = key%size;
        auto &chain =v[idx];
        for(auto &p:chain){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;
        
    }
    
    void remove(int key) {
        int idx = key%size;
        auto &chain =v[idx];
        for(auto it=chain.begin();it!=chain.end();it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
            
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */