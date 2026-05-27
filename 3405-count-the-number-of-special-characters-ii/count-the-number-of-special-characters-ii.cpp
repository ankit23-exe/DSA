class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool,bool>> pres(26,{false,false});
        for(char c:word){
            int idx = c>'Z'?c-'a':c-'A';
            if(c>='a' && c<='z'){
                if(!pres[idx].second){
                    pres[idx].first=true;
                }else if(pres[idx].second){
                    pres[idx].first = false;
                }
            }else if(c>='A' && c<='Z'){
                if(pres[idx].first){
                    pres[idx].second = true;
                }else if(!pres[idx].second){
                    pres[idx].second = true;
                }
            }
        }
        int ans = 0;
        for(auto p:pres){
            if(p.first && p.second) ans++;
        }
        return ans;
    }
};