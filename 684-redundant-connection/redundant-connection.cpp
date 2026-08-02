class Solution {
public:
    int n;
    bool checkConnection(unordered_map<int, vector<int>>& adj,
                         vector<bool>& vis, int u,
                         int v) { // true mtlb connection hai

        if (u == v)
            return true;

        // if (vis[u] == true)
        //     return false;
        vis[u] = true;
        for (int& neigh : adj[u]) {

            if (vis[neigh] == false) {

                if (checkConnection(adj, vis, neigh, v))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        vector<bool> vis(n+1, false);
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            if (adj.count(u) && adj.count(v) &&
                checkConnection(adj, vis, u, v)) {
                return e;
            }
            fill(vis.begin(), vis.end(), false);
           
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};