class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n,0);

        for(int i=0;i<n;i++){
            int zcount =0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1) break;
                else{
                    zcount++;
                }
            }
            zeros[i]=zcount;
        }

        int steps=0;
        for(int i=0;i<n;i++){
            int zeroneed = n -i -1;

            int j =i;
            while(j<n && zeros[j] < zeroneed){
                j++;
            }
            if(j==n) return -1;

            steps += j-i;

            while(j>i){
                swap(zeros[j],zeros[j-1]);
                j--;
            }
        }
        return steps;
    }
};