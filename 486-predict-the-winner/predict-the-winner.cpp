class Solution {
public:
    int t[21][21];
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(i==j) return nums[i];

        if(t[i][j]!=-1) return t[i][j];

        int takei = nums[i]+ min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej = nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return t[i][j]=max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();
        int totalScore = accumulate(nums.begin(),nums.end(),0);
        int p1Score = solve(0,n-1,nums);
        int p2Score = totalScore-p1Score;

        return p1Score>=p2Score;


    }
};