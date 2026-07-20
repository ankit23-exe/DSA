class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        k%=m*n;
        vector<int>numbers;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                numbers.push_back(grid[i][j]);
            }
        }
        // for(int i=0;i<m*n;i++){
        //     numbers[(i+k)%(m*n)]=numbers[i];
        // }
        reverse(numbers.begin(),numbers.end());
        reverse(numbers.begin(),numbers.begin()+k);
        reverse(numbers.begin()+k,numbers.end());

        int idx =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=numbers[idx++];
            }
        }

        return grid;
    }
};