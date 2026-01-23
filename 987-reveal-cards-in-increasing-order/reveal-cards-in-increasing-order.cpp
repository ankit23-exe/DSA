class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        vector<int> ans(n,0);
        sort(deck.begin(),deck.end());
        int i =0; // sorted mai
        bool skip = false;
        int j = 0;  // ans mai 
        while(i<n){
            if(ans[j]!=0){
                j= (j+1)%n;
                continue;
            }else if(ans[j]==0 && skip == false){
                ans[j]=deck[i++];
                skip = true;
            }else if( skip == true){
                skip = false;
            }
            j = (j+1)%n;
        }
        return ans;
        
        
    }
};