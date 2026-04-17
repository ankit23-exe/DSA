class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp; //reverse vale : idx
        int ans =INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                ans = min(ans,abs(i-mp[nums[i]]));
            }
            string r_num = to_string(nums[i]);
            reverse(r_num.begin(),r_num.end());
            mp[stoi(r_num)]=i;

        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};