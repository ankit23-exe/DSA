class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(vector<string> &board,int row,int col){
        //checking in the colum
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        //checking left diag
        int r = row;
        int c = col;
        while(r-1 >=0 && c-1>=0){
            if(board[r-1][c-1]=='Q') return false;
            r--;c--;
        }

        //checking right diag
        while(row-1 >=0 && col+1<board.size()){
            if(board[row-1][col+1]=='Q') return false;
            row--;col++;
        }



        return true;
    }
    
    void solve(vector<string> &board,int row){
        if(row>=board.size()){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<board.size();col++){
            if(isValid(board,row,col)==true){
                board[row][col]='Q';
                solve(board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        solve(board,0);
        return ans;
    }
};