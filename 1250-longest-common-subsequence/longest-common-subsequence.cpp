class Solution {
public:
    // int t[1001][1001];
    // int n1,n2;
    // int solve(int p1,int p2,string &text1, string &text2){
    //     if(p1>=n1 || p2>=n2) return 0;

    //     if(t[p1][p2]!=-1) return t[p1][p2];
    //     if(text1[p1]==text2[p2]){
    //         return t[p1][p2] = 1+solve(p1+1,p2+1,text1,text2);
    //     }
        
    //     //once skipping from p1 and once from p2
    //     return t[p1][p2]=max(solve(p1+1,p2,text1,text2),solve(p1,p2+1,text1,text2));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(t,-1,sizeof(t));
        int m = text1.size();
        int n = text2.size();
        if(text1==text2) return n;
        // return solve(0,0,text1,text2);
        vector<vector<int>>t(m+1,vector<int>(n+1,0));

        //first row and first col will be zero,
        //t[i][j] mtlb ya hai ki , string1 i length ka and 
        //string2 j length ka, toh unka max kya ayega

        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        } 
        return t[m][n];

    }
};