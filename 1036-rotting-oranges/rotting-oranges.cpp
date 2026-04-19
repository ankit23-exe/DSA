class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int curFresh = 0;
        queue<pair<int, int>> que; // store the rotten orange idx
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    curFresh++;
                }
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }

        if (curFresh == 0)
            return 0;
        int min = 0;

        while (!que.empty()) {
            ++min;
            int s = que.size();
            while (s--) {
                auto p = que.front();
                que.pop();
                if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == 1) {
                    --curFresh;
                    grid[p.first - 1][p.second] = 2;
                    que.push({p.first - 1, p.second});
                }
                if (p.first + 1 < m && grid[p.first + 1][p.second] == 1) {
                    --curFresh;
                    grid[p.first + 1][p.second] = 2;
                    que.push({p.first + 1, p.second});
                }
                // colum
                if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == 1) {
                    --curFresh;
                    grid[p.first][p.second - 1] = 2;
                    que.push({p.first, p.second - 1});
                }
                if (p.second + 1 < n && grid[p.first][p.second + 1] == 1) {
                    --curFresh;
                    grid[p.first][p.second + 1] = 2;
                    que.push({p.first, p.second + 1});
                }
                if (curFresh == 0)
                break;
            }
             if (curFresh == 0)
                break;
           
        }
        if(curFresh!=0) return -1;
        return min;
    }
};