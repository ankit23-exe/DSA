class Solution {
public:
    vector<vector<double>> t{101, vector<double>(101, -1.0)};
    double solve(int poured,int i,int j){
        if(i==0 && j ==0){
            return poured;
        }
        if(j<0 || i<0 || i<j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        double lefttop = ((solve(poured,i-1,j-1)-1)/2.0);
        double righttop = ((solve(poured,i-1,j)-1)/2.0);
        if(lefttop<0){
            lefttop=0;
        }
        if(righttop<0){
            righttop=0;
        }

        return  t[i][j]= lefttop+righttop;

    }
    double champagneTower(int poured, int query_row, int query_glass) {
        return min(1.0 , solve(poured,query_row,query_glass));
    }
};