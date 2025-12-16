class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);

        //calculating left largest
        int lar=height[0];
        for(int i=1;i<n;i++){
            left[i]=lar;
            lar=max(lar,height[i]);
        }

        lar=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=lar;
            lar=max(lar,height[i]);
        }

        int ans=0;
        for(int i=1;i<n-1;i++){
            if(height[i]<left[i] && height[i]<right[i]){
                ans+=min(left[i],right[i]) - height[i];
            }
        }

        return ans;
        
    }
};