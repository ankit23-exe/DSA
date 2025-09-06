class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.length();
        string word ="";
        
        for(int i =0 ;i<n;i++){
            if(s[i]!=' '){
                word+=s[i];
            }else{
                if(word!=""){
                    v.push_back(word);
                }
                
                word="";
            }
        }
        if(word!=""){
            v.push_back(word);
        }
        s="";
        while(!v.empty()){
            s+=v[v.size()-1]+' ';
            v.pop_back();
        }
        s.pop_back();

        return s;
        
        
    }
};