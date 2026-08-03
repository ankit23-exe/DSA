class Solution {
public:
    int m,n;
    vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
    bool traverse(int i,int j,int k,vector<vector<bool>>&vis,vector<vector<char>>& board, string &word){
            vis[i][j]=true;
            k++;
            if(k==word.size()) return true;

            for(auto &d:direction){
                int newi = i+d[0];
                int newj = j+d[1];

                if(newi<0||newj<0 ||newi>=m ||newj>=n) continue;

                if(board[newi][newj]==word[k] && !vis[newi][newj]){
                    if(traverse(newi,newj,k,vis,board,word)) return true;
                }
            }
            vis[i][j]=false;

            return false;
        };




    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int k = 0;
                vector<vector<bool>>vis(m,vector<bool>(n,false));
                if(board[i][j]==word[k]){
                    if(traverse(i,j,k,vis,board,word)) return true;

                }
            }
        }

        return false;
        
    }
};