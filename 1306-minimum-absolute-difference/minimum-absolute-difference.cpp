class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mindiff =INT_MAX;
        for(int i=1;i<=n-1;i++){
            mindiff = min(mindiff, abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>> ans;

        for(int i = 1 ; i<=n-1;i++){
            if(abs(arr[i]-arr[i-1])==mindiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};