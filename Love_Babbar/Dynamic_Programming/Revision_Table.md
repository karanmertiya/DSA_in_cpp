# Dynamic Programming Revision Table

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
      <td rowspan="1">Dp 01 Climbing Stairs<br><br></b> <a href='https://leetcode.com/problems/climbing-stairs/' target='_blank'>LeetCode 70</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: n = 3, Output: 3 (1+1+1, 1+2, 2+1)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Variable Swapping:</b> `prev2` becomes `prev`, and `prev` becomes the new `curr`.</td>
      <td><b>Explanation:</b> Space Optimization (Bottom-Up): Since state `n` only depends on `n-1` and `n-2`, we only need two variables.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int climbStairs(int n) {&#10;    if (n &lt;= 1) return 1;&#10;    int prev2 = 1, prev = 1;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        int curr = prev + prev2;&#10;        prev2 = prev;&#10;        prev = curr;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Dp 02 Longest Common Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-common-subsequence/' target='_blank'>LeetCode 1143</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: text1 = "abcde", text2 = "ace", Output: 3 ("ace")</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Trade-off)</td>
      <td><code>std::max</code></td>
      <td><b>1-Based Indexing:</b> Shifting indices by 1 prevents out-of-bounds checks and elegantly handles the 0-length prefix base case.</td>
      <td><b>Explanation:</b> Tabulation (Bottom-Up). Use a 2D array where `dp[i][j]` represents the LCS of prefixes of length `i` and `j`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;int longestCommonSubsequence(std::string text1, std::string text2) {&#10;    int n = text1.length(), m = text2.length();&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; dp(n + 1, std::vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];&#10;            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Dp 03 Coin Change<br><br></b> <a href='https://leetcode.com/problems/coin-change/' target='_blank'>LeetCode 322</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: coins = [1,2,5], amount = 11, Output: 3 (5+5+1)</td>
      <td><b>Time:</b> O(Amount * N)<br><b>Space:</b> O(Amount)</td>
      <td><code>std::min</code></td>
      <td><b>Initialization:</b> Fill array with `Amount + 1` (acting as infinity). If `dp[Amount]` remains `Amount + 1`, return `-1`.</td>
      <td><b>Explanation:</b> Unbounded Knapsack. State `dp[i]` is the min coins needed to make amount `i`. `dp[i] = min(dp[i], 1 + dp[i - coin])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;int coinChange(std::vector&lt;int&gt;&amp; coins, int amount) {&#10;    std::vector&lt;int&gt; dp(amount + 1, amount + 1);&#10;    dp[0] = 0;&#10;    for(int i = 1; i &lt;= amount; i++) {&#10;        for(int coin : coins) {&#10;            if(i - coin &gt;= 0) {&#10;                dp[i] = std::min(dp[i], 1 + dp[i - coin]);&#10;            }&#10;        }&#10;    }&#10;    return dp[amount] &gt; amount ? -1 : dp[amount];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Dp 04 Longest Increasing Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-increasing-subsequence/' target='_blank'>LeetCode 300</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [10,9,2,5,3,7,101,18], Output: 4 ([2,3,7,101])</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><code>std::lower_bound</code> / <code>bisect_left</code></td>
      <td><b>Temp Array:</b> `temp` does NOT store the actual LIS, but its length correctly represents the LIS length.</td>
      <td><b>Explanation:</b> Binary Search Patience Sorting method. Maintain a `temp` array. If current element is larger than `temp.back()`, append. Else, replace the first element >= current.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;int lengthOfLIS(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; temp;&#10;    for(int num : nums) {&#10;        auto it = std::lower_bound(temp.begin(), temp.end(), num);&#10;        if(it == temp.end()) temp.push_back(num);&#10;        else *it = num;&#10;    }&#10;    return temp.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Dp 05 House Robber<br><br></b> <a href='https://leetcode.com/problems/house-robber/' target='_blank'>LeetCode 198</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,2,3,1], Output: 4 (Rob house 1 and 3)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::max</code></td>
      <td><b>Array length < 2:</b> Automatically handled if initialized properly and loop condition ensures no out-of-bounds.</td>
      <td><b>Explanation:</b> Space Optimized DP. Maintain two variables: `prev1` (max up to previous house) and `prev2` (max up to the house before previous). `curr = max(num + prev2, prev1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int rob(std::vector&lt;int&gt;&amp; nums) {&#10;    int prev1 = 0, prev2 = 0;&#10;    for(int num : nums) {&#10;        int curr = std::max(num + prev2, prev1);&#10;        prev2 = prev1;&#10;        prev1 = curr;&#10;    }&#10;    return prev1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
