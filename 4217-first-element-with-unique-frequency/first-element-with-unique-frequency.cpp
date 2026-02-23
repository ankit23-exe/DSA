class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> a,b;

        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        for(auto &p:a){
            b[p.second]++;
        }

        for(auto x:nums){
            if(b[a[x]]==1) return x;
        }
        return -1;
    }
};