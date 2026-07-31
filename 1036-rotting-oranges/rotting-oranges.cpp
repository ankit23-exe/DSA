class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;

        queue<pair<int, int>> que;
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    freshCount++;
                if (grid[i][j] == 2)
                    que.push({i, j});
            }
        }

        if(freshCount==0) return 0;
        if(que.empty()) return -1;
        int timeLapse = 0;

        int prevFreshCount =0;
        while (!que.empty() && freshCount>0) {
            
            int s = que.size();
            timeLapse++;
            prevFreshCount=freshCount;
            while (s--) {
                auto p = que.front();
                que.pop();
                // traverse in neigh
                for (auto d : direction) {
                    int newx = p.first+d[0];
                    int newy = p.second+d[1];
                    if (newx < 0 || newy < 0 || newx >= m || newy >= n) {
                        continue;
                    }
                    if (grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        freshCount--;
                        que.push({newx, newy});
                    }
                }
            }
            
            if(prevFreshCount==freshCount) return -1;
            
        }

        return timeLapse;
    }
};