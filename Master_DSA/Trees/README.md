# Trees & Binary Search Trees (BST)
## 🧠 Core Intuition
Hierarchical nodes linked by edges. Binary Trees limit nodes to at most two children. BSTs enforce strict ordering (Left < Root < Right) for lightning-fast lookups.

## 🛠️ Dependencies & Prerequisites
You must be comfortable with recursion and Queue data structures (for BFS).

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Standard DFS
void dfs(TreeNode* root) {
    if (!root) return;
    // Pre-order logic
    dfs(root->left);
    // In-order logic
    dfs(root->right);
    // Post-order logic
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Standard DFS
def dfs(root: TreeNode):
    if not root:
        return
    # Pre-order logic
    dfs(root.left)
    # In-order logic
    dfs(root.right)
    # Post-order logic
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Balanced BST (Time) | Unbalanced BST (Time) |
| :--- | :--- | :--- |
| **Search** | `O(log N)` | `O(N)` |
| **Insert** | `O(log N)` | `O(N)` |
| **Delete** | `O(log N)` | `O(N)` |

## 💡 Elite Patterns
- **DFS Traversals:** 
  - **Inorder:** Left, Root, Right. (Yields sorted order in a BST).
  - **Preorder:** Root, Left, Right.
  - **Postorder:** Left, Right, Root.
- **Level Order Traversal (BFS):** Use a Queue. Process nodes level by level.
- **Bottom-Up Recursion:** Have leaf nodes return values up to their parents (e.g., to calculate heights or balanced states in `O(N)`).
