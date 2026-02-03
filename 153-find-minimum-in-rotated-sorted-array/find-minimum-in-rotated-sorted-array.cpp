class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l =0;
        int r =n-1;
        int small = INT_MAX;
        while(l<=r){
            int mid = l +(r-l)/2;
            small = min(small, nums[mid]);
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid-1;
            }
            
        }
        return small;
    }
};