class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,0);

        deque<int> d;
        d.push_back(0);
        
        for(int i = 1;i<k;i++){
            while(!d.empty() && nums[d.back()]<= nums[i] ){
                d.pop_back();
            }
            d.push_back(i);
            
        }

        
        ans[0]=nums[d.front()];

        int ansidx = 1;
        
        for(int j = k ; j<n;j++){

            if(!d.empty() && d.front()<=j-k){
                d.pop_front();
            }
            while(!d.empty() && nums[d.back()]<=nums[j]){
                d.pop_back();
            }
            d.push_back(j);
            
            ans[ansidx++]=nums[d.front()];
        }
        return ans;

    }
};