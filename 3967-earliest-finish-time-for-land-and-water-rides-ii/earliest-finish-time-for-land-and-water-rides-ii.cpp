class Solution {
public:
    int findFinTime(vector<int>& v1, vector<int>& v1d, vector<int>& v2, vector<int>& v2d){
        int finish1 = INT_MAX;
        for(int i=0;i<v1.size();i++){
            finish1 = min(finish1,v1[i]+v1d[i]);
        }
        int finish2 =INT_MAX;
        for(int i=0;i<v2.size();i++){
            finish2 = min(finish2 , max(finish1,v2[i])+v2d[i]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int r1 = findFinTime(landStartTime,landDuration,waterStartTime,waterDuration);
        int r2 = findFinTime(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(r1,r2);
        
    }
};