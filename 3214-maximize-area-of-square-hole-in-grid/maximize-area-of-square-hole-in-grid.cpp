class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int x = 1;
        int c = 1;
        for (int i = 0; i < hBars.size()-1; i++) {
            if (hBars[i] +1 == hBars[i+1]) {
                c++;
            } else {
                x = max(x, c);
                c = 1;
            }
        }
        x = max(x, c);
        int y = 1;
        int d =1;
        for (int i = 0; i < vBars.size()-1; i++) {
            if(vBars[i] +1 ==vBars[i+1]){
                d++;
            }else{
                y=max(y,d);
                d=1;
            }
        }
        y = max(y, d);

        int ans = min(x+1,y+1);
        return ans*ans;
    }
};