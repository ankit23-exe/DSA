class Solution {
public:
    bool canPlaceFlowers(vector<int>& flw, int n) {
        int max=0;
        int fi =-1;
        int li=-1;
        for(int i = 0;i<flw.size();i++){
            if(flw[i]==0){
                continue;
            }
            else if(fi==-1){
                fi=i;
                li=i;
            }else{
                li=i;
            }
        }

        if(fi==-1){//all zero case
            max = (flw.size()+1) /2;
        }else{
            int left = fi/2;
            int right = (flw.size()-1-li)/2;
            max =left;
            max+=right;
            int count =0;
            for(int i = fi+1;i<=li-1;i++){
                if(flw[i]==0){
                    count++;
                }else{
                    max+=(count-1)/2;
                    count=0;
                }
            }
            max+=(count-1)/2;

        }
        return n<=max;

       
    }
};