class LRUCache {
public:
    list<int> dll;
   unordered_map<int, pair<list<int>::iterator, int>> mp;
    int siz;
    LRUCache(int capacity) {
        siz = capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        else{
            auto p = mp[key];
            dll.erase(p.first);
            dll.push_front(key);
            mp[key]={dll.begin(),p.second};
            return p.second;
        }
    }
    
    void put(int key, int value) {
         if(mp.count(key)){ //present then update it
            auto p = mp[key];
            dll.erase(p.first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            return;
         }else{
            
                dll.push_front(key);
                mp[key]={dll.begin(),value};
                if(dll.size()>siz){
                    int lastKey = dll.back();
                    dll.pop_back();
                    mp.erase(lastKey);
                   
                }
            
         }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */