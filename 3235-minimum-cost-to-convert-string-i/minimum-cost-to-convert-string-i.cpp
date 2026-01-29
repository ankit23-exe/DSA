class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n =original.size();


        vector<vector<long long>> grid(26,vector<long long> (26,INT_MAX));

        for (int i = 0; i < 26; i++) {
            grid[i][i] = 0;
        }

        for(int i =0;i<n;i++){
            int s =original[i] - 'a';
            int e =changed[i] - 'a';
        
            grid[s][e]=min((long long)cost[i],grid[s][e]);
        }

        //warshall algo 
        for(int via =0;via<26;via++){
            for(int i = 0 ; i<26;i++){
                for(int j = 0;j<26;j++){
                    grid[i][j]=min(grid[i][j] , grid[i][via]+grid[via][j]);
                }
            }
        }
        long long ans =0;
        for(int i =0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            if(grid[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }else{
                ans +=grid[source[i]-'a'][target[i]-'a'];
            }
            
        }
        return ans;
        

    }
};