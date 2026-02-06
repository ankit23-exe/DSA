class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> t(nums.size(), 1);
        int maxLIS = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    t[i] = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;
    }
};