class Solution {
public:
    string addBinary(string a, string b) {
        int as = a.size();
        int bs = b.size();
        int i =as-1;
        int j = bs-1;
        bool carry = false;
        string ans = "";
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry==true){
                    ans.push_back('1');
                    carry=true;
                }else{
                    ans.push_back('0');
                    carry=true;

                }
            }else if(a[i]=='0' && b[j]=='0'){
                 if(carry==true){
                    ans.push_back('1');
                    carry=false;
                }else{
                    ans.push_back('0');
                    
                }
            }else{
                 if(carry==true){
                    ans.push_back('0');
                    carry=true;
                }else{
                    ans.push_back('1');
                    carry=false;
                }
            }
            i--;j--;
        }
        while(i>=0){
            if(a[i]=='1'){
                if(carry==true){
                    ans.push_back('0');
                    carry = true;
                }else{
                    ans.push_back('1');
                }
            }else{
                if(carry==true){
                    ans.push_back('1');
                    carry = false;
                }else{
                    ans.push_back('0');
                }
            }
            
            i--;

        }
        while(j>=0){
           if(b[j]=='1'){
                if(carry==true){
                    ans.push_back('0');
                    carry = true;
                }else{
                    ans.push_back('1');
                }
            }else{
                if(carry==true){
                    ans.push_back('1');
                    carry = false;
                }else{
                    ans.push_back('0');
                }
            }
            
            j--;

        }

        if(carry==true){
            ans.push_back('1');
        }

         i =0;
         j= ans.size()-1;
        while(i<j){
            swap(ans[i],ans[j]);
            i++;j--;
        }
        return ans;
    }
};