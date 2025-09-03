class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string ans ="";
        int max,min;
        int len1 =word1.length() ;
        int len2 =word2.length() ;
        max = (len1 > len2) ? len1 : len2;
        min = (len1 > len2) ? len2 : len1;

        for(int i =0 ;i<min;i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        for(int i =min;i<max;i++){
            if(len1>len2){
                ans+=word1[i];
            }else{
                ans+=word2[i];
            }
        }

        return ans;


       

       


            
        
        
    }
};