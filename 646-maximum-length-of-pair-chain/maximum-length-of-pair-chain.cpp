class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int p, vector<vector<int>>& pairs) {

        if (i >= pairs.size())
            return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int take = 0;
        if (p == -1 || pairs[p][1] < pairs[i][0]) {
            take = 1 + solve(i + 1, i, pairs);
        }
        int skip = solve(i + 1, p, pairs);

        return dp[i][p+1]= max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        dp.assign(1001,vector<int>(1001,-1));
        return solve(0, -1, pairs);
    }
};