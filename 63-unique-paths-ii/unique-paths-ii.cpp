class Solution {
public:
    int t[101][101];
    int solve(int x, int y, vector<vector<int>>& grid) {

        if (x >= grid.size() || y >= grid[0].size() || grid[x][y] == 1) {
            return 0;
        }

        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            return 1;
        }
        if (t[x][y] != -1) {
            return t[x][y];
        }

        int right = solve(x, y + 1, grid);

        int down = solve(x + 1, y, grid);

        return t[x][y] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, grid);
    }
};
