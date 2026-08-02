class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<int> distance(n, INT_MAX);

        // making the adjlist
        unordered_map<int, vector<pair<int, int>>> adj; // u, {v,wt}
        for (auto& f : flights) {
            int u = f[0];
            int v = f[1];
            int wt = f[2];
            adj[u].push_back({v, wt});
        }
        distance[src] = 0;

        queue<pair<int, int>> que;
        que.push({0, src});
        int steps = 0;
        while (!que.empty() && steps <= k) {

            int s = que.size();

            while (s--) {
                auto [wt, u] = que.front();
                que.pop();

                for (auto neigh : adj[u]) {
                    auto [v, cost] = neigh;
                    if (wt + cost < distance[v]) {
                        distance[v] = wt + cost;
                        que.push({wt + cost, v});
                    }
                }
            }
            steps++;
        }
        if (distance[dst] == INT_MAX)
            return -1;
        return distance[dst];
    }
};