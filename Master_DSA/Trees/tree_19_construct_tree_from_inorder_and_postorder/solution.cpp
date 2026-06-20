// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Store inorder indices in a HashMap. The last element in postorder is the root. Find this root in inorder map to determine left subtree size. Recursively build left and right subtrees by slicing array indices.

TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inMap) {
    if(inStart > inEnd || postStart > postEnd) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> inMap;
    for(int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
    TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    return root;
}

