class Solution {
public:
    int t[10001];
    bool solve(int idx,vector<int>& nums){
        if(idx == nums.size()-1){
            return true;
        }
        if(idx>=nums.size()) return false;

        if(t[idx]!=-1) return t[idx];
        bool flag = false;
        for(int i=nums[idx];i>=1;i--){
            if(solve(idx+i,nums)){
                flag = true;
                return true;
            } 
        }
        if(flag) t[idx]=true;
        else t[idx]=false;
        
        return  false;
    }


    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};