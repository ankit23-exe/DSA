class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removed = 0;
        int n = intervals.size();
        auto comparator =[](vector<int>p1,vector<int>p2){
            return p1[1]<p2[1];
        };
        sort(intervals.begin(),intervals.end(),comparator);
        int prevend = intervals[0][1];
        for(int i=1;i<n;i++){
            int curStart = intervals[i][0];
            if(prevend>curStart){
                removed++;
            }else{
                prevend = intervals[i][1];
            }
        }

        return removed;
    }
};