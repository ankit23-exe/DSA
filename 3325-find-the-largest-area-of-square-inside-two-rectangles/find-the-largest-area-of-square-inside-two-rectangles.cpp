class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        int side =0;

        for(int i =0; i<n;i++){
            for(int j=i+1;j<n;j++){

                int toprightx =min(topRight[i][0],topRight[j][0]);
                int bottomleftx =max(bottomLeft[i][0],bottomLeft[j][0]);

                int width = toprightx-bottomleftx;

                int topy = min(topRight[i][1],topRight[j][1]);
                int bottomy = max(bottomLeft[i][1],bottomLeft[j][1]);

                int height = topy-bottomy;

                side = max(side,min(height,width));
            }
 
        }
        return 1LL*side*side;
    }
};