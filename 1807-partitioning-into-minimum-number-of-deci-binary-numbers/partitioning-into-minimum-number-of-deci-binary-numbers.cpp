class Solution {
public:
    int minPartitions(string n) {
        int s = n.size();
        int ans =INT_MIN;
        for(int i=0;i<s;i++){
            if(ans<n[i]-'0'){
                ans = n[i]-'0';
            }
        }
        return ans;
    }
};