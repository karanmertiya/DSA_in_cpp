// Time Complexity: O(length of word) for all operations
// Space Complexity: O(total characters inserted * 26)
// Explanation: Create a Node struct with an array of 26 Node pointers and a boolean `flag`. Insert: Traverse characters, create new nodes if missing, mark last node's `flag = true`. Search: Traverse characters, return false if missing link, else return `flag` of last node. StartsWith: Similar to Search but return true at the end without checking `flag`.

struct Node {
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++) {
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

