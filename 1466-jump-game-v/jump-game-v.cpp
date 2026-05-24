class Solution {
public:
    int t[1001][1001];
    bool check(int i,vector<int>& arr,int s,int e){
        //if(s<0 || e>=n) return 
        for(int j=s;j<=e;j++){
            if(arr[j]>=arr[i]) return false;
        }
        return true;
    }
    int solve(int i,vector<int>& arr, int d,int n){
        if(i>=n || i<0) return 0;
        if(t[i][d]!=-1){
            return t[i][d];
        }
        int left = 0;
        for(int id=1;id<=d;id++){
            if(i-id>=0 && arr[i-id]<arr[i] && check(i,arr,i-id+1,i-1) ){
                left = max(left,solve(i-id,arr,d,n));
            }
            
        }
        
        int right = 0;
        for(int id=1;id<=d;id++){
            if(i+id<n && arr[i+id]<arr[i] && check(i,arr,i+1,i+id-1)){
                right = max(right,solve(i+id,arr,d,n));
            }
            
        }

        return t[i][d] = 1+ max(left,right);
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(t, -1, sizeof(t));
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;i++){
            result = max(result,solve(i,arr,d,n));
        }
        return result;
    }
};