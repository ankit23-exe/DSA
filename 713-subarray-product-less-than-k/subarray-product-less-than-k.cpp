class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        if(k<=1){
            return ans;
        }
        
        int j=0;
        int p=1;
        for(int i=0;i<nums.size();i++){
            p*=nums[i];
            while(p>=k){
                p/=nums[j];
                j++;
            }
            ans+=(i-j+1);
           
        }
        
       
       
        return ans;
        
        
    }
};