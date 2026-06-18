# Trees Revision Table

<table border="1">
  <thead>
    <tr>
      <th rowspan="2" style="width: 5%;">S.No</th>
      <th rowspan="2" style="width: 15%;">Problem Name</th>
      <th rowspan="2" style="width: 25%;">Example & Constraints</th>
      <th rowspan="2" style="width: 10%;">Complexity</th>
      <th colspan="2" style="width: 20%;">Conditions & Edge Cases</th>
      <th rowspan="2" style="width: 25%;">Logic</th>
    </tr>
    <tr>
      <th>Dependencies / Setup</th>
      <th>Edge Case Handling</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="1">1</td>
      <td rowspan="1">Tree 01 Binary Tree Inorder Traversal<br><br></b> <a href='https://leetcode.com/problems/binary-tree-inorder-traversal/' target='_blank'>LeetCode 94</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,null,2,3], Output: [1,3,2]<br><br><b>Note (Constraint):</b> Inorder -> Left, Root, Right.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>-</td>
      <td><b>Recursion Depth:</b> In the worst-case (skewed tree), the recursion stack takes `O(N)` space. For balanced trees, it takes `O(log N)`.</td>
      <td><b>Explanation:</b> Recursive approach. Traverse the left subtree, process the current node, then traverse the right subtree.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">/*&#10;struct TreeNode {&#10;    int val;&#10;    TreeNode *left;&#10;    TreeNode *right;&#10;    TreeNode(int x) : val(x), left(NULL), right(NULL) {}&#10;};&#10;*/&#10;#include &lt;vector&gt;&#10;&#10;void inorder(TreeNode* root, std::vector&lt;int&gt;&amp; ans) {&#10;    if (root == nullptr) return;&#10;    inorder(root-&gt;left, ans);&#10;    ans.push_back(root-&gt;val);&#10;    inorder(root-&gt;right, ans);&#10;}&#10;&#10;std::vector&lt;int&gt; inorderTraversal(TreeNode* root) {&#10;    std::vector&lt;int&gt; ans;&#10;    inorder(root, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Tree 02 Maximum Depth Of Binary Tree<br><br></b> <a href='https://leetcode.com/problems/maximum-depth-of-binary-tree/' target='_blank'>LeetCode 104</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: 3</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(H) &cong; O(N) (Constraint)</td>
      <td><code>std::max</code> / <code>max</code></td>
      <td><b>Null Root:</b> If the tree is empty (`root == NULL`), the depth is 0.</td>
      <td><b>Explanation:</b> Recursively find the max depth of left and right subtrees. The depth of the current node is `1 + max(left_depth, right_depth)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;algorithm&gt;&#10;&#10;int maxDepth(TreeNode* root) {&#10;    if (root == nullptr) return 0;&#10;    int leftDepth = maxDepth(root-&gt;left);&#10;    int rightDepth = maxDepth(root-&gt;right);&#10;    return 1 + std::max(leftDepth, rightDepth);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Tree 03 Lowest Common Ancestor Of A Binary Tree<br><br></b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1, Output: 3</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Node is LCA:</b> If one node is the ancestor of the other, the ancestor will be returned as soon as it's found, bypassing the need to search its subtree.</td>
      <td><b>Explanation:</b> Traverse the tree. If we find `p` or `q`, return it. If left and right subtrees both return non-null, the current node is the LCA. Otherwise, return the non-null subtree result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if (root == nullptr || root == p || root == q) return root;&#10;    &#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    &#10;    if (left == nullptr) return right;&#10;    else if (right == nullptr) return left;&#10;    else return root; // Both left and right are not null&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
