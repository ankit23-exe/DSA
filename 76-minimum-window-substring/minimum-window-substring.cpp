class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> map;
        for (char& c : t) {
            map[c]++;
        }
        int countRequired = t.size();
        int i = 0, j = 0;
        int minWindow = INT_MAX;
        int start_idx = 0;
        int curWindow = 0;

        while (j < s.size()) {

            if (map[s[j]] > 0)
                countRequired--;
            map[s[j]]--;

            // shringking window if we found

            // shrinking krta hai
            while ( countRequired == 0) {
                curWindow = j-i+1;
                if (curWindow<minWindow) {
                    minWindow = curWindow;
                    start_idx = i;
                }

                map[s[i]]++;
                if (map[s[i]] > 0) {
                    countRequired++;
                }
                i++;
            }

            j++;
        }

        if (minWindow == INT_MAX)
            return "";
        return s.substr(start_idx, minWindow);
    }
};