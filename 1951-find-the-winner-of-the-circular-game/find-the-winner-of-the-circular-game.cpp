class Solution {
public:
    int winner(int n, int k){
        if(n==1){
            return 0;
        }

        int idx=winner(n-1,k);
        idx=(idx+k)%n;
        return idx;
        
        }

    int findTheWinner(int n, int k) {   //joseph recurrence
        
        return winner(n,k)+ 1; 
    }
};
