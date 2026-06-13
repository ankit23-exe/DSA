class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int s = i + 1;
            int e = n - 1;
            int target = -nums[i];
            while (s < e) {
                if (nums[s] + nums[e] == target) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                    while (s < e && nums[s] == nums[s - 1])
                        s++;

                    while (s < e && nums[e] == nums[e + 1])
                        e--;

                } else if (nums[s] + nums[e] < target) {
                    s++;
                } else {
                    e--;
                }
            }
        }
        return ans;
    }
};