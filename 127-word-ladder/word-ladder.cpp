class Solution {
public:
    bool onlyOneCharDif(string& w1, string& w2) {
        int difCount = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i])
                difCount++;
        }
        return (difCount == 1);
    }
    int bfs(string& beginWord, string& endWord,
            map<string, set<string>>& adjlist) {
        queue<string> que;
        que.push(beginWord);
        int count = 1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                string s = que.front();
                que.pop();
                if (s == endWord)
                    return count;
                for (auto neigh : adjlist[s]) {
                    que.push(neigh);
                }
                adjlist.erase(s);
            }

            count++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        // checking if endWord not in wordList return 0
        bool flag = false;
        for (string& w : wordList) {
            if (endWord == w)
                flag = true;
        }
        if (!flag)
            return 0;

        map<string, set<string>> adjlist;
        // baki ka sara elements
        for (string& w : wordList) {
            for (int i = 0; i < wordList.size(); i++) {
                if (w == wordList[i])
                    continue;
                if (onlyOneCharDif(w, wordList[i])) {
                    adjlist[w].insert(wordList[i]);
                }
            }
        }
        // beginword
        string w = beginWord;
        for (int i = 0; i < wordList.size(); i++) {

            if (onlyOneCharDif(w, wordList[i])) {
                adjlist[w].insert(wordList[i]);
            }
        }

        return bfs(beginWord, endWord, adjlist);
    }
};