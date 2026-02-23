class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.length()) return false;
        unordered_set<string> set;
        string temp="";
        for(int i=0;i<k;i++){
            temp.push_back(s[i]);
        }
        set.insert(temp);

        for(int i=k;i<s.size();i++){
            temp.push_back(s[i]);
            temp.erase(0, 1);
            set.insert(temp);
        }

        if(set.size()==pow(2,k)) return true;
        return false;
    }
};