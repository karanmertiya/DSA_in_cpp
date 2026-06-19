// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: The first element of preorder is the root. Find its index in inorder array using a hash map. The left part of inorder is the left subtree, right part is right subtree. Recurse.

TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

