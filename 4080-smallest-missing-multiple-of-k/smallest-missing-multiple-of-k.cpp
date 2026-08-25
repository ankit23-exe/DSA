class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(auto &n:nums){
            set.insert(n);
        }
        int multiple = 1;
        while(true){
            if(set.count(k*multiple)){
                multiple++;
            }else{
                return k*multiple;
            }
        }
        return -1;
    }
};