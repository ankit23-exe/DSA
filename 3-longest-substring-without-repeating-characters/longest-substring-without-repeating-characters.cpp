class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int i=0;
        int j=0;
        int n = s.size();
        int ans=0;
        while(j<n){
            while(set.count(s[j])){
                set.erase(s[i++]);
            }
            ans = max(ans,j-i+1);
            set.insert(s[j++]);
        }
        return ans;
    }
};