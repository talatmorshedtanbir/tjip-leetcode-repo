// https://leetcode.com/problems/implement-trie-prefix-tree/
// Time Complexity: O(N*M) 
// Spcae Complexity: O(N*M)

class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
public:
    Trie() {
        root = new TrieNode;
    }

    ~Trie(){
        clear(root);
    }

    void insert(string word) {
        TrieNode *temp = root;

        for(int i = 0; i < word.size(); i++) {
            if(temp->next[word[i] - 'a'] == nullptr)
                temp->next[word[i] - 'a'] = new TrieNode;
            temp = temp->next[word[i]-'a'];
        }

        temp->is_word = true;
    }

    bool search(string word) {
        TrieNode *temp = find(word);
        if(temp != nullptr && (temp->is_word))
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *temp = find(prefix);
        if(temp != nullptr)
            return true;
        else
            return false;
    }

private:
    TrieNode *root;

    TrieNode* find(string word) {
        TrieNode *p = root;
        for(int i=0; i< word.size() && p!= NULL; ++i) {
            p = p -> next[word[i]-'a'];
        }

        return p;
    }

    void clear(TrieNode *root){
        for(int i = 0; i < 26; i++){
            if(root->next[i] != nullptr){
                clear(root->next[i]);
            }
        }

        delete root;
    }
};
