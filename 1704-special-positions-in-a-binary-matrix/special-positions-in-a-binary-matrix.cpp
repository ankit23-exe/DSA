class Solution {
public:
    bool check(vector<vector<int>>& mat,int r,int c){
        
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            if(i == r) continue;
            if(mat[i][c] == 1) return false;
        }
        for(int i=0;i<n;i++){
            if(i==c) continue;
            if(mat[r][i]==1) return false;
        }

        return true;

    }
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && check(mat,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};