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
      <td rowspan="1">Tree 10 Lowest Common Ancestor<br><br></b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,5,1,6,2,0,8], p = 5, q = 1, Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H) recursion stack</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS traversal. If root is NULL or equals p or q, return root. Recursively find LCA in left and right subtrees. If both return non-null, root is LCA. Otherwise return the non-null child.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if(!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if(left &amp;&amp; right) return root;&#10;    return left ? left : right;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Tree 11 Construct Tree From Preorder And Inorder<br><br></b> <a href='https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/' target='_blank'>LeetCode 105</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for Hash Map</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    unordered_map&lt;int, int&gt; inMap;&#10;    for(int i=0; i&lt;inorder.size(); i++) inMap[inorder[i]] = i;&#10;    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; pre, int preStart, int preEnd, vector&lt;int&gt;&amp; in, int inStart, int inEnd, unordered_map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(pre[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);&#10;    root-&gt;right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Tree 12 Diameter Of Binary Tree<br><br></b> <a href='https://leetcode.com/problems/diameter-of-binary-tree/' target='_blank'>LeetCode 543</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,2,3,4,5], Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Modify the standard Height of Binary Tree DFS. Compute left height and right height. At each node, the diameter passing through it is `left + right`. Track the max.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int diameterOfBinaryTree(TreeNode* root) {&#10;    int diameter = 0;&#10;    height(root, diameter);&#10;    return diameter;&#10;}&#10;int height(TreeNode* node, int&amp; diameter) {&#10;    if(!node) return 0;&#10;    int lh = height(node-&gt;left, diameter);&#10;    int rh = height(node-&gt;right, diameter);&#10;    diameter = max(diameter, lh + rh);&#10;    return 1 + max(lh, rh);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Tree 13 Maximum Path Sum<br><br></b> <a href='https://leetcode.com/problems/binary-tree-maximum-path-sum/' target='_blank'>LeetCode 124</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [-10,9,20,null,null,15,7], Output: 42</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>All Negative Nodes:</b> Initialization with `INT_MIN` properly returns the least negative node.</td>
      <td><b>Explanation:</b> DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxPathSum(TreeNode* root) {&#10;    int maxi = INT_MIN;&#10;    maxPathDown(root, maxi);&#10;    return maxi;&#10;}&#10;int maxPathDown(TreeNode* node, int&amp; maxi) {&#10;    if(!node) return 0;&#10;    int left = max(0, maxPathDown(node-&gt;left, maxi));&#10;    int right = max(0, maxPathDown(node-&gt;right, maxi));&#10;    maxi = max(maxi, left + right + node-&gt;val);&#10;    return max(left, right) + node-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Tree 14 Same Tree<br><br></b> <a href='https://leetcode.com/problems/same-tree/' target='_blank'>LeetCode 100</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: p = [1,2,3], q = [1,2,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Preorder DFS simultaneously on both trees. If both are null, true. If one is null or vals mismatch, false. Recursively check left and right subtrees.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p || !q) return p == q;&#10;    return (p-&gt;val == q-&gt;val) &amp;&amp; isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Tree 15 Boundary Traversal<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return array of boundary nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isLeaf(TreeNode* root) { return !root-&gt;left &amp;&amp; !root-&gt;right; }&#10;void addLeft(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;left;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) res.push_back(cur-&gt;val);&#10;        if(cur-&gt;left) cur = cur-&gt;left;&#10;        else cur = cur-&gt;right;&#10;    }&#10;}&#10;void addRight(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;right;&#10;    vector&lt;int&gt; tmp;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) tmp.push_back(cur-&gt;val);&#10;        if(cur-&gt;right) cur = cur-&gt;right;&#10;        else cur = cur-&gt;left;&#10;    }&#10;    for(int i = tmp.size()-1; i&gt;=0; --i) res.push_back(tmp[i]);&#10;}&#10;void addLeaves(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    if(isLeaf(root)) { res.push_back(root-&gt;val); return; }&#10;    if(root-&gt;left) addLeaves(root-&gt;left, res);&#10;    if(root-&gt;right) addLeaves(root-&gt;right, res);&#10;}&#10;vector&lt;int&gt; boundary(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    if(!isLeaf(root)) res.push_back(root-&gt;val);&#10;    addLeft(root, res); addLeaves(root, res); addRight(root, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
