class Solution {
public:
    int t[201][201];
    int solve(int x,int y,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(x == m-1 && y == n-1){
            return grid[m-1][n-1];
        }

        if(x>=m || y>=n) return INT_MAX;

        if(t[x][y] !=-1){
            return t[x][y];
        }
        
        int right = solve(x,y+1,grid);
        int down = solve(x+1,y,grid);

        return t[x][y] = grid[x][y] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};