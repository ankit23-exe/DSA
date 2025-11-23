class Solution {
public:
    int maxScore(vector<int>& cp, int k) {

        int sum=0;
        int maxx=0;
        int n=cp.size();
        for(int i=0;i<k;i++){
            sum+=cp[i];
        }
        maxx=max(maxx,sum);

        int end=k-1;

        for(int i=n-1;i>=n-k;i--){
            sum-=cp[end--];
            sum+=cp[i];
            maxx=max(maxx,sum);
        }

        return maxx;
            
       

        
    }
};