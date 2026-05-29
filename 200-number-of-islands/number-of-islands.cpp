class Solution {
public:
    int m ;
    int n;
    vector<vector<int>>direction = {{0,-1},{-1,0},{0,1},{1,0}};
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> que;
        que.push({i,j});
        while(!que.empty()){
            auto p = que.front();
            que.pop();
            grid[p.first][p.second]='0';
            for(auto &d:direction){
                int newi = p.first+d[0];
                int newj = p.second+d[1];
                if(newi>=0 && newi<m && newj >=0 && newj <n){
                    if(grid[newi][newj]=='1'){
                        que.push({newi,newj});
                        grid[newi][newj]=0;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count =0;
         m = grid.size();
         n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid);
                }
            }
        }
        return count;

    }
};