# Step 07 Recursion Revision Table

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
      <td>Str 01 Palindrome String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindrome-string0817/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use two pointers, `left` at the beginning and `right` at the end of the string. Compare the characters at these pointers. If they are different, return 0. Move pointers towards each other. If all characters match, return 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPalindrome(string S) {&#10;    int left = 0, right = S.length() - 1;&#10;    while(left &lt; right) {&#10;        if(S[left] != S[right]) return 0;&#10;        left++; right--;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Rec 02 Combination Sum<br><br></b> <a href="https://leetcode.com/problems/combination-sum/" target="_blank">LeetCode 39</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: candidates = [2,3,6,7], target = 7, Output: [[2,2,3],[7]]<br><br><b>Note (Constraint):</b> The same number may be chosen unlimited number of times.</td>
      <td><b>Time:</b> O(2<sup>T</sup>) (Trade-off)<br><b>Space:</b> O(T) (Trade-off)</td>
      <td><b>Explanation:</b> Pick/Non-Pick but when picking, we *do not* increment the index `i`, allowing the same element to be picked infinitely until `target < 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, std::vector&lt;int&gt;&amp; arr, int target, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == arr.size()) {&#10;        if (target == 0) ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick (Stay on same index if valid)&#10;    if (arr[i] &lt;= target) {&#10;        temp.push_back(arr[i]);&#10;        solve(i, arr, target - arr[i], temp, ans);&#10;        temp.pop_back();&#10;    }&#10;    // Not Pick (Move to next)&#10;    solve(i + 1, arr, target, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; combinationSum(std::vector&lt;int&gt;&amp; candidates, int target) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, candidates, target, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Rec 03 N Queens<br><br></b> <a href="https://leetcode.com/problems/n-queens/" target="_blank">LeetCode 51</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: n = 4, Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br><br><b>Note (Constraint):</b> 1 &le; n &le; 9</td>
      <td><b>Time:</b> O(N!) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td><b>Explanation:</b> Backtracking. Try placing a queen in each row of the current column. Use `O(1)` lookups (Hashing logic) via arrays to check if row/diagonals are safe.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, int n, std::vector&lt;std::string&gt;&amp; board, std::vector&lt;std::vector&lt;std::string&gt;&gt;&amp; ans, std::vector&lt;int&gt;&amp; leftRow, std::vector&lt;int&gt;&amp; upperDiag, std::vector&lt;int&gt;&amp; lowerDiag) {&#10;    if (col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for (int row = 0; row &lt; n; row++) {&#10;        if (leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            &#10;            solve(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;            &#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;&#10;std::vector&lt;std::vector&lt;std::string&gt;&gt; solveNQueens(int n) {&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    std::vector&lt;std::string&gt; board(n, std::string(n, &#x27;.&#x27;));&#10;    std::vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Rec 04 Permutations<br><br></b> <a href="https://leetcode.com/problems/permutations/" target="_blank">LeetCode 46</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Backtracking. Swap elements to generate permutations. For index `i`, swap it with every index from `i` to `n-1`, recurse, then backtrack (swap back).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; nums.size(); i++) {&#10;        std::swap(nums[idx], nums[i]);&#10;        solve(idx + 1, nums, ans);&#10;        std::swap(nums[idx], nums[i]);&#10;    }&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; permute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    solve(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Rec 05 Sudoku Solver<br><br></b> <a href="https://leetcode.com/problems/sudoku-solver/" target="_blank">LeetCode 37</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Input: board with '.' for empty cells. Solve in-place.</td>
      <td><b>Time:</b> O(9^(n*n))<br><b>Space:</b> O(1) auxiliary</td>
      <td><b>Explanation:</b> Backtracking. Find first empty cell, try placing 1-9. Validate row, col, and 3x3 sub-grid. Recursively solve the rest. If it fails, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board)) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Rec 06 M Coloring Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Return true if possible.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Backtracking. Try coloring each node with color 1 to m. For a color, check if any adjacent node has the same color. If safe, assign and recurse for next node. If recursion returns false, backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int n, bool graph[101][101]) {&#10;    if(node == n) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, n, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, n, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int n) {&#10;    int color[n] = {0};&#10;    return solve(0, color, m, n, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Rec 07 Rat In A Maze<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Lexicographical order paths.</td>
      <td><b>Time:</b> O(4^(N*N))<br><b>Space:</b> O(N*N)</td>
      <td><b>Explanation:</b> Backtracking. Explore 4 directions (D, L, R, U) in lexicographical order to get sorted paths naturally. Mark cell as visited, recurse, then unmark (backtrack).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;m, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis, int di[], int dj[]) {&#10;    if(i == n-1 &amp;&amp; j == n-1) { ans.push_back(move); return; }&#10;    string dir = &quot;DLRU&quot;;&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; m[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis, di, dj);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Rec 08 Word Break<br><br></b> <a href="https://leetcode.com/problems/word-break/" target="_blank">LeetCode 139</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> Input: s = 'leetcode', wordDict = ['leet','code'], Output: true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Recursion with Memoization (or DP). For each index, try all possible word lengths. If a prefix exists in dict, recurse for the suffix. DP array `dp[i]` stores if `s[0...i-1]` is valid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Rec 09 Word Break Ii<br><br></b> <a href="https://leetcode.com/problems/word-break-ii/" target="_blank">LeetCode 140</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Return list of sentences.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td><b>Explanation:</b> Backtracking. Generate all combinations. At each step, if a prefix is in dict, recursively call for the rest of the string and append the prefix to the result of the recursive call.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;string&gt; solve(string s, unordered_set&lt;string&gt;&amp; dict, unordered_map&lt;string, vector&lt;string&gt;&gt;&amp; memo) {&#10;    if(memo.count(s)) return memo[s];&#10;    if(s.empty()) return {&quot;&quot;};&#10;    vector&lt;string&gt; res;&#10;    for(int i=1; i&lt;=s.length(); i++) {&#10;        string word = s.substr(0, i);&#10;        if(dict.count(word)) {&#10;            vector&lt;string&gt; rem = solve(s.substr(i), dict, memo);&#10;            for(string str : rem) {&#10;                res.push_back(word + (str.empty() ? &quot;&quot; : &quot; &quot;) + str);&#10;            }&#10;        }&#10;    }&#10;    return memo[s] = res;&#10;}&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    unordered_map&lt;string, vector&lt;string&gt;&gt; memo;&#10;    return solve(s, dict, memo);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Rec 10 Palindrome Partitioning<br><br></b> <a href="https://leetcode.com/problems/palindrome-partitioning/" target="_blank">LeetCode 131</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Input: s = 'aab', Output: [['a','a','b'],['aa','b']]</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Backtracking. Try to partition the string at every index. If the prefix `s[start:i]` is a palindrome, add it to current path and recurse for the rest of the string `s[i:end]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(int index, string s, vector&lt;string&gt; &amp;path, vector&lt;vector&lt;string&gt;&gt; &amp;res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            solve(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    solve(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Rec 11 Expression Add Operators<br><br></b> <a href="https://leetcode.com/problems/expression-add-operators/" target="_blank">LeetCode 282</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Return expressions.</td>
      <td><b>Time:</b> O(N * 4^N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Backtracking. Keep track of the evaluated sum so far, and the previous operand (for multiplication precedence). For '*', `newSum = sum - prev + prev * curr`. Handle leading zeros.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string num, int target, vector&lt;string&gt;&amp; ans, string path, long long eval, long long multed) {&#10;    if(ind == num.size()) {&#10;        if(eval == target) ans.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; num.size(); i++) {&#10;        if(i != ind &amp;&amp; num[ind] == &#x27;0&#x27;) break;&#10;        string curStr = num.substr(ind, i - ind + 1);&#10;        long long curNum = stoll(curStr);&#10;        if(ind == 0) {&#10;            solve(i + 1, num, target, ans, path + curStr, curNum, curNum);&#10;        } else {&#10;            solve(i + 1, num, target, ans, path + &quot;+&quot; + curStr, eval + curNum, curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;-&quot; + curStr, eval - curNum, -curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;*&quot; + curStr, eval - multed + multed * curNum, multed * curNum);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; addOperators(string num, int target) {&#10;    vector&lt;string&gt; ans;&#10;    solve(0, num, target, ans, &quot;&quot;, 0, 0);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Rec 12 Subset Sums Ii<br><br></b> <a href="https://leetcode.com/problems/subsets-ii/" target="_blank">LeetCode 90</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * N)</td>
      <td><b>Explanation:</b> Sort array first to bring duplicates together. In recursive call, loop from `ind` to `n`. If `i > ind` and `nums[i] == nums[i-1]`, `continue` to skip duplicate recursive branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i = ind; i &lt; nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i - 1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Rec 13 Combination Sum Ii<br><br></b> <a href="https://leetcode.com/problems/combination-sum-ii/" target="_blank">LeetCode 40</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Return unique combinations.</td>
      <td><b>Time:</b> O(2^N * k)<br><b>Space:</b> O(k * x)</td>
      <td><b>Explanation:</b> Sort the array. Recursive function iterates from `ind` to `n`. Skip duplicates (`if i > ind and arr[i] == arr[i-1]`). If `arr[i] > target`, break. Else add to path, subtract from target, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i - 1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Rec 14 Combination Sum Iii<br><br></b> <a href="https://leetcode.com/problems/combination-sum-iii/" target="_blank">LeetCode 216</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Return combinations.</td>
      <td><b>Time:</b> O(2^9)<br><b>Space:</b> O(k)</td>
      <td><b>Explanation:</b> Backtracking. Start from 1, go up to 9. Add the current number to the path and subtract from target. Stop when path size is `k` and `target` is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int start, int k, int n, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(k == 0 &amp;&amp; n == 0) { ans.push_back(ds); return; }&#10;    if(k == 0 || n &lt; 0) return;&#10;    for(int i = start; i &lt;= 9; i++) {&#10;        ds.push_back(i);&#10;        solve(i + 1, k - 1, n - i, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum3(int k, int n) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    solve(1, k, n, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Rec 15 Letter Combinations Of A Phone Number<br><br></b> <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number/" target="_blank">LeetCode 17</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> String combinations.</td>
      <td><b>Time:</b> O(4^N * N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Backtracking. Create a mapping of digit to letters. Iterate through digits, for each digit loop through its mapped letters, append to current string, and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string digits, string mapping[], string path, vector&lt;string&gt;&amp; ans) {&#10;    if(ind == digits.length()) {&#10;        ans.push_back(path);&#10;        return;&#10;    }&#10;    int number = digits[ind] - &#x27;0&#x27;;&#10;    string value = mapping[number];&#10;    for(int i = 0; i &lt; value.length(); i++) {&#10;        solve(ind + 1, digits, mapping, path + value[i], ans);&#10;    }&#10;}&#10;vector&lt;string&gt; letterCombinations(string digits) {&#10;    if(digits.length() == 0) return {};&#10;    vector&lt;string&gt; ans;&#10;    string mapping[10] = {&quot;&quot;, &quot;&quot;, &quot;abc&quot;, &quot;def&quot;, &quot;ghi&quot;, &quot;jkl&quot;, &quot;mno&quot;, &quot;pqrs&quot;, &quot;tuv&quot;, &quot;wxyz&quot;};&#10;    solve(0, digits, mapping, &quot;&quot;, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Rec 16 Subset Sum I<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subset-sums2234/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Take / Not Take.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td><b>Explanation:</b> Recursively either include `arr[ind]` in sum, or exclude it. If `ind == N`, add `sum` to result array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void func(int ind, int sum, vector&lt;int&gt;&amp; arr, int N, vector&lt;int&gt;&amp; sumSubset) {&#10;    if(ind == N) {&#10;        sumSubset.push_back(sum);&#10;        return;&#10;    }&#10;    func(ind + 1, sum + arr[ind], arr, N, sumSubset);&#10;    func(ind + 1, sum, arr, N, sumSubset);&#10;}&#10;vector&lt;int&gt; subsetSums(vector&lt;int&gt; arr, int N) {&#10;    vector&lt;int&gt; sumSubset;&#10;    func(0, 0, arr, N, sumSubset);&#10;    sort(sumSubset.begin(), sumSubset.end());&#10;    return sumSubset;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Rec 17 N Queens Ii<br><br></b> <a href="https://leetcode.com/problems/n-queens-ii/" target="_blank">LeetCode 52</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Backtracking with hashing.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use backtracking to place queens column by column. Use three hash arrays (or bitmasks) to track attacked rows, upper diagonals, and lower diagonals. If placing a queen is safe, update hashes, recurse for next column, and then backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, int n, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiag, vector&lt;int&gt;&amp; lowerDiag, int&amp; count) {&#10;    if(col == n) {&#10;        count++;&#10;        return;&#10;    }&#10;    for(int row = 0; row &lt; n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;int totalNQueens(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, leftRow, upperDiag, lowerDiag, count);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Rec 18 Word Search<br><br></b> <a href="https://leetcode.com/problems/word-search/" target="_blank">LeetCode 79</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Backtracking DFS.</td>
      <td><b>Time:</b> O(N * M * 4^L)<br><b>Space:</b> O(L) recursion stack</td>
      <td><b>Explanation:</b> Start DFS from each cell that matches the first letter of the word. In DFS, check 4 neighbors. Mark current cell as visited (e.g. change to '#') before moving to neighbors, and unmark (backtrack) after exploring.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(vector&lt;vector&lt;char&gt;&gt;&amp; board, int i, int j, string&amp; word, int idx) {&#10;    if(idx == word.length()) return true;&#10;    if(i &lt; 0 || i &gt;= board.size() || j &lt; 0 || j &gt;= board[0].size() || board[i][j] != word[idx]) return false;&#10;    char temp = board[i][j];&#10;    board[i][j] = &#x27;#&#x27;;&#10;    bool found = dfs(board, i+1, j, word, idx+1) ||&#10;                 dfs(board, i-1, j, word, idx+1) ||&#10;                 dfs(board, i, j+1, word, idx+1) ||&#10;                 dfs(board, i, j-1, word, idx+1);&#10;    board[i][j] = temp;&#10;    return found;&#10;}&#10;bool exist(vector&lt;vector&lt;char&gt;&gt;&amp; board, string word) {&#10;    for(int i = 0; i &lt; board.size(); i++) {&#10;        for(int j = 0; j &lt; board[0].size(); j++) {&#10;            if(board[i][j] == word[0] &amp;&amp; dfs(board, i, j, word, 0)) return true;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Rec 19 K Th Symbol In Grammar<br><br></b> <a href="https://leetcode.com/problems/k-th-symbol-in-grammar/" target="_blank">LeetCode 779</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Recursive division.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Row N has length 2^(N-1). The first half of row N is exactly same as row N-1. The second half of row N is the complement of row N-1. If k is in the first half (k <= mid), return solve(N-1, k). If k is in the second half, return !solve(N-1, k - mid).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthGrammar(int n, int k) {&#10;    if(n == 1 &amp;&amp; k == 1) return 0;&#10;    int mid = pow(2, n - 2);&#10;    if(k &lt;= mid) {&#10;        return kthGrammar(n - 1, k);&#10;    } else {&#10;        return !kthGrammar(n - 1, k - mid);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Rec 20 Beautiful Arrangement<br><br></b> <a href="https://leetcode.com/problems/beautiful-arrangement/" target="_blank">LeetCode 526</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(K) where K is number of valid permutations<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use an array to track visited numbers. Iterate from index 1 to n. For the current index, try placing an unvisited number. Check if the condition `(num % idx == 0 || idx % num == 0)` is met. If so, mark as visited, recurse to `idx + 1`, then backtrack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countArrangement(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; visited(n + 1, 0);&#10;    function&lt;void(int)&gt; solve = [&amp;](int idx) {&#10;        if(idx &gt; n) {&#10;            count++;&#10;            return;&#10;        }&#10;        for(int i = 1; i &lt;= n; i++) {&#10;            if(!visited[i] &amp;&amp; (i % idx == 0 || idx % i == 0)) {&#10;                visited[i] = 1;&#10;                solve(idx + 1);&#10;                visited[i] = 0;&#10;            }&#10;        }&#10;    };&#10;    solve(1);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Rec 21 Print All Permutations Of A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Convert string to char array and sort it. Use backtracking: pass a boolean visited array and a temporary string. If temporary string length equals original length, add to answer. Else, iterate through characters. To avoid duplicates, if `i > 0` and `s[i] == s[i-1]` and `!vis[i-1]`, skip. Otherwise, mark visited, append, recurse, unmark, pop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string&amp; S, vector&lt;bool&gt;&amp; vis, string&amp; curr, vector&lt;string&gt;&amp; ans) {&#10;    if(curr.length() == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(vis[i] || (i &gt; 0 &amp;&amp; S[i] == S[i-1] &amp;&amp; !vis[i-1])) continue;&#10;        vis[i] = true;&#10;        curr.push_back(S[i]);&#10;        solve(S, vis, curr, ans);&#10;        curr.pop_back();&#10;        vis[i] = false;&#10;    }&#10;}&#10;vector&lt;string&gt; find_permutation(string S) {&#10;    sort(S.begin(), S.end());&#10;    vector&lt;string&gt; ans;&#10;    string curr = &quot;&quot;;&#10;    vector&lt;bool&gt; vis(S.length(), false);&#10;    solve(S, vis, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Rec 22 Find All Possible Palindromic Partitions Of A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Iterate through the string. Extract substring `S[ind..i]`. If it is a palindrome, add it to the current partition list and recursively call for `i+1`. When `ind == length`, push the partition list to the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPal(string&amp; s) {&#10;    int i = 0, j = s.length() - 1;&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;void solve(string&amp; S, int ind, vector&lt;string&gt;&amp; curr, vector&lt;vector&lt;string&gt;&gt;&amp; ans) {&#10;    if(ind == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; S.length(); i++) {&#10;        string sub = S.substr(ind, i - ind + 1);&#10;        if(isPal(sub)) {&#10;            curr.push_back(sub);&#10;            solve(S, i + 1, curr, ans);&#10;            curr.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; allPalindromicPerms(string S) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; curr;&#10;    solve(S, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Rec 23 Print 1 To N Without Loop<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a recursive function. Call `f(N-1)` first and then print `N`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printTillN(int N) {&#10;    if(N == 0) return;&#10;    printTillN(N - 1);&#10;    cout &lt;&lt; N &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Rec 24 Print N To 1 Without Loop<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-n-to-1-without-loop/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a recursive function. Print `N` first and then call `f(N-1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printNos(int N) {&#10;    if(N == 0) return;&#10;    cout &lt;&lt; N &lt;&lt; &quot; &quot;;&#10;    printNos(N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Rec 25 Sum Of First N Terms<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Math or Recursion.</td>
      <td><b>Time:</b> O(1) Math, O(N) Recursion<br><b>Space:</b> O(1) Math, O(N) Recursion</td>
      <td><b>Explanation:</b> The mathematical formula for the sum of cubes is `(n * (n + 1) / 2)^2`. Alternatively, use recursion `f(n) = n^3 + f(n-1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long sumOfSeries(long long n) {&#10;    return (n * (n + 1) / 2) * (n * (n + 1) / 2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Rec 26 Find All Factorial Numbers Less Than Or Equal To N<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(K) where K! <= N<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a current factorial value and an index `i`. At each recursive step, compute the next factorial by multiplying by `i`. If the next factorial is `<= n`, add it to the list and recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findFactorials(long long n, long long i, long long fact, vector&lt;long long&gt;&amp; ans) {&#10;    if(fact &gt; n) return;&#10;    ans.push_back(fact);&#10;    findFactorials(n, i + 1, fact * (i + 1), ans);&#10;}&#10;vector&lt;long long&gt; factorialNumbers(long long N) {&#10;    vector&lt;long long&gt; ans;&#10;    findFactorials(N, 1, 1, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Rec 27 Reverse An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-an-array/0" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Recursion with two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) recursive stack</td>
      <td><b>Explanation:</b> Swap `arr[l]` and `arr[r]` and then recursively call `reverse(arr, l+1, r-1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void reverseArray(vector&lt;int&gt;&amp; arr, int l, int r) {&#10;    if(l &gt;= r) return;&#10;    swap(arr[l], arr[r]);&#10;    reverseArray(arr, l + 1, r - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Rec 28 Fibonacci Number<br><br></b> <a href="https://leetcode.com/problems/fibonacci-number/" target="_blank">LeetCode 509</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Base Case.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Return `fib(n-1) + fib(n-2)` with base cases `fib(0) = 0`, `fib(1) = 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int fib(int n) {&#10;    if(n &lt;= 1) return n;&#10;    return fib(n - 1) + fib(n - 2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Rec 29 Count Good Numbers<br><br></b> <a href="https://leetcode.com/problems/count-good-numbers/" target="_blank">LeetCode 1922</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Modular Exponentiation.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> There are 5 even digits and 4 prime digits. At even indices we have 5 choices. At odd indices we have 4 choices. If `n` is even, we have `n/2` even indices and `n/2` odd indices. So answer is `(5^(n/2) * 4^(n/2)) % mod`. If `n` is odd, we have `n/2 + 1` even indices. So answer is `(5^(n/2 + 1) * 4^(n/2)) % mod`. Use binary exponentiation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long power(long long x, long long y) {&#10;    long long res = 1;&#10;    long long mod = 1e9 + 7;&#10;    x = x % mod;&#10;    while(y &gt; 0) {&#10;        if(y % 2 == 1) res = (res * x) % mod;&#10;        y = y / 2;&#10;        x = (x * x) % mod;&#10;    }&#10;    return res;&#10;}&#10;int countGoodNumbers(long long n) {&#10;    long long mod = 1e9 + 7;&#10;    long long evenIndices = (n + 1) / 2;&#10;    long long oddIndices = n / 2;&#10;    return (power(5, evenIndices) * power(4, oddIndices)) % mod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Rec 30 Sort A Stack Using Recursion<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sort-a-stack/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Recursive sort and insert.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Recursively pop elements until the stack is empty. When returning from the recursive call, use another recursive function `sortedInsert` to insert the popped element into its correct sorted position in the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortedInsert(stack&lt;int&gt;&amp; s, int element) {&#10;    if(s.empty() || element &gt; s.top()) {&#10;        s.push(element);&#10;        return;&#10;    }&#10;    int num = s.top();&#10;    s.pop();&#10;    sortedInsert(s, element);&#10;    s.push(num);&#10;}&#10;void sortStack(stack&lt;int&gt;&amp; s) {&#10;    if(s.empty()) return;&#10;    int num = s.top();&#10;    s.pop();&#10;    sortStack(s);&#10;    sortedInsert(s, num);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
