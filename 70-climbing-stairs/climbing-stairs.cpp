class Solution {
public:
    int climbStairs(int n) {
        int arr[n+1];
        if(n<3){
            return n;
        }
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;

        for(int i =3;i<=n;i++){   //bottom up approach hai ya
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};