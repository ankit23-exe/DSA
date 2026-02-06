class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());

        int l = 0;
        int i=0;
        int j=0;

        while(j<n && i<n){
            if(1LL*nums[j]<=1LL*k*nums[i]){
                l = max(l,j-i+1);
                j++;
            }else{
                i++;
            }
        }
        return n-l;
        
    }
};