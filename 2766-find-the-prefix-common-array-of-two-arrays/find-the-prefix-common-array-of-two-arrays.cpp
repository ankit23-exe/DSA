class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> set;
        vector<int>c(n,0);
        for(int i=0;i<n;i++){
            set.insert(A[i]);
            int count =0;
            for(int j=0;j<=i;j++){
                if(set.count(B[j])){
                    count++;
                }
            }
            c[i]=count;

        }
        return c;
    }
};