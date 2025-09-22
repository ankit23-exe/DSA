class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long double sum=0;
        long double intsum=0;    //intsum is referening to current window sum

        for(int i =0;i<k;i++){
            intsum+=nums[i];
        }
        sum+=(intsum/k);

        for(int j =k;j<nums.size();j++){
            intsum+=nums[j];
            intsum-=nums[j-k];
            sum=max(sum,(intsum/k));

        }
        return sum;
    }

};