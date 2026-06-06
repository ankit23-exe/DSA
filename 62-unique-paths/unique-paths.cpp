class Solution {
public:
    int t[101][101];
    int solve(int m,int n,int i,int j){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i>=m||j>=n||i<0||j<0){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        
        int down =0;
        int right =0;
        if(i+1<m){
            down = solve(m,n,i+1,j);
        }
        if(j+1<n){
            right = solve(m,n,i,j+1);
        }
        return t[i][j]= down+right;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return solve(m,n,0,0);
    }
};