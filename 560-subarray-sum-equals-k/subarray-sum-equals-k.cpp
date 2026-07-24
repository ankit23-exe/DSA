class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = 0;
    
        unordered_map<int,int>mp; //sum,freq
        int temp =0;
        mp[0]=1;
        
        for(int i=0;i<n;i++){
            temp+=nums[i];
            if(mp.count(temp- k)){
                ans+=mp[temp-k];
                //mp[temp-k]++;
            }
            mp[temp]++;
            
        }
        return ans;

    }
};