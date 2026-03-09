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

        vector<int> group1;
        vector<int> group2;

        for(auto &x:nums){
            if(x & mask){
                group1.push_back(x);
            }else{
                group2.push_back(x);
            }
        }

        int c1 = 0;
        for(auto x:group1){
            c1 = c1 ^ x;
        }

        int c2 = 0;
        for(auto x:group2){
            c2 = c2 ^ x;
        }

        return {c1,c2};
    }

};