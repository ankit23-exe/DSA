class Solution {
public:
    bool balanced(vector<int> &freq){
        int c = 0;
        for(auto &n:freq){
            if(n==0) continue;
            else{
                c = n;
                break;
            }

        }

        for(auto &n:freq){
            if(n==0) continue;
            else if(n==c) continue;
            else{
                return false;
            }
        }

        return true;
            
    }
    int longestBalanced(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j =i;j<n;j++){
                freq[s[j]-'a']++;
                
                if(balanced(freq)){
                    count = max(count,j-i+1);
                }
                
            }
        }
        return count;
    }
};