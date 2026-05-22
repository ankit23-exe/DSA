class Solution {
public:
    int binarysearch(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        //finding the point where it is divided
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid ;
            }
        }
        int r1 = binarysearch(nums, target, 0, s-1);
        if (r1 != -1)
            return r1;
        return binarysearch(nums, target, s, nums.size() - 1);
    }
};