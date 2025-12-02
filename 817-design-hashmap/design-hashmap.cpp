class MyHashMap {
private:
    static const int MAXK = 1000000;      // maximum possible key
    std::vector<int> table;               // direct-address table

public:
    MyHashMap() : table(MAXK + 1, -1) {
        // initialize all entries to -1 (meaning "not present")
    }
    
    void put(int key, int value) {
        table[key] = value;
    }
    
    int get(int key) {
        return table[key]; // returns -1 if absent, otherwise the value
    }
    
    void remove(int key) {
        table[key] = -1;   // set back to "not present"
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
