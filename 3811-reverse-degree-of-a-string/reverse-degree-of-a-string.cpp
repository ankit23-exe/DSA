class Solution {
public:
    int reverseDegree(string s) {
        int ans = 1;
        int mul =1;
        for(char &c:s){
            int val = c-'a';
            val = 26 - val;
            ans+=(val*mul);
            mul++;
        }
        return ans-1;
    }
};