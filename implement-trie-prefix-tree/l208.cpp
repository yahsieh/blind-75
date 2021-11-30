class Node {
public:
    bool end;
    Node *next[26];
    Node() {
        end = false;
        for (int i=0;i<26;i++)
            next[i] = NULL;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node *cur = root;
        for (int i=0;i<word.size();i++) {
            char c = word[i];
            if (cur->next[c-'a'] == NULL) {
                cur->next[c-'a'] = new Node;
            }
            cur = cur->next[c-'a'];
            if (i==word.size()-1)
                cur->end = true;
        }
    }
    
    bool search(string word) {
        Node *cur = root;
        for (int i=0;i<word.size();i++) {
            char c = word[i];
            Node *nxt = cur->next[c-'a'];
            if (nxt == NULL)
                return false;
            else
                cur = nxt;
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for (int i=0;i<prefix.size();i++) {
            char c = prefix[i];
            Node *nxt = cur->next[c-'a'];
            if (nxt == NULL)
                return false;
            else
                cur = nxt;
        }
        return true;
    }
};