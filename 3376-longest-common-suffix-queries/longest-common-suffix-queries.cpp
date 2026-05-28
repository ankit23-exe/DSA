class Solution {
public:
    struct trieNode {
        bool wordEnd;
        trieNode* children[26];
        int bestLen;
        int bestIdx;
        ~trieNode() { //Adding a desctructor
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };
    trieNode* getNode() {
        trieNode* temp = new trieNode();
        temp->wordEnd = false;
        temp->bestLen = INT_MAX;
        temp->bestIdx = INT_MAX;
        for (int i = 0; i < 26; i++) {
            temp->children[i] = NULL;
        }
        return temp;
    }
    void insert(trieNode* root, string& word, int ind) {

        int size = word.size();
        trieNode* temp = root;

        // update root
        if (size < temp->bestLen) {
            temp->bestLen = size;
            temp->bestIdx = ind;
        } else if (size == temp->bestLen) {
            temp->bestIdx = min(temp->bestIdx, ind);
        }

        for (int i = size - 1; i >= 0; i--) {

            int idx = word[i] - 'a';

            if (temp->children[idx] == NULL) {
                temp->children[idx] = getNode();
            }

            temp = temp->children[idx];

            if (size < temp->bestLen) {
                temp->bestLen = size;
                temp->bestIdx = ind;
            } else if (size == temp->bestLen) {
                temp->bestIdx = min(temp->bestIdx, ind);
            }
        }
    }

    int query(trieNode* root, string &word) {
        int size = word.size();
        trieNode* temp = root;
        for (int i = size - 1; i >= 0; i--) {
            int idx = word[i] - 'a';
            if (temp->children[idx] == NULL) {
                // find the smallest index thing
                return temp->bestIdx;
            }
            temp = temp->children[idx];
        }
        // find the smallest index thing(bfs)
        return temp->bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsQuery.size();
        vector<int> ans(n, 0);
        trieNode* root = getNode();
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(root, wordsContainer[i], i);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = query(root, wordsQuery[i]);
        }
        delete root; 
        return ans;
    }
};