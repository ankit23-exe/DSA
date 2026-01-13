class Solution {
public:

    bool check(vector<vector<int>>& squares,double midy, double total){
        double b_area =0.00000;
        for(auto &sq :squares){
            double x = sq[0];
            double y= sq[1];
            double l = sq[2];

            if(midy >= y+l){
                b_area+=l*l;
            }else if(midy > y){
                b_area += l * (midy-y);
            }


        }

        return b_area >= total/2.0000;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.00000;
        double miny =INT_MAX;
        double maxy =INT_MIN;

        for(auto &sq :squares){
            double x = sq[0];
            double y= sq[1];
            double l = sq[2];
            total += l*l;

            miny=min(y,miny);
            maxy= max(y+l,maxy);
        }

        double resulty=0.0000;

        while(maxy-miny > 1e-5){

            double midy = miny + (maxy-miny)/2.00000;
            resulty =midy;

            if(check(squares,midy,total)==true){   //true mtlb bottom_area >= top_area
                maxy=midy;
            }else{
                miny =midy;
            }
        
        }
        return resulty;
    }
};