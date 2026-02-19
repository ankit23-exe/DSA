class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> vec;
        int curr = s[0];
        int count =1;
        for(int i=1;i<s.size();i++){
            if(curr == s[i]){
                count++;
            }else{
                vec.push_back(count);
                count =1;
                curr = s[i];
            }
        }
        vec.push_back(count);

        int ans = 0;
        for(int i=1;i<vec.size();i++){
            ans += min(vec[i],vec[i-1]);
        }

        return ans;
    }
};