class LRUCache {
public:
    int n;
    list<int> dll;   //key store krenga , linked list mai 
    unordered_map<int,pair< list<int>::iterator ,int>> mp; //key -> addres,val
    LRUCache(int capacity) {
        n=capacity;

        
    }

    void makeRecentlyUsed(int key){
        auto ads=mp[key].first;
        dll.erase(ads);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end()){
            return -1;
        }
        makeRecentlyUsed(key);
        return mp[key].second;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){  //pehla sa present hai
            makeRecentlyUsed(key);
            mp[key].second=value;
        }else{                    //agar nhi present toh
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }

        if(n<0){
            int last_key=dll.back();
            dll.erase(mp[last_key].first);
            mp.erase(last_key);
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */