// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Constraint)
// Explanation: Recursive approach. Traverse the left subtree, process the current node, then traverse the right subtree.

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
#include <vector>

void inorder(TreeNode* root, std::vector<int>& ans) {
    if (root == nullptr) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> ans;
    inorder(root, ans);
    return ans;
}

