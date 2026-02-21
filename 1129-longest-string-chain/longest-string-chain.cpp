class Solution {
public:
   int dp[1001][1001];
    bool check(string &word1, string &word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int k = 0;
        for (int i = 0; i < len2; i++) {
            if (k < len1 && word1[k] == word2[i]) {
                k++;
            }
        }
        if (k == len1 && len2-len1 == 1)
            return true;
        else
            return false;
    }
    int solve(int i, int p, vector<string>& words) {

        if (i >= words.size())
            return 0;
        if (dp[i][p + 1] != -1)
            return dp[i][p + 1];
        int take = 0;
        if (p == -1 || check(words[p], words[i])) {
            take = 1 + solve(i + 1, i, words);
        }
        int skip = solve(i + 1, p, words);

        return dp[i][p + 1] = max(take, skip);
    }
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        memset(dp, -1, sizeof(dp));
        return solve(0, -1, words);
    }
};