class Solution {
public:
    //function to check, if its satisfy or not 
    bool check(long long target,vector<int>& stations, int r, int k){
        int n = stations.size();
        vector<long long>diff(n,0);

        for(int i=0;i<n;i++){ //making the diff array
            diff[max(0,i-r)]+=stations[i]; //adding at left side of diff array
            if(i+r+1<n) diff[i+r+1]-=stations[i];  //if r indx valid then subing it 
        }

        long long cumsum = 0;
        for(int i=0;i<n;i++){ //main check loop , if we need to use k house we can 
            cumsum+=diff[i];
            long long need = target-cumsum;
            if(need>k) return false;
            else{
                if(need<=0) continue;
                 if(i+2*r+1<n) diff[i+2*r+1]-=need;
                cumsum+=need;
                k-=need;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        long long s = *min_element(stations.begin(),stations.end());
        long long e = accumulate(stations.begin(),stations.end(),0*1LL)+k;
        long long ans=0 ;
        
        //binary search wala thing 
        while(s<=e){
            long long mid = s +(e-s)/2;
            if(check(mid,stations,r,k)){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
};