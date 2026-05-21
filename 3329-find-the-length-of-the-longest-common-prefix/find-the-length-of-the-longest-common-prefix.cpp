class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int ans = 0;
        unordered_set<string> set;
        for(int i=0;i<n1;i++){
            string s1 = to_string(arr1[i]);
            while(s1.size()){
                set.insert(s1);
                s1.pop_back();
            }
        }

        for(int i=0;i<n2;i++){
             string s2 = to_string(arr2[i]);
             while(s2.size()){
                if(set.count(s2)){
                    int size = s2.size();
                    ans = max(ans,size);
                    break;
                }
                s2.pop_back();
                
             }
        }

        return ans;
    }
};