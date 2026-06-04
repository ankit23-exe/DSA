class Solution {
public:
    int waviness(int num){
        int size = log10(num) + 1;
        string s = to_string(num);
        int i=1;
        int wavi = 0;
        for(;i<=size-2;i++){
            if(s[i]-'0'>s[i-1]-'0' && s[i]-'0'>s[i+1]-'0') wavi++;
            if(s[i]-'0'<s[i-1]-'0' && s[i]-'0'<s[i+1]-'0') wavi++;
        }

        return wavi;
        
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++){
            if(i<=100) continue;
            ans+=waviness(i);
        }
        return ans;
    }
};