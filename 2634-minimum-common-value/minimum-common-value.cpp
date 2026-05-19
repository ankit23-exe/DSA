class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        //int s1 = nums1.size();
        unordered_set<int>set;
        for(auto &x:nums1){
            set.insert(x);
        }
        for(auto x:nums2){
            if(set.count(x)){
                return x;
            }
        }
        return -1;
    }
};