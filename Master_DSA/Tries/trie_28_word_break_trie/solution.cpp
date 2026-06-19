// Time Complexity: O(N^2 + sum(word_len))
// Space Complexity: O(N + sum(word_len))
// Explanation: Insert all dictionary words into a Trie. Use DP where `dp[i]` is true if `s[0...i-1]` is valid. For index `i`, start a Trie search. If we find a valid word ending at `j`, then `dp[j+1]` becomes true (if `dp[i]` was true).

struct Node {
    Node *links[26];
    bool isEnd = false;
};
class Trie {
public:
    Node* root = new Node();
    void insert(string word) {
        Node* node = root;
        for(char c : word) {
            if(!node->links[c-'a']) node->links[c-'a'] = new Node();
            node = node->links[c-'a'];
        }
        node->isEnd = true;
    }
};
bool wordBreak(string s, vector<string>& wordDict) {
    Trie t;
    for(string w : wordDict) t.insert(w);
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for(int i=0; i<s.length(); i++) {
        if(!dp[i]) continue;
        Node* node = t.root;
        for(int j=i; j<s.length(); j++) {
            if(!node->links[s[j]-'a']) break;
            node = node->links[s[j]-'a'];
            if(node->isEnd) dp[j+1] = true;
        }
    }
    return dp[s.length()];
}

