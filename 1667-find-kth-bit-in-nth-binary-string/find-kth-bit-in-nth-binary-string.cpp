class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s[i]='1';
            }else{
                s[i]='0';
            }
        }
        return s;
    }
    string make(int n){
        if(n == 1){
           
            return "0";
        }
        string t1 = make(n-1);
        //t1 = t1 + "1";
        string t2 = invert(t1);
        reverse(t2.begin(),t2.end());
        t1 = t1 + "1" + t2;
        return t1;
    }
    char findKthBit(int n, int k) {

       //forming the string 
       
        string temp = make(n); 
        return temp[k-1];
    }
};