class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sum  = 0;
        int product = 1;
        for(char c:s){
            int temp = c-'0';
            sum+=temp;
            product*=temp;
        }
        if(n%(sum+product)==0) return true;
        return false;
    }
};