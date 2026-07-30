class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        if(n==2) 
            return nums[0]>nums[1]?0:1;

        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        for(int i=0;i<n;i++){
            if(i-1>=0 && i+1<n){
                if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                    return i;
                }
            }
        }
        return 1;
    }
};