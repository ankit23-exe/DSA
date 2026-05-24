class Solution {
public:
   
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> t(n, 1); //vec[i] store max indx cover from i 
        int fans = 0;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({arr[i],i});
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>&p1,pair<int,int>&p2){
            return p1.first<p2.first;
        });

        for (int i = 0; i < n; i++) {
            int idx = vec[i].second;

            
            for (int j = idx - 1; j >= max(0, idx - d); j--) {
                if (arr[j] >= arr[idx])
                    break;
                t[idx] = max(t[idx], 1 + t[j]);
            }
            for (int j = idx + 1; j <= min(n-1, idx + d); j++) {
                if (arr[j] >= arr[idx])
                    break;
                t[idx] = max(t[idx], 1 + t[j]);
            }
            
            fans = max(fans, t[idx]);
        }

        return fans;
    }
};