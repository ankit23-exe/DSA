class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp; // reminder:freq 
        int ans=0;
        int cumsum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            cumsum+=nums[i];
            int r=(cumsum%k)>=0?cumsum%k:(cumsum%k) +k; 
            if(mp.find(r)!=mp.end()){
                ans+=mp[r];
            } 
              mp[r]++;
            
            
        }
        return ans;

        
    }
};