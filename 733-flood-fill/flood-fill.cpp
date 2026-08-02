class Solution {
public:
    vector<vector<int>> direction={{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m = image.size();
        int n = image[0].size();

        
        int originalColor = image[sr][sc]; // original color which need to change

        queue<pair<int,int>> que;
        que.push({sr,sc});
        while(!que.empty()){
            auto [r,c]=que.front();
            que.pop();
    
            image[r][c]=color;
            //generating neigh
            for(auto d:direction){
                int newr = r+d[0];
                int newc = c+d[1];

                if(newr<0 || newc <0||newr>=m || newc>=n) continue;

                if(image[newr][newc]==originalColor){
                     image[newr][newc]=color; 
                    que.push({newr,newc});
                }
            }


        }
        return image;
    }
};