class Solution {
public:
    vector<int> v;
    int f(int n){
         if(n==0) return 0;
        if(n==1) return 1;

        if(v[n]!=-1){
            return v[n];
        }
        return v[n] = fib(n-1)+fib(n-2);
         
    }
    

    int fib(int n) {
        v.resize(31,-1);
        return f(n);
    }
       
};