class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1;
        map<char, int> mp2;

        for (auto c : word1) {
            mp1[c]++;
        }

        for (auto c : word2) {
            mp2[c]++;
        }
        vector<int> v1, v2;

        for (auto& p : mp1)
            v1.push_back(p.second);
        for (auto& p : mp2)
            v2.push_back(p.second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

         vector<int> v3, v4;

        for (auto& p : mp1)
            v3.push_back(p.first);
        for (auto& p : mp2)
            v4.push_back(p.first);

        sort(v3.begin(), v3.end());
        sort(v4.begin(), v4.end());


        return v1==v2 && v3==v4;
    }
};