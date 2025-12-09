class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        
        int oddcount=0;
        int precount=0;
        int result=0;

        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]%2!=0){  //num odd hai toh
                oddcount++;
                precount=0;
            }
            while(oddcount==k){
                precount++;

                if(i<n && nums[i]%2 ==1){   // odd number hai 
                    oddcount--;
                }
                i++;
            }
            result+=precount;
            j++;
        }

        return result;
    }
};