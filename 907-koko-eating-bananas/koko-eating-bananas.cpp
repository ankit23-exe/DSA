class Solution {
public:
    bool possible(int k ,vector<int>& piles, int h){
        int n = piles.size();
        long long currh = 0;
        for(int i=0;i<n;i++){
            currh+= (piles[i]+k -1)/k;
        }
        if(currh<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int r=0;
        int l=1;
        for(int i=0;i<n;i++){
            r = max(r,piles[i]);
        }
        if(n == h) return r;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(possible(mid,piles,h)){
                r =mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};