// Time Complexity: O(min(M, N))
// Space Complexity: O(min(H1, H2))
// Explanation: Two trees are isomorphic if one can be obtained from another by a series of flips. If roots are null, return true. If values don't match, false. Then check `(isIsomorphic(n1.left, n2.left) && isIsomorphic(n1.right, n2.right))` OR `(isIsomorphic(n1.left, n2.right) && isIsomorphic(n1.right, n2.left))`.

bool isIsomorphic(Node *root1, Node *root2) {
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data) return false;
    bool no_swap = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool swap_case = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
    return no_swap || swap_case;
}

