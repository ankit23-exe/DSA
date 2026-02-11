class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       long long ans = 0;
       int l =0;
       int n= nums.size();
       deque<int> maxdq,mindq;
       for(int r=0;r<n;r++){
        //maintaing the mxdq
        while(!maxdq.empty() && nums[maxdq.back()]<nums[r]){
           maxdq.pop_back();
        }
         maxdq.push_back(r);


        //maintaining the mindq
         while(!mindq.empty() && nums[mindq.back()]>nums[r]){
           mindq.pop_back();
        }
         mindq.push_back(r);


         //shrinking if the window is not valid

        while(!mindq.empty() && !maxdq.empty() && 1LL * (nums[maxdq.front()] - nums[mindq.front()]) * (r - l + 1) > k
){
            if(maxdq.front()==l) maxdq.pop_front();
            if(mindq.front()==l) mindq.pop_front();
            l++;
        } 

        ans += r-l+1;


       } 
       return ans;
    }
};