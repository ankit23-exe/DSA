class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        unordered_map<int, vector<int>> adjlist;
    

        // adjlist making
        for (auto& e : richer) {
            adjlist[e[0]].push_back(e[1]);
            
        }
        int n = quiet.size();
        // calcuating the indgree
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++) {
            for (int& v : adjlist[u]) {
                indegree[v]++;
            }
        }
        queue<int> que;
        // putting those into the queue who have 0 indegree
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                que.push(u);
            }
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }
        // the final bfs
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int& v : adjlist[u]) {

                if (quiet[ans[u]] < quiet[ans[v]]) {
                    ans[v] = ans[u]; // v inherits the quieter person from u's
                                     // lineage
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return ans;
    }
};