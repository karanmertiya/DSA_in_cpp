// Time Complexity: O(N * W)
// Space Complexity: O(Total Chars in Dict + Sentence Length)
// Explanation: Insert all dictionary roots into a Trie. For each word in the sentence, search the Trie. If a prefix matches a root (i.e., `isEnd` becomes true), replace the word with the root. If no root matches, keep the original word.

struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class Solution {
    TrieNode* root;
    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    string findRoot(string word) {
        TrieNode* node = root;
        string prefix = "";
        for(char c : word) {
            if(!node->children[c - 'a']) break;
            prefix += c;
            node = node->children[c - 'a'];
            if(node->isEnd) return prefix;
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for(string w : dictionary) insert(w);
        string ans = "", word = "";
        for(char c : sentence) {
            if(c == ' ') {
                ans += findRoot(word) + " ";
                word = "";
            } else {
                word += c;
            }
        }
        ans += findRoot(word);
        return ans;
    }
};

