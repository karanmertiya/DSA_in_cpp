// Time Complexity: O(N) Add, O(N * 26) Search
// Space Complexity: O(Total Chars)
// Explanation: Store dictionary in a Trie. For searching, recursively traverse the Trie. Maintain a `modified` boolean flag. If characters mismatch, set `modified` to true and continue. If we reach the end of the word and `modified` is true, return true.

struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class MagicDictionary {
    TrieNode* root;
    bool dfs(string& word, int i, TrieNode* node, bool modified) {
        if(i == word.length()) return modified && node->isEnd;
        if(modified) {
            if(node->children[word[i] - 'a']) {
                return dfs(word, i + 1, node->children[word[i] - 'a'], true);
            }
            return false;
        }
        for(int j = 0; j < 26; j++) {
            if(node->children[j]) {
                if(dfs(word, i + 1, node->children[j], j != (word[i] - 'a'))) return true;
            }
        }
        return false;
    }
public:
    MagicDictionary() { root = new TrieNode(); }
    void buildDict(vector<string> dictionary) {
        for(string word : dictionary) {
            TrieNode* node = root;
            for(char c : word) {
                if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }
    }
    bool search(string searchWord) {
        return dfs(searchWord, 0, root, false);
    }
};

