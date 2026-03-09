class Solution {
public:
    int t[101][101][101];
    int MOD = 1e9+7;
    int solve(int idx,int cost,int pmax,int n,int m,int k){
        if(idx == n){
            if(cost == k){
                return 1;
            }
            return 0;
        }

        if( t[idx][cost][pmax] != -1){
            return t[idx][cost][pmax];
        }

        int ans = 0;
        for(int i=1;i<=m;i++){
            if(i>pmax){
                ans = (ans + solve(idx+1,cost+1,i,n,m,k))%MOD;
            }else{
                ans = (ans + solve(idx+1,cost,pmax,n,m,k))%MOD;
            }
        }
        return t[idx][cost][pmax]=ans%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,0,0,n,m,k);
    }
};