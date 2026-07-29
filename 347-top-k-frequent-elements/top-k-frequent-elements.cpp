class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &n:nums){
            mp[n]++;
        }
        vector<pair<int,int>>vec;
        for(auto &p:mp){
            vec.push_back({p.second,p.first});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};