class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        bool wordContinue = false;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                wordContinue = true;
            }else{
                if(wordContinue){
                    ans++;
                    wordContinue = false;
                }
            }
        }
        if(wordContinue)
            ans++;
        
        return ans;
    }
};