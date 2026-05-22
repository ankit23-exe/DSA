class Solution {
public:
    int m,n;
    vector<string> ans;

    vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};

    struct trieNode{
        string word;
        bool wordend;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->word="";
        newNode->wordend = false;

        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    void insert(trieNode* root,string &word){
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(root->children[ch-'a']==NULL){
                trieNode* newNode = getNode();
                root->children[ch-'a']=newNode;
            }
            root=root->children[ch-'a'];
        }
        root->wordend = true;
        root->word = word;
    }


    void dfs(trieNode* root,int i,int j,vector<vector<char>>& board){
        if(i>=m || j>=n || i<0 || j<0){
            return;
        }
        if(board[i][j]=='$') return;

        
        if(root->wordend == true){
            ans.push_back(root->word);
            root->wordend = false;

        }
        char temp  = board[i][j];
        board[i][j]='$';
        //all 4 ways, but we need to make sure waha na jaya jaha sa aya hai
        
        for(int d=0;d<4;d++){
            int newi = i + direction[d][0];
            int newj = j + direction[d][1];

            if(newi>=m || newj>=n || newi<0 || newj<0) continue;

            char newch = board[newi][newj];
            if(newch == '$') continue;
           
            if(root->children[newch-'a']!=NULL){
                dfs(root->children[newch-'a'],newi,newj,board);
            }

        }
        board[i][j]=temp;
        
    }


    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        //root create 
        trieNode* root = getNode();
        //creating the trie tree of words
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }

        //traverse all matrix element and check if its present in it or not 
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                char ch = board[i][j];
                
                if(root->children[ch-'a']!=NULL){
                    dfs(root->children[ch-'a'],i,j,board);
                }
            }
        }
        return ans;
    }
};