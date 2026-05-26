class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>present(26,0);
        for(auto w:word){
            if(w>='a' && w<='z'){
                if(present[w-'a']==0 ||present[w-'a']==2){
                    present[w-'a']+=1;
                }
            }else if(w>='A' && w<='Z'){
                if(present[w-'A']==0 ||present[w-'A']==1){
                    present[w-'A']+=2;
                }
            }
        }
        int ans = 0;
        for(int p:present){
            if(p==3){
                ans++;
            }
        }
        return ans;
    }
};