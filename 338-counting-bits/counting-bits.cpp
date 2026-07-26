class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int>ans(n+1);
        for(int i=1;i<=n;i++){
            if(i%2!=0){ //odd number
                ans[i]=ans[i-1]+1;
            }else{
                ans[i]=ans[i/2];
            }
        }
        return ans;
    }
};