class Solution {
public:
    bool possible(int wt,vector<int>& weights,int days){
        int n = weights.size();
        int cursize =0;
        int needday=0;
        for(int i=0;i<n;i++){
            if(cursize + weights[i]<= wt){
                cursize+=weights[i];
            }else{
                cursize=weights[i];
                needday++;
            }
        }
        if(cursize!=0) needday+=1;

        if (needday <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while(l<=r){
            int mid = l + (r-l)/2;
            if(possible(mid,weights,days)){
                r=mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};