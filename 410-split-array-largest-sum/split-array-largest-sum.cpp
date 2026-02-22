class Solution {
public:
    int calculate(int m,vector<int>& nums){
        int req=1;
        int currsum =0;
        for(int i=0;i<nums.size();i++){
            if(currsum +nums[i]<=m){
                currsum += nums[i];
            }else{
                req++;
                currsum = nums[i];
            }
        }
        
        return req;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0 ;
        int r=0 ;
        for(int i =0;i<nums.size();i++){
            l = max(l,nums[i]);
            r+=nums[i];
        }
       
        int mid=0;
        while(l<=r){
            mid = l + (r-l)/2;
            int currreq = calculate(mid,nums);

            if(currreq<=k){
                 r = mid-1;
            }else{
               
                 l=mid+1;
            }
        }
        return l;
    }
};