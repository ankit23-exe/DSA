class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                pos = mid;
                right = mid - 1;   // search left
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                pos = mid;
                left = mid + 1;   // search right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return pos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return { findFirst(nums, target), findLast(nums, target) };
    }
};
