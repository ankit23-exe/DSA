class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        vector<vector<int>>ans;
        ans.push_back({1});

        for(int i=1;i<numRows;i++){
            vector<int>currow;
            for(int j=0;j<=ans[i-1].size();j++){
                int num =0;
                if(j!=ans[i-1].size()){
                    num = ans[i-1][j];
                }
                if(j-1>=0){
                    num += ans[i-1][j-1];
                }
                currow.push_back(num);
            }
            ans.push_back(currow);
        }
        return ans;
    }
};