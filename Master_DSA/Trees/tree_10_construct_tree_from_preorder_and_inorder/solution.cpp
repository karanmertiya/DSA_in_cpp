// Time Complexity: O(N)
// Space Complexity: O(N) for Hash Map
// Explanation: First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
}
TreeNode* build(vector<int>& pre, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(pre[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);
    root->right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);
    return root;
}

