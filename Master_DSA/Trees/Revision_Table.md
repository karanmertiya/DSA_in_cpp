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
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Tree 06 Diameter Of Binary Tree<br><br></b> <a href='https://leetcode.com/problems/diameter-of-binary-tree/' target='_blank'>LeetCode 543</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,2,3,4,5], Output: 3 (Path is [4,2,1,3] or [5,2,1,3])</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>std::max</code></td>
      <td><b>Path doesn't pass through root:</b> Handled correctly by tracking the global maximum `max_d` at every recursive step.</td>
      <td><b>Explanation:</b> Modify the Height/Depth algorithm. Calculate `left_depth + right_depth` at every node to find max diameter, while returning standard height.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int height(TreeNode* node, int&amp; max_d) {&#10;    if(!node) return 0;&#10;    int left = height(node-&gt;left, max_d);&#10;    int right = height(node-&gt;right, max_d);&#10;    max_d = std::max(max_d, left + right);&#10;    return 1 + std::max(left, right);&#10;}&#10;int diameterOfBinaryTree(TreeNode* root) {&#10;    int max_d = 0;&#10;    height(root, max_d);&#10;    return max_d;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Tree 07 Balanced Binary Tree<br><br></b> <a href='https://leetcode.com/problems/balanced-binary-tree/' target='_blank'>LeetCode 110</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>std::abs</code></td>
      <td><b>Early Exit:</b> Checking if `left == -1` or `right == -1` immediately breaks the recursion, optimizing time.</td>
      <td><b>Explanation:</b> Modify the Height algorithm. If the difference between `left` and `right` height is > 1, return `-1` to propagate the unbalanced signal.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int checkHeight(TreeNode* node) {&#10;    if(!node) return 0;&#10;    int left = checkHeight(node-&gt;left);&#10;    if(left == -1) return -1;&#10;    int right = checkHeight(node-&gt;right);&#10;    if(right == -1) return -1;&#10;    if(std::abs(left - right) &gt; 1) return -1;&#10;    return 1 + std::max(left, right);&#10;}&#10;bool isBalanced(TreeNode* root) {&#10;    return checkHeight(root) != -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Tree 08 Binary Search Tree Iterator<br><br></b> <a href='https://leetcode.com/problems/binary-search-tree-iterator/' target='_blank'>LeetCode 173</a></td>
      <td rowspan="1"><b>Example 1:</b> next() returns smallest element.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(H)</td>
      <td><code>#include <stack></code></td>
      <td><b>Empty Tree:</b> Stack is empty.</td>
      <td><b>Explanation:</b> Use a stack to simulate in-order traversal. Push all left children initially. On next(), pop, return val, and push all left children of popped node's right child.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BSTIterator {&#10;    stack&lt;TreeNode*&gt; st;&#10;    void pushAll(TreeNode* node) {&#10;        while(node) {&#10;            st.push(node);&#10;            node = node-&gt;left;&#10;        }&#10;    }&#10;public:&#10;    BSTIterator(TreeNode* root) {&#10;        pushAll(root);&#10;    }&#10;    int next() {&#10;        TreeNode* tmpNode = st.top();&#10;        st.pop();&#10;        pushAll(tmpNode-&gt;right);&#10;        return tmpNode-&gt;val;&#10;    }&#10;    bool hasNext() {&#10;        return !st.empty();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Tree 09 Validate Binary Search Tree<br><br></b> <a href='https://leetcode.com/problems/validate-binary-search-tree/' target='_blank'>LeetCode 98</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [2,1,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>Values reach INT bounds:</b> Use LLONG_MIN/LLONG_MAX bounds.</td>
      <td><b>Explanation:</b> Recursive validation with min and max bounds for every node. Long long is used to avoid overflow.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValidBST(TreeNode* root, long minVal, long maxVal) {&#10;    if(!root) return true;&#10;    if(root-&gt;val &gt;= maxVal || root-&gt;val &lt;= minVal) return false;&#10;    return isValidBST(root-&gt;left, minVal, root-&gt;val) &amp;&amp; isValidBST(root-&gt;right, root-&gt;val, maxVal);&#10;}&#10;bool isValidBST(TreeNode* root) {&#10;    return isValidBST(root, LONG_MIN, LONG_MAX);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Tree 10 Lowest Common Ancestor<br><br></b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,5,1,6,2,0,8], p = 5, q = 1, Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H) recursion stack</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS traversal. If root is NULL or equals p or q, return root. Recursively find LCA in left and right subtrees. If both return non-null, root is LCA. Otherwise return the non-null child.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if(!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if(left &amp;&amp; right) return root;&#10;    return left ? left : right;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Tree 11 Construct Tree From Preorder And Inorder<br><br></b> <a href='https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/' target='_blank'>LeetCode 105</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for Hash Map</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    unordered_map&lt;int, int&gt; inMap;&#10;    for(int i=0; i&lt;inorder.size(); i++) inMap[inorder[i]] = i;&#10;    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; pre, int preStart, int preEnd, vector&lt;int&gt;&amp; in, int inStart, int inEnd, unordered_map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(pre[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);&#10;    root-&gt;right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Tree 12 Diameter Of Binary Tree<br><br></b> <a href='https://leetcode.com/problems/diameter-of-binary-tree/' target='_blank'>LeetCode 543</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,2,3,4,5], Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Modify the standard Height of Binary Tree DFS. Compute left height and right height. At each node, the diameter passing through it is `left + right`. Track the max.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int diameterOfBinaryTree(TreeNode* root) {&#10;    int diameter = 0;&#10;    height(root, diameter);&#10;    return diameter;&#10;}&#10;int height(TreeNode* node, int&amp; diameter) {&#10;    if(!node) return 0;&#10;    int lh = height(node-&gt;left, diameter);&#10;    int rh = height(node-&gt;right, diameter);&#10;    diameter = max(diameter, lh + rh);&#10;    return 1 + max(lh, rh);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Tree 13 Maximum Path Sum<br><br></b> <a href='https://leetcode.com/problems/binary-tree-maximum-path-sum/' target='_blank'>LeetCode 124</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [-10,9,20,null,null,15,7], Output: 42</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>All Negative Nodes:</b> Initialization with `INT_MIN` properly returns the least negative node.</td>
      <td><b>Explanation:</b> DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxPathSum(TreeNode* root) {&#10;    int maxi = INT_MIN;&#10;    maxPathDown(root, maxi);&#10;    return maxi;&#10;}&#10;int maxPathDown(TreeNode* node, int&amp; maxi) {&#10;    if(!node) return 0;&#10;    int left = max(0, maxPathDown(node-&gt;left, maxi));&#10;    int right = max(0, maxPathDown(node-&gt;right, maxi));&#10;    maxi = max(maxi, left + right + node-&gt;val);&#10;    return max(left, right) + node-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Tree 14 Same Tree<br><br></b> <a href='https://leetcode.com/problems/same-tree/' target='_blank'>LeetCode 100</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: p = [1,2,3], q = [1,2,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Preorder DFS simultaneously on both trees. If both are null, true. If one is null or vals mismatch, false. Recursively check left and right subtrees.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p || !q) return p == q;&#10;    return (p-&gt;val == q-&gt;val) &amp;&amp; isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Tree 15 Boundary Traversal<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return array of boundary nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isLeaf(TreeNode* root) { return !root-&gt;left &amp;&amp; !root-&gt;right; }&#10;void addLeft(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;left;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) res.push_back(cur-&gt;val);&#10;        if(cur-&gt;left) cur = cur-&gt;left;&#10;        else cur = cur-&gt;right;&#10;    }&#10;}&#10;void addRight(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;right;&#10;    vector&lt;int&gt; tmp;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) tmp.push_back(cur-&gt;val);&#10;        if(cur-&gt;right) cur = cur-&gt;right;&#10;        else cur = cur-&gt;left;&#10;    }&#10;    for(int i = tmp.size()-1; i&gt;=0; --i) res.push_back(tmp[i]);&#10;}&#10;void addLeaves(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    if(isLeaf(root)) { res.push_back(root-&gt;val); return; }&#10;    if(root-&gt;left) addLeaves(root-&gt;left, res);&#10;    if(root-&gt;right) addLeaves(root-&gt;right, res);&#10;}&#10;vector&lt;int&gt; boundary(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    if(!isLeaf(root)) res.push_back(root-&gt;val);&#10;    addLeft(root, res); addLeaves(root, res); addRight(root, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Tree 16 Zigzag Traversal<br><br></b> <a href='https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/' target='_blank'>LeetCode 103</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: [[3],[20,9],[15,7]]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Standard BFS Level Order Traversal with a boolean flag `leftToRight`. After finishing a level, if the flag is false, reverse the level array before adding to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; zigzagLevelOrder(TreeNode* root) {&#10;    vector&lt;vector&lt;int&gt;&gt; result;&#10;    if(!root) return result;&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(root);&#10;    bool leftToRight = true;&#10;    while(!q.empty()) {&#10;        int size = q.size();&#10;        vector&lt;int&gt; row(size);&#10;        for(int i=0; i&lt;size; i++) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            int index = leftToRight ? i : (size - 1 - i);&#10;            row[index] = node-&gt;val;&#10;            if(node-&gt;left) q.push(node-&gt;left);&#10;            if(node-&gt;right) q.push(node-&gt;right);&#10;        }&#10;        leftToRight = !leftToRight;&#10;        result.push_back(row);&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Tree 17 Vertical Order Traversal<br><br></b> <a href='https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/' target='_blank'>LeetCode 987</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: [[9],[3,15],[20],[7]]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <map>\n#include <queue>\n#include <set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a map structure: `map<int, map<int, multiset<int>>>` to store nodes mapped by their horizontal distance and level. BFS traversal ensures levels are processed top-down.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; verticalTraversal(TreeNode* root) {&#10;    map&lt;int, map&lt;int, multiset&lt;int&gt;&gt;&gt; nodes;&#10;    queue&lt;pair&lt;TreeNode*, pair&lt;int, int&gt;&gt;&gt; todo;&#10;    todo.push({root, {0, 0}});&#10;    while(!todo.empty()) {&#10;        auto p = todo.front(); todo.pop();&#10;        TreeNode* node = p.first;&#10;        int x = p.second.first, y = p.second.second;&#10;        nodes[x][y].insert(node-&gt;val);&#10;        if(node-&gt;left) todo.push({node-&gt;left, {x - 1, y + 1}});&#10;        if(node-&gt;right) todo.push({node-&gt;right, {x + 1, y + 1}});&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(auto p : nodes) {&#10;        vector&lt;int&gt; col;&#10;        for(auto q : p.second) {&#10;            col.insert(col.end(), q.second.begin(), q.second.end());&#10;        }&#10;        ans.push_back(col);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Tree 18 Top View<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> BFS traversal maintaining horizontal distance (HD) from root. Use a map `hd -> value`. Only insert into the map if the HD is not already present, ensuring the top-most node is recorded.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        if(mpp.find(line) == mpp.end()) mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Tree 19 Bottom View<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> BFS traversal maintaining horizontal distance (HD). Map `hd -> value`. Always update the map value for a given HD so that the last node encountered (bottom-most) overrides previous ones.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bottomView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Tree 20 Right View<br><br></b> <a href='https://leetcode.com/problems/binary-tree-right-side-view/' target='_blank'>LeetCode 199</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: root = [1,2,3,null,5,null,4], Output: [1,3,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS Traversing right child before left child. Maintain the current level. If `level == result.size()`, append the node value to the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(TreeNode *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;val);&#10;    recursion(root-&gt;right, level + 1, res);&#10;    recursion(root-&gt;left, level + 1, res);&#10;}&#10;vector&lt;int&gt; rightSideView(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Tree 21 Left View<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Print left-most node at each level.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS Traversing left child before right child. Maintain the current level. If `level == result.size()`, append the node value to the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(Node *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;data);&#10;    recursion(root-&gt;left, level + 1, res);&#10;    recursion(root-&gt;right, level + 1, res);&#10;}&#10;vector&lt;int&gt; leftView(Node *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Tree 22 Construct Tree From Inorder And Preorder<br><br></b> <a href='https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/' target='_blank'>LeetCode 105</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Store inorder indices in a HashMap. The first element in preorder is the root. Find this root in inorder map to determine left subtree size. Recursively build left and right subtrees by slicing array indices.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, int preStart, int preEnd, vector&lt;int&gt;&amp; inorder, int inStart, int inEnd, map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(preorder[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);&#10;    root-&gt;right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);&#10;    return root;&#10;}&#10;TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    map&lt;int, int&gt; inMap;&#10;    for(int i = 0; i &lt; inorder.size(); i++) inMap[inorder[i]] = i;&#10;    TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Tree 23 Construct Tree From Inorder And Postorder<br><br></b> <a href='https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/' target='_blank'>LeetCode 106</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Store inorder indices in a HashMap. The last element in postorder is the root. Find this root in inorder map to determine left subtree size. Recursively build left and right subtrees by slicing array indices.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, int inStart, int inEnd, vector&lt;int&gt;&amp; postorder, int postStart, int postEnd, map&lt;int, int&gt;&amp; inMap) {&#10;    if(inStart &gt; inEnd || postStart &gt; postEnd) return NULL;&#10;    TreeNode* root = new TreeNode(postorder[postEnd]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);&#10;    root-&gt;right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);&#10;    return root;&#10;}&#10;TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, vector&lt;int&gt;&amp; postorder) {&#10;    map&lt;int, int&gt; inMap;&#10;    for(int i = 0; i &lt; inorder.size(); i++) inMap[inorder[i]] = i;&#10;    TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Tree 24 Serialize And Deserialize Binary Tree<br><br></b> <a href='https://leetcode.com/problems/serialize-and-deserialize-binary-tree/' target='_blank'>LeetCode 297</a></td>
      <td rowspan="1"><b>Example 1:</b> Serialization/Deserialization.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue>\n#include <sstream></code></td>
      <td><b>Empty Tree:</b> Serialized string is empty. Deserialize returns null.</td>
      <td><b>Explanation:</b> Use Level Order Traversal (BFS) using a queue. For serialization, append '#' for null nodes. For deserialization, split string by comma and use a queue to reconstruct the tree structure level by level.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Codec {&#10;public:&#10;    string serialize(TreeNode* root) {&#10;        if(!root) return &quot;&quot;;&#10;        string s = &quot;&quot;; queue&lt;TreeNode*&gt; q;&#10;        q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* curNode = q.front(); q.pop();&#10;            if(curNode==NULL) s.append(&quot;#,&quot;);&#10;            else { s.append(to_string(curNode-&gt;val) + &quot;,&quot;); q.push(curNode-&gt;left); q.push(curNode-&gt;right); }&#10;        }&#10;        return s;&#10;    }&#10;    TreeNode* deserialize(string data) {&#10;        if(data.empty()) return NULL;&#10;        stringstream s(data); string str;&#10;        getline(s, str, &#x27;,&#x27;);&#10;        TreeNode* root = new TreeNode(stoi(str));&#10;        queue&lt;TreeNode*&gt; q; q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;left = NULL;&#10;            else { TreeNode* leftNode = new TreeNode(stoi(str)); node-&gt;left = leftNode; q.push(leftNode); }&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;right = NULL;&#10;            else { TreeNode* rightNode = new TreeNode(stoi(str)); node-&gt;right = rightNode; q.push(rightNode); }&#10;        }&#10;        return root;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Tree 25 Lowest Common Ancestor<br><br></b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> Return the LCA node.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DFS traversal. If the current node is p or q, return the current node. Recurse left and right. If both left and right return non-null, the current node is the LCA. If one returns non-null, return that one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if(root == NULL || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if(left == NULL) return right;&#10;    else if(right == NULL) return left;&#10;    else return root;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
