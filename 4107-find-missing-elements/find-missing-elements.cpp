class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minN = *min_element(nums.begin(),nums.end());
        int maxN = *max_element(nums.begin(),nums.end());

        unordered_set<int> set;
        for(auto &n:nums){
            set.insert(n);
        }
        vector<int>ans;
        for(int i=minN;i<=maxN;i++){
            if(!set.count(i)){
                ans.push_back(i);

            }
        }
        return ans;
    }
};