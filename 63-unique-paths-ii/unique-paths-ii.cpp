class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1) return 0;

        vector<vector<int>> way(m,vector<int>(n,0));
        way[0][0]=1;
        for(int col =1;col<n;col++){
            if(grid[0][col]!=1){
                way[0][col]=1;
            }else{
                break;
            }
        }

        for(int row =1;row<m;row++){
            if(grid[row][0]!=1){
                way[row][0]=1;
            }else{
                break;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]!=1){
                    way[i][j]=way[i-1][j] + way[i][j-1];
                }
            }
        }

        return way[m-1][n-1];
        
    }
};