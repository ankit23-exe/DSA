class Solution {
public:
    bool possible(int d, vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int count = 0;
        int bookay = 0;
        for (int i = 0; i < n; i++) {
            if (d >= bloomDay[i]) {
                count++;
                if (count == k) {
                    bookay++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        if (count == k) {
            bookay++;
            count = 0;
        }
        if(bookay>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL*m * k > n)
            return -1;
        int maxday = 0;
        for (int i = 0; i < n; i++) {
            maxday = max(maxday, bloomDay[i]);
        }
        if (m * k == n)
            return maxday;
        else {

            int r = maxday;
            int l = 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (possible(mid, bloomDay, m, k)) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            return l;
        }
    }
};