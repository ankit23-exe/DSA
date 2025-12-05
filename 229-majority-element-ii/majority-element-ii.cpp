class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for (int num : nums) {
            if (mp.find(num) != mp.end()) {
                mp[num]++;
            } else {
                mp[num] = 1;
            }
        }
        for (auto item : mp) {
            if (item.second > (n / 3)) {
                ans.push_back(item.first);
            }
        }
        return ans;
    };
};