class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(auto &s:strs){
            string key = s;
            sort(key.begin(),key.end());
            map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &p:map){
            ans.push_back(p.second);
        }
        return ans;
    }
};