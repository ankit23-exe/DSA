class Trie {
public:
    struct trieNode{
        bool endword;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* temp = new trieNode();
        temp->endword = false;
        for(int i=0;i<26;i++){
            temp->children[i]=NULL;
        }
        return temp;
    }

    trieNode* root = getNode();

    
    
    Trie() {
        
    }
    
    void insert(string word) {
        trieNode* crawl = root;
        
        for(auto &w:word){
            if(crawl->children[w-'a']==NULL){
                crawl->children[w-'a'] = getNode();
            }
            crawl = crawl->children[w-'a']; 
        }
        crawl->endword = true;
    }
    
    bool search(string word) {
        trieNode* crawl = root;
        
        for(auto &w:word){
            if(crawl->children[w-'a']==NULL){
                return false;
            }
            crawl = crawl->children[w-'a'];  
        }
        return crawl->endword;
        
    }
    
    bool startsWith(string prefix) {

        trieNode* crawl = root;
        
        for(auto &w:prefix){
            if(crawl->children[w-'a']==NULL){
                return false;
            }
            crawl = crawl->children[w-'a'];  
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */