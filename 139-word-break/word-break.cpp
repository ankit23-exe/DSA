class Solution {
public:
    unordered_set<string> st;
    int t[301];
    bool solve(int idx,string s){
        if(idx == s.size()){
            return true;
        }
        if(st.find(s)!=st.end()) return true;

        if(t[idx]!=-1) return t[idx];

        for(int i=0;i<=s.size();i++){
            string temp = s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(idx+i,s)) return true;
        }

        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &w:wordDict){
            st.insert(w);
        }
        memset(t,-1,sizeof(t));
        return solve(0,s);
    }
};