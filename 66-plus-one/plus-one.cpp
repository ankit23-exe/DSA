class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        if(digits[n-1]!=9){
            digits[n-1]++;
            return digits;
        }else{
            int lidx=n-1;
            while(lidx>=0 && digits[lidx]==9){
                digits[lidx]=0;
                lidx--;
            }
            if(lidx!=-1){
                digits[lidx]++;
                return digits;
            }else{
                ans.resize(n+1,0);
                ans[0]=1;
                return ans;
            }
        }
        return ans; 
    
    }
        
};