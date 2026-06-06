class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int rsum = nums[n-1];
        for(int i=n-2;i>=0;i--){
            rsum+=nums[i];
        }
        
        int lsum = 0;
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            int temp = nums[i];
            nums[i]=abs(lsum-rsum);
            lsum+=temp;
        }

        return nums;
    }
};