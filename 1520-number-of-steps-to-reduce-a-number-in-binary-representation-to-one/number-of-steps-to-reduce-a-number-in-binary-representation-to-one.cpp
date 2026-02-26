class Solution {
public:
    int numSteps(string s) {
        int count =0;
        while(s.size()!=1){
            if(s[s.size()-1]=='1'){ //odd
                count++;
                int flag =0;
                for(int i=s.size()-1;i>=0;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        flag =1;
                        break;
                    } 
                    else{
                        s[i]='0';
                        
                    }
                }
                if(flag == 0){
                    s = "1"+s;
                }

            }else{  //even
                count++;
                s.pop_back(); 

            }
        }
        return count;
    }
};