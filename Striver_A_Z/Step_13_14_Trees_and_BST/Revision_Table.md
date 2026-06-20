# Step 13 14 Trees and BST Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 15%;">Complexity</th>
      <th style="width: 35%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Tree 01 Binary Tree Inorder Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-inorder-traversal/" target="_blank">LeetCode 94</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [1,null,2,3], Output: [1,3,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Recursive approach. Traverse Left, process Root, then traverse Right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(TreeNode* root, std::vector&lt;int&gt;&amp; ans) {&#10;    if (!root) return;&#10;    inorder(root-&gt;left, ans);&#10;    ans.push_back(root-&gt;val);&#10;    inorder(root-&gt;right, ans);&#10;}&#10;std::vector&lt;int&gt; inorderTraversal(TreeNode* root) {&#10;    std::vector&lt;int&gt; ans;&#10;    inorder(root, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Tree 02 Maximum Depth Of Binary Tree<br><br></b> <a href="https://leetcode.com/problems/maximum-depth-of-binary-tree/" target="_blank">LeetCode 104</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H) &cong; O(N)</td>
      <td><b>Explanation:</b> Recursively find the max depth of left and right subtrees. The depth is `1 + max(left_depth, right_depth)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(TreeNode* root) {&#10;    if (!root) return 0;&#10;    return 1 + std::max(maxDepth(root-&gt;left), maxDepth(root-&gt;right));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Tree 03 Lowest Common Ancestor Of A Binary Tree<br><br></b> <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/" target="_blank">LeetCode 236</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1, Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> If we find `p` or `q`, return it. If both left and right return non-null, current node is LCA.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if (!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if (!left) return right;&#10;    else if (!right) return left;&#10;    else return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Tree 04 Same Tree<br><br></b> <a href="https://leetcode.com/problems/same-tree/" target="_blank">LeetCode 100</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: p = [1,2,3], q = [1,2,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Traverse both trees simultaneously. If both nodes are null, true. If one is null or values mismatch, false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p &amp;&amp; !q) return true;&#10;    if(!p || !q || p-&gt;val != q-&gt;val) return false;&#10;    return isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Tree 05 Invert Binary Tree<br><br></b> <a href="https://leetcode.com/problems/invert-binary-tree/" target="_blank">LeetCode 226</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [4,2,7,1,3,6,9], Output: [4,7,2,9,6,3,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Recursively swap the left and right children of every node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* invertTree(TreeNode* root) {&#10;    if(!root) return nullptr;&#10;    std::swap(root-&gt;left, root-&gt;right);&#10;    invertTree(root-&gt;left);&#10;    invertTree(root-&gt;right);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Tree 06 Diameter Of Binary Tree<br><br></b> <a href="https://leetcode.com/problems/diameter-of-binary-tree/" target="_blank">LeetCode 543</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [1,2,3,4,5], Output: 3 (Path is [4,2,1,3] or [5,2,1,3])</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Modify the Height/Depth algorithm. Calculate `left_depth + right_depth` at every node to find max diameter, while returning standard height.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int height(TreeNode* node, int&amp; max_d) {&#10;    if(!node) return 0;&#10;    int left = height(node-&gt;left, max_d);&#10;    int right = height(node-&gt;right, max_d);&#10;    max_d = std::max(max_d, left + right);&#10;    return 1 + std::max(left, right);&#10;}&#10;int diameterOfBinaryTree(TreeNode* root) {&#10;    int max_d = 0;&#10;    height(root, max_d);&#10;    return max_d;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Tree 07 Balanced Binary Tree<br><br></b> <a href="https://leetcode.com/problems/balanced-binary-tree/" target="_blank">LeetCode 110</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Modify the Height algorithm. If the difference between `left` and `right` height is > 1, return `-1` to propagate the unbalanced signal.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int checkHeight(TreeNode* node) {&#10;    if(!node) return 0;&#10;    int left = checkHeight(node-&gt;left);&#10;    if(left == -1) return -1;&#10;    int right = checkHeight(node-&gt;right);&#10;    if(right == -1) return -1;&#10;    if(std::abs(left - right) &gt; 1) return -1;&#10;    return 1 + std::max(left, right);&#10;}&#10;bool isBalanced(TreeNode* root) {&#10;    return checkHeight(root) != -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Tree 08 Binary Search Tree Iterator<br><br></b> <a href="https://leetcode.com/problems/binary-search-tree-iterator/" target="_blank">LeetCode 173</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> next() returns smallest element.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Use a stack to simulate in-order traversal. Push all left children initially. On next(), pop, return val, and push all left children of popped node's right child.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BSTIterator {&#10;    stack&lt;TreeNode*&gt; st;&#10;    void pushAll(TreeNode* node) {&#10;        while(node) {&#10;            st.push(node);&#10;            node = node-&gt;left;&#10;        }&#10;    }&#10;public:&#10;    BSTIterator(TreeNode* root) {&#10;        pushAll(root);&#10;    }&#10;    int next() {&#10;        TreeNode* tmpNode = st.top();&#10;        st.pop();&#10;        pushAll(tmpNode-&gt;right);&#10;        return tmpNode-&gt;val;&#10;    }&#10;    bool hasNext() {&#10;        return !st.empty();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Tree 09 Validate Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/validate-binary-search-tree/" target="_blank">LeetCode 98</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [2,1,3], Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Recursive validation with min and max bounds for every node. Long long is used to avoid overflow.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValidBST(TreeNode* root, long minVal, long maxVal) {&#10;    if(!root) return true;&#10;    if(root-&gt;val &gt;= maxVal || root-&gt;val &lt;= minVal) return false;&#10;    return isValidBST(root-&gt;left, minVal, root-&gt;val) &amp;&amp; isValidBST(root-&gt;right, root-&gt;val, maxVal);&#10;}&#10;bool isValidBST(TreeNode* root) {&#10;    return isValidBST(root, LONG_MIN, LONG_MAX);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Tree 10 Construct Tree From Preorder And Inorder<br><br></b> <a href="https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/" target="_blank">LeetCode 105</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for Hash Map</td>
      <td><b>Explanation:</b> First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    unordered_map&lt;int, int&gt; inMap;&#10;    for(int i=0; i&lt;inorder.size(); i++) inMap[inorder[i]] = i;&#10;    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; pre, int preStart, int preEnd, vector&lt;int&gt;&amp; in, int inStart, int inEnd, unordered_map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(pre[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);&#10;    root-&gt;right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Tree 11 Maximum Path Sum<br><br></b> <a href="https://leetcode.com/problems/binary-tree-maximum-path-sum/" target="_blank">LeetCode 124</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [-10,9,20,null,null,15,7], Output: 42</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxPathSum(TreeNode* root) {&#10;    int maxi = INT_MIN;&#10;    maxPathDown(root, maxi);&#10;    return maxi;&#10;}&#10;int maxPathDown(TreeNode* node, int&amp; maxi) {&#10;    if(!node) return 0;&#10;    int left = max(0, maxPathDown(node-&gt;left, maxi));&#10;    int right = max(0, maxPathDown(node-&gt;right, maxi));&#10;    maxi = max(maxi, left + right + node-&gt;val);&#10;    return max(left, right) + node-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Tree 12 Boundary Traversal<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Return array of boundary nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> 1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isLeaf(TreeNode* root) { return !root-&gt;left &amp;&amp; !root-&gt;right; }&#10;void addLeft(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;left;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) res.push_back(cur-&gt;val);&#10;        if(cur-&gt;left) cur = cur-&gt;left;&#10;        else cur = cur-&gt;right;&#10;    }&#10;}&#10;void addRight(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;right;&#10;    vector&lt;int&gt; tmp;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) tmp.push_back(cur-&gt;val);&#10;        if(cur-&gt;right) cur = cur-&gt;right;&#10;        else cur = cur-&gt;left;&#10;    }&#10;    for(int i = tmp.size()-1; i&gt;=0; --i) res.push_back(tmp[i]);&#10;}&#10;void addLeaves(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    if(isLeaf(root)) { res.push_back(root-&gt;val); return; }&#10;    if(root-&gt;left) addLeaves(root-&gt;left, res);&#10;    if(root-&gt;right) addLeaves(root-&gt;right, res);&#10;}&#10;vector&lt;int&gt; boundary(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    if(!isLeaf(root)) res.push_back(root-&gt;val);&#10;    addLeft(root, res); addLeaves(root, res); addRight(root, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Tree 13 Zigzag Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/" target="_blank">LeetCode 103</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: root = [3,9,20,null,null,15,7], Output: [[3],[20,9],[15,7]]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Standard BFS Level Order Traversal with a boolean flag `leftToRight`. After finishing a level, if the flag is false, reverse the level array before adding to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; zigzagLevelOrder(TreeNode* root) {&#10;    vector&lt;vector&lt;int&gt;&gt; result;&#10;    if(!root) return result;&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(root);&#10;    bool leftToRight = true;&#10;    while(!q.empty()) {&#10;        int size = q.size();&#10;        vector&lt;int&gt; row(size);&#10;        for(int i=0; i&lt;size; i++) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            int index = leftToRight ? i : (size - 1 - i);&#10;            row[index] = node-&gt;val;&#10;            if(node-&gt;left) q.push(node-&gt;left);&#10;            if(node-&gt;right) q.push(node-&gt;right);&#10;        }&#10;        leftToRight = !leftToRight;&#10;        result.push_back(row);&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Tree 14 Vertical Order Traversal<br><br></b> <a href="https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/" target="_blank">LeetCode 987</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Output: [[9],[3,15],[20],[7]]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a map structure: `map<int, map<int, multiset<int>>>` to store nodes mapped by their horizontal distance and level. BFS traversal ensures levels are processed top-down.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; verticalTraversal(TreeNode* root) {&#10;    map&lt;int, map&lt;int, multiset&lt;int&gt;&gt;&gt; nodes;&#10;    queue&lt;pair&lt;TreeNode*, pair&lt;int, int&gt;&gt;&gt; todo;&#10;    todo.push({root, {0, 0}});&#10;    while(!todo.empty()) {&#10;        auto p = todo.front(); todo.pop();&#10;        TreeNode* node = p.first;&#10;        int x = p.second.first, y = p.second.second;&#10;        nodes[x][y].insert(node-&gt;val);&#10;        if(node-&gt;left) todo.push({node-&gt;left, {x - 1, y + 1}});&#10;        if(node-&gt;right) todo.push({node-&gt;right, {x + 1, y + 1}});&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(auto p : nodes) {&#10;        vector&lt;int&gt; col;&#10;        for(auto q : p.second) {&#10;            col.insert(col.end(), q.second.begin(), q.second.end());&#10;        }&#10;        ans.push_back(col);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Tree 15 Top View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> BFS traversal maintaining horizontal distance (HD) from root. Use a map `hd -> value`. Only insert into the map if the HD is not already present, ensuring the top-most node is recorded.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        if(mpp.find(line) == mpp.end()) mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Tree 16 Bottom View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> BFS traversal maintaining horizontal distance (HD). Map `hd -> value`. Always update the map value for a given HD so that the last node encountered (bottom-most) overrides previous ones.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bottomView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Tree 17 Right View<br><br></b> <a href="https://leetcode.com/problems/binary-tree-right-side-view/" target="_blank">LeetCode 199</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Input: root = [1,2,3,null,5,null,4], Output: [1,3,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> DFS Traversing right child before left child. Maintain the current level. If `level == result.size()`, append the node value to the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(TreeNode *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;val);&#10;    recursion(root-&gt;right, level + 1, res);&#10;    recursion(root-&gt;left, level + 1, res);&#10;}&#10;vector&lt;int&gt; rightSideView(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Tree 18 Left View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Print left-most node at each level.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> DFS Traversing left child before right child. Maintain the current level. If `level == result.size()`, append the node value to the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(Node *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;data);&#10;    recursion(root-&gt;left, level + 1, res);&#10;    recursion(root-&gt;right, level + 1, res);&#10;}&#10;vector&lt;int&gt; leftView(Node *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Tree 19 Construct Tree From Inorder And Postorder<br><br></b> <a href="https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/" target="_blank">LeetCode 106</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3], Output: [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Store inorder indices in a HashMap. The last element in postorder is the root. Find this root in inorder map to determine left subtree size. Recursively build left and right subtrees by slicing array indices.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, int inStart, int inEnd, vector&lt;int&gt;&amp; postorder, int postStart, int postEnd, map&lt;int, int&gt;&amp; inMap) {&#10;    if(inStart &gt; inEnd || postStart &gt; postEnd) return NULL;&#10;    TreeNode* root = new TreeNode(postorder[postEnd]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);&#10;    root-&gt;right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);&#10;    return root;&#10;}&#10;TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, vector&lt;int&gt;&amp; postorder) {&#10;    map&lt;int, int&gt; inMap;&#10;    for(int i = 0; i &lt; inorder.size(); i++) inMap[inorder[i]] = i;&#10;    TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Tree 20 Serialize And Deserialize Binary Tree<br><br></b> <a href="https://leetcode.com/problems/serialize-and-deserialize-binary-tree/" target="_blank">LeetCode 297</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Serialization/Deserialization.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use Level Order Traversal (BFS) using a queue. For serialization, append '#' for null nodes. For deserialization, split string by comma and use a queue to reconstruct the tree structure level by level.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Codec {&#10;public:&#10;    string serialize(TreeNode* root) {&#10;        if(!root) return &quot;&quot;;&#10;        string s = &quot;&quot;; queue&lt;TreeNode*&gt; q;&#10;        q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* curNode = q.front(); q.pop();&#10;            if(curNode==NULL) s.append(&quot;#,&quot;);&#10;            else { s.append(to_string(curNode-&gt;val) + &quot;,&quot;); q.push(curNode-&gt;left); q.push(curNode-&gt;right); }&#10;        }&#10;        return s;&#10;    }&#10;    TreeNode* deserialize(string data) {&#10;        if(data.empty()) return NULL;&#10;        stringstream s(data); string str;&#10;        getline(s, str, &#x27;,&#x27;);&#10;        TreeNode* root = new TreeNode(stoi(str));&#10;        queue&lt;TreeNode*&gt; q; q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;left = NULL;&#10;            else { TreeNode* leftNode = new TreeNode(stoi(str)); node-&gt;left = leftNode; q.push(leftNode); }&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;right = NULL;&#10;            else { TreeNode* rightNode = new TreeNode(stoi(str)); node-&gt;right = rightNode; q.push(rightNode); }&#10;        }&#10;        return root;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Tree 21 Flatten Binary Tree To Linked List<br><br></b> <a href="https://leetcode.com/problems/flatten-binary-tree-to-linked-list/" target="_blank">LeetCode 114</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> In-place flatten.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Morris Traversal. If node has a left child, find the rightmost node of the left subtree. Point its right to current node's right. Move current node's left to its right, and set left to null. Move to current's right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void flatten(TreeNode* root) {&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;left) {&#10;            TreeNode* pre = curr-&gt;left;&#10;            while(pre-&gt;right) pre = pre-&gt;right;&#10;            pre-&gt;right = curr-&gt;right;&#10;            curr-&gt;right = curr-&gt;left;&#10;            curr-&gt;left = NULL;&#10;        }&#10;        curr = curr-&gt;right;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Tree 22 Kth Smallest Element In A Bst<br><br></b> <a href="https://leetcode.com/problems/kth-smallest-element-in-a-bst/" target="_blank">LeetCode 230</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Inorder traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) using Morris Traversal</td>
      <td><b>Explanation:</b> Inorder traversal of BST gives sorted elements. Keep a counter, when it reaches K, store the result. Morris Traversal can do this in O(1) space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(TreeNode* root, int k) {&#10;    int count = 0, ans = -1;&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;left == NULL) {&#10;            count++;&#10;            if(count == k) ans = curr-&gt;val;&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            TreeNode* pre = curr-&gt;left;&#10;            while(pre-&gt;right &amp;&amp; pre-&gt;right != curr) pre = pre-&gt;right;&#10;            if(pre-&gt;right == NULL) {&#10;                pre-&gt;right = curr;&#10;                curr = curr-&gt;left;&#10;            } else {&#10;                pre-&gt;right = NULL;&#10;                count++;&#10;                if(count == k) ans = curr-&gt;val;&#10;                curr = curr-&gt;right;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Tree 23 Lowest Common Ancestor Of A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/" target="_blank">LeetCode 235</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Exploit BST property.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> If both `p` and `q` are less than root, LCA is in the left subtree. If both are greater, LCA is in the right subtree. Otherwise, the current node is the LCA.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    while(root) {&#10;        if(root-&gt;val &gt; p-&gt;val &amp;&amp; root-&gt;val &gt; q-&gt;val) root = root-&gt;left;&#10;        else if(root-&gt;val &lt; p-&gt;val &amp;&amp; root-&gt;val &lt; q-&gt;val) root = root-&gt;right;&#10;        else return root;&#10;    }&#10;    return NULL;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Tree 24 Insert Into A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/insert-into-a-binary-search-tree/" target="_blank">LeetCode 701</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Traverse and insert.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse left or right depending on the value. Keep track of parent. Insert as left or right child of parent when a null pointer is reached.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* insertIntoBST(TreeNode* root, int val) {&#10;    if(!root) return new TreeNode(val);&#10;    TreeNode* curr = root;&#10;    while(true) {&#10;        if(val &lt; curr-&gt;val) {&#10;            if(curr-&gt;left) curr = curr-&gt;left;&#10;            else { curr-&gt;left = new TreeNode(val); break; }&#10;        } else {&#10;            if(curr-&gt;right) curr = curr-&gt;right;&#10;            else { curr-&gt;right = new TreeNode(val); break; }&#10;        }&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Tree 25 Delete Node In A Bst<br><br></b> <a href="https://leetcode.com/problems/delete-node-in-a-bst/" target="_blank">LeetCode 450</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Locate and delete.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(H) or O(1)</td>
      <td><b>Explanation:</b> Find the node. If it has no left child, return right child. If no right, return left. If both exist, find the right child of the rightmost node in the left subtree, and point it to the node's right child. Return the node's left child.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* helper(TreeNode* root) {&#10;    if(!root-&gt;left) return root-&gt;right;&#10;    if(!root-&gt;right) return root-&gt;left;&#10;    TreeNode* rightChild = root-&gt;right;&#10;    TreeNode* lastRight = root-&gt;left;&#10;    while(lastRight-&gt;right) lastRight = lastRight-&gt;right;&#10;    lastRight-&gt;right = rightChild;&#10;    return root-&gt;left;&#10;}&#10;TreeNode* deleteNode(TreeNode* root, int key) {&#10;    if(!root) return NULL;&#10;    if(root-&gt;val == key) return helper(root);&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;val &gt; key) {&#10;            if(curr-&gt;left &amp;&amp; curr-&gt;left-&gt;val == key) {&#10;                curr-&gt;left = helper(curr-&gt;left);&#10;                break;&#10;            } else curr = curr-&gt;left;&#10;        } else {&#10;            if(curr-&gt;right &amp;&amp; curr-&gt;right-&gt;val == key) {&#10;                curr-&gt;right = helper(curr-&gt;right);&#10;                break;&#10;            } else curr = curr-&gt;right;&#10;        }&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Tree 26 Inorder Successor In Bst<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Find next greater.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse BST. If `curr.val > node.val`, then `curr` is a potential successor, store it and move left to find smaller. Else, move right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* inOrderSuccessor(TreeNode *root, TreeNode *x) {&#10;    TreeNode* successor = NULL;&#10;    while(root) {&#10;        if(root-&gt;val &lt;= x-&gt;val) {&#10;            root = root-&gt;right;&#10;        } else {&#10;            successor = root;&#10;            root = root-&gt;left;&#10;        }&#10;    }&#10;    return successor;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Tree 27 Two Sum Iv Input Is A Bst<br><br></b> <a href="https://leetcode.com/problems/two-sum-iv-input-is-a-bst/" target="_blank">LeetCode 653</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> BST Iterator two pointer.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Use two BST iterators: one for normal inorder (next) and one for reverse inorder (before). Apply two-pointer approach like in a sorted array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BSTIterator {&#10;    stack&lt;TreeNode*&gt; st;&#10;    bool reverse;&#10;    void pushAll(TreeNode* node) {&#10;        while(node) {&#10;            st.push(node);&#10;            if(reverse) node = node-&gt;right;&#10;            else node = node-&gt;left;&#10;        }&#10;    }&#10;public:&#10;    BSTIterator(TreeNode* root, bool isReverse) {&#10;        reverse = isReverse;&#10;        pushAll(root);&#10;    }&#10;    int next() {&#10;        TreeNode* tmpNode = st.top();&#10;        st.pop();&#10;        if(reverse) pushAll(tmpNode-&gt;left);&#10;        else pushAll(tmpNode-&gt;right);&#10;        return tmpNode-&gt;val;&#10;    }&#10;};&#10;bool findTarget(TreeNode* root, int k) {&#10;    if(!root) return false;&#10;    BSTIterator l(root, false);&#10;    BSTIterator r(root, true);&#10;    int i = l.next();&#10;    int j = r.next();&#10;    while(i &lt; j) {&#10;        if(i + j == k) return true;&#10;        else if(i + j &lt; k) i = l.next();&#10;        else j = r.next();&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Tree 28 Recover Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/recover-binary-search-tree/" target="_blank">LeetCode 99</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Inorder traversal tracking anomalies.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Inorder traversal of BST gives sorted array. If two are swapped, there will be 1 or 2 anomalies where `prev->val > curr->val`. First anomaly: `first = prev`, `middle = curr`. Second anomaly: `last = curr`. Swap `first` and `last` (or `first` and `middle` if adjacent).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode *first, *prev, *middle, *last;&#10;void inorder(TreeNode* root) {&#10;    if(root == NULL) return;&#10;    inorder(root-&gt;left);&#10;    if(prev != NULL &amp;&amp; (root-&gt;val &lt; prev-&gt;val)) {&#10;        if(first == NULL) {&#10;            first = prev;&#10;            middle = root;&#10;        } else {&#10;            last = root;&#10;        }&#10;    }&#10;    prev = root;&#10;    inorder(root-&gt;right);&#10;}&#10;void recoverTree(TreeNode* root) {&#10;    first = middle = last = NULL;&#10;    prev = new TreeNode(INT_MIN);&#10;    inorder(root);&#10;    if(first &amp;&amp; last) swap(first-&gt;val, last-&gt;val);&#10;    else if(first &amp;&amp; middle) swap(first-&gt;val, middle-&gt;val);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Tree 29 Largest Bst In Binary Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-bst/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Bottom-up verification.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Return `[minNode, maxNode, maxSize]` from each subtree. For current node, if `left.max < node.val < right.min`, it's a BST. Return `[min(node.val, left.min), max(node.val, right.max), left.size + right.size + 1]`. Else, it's not a BST, return `[-inf, inf, max(left.size, right.size)]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class NodeValue {&#10;public:&#10;    int maxNode, minNode, maxSize;&#10;    NodeValue(int minNode, int maxNode, int maxSize) {&#10;        this-&gt;maxNode = maxNode;&#10;        this-&gt;minNode = minNode;&#10;        this-&gt;maxSize = maxSize;&#10;    }&#10;};&#10;NodeValue largestBSTSubtreeHelper(Node* root) {&#10;    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);&#10;    auto left = largestBSTSubtreeHelper(root-&gt;left);&#10;    auto right = largestBSTSubtreeHelper(root-&gt;right);&#10;    if(left.maxNode &lt; root-&gt;data &amp;&amp; root-&gt;data &lt; right.minNode) {&#10;        return NodeValue(min(root-&gt;data, left.minNode), max(root-&gt;data, right.maxNode), left.maxSize + right.maxSize + 1);&#10;    }&#10;    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));&#10;}&#10;int largestBst(Node *root) {&#10;    return largestBSTSubtreeHelper(root).maxSize;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Tree 30 Maximum Sum Bst In Binary Tree<br><br></b> <a href="https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/" target="_blank">LeetCode 1373</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Similar to largest BST.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Bottom-up traversal. Return `[isBST, minNode, maxNode, sum]`. Update global max sum when valid BST is found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Info {&#10;    bool isBST;&#10;    int minNode, maxNode, sum;&#10;};&#10;int maxSum = 0;&#10;Info solve(TreeNode* root) {&#10;    if(!root) return {true, INT_MAX, INT_MIN, 0};&#10;    Info left = solve(root-&gt;left);&#10;    Info right = solve(root-&gt;right);&#10;    if(left.isBST &amp;&amp; right.isBST &amp;&amp; left.maxNode &lt; root-&gt;val &amp;&amp; root-&gt;val &lt; right.minNode) {&#10;        int currSum = left.sum + right.sum + root-&gt;val;&#10;        maxSum = max(maxSum, currSum);&#10;        return {true, min(root-&gt;val, left.minNode), max(root-&gt;val, right.maxNode), currSum};&#10;    }&#10;    return {false, INT_MIN, INT_MAX, max(left.sum, right.sum)};&#10;}&#10;int maxSumBST(TreeNode* root) {&#10;    maxSum = 0;&#10;    solve(root);&#10;    return maxSum &gt; 0 ? maxSum : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Tree 31 Kth Largest Element In A Bst<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Reverse inorder traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Kth largest is Kth element in reverse inorder traversal (Right, Root, Left). Maintain a counter `k`. When visiting a node, decrement `k`. If `k == 0`, current node is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ans = -1;&#10;void reverseInorder(Node* root, int&amp; k) {&#10;    if(!root || k == 0) return;&#10;    reverseInorder(root-&gt;right, k);&#10;    k--;&#10;    if(k == 0) {&#10;        ans = root-&gt;data;&#10;        return;&#10;    }&#10;    reverseInorder(root-&gt;left, k);&#10;}&#10;int kthLargest(Node *root, int K) {&#10;    ans = -1;&#10;    reverseInorder(root, K);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Tree 32 Predecessor And Successor In Bst<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Search down the tree.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> For Successor: search for key. If node->val <= key, go right. If node->val > key, update succ = node, go left. For Predecessor: If node->val >= key, go left. If node->val < key, update pred = node, go right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findPreSuc(Node* root, Node*&amp; pre, Node*&amp; suc, int key) {&#10;    Node* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;key &gt; key) {&#10;            suc = curr;&#10;            curr = curr-&gt;left;&#10;        } else {&#10;            curr = curr-&gt;right;&#10;        }&#10;    }&#10;    curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;key &lt; key) {&#10;            pre = curr;&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            curr = curr-&gt;left;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Tree 33 Construct Bst From Preorder Traversal<br><br></b> <a href="https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/" target="_blank">LeetCode 1008</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Upper bound tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Use an upper bound value. `build(preorder, index, bound)`: If index >= len or preorder[index] > bound, return NULL. Create root with preorder[index]. `root->left = build(..., root->val)`. `root->right = build(..., bound)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* bstFromPreorder(vector&lt;int&gt;&amp; preorder) {&#10;    int i = 0;&#10;    return build(preorder, i, INT_MAX);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; A, int&amp; i, int bound) {&#10;    if(i == A.size() || A[i] &gt; bound) return NULL;&#10;    TreeNode* root = new TreeNode(A[i++]);&#10;    root-&gt;left = build(A, i, root-&gt;val);&#10;    root-&gt;right = build(A, i, bound);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Tree 34 All Nodes Distance K In Binary Tree<br><br></b> <a href="https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/" target="_blank">LeetCode 863</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Convert to graph or use parent pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Perform BFS/DFS to map each node to its parent. Then, start a BFS from the target node, visiting left, right, and parent. Track visited nodes. After `k` levels in BFS, the current queue holds the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void markParents(TreeNode* root, unordered_map&lt;TreeNode*, TreeNode*&gt;&amp; parent_track) {&#10;    queue&lt;TreeNode*&gt; queue;&#10;    queue.push(root);&#10;    while(!queue.empty()) {&#10;        TreeNode* current = queue.front();&#10;        queue.pop();&#10;        if(current-&gt;left) {&#10;            parent_track[current-&gt;left] = current;&#10;            queue.push(current-&gt;left);&#10;        }&#10;        if(current-&gt;right) {&#10;            parent_track[current-&gt;right] = current;&#10;            queue.push(current-&gt;right);&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; distanceK(TreeNode* root, TreeNode* target, int k) {&#10;    unordered_map&lt;TreeNode*, TreeNode*&gt; parent_track;&#10;    markParents(root, parent_track);&#10;    unordered_map&lt;TreeNode*, bool&gt; visited;&#10;    queue&lt;TreeNode*&gt; queue;&#10;    queue.push(target);&#10;    visited[target] = true;&#10;    int curr_level = 0;&#10;    while(!queue.empty()) {&#10;        int size = queue.size();&#10;        if(curr_level++ == k) break;&#10;        for(int i=0; i&lt;size; i++) {&#10;            TreeNode* current = queue.front();&#10;            queue.pop();&#10;            if(current-&gt;left &amp;&amp; !visited[current-&gt;left]) {&#10;                queue.push(current-&gt;left);&#10;                visited[current-&gt;left] = true;&#10;            }&#10;            if(current-&gt;right &amp;&amp; !visited[current-&gt;right]) {&#10;                queue.push(current-&gt;right);&#10;                visited[current-&gt;right] = true;&#10;            }&#10;            if(parent_track[current] &amp;&amp; !visited[parent_track[current]]) {&#10;                queue.push(parent_track[current]);&#10;                visited[parent_track[current]] = true;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; result;&#10;    while(!queue.empty()) {&#10;        TreeNode* current = queue.front(); queue.pop();&#10;        result.push_back(current-&gt;val);&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Tree 35 Amount Of Time For Binary Tree To Be Infected<br><br></b> <a href="https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/" target="_blank">LeetCode 2385</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Parent pointers and BFS.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Same as 'Distance K' problem. Map parents. Find the start node. Perform BFS from start node. The time taken is the number of levels in BFS until all reachable nodes are visited.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* markParents(TreeNode* root, unordered_map&lt;TreeNode*, TreeNode*&gt;&amp; m, int start) {&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(root);&#10;    TreeNode* res;&#10;    while(!q.empty()) {&#10;        TreeNode* node = q.front(); q.pop();&#10;        if(node-&gt;val == start) res = node;&#10;        if(node-&gt;left) {&#10;            m[node-&gt;left] = node;&#10;            q.push(node-&gt;left);&#10;        }&#10;        if(node-&gt;right) {&#10;            m[node-&gt;right] = node;&#10;            q.push(node-&gt;right);&#10;        }&#10;    }&#10;    return res;&#10;}&#10;int amountOfTime(TreeNode* root, int start) {&#10;    unordered_map&lt;TreeNode*, TreeNode*&gt; m;&#10;    TreeNode* target = markParents(root, m, start);&#10;    unordered_map&lt;TreeNode*, int&gt; vis;&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(target);&#10;    vis[target] = 1;&#10;    int maxi = 0;&#10;    while(!q.empty()) {&#10;        int sz = q.size();&#10;        int fl = 0;&#10;        for(int i=0; i&lt;sz; i++) {&#10;            auto node = q.front(); q.pop();&#10;            if(node-&gt;left &amp;&amp; !vis[node-&gt;left]) {&#10;                fl = 1;&#10;                vis[node-&gt;left] = 1;&#10;                q.push(node-&gt;left);&#10;            }&#10;            if(node-&gt;right &amp;&amp; !vis[node-&gt;right]) {&#10;                fl = 1;&#10;                vis[node-&gt;right] = 1;&#10;                q.push(node-&gt;right);&#10;            }&#10;            if(m[node] &amp;&amp; !vis[m[node]]) {&#10;                fl = 1;&#10;                vis[m[node]] = 1;&#10;                q.push(m[node]);&#10;            }&#10;        }&#10;        if(fl) maxi++;&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Tree 36 Count Complete Tree Nodes<br><br></b> <a href="https://leetcode.com/problems/count-complete-tree-nodes/" target="_blank">LeetCode 222</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Recursive with Height check.</td>
      <td><b>Time:</b> O(log^2 N)<br><b>Space:</b> O(log N)</td>
      <td><b>Explanation:</b> Compute the left height (following left child) and right height (following right child) of the tree. If they are equal, the tree is a full binary tree, and the number of nodes is `2^h - 1`. If they are not equal, recursively count the nodes in the left and right subtrees and add 1 for the root.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getLeftHeight(TreeNode* node) {&#10;    int h = 0;&#10;    while(node) {&#10;        h++;&#10;        node = node-&gt;left;&#10;    }&#10;    return h;&#10;}&#10;int getRightHeight(TreeNode* node) {&#10;    int h = 0;&#10;    while(node) {&#10;        h++;&#10;        node = node-&gt;right;&#10;    }&#10;    return h;&#10;}&#10;int countNodes(TreeNode* root) {&#10;    if(!root) return 0;&#10;    int lh = getLeftHeight(root);&#10;    int rh = getRightHeight(root);&#10;    if(lh == rh) return (1 &lt;&lt; lh) - 1;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Tree 37 Morris Preorder Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-preorder-traversal/" target="_blank">LeetCode 144</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Threaded Binary Tree.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Similar to Morris Inorder. If left child is null, process current, move right. Else, find predecessor. If predecessor's right is null, process current, make thread, move left. If predecessor's right is current, remove thread, move right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; preorderTraversal(TreeNode* root) {&#10;    vector&lt;int&gt; preorder;&#10;    TreeNode* curr = root;&#10;    while(curr != NULL) {&#10;        if(curr-&gt;left == NULL) {&#10;            preorder.push_back(curr-&gt;val);&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            TreeNode* prev = curr-&gt;left;&#10;            while(prev-&gt;right &amp;&amp; prev-&gt;right != curr) {&#10;                prev = prev-&gt;right;&#10;            }&#10;            if(prev-&gt;right == NULL) {&#10;                prev-&gt;right = curr;&#10;                preorder.push_back(curr-&gt;val);&#10;                curr = curr-&gt;left;&#10;            } else {&#10;                prev-&gt;right = NULL;&#10;                curr = curr-&gt;right;&#10;            }&#10;        }&#10;    }&#10;    return preorder;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Tree 38 Search In A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/search-in-a-binary-search-tree/" target="_blank">LeetCode 700</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Iterative or Recursive.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Start at root. If root is null or its value is `val`, return root. If `val < root.val`, go left. Else go right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* searchBST(TreeNode* root, int val) {&#10;    while(root != NULL &amp;&amp; root-&gt;val != val) {&#10;        root = val &lt; root-&gt;val ? root-&gt;left : root-&gt;right;&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Tree 39 Find Minimum In Binary Search Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Leftmost node.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Traverse the left children until a node with no left child is reached. That node contains the minimum value.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minValue(TreeNode* root) {&#10;    if(root == NULL) return -1;&#10;    while(root-&gt;left != NULL) {&#10;        root = root-&gt;left;&#10;    }&#10;    return root-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Tree 40 Inorder Successor In Bst<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Iterative search.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Start from root. If `p.val >= root.val`, the successor must be in the right subtree (`root = root.right`). If `p.val < root.val`, the current root could be the successor, so record it and search the left subtree for a closer successor (`successor = root; root = root.left`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {&#10;    TreeNode* successor = NULL;&#10;    while(root != NULL) {&#10;        if(p-&gt;val &gt;= root-&gt;val) {&#10;            root = root-&gt;right;&#10;        } else {&#10;            successor = root;&#10;            root = root-&gt;left;&#10;        }&#10;    }&#10;    return successor;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Tree 41 Convert Binary Tree Into Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> DFS Inorder, maintaining a `prev` pointer.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Perform Inorder traversal. Maintain a `prev` pointer (initially null). At each node: if `prev == null`, this node is the head of DLL. Else, `prev->right = node` and `node->left = prev`. Update `prev = node`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bToDLLHelper(Node* root, Node*&amp; head, Node*&amp; prev) {&#10;    if(!root) return;&#10;    bToDLLHelper(root-&gt;left, head, prev);&#10;    if(prev == NULL) {&#10;        head = root;&#10;    } else {&#10;        root-&gt;left = prev;&#10;        prev-&gt;right = root;&#10;    }&#10;    prev = root;&#10;    bToDLLHelper(root-&gt;right, head, prev);&#10;}&#10;Node *bToDLL(Node *root) {&#10;    Node* head = NULL;&#10;    Node* prev = NULL;&#10;    bToDLLHelper(root, head, prev);&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Tree 42 Construct Tree From Inorder And Preorder<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/construct-tree-1/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Hash map for fast search.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> The first element in preorder is the root. Find this root in inorder using a hash map. Elements to the left in inorder form the left subtree, elements to the right form the right subtree. Recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* buildTreeUtil(int in[], int pre[], int inSt, int inEnd, int&amp; preIdx, unordered_map&lt;int, int&gt;&amp; mp) {&#10;    if(inSt &gt; inEnd) return NULL;&#10;    int curr = pre[preIdx++];&#10;    Node* tNode = new Node(curr);&#10;    if(inSt == inEnd) return tNode;&#10;    int inIdx = mp[curr];&#10;    tNode-&gt;left = buildTreeUtil(in, pre, inSt, inIdx - 1, preIdx, mp);&#10;    tNode-&gt;right = buildTreeUtil(in, pre, inIdx + 1, inEnd, preIdx, mp);&#10;    return tNode;&#10;}&#10;Node* buildTree(int in[], int pre[], int n) {&#10;    unordered_map&lt;int, int&gt; mp;&#10;    for(int i = 0; i &lt; n; i++) mp[in[i]] = i;&#10;    int preIdx = 0;&#10;    return buildTreeUtil(in, pre, 0, n - 1, preIdx, mp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Tree 43 Symmetric Tree<br><br></b> <a href="https://leetcode.com/problems/symmetric-tree/" target="_blank">LeetCode 101</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Recursive.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Use a helper function `isMirror(left, right)`. The tree is symmetric if `root->left` and `root->right` are mirrors. Two trees are mirrors if their roots are equal and `left1->left` is mirror of `right1->right`, and `left1->right` is mirror of `right1->left`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isMirror(TreeNode* n1, TreeNode* n2) {&#10;    if(!n1 &amp;&amp; !n2) return true;&#10;    if(!n1 || !n2) return false;&#10;    return (n1-&gt;val == n2-&gt;val) &amp;&amp; isMirror(n1-&gt;left, n2-&gt;right) &amp;&amp; isMirror(n1-&gt;right, n2-&gt;left);&#10;}&#10;bool isSymmetric(TreeNode* root) {&#10;    if(!root) return true;&#10;    return isMirror(root-&gt;left, root-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Tree 44 Root To Node Path In Binary Tree<br><br></b> <a href="https://www.interviewbit.com/problems/path-to-given-node/" target="_blank">InterviewBit</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Recursive backtracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> Use recursion. Push current node to the path array. If it's the target node, return true. Recursively search left and right subtrees. If either returns true, return true. If not found in either, pop the current node from the path array and return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool getPath(TreeNode* root, vector&lt;int&gt;&amp; arr, int x) {&#10;    if(!root) return false;&#10;    arr.push_back(root-&gt;val);&#10;    if(root-&gt;val == x) return true;&#10;    if(getPath(root-&gt;left, arr, x) || getPath(root-&gt;right, arr, x)) return true;&#10;    arr.pop_back();&#10;    return false;&#10;}&#10;vector&lt;int&gt; solve(TreeNode* A, int B) {&#10;    vector&lt;int&gt; arr;&#10;    if(!A) return arr;&#10;    getPath(A, arr, B);&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
