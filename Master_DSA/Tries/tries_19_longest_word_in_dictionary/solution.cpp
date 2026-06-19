// Time Complexity: O(Total Chars)
// Space Complexity: O(Total Chars)
// Explanation: Insert all words into a Trie, marking the end of each word. Perform DFS on the Trie. Only proceed to children that are marked as the end of a word (i.e., `isEnd == true`). Keep track of the longest string found during DFS.

struct TrieNode {
    TrieNode* children[26];
    string word = "";
    bool isEnd = false;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class Solution {
    TrieNode* root;
    string longest = "";
    void dfs(TrieNode* node) {
        if(node->isEnd) {
            if(node->word.length() > longest.length() || (node->word.length() == longest.length() && node->word < longest)) {
                longest = node->word;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(node->children[i] && node->children[i]->isEnd) {
                dfs(node->children[i]);
            }
        }
    }
public:
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for(string w : words) {
            TrieNode* node = root;
            for(char c : w) {
                if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
            node->word = w;
        }
        for(int i = 0; i < 26; i++) {
            if(root->children[i] && root->children[i]->isEnd) {
                dfs(root->children[i]);
            }
        }
        return longest;
    }
};

