class Solution {
public:
    int t[2501][2501];
    int solve(int idx,int prevIdx,vector<int>& nums){
        if(idx>=nums.size()){
            return 0;
        }
        if(prevIdx>=0 && t[idx][prevIdx]!=-1) return t[idx][prevIdx];
        int take = 0;
        //take
        if(prevIdx==-1 || nums[prevIdx]<nums[idx])
            take = 1+solve(idx+1,idx,nums); //take krna ka baad ka max count kitna aa sakta hai
        //skip 
        int skip = solve(idx+1,prevIdx,nums); //if we skip toh max count kitna ayega 
        if(prevIdx>=0) return t[idx][prevIdx] = max(take,skip);
        return max(take,skip);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int prevIdx =-1;
        return solve(0,prevIdx,nums);
    }
};