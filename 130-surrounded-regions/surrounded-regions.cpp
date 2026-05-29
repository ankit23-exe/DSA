class Solution {
public:
    int m,n;
    vector<vector<int>>direction = {{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(int i, int j,vector<vector<char>>& board) {
        board[i][j]='#';
        
        for (auto &d : direction) {
            int newi = i+d[0];
            int newj = j+d[1];
            if (newi>=0 && newi<m && newj>=0 && newj<n) {
                if(board[newi][newj]=='O')
                    dfs(newi,newj,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<char>> finalboard = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             bool isBoundary = (i==0 || i==m-1 ||j==0 || j==n-1);
                if(isBoundary && board[i][j]=='O'){
                    dfs(i,j,board);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};