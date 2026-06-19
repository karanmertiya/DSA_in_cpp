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
      <td rowspan="1">1</td>
      <td rowspan="1">Rec 01 Subsets<br><br></b> <a href='https://leetcode.com/problems/subsets/' target='_blank'>LeetCode 78</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,2,3], Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]<br><br><b>Note (Constraint):</b> The solution set must not contain duplicate subsets.</td>
      <td><b>Time:</b> O(2<sup>N</sup>) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>-</td>
      <td><b>Recursion Tree Depth:</b> The maximum depth of the recursive stack is `N`, leading to `O(N)` auxiliary space.</td>
      <td><b>Explanation:</b> Pick / Non-Pick logic. For every element, we have two choices: either include it in the current subset, or don't. Recursively explore both paths.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void solve(int i, std::vector&lt;int&gt;&amp; nums, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == nums.size()) {&#10;        ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick&#10;    temp.push_back(nums[i]);&#10;    solve(i + 1, nums, temp, ans);&#10;    temp.pop_back();&#10;    &#10;    // Not Pick&#10;    solve(i + 1, nums, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; subsets(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, nums, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Rec 02 Combination Sum<br><br></b> <a href='https://leetcode.com/problems/combination-sum/' target='_blank'>LeetCode 39</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: candidates = [2,3,6,7], target = 7, Output: [[2,2,3],[7]]<br><br><b>Note (Constraint):</b> The same number may be chosen unlimited number of times.</td>
      <td><b>Time:</b> O(2<sup>T</sup>) (Trade-off)<br><b>Space:</b> O(T) (Trade-off)</td>
      <td>-</td>
      <td><b>Infinite Loop Prevention:</b> Base cases must immediately return if `target < 0` to prevent infinite recursion on the same index.</td>
      <td><b>Explanation:</b> Pick/Non-Pick but when picking, we *do not* increment the index `i`, allowing the same element to be picked infinitely until `target < 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void solve(int i, std::vector&lt;int&gt;&amp; arr, int target, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == arr.size()) {&#10;        if (target == 0) ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick (Stay on same index if valid)&#10;    if (arr[i] &lt;= target) {&#10;        temp.push_back(arr[i]);&#10;        solve(i, arr, target - arr[i], temp, ans);&#10;        temp.pop_back();&#10;    }&#10;    // Not Pick (Move to next)&#10;    solve(i + 1, arr, target, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; combinationSum(std::vector&lt;int&gt;&amp; candidates, int target) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, candidates, target, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Rec 03 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: n = 4, Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br><br><b>Note (Constraint):</b> 1 &le; n &le; 9</td>
      <td><b>Time:</b> O(N!) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>Hash Maps/Arrays for safety checks</td>
      <td><b>Diagonal Math:</b> Lower diagonal is tracked via `row + col`, Upper diagonal via `(n - 1) + (col - row)`.</td>
      <td><b>Explanation:</b> Backtracking. Try placing a queen in each row of the current column. Use `O(1)` lookups (Hashing logic) via arrays to check if row/diagonals are safe.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;string&gt;&#10;&#10;void solve(int col, int n, std::vector&lt;std::string&gt;&amp; board, std::vector&lt;std::vector&lt;std::string&gt;&gt;&amp; ans, std::vector&lt;int&gt;&amp; leftRow, std::vector&lt;int&gt;&amp; upperDiag, std::vector&lt;int&gt;&amp; lowerDiag) {&#10;    if (col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for (int row = 0; row &lt; n; row++) {&#10;        if (leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            &#10;            solve(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;            &#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;&#10;std::vector&lt;std::vector&lt;std::string&gt;&gt; solveNQueens(int n) {&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    std::vector&lt;std::string&gt; board(n, std::string(n, &#x27;.&#x27;));&#10;    std::vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Rec 02 Subsets<br><br></b> <a href='https://leetcode.com/problems/subsets/' target='_blank'>LeetCode 78</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,2,3], Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]</td>
      <td><b>Time:</b> O(2<sup>N</sup> * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Reference Storage:</b> In Python, `temp[:]` must be used to append a copy of the subset, not the reference to the mutating list.</td>
      <td><b>Explanation:</b> Pick / Not Pick technique. For every element, branch recursively: one path includes the element, the other path excludes it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(temp);&#10;        return;&#10;    }&#10;    temp.push_back(nums[idx]);&#10;    solve(idx + 1, nums, temp, ans);&#10;    temp.pop_back();&#10;    solve(idx + 1, nums, temp, ans);&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; subsets(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, nums, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Rec 03 Permutations<br><br></b> <a href='https://leetcode.com/problems/permutations/' target='_blank'>LeetCode 46</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,2,3], Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td><code>std::swap</code></td>
      <td><b>Backtracking necessity:</b> Without the second swap (backtrack), the array remains mutated for subsequent sibling recursion branches.</td>
      <td><b>Explanation:</b> Backtracking. Swap elements to generate permutations. For index `i`, swap it with every index from `i` to `n-1`, recurse, then backtrack (swap back).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; nums.size(); i++) {&#10;        std::swap(nums[idx], nums[i]);&#10;        solve(idx + 1, nums, ans);&#10;        std::swap(nums[idx], nums[i]);&#10;    }&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; permute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    solve(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Rec 06 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td rowspan="1"><b>Example 1:</b> Classic N-Queens constraint satisfaction.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Place queen column by column. To optimize collision checking to O(1), use 3 arrays/hashmaps: `leftRow`, `upperDiagonal`, and `lowerDiagonal`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, vector&lt;string&gt;&amp; board, vector&lt;vector&lt;string&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiag, vector&lt;int&gt;&amp; lowerDiag, int n) {&#10;    if(col == n) { ans.push_back(board); return; }&#10;    for(int row=0; row&lt;n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1; lowerDiag[row + col] = 1; upperDiag[n - 1 + col - row] = 1;&#10;            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);&#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0; lowerDiag[row + col] = 0; upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; solveNQueens(int n) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; board(n, string(n, &#x27;.&#x27;));&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);&#10;    solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Rec 07 Sudoku Solver<br><br></b> <a href='https://leetcode.com/problems/sudoku-solver/' target='_blank'>LeetCode 37</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: board with '.' for empty cells. Solve in-place.</td>
      <td><b>Time:</b> O(9^(n*n))<br><b>Space:</b> O(1) auxiliary</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Find first empty cell, try placing 1-9. Validate row, col, and 3x3 sub-grid. Recursively solve the rest. If it fails, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board)) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Rec 08 M Coloring Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return true if possible.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Try coloring each node with color 1 to m. For a color, check if any adjacent node has the same color. If safe, assign and recurse for next node. If recursion returns false, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int n, bool graph[101][101]) {&#10;    if(node == n) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, n, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, n, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int n) {&#10;    int color[n] = {0};&#10;    return solve(0, color, m, n, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Rec 09 Rat In A Maze<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Lexicographical order paths.</td>
      <td><b>Time:</b> O(4^(N*N))<br><b>Space:</b> O(N*N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Explore 4 directions (D, L, R, U) in lexicographical order to get sorted paths naturally. Mark cell as visited, recurse, then unmark (backtrack).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;m, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis, int di[], int dj[]) {&#10;    if(i == n-1 &amp;&amp; j == n-1) { ans.push_back(move); return; }&#10;    string dir = &quot;DLRU&quot;;&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; m[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis, di, dj);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Rec 10 Word Break<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = 'leetcode', wordDict = ['leet','code'], Output: true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Recursion with Memoization (or DP). For each index, try all possible word lengths. If a prefix exists in dict, recurse for the suffix. DP array `dp[i]` stores if `s[0...i-1]` is valid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Rec 11 Word Break Ii<br><br></b> <a href='https://leetcode.com/problems/word-break-ii/' target='_blank'>LeetCode 140</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of sentences.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Generate all combinations. At each step, if a prefix is in dict, recursively call for the rest of the string and append the prefix to the result of the recursive call.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;string&gt; solve(string s, unordered_set&lt;string&gt;&amp; dict, unordered_map&lt;string, vector&lt;string&gt;&gt;&amp; memo) {&#10;    if(memo.count(s)) return memo[s];&#10;    if(s.empty()) return {&quot;&quot;};&#10;    vector&lt;string&gt; res;&#10;    for(int i=1; i&lt;=s.length(); i++) {&#10;        string word = s.substr(0, i);&#10;        if(dict.count(word)) {&#10;            vector&lt;string&gt; rem = solve(s.substr(i), dict, memo);&#10;            for(string str : rem) {&#10;                res.push_back(word + (str.empty() ? &quot;&quot; : &quot; &quot;) + str);&#10;            }&#10;        }&#10;    }&#10;    return memo[s] = res;&#10;}&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    unordered_map&lt;string, vector&lt;string&gt;&gt; memo;&#10;    return solve(s, dict, memo);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Rec 12 Palindrome Partitioning<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning/' target='_blank'>LeetCode 131</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = 'aab', Output: [['a','a','b'],['aa','b']]</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Try to partition the string at every index. If the prefix `s[start:i]` is a palindrome, add it to current path and recurse for the rest of the string `s[i:end]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(int index, string s, vector&lt;string&gt; &amp;path, vector&lt;vector&lt;string&gt;&gt; &amp;res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            solve(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    solve(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Rec 13 Expression Add Operators<br><br></b> <a href='https://leetcode.com/problems/expression-add-operators/' target='_blank'>LeetCode 282</a></td>
      <td rowspan="1"><b>Example 1:</b> Return expressions.</td>
      <td><b>Time:</b> O(N * 4^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Keep track of the evaluated sum so far, and the previous operand (for multiplication precedence). For '*', `newSum = sum - prev + prev * curr`. Handle leading zeros.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string num, int target, vector&lt;string&gt;&amp; ans, string path, long long eval, long long multed) {&#10;    if(ind == num.size()) {&#10;        if(eval == target) ans.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; num.size(); i++) {&#10;        if(i != ind &amp;&amp; num[ind] == &#x27;0&#x27;) break;&#10;        string curStr = num.substr(ind, i - ind + 1);&#10;        long long curNum = stoll(curStr);&#10;        if(ind == 0) {&#10;            solve(i + 1, num, target, ans, path + curStr, curNum, curNum);&#10;        } else {&#10;            solve(i + 1, num, target, ans, path + &quot;+&quot; + curStr, eval + curNum, curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;-&quot; + curStr, eval - curNum, -curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;*&quot; + curStr, eval - multed + multed * curNum, multed * curNum);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; addOperators(string num, int target) {&#10;    vector&lt;string&gt; ans;&#10;    solve(0, num, target, ans, &quot;&quot;, 0, 0);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Rec 14 Subset Sums Ii<br><br></b> <a href='https://leetcode.com/problems/subsets-ii/' target='_blank'>LeetCode 90</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array first to bring duplicates together. In recursive call, loop from `ind` to `n`. If `i > ind` and `nums[i] == nums[i-1]`, `continue` to skip duplicate recursive branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i = ind; i &lt; nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i - 1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Rec 15 Combination Sum Ii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-ii/' target='_blank'>LeetCode 40</a></td>
      <td rowspan="1"><b>Example 1:</b> Return unique combinations.</td>
      <td><b>Time:</b> O(2^N * k)<br><b>Space:</b> O(k * x)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Recursive function iterates from `ind` to `n`. Skip duplicates (`if i > ind and arr[i] == arr[i-1]`). If `arr[i] > target`, break. Else add to path, subtract from target, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i - 1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Rec 16 Combination Sum Iii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-iii/' target='_blank'>LeetCode 216</a></td>
      <td rowspan="1"><b>Example 1:</b> Return combinations.</td>
      <td><b>Time:</b> O(2^9)<br><b>Space:</b> O(k)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Start from 1, go up to 9. Add the current number to the path and subtract from target. Stop when path size is `k` and `target` is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int start, int k, int n, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(k == 0 &amp;&amp; n == 0) { ans.push_back(ds); return; }&#10;    if(k == 0 || n &lt; 0) return;&#10;    for(int i = start; i &lt;= 9; i++) {&#10;        ds.push_back(i);&#10;        solve(i + 1, k - 1, n - i, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum3(int k, int n) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    solve(1, k, n, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Rec 17 Letter Combinations Of A Phone Number<br><br></b> <a href='https://leetcode.com/problems/letter-combinations-of-a-phone-number/' target='_blank'>LeetCode 17</a></td>
      <td rowspan="1"><b>Example 1:</b> String combinations.</td>
      <td><b>Time:</b> O(4^N * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. Create a mapping of digit to letters. Iterate through digits, for each digit loop through its mapped letters, append to current string, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string digits, string mapping[], string path, vector&lt;string&gt;&amp; ans) {&#10;    if(ind == digits.length()) {&#10;        ans.push_back(path);&#10;        return;&#10;    }&#10;    int number = digits[ind] - &#x27;0&#x27;;&#10;    string value = mapping[number];&#10;    for(int i = 0; i &lt; value.length(); i++) {&#10;        solve(ind + 1, digits, mapping, path + value[i], ans);&#10;    }&#10;}&#10;vector&lt;string&gt; letterCombinations(string digits) {&#10;    if(digits.length() == 0) return {};&#10;    vector&lt;string&gt; ans;&#10;    string mapping[10] = {&quot;&quot;, &quot;&quot;, &quot;abc&quot;, &quot;def&quot;, &quot;ghi&quot;, &quot;jkl&quot;, &quot;mno&quot;, &quot;pqrs&quot;, &quot;tuv&quot;, &quot;wxyz&quot;};&#10;    solve(0, digits, mapping, &quot;&quot;, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Rec 18 Rat In A Maze<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(4^(N^2))<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use backtracking to explore paths in lexicographical order: Down, Left, Right, Up (DLRU). Maintain a visited array. If destination is reached, add path to answers. Backtrack by unmarking visited.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;a, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis) {&#10;    if(i == n-1 &amp;&amp; j == n-1) {&#10;        ans.push_back(move);&#10;        return;&#10;    }&#10;    string dir = &quot;DLRU&quot;;&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; a[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, a, n, ans, move + dir[ind], vis);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Rec 19 Word Break Ii<br><br></b> <a href='https://leetcode.com/problems/word-break-ii/' target='_blank'>LeetCode 140</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion + Memoization.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(2^N * N)</td>
      <td><code>#include <unordered_set>\n#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Backtracking. For each index, try all possible prefixes. If prefix is in dict, recursively break the remaining string. Use memoization or DP to store answers for a substring to avoid recomputation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">unordered_map&lt;string, vector&lt;string&gt;&gt; dp;&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    return helper(s, dict);&#10;}&#10;vector&lt;string&gt; helper(string s, unordered_set&lt;string&gt;&amp; dict) {&#10;    if(dp.find(s) != dp.end()) return dp[s];&#10;    vector&lt;string&gt; res;&#10;    if(dict.find(s) != dict.end()) res.push_back(s);&#10;    for(int i=1; i&lt;s.length(); i++) {&#10;        string right = s.substr(i);&#10;        if(dict.find(right) != dict.end()) {&#10;            vector&lt;string&gt; left_res = helper(s.substr(0, i), dict);&#10;            for(string l : left_res) res.push_back(l + &quot; &quot; + right);&#10;        }&#10;    }&#10;    return dp[s] = res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Rec 20 M Coloring Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Graph coloring backtracking.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Try coloring each node from `1` to `M`. Before coloring, check if it's safe (no adjacent node has same color). If safe, color it and recurse for next node. Backtrack if no color works.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int N, bool graph[101][101]) {&#10;    if(node == N) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, N, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, N, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int N) {&#10;    int color[N] = {0};&#10;    return solve(0, color, m, N, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Rec 21 Sudoku Solver<br><br></b> <a href='https://leetcode.com/problems/sudoku-solver/' target='_blank'>LeetCode 37</a></td>
      <td rowspan="1"><b>Example 1:</b> Classic backtracking.</td>
      <td><b>Time:</b> O(9^(N^2))<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through matrix. If empty, try '1' to '9'. Check `isValid` (row, col, 3x3 box). If valid, set it and recurse. If recursion returns true, puzzle solved. Else backtrack. If loop ends without returning true, return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board) == true) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Rec 22 N Queens<br><br></b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking on board.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Place queens column by column. Keep track of safe rows and diagonals using hashing arrays: `leftRow`, `lowerDiagonal`, `upperDiagonal`. If safe, place queen, update hashes, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, vector&lt;string&gt;&amp; board, vector&lt;vector&lt;string&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiagonal, vector&lt;int&gt;&amp; lowerDiagonal, int n) {&#10;    if(col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for(int row=0; row&lt;n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiagonal[row + col] == 0 &amp;&amp; upperDiagonal[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiagonal[row + col] = 1;&#10;            upperDiagonal[n - 1 + col - row] = 1;&#10;            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);&#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiagonal[row + col] = 0;&#10;            upperDiagonal[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; solveNQueens(int n) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; board(n);&#10;    string s(n, &#x27;.&#x27;);&#10;    for(int i=0; i&lt;n; i++) board[i] = s;&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);&#10;    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Rec 23 Permutations Of A String Or Array<br><br></b> <a href='https://leetcode.com/problems/permutations/' target='_blank'>LeetCode 46</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking swap.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate `i` from `index` to `n-1`. Swap `nums[index]` and `nums[i]`, then recurse for `index + 1`. Swap back to backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recurPermute(int index, vector&lt;int&gt;&amp; nums, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(index == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; nums.size(); i++) {&#10;        swap(nums[index], nums[i]);&#10;        recurPermute(index + 1, nums, ans);&#10;        swap(nums[index], nums[i]);&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; permute(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    recurPermute(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Rec 24 Combination Sum Ii<br><br></b> <a href='https://leetcode.com/problems/combination-sum-ii/' target='_blank'>LeetCode 40</a></td>
      <td rowspan="1"><b>Example 1:</b> `candidates = [10,1,2,7,6,1,5], target = 8`.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N * X) where X is number of combinations</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort candidates. Recursively pick combinations. If `i > ind` and `candidates[i] == candidates[i-1]`, skip to avoid duplicates. If `target - candidates[i] >= 0`, pick it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i=ind; i&lt;arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i-1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Rec 25 Subset Sum I<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/subset-sums2234/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Take / Not Take.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recursively either include `arr[ind]` in sum, or exclude it. If `ind == N`, add `sum` to result array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void func(int ind, int sum, vector&lt;int&gt;&amp; arr, int N, vector&lt;int&gt;&amp; sumSubset) {&#10;    if(ind == N) {&#10;        sumSubset.push_back(sum);&#10;        return;&#10;    }&#10;    func(ind + 1, sum + arr[ind], arr, N, sumSubset);&#10;    func(ind + 1, sum, arr, N, sumSubset);&#10;}&#10;vector&lt;int&gt; subsetSums(vector&lt;int&gt; arr, int N) {&#10;    vector&lt;int&gt; sumSubset;&#10;    func(0, 0, arr, N, sumSubset);&#10;    sort(sumSubset.begin(), sumSubset.end());&#10;    return sumSubset;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Rec 26 Subset Sum Ii<br><br></b> <a href='https://leetcode.com/problems/subsets-ii/' target='_blank'>LeetCode 90</a></td>
      <td rowspan="1"><b>Example 1:</b> Subset skip duplicates.</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * K)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Recursive call adds current `ds` to `ans`. Then iterate `i` from `ind` to `n`. Skip if `i > ind` and `nums[i] == nums[i-1]`. Add to `ds`, recurse for `i+1`, pop from `ds`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i=ind; i&lt;nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Rec 27 Palindrome Partitioning<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning/' target='_blank'>LeetCode 131</a></td>
      <td rowspan="1"><b>Example 1:</b> Valid palindrome checks on prefix.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * X)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recurse through string. For index `i`, check substring `s[index...i]`. If it is palindrome, add it to current list, and recurse for `i+1`. Backtrack after recursion.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void func(int index, string s, vector&lt;string&gt;&amp; path, vector&lt;vector&lt;string&gt;&gt;&amp; res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i=index; i&lt;s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            func(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    func(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
