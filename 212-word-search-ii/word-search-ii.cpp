class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> ans;
    struct trieNode {
        bool endOfWord;
        string word;
        trieNode* children[26];
    };
    trieNode* getNode() {
        trieNode* node = new trieNode();
        node->endOfWord = false;
        node->word = "";
        for (int i = 0; i < 26; i++) {
            node->children[i] = nullptr;
        }

        return node;
    }

    void insertWord(trieNode* root, string word) {
        trieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'] == nullptr) {
                temp->children[word[i] - 'a'] = getNode();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->endOfWord = true;
        temp->word = word;
    }

    void findTrieNode(trieNode* root, int i, int j,
                      vector<vector<char>>& board) {
        if (board[i][j] == '$' || root->children[board[i][j] - 'a'] == nullptr)
            return;

        root = root->children[board[i][j] - 'a'];

        if (root->endOfWord) {
            ans.push_back(root->word);
            root->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        // now move forward and do dfs
        for (auto& d : direction) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (newi < 0 || newj < 0 || newi >= m || newj >= n ||
                board[newi][newj] == '$')
                continue;
            findTrieNode(root, newi, newj, board);
        }

        board[i][j] = temp;
    }

    int m, n;
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode();

        for (auto& w : words) {
            insertWord(root, w);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != nullptr) {
                    findTrieNode(root, i, j, board);
                }
            }
        }
        return ans;
    }
};