class Solution {
public:
    long long solve(vector<int>& nums1, vector<int>& nums2, long long canAns){
        long n1 = nums1.size();
        long n2 = nums2.size();
        long long prodCount = 0;
        for(int i=0;i<n1;i++){
            if(nums1[i]>=0){        //if nums[i] is positive
                //we got the num1[i] now we wil do bSearch on 2nd array;
                long long l = 0;
                long long r = n2-1;
                long long m =-1;
                while(l<=r){
                    long long mid = l+(r-l)/2;
                    long long curProd = 1LL*nums1[i]*nums2[mid];
                    if(curProd<=canAns){
                        m = mid;
                        l=mid+1;
                    }else{
                        r = mid-1;
                    }
                }
                prodCount+=(m+1);
            }else{                      //if nums[i] is negative 
                long long l = 0;
                long long r = n2-1;
                long long m =n2;
                while(l<=r){
                    long long mid = l+(r-l)/2;
                    long long curProd = 1LL*nums1[i]*nums2[mid];
                    if(curProd<=canAns){
                        m = mid;
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
                prodCount+=(n2-m);

            }
        }
        return prodCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long minVal = -1e10;
        long long maxVal = 1e10;
        long long ans =0;
        while(minVal<=maxVal){
            long long canAns = minVal+(maxVal-minVal)/2;

            long long smallCount = solve(nums1,nums2,canAns);
            if(smallCount>=k){
                ans = canAns;
                maxVal = canAns-1;
            }else{
                minVal = canAns+1;
            }
        }
        return ans;
        
    }
};