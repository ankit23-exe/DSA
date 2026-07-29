class Solution {
public:
    int check(int target, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, target / i); // main part yahi hai
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int minv = 1;
        int maxv = m * n;
        while (minv <= maxv) {
            int mid = minv + (maxv - minv) / 2;

            int count = check(mid, m, n, k);

            if (count >= k)
                maxv = mid - 1;
            else
                minv = mid + 1;
        }
        return minv;
    }
};