// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Explanation: To find all substrings, iterate `i` from 0 to N-1, and `j` from `i` to N-1. Each sequence `s[i...j]` is a substring. Insert it into the Trie. Every time we create a new node, it corresponds to a new distinct substring. Increment count. Add 1 for the empty substring.

struct Node {
    Node *links[26];
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
};
int countDistinctSubstrings(string s) {
    Node* root = new Node();
    int count = 0;
    for(int i=0; i<s.length(); i++) {
        Node* node = root;
        for(int j=i; j<s.length(); j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}

