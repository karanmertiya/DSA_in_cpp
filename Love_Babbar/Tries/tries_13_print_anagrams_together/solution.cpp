// Time Complexity: O(N * K log K)
// Space Complexity: O(N * K)
// Explanation: Sort each string to form a key. Insert the sorted key into the Trie. At the end node of the key in the Trie, store a list of indices representing the original strings that map to this key.

struct TrieNode {
    TrieNode* children[26];
    vector<int> indices;
    TrieNode() { for(int i=0; i<26; i++) children[i] = NULL; }
};
class Solution{
    TrieNode* root;
    void insert(string word, int index) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->indices.push_back(index);
    }
    void traverse(TrieNode* node, vector<vector<string>>& ans, vector<string>& string_list) {
        if(node->indices.size() > 0) {
            vector<string> group;
            for(int i : node->indices) group.push_back(string_list[i]);
            ans.push_back(group);
        }
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) traverse(node->children[i], ans, string_list);
        }
    }
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        root = new TrieNode();
        for(int i = 0; i < string_list.size(); i++) {
            string s = string_list[i];
            sort(s.begin(), s.end());
            insert(s, i);
        }
        vector<vector<string>> ans;
        traverse(root, ans, string_list);
        return ans;
    }
};

