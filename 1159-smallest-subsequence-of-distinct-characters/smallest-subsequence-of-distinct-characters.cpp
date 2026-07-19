class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>lastSeen(26);

        for(int i=0;i<n;i++){ 
            lastSeen[s[i]-'a']=i;
        }
        vector<bool>taken(26,false);

        string ans ="";

        for(int i=0;i<n;i++){
            if(taken[s[i]-'a']==true) continue;
            // if(ans==""){
            //     ans+=s[i];
            //     taken[s[i]-'a']=true;
            //     continue;
            // }
            while(ans!= "" && ans.back()>s[i] && lastSeen[ans.back()-'a']>i){
                taken[ans.back()-'a']=false;
                ans.pop_back();
            }

            ans+=s[i];
            taken[s[i]-'a']=true;

            
        }
        return ans;
    }
};