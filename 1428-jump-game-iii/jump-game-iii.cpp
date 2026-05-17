class Solution {
public:
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>que;
        vector<bool>vis(n,false);
        vis[start]=true;
        que.push(start);
        while(!que.empty()){
            int f = que.front();
            que.pop();
            vis[f]=true;
            if(arr[f]==0) return true;
            if(f+arr[f]<n && !vis[f+arr[f]]){
                que.push(f+arr[f]);
            }
             if(f-arr[f]>=0  && !vis[f-arr[f]]){
                que.push(f-arr[f]);
            }

        }
        return false;
    }
};