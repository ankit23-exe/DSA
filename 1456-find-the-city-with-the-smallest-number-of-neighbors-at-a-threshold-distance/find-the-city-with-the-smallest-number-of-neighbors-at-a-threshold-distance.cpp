class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjmatrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            adjmatrix[i][i]=0;
        }
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adjmatrix[u][v]=wt;
            adjmatrix[v][u]=wt;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjmatrix[i][via]==INT_MAX || adjmatrix[via][j]==INT_MAX ) continue;
                    adjmatrix[i][j] = min(adjmatrix[i][j],adjmatrix[i][via]+adjmatrix[via][j]);
                }
            }
        }
        int node = 0;
        int minreach = INT_MAX;
        for(int i=0;i<n;i++){
            int curreach = 0;

            for(int j=0;j<n;j++){
                if(adjmatrix[i][j]<=distanceThreshold){
                    curreach++;
                }
            }
            if(curreach<=minreach){
                minreach = curreach;
                node = i;
            }

        }
        return node; 
    }
};