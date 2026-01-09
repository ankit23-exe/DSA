class Solution {
public:
    vector<int> v;
    int fib(int n) {
        if(n<=1) return n;
        v.resize(n+1,-1);
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
       
};