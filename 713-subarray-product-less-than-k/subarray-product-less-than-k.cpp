class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        while(i<nums.size()){
            int r=i;
            int p=1;
            while(r<nums.size()){
                if(p*nums[r]<k){
                    ans++;
                    p*=nums[r];
                    r++;
                }else{
                    break;
                }
            }
            i++;
        }
        return ans;
        
        
    }
};