class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v(nums.size()+1,-1);

        v[0]=0;
        v[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            v[i] = max(nums[i-1]+v[i-2],v[i-1]);  // bottom up approach
        }                                         // so basically , max( steal , skip)
        return v[nums.size()];
    }
};