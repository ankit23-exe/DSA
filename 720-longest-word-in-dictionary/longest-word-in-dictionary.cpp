class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> set;
        for (string& s : words) {
            set.insert(s);
        }
        auto comparator = [&](const string& s1, const string& s2) {
            if (s1.size() == s2.size()) {
                return s1 < s2; // lexicographically smaller first
            }
            return s1.size() > s2.size(); // longer string first
        };
        sort(words.begin(), words.end(), comparator);

        for (string& w : words) {

            bool ok = true;

            for (int i = 1; i < w.size(); i++) {
                string prefix = w.substr(0, i);

                if (!set.count(prefix)) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return w;
        }
        return "";
    }
};