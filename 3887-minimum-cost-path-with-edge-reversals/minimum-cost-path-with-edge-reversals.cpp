class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        //making adjancy list
        vector<vector<pair<int,int>>> adj(n); //{{node,dist},{nod2,dist2}}

        for(auto &ed:edges){
            int u = ed[0];
            int v = ed[1];
            int wt = ed[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }

        //making priority_queue
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; //it is a min heap for the source 
        //pq --> {dist,node}
        //source is 0

        vector<int> result(n,INT_MAX);
        result[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &p:adj[node]){
                int adjnode= p.first;
                int wt = p.second;
                if(d+wt<result[adjnode]){
                    result[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }

        if(result[n-1] == INT_MAX) return -1;
        else  return result[n-1];   
       
    }
};