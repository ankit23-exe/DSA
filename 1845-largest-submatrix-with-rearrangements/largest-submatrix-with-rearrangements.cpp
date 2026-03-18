class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]== 1 && i-1>=0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
            vector<int> row = matrix[i];
            sort(begin(row),end(row),greater<int>());

           
            for(int j = 0; j < n; j++){
                int h = row[j];
                int b = j + 1;
                ans = max(ans, b * h);
            }
        }

        return ans;
    }
};