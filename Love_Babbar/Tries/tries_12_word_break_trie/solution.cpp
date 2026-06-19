// Time Complexity: O(N^2)
// Space Complexity: O(N + sum of word lengths in dict)
// Explanation: Build a Trie with all words in `wordDict`. Use a recursive function with memoization `solve(i)` which returns true if the substring `s[i...]` can be segmented. Inside `solve(i)`, traverse the Trie starting from `s[i]`. If we reach a Trie node where `isEnd` is true, recursively call `solve(j+1)`. If any returns true, then `solve(i)` is true.

struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class Solution {
    TrieNode* root;
    vector<int> memo;
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool solve(string& s, int i) {
        if(i == s.length()) return true;
        if(memo[i] != -1) return memo[i];
        TrieNode* node = root;
        for(int j = i; j < s.length(); j++) {
            if(!node->children[s[j] - 'a']) break;
            node = node->children[s[j] - 'a'];
            if(node->isEnd && solve(s, j + 1)) return memo[i] = 1;
        }
        return memo[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for(string word : wordDict) insert(word);
        memo.assign(s.length(), -1);
        return solve(s, 0);
    }
};

