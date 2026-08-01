class Solution {
public:
    int t[301][5001];
    int solve(int idx,int amount, vector<int>& coins){
        if(idx>=coins.size()) return 0;
        if(amount==0) return 1;
        if(t[idx][amount]!=-1) return t[idx][amount];
        //take 
        int take=0;
        if(amount>=coins[idx])
            take = solve(idx,amount-coins[idx],coins);

        int skip = solve(idx+1,amount,coins);

        return t[idx][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
        int n = coins.size();
        return solve(0,amount,coins);

    }
};