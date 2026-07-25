class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxFreq = 0;
        int maxlen = 0;
        while (j < n) {

            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            int window = j - i + 1;
            if (window - maxFreq <= k) {
                maxlen = max(maxlen, window);
            }
            while (window - maxFreq > k) {
                
                // need to recompute maxFreq
                maxFreq = 0;
                for (auto& it : mp) {
                    maxFreq = max(maxFreq, it.second);
                }
                mp[s[i++]]--;
                window = j - i + 1;
            }
            j++;
        }
        return maxlen;
    }
};