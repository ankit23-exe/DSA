class Solution {
public:
    int binaryGap(int n) {
        vector<int> vec;
        int i=0;
        while(n){
            if(n%2!=0){
               vec.push_back(i);
            }
            n/=2;
            i++;
        }
        int maxdif =0;
        for(int i=1;i<vec.size();i++){
            maxdif  = max(maxdif,vec[i]-vec[i-1]);
        }
        return maxdif;
    }
};