// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Similar to preorder+inorder, but the root is at the end of the postorder array. Map inorder indices. Find root, divide, and recurse.

TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap) {
    if(inStart > inEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTreeHelper(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
}

