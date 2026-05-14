class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>diff(2*limit+2);
        int n = nums.size();


        for(int i=0;i<n/2;i++){
            int a = nums[i];
            int b = nums[n-1-i];

            int minl = min(a,b)+1;
            int maxl = max(a,b)+limit;

            diff[2]+=2;
            diff[2*limit+1]-=2;

            diff[minl]+=(-1);
            diff[maxl+1]-=(-1);

            //making that zero
            diff[a+b]+=(-1);
            diff[a+b+1]-=(-1);
        }
        //doing the cumilative sum

        int ans = INT_MAX;
        for(int i=2;i<=2*limit;i++){
            diff[i]+=diff[i-1];
            ans = min(ans,diff[i]);
        }
        
        
        return ans;
    }
};