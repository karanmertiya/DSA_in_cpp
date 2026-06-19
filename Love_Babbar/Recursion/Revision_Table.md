# Recursion Revision Table

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
      <td>1</td>
      <td>Rec 01 Subsets<br><br></b> <a href='https://leetcode.com/problems/subsets/' target='_blank'>LeetCode 78</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]<br><br><b>Note (Constraint):</b> The solution set must not contain duplicate subsets.</td>
      <td><b>Time:</b> O(2<sup>N</sup>) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>-</td>
      <td><b>Recursion Tree Depth:</b> The maximum depth of the recursive stack is `N`, leading to `O(N)` auxiliary space.</td>
      <td><b>Explanation:</b> Pick / Non-Pick logic. For every element, we have two choices: either include it in the current subset, or don't. Recursively explore both paths.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void solve(int i, std::vector&lt;int&gt;&amp; nums, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == nums.size()) {&#10;        ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick&#10;    temp.push_back(nums[i]);&#10;    solve(i + 1, nums, temp, ans);&#10;    temp.pop_back();&#10;    &#10;    // Not Pick&#10;    solve(i + 1, nums, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; subsets(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, nums, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Rec 02 Combination Sum<br><br></b> <a href='https://leetcode.com/problems/combination-sum/' target='_blank'>LeetCode 39</a></td>
      <td><b>Example 1:</b> Input: candidates = [2,3,6,7], target = 7, Output: [[2,2,3],[7]]<br><br><b>Note (Constraint):</b> The same number may be chosen unlimited number of times.</td>
      <td><b>Time:</b> O(2<sup>T</sup>) (Trade-off)<br><b>Space:</b> O(T) (Trade-off)</td>
      <td>-</td>
      <td><b>Infinite Loop Prevention:</b> Base cases must immediately return if `target < 0` to prevent infinite recursion on the same index.</td>
      <td><b>Explanation:</b> Pick/Non-Pick but when picking, we *do not* increment the index `i`, allowing the same element to be picked infinitely until `target < 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void solve(int i, std::vector&lt;int&gt;&amp; arr, int target, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == arr.size()) {&#10;        if (target == 0) ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick (Stay on same index if valid)&#10;    if (arr[i] &lt;= target) {&#10;        temp.push_back(arr[i]);&#10;        solve(i, arr, target - arr[i], temp, ans);&#10;        temp.pop_back();&#10;    }&#10;    // Not Pick (Move to next)&#10;    solve(i + 1, arr, target, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; combinationSum(std::vector&lt;int&gt;&amp; candidates, int target) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, candidates, target, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Rec 03 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td><b>Example 1:</b> Input: n = 4, Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br><br><b>Note (Constraint):</b> 1 &le; n &le; 9</td>
      <td><b>Time:</b> O(N!) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>Hash Maps/Arrays for safety checks</td>
      <td><b>Diagonal Math:</b> Lower diagonal is tracked via `row + col`, Upper diagonal via `(n - 1) + (col - row)`.</td>
      <td><b>Explanation:</b> Backtracking. Try placing a queen in each row of the current column. Use `O(1)` lookups (Hashing logic) via arrays to check if row/diagonals are safe.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;string&gt;&#10;&#10;void solve(int col, int n, std::vector&lt;std::string&gt;&amp; board, std::vector&lt;std::vector&lt;std::string&gt;&gt;&amp; ans, std::vector&lt;int&gt;&amp; leftRow, std::vector&lt;int&gt;&amp; upperDiag, std::vector&lt;int&gt;&amp; lowerDiag) {&#10;    if (col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for (int row = 0; row &lt; n; row++) {&#10;        if (leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            &#10;            solve(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;            &#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;&#10;std::vector&lt;std::vector&lt;std::string&gt;&gt; solveNQueens(int n) {&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    std::vector&lt;std::string&gt; board(n, std::string(n, &#x27;.&#x27;));&#10;    std::vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Rec 02 Subsets<br><br></b> <a href='https://leetcode.com/problems/subsets/' target='_blank'>LeetCode 78</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]</td>
      <td><b>Time:</b> O(2<sup>N</sup> * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Reference Storage:</b> In Python, `temp[:]` must be used to append a copy of the subset, not the reference to the mutating list.</td>
      <td><b>Explanation:</b> Pick / Not Pick technique. For every element, branch recursively: one path includes the element, the other path excludes it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(temp);&#10;        return;&#10;    }&#10;    temp.push_back(nums[idx]);&#10;    solve(idx + 1, nums, temp, ans);&#10;    temp.pop_back();&#10;    solve(idx + 1, nums, temp, ans);&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; subsets(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, nums, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Rec 03 Permutations<br><br></b> <a href='https://leetcode.com/problems/permutations/' target='_blank'>LeetCode 46</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td><code>std::swap</code></td>
      <td><b>Backtracking necessity:</b> Without the second swap (backtrack), the array remains mutated for subsequent sibling recursion branches.</td>
      <td><b>Explanation:</b> Backtracking. Swap elements to generate permutations. For index `i`, swap it with every index from `i` to `n-1`, recurse, then backtrack (swap back).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; nums.size(); i++) {&#10;        std::swap(nums[idx], nums[i]);&#10;        solve(idx + 1, nums, ans);&#10;        std::swap(nums[idx], nums[i]);&#10;    }&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; permute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    solve(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Rec 06 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td><b>Example 1:</b> Classic N-Queens constraint satisfaction.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Place queen column by column. To optimize collision checking to O(1), use 3 arrays/hashmaps: `leftRow`, `upperDiagonal`, and `lowerDiagonal`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, vector&lt;string&gt;&amp; board, vector&lt;vector&lt;string&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiag, vector&lt;int&gt;&amp; lowerDiag, int n) {&#10;    if(col == n) { ans.push_back(board); return; }&#10;    for(int row=0; row&lt;n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1; lowerDiag[row + col] = 1; upperDiag[n - 1 + col - row] = 1;&#10;            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);&#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0; lowerDiag[row + col] = 0; upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; solveNQueens(int n) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; board(n, string(n, &#x27;.&#x27;));&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);&#10;    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Rec 07 Sudoku Solver<br><br></b> <a href='https://leetcode.com/problems/sudoku-solver/' target='_blank'>LeetCode 37</a></td>
      <td><b>Example 1:</b> Input: board with '.' for empty cells. Solve in-place.</td>
      <td><b>Time:</b> O(9^(n*n))<br><b>Space:</b> O(1) auxiliary</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Find first empty cell, try placing 1-9. Validate row, col, and 3x3 sub-grid. Recursively solve the rest. If it fails, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board)) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Rec 08 M Coloring Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return true if possible.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Try coloring each node with color 1 to m. For a color, check if any adjacent node has the same color. If safe, assign and recurse for next node. If recursion returns false, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int n, bool graph[101][101]) {&#10;    if(node == n) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, n, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, n, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int n) {&#10;    int color[n] = {0};&#10;    return solve(0, color, m, n, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Rec 09 Rat In A Maze<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Lexicographical order paths.</td>
      <td><b>Time:</b> O(4^(N*N))<br><b>Space:</b> O(N*N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Explore 4 directions (D, L, R, U) in lexicographical order to get sorted paths naturally. Mark cell as visited, recurse, then unmark (backtrack).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;m, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis, int di[], int dj[]) {&#10;    if(i == n-1 &amp;&amp; j == n-1) { ans.push_back(move); return; }&#10;    string dir = &quot;DLRU&quot;;&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; m[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis, di, dj);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Rec 10 Word Break<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td><b>Example 1:</b> Input: s = 'leetcode', wordDict = ['leet','code'], Output: true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Recursion with Memoization (or DP). For each index, try all possible word lengths. If a prefix exists in dict, recurse for the suffix. DP array `dp[i]` stores if `s[0...i-1]` is valid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Rec 11 Word Break Ii<br><br></b> <a href='https://leetcode.com/problems/word-break-ii/' target='_blank'>LeetCode 140</a></td>
      <td><b>Example 1:</b> Return list of sentences.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Generate all combinations. At each step, if a prefix is in dict, recursively call for the rest of the string and append the prefix to the result of the recursive call.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;string&gt; solve(string s, unordered_set&lt;string&gt;&amp; dict, unordered_map&lt;string, vector&lt;string&gt;&gt;&amp; memo) {&#10;    if(memo.count(s)) return memo[s];&#10;    if(s.empty()) return {&quot;&quot;};&#10;    vector&lt;string&gt; res;&#10;    for(int i=1; i&lt;=s.length(); i++) {&#10;        string word = s.substr(0, i);&#10;        if(dict.count(word)) {&#10;            vector&lt;string&gt; rem = solve(s.substr(i), dict, memo);&#10;            for(string str : rem) {&#10;                res.push_back(word + (str.empty() ? &quot;&quot; : &quot; &quot;) + str);&#10;            }&#10;        }&#10;    }&#10;    return memo[s] = res;&#10;}&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    unordered_map&lt;string, vector&lt;string&gt;&gt; memo;&#10;    return solve(s, dict, memo);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Rec 12 Palindrome Partitioning<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning/' target='_blank'>LeetCode 131</a></td>
      <td><b>Example 1:</b> Input: s = 'aab', Output: [['a','a','b'],['aa','b']]</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Try to partition the string at every index. If the prefix `s[start:i]` is a palindrome, add it to current path and recurse for the rest of the string `s[i:end]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(int index, string s, vector&lt;string&gt; &amp;path, vector&lt;vector&lt;string&gt;&gt; &amp;res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            solve(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    solve(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Rec 13 Expression Add Operators<br><br></b> <a href='https://leetcode.com/problems/expression-add-operators/' target='_blank'>LeetCode 282</a></td>
      <td><b>Example 1:</b> Return expressions.</td>
      <td><b>Time:</b> O(N * 4^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Keep track of the evaluated sum so far, and the previous operand (for multiplication precedence). For '*', `newSum = sum - prev + prev * curr`. Handle leading zeros.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string num, int target, vector&lt;string&gt;&amp; ans, string path, long long eval, long long multed) {&#10;    if(ind == num.size()) {&#10;        if(eval == target) ans.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; num.size(); i++) {&#10;        if(i != ind &amp;&amp; num[ind] == &#x27;0&#x27;) break;&#10;        string curStr = num.substr(ind, i - ind + 1);&#10;        long long curNum = stoll(curStr);&#10;        if(ind == 0) {&#10;            solve(i + 1, num, target, ans, path + curStr, curNum, curNum);&#10;        } else {&#10;            solve(i + 1, num, target, ans, path + &quot;+&quot; + curStr, eval + curNum, curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;-&quot; + curStr, eval - curNum, -curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;*&quot; + curStr, eval - multed + multed * curNum, multed * curNum);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; addOperators(string num, int target) {&#10;    vector&lt;string&gt; ans;&#10;    solve(0, num, target, ans, &quot;&quot;, 0, 0);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Rec 14 Subset Sums Ii<br><br></b> <a href='https://leetcode.com/problems/subsets-ii/' target='_blank'>LeetCode 90</a></td>
      <td><b>Example 1:</b> Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array first to bring duplicates together. In recursive call, loop from `ind` to `n`. If `i > ind` and `nums[i] == nums[i-1]`, `continue` to skip duplicate recursive branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i = ind; i &lt; nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i - 1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Rec 15 Combination Sum Ii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-ii/' target='_blank'>LeetCode 40</a></td>
      <td><b>Example 1:</b> Return unique combinations.</td>
      <td><b>Time:</b> O(2^N * k)<br><b>Space:</b> O(k * x)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Recursive function iterates from `ind` to `n`. Skip duplicates (`if i > ind and arr[i] == arr[i-1]`). If `arr[i] > target`, break. Else add to path, subtract from target, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i - 1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Rec 16 Combination Sum Iii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-iii/' target='_blank'>LeetCode 216</a></td>
      <td><b>Example 1:</b> Return combinations.</td>
      <td><b>Time:</b> O(2^9)<br><b>Space:</b> O(k)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Start from 1, go up to 9. Add the current number to the path and subtract from target. Stop when path size is `k` and `target` is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int start, int k, int n, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(k == 0 &amp;&amp; n == 0) { ans.push_back(ds); return; }&#10;    if(k == 0 || n &lt; 0) return;&#10;    for(int i = start; i &lt;= 9; i++) {&#10;        ds.push_back(i);&#10;        solve(i + 1, k - 1, n - i, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum3(int k, int n) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    solve(1, k, n, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Rec 17 Letter Combinations Of A Phone Number<br><br></b> <a href='https://leetcode.com/problems/letter-combinations-of-a-phone-number/' target='_blank'>LeetCode 17</a></td>
      <td><b>Example 1:</b> String combinations.</td>
      <td><b>Time:</b> O(4^N * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Create a mapping of digit to letters. Iterate through digits, for each digit loop through its mapped letters, append to current string, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string digits, string mapping[], string path, vector&lt;string&gt;&amp; ans) {&#10;    if(ind == digits.length()) {&#10;        ans.push_back(path);&#10;        return;&#10;    }&#10;    int number = digits[ind] - &#x27;0&#x27;;&#10;    string value = mapping[number];&#10;    for(int i = 0; i &lt; value.length(); i++) {&#10;        solve(ind + 1, digits, mapping, path + value[i], ans);&#10;    }&#10;}&#10;vector&lt;string&gt; letterCombinations(string digits) {&#10;    if(digits.length() == 0) return {};&#10;    vector&lt;string&gt; ans;&#10;    string mapping[10] = {&quot;&quot;, &quot;&quot;, &quot;abc&quot;, &quot;def&quot;, &quot;ghi&quot;, &quot;jkl&quot;, &quot;mno&quot;, &quot;pqrs&quot;, &quot;tuv&quot;, &quot;wxyz&quot;};&#10;    solve(0, digits, mapping, &quot;&quot;, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Rec 18 Rat In A Maze<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(4^(N^2))<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use backtracking to explore paths in lexicographical order: Down, Left, Right, Up (DLRU). Maintain a visited array. If destination is reached, add path to answers. Backtrack by unmarking visited.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;a, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis) {&#10;    if(i == n-1 &amp;&amp; j == n-1) {&#10;        ans.push_back(move);&#10;        return;&#10;    }&#10;    string dir = &quot;DLRU&quot;;&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; a[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, a, n, ans, move + dir[ind], vis);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Rec 19 Word Break Ii<br><br></b> <a href='https://leetcode.com/problems/word-break-ii/' target='_blank'>LeetCode 140</a></td>
      <td><b>Example 1:</b> Recursion + Memoization.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(2^N * N)</td>
      <td><code>#include <unordered_set>\n#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. For each index, try all possible prefixes. If prefix is in dict, recursively break the remaining string. Use memoization or DP to store answers for a substring to avoid recomputation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">unordered_map&lt;string, vector&lt;string&gt;&gt; dp;&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    return helper(s, dict);&#10;}&#10;vector&lt;string&gt; helper(string s, unordered_set&lt;string&gt;&amp; dict) {&#10;    if(dp.find(s) != dp.end()) return dp[s];&#10;    vector&lt;string&gt; res;&#10;    if(dict.find(s) != dict.end()) res.push_back(s);&#10;    for(int i=1; i&lt;s.length(); i++) {&#10;        string right = s.substr(i);&#10;        if(dict.find(right) != dict.end()) {&#10;            vector&lt;string&gt; left_res = helper(s.substr(0, i), dict);&#10;            for(string l : left_res) res.push_back(l + &quot; &quot; + right);&#10;        }&#10;    }&#10;    return dp[s] = res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Rec 20 M Coloring Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Graph coloring backtracking.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Try coloring each node from `1` to `M`. Before coloring, check if it's safe (no adjacent node has same color). If safe, color it and recurse for next node. Backtrack if no color works.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int N, bool graph[101][101]) {&#10;    if(node == N) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, N, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, N, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int N) {&#10;    int color[N] = {0};&#10;    return solve(0, color, m, N, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Rec 21 Sudoku Solver<br><br></b> <a href='https://leetcode.com/problems/sudoku-solver/' target='_blank'>LeetCode 37</a></td>
      <td><b>Example 1:</b> Classic backtracking.</td>
      <td><b>Time:</b> O(9^(N^2))<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through matrix. If empty, try '1' to '9'. Check `isValid` (row, col, 3x3 box). If valid, set it and recurse. If recursion returns true, puzzle solved. Else backtrack. If loop ends without returning true, return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board) == true) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Rec 22 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td><b>Example 1:</b> Backtracking on board.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Place queens column by column. Keep track of safe rows and diagonals using hashing arrays: `leftRow`, `lowerDiagonal`, `upperDiagonal`. If safe, place queen, update hashes, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, vector&lt;string&gt;&amp; board, vector&lt;vector&lt;string&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiagonal, vector&lt;int&gt;&amp; lowerDiagonal, int n) {&#10;    if(col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for(int row=0; row&lt;n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiagonal[row + col] == 0 &amp;&amp; upperDiagonal[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiagonal[row + col] = 1;&#10;            upperDiagonal[n - 1 + col - row] = 1;&#10;            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);&#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiagonal[row + col] = 0;&#10;            upperDiagonal[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; solveNQueens(int n) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; board(n);&#10;    string s(n, &#x27;.&#x27;);&#10;    for(int i=0; i&lt;n; i++) board[i] = s;&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);&#10;    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Rec 23 Permutations Of A String Or Array<br><br></b> <a href='https://leetcode.com/problems/permutations/' target='_blank'>LeetCode 46</a></td>
      <td><b>Example 1:</b> Backtracking swap.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate `i` from `index` to `n-1`. Swap `nums[index]` and `nums[i]`, then recurse for `index + 1`. Swap back to backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recurPermute(int index, vector&lt;int&gt;&amp; nums, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(index == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; nums.size(); i++) {&#10;        swap(nums[index], nums[i]);&#10;        recurPermute(index + 1, nums, ans);&#10;        swap(nums[index], nums[i]);&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; permute(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    recurPermute(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Rec 24 Combination Sum Ii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-ii/' target='_blank'>LeetCode 40</a></td>
      <td><b>Example 1:</b> `candidates = [10,1,2,7,6,1,5], target = 8`.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N * X) where X is number of combinations</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort candidates. Recursively pick combinations. If `i > ind` and `candidates[i] == candidates[i-1]`, skip to avoid duplicates. If `target - candidates[i] >= 0`, pick it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i=ind; i&lt;arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i-1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Rec 25 Subset Sum I<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/subset-sums2234/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Take / Not Take.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recursively either include `arr[ind]` in sum, or exclude it. If `ind == N`, add `sum` to result array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void func(int ind, int sum, vector&lt;int&gt;&amp; arr, int N, vector&lt;int&gt;&amp; sumSubset) {&#10;    if(ind == N) {&#10;        sumSubset.push_back(sum);&#10;        return;&#10;    }&#10;    func(ind + 1, sum + arr[ind], arr, N, sumSubset);&#10;    func(ind + 1, sum, arr, N, sumSubset);&#10;}&#10;vector&lt;int&gt; subsetSums(vector&lt;int&gt; arr, int N) {&#10;    vector&lt;int&gt; sumSubset;&#10;    func(0, 0, arr, N, sumSubset);&#10;    sort(sumSubset.begin(), sumSubset.end());&#10;    return sumSubset;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Rec 26 Subset Sum Ii<br><br></b> <a href='https://leetcode.com/problems/subsets-ii/' target='_blank'>LeetCode 90</a></td>
      <td><b>Example 1:</b> Subset skip duplicates.</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * K)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Recursive call adds current `ds` to `ans`. Then iterate `i` from `ind` to `n`. Skip if `i > ind` and `nums[i] == nums[i-1]`. Add to `ds`, recurse for `i+1`, pop from `ds`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i=ind; i&lt;nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Rec 27 Palindrome Partitioning<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning/' target='_blank'>LeetCode 131</a></td>
      <td><b>Example 1:</b> Valid palindrome checks on prefix.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * X)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recurse through string. For index `i`, check substring `s[index...i]`. If it is palindrome, add it to current list, and recurse for `i+1`. Backtrack after recursion.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void func(int index, string s, vector&lt;string&gt;&amp; path, vector&lt;vector&lt;string&gt;&gt;&amp; res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i=index; i&lt;s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            func(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    func(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Recursion 27 N Queens Ii<br><br></b> <a href='https://leetcode.com/problems/n-queens-ii/' target='_blank'>LeetCode 52</a></td>
      <td><b>Example 1:</b> Backtracking with hashing.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use backtracking to place queens column by column. Use three hash arrays (or bitmasks) to track attacked rows, upper diagonals, and lower diagonals. If placing a queen is safe, update hashes, recurse for next column, and then backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, int n, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiag, vector&lt;int&gt;&amp; lowerDiag, int&amp; count) {&#10;    if(col == n) {&#10;        count++;&#10;        return;&#10;    }&#10;    for(int row = 0; row &lt; n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;int totalNQueens(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, leftRow, upperDiag, lowerDiag, count);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Recursion 28 Sudoku Solver<br><br></b> <a href='https://leetcode.com/problems/sudoku-solver/' target='_blank'>LeetCode 37</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(9^(n*n))<br><b>Space:</b> O(1) excluding recursion stack</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through each cell. If it's empty, try placing digits '1' to '9'. For each digit, check if it's valid in its row, column, and 3x3 subgrid. If valid, place it and recursively try to solve the rest. If a path leads to a solution, return true. Otherwise, backtrack (remove digit).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i = 0; i &lt; 9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i = 0; i &lt; board.size(); i++) {&#10;        for(int j = 0; j &lt; board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c = &#x27;1&#x27;; c &lt;= &#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board)) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Recursion 29 Word Search<br><br></b> <a href='https://leetcode.com/problems/word-search/' target='_blank'>LeetCode 79</a></td>
      <td><b>Example 1:</b> Backtracking DFS.</td>
      <td><b>Time:</b> O(N * M * 4^L)<br><b>Space:</b> O(L) recursion stack</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start DFS from each cell that matches the first letter of the word. In DFS, check 4 neighbors. Mark current cell as visited (e.g. change to '#') before moving to neighbors, and unmark (backtrack) after exploring.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(vector&lt;vector&lt;char&gt;&gt;&amp; board, int i, int j, string&amp; word, int idx) {&#10;    if(idx == word.length()) return true;&#10;    if(i &lt; 0 || i &gt;= board.size() || j &lt; 0 || j &gt;= board[0].size() || board[i][j] != word[idx]) return false;&#10;    char temp = board[i][j];&#10;    board[i][j] = &#x27;#&#x27;;&#10;    bool found = dfs(board, i+1, j, word, idx+1) ||&#10;                 dfs(board, i-1, j, word, idx+1) ||&#10;                 dfs(board, i, j+1, word, idx+1) ||&#10;                 dfs(board, i, j-1, word, idx+1);&#10;    board[i][j] = temp;&#10;    return found;&#10;}&#10;bool exist(vector&lt;vector&lt;char&gt;&gt;&amp; board, string word) {&#10;    for(int i = 0; i &lt; board.size(); i++) {&#10;        for(int j = 0; j &lt; board[0].size(); j++) {&#10;            if(board[i][j] == word[0] &amp;&amp; dfs(board, i, j, word, 0)) return true;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Recursion 30 Palindrome Partitioning<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning/' target='_blank'>LeetCode 131</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string. If a prefix is a palindrome, add it to the current partition list, and recursively partition the remaining substring. When we reach the end of the string, add the current partition to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string&amp; s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(int ind, string&amp; s, vector&lt;string&gt;&amp; path, vector&lt;vector&lt;string&gt;&gt;&amp; res) {&#10;    if(ind == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; s.size(); ++i) {&#10;        if(isPalindrome(s, ind, i)) {&#10;            path.push_back(s.substr(ind, i - ind + 1));&#10;            solve(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    solve(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Recursion 31 Rat In A Maze Problem I<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking DFS.</td>
      <td><b>Time:</b> O(4^(N*N))<br><b>Space:</b> O(N*N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start DFS from (0,0). Try D, L, R, U sequentially. If valid and not visited, mark visited, append direction to path, recurse, then unmark (backtrack) and pop direction. If reached (N-1, N-1), add path to results.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;m, int n, vector&lt;string&gt;&amp; ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis) {&#10;    if(i == n-1 &amp;&amp; j == n-1) {&#10;        ans.push_back(move);&#10;        return;&#10;    }&#10;    string dir = &quot;DLRU&quot;;&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    for(int ind=0; ind&lt;4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; m[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, m, n, ans, move + dir[ind], vis);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Recursion 32 Word Break Ii<br><br></b> <a href='https://leetcode.com/problems/word-break-ii/' target='_blank'>LeetCode 140</a></td>
      <td><b>Example 1:</b> Backtracking with Memoization (optional, but good for optimization).</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * 2^N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through all possible prefixes. If a prefix exists in the wordDict, recursively solve for the remaining suffix. Backtrack by appending the current prefix to the results of the suffix.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string s, unordered_set&lt;string&gt;&amp; dict, string path, vector&lt;string&gt;&amp; res) {&#10;    if(ind == s.length()) {&#10;        path.pop_back();&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    string temp = &quot;&quot;;&#10;    for(int i = ind; i &lt; s.length(); i++) {&#10;        temp += s[i];&#10;        if(dict.find(temp) != dict.end()) {&#10;            solve(i + 1, s, dict, path + temp + &quot; &quot;, res);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    vector&lt;string&gt; res;&#10;    solve(0, s, dict, &quot;&quot;, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Recursion 33 M Coloring Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Try coloring nodes one by one. For each node, try all M colors. Check if it's safe (no adjacent node has the same color). If safe, color it and recurse to the next node. If recursion returns true, we are done. Else backtrack and try next color.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k = 0; k &lt; n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int N, bool graph[101][101]) {&#10;    if(node == N) return true;&#10;    for(int i = 1; i &lt;= m; i++) {&#10;        if(isSafe(node, color, graph, N, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, N, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int n) {&#10;    int color[101] = {0};&#10;    if(solve(0, color, m, n, graph)) return true;&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Recursion 34 Expression Add Operators<br><br></b> <a href='https://leetcode.com/problems/expression-add-operators/' target='_blank'>LeetCode 282</a></td>
      <td><b>Example 1:</b> Backtracking with value and previous operand tracking.</td>
      <td><b>Time:</b> O(4^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string, extracting substrings as numbers. Prevent numbers with leading zeros. Recursively try `+`, `-`, `*`. For `*`, we must subtract the previous added value, and add `prev * current_val` to maintain precedence.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int idx, string num, int target, string path, long prevNum, long currVal, vector&lt;string&gt;&amp; res) {&#10;    if(idx == num.length()) {&#10;        if(currVal == target) res.push_back(path);&#10;        return;&#10;    }&#10;    string s = &quot;&quot;;&#10;    long n = 0;&#10;    for(int i = idx; i &lt; num.length(); i++) {&#10;        if(i &gt; idx &amp;&amp; num[idx] == &#x27;0&#x27;) break;&#10;        s += num[i];&#10;        n = n * 10 + (num[i] - &#x27;0&#x27;);&#10;        if(idx == 0) {&#10;            solve(i + 1, num, target, s, n, n, res);&#10;        } else {&#10;            solve(i + 1, num, target, path + &quot;+&quot; + s, n, currVal + n, res);&#10;            solve(i + 1, num, target, path + &quot;-&quot; + s, -n, currVal - n, res);&#10;            solve(i + 1, num, target, path + &quot;*&quot; + s, prevNum * n, currVal - prevNum + prevNum * n, res);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; addOperators(string num, int target) {&#10;    vector&lt;string&gt; res;&#10;    solve(0, num, target, &quot;&quot;, 0, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Recursion 35 K Th Symbol In Grammar<br><br></b> <a href='https://leetcode.com/problems/k-th-symbol-in-grammar/' target='_blank'>LeetCode 779</a></td>
      <td><b>Example 1:</b> Recursive division.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Row N has length 2^(N-1). The first half of row N is exactly same as row N-1. The second half of row N is the complement of row N-1. If k is in the first half (k <= mid), return solve(N-1, k). If k is in the second half, return !solve(N-1, k - mid).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthGrammar(int n, int k) {&#10;    if(n == 1 &amp;&amp; k == 1) return 0;&#10;    int mid = pow(2, n - 2);&#10;    if(k &lt;= mid) {&#10;        return kthGrammar(n - 1, k);&#10;    } else {&#10;        return !kthGrammar(n - 1, k - mid);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Recursion 36 Beautiful Arrangement<br><br></b> <a href='https://leetcode.com/problems/beautiful-arrangement/' target='_blank'>LeetCode 526</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(K) where K is number of valid permutations<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use an array to track visited numbers. Iterate from index 1 to n. For the current index, try placing an unvisited number. Check if the condition `(num % idx == 0 || idx % num == 0)` is met. If so, mark as visited, recurse to `idx + 1`, then backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countArrangement(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; visited(n + 1, 0);&#10;    function&lt;void(int)&gt; solve = [&amp;](int idx) {&#10;        if(idx &gt; n) {&#10;            count++;&#10;            return;&#10;        }&#10;        for(int i = 1; i &lt;= n; i++) {&#10;            if(!visited[i] &amp;&amp; (i % idx == 0 || idx % i == 0)) {&#10;                visited[i] = 1;&#10;                solve(idx + 1);&#10;                visited[i] = 0;&#10;            }&#10;        }&#10;    };&#10;    solve(1);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Rec 38 Print All Permutations Of A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Convert string to char array and sort it. Use backtracking: pass a boolean visited array and a temporary string. If temporary string length equals original length, add to answer. Else, iterate through characters. To avoid duplicates, if `i > 0` and `s[i] == s[i-1]` and `!vis[i-1]`, skip. Otherwise, mark visited, append, recurse, unmark, pop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string&amp; S, vector&lt;bool&gt;&amp; vis, string&amp; curr, vector&lt;string&gt;&amp; ans) {&#10;    if(curr.length() == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(vis[i] || (i &gt; 0 &amp;&amp; S[i] == S[i-1] &amp;&amp; !vis[i-1])) continue;&#10;        vis[i] = true;&#10;        curr.push_back(S[i]);&#10;        solve(S, vis, curr, ans);&#10;        curr.pop_back();&#10;        vis[i] = false;&#10;    }&#10;}&#10;vector&lt;string&gt; find_permutation(string S) {&#10;    sort(S.begin(), S.end());&#10;    vector&lt;string&gt; ans;&#10;    string curr = &quot;&quot;;&#10;    vector&lt;bool&gt; vis(S.length(), false);&#10;    solve(S, vis, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Rec 39 Word Break Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/word-break1352/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive with Memoization.</td>
      <td><b>Time:</b> O(N^2 * L)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a helper function `solve(index)` that returns true if substring `s[index...]` can be segmented. Try all possible prefixes from `index`. If `s[index...i]` is in dict, recursively call `solve(i+1)`. Use memoization.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solve(int ind, string&amp; A, unordered_set&lt;string&gt;&amp; dict, vector&lt;int&gt;&amp; memo) {&#10;    if(ind == A.length()) return 1;&#10;    if(memo[ind] != -1) return memo[ind];&#10;    for(int i = ind; i &lt; A.length(); i++) {&#10;        string prefix = A.substr(ind, i - ind + 1);&#10;        if(dict.find(prefix) != dict.end()) {&#10;            if(solve(i + 1, A, dict, memo)) return memo[ind] = 1;&#10;        }&#10;    }&#10;    return memo[ind] = 0;&#10;}&#10;int wordBreak(string A, vector&lt;string&gt; &amp;B) {&#10;    unordered_set&lt;string&gt; dict(B.begin(), B.end());&#10;    vector&lt;int&gt; memo(A.length(), -1);&#10;    return solve(0, A, dict, memo);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Rec 40 Remove Invalid Parentheses<br><br></b> <a href='https://leetcode.com/problems/remove-invalid-parentheses/' target='_blank'>LeetCode 301</a></td>
      <td><b>Example 1:</b> Recursion and Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> First find the number of misplaced left (`rm_l`) and right (`rm_r`) parentheses. Then use backtracking to try removing `rm_l` and `rm_r` parentheses. To avoid duplicates, skip identical adjacent characters. Finally, check if the resulting string is valid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(string&amp; s) {&#10;    int count = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) count++;&#10;        else if(c == &#x27;)&#x27;) count--;&#10;        if(count &lt; 0) return false;&#10;    }&#10;    return count == 0;&#10;}&#10;void solve(string s, int start, int rm_l, int rm_r, vector&lt;string&gt;&amp; ans) {&#10;    if(rm_l == 0 &amp;&amp; rm_r == 0) {&#10;        if(isValid(s)) ans.push_back(s);&#10;        return;&#10;    }&#10;    for(int i = start; i &lt; s.length(); i++) {&#10;        if(i != start &amp;&amp; s[i] == s[i-1]) continue;&#10;        if(s[i] == &#x27;(&#x27; &amp;&amp; rm_l &gt; 0) {&#10;            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l - 1, rm_r, ans);&#10;        }&#10;        else if(s[i] == &#x27;)&#x27; &amp;&amp; rm_r &gt; 0) {&#10;            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l, rm_r - 1, ans);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; removeInvalidParentheses(string s) {&#10;    int rm_l = 0, rm_r = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) rm_l++;&#10;        else if(c == &#x27;)&#x27;) {&#10;            if(rm_l &gt; 0) rm_l--;&#10;            else rm_r++;&#10;        }&#10;    }&#10;    vector&lt;string&gt; ans;&#10;    solve(s, 0, rm_l, rm_r, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Rec 41 Matchsticks To Square<br><br></b> <a href='https://leetcode.com/problems/matchsticks-to-square/' target='_blank'>LeetCode 473</a></td>
      <td><b>Example 1:</b> Backtracking to 4 subsets.</td>
      <td><b>Time:</b> O(4^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Calculate sum. If sum % 4 != 0, return false. Target side length is sum / 4. Sort matchsticks in descending order to optimize. Create an array `sides` of size 4. For each matchstick, try adding it to one of the 4 sides. If a side equals the target or is less, recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool solve(vector&lt;int&gt;&amp; arr, vector&lt;int&gt;&amp; sides, int target, int ind) {&#10;    if(ind == arr.size()) {&#10;        return sides[0] == target &amp;&amp; sides[1] == target &amp;&amp; sides[2] == target;&#10;    }&#10;    for(int i = 0; i &lt; 4; i++) {&#10;        if(sides[i] + arr[ind] &lt;= target) {&#10;            sides[i] += arr[ind];&#10;            if(solve(arr, sides, target, ind + 1)) return true;&#10;            sides[i] -= arr[ind];&#10;        }&#10;        if(sides[i] == 0) break;&#10;    }&#10;    return false;&#10;}&#10;bool makesquare(vector&lt;int&gt;&amp; matchsticks) {&#10;    long long sum = 0;&#10;    for(int m : matchsticks) sum += m;&#10;    if(sum % 4 != 0 || matchsticks.size() &lt; 4) return false;&#10;    sort(matchsticks.rbegin(), matchsticks.rend());&#10;    vector&lt;int&gt; sides(4, 0);&#10;    return solve(matchsticks, sides, sum / 4, 0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Rec 42 Tug Of War<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/tug-of-war/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Keep track of the number of elements included in subset 1 and their sum. Recurse by including the current element in subset 1 or subset 2. Base case: if we reach end, check if subset 1 has `n/2` elements. If so, compute difference and update global minimum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDiff;&#10;void solve(vector&lt;int&gt;&amp; arr, int ind, int cnt, int sum1, int totalSum, int n) {&#10;    if(ind == n) {&#10;        if(cnt == n / 2) {&#10;            int sum2 = totalSum - sum1;&#10;            minDiff = min(minDiff, abs(sum1 - sum2));&#10;        }&#10;        return;&#10;    }&#10;    if(cnt &lt; n / 2) solve(arr, ind + 1, cnt + 1, sum1 + arr[ind], totalSum, n);&#10;    solve(arr, ind + 1, cnt, sum1, totalSum, n);&#10;}&#10;int tugOfWar(vector&lt;int&gt;&amp; arr) {&#10;    int totalSum = 0;&#10;    for(int x : arr) totalSum += x;&#10;    minDiff = INT_MAX;&#10;    solve(arr, 0, 0, 0, totalSum, arr.size());&#10;    return minDiff;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Rec 43 Find Paths From Corner Cell To Middle Cell<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/paths-from-corner-to-middle/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> BFS / DFS for path finding.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Perform BFS or DFS starting from all 4 corners simultaneously or individually. At each cell `(r, c)`, the jump size is `val = grid[r][c]`. We can move to `(r+val, c)`, `(r-val, c)`, `(r, c+val)`, `(r, c-val)`. Target is `(N/2, N/2)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    vector&lt;vector&lt;bool&gt;&gt; vis(n, vector&lt;bool&gt;(n, false));&#10;    auto add = [&amp;](int r, int c) { q.push({r, c}); vis[r][c] = true; };&#10;    add(0, 0); add(0, n-1); add(n-1, 0); add(n-1, n-1);&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    while(!q.empty()) {&#10;        auto [r, c] = q.front(); q.pop();&#10;        if(r == n/2 &amp;&amp; c == n/2) { /* found path */ }&#10;        int val = grid[r][c];&#10;        for(int i=0; i&lt;4; i++) {&#10;            int nr = r + dr[i] * val, nc = c + dc[i] * val;&#10;            if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n &amp;&amp; !vis[nr][nc]) {&#10;                vis[nr][nc] = true;&#10;                q.push({nr, nc});&#10;            }&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Rec 44 Arithmetic Expressions<br><br></b> <a href='https://www.hackerrank.com/challenges/arithmetic-expressions/problem' target='_blank'>HackerRank</a></td>
      <td><b>Example 1:</b> DP with path reconstruction.</td>
      <td><b>Time:</b> O(N * 101)<br><b>Space:</b> O(N * 101)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a DP table `dp[i][mod]` to store the operator used to reach remainder `mod` at index `i`. Iterate through the array, for each reachable mod from previous step, try `(mod + arr[i]) % 101`, `(mod - arr[i]) % 101`, `(mod * arr[i]) % 101`. Then backtrack from `dp[N-1][0]` to find the operators.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string arithmeticExpressions(vector&lt;int&gt; arr) {&#10;    int n = arr.size();&#10;    vector&lt;vector&lt;char&gt;&gt; dp(n, vector&lt;char&gt;(101, 0));&#10;    dp[0][arr[0] % 101] = &#x27; &#x27;;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; 101; j++) {&#10;            if(dp[i-1][j]) {&#10;                dp[i][(j + arr[i]) % 101] = &#x27;+&#x27;;&#10;                dp[i][(j - arr[i] % 101 + 101) % 101] = &#x27;-&#x27;;&#10;                dp[i][(j * arr[i]) % 101] = &#x27;*&#x27;;&#10;            }&#10;        }&#10;    }&#10;    string res = &quot;&quot;;&#10;    int curr = 0;&#10;    for(int i = n - 1; i &gt; 0; i--) {&#10;        char op = dp[i][curr];&#10;        res = op + to_string(arr[i]) + res;&#10;        for(int j = 0; j &lt; 101; j++) {&#10;            if(dp[i-1][j]) {&#10;                if(op == &#x27;+&#x27; &amp;&amp; (j + arr[i]) % 101 == curr) { curr = j; break; }&#10;                if(op == &#x27;-&#x27; &amp;&amp; (j - arr[i] % 101 + 101) % 101 == curr) { curr = j; break; }&#10;                if(op == &#x27;*&#x27; &amp;&amp; (j * arr[i]) % 101 == curr) { curr = j; break; }&#10;            }&#10;        }&#10;    }&#10;    return to_string(arr[0]) + res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Rec 45 Find All Possible Palindromic Partitions Of A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string. Extract substring `S[ind..i]`. If it is a palindrome, add it to the current partition list and recursively call for `i+1`. When `ind == length`, push the partition list to the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPal(string&amp; s) {&#10;    int i = 0, j = s.length() - 1;&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;void solve(string&amp; S, int ind, vector&lt;string&gt;&amp; curr, vector&lt;vector&lt;string&gt;&gt;&amp; ans) {&#10;    if(ind == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; S.length(); i++) {&#10;        string sub = S.substr(ind, i - ind + 1);&#10;        if(isPal(sub)) {&#10;            curr.push_back(sub);&#10;            solve(S, i + 1, curr, ans);&#10;            curr.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; allPalindromicPerms(string S) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; curr;&#10;    solve(S, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Rec 46 Partition Array To K Subsets<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(K * 2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total sum is not divisible by K, return false. Sort array in descending order. Use a boolean array `vis`. Helper function `solve(ind, currentSum, k)`: if `k == 1` return true. If `currentSum == target`, `solve(0, 0, k-1)`. Otherwise, iterate from `ind` to `N`, if `!vis[i]` and `currentSum + arr[i] <= target`, mark `vis[i] = true`, recurse, unmark.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool solve(int a[], int n, int k, int target, int currSum, int ind, vector&lt;bool&gt;&amp; vis) {&#10;    if(k == 1) return true;&#10;    if(currSum == target) return solve(a, n, k - 1, target, 0, 0, vis);&#10;    for(int i = ind; i &lt; n; i++) {&#10;        if(!vis[i] &amp;&amp; currSum + a[i] &lt;= target) {&#10;            vis[i] = true;&#10;            if(solve(a, n, k, target, currSum + a[i], i + 1, vis)) return true;&#10;            vis[i] = false;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool isKPartitionPossible(int a[], int n, int k) {&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) sum += a[i];&#10;    if(sum % k != 0 || n &lt; k) return false;&#10;    vector&lt;bool&gt; vis(n, false);&#10;    return solve(a, n, k, sum / k, 0, 0, vis);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Rec 47 Longest Possible Route In A Matrix With Hurdles<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(4^(N*M))<br><b>Space:</b> O(N*M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a global `max_dist` or pass it by reference. In `solve(r, c, dist)`, if `(r, c) == (dest_r, dest_c)`, `max_dist = max(max_dist, dist)` and return. Mark `(r, c)` as visited. Explore 4 directions. Unmark `(r, c)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDist;&#10;void solve(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int r, int c, int dr, int dc, int dist) {&#10;    if(r == dr &amp;&amp; c == dc) {&#10;        maxDist = max(maxDist, dist);&#10;        return;&#10;    }&#10;    mat[r][c] = 0; // mark visited&#10;    int dRow[] = {-1, 1, 0, 0};&#10;    int dCol[] = {0, 0, -1, 1};&#10;    for(int i = 0; i &lt; 4; i++) {&#10;        int nr = r + dRow[i];&#10;        int nc = c + dCol[i];&#10;        if(nr &gt;= 0 &amp;&amp; nr &lt; mat.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; mat[0].size() &amp;&amp; mat[nr][nc] == 1) {&#10;            solve(mat, nr, nc, dr, dc, dist + 1);&#10;        }&#10;    }&#10;    mat[r][c] = 1; // unmark&#10;}&#10;int longestPath(vector&lt;vector&lt;int&gt;&gt; mat, int xs, int ys, int xd, int yd) {&#10;    if(mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;&#10;    maxDist = -1;&#10;    solve(mat, xs, ys, xd, yd, 0);&#10;    return maxDist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Backtracking 09 Find Shortest Safe Route In A Path With Landmines<br><br></b> <a href='https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> BFS or Backtracking.</td>
      <td><b>Time:</b> O(R * C)<br><b>Space:</b> O(R * C)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> First, mark all adjacent cells of landmines as unsafe. Then start from each cell in the first column and use BFS or Backtracking to find the shortest path to the last column, avoiding unsafe cells.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findShortestPath(vector&lt;vector&lt;int&gt;&gt; &amp;mat) {&#10;    int R = mat.size(), C = mat[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; grid(R, vector&lt;int&gt;(C, 1));&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int i = 0; i &lt; R; i++) {&#10;        for(int j = 0; j &lt; C; j++) {&#10;            if(mat[i][j] == 0) {&#10;                grid[i][j] = 0;&#10;                for(int k = 0; k &lt; 4; k++) {&#10;                    int nr = i + dr[k], nc = j + dc[k];&#10;                    if(nr &gt;= 0 &amp;&amp; nr &lt; R &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; C) grid[nr][nc] = 0;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    vector&lt;vector&lt;bool&gt;&gt; vis(R, vector&lt;bool&gt;(C, false));&#10;    for(int i = 0; i &lt; R; i++) {&#10;        if(grid[i][0] == 1) {&#10;            q.push({{i, 0}, 1});&#10;            vis[i][0] = true;&#10;        }&#10;    }&#10;    while(!q.empty()) {&#10;        auto curr = q.front(); q.pop();&#10;        int r = curr.first.first, c = curr.first.second, dist = curr.second;&#10;        if(c == C - 1) return dist;&#10;        for(int k = 0; k &lt; 4; k++) {&#10;            int nr = r + dr[k], nc = c + dc[k];&#10;            if(nr &gt;= 0 &amp;&amp; nr &lt; R &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; C &amp;&amp; grid[nr][nc] == 1 &amp;&amp; !vis[nr][nc]) {&#10;                vis[nr][nc] = true;&#10;                q.push({{nr, nc}, dist + 1});&#10;            }&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>49</td>
      <td>Backtracking 10 Combinational Sum<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(2^N * K)<br><b>Space:</b> O(K * X)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array and remove duplicates. Use backtracking. At each step, either include the current element (and stay at the current element to allow unlimited picks) or move to the next element. Backtrack when sum < 0 or we reach the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(vector&lt;int&gt;&amp; arr, int sum, int idx, vector&lt;int&gt;&amp; curr, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(sum == 0) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    if(sum &lt; 0 || idx == arr.size()) return;&#10;    curr.push_back(arr[idx]);&#10;    solve(arr, sum - arr[idx], idx, curr, ans);&#10;    curr.pop_back();&#10;    solve(arr, sum, idx + 1, curr, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum(vector&lt;int&gt; &amp;A, int B) {&#10;    sort(A.begin(), A.end());&#10;    A.erase(unique(A.begin(), A.end()), A.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; curr;&#10;    solve(A, B, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>50</td>
      <td>Backtracking 11 Find Maximum Number Possible By Doing At Most K Swaps<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(N! / (N-K)!)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use backtracking to try swapping each digit with every digit that appears after it and is greater than it. Keep track of the maximum string seen so far. Prune if swaps == 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string str, int k, string&amp; maxStr, int idx) {&#10;    if(k == 0 || idx == str.length() - 1) return;&#10;    char maxChar = str[idx];&#10;    for(int i = idx + 1; i &lt; str.length(); i++) {&#10;        if(maxChar &lt; str[i]) maxChar = str[i];&#10;    }&#10;    if(maxChar != str[idx]) k--;&#10;    for(int i = str.length() - 1; i &gt;= idx; i--) {&#10;        if(str[i] == maxChar) {&#10;            swap(str[idx], str[i]);&#10;            if(str &gt; maxStr) maxStr = str;&#10;            solve(str, k, maxStr, idx + 1);&#10;            swap(str[idx], str[i]);&#10;        }&#10;    }&#10;}&#10;string findMaximumNum(string str, int k) {&#10;    string maxStr = str;&#10;    solve(str, k, maxStr, 0);&#10;    return maxStr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>51</td>
      <td>Backtracking 12 Print All Permutations Of A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Swap based backtracking.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N!)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from index `i` to `n-1`. Swap `str[i]` with `str[j]`, then recursively call for the next index. After returning, swap back to backtrack. Store permutations in a set or sort the array to handle duplicates and lexicographical order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string S, int idx, set&lt;string&gt;&amp; st) {&#10;    if(idx == S.length()) {&#10;        st.insert(S);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; S.length(); i++) {&#10;        swap(S[idx], S[i]);&#10;        solve(S, idx + 1, st);&#10;        swap(S[idx], S[i]);&#10;    }&#10;}&#10;vector&lt;string&gt; find_permutation(string S) {&#10;    set&lt;string&gt; st;&#10;    solve(S, 0, st);&#10;    vector&lt;string&gt; ans(st.begin(), st.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>52</td>
      <td>Backtracking 13 Find If There Is A Path Of More Than K Length From A Source<br><br></b> <a href='https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS Backtracking.</td>
      <td><b>Time:</b> O(V!)<br><b>Space:</b> O(V)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Backtracking to perform DFS traversal from the source. Mark the current vertex as visited, subtract the edge weight from `k`, and recursively call for all adjacent unvisited vertices. If `k <= 0`, return true. Backtrack by unmarking the vertex.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool pathMoreThanK(int src, int k, vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt;&amp; adj, vector&lt;bool&gt;&amp; vis) {&#10;    if(k &lt;= 0) return true;&#10;    vis[src] = true;&#10;    for(auto i : adj[src]) {&#10;        int v = i.first, w = i.second;&#10;        if(!vis[v]) {&#10;            if(pathMoreThanK(v, k - w, adj, vis)) return true;&#10;        }&#10;    }&#10;    vis[src] = false;&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>53</td>
      <td>Backtracking 14 Longest Possible Route In A Matrix With Hurdles<br><br></b> <a href='https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(4^(M*N))<br><b>Space:</b> O(M*N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Backtracking. Start from the source, mark it as visited, recursively find the longest path from all valid unvisited adjacent cells, add 1 to the maximum among them. Unmark the cell after returning.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findLongestPath(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int i, int j, int di, int dj, int curr, int&amp; max_dist, vector&lt;vector&lt;bool&gt;&gt;&amp; vis) {&#10;    if(i == di &amp;&amp; j == dj) {&#10;        max_dist = max(max_dist, curr);&#10;        return;&#10;    }&#10;    vis[i][j] = true;&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int k = 0; k &lt; 4; k++) {&#10;        int nr = i + dr[k], nc = j + dc[k];&#10;        if(nr &gt;= 0 &amp;&amp; nr &lt; mat.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; mat[0].size() &amp;&amp; mat[nr][nc] == 1 &amp;&amp; !vis[nr][nc]) {&#10;            findLongestPath(mat, nr, nc, di, dj, curr + 1, max_dist, vis);&#10;        }&#10;    }&#10;    vis[i][j] = false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>54</td>
      <td>Backtracking 15 Print All Possible Paths From Top Left To Bottom Right Of A Mxn Matrix<br><br></b> <a href='https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(2^(M+N))<br><b>Space:</b> O(M+N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use simple DFS from top-left. From cell (i, j), we can move to (i+1, j) or (i, j+1). Keep track of the path elements in an array/list. When reaching bottom-right, print/save the path.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findPaths(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int i, int j, vector&lt;int&gt;&amp; path, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(i == mat.size() - 1 &amp;&amp; j == mat[0].size() - 1) {&#10;        path.push_back(mat[i][j]);&#10;        ans.push_back(path);&#10;        path.pop_back();&#10;        return;&#10;    }&#10;    path.push_back(mat[i][j]);&#10;    if(i + 1 &lt; mat.size()) findPaths(mat, i + 1, j, path, ans);&#10;    if(j + 1 &lt; mat[0].size()) findPaths(mat, i, j + 1, path, ans);&#10;    path.pop_back();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>55</td>
      <td>Backtracking 16 Partition Of A Set Into K Subsets With Equal Sum<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking with tracking subset sum.</td>
      <td><b>Time:</b> O(K^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total sum is not divisible by K, return false. Create an array of K subset sums. Backtrack to assign each element to one of the K subsets, ensuring no subset sum exceeds total_sum / K. To optimize, sort array descending.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool solve(int a[], int n, int k, int target, vector&lt;int&gt;&amp; subsetSum, int idx) {&#10;    if(idx == n) {&#10;        for(int i = 0; i &lt; k; i++) if(subsetSum[i] != target) return false;&#10;        return true;&#10;    }&#10;    for(int i = 0; i &lt; k; i++) {&#10;        if(subsetSum[i] + a[idx] &lt;= target) {&#10;            subsetSum[i] += a[idx];&#10;            if(solve(a, n, k, target, subsetSum, idx + 1)) return true;&#10;            subsetSum[i] -= a[idx];&#10;        }&#10;        if(subsetSum[i] == 0) break; // Optimization&#10;    }&#10;    return false;&#10;}&#10;bool isKPartitionPossible(int a[], int n, int k) {&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) sum += a[i];&#10;    if(sum % k != 0) return false;&#10;    sort(a, a + n, greater&lt;int&gt;());&#10;    vector&lt;int&gt; subsetSum(k, 0);&#10;    return solve(a, n, k, sum / k, subsetSum, 0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>56</td>
      <td>Backtracking 17 Find All Possible Palindromic Partitions Of A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate over the string to pick substrings. Check if the picked substring is a palindrome. If yes, add it to current partition and recur for the remaining string. Backtrack by removing it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string&amp; s, int l, int r) {&#10;    while(l &lt; r) {&#10;        if(s[l++] != s[r--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(string&amp; S, int idx, vector&lt;string&gt;&amp; curr, vector&lt;vector&lt;string&gt;&gt;&amp; ans) {&#10;    if(idx == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; S.length(); i++) {&#10;        if(isPalindrome(S, idx, i)) {&#10;            curr.push_back(S.substr(idx, i - idx + 1));&#10;            solve(S, i + 1, curr, ans);&#10;            curr.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; allPalindromicPerms(string S) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; curr;&#10;    solve(S, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>57</td>
      <td>Backtracking 18 Word Break Problem Using Backtracking<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/word-break-part-23249/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from current index. For each prefix, if it is in the dictionary, add it to the current sentence string, add a space, and recur for the suffix. If we reach the end of the string, add the current sentence to the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string&amp; s, int idx, string curr, unordered_set&lt;string&gt;&amp; dict, vector&lt;string&gt;&amp; ans) {&#10;    if(idx == s.length()) {&#10;        curr.pop_back(); // Remove last space&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; s.length(); i++) {&#10;        string word = s.substr(idx, i - idx + 1);&#10;        if(dict.find(word) != dict.end()) {&#10;            solve(s, i + 1, curr + word + &quot; &quot;, dict, ans);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; wordBreak(int n, vector&lt;string&gt;&amp; dict, string s) {&#10;    unordered_set&lt;string&gt; st(dict.begin(), dict.end());&#10;    vector&lt;string&gt; ans;&#10;    solve(s, 0, &quot;&quot;, st, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
