class MyCalendar {
public:
    vector<pair<int,int>>cal;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto &p:cal){
            int s = p.first;
            int e = p.second;
            if(startTime<e && s<endTime){
                return false;
            }
        }
        cal.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */