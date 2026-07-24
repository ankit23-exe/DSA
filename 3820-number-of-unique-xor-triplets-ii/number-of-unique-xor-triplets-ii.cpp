class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>pair;
        unordered_set<int>ans;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pair.insert(nums[i]^nums[j]);
            }
        }
        for(auto &p:pair){
            for(auto &n:nums){
                ans.insert(p^n);
            }
        }
        return ans.size();
    }
};