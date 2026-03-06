class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        if(n==1) return true;
        if(s[1]==0) return false;
        int i;
        for(i=1;i<n;i++){
            if(s[i]=='0') break;
        }

        while(i<n){
            if(s[i]=='1') return false;
            i++;
        }

        return true;
    }
};