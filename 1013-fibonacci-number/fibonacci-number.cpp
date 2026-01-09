class Solution {
public:
    vector<int> v;
    int fib(int n) {
        if(n<=1) return n;
        v.resize(n+1,-1);
        v[0]=0;
        v[1]=1;
        for(int i=2;i<=n;i++){
            v[i]=v[i-1]+v[i-2];
        }
        return v[n];
    }
       
};