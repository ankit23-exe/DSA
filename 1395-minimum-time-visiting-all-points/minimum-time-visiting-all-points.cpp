class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans=0;
        for(int i =0;i<n-1;i++){
            auto start =points[i];
            auto end = points[i+1];

            int d1 = abs(start[0]-end[0]);
            int d2 = abs(start[1]-end[1]);

            int mind = d1<=d2?d1:d2;

            ans+=mind;
            int notmin = d1>d2?d1:d2;
            ans+=(notmin-mind);
        }
        return ans;
    }
};