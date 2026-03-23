class Solution {
public:
    int t[101][101];
    int solve(int x, int y, int m, int n){
        if(x==m-1 && y == n-1){
            return 1;
        }
        if(x<0 || y<0 || x>=m || y>= n){
            return 0;
        }
        if(t[x][y] != 0){
            return t[x][y];
        }

        int right = solve(x,y+1,m,n);
        int down = solve(x+1,y,m,n);

        return t[x][y] = right+ down;
    }
    int uniquePaths(int m, int n) {
        memset(t,0,sizeof(t));
        return solve(0,0,m,n);
    }
};