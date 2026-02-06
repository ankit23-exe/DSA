class Solution {
public:
    void dfs(int u,vector<vector<int>>& isConnected,vector<bool>&vis){
        vis[u]=true;
        for(int i=0;i<isConnected.size();i++){
            int v=isConnected[u][i];
            if(v==1  && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);

        int count =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                count++;
            }
        }
        return count;
    }
};