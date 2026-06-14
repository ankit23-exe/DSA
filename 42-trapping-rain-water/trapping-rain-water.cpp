class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        int lmax = height[0];
        for(int i=1;i<n;i++){
            left[i]=lmax;
            lmax=max(lmax,height[i]);
        }
        int rmax = height[n-1];
        for(int i=n-1;i>=0;i--){
            right[i]=rmax;
            rmax=max(rmax,height[i]);
        }

        int ans = 0;
        for(int i=1;i<n-1;i++){
            int water = (min(left[i],right[i])-height[i]);
            if(water>0) ans+=water;
        }

        return ans;

    }
};