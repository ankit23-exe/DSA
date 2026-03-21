class Solution {
public:
    void addToSet(set<int> &set,int v){
        set.insert(v);
        while(set.size()>3){
            set.erase(set.begin());
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> set;
        
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                addToSet(set,grid[r][c]);
                //side length looping
                for(int side =1;r-side>=0 && r+side<m && c-side>=0 && c+side<n;side++){
                    //loping over the diagonal to cal the sum
                    int sum=0;
                    for(int k=0;k<side;k++){
                        sum+=grid[r-side+k][c+k];
                        sum+=grid[r+k][c-side+k];
                        sum+=grid[r+k][c+side-k];
                        sum+=grid[r-side+k][c-k];
                    }
                    sum+=grid[r+side][c];
                    sum -= grid[r-side][c];
                    addToSet(set,sum);

                }
            }
        }
        vector<int> temp;
        for(auto x:set){
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        return temp;
    }
};