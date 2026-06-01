class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rowImpact = false;
        int colImpact = false;
        // checking first row
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                rowImpact = true;
                break;
            }
        }
        // checking first col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                colImpact = true;
                break;
            }
        }
        // now marking the row and col if 0 present in center
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // making it zero
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // last make row 0 if impacted
        if (rowImpact) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (colImpact) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};