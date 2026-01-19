class Solution {
public:
    bool check(vector<vector<int>> &premat,vector<vector<int>> &mat,int threshold,int x1,int x2,int y1,int y2){
        int cursum=0;
        cursum += premat[x2][y2] - (x1-1>=0?premat[x1-1][y2]:0) - (y1-1>=0?premat[x2][y1-1]:0) + (x1-1>=0 && y1-1 >=0 ?premat[x1-1][y1-1]:0);
        if(cursum<=threshold){
            return true;
        }else{
            return false;
        }
    }
    int maxSideLength(vector<vector<int>> &mat,int threshold ) {
        int m = mat.size();  //row
        int n = mat[0].size();   //col
        vector<vector<int>> premat(m,vector<int> (n,0));

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                premat[i][j] = mat[i][j] + (i-1 >=0? premat[i-1][j]:0) +(j-1>=0?premat[i][j-1]:0) - (i-1>=0 && j-1 >=0 ?premat[i-1][j-1]:0);
            }
        }

        int side = min(m,n);

        while(side>=1){
            for(int i =0;i+side-1<m;i++){
                for(int j = 0;j+side-1<n;j++){
                    int x1= i;
                    int y1=j;
                    int x2=i+side-1;
                    int y2=j+side-1;
                    if(check(premat,mat,threshold,x1,x2,y1,y2)){
                        return side;
                    }
                }
            }
            side--;
        }
        return 0;
    }
};