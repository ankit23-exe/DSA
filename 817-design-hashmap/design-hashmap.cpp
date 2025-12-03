class MyHashMap {
public:
    vector<int> v;
    MyHashMap() {
        v.resize(1000001,-1);
        
    }
    
    void put(int k, int value) {
        v[k]=value;
        
    }
    
    int get(int key) {

        return v[key];
        
    }
    
    void remove(int key) {
        if(v[key]!=-1){
            v[key]=-1;
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