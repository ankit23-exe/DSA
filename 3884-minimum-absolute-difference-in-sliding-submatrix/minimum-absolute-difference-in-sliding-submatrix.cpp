class Solution {
public:
    void helper(int i, int j, int k, vector<vector<int>>& ans,
                vector<vector<int>>& grid) {
        set<int> temp;
        for (int r = i; r < i + k; r++) {
            for (int c = j; c < j + k; c++) {
                temp.insert(grid[r][c]);
            }
        }

        int finalval = INT_MAX;
        if (temp.size() == 1) {
            ans[i][j] = 0;
            return;
        }
       
        auto it = temp.begin();
        auto prev = it;
        it++;

        for (; it != temp.end(); it++) {
            finalval = min(finalval, *it - *prev);
            prev = it;
        }

        ans[i][j] = finalval;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                // function to check
                if (k == 1) {
                    ans[i][j] = 0;
                } else {
                    helper(i, j, k, ans, grid);
                }
            }
        }

        return ans;
    }
};