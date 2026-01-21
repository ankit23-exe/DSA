class Solution {
public:
    int n;
    vector<vector<long long>> t;

    long long solve(vector<int>& nums,int idx,bool flag){
        if(idx>=n){
            return 0;
        }

        if(t[idx][flag]!=-1){
            return t[idx][flag];
        }

        long long skip = solve(nums,idx+1,flag);

        long long val = nums[idx];
        if(flag == false) val = -val;

        long long take = solve(nums,idx+1,!flag) + val;

        return t[idx][flag] = max(skip,take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        t.resize(n+1,vector<long long>(2,-1));

        return solve(nums,0,true); //0 idx is always added , so true represent that thing
    }
};