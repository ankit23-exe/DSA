class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(int i=0;i<strs.size();i++){ //strs pr loop laga diya
            string org=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(mp.find(strs[i])!=mp.end()){
                mp[strs[i]].push_back(org);
            }else{
                mp[strs[i]].push_back(org);
            }

        }
        vector<vector<string>> ans;
        for(auto item:mp){
            ans.push_back(item.second);
        }
        return ans;
    }
};