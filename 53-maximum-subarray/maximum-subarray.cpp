class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = INT_MIN;
        int cursum = 0;
        for(int i=0;i<n;i++){
            cursum +=nums[i];
            if(cursum<0){
                cursum=0;
            }
            sum= max(sum,cursum);   
        }
        if(sum==0){
            return *max_element(nums.begin(),nums.end());
        }
        return sum;
    }
};