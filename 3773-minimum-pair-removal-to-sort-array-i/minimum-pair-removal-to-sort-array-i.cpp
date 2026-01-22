class Solution {
public:
    bool check(vector<int>& nums){   // to check if its already sorted or not
        for(int i = 1 ; i <nums.size();i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0 ;
        if(check(nums)){
            return 0;
        }
        while(true){
            int minidx = -1;
            int minpairsum = INT_MAX;
            for(int i = 1 ; i <nums.size();i++){
                if(nums[i]+nums[i-1]<minpairsum){
                    minpairsum = nums[i]+nums[i-1];
                    minidx = i;
                }
            }
            nums[minidx]=minpairsum;
            //i-1 indx delete krna hai 
            nums.erase(nums.begin() + minidx-1);

            count++;

            if(check(nums)){
                break;
            }
        }

        return count;
    }
};