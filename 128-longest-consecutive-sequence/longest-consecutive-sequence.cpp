class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int &n:nums){
            set.insert(n);
        }
        int curCount =0;
        int ans =0;

        for(auto &n:set){
            if(set.count(n-1)) continue; //if i found previous then skip the current

            int value = n; //start point 100
            while(set.count(value)){
                value++;
                curCount++;   
            }

            ans = max(curCount,ans);
            curCount = 0;
        }
        return ans;
    }
};