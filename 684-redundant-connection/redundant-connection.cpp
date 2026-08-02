class Solution {
public:
    int n;
    bool checkConnection(unordered_map<int,vector<int>>&adj,int u,int v){        //true mtlb connection hai
        vector<bool>vis(n,false);
        queue<int>que;
        que.push(u);
        while(!que.empty()){
            int f = que.front();
            que.pop();
            if(vis[f]==true) continue;
            vis[f]=true;
            for(int neigh:adj[f]){
                if(neigh==v) return true;
                if(vis[neigh]==false){
                    que.push(neigh);
                }
            }

        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(auto &e:edges){
            int u = e[0];
            int v=e[1];
            if(adj.count(u) && adj.count(v) && checkConnection(adj,u,v)){
                return e;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        return {};
    }
};