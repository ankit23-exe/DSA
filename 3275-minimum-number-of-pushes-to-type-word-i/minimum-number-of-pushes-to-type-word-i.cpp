class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int mul = 1;
        while(n>0){
            if(n<=8){
                ans+=n*mul;
                n=0;
            }else{
                ans+=8*mul;
                n-=8;
            }
            mul++;
        }
        return ans;

    }
};