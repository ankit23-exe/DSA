class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = encodedText.size();
        if(rows ==1 || n==0 ) return encodedText;
        int col = n/rows;
        vector<vector<char>> grid(rows,vector<char>(col,' '));
        //making the grid
        int k =0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                grid[i][j] = encodedText[k++];
            }
        }
        // traversing and making string
        string ans ="";
        for(int i=0;i<col;i++){
            int c = i;
            int r= 0;
            while(c<col && r<rows){
                ans+=grid[r][c];
                c++;r++;
            }

        }
        // poping the trail spaces
        int i =ans.size()-1;
        while(ans[i]==' '){
            ans.pop_back();
            i--;
        }
        return ans;
    }
};