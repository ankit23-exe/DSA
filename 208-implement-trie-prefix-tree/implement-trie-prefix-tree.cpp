class Trie {
public:

    struct trieNode{
        bool isWordEnd;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* root = new trieNode();
        root->isWordEnd = false;
        for(int i=0;i<26;i++){
            root->children[i]=nullptr;
        }
        return root;
    }

    trieNode* root = getNode();

    

    Trie() {
        
    }
    
    void insert(string word) {
        trieNode* crawl = root;
        for(auto &w:word){
            if(crawl->children[w-'a']==nullptr){
                crawl->children[w-'a']=getNode();
            }
            crawl = crawl->children[w-'a'];
        }
        crawl->isWordEnd = true;
    }
    
    bool search(string word) {
        trieNode* crawl = root;
        for(auto &w:word){
            if(crawl->children[w-'a']==nullptr){
                return false;
            }
            crawl = crawl->children[w-'a'];
        }
        return crawl->isWordEnd ;
        
        
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl = root;
        for(auto &w:prefix){
            if(crawl->children[w-'a']==nullptr){
                return false;
            }
            crawl = crawl->children[w-'a'];
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */