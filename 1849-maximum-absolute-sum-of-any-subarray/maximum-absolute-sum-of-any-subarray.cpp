class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        int maxsubsum = nums[0];
        int curmaxsubsum = nums[0];
        int minsubsum = nums[0];
        int curminsubsum = nums[0];

        for(int i=1;i<n;i++){
            curmaxsubsum = max(nums[i],curmaxsubsum+nums[i]);
            maxsubsum = max(maxsubsum,curmaxsubsum);

            curminsubsum = min(nums[i],curminsubsum+nums[i]);
            minsubsum = min(minsubsum,curminsubsum);
        }

        return max(maxsubsum,abs(minsubsum));
    
    }
};