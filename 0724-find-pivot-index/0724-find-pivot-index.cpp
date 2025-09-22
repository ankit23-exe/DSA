class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int csum=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            if(csum==sum){
                return i;
            }
            csum+=nums[i];
        }
        return -1;
        
    }
};