class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp; //reminder, first seen index
        long long cumsum =0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            cumsum+=nums[i];
            int reminder = cumsum%k;
            if(!mp.count(reminder)){
                mp[reminder]=i;
            }else{
                
                if(i-mp[reminder]>=2) return true;
            }
        }
        
        return false;
    }
};