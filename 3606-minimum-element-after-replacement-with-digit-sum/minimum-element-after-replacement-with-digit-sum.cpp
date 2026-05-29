class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans =INT_MAX;
        for(auto n:nums){
            int cursum = 0;
            while(n>0){
                int digi = n%10;
                n/=10;
                cursum+=digi;
            }
            ans=min(ans,cursum);
        }
        return ans;
    }
};