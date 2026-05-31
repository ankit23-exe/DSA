class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {
        {0, -1}, // Left
        {-1, 0}, // Up
        {0, 1},  // Right
        {1, 0},  // Down
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq; //mindiff,(i,j)
        vector<vector<int>> visited(m,vector<int>(n,INT_MAX));
        
        visited[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int i = f.second.first;
            int j = f.second.second;
            int cost = f.first;

            for(auto &d:directions){
                int newi = i+d[0];
                int newj = j+d[1];
                if(newi<0 || newj<0 || newi>=m || newj>=n) continue;
                int v1 = cost;
                int v2 = abs(heights[newi][newj]-heights[i][j]);
                if(max(v1,v2)<visited[newi][newj]){
                    visited[newi][newj]=max(v1,v2);
                    pq.push({max(v1,v2),{newi,newj}});
                }
            }
        }
        return visited[m-1][n-1];
        
    }
};