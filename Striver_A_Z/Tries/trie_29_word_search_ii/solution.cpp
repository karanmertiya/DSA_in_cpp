// Time Complexity: O(M * N * 4^L)
// Space Complexity: O(sum(L))
// Explanation: Insert all words into a Trie. Store the actual word at the `isEnd` node for easy retrieval. Do DFS from each cell. During DFS, traverse the Trie simultaneously. If a Trie node has a word, add it to results and remove the word from the node to avoid duplicates.

struct Node {
    Node* links[26];
    string word = "";
};
class Trie {
public:
    Node* root = new Node();
    void insert(string& w) {
        Node* node = root;
        for(char c : w) {
            if(!node->links[c-'a']) node->links[c-'a'] = new Node();
            node = node->links[c-'a'];
        }
        node->word = w;
    }
};
void dfs(vector<vector<char>>& board, int i, int j, Node* p, vector<string>& res) {
    char c = board[i][j];
    if(c == '#' || !p->links[c-'a']) return;
    p = p->links[c-'a'];
    if(p->word != "") {
        res.push_back(p->word);
        p->word = "";
    }
    board[i][j] = '#';
    if(i > 0) dfs(board, i-1, j, p, res);
    if(j > 0) dfs(board, i, j-1, p, res);
    if(i < board.size()-1) dfs(board, i+1, j, p, res);
    if(j < board[0].size()-1) dfs(board, i, j+1, p, res);
    board[i][j] = c;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie t;
    for(string w : words) t.insert(w);
    vector<string> res;
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            dfs(board, i, j, t.root, res);
        }
    }
    return res;
}

