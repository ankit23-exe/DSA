class Solution {
public:
    int bsearch(vector<int>& nums, int l, int r, int target) {

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int p = -1;
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        // finding pivot index
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        p = r;

        // calling binary search on both part
        int s1 = bsearch(nums, 0, p - 1, target);
        int s2 = bsearch(nums, p, n - 1, target);

        return max(s1, s2);
    }
};