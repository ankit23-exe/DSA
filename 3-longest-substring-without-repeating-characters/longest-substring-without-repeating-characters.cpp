class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int i=0,j=0;
        int ans = 0;
        while(j<n){
            while(set.count(s[j])){
                set.erase(s[i++]);
            }
            set.insert(s[j]);
            ans = max(ans,j-i+1);


            j++;
        }
        return ans;
    }
};