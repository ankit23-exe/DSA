class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        
        int j=0;
        //int cur=0;
        int maxx=0;

        for(int i=0;i<s.size();i++){
            if(set.count(s[i])){
                while(set.count(s[i])){
                    set.erase(s[j++]);
                }
                set.insert(s[i]);
                maxx= max((int)set.size(),maxx);



            }else{
                //not present
                set.insert(s[i]);
                maxx=max((int)set.size(),maxx);

            }
        }
        return maxx;

        
    }
};