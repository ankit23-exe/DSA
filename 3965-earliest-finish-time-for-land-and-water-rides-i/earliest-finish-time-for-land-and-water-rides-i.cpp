class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int ans = INT_MAX;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int lstart = landStartTime[i];
                int ldur = landDuration[i];
                int wstart = waterStartTime[j];
                int wdur = waterDuration[j];
                int curans = min(lstart,wstart);
                curans += lstart<wstart?ldur:wdur;
                if(curans<max(lstart,wstart)) curans+=(max(lstart,wstart)-curans);
                curans += lstart<wstart?wdur:ldur;

                ans = min(ans,curans);
            }
        }
        return ans;
    }
};