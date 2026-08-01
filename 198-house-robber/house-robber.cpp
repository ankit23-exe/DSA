class Solution {
public:
    int t[101][101];
    int solve(int i,int pidx,vector<int>& nums){
        if(i>=nums.size()) return 0;

        if(pidx!=-1 && t[i][pidx]!=-1) return t[i][pidx];
        int take =0;
        if(pidx==-1 || pidx!=i-1){
            take = nums[i]+solve(i+1,i,nums);
        }
        int skip = solve(i+1,pidx,nums);
        if(pidx!=-1) return t[i][pidx]=max(take,skip);
        return max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));

        return solve(0,-1,nums);
    }
};