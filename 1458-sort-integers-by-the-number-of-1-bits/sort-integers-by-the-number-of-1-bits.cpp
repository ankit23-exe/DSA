class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> mp;
        for(int x:arr){
            mp[__builtin_popcount(x)].push_back(x);
        }
        vector<int> ans;
        for(auto &p:mp){
            sort(p.second.begin(),p.second.end());
            for(auto x:p.second){
                ans.push_back(x);
            }
        }
        return ans;
    }
};