class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int l =0;
        int r =1e9;
        int ans =0;
        sort(price.begin(),price.end());
        while(l<=r){
            int mid = l + (r-l)/2;
            int c =1;
            int last =0;

            for(int i=0;i<price.size();i++){
                if(price[i]-price[last]>=mid){
                    last = i;
                    c++;
                }
            }
            if(c>=k){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans ;
    }
};