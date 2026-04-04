class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.size();
        if(rows == 1 || n==0 ) return encodedText;
        int col = n/rows;
        string ans ="";
        for(int c=0;c<col;c++){
            for(int j=c;j<n;j+=col+1){
                ans+=encodedText[j];
            }
            
        }
        int i=ans.size()-1;
        while(ans[i]==' '){
            ans.pop_back();
            i--;
        }
        return ans;
    }
};