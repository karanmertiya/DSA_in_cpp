// Time Complexity: O(N * 32)
// Space Complexity: O(N * 32)
// Explanation: Insert binary representation of each number (from MSB to LSB, 31 to 0) into a Trie. To find max XOR for `x`, traverse the Trie aiming for opposite bits (1 for 0, 0 for 1). If opposite bit exists, go that way and add `1 << i` to result. Else go same way.

struct Node {
    Node *links[2];
    bool containsKey(int bit) { return links[bit] != NULL; }
    void put(int bit, Node* node) { links[bit] = node; }
    Node* get(int bit) { return links[bit]; }
};
class Trie {
    Node* root;
public:
    Trie() { root = new Node(); }
    void insert(int num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for(auto &it : nums) trie.insert(it);
    int maxi = 0;
    for(auto &it : nums) {
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}

