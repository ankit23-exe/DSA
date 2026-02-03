class Solution {
public:

    bool bipartiteBFS(vector<vector<int>>& adj,int curr,vector<int> &color,int curcol){
        queue<int> que;
        que.push(curr);
        color[curr]=curcol;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto v:adj[u]){
                if(color[v]==color[u]) return false;
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    que.push(v);
                }
            }
           
        }
         return true;

    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n,-1);

        for(int i =0;i<n;i++){
            if(color[i]==-1){
                if(bipartiteBFS(adj,i,color,1)==false) return false;
            }
        }

        return true;

    }
};