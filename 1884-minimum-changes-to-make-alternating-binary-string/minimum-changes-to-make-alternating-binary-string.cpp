class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        //posibility 1
        //making even idx element = 0
        int count1=0;
        for(int i=0;i<n;i++){
            if(i%2==0){ //even idx
                if(s[i]=='1') count1++;
            }else{   //odd idx
                if(s[i]=='0') count1++;
            }
        }

        //making even idx element= 1
        int count2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){ //even idx
                if(s[i]=='0') count2++;
            }else{   //odd idx
                if(s[i]=='1') count2++;
            }
        }

        return min(count1,count2);
    }
};