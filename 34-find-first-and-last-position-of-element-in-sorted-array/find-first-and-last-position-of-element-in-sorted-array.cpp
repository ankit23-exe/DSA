class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2,-1);
        if(n == 0) return ans;
        //spotting first time
        int i ;
        for( i=0;i<n;i++ ){
            if(nums[i]==target){
                ans[0]=i;
                break;
            }
        }
        for(i;i<n;i++){
            if(nums[i]!=target){
                ans[1]=i-1;
                break;
            }
        }
        if(ans[0]!= -1 && ans[1] == -1){
            ans[1]=n-1;
        }
        return ans;

    }
};