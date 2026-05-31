class Solution {
public:
    int m, n;
    int directions[4][2] = {
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

            if (i == m - 1 && j == n - 1) return cost;

            for(auto &d:directions){
                int newi = i+d[0];
                int newj = j+d[1];
                if(newi<0 || newj<0 || newi>=m || newj>=n) continue;
                int effort = max(cost, abs(heights[newi][newj] - heights[i][j]));
                if(effort<visited[newi][newj]){
                    visited[newi][newj]=effort;
                    pq.push({effort,{newi,newj}});
                }
            }
        }
        return visited[m-1][n-1];
        
    }
};