class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rowsum(m,0);
        vector<long long> colsum(n,0);
        long long totalsum =0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
            rowsum[i]+=grid[i][j];
            colsum[j]+=grid[i][j];
            totalsum+=grid[i][j];
           }


        }

        if(totalsum%2!=0) return false;

        long long cur_row_sum = 0;
        for(int i=0;i<=m-2;i++){
            cur_row_sum+=rowsum[i];
            if(cur_row_sum == totalsum-cur_row_sum){
                return true;
            }
           
        }

         long long cur_col_sum = 0;
        for(int i=0;i<=n-2;i++){
            cur_col_sum+=colsum[i];
            if(cur_col_sum == totalsum-cur_col_sum){
                return true;
            }
           
        }
        return false;
    }
};