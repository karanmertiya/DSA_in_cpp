// Time Complexity: O(N * L^2)
// Space Complexity: O(N * L)
// Explanation: Insert the REVERSE of every word into a Trie. Store index of word at node. For each word, search the Trie. Three cases: 1. Trie word is longer (current word exhausted, check if rest of Trie branch is palindrome). 2. Current word is longer (Trie exhausted, check if rest of current word is palindrome). 3. Exact match. Store valid indices.

struct Node {
    Node* links[26];
    int index = -1;
    vector<int> pal_indices;
};
class Trie {
public:
    Node* root = new Node();
    bool isPal(string& s, int i, int j) {
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    void insert(string& w, int id) {
        Node* node = root;
        for(int i = w.size()-1; i >= 0; i--) {
            if(isPal(w, 0, i)) node->pal_indices.push_back(id);
            if(!node->links[w[i]-'a']) node->links[w[i]-'a'] = new Node();
            node = node->links[w[i]-'a'];
        }
        node->index = id;
        node->pal_indices.push_back(id);
    }
};
vector<vector<int>> palindromePairs(vector<string>& words) {
    Trie t;
    for(int i=0; i<words.size(); i++) t.insert(words[i], i);
    vector<vector<int>> res;
    for(int i=0; i<words.size(); i++) {
        Node* node = t.root;
        string w = words[i];
        for(int j=0; j<w.size(); j++) {
            if(node->index != -1 && node->index != i && t.isPal(w, j, w.size()-1)) {
                res.push_back({i, node->index});
            }
            if(!node->links[w[j]-'a']) { node = NULL; break; }
            node = node->links[w[j]-'a'];
        }
        if(node) {
            for(int id : node->pal_indices) {
                if(i != id) res.push_back({i, id});
            }
        }
    }
    return res;
}

