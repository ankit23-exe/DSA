class Solution {
public:
    int maxVowels(string s, int k) {

        int ans = 0;
        int final = 0;
        for(int i=0;i<k;i++){
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u')){
                    ans++;
                 }
        }
        final=ans;

        for (int i = k; i < s.size(); i++) {

            int l = i - k;
            if ((s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' ||
                 s[l] == 'u')) {
                ans--;
            }
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u')) {
                ans++;
            }

            final = max(final, ans);
        }
        return final;
    }
    
    

}
;