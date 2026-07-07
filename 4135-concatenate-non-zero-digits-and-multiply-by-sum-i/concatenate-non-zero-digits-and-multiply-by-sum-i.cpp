class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x = "";
        long long sum =0;
        for(auto c:s){
            if(c-'0'!=0){
                x+=c;
                sum+=(c-'0');
            }
        }
        if(x=="") return 0;
        return 1LL*stoi(x)*sum;
    }
};