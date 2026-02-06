class Solution {
public:
    vector<vector<int>> t;
    int solve(int i, int p,vector<int>& nums){
        if(i>=nums.size()){
            return 0;
        }

        if(t[i][p+1]!=-1){
            return t[i][p+1];
        }

        //take
        int take=0;
        if(p==-1 || nums[p]<nums[i]){
            take = 1+ solve(i+1,i,nums);

        }
        //skip
        int skip = solve(i+1,p,nums);

        return t[i][p+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        t.resize(nums.size()+1,vector<int> (nums.size(),-1));
       
        return solve(0,-1,nums); //i , p
    }
};