class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || nums[0]>nums[1]) return 0;
        //checking first element 
        if(nums[n-1]>nums[n-2]) return n-1;

        int s =1;
        int e = n-2;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid] ){
                return mid;
            }else if(nums[mid-1]>nums[mid]){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        //kabhi nhi chalega 
        return 0;
    }
};