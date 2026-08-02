class Solution {
public:
    int t[201][20001];
    bool solve(int i, vector<int>& nums,int target){
        if(target<0) return false;
        if(target==0) return true;
        if(i>=nums.size())return false;

        if(target>=0 && t[i][target]!=-1) return t[i][target];

        
        if(solve(i+1,nums,target-nums[i])||
        solve(i+1,nums,target)){
            if(target>=0) return t[i][target]=true;
            return true;

        } 

        if(target>=0) return t[i][target]=false;
        return false;

    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        if(totalsum%2!=0) return false;
        int target = totalsum/2;
        return solve(0,nums,target);
        
        
    }
};