class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int minnum = INT_MAX;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[e]){
                s = mid+1;
            }else{
                minnum = min(minnum,nums[mid]);
                e = mid-1;
            }
        }
        return minnum;
    }
};