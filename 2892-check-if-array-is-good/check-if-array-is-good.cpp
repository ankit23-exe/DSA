class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        sort(nums.begin(),nums.end());

        if(nums[n-1]!=nums[n-2]) return false;

        if(n==2){
            if( nums[0]== 1) return true;
            else return false;
        } 

        if(nums[0]!=1){
            return false;
        }

        for(int i=0;i<=n-3;i++){
            if(nums[i]+1 !=nums[i+1]){
                return false;
            }
        }
        return true;
    }
};