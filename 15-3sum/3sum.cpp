class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<=n-3;i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int l =i+1;
            int r = n-1;
            while(l<r){
                if(nums[l]+nums[r]==target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l+1<n && nums[l]==nums[l+1])
                        l++;
                    while(l<r && nums[r]==nums[r-1])
                        r--;
                    l++;r--;
                }else if(nums[l]+nums[r]>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};