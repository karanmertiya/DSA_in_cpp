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
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,null,2,3], Output: [1,3,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Recursion Depth:</b> Worst-case skewed tree takes `O(N)` space.</td>
      <td><b>Explanation:</b> Recursive approach. Traverse Left, process Root, then traverse Right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(TreeNode* root, std::vector&lt;int&gt;&amp; ans) {&#10;    if (!root) return;&#10;    inorder(root-&gt;left, ans);&#10;    ans.push_back(root-&gt;val);&#10;    inorder(root-&gt;right, ans);&#10;}&#10;std::vector&lt;int&gt; inorderTraversal(TreeNode* root) {&#10;    std::vector&lt;int&gt; ans;&#10;    inorder(root, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Tree 02 Maximum Depth Of Binary Tree<br><br></b> <a href='https://leetcode.com/problems/maximum-depth-of-binary-tree/' target='_blank'>LeetCode 104</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H) &cong; O(N)</td>
      <td><code>std::max</code></td>
      <td><b>Null Root:</b> If empty (`root == NULL`), depth is 0.</td>
      <td><b>Explanation:</b> Recursively find the max depth of left and right subtrees. The depth is `1 + max(left_depth, right_depth)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(TreeNode* root) {&#10;    if (!root) return 0;&#10;    return 1 + std::max(maxDepth(root-&gt;left), maxDepth(root-&gt;right));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Tree 03 Lowest Common Ancestor Of A Binary Tree<br><br></b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1, Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Node is LCA:</b> If one is ancestor of other, it returns immediately.</td>
      <td><b>Explanation:</b> If we find `p` or `q`, return it. If both left and right return non-null, current node is LCA.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if (!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if (!left) return right;&#10;    else if (!right) return left;&#10;    else return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Tree 04 Same Tree<br><br></b> <a href='https://leetcode.com/problems/same-tree/' target='_blank'>LeetCode 100</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: p = [1,2,3], q = [1,2,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Structural mismatch:</b> Safely handled by `!p || !q`.</td>
      <td><b>Explanation:</b> Traverse both trees simultaneously. If both nodes are null, true. If one is null or values mismatch, false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p &amp;&amp; !q) return true;&#10;    if(!p || !q || p-&gt;val != q-&gt;val) return false;&#10;    return isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Tree 05 Invert Binary Tree<br><br></b> <a href='https://leetcode.com/problems/invert-binary-tree/' target='_blank'>LeetCode 226</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [4,2,7,1,3,6,9], Output: [4,7,2,9,6,3,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>std::swap</code></td>
      <td><b>Empty Tree:</b> Returns null immediately.</td>
      <td><b>Explanation:</b> Recursively swap the left and right children of every node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* invertTree(TreeNode* root) {&#10;    if(!root) return nullptr;&#10;    std::swap(root-&gt;left, root-&gt;right);&#10;    invertTree(root-&gt;left);&#10;    invertTree(root-&gt;right);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
