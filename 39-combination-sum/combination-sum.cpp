class Solution {
public:
    vector<vector<int>>finalarray;
    void solve(int idx,int cursum,vector<int>&curarray,vector<int>& candidates, int target){
        if(cursum>target) return;
        if(cursum==target){
            finalarray.push_back(curarray);
            return;
        }

        for(int i=0;i<candidates.size();i++){
            if(i<idx) continue;
            curarray.push_back(candidates[i]);
            solve(i,cursum+candidates[i],curarray,candidates,target);
            curarray.pop_back();
            
        }

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curarray;
        solve(0,0,curarray,candidates,target); //cursum,curarray,candidate,target
        return finalarray;
    }
};