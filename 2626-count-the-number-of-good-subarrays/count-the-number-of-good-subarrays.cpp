class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0,j=0;
        long long pair=0;
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int> map;
        while(j<n){
            pair+=map[nums[j]];
            map[nums[j]]++;
            while(pair>=k){
                ans+=(n-j);
                map[nums[i]]--;
                pair-=map[nums[i]];
                i++;

            }
            j++;
        }
        return ans;
        
    }
};