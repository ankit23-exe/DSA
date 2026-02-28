class Solution {
public:
    string convertBinary(int n){
        string temp ="";
        while(n){
            int digi = n%2;
            temp.push_back(digi+'0');
            n/=2;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    

    }
    int concatenatedBinary(int n) {
        int ans =0;
        int M = 1000000007;
        for(int i=1;i<=n;i++){
            string binary = convertBinary(i);

            for(int j=0;j<binary.size();j++){
                ans = ans*2 + (binary[j]-'0');
                ans%=M;
            }

        }
        return ans;
    }
};