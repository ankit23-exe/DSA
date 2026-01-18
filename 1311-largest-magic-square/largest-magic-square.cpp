class Solution {
public:
    bool check(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
        unordered_set<int> s;
        // row checking
        int sum = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                sum += grid[i][j];
            }
            s.insert(sum);
            sum = 0;
            if (s.size() > 1)
                return false;
        }
        // col checking
        for (int j = y1; j <= y2; j++) {
            for (int i = x1; i <= x2; i++) {
                sum += grid[i][j];
            }
            s.insert(sum);
            sum = 0;
            if (s.size() > 1)
                return false;
        }

        // diagonal checking
        for (int d = 0; d <= x2 - x1; d++) {
            sum += grid[x1 + d][y1 + d];
        }

        s.insert(sum);
        sum = 0;
        if (s.size() > 1)
            return false;

        // off diagonal

        for (int d = 0; d <= x2 - x1; d++) {
            sum += grid[x1 + d][y2 - d];
        }

        s.insert(sum);
        sum = 0;
        if (s.size() > 1)
            return false;

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int side = min(m, n);
        while (side > 1) {
            for (int i = 0; i + side <= m; i++) {
                for (int j = 0; j + side <= n; j++) {
                    int x1 = i;
                    int y1 = j;
                    int x2 = i + side - 1;
                    int y2 = j + side - 1;

                    if (check(x1, y1, x2, y2, grid)) {
                        return side;
                    }
                }
            }
            side--;
        }
        return 1;
    }
};