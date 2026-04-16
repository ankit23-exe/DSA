class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: map value -> indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        // Step 2: process each query
        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            // only one occurrence
            if (vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // find position using binary search
            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            
            int prev = vec[(idx - 1 + vec.size()) % vec.size()];
            int next = vec[(idx + 1) % vec.size()];
          
            int d1 = min(abs(q - prev), n - abs(q - prev));
            int d2 = min(abs(q - next), n - abs(q - next));
            
            ans.push_back(min(d1, d2));
        }
        
        return ans;
    }
};