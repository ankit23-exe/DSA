class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0; // i take care of 0
        int j=0;//will toward right and take care of 1
        int k =n-1;//k will take care of 2 

        while(j<=k){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }else{ //nums[j]==1
                j++;
            }  
        }  
    }
};