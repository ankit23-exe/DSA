class Solution {
public:
    bool compare(vector<int>& vecS, vector<int>& vecT) {
        for (int i = 0; i < 125; i++) {
            if (vecT[i] > vecS[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n > m)
            return "";

        vector<int> vecT(125);
        vector<int> vecS(125);

        string ans;
        string ansfinal;
        int minlen = INT_MAX ;
        int left =0;

            // processing string t
        for (int i = 0; i < t.size(); i++) {
            vecT[t[i]]++;
        }

        // generating all possible window in s
        for (int i = 0; i < n; i++) {
            vecS[s[i]]++;
            ans += s[i];
        }
        if (compare(vecS, vecT))
            return ans;

        for (int i = n; i < m; i++) {
            vecS[s[i]]++;

            ans += s[i];
            if (compare(vecS, vecT)) {

                if (ans.size() < minlen) {
                    ansfinal = ans;
                    minlen = ans.size();

                }
                while (compare(vecS, vecT)) {
                    vecS[s[left]]--;   // <-- Fixed
                    ans.erase(0, 1);
                    left++;            

                    if (compare(vecS, vecT)) {
                        if (ans.size() < minlen) {
                            ansfinal = ans;
                             minlen = ans.size();
                        }
                    }
                }
            }
        }

        return ansfinal;
    }
};