class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        for(int i=0;i<n1;i++){
           int s = i;int e=n2;
           while(s<e){
            int mid = (((e-s)/2) + s);
            if(nums2[mid]>=nums1[i]){
                s = mid+1;
                ans = max(ans,mid-i);
            }else{
                e = mid;
            }
           }
        }
        return ans;
    }
};