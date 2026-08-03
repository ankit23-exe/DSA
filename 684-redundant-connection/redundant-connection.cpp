class Solution {
public:
    int find(int i,vector<int>&parent){
        if(i==parent[i]) return i;
        return parent[i]=find(parent[i],parent);
    }
    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);
        if(x_parent == y_parent) return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[y_parent]=x_parent;
            rank[x_parent]+=1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int>rank(n+1,0);

        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int pu = find(u,parent);
            int pv = find(v,parent);

            if(pu==pv){
                return e;
            }
            Union(u,v,parent,rank);
        }
        return {};


        
    }
};