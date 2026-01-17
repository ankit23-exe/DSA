class Solution {
public:
    vector<int> t;
    int solve(int i ,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        } 
        //memorisation use kr rha hai
        if(t[i]!=-1){
            return t[i];
        }

        //steal
        int steal = nums[i] +solve(i+2,nums);
        //skip
        int skip = solve(i+1,nums);

        return t[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        t.resize(nums.size()+1 ,-1);
        return solve(0,nums);
    }
};