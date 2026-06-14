class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        int i=0;
        int j=0;
        while(j<n){
            while(j<n && nums[i]==nums[j]){
                j++;
            }
            if(j<n)
                swap(nums[++i],nums[j++]);
            
            
        }

        return i+1;
    }
};