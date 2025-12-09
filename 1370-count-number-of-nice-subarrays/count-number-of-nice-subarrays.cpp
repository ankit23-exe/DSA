class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // cout of odd no. :freq
        int ans = 0;
        int odd_count=0;
        mp[0] = 1;   // 0 odd number , freq 1
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]%2!=0){
                odd_count++;
            }
            if (mp.find(odd_count-k) != mp.end()) {
                ans += mp[odd_count-k];
            }
               
           
            mp[odd_count]++;
            
        }
        return ans;
    }
};