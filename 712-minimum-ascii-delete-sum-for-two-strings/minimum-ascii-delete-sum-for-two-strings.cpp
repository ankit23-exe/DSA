class Solution {
public:
   
    int M;
    int N;
    vector<vector<int>> t;
   
    int solve(string &s1, string &s2,int i,int j){
        if(i>=M && j>=N){
            return 0;
        }

        if(t[i][j]!=-1){
            return t[i][j];
        }
       
        if(i>=M)  return s2[j] + solve(s1,s2,i,j+1);   
        if(j>=N) return s1[i] + solve(s1,s2,i+1,j);
         if(s1[i]==s2[j]){
            return solve(s1,s2,i+1,j+1);
        }
        int delete_s1_i = s1[i] + solve(s1,s2,i+1,j);
        int delete_s2_j = s2[j] + solve(s1,s2,i,j+1);
            
         
        return t[i][j]= min(delete_s1_i,delete_s2_j);  

    }
    int minimumDeleteSum(string s1, string s2) {
        M=s1.size();
        N=s2.size();
        t.resize(M+1,vector<int>(N+1,-1));
         
        return solve(s1,s2,0,0);
    }
};