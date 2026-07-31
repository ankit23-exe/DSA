class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map< vector<int> ,bool >visited;
        for(auto &p:points){
            visited[p]=false;
        }
        priority_queue<
    pair<int, vector<int>>,
    vector<pair<int, vector<int>>>,
    greater<pair<int, vector<int>>>
> pq;
        // visited[points[0]]=true;
        int ans = 0;
        pq.push({0,points[0]});

        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            if(visited[f.second]) continue;
            int fx = f.second[0];
            int fy = f.second[1];
            int wt = f.first;
            visited[f.second]=true;
            ans+=wt;
            for(auto &p:points){
                if(visited[p]) continue;     //visited hai toh skip
                int px = p[0];
                int py = p[1]; 
                int newWt = abs(px-fx)+abs(py-fy);
                //visited[p]=true;
                pq.push({newWt,p});
            }
        }

        return ans;


    }
};