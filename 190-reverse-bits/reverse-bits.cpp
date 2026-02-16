class Solution {
public:
    int reverseBits(int n) {
        string ans ="";
        for(int i=1;i<=32;i++){
            if(n){
                ans.push_back(n%2);
                n/=2;
            }else{
                ans.push_back(0);
            }
        }
        int j = 31;
        long long k = 1;
        long long number = 0;
        while(j>=0){
            if(ans[j]==1){
                number+=k;
            }
            k*=2;
            j--;
        }
        return number;

    }
};