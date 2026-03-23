class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dgrid(m,vector<int>(n,0));
        dgrid[0][0]=grid[0][0];
        
        for(int i=1;i<m;i++){
            dgrid[i][0] = grid[i][0] + dgrid[i-1][0];
        }
        for(int j = 1;j<n;j++){
            dgrid[0][j]= grid[0][j] + dgrid[0][j-1]; 
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dgrid[i][j] = grid[i][j] + min(dgrid[i-1][j],dgrid[i][j-1]);
            }
        }

        return dgrid[m-1][n-1];
    }
};