class Solution {
public:
    bool isprimary(int n){
        bool prime =true;
        for(int i=2;i<n;i++){
            if(n%i==0){
                prime = false;
                break;
            }
        }
        return prime;
    }
    int countPrimeSetBits(int left, int right) {
        int ans =0;
        for(int i=left;i<=right;i++){
            int bitcount = __builtin_popcount(i);
            if(bitcount==1) continue;
            if(isprimary(bitcount)) ans++;
        }
        return ans;
    }
};