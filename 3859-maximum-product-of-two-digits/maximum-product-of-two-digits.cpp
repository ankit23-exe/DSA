class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        vector<int>num;
        for(auto c:s){
            num.push_back(int(c-'0'));
        }
        sort(num.begin(), num.end(), greater<int>());

        return num[0]*num[1];
    }
};