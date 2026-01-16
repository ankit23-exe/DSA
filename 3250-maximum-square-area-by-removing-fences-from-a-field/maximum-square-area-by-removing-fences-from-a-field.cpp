class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hF, vector<int>& vF) {
        int M = 1e9 + 7;
        hF.push_back(1);
        hF.push_back(m);
        sort(hF.begin(), hF.end());

        vF.push_back(1);
        vF.push_back(n);
        sort(vF.begin(), vF.end());

        
        unordered_set<int> hset;
        // maxmum possible area
        hset.insert(m - 1);
        

        // horizontal fence ka distance calculate unka bich ka
        for (int i = 0; i < hF.size(); i++) {
            for (int j = i + 1; j < hF.size(); j++) {
                hset.insert(hF[j] - hF[i]);
            }
        }

        int ans = -1;

        for (int i = 0; i < vF.size(); i++) {
            for (int j = i + 1; j < vF.size(); j++) {
                
                int width = vF[j] - vF[i];
                if(hset.find(width)!=hset.end()){ //we found it
                    ans=max(ans,width);
                }
            }
        }
        
        if (ans == -1) {
            return -1;
        } else {
            return (1LL * ans * ans) % M;
        }
    }
};