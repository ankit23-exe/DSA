class Solution {
public:
    vector<vector<int>> directions = {
        {0, -1},  // Left
        {-1, 0},  // Up
        {0, 1},   // Right
        {1, 0},   // Down
        {-1, -1}, // Top-Left
        {-1, 1},  // Top-Right
        {1, -1},  // Bottom-Left
        {1, 1}    // Bottom-Right
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        int count = 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // visited[0][0] = 1;
        queue<pair<int, int>> que;
        que.push({0, 0});
        visited[0][0] = true;
        // priority_queue<pair<int, pair<int, int>>,
        //                vector<pair<int, pair<int, int>>>,
        //                greater<pair<int, pair<int, int>>>>
        //     pq;

        // pq.push({1, {0, 0}});
        // while (!pq.empty()) {
        //     auto p = pq.top();
        //     pq.pop();
        //     int wt = p.first;
        //     int i = p.second.first;
        //     int j = p.second.second;

        //     for (auto &d : directions) {
        //         int newi = i + d[0];
        //         int newj = j + d[1];
        //         if (newi < 0 || newi >= n || newj < 0 || newj >= n)
        //             continue;
        //         if (grid[newi][newj] == 0) {
        //             if (wt + 1 < visited[newi][newj]) {
        //                 visited[newi][newj] = wt + 1;
        //                 pq.push({wt + 1, {newi, newj}});
        //             }
        //         }
        //     }
        // }
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto p = que.front();
                que.pop();
                int i = p.first;
                int j = p.second;
                if (i == n - 1 && j == n - 1)
                    return count;
                for (auto& d : directions) {
                    int newi = i + d[0];
                    int newj = j + d[1];

                    if (newi < 0 || newi >= n || newj < 0 || newj >= n)
                        continue;

                    if (grid[newi][newj] == 0) {
                        if (!visited[newi][newj]) {
                            que.push({newi, newj});
                            visited[newi][newj] = true;
                        }
                    }
                }
            }
            count++;
        }

        return -1;
        // if(visited[n-1][n-1]==INT_MAX) return -1;
        // return visited[n - 1][n - 1];
    }
};