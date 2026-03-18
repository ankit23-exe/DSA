class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        //making the prefix matrix
        vector<vector<int>> presum(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                int currsum = 0;
                if(i-1>=0){
                    currsum += presum[i-1][j];
                }
                if(j-1>=0){
                    currsum += presum[i][j-1];
                }

                if(i-1>=0 && j-1>=0){
                    currsum -= presum[i-1][j-1];
                }
                currsum += grid[i][j];

                presum[i][j] = currsum;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(presum[i][j]<=k){
                    count++;
                }
            }
        }

        return count;
    }
};