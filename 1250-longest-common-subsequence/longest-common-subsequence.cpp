class Solution {
public:
    int t[1001][1001];
    int n1,n2;
    int solve(int p1,int p2,string &text1, string &text2){
        if(p1>=n1 || p2>=n2) return 0;

        if(t[p1][p2]!=-1) return t[p1][p2];
        if(text1[p1]==text2[p2]){
            return t[p1][p2] = 1+solve(p1+1,p2+1,text1,text2);
        }
        
        //once skipping from p1 and once from p2
        return t[p1][p2]=max(solve(p1+1,p2,text1,text2),solve(p1,p2+1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        n1 = text1.size();
        n2 = text2.size();
        if(text1==text2) return n1;
        return solve(0,0,text1,text2);

    }
};