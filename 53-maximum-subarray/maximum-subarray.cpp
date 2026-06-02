class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxsubsum = nums[0];
        int curmaxsubsum = nums[0];


        for(int i=1;i<n;i++){
            curmaxsubsum = max(nums[i],curmaxsubsum+nums[i]);
            maxsubsum = max(maxsubsum,curmaxsubsum);
        }
        return maxsubsum;
    }
};