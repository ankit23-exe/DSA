class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int best = 0;
        int curBest = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                curBest++;
            }else{
                best = max(best,curBest);
                curBest=0;
            }
        }
        best = max(best,curBest);
        return best;
    }
};