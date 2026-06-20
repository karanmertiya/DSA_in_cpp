// Time Complexity: O(N * M * 4^L) where L is max word length
// Space Complexity: O(Total Chars in Dict)
// Explanation: Build a Trie from the dictionary. Perform DFS from every cell in the matrix. During DFS, traverse the Trie simultaneously. If `node.word` is found, add it to result and clear `node.word` to prevent duplicates. Mark visited cells to avoid loops.

struct TrieNode {
    TrieNode* children[26];
    string word = "";
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class Solution {
    vector<string> ans;
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if(c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j, node);
        if(j > 0) dfs(board, i, j - 1, node);
        if(i < board.size() - 1) dfs(board, i + 1, j, node);
        if(j < board[0].size() - 1) dfs(board, i, j + 1, node);
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string w : words) {
            TrieNode* node = root;
            for(char c : w) {
                if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->word = w;
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

