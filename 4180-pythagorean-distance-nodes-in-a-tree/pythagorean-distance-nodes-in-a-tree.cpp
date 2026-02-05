class Solution {
public:
    vector<int> djkista(int src, vector<vector<pair<int,int>>> &adj){
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(adj.size(),INT_MAX);  // wt, node
        result[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            for(pair<int,int> &p:adj[u]){
                int v =p.first;
                int v_wt = p.second;
                if(wt+v_wt<result[v]){
                    result[v]=wt+v_wt;
                    pq.push({wt+v_wt,v});
                }
            }
        }
        return result;
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        //making the adjancy list
        vector<vector<pair<int,int>>> adj(n);  //node , wt
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }

        //now we will calculate the dx , dy, dz vector which contain all the distance of each node from that x node , okay
        vector<int> dx = djkista(x,adj);
        vector<int> dy = djkista(y,adj);
        vector<int> dz = djkista(z,adj);


        int ans=0;
        for(int i =0;i<n;i++){
            vector<int>sample;
            sample.push_back(dx[i]);
            sample.push_back(dy[i]);
            sample.push_back(dz[i]);
            sort(sample.begin(),sample.end());

            if((1LL*sample[0]*sample[0] +1LL*sample[1]*sample[1]) == 1LL*sample[2]*sample[2] ){
                ans++;
            }
        }
        return ans;
    }
};