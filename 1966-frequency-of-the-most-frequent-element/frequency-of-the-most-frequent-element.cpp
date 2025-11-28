class Solution {
public:
    vector<long long> presum;

    int binary(const vector<int>& nums, int target_idx, long long k) {
        int l = 0;
        int r = target_idx;
        int best = target_idx;   // leftmost index that works

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long len = target_idx - mid + 1;              // window length
            long long window = len * 1LL * nums[target_idx];   // target value * len

            long long original = presum[target_idx] - (mid > 0 ? presum[mid - 1] : 0LL);

            if (window - original > k) {
                // need more increments than k -> move left bound right
                l = mid + 1;
            } else {
                // this mid works, try to expand window to the left
                best = mid;
                r = mid - 1;
            }
        }

        return target_idx - best + 1;  // frequency
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        presum.assign(n, 0);
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];        // sum can overflow int, so long long
            presum[i] = sum;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int freq = binary(nums, i, k);
            if (freq > res) res = freq;
        }

        return res;
    }
};
