class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int maxx = 0;
        int smaxx =0;
        for(int i=0;i<n;i++){
            if(nums[i]>=maxx){
                smaxx=maxx;
                maxx = nums[i];   
            }else{
                if(nums[i]>smaxx){
                    smaxx = nums[i];
                }
            }
        }
        return (maxx-1)*(smaxx-1);
    }
};