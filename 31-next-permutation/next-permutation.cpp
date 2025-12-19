class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag=0;
        int n=nums.size();
        for(int i=n-1;i>0;i-- ){
            if(nums[i-1]<nums[i]){
                flag=1;
            }
        }
        if(flag==0){
            int i=0,j=n-1;
            while(i<j){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
             return ;
        }
       

        int pid=-1;
        
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                pid=i-1;
                 break;
            }
           
        }
        int j=n-1;

        while(j>=0){
            if(nums[j]>nums[pid]){
                break;
            }
            j--;
        }

        swap(nums[pid],nums[j]);

        pid++;

        j=n-1;
        while(pid<j){
            swap(nums[pid],nums[j]);
            pid++;
            j--;
        }
        return;
    }
};