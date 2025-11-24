class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int p=1;
            for(int j=i;j<nums.size();j++){
                if(p*nums[j]<k){
                    ans++;
                    p*=nums[j];
                }else{
                    break;
                }

            }
        }
        return ans;
        
        
    }
};