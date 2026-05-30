class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //making adjlist
        unordered_map<int,vector<pair<int,int>>>adjlist;
        for(auto &k:flights){
            adjlist[k[0]].push_back({k[1],k[2]}); //v,wt
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        vector<int> visited(n,INT_MAX);
        vector<int> stop_count(n,INT_MAX);
        visited[src] = 0;

        pq.push({0,{0,src}}); //{stopcount , {dis,node}}


        while(!pq.empty()){
            
                auto f = pq.top();
                pq.pop();
                int stop = f.first;
                int node = f.second.second;
                int dis = f.second.first;
                if(stop>k) continue;
                for(auto &neigh:adjlist[node]){
                    int nei_node = neigh.first;
                    int wt = neigh.second;
                    if(dis+wt<visited[nei_node]|| stop+1<stop_count[nei_node]){
                        visited[nei_node]=dis+wt;
                        stop_count[nei_node]=stop+1;
                        pq.push({stop+1,{dis+wt,nei_node}});
                    }
                }
               
        }







        if(visited[dst]==INT_MAX) return -1;
        return visited[dst];

        
    }
};