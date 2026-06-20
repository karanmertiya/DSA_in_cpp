// Time Complexity: O(Length of word) (Constraint)
// Space Complexity: O(Length * 26) per word
// Explanation: Use a Tree where each node contains an array of 26 pointers (for 'a'-'z') and a boolean flag `isEnd`.

struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) { return (links[ch - 'a'] != nullptr); }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;
public:
    Trie() { root = new Node(); }
    
    void insert(std::string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(std::string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(std::string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
};

