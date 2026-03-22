class Solution {
public:
    bool compare(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    void transpose(vector<vector<int>>& mat){
        int n= mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        //vector<vector<int>> mat2 = mat;

        if(compare(mat,target)) return true;
        

        transpose(mat);
        for(int i=0;i<n;i++){
            int s =0;
            int e = n-1;
            while(s<e){
                swap(mat[i][s],mat[i][e]);
                s++;e--;
            }
        }
        if(compare(mat,target)) return true; //1st round

        transpose(mat);
        for(int i=0;i<n;i++){
            int s =0;
            int e = n-1;
            while(s<e){
                swap(mat[i][s],mat[i][e]);
                s++;e--;
            }
        }

        if(compare(mat,target)) return true; //2nst round


         transpose(mat);
        for(int i=0;i<n;i++){
            int s =0;
            int e = n-1;
            while(s<e){
                swap(mat[i][s],mat[i][e]);
                s++;e--;
            }
        }

        if(compare(mat,target)) return true; //3rd round

        return false;
        
        
    }
};