class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        vector<int> result(n,0);
        for(int i =0;i<n;i++){
            if(nums[i]==0){
                result[i]=nums[i];
            }else if(nums[i]>0){
                int cidx = (i +nums[i])%n;
                result[i]=nums[cidx];
            }else{
                int abv = abs(nums[i])%n;
                int cidx = (i-abv+n)%n;
                result[i]=nums[cidx];
            }

        }
        return result;
    }
};