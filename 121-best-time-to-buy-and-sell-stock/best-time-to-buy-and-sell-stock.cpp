class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int flag = true;
        // int temp = prices[0];
        // for(int i=1;i<n;i++){
        //     int p = prices[i];
        //     if(temp<p){
        //         flag= false;
        //         break;
        //     }
        //     temp=p;
        // }
        // if(flag) return 0;

        vector<int>rightmax(n,0);
        int rmax = prices[n-1];
        for(int i=n-1;i>=0;i--){
            rightmax[i]=rmax;
            rmax=max(prices[i],rmax);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,rightmax[i]-prices[i]);
        }
        return ans;
    }
};