class Solution {
public:
    int M = 1000000007;
    long long modPow(long long a, long long b){
            if(b==0) return 1;
            if(b%2!=0){
                return (a%M)*modPow((a*a%M),(b-1)/2)%M;
            }else{
                return modPow((a*a%M),b/2)%M;
            }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //adjlist
        unordered_map<int,vector<int>>adjlist;
        for(auto &e:edges){
            int u= e[0];
            int v = e[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        //finding the edge count to reach the furthest node
        queue<int> que;
        vector<bool>visit(edges.size()+2,false);
        int edge_count = 0;
        que.push(1);
        visit[1]=true;
        while(!que.empty()){
            int s = que.size();
            while(s--){
                int u = que.front();
                que.pop();
                for(int v:adjlist[u]){
                    if(!visit[v]){
                        visit[v]=true;
                        que.push(v);
                    }

                }
            }
            edge_count++;

        }

        edge_count-=1;

        long long ans = modPow(2,edge_count-1);
        

        return ans;

    }
};