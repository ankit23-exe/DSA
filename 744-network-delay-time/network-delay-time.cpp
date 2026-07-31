class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        vector<int>visited(n+1,false);
       
        //making the adjlist
        unordered_map<int,vector<pair<int,int>>>adjlist; // u, {v,wt}
        for(auto &p:times){
            int u =p[0];
            int v = p[1];
            int wt = p[2];
            adjlist[u].push_back({v,wt});
        }

        priority_queue< pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> >pq;
                        //wt , v

        //dijikstra thing here
        pq.push({0,k}); // mean zero time pr , we are at current node k 

        while(!pq.empty()){
            
            auto f = pq.top();
            pq.pop();
            int u = f.second;
            int wt = f.first;
            if(visited[u]) continue;
            visited[u]=true;
            for(auto &neigh:adjlist[u]){
                int v = neigh.first;
                int t = neigh.second;
                if(distance[v] > wt+t){
                distance[v]=wt+t;
                pq.push({wt+t,v});
                }
                
                
            }
        }

        //
        int maxVal = 0;
        for(int i=1;i<distance.size();i++){
            int d = distance[i];
            if(d==INT_MAX) return -1;
            maxVal = max(maxVal,d);

        }
        return maxVal;

    }
};