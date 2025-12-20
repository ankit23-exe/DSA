class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> res;
        vector<bool> visited(n, false);
        int stars = 0;

        auto canReplace = [&](int i) {
            bool diff = false;
            for (int j = 0; j < m; j++) {
                if (target[i + j] == '?') continue;
                if (target[i + j] != stamp[j]) return false;
                diff = true;
            }
            return diff;
        };

        auto doReplace = [&](int i) {
            for (int j = 0; j < m; j++) {
                if (target[i + j] != '?') {
                    target[i + j] = '?';
                    stars++;
                }
            }
        };

        while (stars < n) {
            bool changed = false;

            for (int i = 0; i <= n - m; i++) {
                if (!visited[i] && canReplace(i)) {
                    visited[i] = true;
                    doReplace(i);
                    res.push_back(i);
                    changed = true;
                }
            }

            if (!changed) return {};
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
