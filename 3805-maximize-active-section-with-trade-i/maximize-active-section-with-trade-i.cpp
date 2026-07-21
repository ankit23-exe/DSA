class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>zeroBlock;
        int zcount =0;
        int onecount =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zcount++;
            }else{
                if(zcount>0)
                    zeroBlock.push_back(zcount);
                zcount =0;
                onecount++;
            }

            
            
        }
        if(zcount>0)
            zeroBlock.push_back(zcount);

        if(onecount == s.size()) return onecount;
        int ans = 0;
        for(int i=0;i<zeroBlock.size()-1;i++){
            int cur = zeroBlock[i]+zeroBlock[i+1];
            ans = max(ans,cur);

        }
        return ans+onecount;
    }
};