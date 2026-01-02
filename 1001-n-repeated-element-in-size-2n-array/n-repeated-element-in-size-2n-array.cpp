class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto p:mp){
            if(p.second>1){
                ans=p.first;
                break;
            }
        }
        return ans;
    }
};