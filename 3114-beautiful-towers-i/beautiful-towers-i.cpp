class Solution {
public:
    long long lsum(vector<int>& heights,int peak){
        long long maxheight=heights[peak];
        long long sum=0;
        for(int j=peak;j>0;j--){
            if(heights[j-1]<=maxheight){
                sum+=heights[j-1];
            }else{
                sum+=maxheight;
            }
            maxheight= min(maxheight,(long long)heights[j-1]);
        }
        return sum;

    }

     long long rsum(vector<int>& heights,int peak){
        long long maxheight=heights[peak];
        long long sum=0;
        for(int j=peak;j<heights.size()-1;j++){
            if(heights[j+1]<=maxheight){
                sum+=heights[j+1];
            }else{
                sum+=maxheight;
            }
            maxheight= min(maxheight,(long long)heights[j+1]);
        }
        return sum;

    }

    long long maximumSumOfHeights(vector<int>& heights) {
        long long ans=0;
        for(int i=0;i<heights.size();i++){
            long long csum=0;
            long long leftsum=lsum(heights,i);
            long long rightsum=rsum(heights,i);
            csum=leftsum+rightsum +heights[i];
            ans=max(csum,ans);
        }
        return ans;
        
    }
};