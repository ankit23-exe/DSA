class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0;
        int j=0;
        unordered_set<char>set;
        while(j<s.size()){
            if(!set.count(s[j])){
                set.insert(s[j]);
                j++;
                ans =max(ans,j-i); 
            }else{
                while(set.count(s[j])){
                    set.erase(s[i++]);
                }
                set.insert(s[j]);
                j++;
                ans =max(ans,j-i); 

            }
        }
        return ans;
    }
};