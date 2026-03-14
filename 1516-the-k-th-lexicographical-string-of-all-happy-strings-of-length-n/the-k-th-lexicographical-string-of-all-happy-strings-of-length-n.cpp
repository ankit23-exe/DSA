class Solution {
public:
    void make(int n,int k, char prev,string &temp,vector<string> &all_strings){
        if(temp.size()==n){
            all_strings.push_back(temp);
            return;
        }
        for(int i=0;i<=2;i++){
            if(prev != 'a'+i){
                temp.push_back('a'+i);
                make(n,k,'a'+i,temp,all_strings);
                temp.pop_back();
            }
           
        }
    }
    string getHappyString(int n, int k) {
        vector<string> all_strings;
        string temp = "";
        make(n,k,'x',temp,all_strings);

        //sort(all_strings.begin(),all_strings.end());
        if(k>all_strings.size()){
            return "";
        }
        return all_strings[k-1];
    }
};