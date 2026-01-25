class Solution {
public:
    int find(vector<int>& nums, int target, int n,bool flag){
        int ans=-1;
        int l = 0;
        int r= n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target){
                ans = mid;
                if(flag){ //going right side
                    l = mid+1;
                }else{
                    r = mid-1;
                }

            }else if(nums[mid]>target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();
        int left = find(nums,target,n,false);
        int right = find(nums,target,n,true);

        return {left,right};
    }
};