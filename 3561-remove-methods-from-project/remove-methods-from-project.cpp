class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //making the adjlist
        unordered_map<int,vector<int>>adj;
        for(auto &e:invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<bool>vis(n,false);
        vector<bool>suspicious(n,false);

        queue<int>que;
        que.push(k);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            if(vis[u]) continue;
            vis[u]=true;
            suspicious[u]=true;
            for(auto &neigh:adj[u]){
                if(vis[neigh]) continue;
                que.push(neigh);

            }
        }
        bool canRemove = true;
        for(auto &e:invocations){
            int a = e[0];
            int b = e[1];
            if(!suspicious[a] && suspicious[b])
                canRemove = false;
            
        }
        vector<int>ans;
        if(canRemove){
            for(int i=0;i<n;i++){
                if(!suspicious[i])
                    ans.push_back(i);
            }
        }else{
            for(int i=0;i<n;i++){
                
                ans.push_back(i);
            }
        }

        return ans;
    }
};