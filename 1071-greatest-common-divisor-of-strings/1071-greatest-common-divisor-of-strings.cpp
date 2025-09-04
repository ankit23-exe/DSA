class Solution {
public:
    int gcd(int n ,int m){
        int min = n>m?m:n;
        int i = min;
        for( i = min;i>0;i--){
            if(m%i==0 && n%i ==0){
                break;
            }
        }
        return i;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 == str2+str1){
            int n = str1.length();
            int m = str2.length();
            int hcf = gcd(n,m);
            return str1.substr(0,hcf);

        }else{
            return "";
        }
        
    }
};