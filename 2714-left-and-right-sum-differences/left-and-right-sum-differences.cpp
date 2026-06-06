class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        int lsum = nums[0];
        for(int i=1;i<n;i++){
            leftsum[i]=lsum;
            lsum+=nums[i];
        }

        int rsum = nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rsum;
            rsum+=nums[i];
        }

        for(int i=0;i<n;i++){
            leftsum[i]=abs(leftsum[i]-rightsum[i]);
        }

        return leftsum;


        
    }
};