class Solution {
public:
    void dfs(int i, int j,
             unordered_map<string, vector<pair<int, int>>>& adjlist,
             set<pair<int, int>>& visited) {
        visited.insert({i, j});
        string key = to_string(i) + "+" + to_string(j);

        for (auto neigh : adjlist[key]) {
            if (!visited.count(neigh)) {
                dfs(neigh.first, neigh.second, adjlist, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        unordered_map<string, vector<pair<int, int>>> adjlist;
        int oneCount = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    string key = to_string(i) + "+" + to_string(j);
                    oneCount++;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                        adjlist[key].push_back({i, j - 1});
                    }
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        adjlist[key].push_back({i, j + 1});
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                        adjlist[key].push_back({i - 1, j});
                    }
                    if (i + 1 < m && grid[i + 1][j] == 1) {
                        adjlist[key].push_back({i + 1, j});
                    }
                }
            }
        }
        set<pair<int, int>> visited;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isBoundary =
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1);

                if (isBoundary && grid[i][j] == 1) {
                    dfs(i, j, adjlist, visited);
                }
            }
        }
        return oneCount - visited.size();
    }
};