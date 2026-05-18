class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> que;
        vector<int> vis(n,false);
        
        int ans = 0;
        que.push(0);
        vis[0]=true;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int i = que.front();
                
                if(i==n-1) return ans;
                que.pop();
                
                if(i-1>=0 && !vis[i-1]){
                    vis[i-1]=true;
                    que.push(i-1);
                }
                if(i+1<n && !vis[i+1]){
                    vis[i+1]=true;
                    que.push(i+1);
                }
                for(auto &idx:mp[arr[i]]){
                    if(idx !=i && idx!=i-1 && idx!=i+1){
                            if(!vis[idx]){
                                vis[idx]=true;
                                que.push(idx);
                            }
                    }
                        
                }
                mp[arr[i]].clear();
            }
            ans++;

        }
        return -1;
    }
};