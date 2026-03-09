class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        if(n==2) return nums;

        int xor_result =0;
        for(auto &x:nums){
            xor_result = xor_result ^ x;
        }
        int bitmaskcount =0;
        while(xor_result){
            if(xor_result%2==0){
                xor_result/=2;
                bitmaskcount++;
            }else{
                break;
            }
        }

        int mask = 1<<bitmaskcount;

       int a = 0, b = 0;

        for(int x : nums){
            if(x & mask)
                a ^= x;
            else
                b ^= x;
        }

        return {a,b};
    }

};