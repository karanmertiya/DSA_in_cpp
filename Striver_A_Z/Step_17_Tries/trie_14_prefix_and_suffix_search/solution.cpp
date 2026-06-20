// Time Complexity: O(N * K^2) Insert, O(K) Search
// Space Complexity: O(N * K^2)
// Explanation: For each word, generate all possible suffixes, append a special character '{', and then append the original word. Insert all these combinations into a Trie along with the index. When querying, search for `suffix + '{' + prefix` in the Trie.

struct TrieNode {
    TrieNode* children[27];
    int index = -1;
    TrieNode() { for(int i=0; i<27; i++) children[i] = NULL; }
};
class WordFilter {
    TrieNode* root;
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            for(int j = 0; j <= w.length(); j++) {
                string s = w.substr(j) + "{" + w;
                TrieNode* node = root;
                for(char c : s) {
                    if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                    node = node->children[c - 'a'];
                    node->index = i;
                }
            }
        }
    }
    int f(string pref, string suff) {
        string s = suff + "{" + pref;
        TrieNode* node = root;
        for(char c : s) {
            if(!node->children[c - 'a']) return -1;
            node = node->children[c - 'a'];
        }
        return node->index;
    }
};

