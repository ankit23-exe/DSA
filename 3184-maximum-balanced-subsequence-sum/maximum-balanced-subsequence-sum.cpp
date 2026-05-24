class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        long long maxEl = *max_element(nums.begin(),nums.end());
        if(maxEl<=0) return maxEl;
        map<int ,long long> mp; //nums[i]-i , sum

        long long result = INT_MIN;

        for(int i=0;i<n;i++){
            auto it = mp.upper_bound(nums[i]-i);
            long long sum = nums[i];
            if(it!=mp.begin()){
                it--;
                sum+=it->second;

            }
            mp[nums[i]-i]=max(sum,mp[nums[i]-i]);
            it = mp.upper_bound(nums[i]-i);
            while(it != mp.end() && it->first > nums[i]-i && it->second<=  mp[nums[i]-i]){
                mp.erase(it++);
            }

            result = max(mp[nums[i]-i],result);
        }
        return result;
    }
};