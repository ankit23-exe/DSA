class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};