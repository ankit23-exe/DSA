class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sumAns =INT_MAX;
        int minDiff = INT_MAX;
        for(int i=0;i<n-1;i++){
            int left = target-nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                int diff = abs(left-(nums[l]+nums[r]));
                if(diff<=minDiff){
                    minDiff = diff;
                    sumAns = nums[i]+nums[l]+nums[r];
                }
                if((nums[l]+nums[r])>left){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return sumAns;
    }
};