// Time Complexity: O(N * max_len)
// Space Complexity: O(N * max_len)
// Explanation: Insert all words into a Trie. For each word, check if every prefix exists (i.e., every node from root to end has `isEnd == true`). Keep track of the longest valid word. Resolve ties lexicographically.

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
    bool checkIfPrefixExists(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                if(!node->isEnd()) return false;
            } else return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &word : a) trie.insert(word);
    string longest = "";
    for(auto &word : a) {
        if(trie.checkIfPrefixExists(word)) {
            if(word.length() > longest.length()) {
                longest = word;
            } else if(word.length() == longest.length() && word < longest) {
                longest = word;
            }
        }
    }
    if(longest == "") return "None";
    return longest;
}

