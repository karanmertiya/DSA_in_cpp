// Time Complexity: O(N log N + Q log Q + Q * 32 + N * 32)
// Space Complexity: O(N * 32 + Q)
// Explanation: Sort `nums` array. Store queries as `{m, x, index}` and sort them by `m`. Iterate through queries. While `nums[i] <= m`, insert `nums[i]` into Trie. If Trie is empty, answer is -1. Else, query Trie for max XOR with `x`.

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
            if(!node->containsKey(bit)) node->put(bit, new Node());
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
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> oQ;
    for(int i=0; i<queries.size(); i++) {
        oQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(oQ.begin(), oQ.end());
    vector<int> ans(queries.size(), 0);
    int ind = 0;
    int n = nums.size();
    Trie trie;
    for(int i=0; i<oQ.size(); i++) {
        int m = oQ[i].first, x = oQ[i].second.first, qInd = oQ[i].second.second;
        while(ind < n && nums[ind] <= m) {
            trie.insert(nums[ind]);
            ind++;
        }
        if(ind == 0) ans[qInd] = -1;
        else ans[qInd] = trie.getMax(x);
    }
    return ans;
}

