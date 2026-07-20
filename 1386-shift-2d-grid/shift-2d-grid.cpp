class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();
        k%=m*n;
        int total = m*n;
        if(k==0) return grid;


        auto reverse =[&](int i ,int j){
            while(i<j){
                int rowi= i/n;
                int coli =i%n;

                int rowj= j/n;
                int colj = j%n;

                swap(grid[rowi][coli],grid[rowj][colj]);
                i++;
                j--;
                
            }
        };
        reverse(0,total-1);
        reverse(0,k-1);
        reverse(k,total-1);

        return grid;
        
    }
};