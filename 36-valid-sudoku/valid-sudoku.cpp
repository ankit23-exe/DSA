class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        // row checking
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                if (s.find(board[i][j]) != s.end()) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
        // column checking
        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;

                if (s.find(board[j][i]) != s.end()) {
                    return false;
                }
                s.insert(board[j][i]);
            }
        }
        // checking box
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                unordered_set<char> s;
                for (int i = sr; i <= er; i++) {
                    for (int j = sc; j <= ec; j++) {
                        if (board[i][j] == '.')
                            continue;

                        if (s.find(board[i][j]) != s.end()) {
                            return false;
                        }
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;

        */
         unordered_set<string> s;
        for (int i = 0; i < 9; i++) {
           
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.'){
                    continue;
                }
                string rowKey = "row" + to_string(i) + "_" + to_string(board[i][j]);
                string colKey = "col" + to_string(j) + "_" + to_string(board[i][j]);
                string boxKey = "box" + to_string(i / 3) + "_" +
                                to_string(j / 3) + "_" + to_string(board[i][j]);

                if (s.count(rowKey) || s.count(colKey) || s.count(boxKey)) {
                    // duplicate found
                    return false;
                }

                s.insert(rowKey);
                s.insert(colKey);
                s.insert(boxKey);
            }
        }
        return true;
    }
}

;