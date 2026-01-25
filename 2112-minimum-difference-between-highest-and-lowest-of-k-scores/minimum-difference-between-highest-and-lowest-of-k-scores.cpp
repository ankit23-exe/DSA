class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        //checking k size windoe in nums
        int ans = nums[k-1]-nums[0];

        for(int i =k;i<n;i++){
            ans = min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
    }
};