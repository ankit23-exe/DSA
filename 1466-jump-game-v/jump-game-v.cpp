class Solution {
public:
    int t[1001];
    
    int solve(int i,vector<int>& arr, int d,int n){
        if(i>=n || i<0) return 0;
        if(t[i]!=-1){
            return t[i];
        }
        int left = 0;
        for(int id=1;id<=d;id++){
            int next_i = i-id;
            if(next_i<0 ||  arr[next_i]>=arr[i]) break;
                left = max(left,solve(i-id,arr,d,n));
            
            
        }
        
        int right = 0;
        for(int id=1;id<=d;id++){
            int next_i = i+id;
            if(next_i>=n || arr[next_i]>=arr[i]) break;
                right = max(right,solve(i+id,arr,d,n));
            
        }

        return t[i] = 1+ max(left,right);
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