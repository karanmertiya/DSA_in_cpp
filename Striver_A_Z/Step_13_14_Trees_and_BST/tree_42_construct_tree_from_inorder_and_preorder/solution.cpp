// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: The first element in preorder is the root. Find this root in inorder using a hash map. Elements to the left in inorder form the left subtree, elements to the right form the right subtree. Recurse.

Node* buildTreeUtil(int in[], int pre[], int inSt, int inEnd, int& preIdx, unordered_map<int, int>& mp) {
    if(inSt > inEnd) return NULL;
    int curr = pre[preIdx++];
    Node* tNode = new Node(curr);
    if(inSt == inEnd) return tNode;
    int inIdx = mp[curr];
    tNode->left = buildTreeUtil(in, pre, inSt, inIdx - 1, preIdx, mp);
    tNode->right = buildTreeUtil(in, pre, inIdx + 1, inEnd, preIdx, mp);
    return tNode;
}
Node* buildTree(int in[], int pre[], int n) {
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[in[i]] = i;
    int preIdx = 0;
    return buildTreeUtil(in, pre, 0, n - 1, preIdx, mp);
}

