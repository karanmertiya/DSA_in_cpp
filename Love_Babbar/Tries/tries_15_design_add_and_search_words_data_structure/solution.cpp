// Time Complexity: O(Word Length) for Add, O(26^Dots * Word Length) for Search
// Space Complexity: O(Total Chars)
// Explanation: Add words normally to the Trie. When searching, if the current character is '.', iterate over all 26 possible children and recursively search the remaining word. If any path returns true, the word is found.

struct TrieNode {
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class WordDictionary {
    TrieNode* root;
    bool searchInNode(string& word, int i, TrieNode* node) {
        if(node == NULL) return false;
        if(i == word.length()) return node->isEnd;
        if(word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }
        for(int j = 0; j < 26; j++) {
            if(searchInNode(word, i + 1, node->children[j])) return true;
        }
        return false;
    }
public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};

