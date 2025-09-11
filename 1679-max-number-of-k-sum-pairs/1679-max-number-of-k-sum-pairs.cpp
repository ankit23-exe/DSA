class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int i=0;
        int j=nums.size()-1;
        int count =0;

        while(i<j){
            if(nums[i]+nums[j]==k){
                count++;
                i++;
                j--;
            }
            while((nums[i]+nums[j])<k){
                i++;
            }
             while((nums[i]+nums[j])>k){
                j--;
            }


        }
        return count;
        
    }
};