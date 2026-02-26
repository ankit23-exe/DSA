class Solution {
public:
    void solve(int &ans,vector<bool> &check,int idx){
        if(idx > check.size()-1){
            ans+=1;
            return;
        }

        for(int i=1;i<check.size();i++){
            if(check[i]==false){
                if(i%idx == 0 || idx%i == 0){
                    check[i]=true;
                    solve(ans,check,idx+1);
                    check[i]=false;
                }
            }
        }
    }
    int countArrangement(int n) {
        int ans =0;
        vector<bool> check(n+1,false);
        
        solve(ans,check,1);
        return ans;
    }
};


