class Solution {
public:
    int t[201][201][2];
    int M = 1e9 +7;
    int count(int zero, int one, int limit,bool flag){
        if(zero == 0 && one == 0){
            return 1;
        }
        if(t[zero][one][flag] != -1){
            return t[zero][one][flag];
        }
        int sum = 0;
        if(flag){ //flag true , abb 1 use hoga
            for(int i=1;i<=min(one,limit);i++){
                sum  = (sum +count(zero,one-i,limit,false))%M;
            }
        }else{ //abb zero use hoga
             for(int i=1;i<=min(zero,limit);i++){
                sum = (sum+ count(zero-i,one,limit,true))%M;
            }
        }
        return t[zero][one][flag] = sum;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        

        return (count(zero,one,limit,false)%M + count(zero,one,limit,true)%M) % M;

    }
    //flag false, mtlb zero use nhi huwa, 
    //flag true mtlb, zero use huwa hai,abb 1 hoga
};