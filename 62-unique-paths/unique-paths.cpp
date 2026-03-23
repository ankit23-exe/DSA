class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid (m,vector<int> (n,0));
        grid[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    continue;
                
                int curval =0;
                if(i-1>=0){
                    curval +=grid[i-1][j];
                }
                if(j-1>=0){
                    curval +=grid[i][j-1];
                }
                
                grid[i][j]=curval;
                
            }
        }

        return grid[m-1][n-1];
    }
};