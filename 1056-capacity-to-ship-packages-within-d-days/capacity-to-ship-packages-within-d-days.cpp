class Solution {
public:
    bool possible(int wt,vector<int>& weights, int days){
        int day=0;
        int cursize=0;
        for(int i=0;i<weights.size();i++){
            if(cursize+weights[i] >wt){
                    day++;
                    cursize=weights[i];
            }else{
                cursize+=weights[i];
            }
        }
        if(cursize != 0) day+=1;
        if(day<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l =0;
        int r = 0;
        for(int i=0;i<n;i++){
            l = max(weights[i],l);
            r+=weights[i];
        }  

        while(l<=r){
            int mid = l +(r-l)/2;
            if(possible(mid,weights,days)){
                r= mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};