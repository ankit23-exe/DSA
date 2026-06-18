class Solution {
public:
     vector<vector<int>> ans;
    void solve(vector<bool> &used,vector<int>& nums,vector<int> &temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        } 

        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            } 
            temp.push_back(nums[i]);
            used[i]=true;
            solve(used,nums,temp);
            temp.pop_back();
            used[i]=false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<bool> used(nums.size(),false);
        vector<int> temp;
        solve(used,nums,temp);
        return ans;
    }
};