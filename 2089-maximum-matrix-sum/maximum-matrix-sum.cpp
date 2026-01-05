class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int neg_count =0;
        long long abs_sum =0;
        int min_num=INT_MAX;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(matrix[i][j]<=-1){
                    neg_count++;
                }
                if(abs(matrix[i][j])<min_num){
                    min_num=abs(matrix[i][j]);
                }
                abs_sum+=abs((matrix[i][j]));
            }
        }
        if(neg_count%2==0){
            return abs_sum;
        }else{
            return abs_sum - 2*min_num;
        }

    }
};