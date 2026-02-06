class Solution {
public:
    int lowerbound(int target, int n, vector<int>& nums) {
        int l = 0;
        int r = n - 1;
        int ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] >= target) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        // lower bound simple question
        int n = nums.size();
        return lowerbound(target, n, nums);
    }
};