class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans;
        if(nums[n/2]==nums[n-1]){   // if(mid ele == last ele)
            ans=nums[n-1];          // then mid is ans
        }else{                      // else 
            ans=nums[(n/2)-1];      //  mid-1 ele is ans
        }
        return ans;
    }
};