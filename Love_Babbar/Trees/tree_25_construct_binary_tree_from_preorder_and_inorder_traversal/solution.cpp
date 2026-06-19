// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a hash map to store indices of inorder elements. The first element of preorder is the root. Find its index in inorder array to divide into left and right subtrees. Recursively build left and right.

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}

