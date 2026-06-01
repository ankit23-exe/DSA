class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //checking its already in desc order
        int n = nums.size();
        bool flag = true;
        int num = nums[0];
        for(int i=1;i<n;i++){
            if(num<nums[i]){
                flag = false;
                break;
            }
            num = nums[i];
        }
        if(flag){
            sort(nums.begin(),nums.end());
            return;
        }
        int i;
        for(i=n-1;i>=0;i--){
            if(nums[i-1]<nums[i]){
                break;
            }
        }
        //swap(nums[i],nums[i-1]);
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[i-1]){
                swap(nums[j],nums[i-1]);
                break;
            }
        }
        
        int j = n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return;

    }
};