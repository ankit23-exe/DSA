class Solution {
public:
    void permu(int i,vector<int>& nums,vector<bool> &check,vector<vector<int>> &ans,vector<int> &temp){

        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int idx = 0;idx<nums.size();idx++){
            if(check[idx]==false){
                temp.push_back(nums[idx]);
                check[idx]=true;
                permu(i+1,nums,check,ans,temp);
                temp.pop_back();
                check[idx]=false;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
       
       vector<vector<int>> ans;
       vector<bool> check(nums.size(),false);
       vector<int> temp;
       permu(0,nums,check,ans,temp);

       return ans;
        

    }
};