class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int>t(n,0);

        t[0]=1;
        int count = 0;
        for(int j=1;j<=n-1;j++){
            if(j-minJump >=0){
                count+=t[j-minJump];
            }
            if(j-maxJump-1 >=0){
                count -=t[j-maxJump-1];
            }

            if(s[j]=='0' && count >0){
                t[j]=1;
            }
        }

        return t[n-1]>0;
    }
};