class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixsum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                prefixsum+=nums[i];
            }else{
                break;
            }
        }

        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=prefixsum){
                set.insert(nums[i]);
            }
        }
        while(1){
            if(!set.count(prefixsum)){
                return prefixsum;
            }
            prefixsum++;
        }

        return -1;
    }
};