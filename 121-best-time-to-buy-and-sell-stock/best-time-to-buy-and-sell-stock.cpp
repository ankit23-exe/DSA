class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>best(n,0);
        int bp = prices[n-1];
        for(int i=n-1;i>=0;i--){
            bp = max(bp,prices[i]);
            best[i]=bp;
        }
        int bans =0;
        for(int i=0;i<n;i++){
            if(prices[i]<best[i]){
                bans = max(bans,best[i]-prices[i]);
            }
        }
        return bans;
    }
};