class Solution {
public:
    int t[50001];
    int solve(int i,vector<int>& stoneValue){
        int n = stoneValue.size();
        if(i>=n) return 0;
        //alice take 1 

        if(t[i]!=-1) return t[i];
        
        int take1 = stoneValue[i]- solve(i+1,stoneValue);
        //alice take 2
        int take2= INT_MIN;
        if(i+1<n)
            take2 = stoneValue[i]+stoneValue[i+1]- solve(i+2,stoneValue);

        //alice take 3 
       int take3= INT_MIN;
        if(i+2<n)
            take3 = stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(i+3,stoneValue);
        

        return t[i] = max(max(take1,take2),take3);
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(t,-1,sizeof(t));
        int n = stoneValue.size();
        
        int Score = solve(0,stoneValue);
        
        if(Score>0) return "Alice";
        else if(Score==0) return "Tie";
        else return "Bob";
    }
};