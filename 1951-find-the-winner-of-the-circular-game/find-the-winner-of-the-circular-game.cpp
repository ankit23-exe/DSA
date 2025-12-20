class Solution {
public:
    int findTheWinner(int n, int k) {   //joseph recurrence
        int winner = 0; 

        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }

        return winner + 1; 
    }
};
