class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;// 0 ko track krega
        int j =0; // non zero ko 

        while( i<n && nums[i]!=0){
            i++; //it will stop at first zero
        }
        j=i;

        while(j<n){
            while(j<n && nums[j]==0){
                j++;  // it will stoop at first non zero ,hamara first zero occur ka baad;
            }

            if(j<n){
                swap(nums[i++],nums[j++]);
            }
        }
        
    }
};