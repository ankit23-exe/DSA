class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int count = 0;
        for(int i =0;i<k;i++){
            if(s[i]=='a' || s[i]=='e'||s[i]=='i' || s[i]=='o'||s[i]=='u'){
                count++;
            }
        }
        int ans =count;

        for(int j = k;j<n;j++){
            if(s[j]=='a' || s[j]=='e'||s[j]=='i' || s[j]=='o'||s[j]=='u'){
                count++;
            }
            if(s[j-k]=='a' || s[j-k]=='e'||s[j-k]=='i' || s[j-k]=='o'||s[j-k]=='u'){
                count--;
            }
            ans=max(ans,count);


        }
        return ans;
        
    }
};