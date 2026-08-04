class Solution {
public:
    vector<vector<string>> answer;
    bool valid(string &s){
        int n = s.size();
        if(n==0) return false;
        if(n==1) return true;
        int i=0;
        int j = n-1;

        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;

    }
    void solve(int idx,string &s,vector<string>&temp){
        
        if(idx==s.size()){
            answer.push_back(temp);
            return;
        }
        for(int i=1;i+idx<=s.size();i++){//i is length from idx 
            string substring = s.substr(idx,i);
            if(valid(substring)){
                temp.push_back(substring);
                solve(idx+i,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       
        vector<string>temp;
        solve(0,s,temp);
        
        return answer;
    }
};