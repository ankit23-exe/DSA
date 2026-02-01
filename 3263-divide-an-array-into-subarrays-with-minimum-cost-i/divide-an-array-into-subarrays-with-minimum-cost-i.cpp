class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()==3) return nums[0]+nums[1]+nums[2];

        int originalfirst = nums[0];
        sort(nums.begin(),nums.end());
        int min1 = nums[0];
        int min2 = nums[1];
        int min3 = nums[2];

        if(min1 ==originalfirst ||min2 ==originalfirst ||min3 ==originalfirst ) 
            return min1+min2+min3;
        else{
            return originalfirst +min1 +min2;
        }

    }
};