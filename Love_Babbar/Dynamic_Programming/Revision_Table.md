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
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Dp 06 Maximum Product Subarray<br><br></b> <a href='https://leetcode.com/problems/maximum-product-subarray/' target='_blank'>LeetCode 152</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [2,3,-2,4], Output: 6 ([2,3])</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::max</code></td>
      <td><b>Zero Element:</b> A zero resets the contiguous product segment. We restart the prefix/suffix product from `1`.</td>
      <td><b>Explanation:</b> Prefix and Suffix product approach. Calculate product from left to right and right to left. Reset product to 1 when a zero is encountered.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProduct(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_prod = INT_MIN, n = nums.size();&#10;    int pref = 1, suff = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= nums[i];&#10;        suff *= nums[n - 1 - i];&#10;        max_prod = std::max({max_prod, pref, suff});&#10;    }&#10;    return max_prod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Dp 06 Longest Increasing Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-increasing-subsequence/' target='_blank'>LeetCode 300</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [10,9,2,5,3,7,101,18], Output: 4 (LIS is [2,3,7,101])</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Empty Array:</b> Handled appropriately.</td>
      <td><b>Explanation:</b> Create a dp array where dp[i] is the length of LIS ending at index i. For each i, check all j < i to see if nums[i] > nums[j] and update dp[i] = max(dp[i], dp[j] + 1). O(N log N) patience sorting approach is better but standard DP is O(N^2).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return 0;&#10;    vector&lt;int&gt; dp(nums.size(), 1);&#10;    int res = 1;&#10;    for(int i = 1; i &lt; nums.size(); ++i) {&#10;        for(int j = 0; j &lt; i; ++j) {&#10;            if(nums[i] &gt; nums[j]) dp[i] = std::max(dp[i], dp[j] + 1);&#10;        }&#10;        res = std::max(res, dp[i]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Dp 07 Coin Change<br><br></b> <a href='https://leetcode.com/problems/coin-change/' target='_blank'>LeetCode 322</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: coins = [1,2,5], amount = 11, Output: 3 (5+5+1)</td>
      <td><b>Time:</b> O(amount * N)<br><b>Space:</b> O(amount)</td>
      <td>-</td>
      <td><b>Cannot make amount:</b> Check if dp[amount] > amount, return -1.</td>
      <td><b>Explanation:</b> Bottom-up DP. dp[i] = min coins for amount i. Initialize dp array with amount + 1. dp[i] = min(dp[i], dp[i - coin] + 1).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int coinChange(vector&lt;int&gt;&amp; coins, int amount) {&#10;    vector&lt;int&gt; dp(amount + 1, amount + 1);&#10;    dp[0] = 0;&#10;    for(int i = 1; i &lt;= amount; ++i) {&#10;        for(int coin : coins) {&#10;            if(i - coin &gt;= 0) dp[i] = std::min(dp[i], dp[i - coin] + 1);&#10;        }&#10;    }&#10;    return dp[amount] &gt; amount ? -1 : dp[amount];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Dp 08 01 Knapsack<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=3, W=4, values[]={1,2,3}, weight[]={4,5,1}, Output: 3</td>
      <td><b>Time:</b> O(N * W)<br><b>Space:</b> O(W)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 2D DP or 1D array space-optimized DP. Check take and not-take scenarios.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int knapSack(int W, int wt[], int val[], int n) {&#10;    vector&lt;int&gt; prev(W + 1, 0);&#10;    for(int w = wt[0]; w &lt;= W; w++) prev[w] = val[0];&#10;    for(int ind = 1; ind &lt; n; ind++) {&#10;        for(int w = W; w &gt;= 0; w--) {&#10;            int notTake = prev[w];&#10;            int take = INT_MIN;&#10;            if(wt[ind] &lt;= w) take = val[ind] + prev[w - wt[ind]];&#10;            prev[w] = max(take, notTake);&#10;        }&#10;    }&#10;    return prev[W];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Dp 09 Longest Common Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-common-subsequence/' target='_blank'>LeetCode 1143</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: text1 = 'abcde', text2 = 'ace', Output: 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 2D DP. If match, 1 + dp[i-1][j-1]. If not match, max(dp[i-1][j], dp[i][j-1]).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubsequence(string text1, string text2) {&#10;    int n = text1.size(), m = text2.size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n+1, vector&lt;int&gt;(m+1, 0));&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];&#10;            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Dp 10 Edit Distance<br><br></b> <a href='https://leetcode.com/problems/edit-distance/' target='_blank'>LeetCode 72</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: word1 = 'horse', word2 = 'ros', Output: 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td><b>Empty Strings:</b> Deletions/insertions equal to length.</td>
      <td><b>Explanation:</b> 2D DP. If chars match, dp[i-1][j-1]. Else, 1 + min(insert, delete, replace).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDistance(string word1, string word2) {&#10;    int n = word1.size(), m = word2.size();&#10;    vector&lt;int&gt; prev(m+1, 0), cur(m+1, 0);&#10;    for(int j=0; j&lt;=m; j++) prev[j] = j;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        cur[0] = i;&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];&#10;            else cur[j] = 1 + min({prev[j], cur[j-1], prev[j-1]});&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
