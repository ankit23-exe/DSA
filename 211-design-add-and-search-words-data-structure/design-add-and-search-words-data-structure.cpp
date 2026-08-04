class WordDictionary {
public:
    struct trieNode{
        bool IsWordEnd;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* root = new trieNode();
        root->IsWordEnd=false;
        for(int i=0;i<26;i++){
            root->children[i]=nullptr;
        }
        return root;
    }

    trieNode*  root = getNode();

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trieNode* crawl = root;
        for(auto &w:word){
            if(crawl->children[w-'a']==nullptr){
                crawl->children[w-'a']=getNode();
            }
            crawl=crawl->children[w-'a'];
        }
        crawl->IsWordEnd = true;
    }

    bool finder(int i,trieNode* root,string &word){
        if(i==word.size()){
            if(root->IsWordEnd)
                return true;
            return false;
        }
        if(word[i]!='.'){
            if(root->children[word[i]-'a']==nullptr) return false;
            if(finder(i+1,root->children[word[i]-'a'],word)) return true;
        }else{
            for(int k=0;k<26;k++)

                if(root->children[k]!=nullptr && 
                finder(i+1,root->children[k],word)) return true;
        }
        return false;
    }
    
    bool search(string word) {
        return finder(0,root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */