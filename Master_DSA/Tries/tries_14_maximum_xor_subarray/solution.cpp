// Time Complexity: O(N * 32)
// Space Complexity: O(N * 32)
// Explanation: Compute prefix XORs. For each prefix XOR `curr_xor`, insert it into a Trie. Then, query the Trie to find the maximum XOR of `curr_xor` with any previously inserted prefix XOR (by trying to follow the opposite bit path). The maximum value over all queries is the answer.

struct Node {
    Node* links[2];
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
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
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
int maxSubarrayXOR(int N, int arr[]) {
    Trie trie;
    trie.insert(0);
    int max_xor = INT_MIN, curr_xor = 0;
    for(int i = 0; i < N; i++) {
        curr_xor ^= arr[i];
        trie.insert(curr_xor);
        max_xor = max(max_xor, trie.getMax(curr_xor));
    }
    return max_xor;
}

