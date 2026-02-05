class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        vis[0] = true;
        queue<int> q;
        for (auto& key : rooms[0]) {
            q.push(key);
        }

        while (!q.empty()) {
            int fkey = q.front();
            vis[fkey]=true;
            q.pop();
            for (auto& present_key : rooms[fkey]) {
                if(vis[present_key]==true) continue;
                vis[present_key] = true;
                q.push(present_key);
            }
        }

        for(int i =0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};