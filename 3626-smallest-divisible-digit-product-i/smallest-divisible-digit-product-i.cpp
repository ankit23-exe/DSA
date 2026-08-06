class Solution {
public:
    bool divisible(int n,int t){
        string s = to_string(n);
        int prod = 1;
        for(char &c:s){
            prod*=(c-'0');
        }
        return (prod%t==0);
    }
    int smallestNumber(int n, int t) {
        int canBeAns = n;
        while(1){
            if(divisible(canBeAns,t)) return canBeAns;
            canBeAns++;
        }
        return 0;
    }
};