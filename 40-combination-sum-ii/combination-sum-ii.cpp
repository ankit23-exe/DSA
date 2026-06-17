class Solution {
public:
    vector<vector<int>>finalarray;
    void solve(int idx,int cursum,vector<int>&curarray,vector<int>& candidates, int target){
        if(cursum>target) return;
        if(cursum==target){
            finalarray.push_back(curarray);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
             if(i > idx && candidates[i] == candidates[i-1])
            continue;
            curarray.push_back(candidates[i]);
            solve(i+1,cursum+candidates[i],curarray,candidates,target);
            curarray.pop_back();
            
        }

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curarray;
        sort(candidates.begin(),candidates.end());
        solve(0,0,curarray,candidates,target); //idx,cursum,curarray,candidate,target
        return finalarray;
    }
};