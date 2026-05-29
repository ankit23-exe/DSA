class Solution {
public:
    int m;
    int n;
    vector<vector<int>>direction = {{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int i, int j,vector<vector<int>>& grid) {
        grid[i][j]=0;
        
        for (auto &d : direction) {
            int newi = i+d[0];
            int newj = j+d[1];
            if (newi>=0 && newi<m && newj>=0 && newj<n) {
                if(grid[newi][newj]== 1)
                    dfs(newi,newj,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isBoundary = (i==0 || i==m-1 ||j==0 || j==n-1);
                if(isBoundary && grid[i][j]==1){
                    dfs(i,j,grid);
                }
                
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;


       
    }
};