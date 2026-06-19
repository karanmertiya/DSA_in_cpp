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
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Dp 11 Matrix Chain Multiplication<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=5, arr=[40, 20, 30, 10, 30], Output: 26000</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td><code>#include <vector></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Partition DP. Try partitioning the matrices at every possible split `k` between `i` and `j`. Cost is `arr[i-1]*arr[k]*arr[j]`. Take the minimum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int f(int i, int j, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; dp) {&#10;    if(i == j) return 0;&#10;    if(dp[i][j] != -1) return dp[i][j];&#10;    int mini = 1e9;&#10;    for(int k=i; k&lt;j; k++) {&#10;        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);&#10;        mini = min(mini, steps);&#10;    }&#10;    return dp[i][j] = mini;&#10;}&#10;int matrixMultiplication(int N, vector&lt;int&gt;&amp; arr) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, -1));&#10;    return f(1, N-1, arr, dp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Dp 12 Subset Sum Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: set=[3,34,4,12,5,2], sum=9, Output: True</td>
      <td><b>Time:</b> O(N * Sum)<br><b>Space:</b> O(Sum) space optimized</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSubsetSum(vector&lt;int&gt;arr, int sum) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; prev(sum+1, false), cur(sum+1, false);&#10;    prev[0] = cur[0] = true;&#10;    if(arr[0] &lt;= sum) prev[arr[0]] = true;&#10;    for(int ind=1; ind&lt;n; ind++) {&#10;        for(int target=1; target&lt;=sum; target++) {&#10;            bool notTaken = prev[target];&#10;            bool taken = false;&#10;            if(arr[ind] &lt;= target) taken = prev[target - arr[ind]];&#10;            cur[target] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Dp 13 Word Break<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s='leetcode', wordDict=['leet', 'code'], Output: true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> 1D DP array. `dp[i]` is true if string up to index `i` can be broken. Loop `i` from 1 to N, loop `j` from 0 to i. If `dp[j]` is true and `s[j...i]` is in dict, then `dp[i] = true`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.size();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(s.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true; break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Dp 14 Longest Common Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-common-subsequence/' target='_blank'>LeetCode 1143</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: text1 = 'abcde', text2 = 'ace', Output: 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 2D DP. If characters match, `dp[i][j] = 1 + dp[i-1][j-1]`. If they don't, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`. Can be space optimized to two 1D arrays.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubsequence(string text1, string text2) {&#10;    int n = text1.size(), m = text2.size();&#10;    vector&lt;int&gt; prev(m+1, 0), cur(m+1, 0);&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];&#10;            else cur[j] = max(prev[j], cur[j-1]);&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Dp 15 Longest Increasing Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-increasing-subsequence/' target='_blank'>LeetCode 300</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [10,9,2,5,3,7,101,18], Output: 4</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary Search approach. Maintain an array `temp` of the increasing sequence. If `nums[i] > temp.back()`, append it. Else, find the lower bound of `nums[i]` in `temp` and replace it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;int&gt; temp;&#10;    temp.push_back(nums[0]);&#10;    for(int i=1; i&lt;nums.size(); i++) {&#10;        if(nums[i] &gt; temp.back()) temp.push_back(nums[i]);&#10;        else {&#10;            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();&#10;            temp[ind] = nums[i];&#10;        }&#10;    }&#10;    return temp.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Dp 16 Edit Distance<br><br></b> <a href='https://leetcode.com/problems/edit-distance/' target='_blank'>LeetCode 72</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: word1 = 'horse', word2 = 'ros', Output: 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If chars match, move both pointers. Else, try all 3 ops: 1 + min(insert(i, j-1), delete(i-1, j), replace(i-1, j-1)). Space optimized to 1D.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDistance(string word1, string word2) {&#10;    int n = word1.size(), m = word2.size();&#10;    vector&lt;int&gt; prev(m+1, 0), cur(m+1, 0);&#10;    for(int j=0; j&lt;=m; j++) prev[j] = j;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        cur[0] = i;&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];&#10;            else cur[j] = 1 + min({prev[j-1], prev[j], cur[j-1]});&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Dp 17 Coin Change<br><br></b> <a href='https://leetcode.com/problems/coin-change/' target='_blank'>LeetCode 322</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: coins = [1,2,5], amount = 11, Output: 3</td>
      <td><b>Time:</b> O(N * Amount)<br><b>Space:</b> O(Amount)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Unbounded Knapsack variant. State `dp[amount]` stores min coins. Iterate through coins, and for each amount from `coin` to `target`, `dp[amt] = min(dp[amt], 1 + dp[amt - coin])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int coinChange(vector&lt;int&gt;&amp; coins, int amount) {&#10;    vector&lt;int&gt; dp(amount + 1, 1e9);&#10;    dp[0] = 0;&#10;    for(int i=0; i&lt;coins.size(); i++) {&#10;        for(int amt=coins[i]; amt&lt;=amount; amt++) {&#10;            dp[amt] = min(dp[amt], 1 + dp[amt - coins[i]]);&#10;        }&#10;    }&#10;    return dp[amount] &gt;= 1e9 ? -1 : dp[amount];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Dp 18 Minimum Path Sum<br><br></b> <a href='https://leetcode.com/problems/minimum-path-sum/' target='_blank'>LeetCode 64</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: grid = [[1,3,1],[1,5,1],[4,2,1]], Output: 7</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DP on Grids. Space optimize to 1D. `cur[j] = grid[i][j] + min(up, left)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;int&gt; prev(m, 0);&#10;    for(int i=0; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(m, 0);&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(i==0 &amp;&amp; j==0) cur[j] = grid[i][j];&#10;            else {&#10;                int up = grid[i][j], left = grid[i][j];&#10;                if(i&gt;0) up += prev[j]; else up += 1e9;&#10;                if(j&gt;0) left += cur[j-1]; else left += 1e9;&#10;                cur[j] = min(up, left);&#10;            }&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Dp 19 Triangle<br><br></b> <a href='https://leetcode.com/problems/triangle/' target='_blank'>LeetCode 120</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: 11</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start from bottom row and move upwards. `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumTotal(vector&lt;vector&lt;int&gt;&gt;&amp; triangle) {&#10;    int n = triangle.size();&#10;    vector&lt;int&gt; front = triangle[n-1];&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=i; j&gt;=0; j--) {&#10;            cur[j] = triangle[i][j] + min(front[j], front[j+1]);&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Dp 20 Minimum Falling Path Sum<br><br></b> <a href='https://leetcode.com/problems/minimum-falling-path-sum/' target='_blank'>LeetCode 931</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: 13</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to minimum path sum, but we can fall diagonally. Space optimize by using previous row.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFallingPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    vector&lt;int&gt; prev = matrix[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=0; j&lt;n; j++) {&#10;            int up = matrix[i][j] + prev[j];&#10;            int ld = matrix[i][j] + (j&gt;0 ? prev[j-1] : 1e9);&#10;            int rd = matrix[i][j] + (j&lt;n-1 ? prev[j+1] : 1e9);&#10;            cur[j] = min({up, ld, rd});&#10;        }&#10;        prev = cur;&#10;    }&#10;    int mini = 1e9;&#10;    for(int j=0; j&lt;n; j++) mini = min(mini, prev[j]);&#10;    return mini;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Dp 21 Cherry Pickup Ii<br><br></b> <a href='https://leetcode.com/problems/cherry-pickup-ii/' target='_blank'>LeetCode 1463</a></td>
      <td rowspan="1"><b>Example 1:</b> 3D DP.</td>
      <td><b>Time:</b> O(N * M * M * 9)<br><b>Space:</b> O(M * M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Robots move simultaneously. State is `dp[row][col1][col2]`. Try all 9 combinations of moves for both robots.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int cherryPickup(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; front(m, vector&lt;int&gt;(m, 0)), cur(m, vector&lt;int&gt;(m, 0));&#10;    for(int j1=0; j1&lt;m; j1++) {&#10;        for(int j2=0; j2&lt;m; j2++) {&#10;            if(j1 == j2) front[j1][j2] = grid[n-1][j1];&#10;            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];&#10;        }&#10;    }&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        for(int j1=0; j1&lt;m; j1++) {&#10;            for(int j2=0; j2&lt;m; j2++) {&#10;                int maxi = -1e9;&#10;                for(int dj1=-1; dj1&lt;=1; dj1++) {&#10;                    for(int dj2=-1; dj2&lt;=1; dj2++) {&#10;                        int val = 0;&#10;                        if(j1 == j2) val = grid[i][j1];&#10;                        else val = grid[i][j1] + grid[i][j2];&#10;                        if(j1+dj1&gt;=0 &amp;&amp; j1+dj1&lt;m &amp;&amp; j2+dj2&gt;=0 &amp;&amp; j2+dj2&lt;m)&#10;                            val += front[j1+dj1][j2+dj2];&#10;                        else val += -1e9;&#10;                        maxi = max(maxi, val);&#10;                    }&#10;                }&#10;                cur[j1][j2] = maxi;&#10;            }&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0][m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Dp 22 Partition Equal Subset Sum<br><br></b> <a href='https://leetcode.com/problems/partition-equal-subset-sum/' target='_blank'>LeetCode 416</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: True.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total sum is odd, impossible. Else, find if there's a subset with sum `Total/2` using space-optimized DP.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canPartition(vector&lt;int&gt;&amp; nums) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum % 2 != 0) return false;&#10;    int target = sum / 2;&#10;    vector&lt;bool&gt; prev(target + 1, false);&#10;    prev[0] = true;&#10;    if(nums[0] &lt;= target) prev[nums[0]] = true;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;bool&gt; cur(target + 1, false);&#10;        cur[0] = true;&#10;        for(int t=1; t&lt;=target; t++) {&#10;            bool notTaken = prev[t];&#10;            bool taken = false;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[target];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Dp 23 Target Sum<br><br></b> <a href='https://leetcode.com/problems/target-sum/' target='_blank'>LeetCode 494</a></td>
      <td rowspan="1"><b>Example 1:</b> Count Subsets with Diff = target.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Subset sum variation. `S1 - S2 = target`, `S1 + S2 = totalSum`. So, `S1 = (target + totalSum) / 2`. Find subsets with this target sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTargetSumWays(vector&lt;int&gt;&amp; nums, int target) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum - target &lt; 0 || (sum - target) % 2 == 1) return 0;&#10;    int s2 = (sum - target) / 2;&#10;    vector&lt;int&gt; prev(s2 + 1, 0);&#10;    if(nums[0] == 0) prev[0] = 2;&#10;    else prev[0] = 1;&#10;    if(nums[0] != 0 &amp;&amp; nums[0] &lt;= s2) prev[nums[0]] = 1;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;int&gt; cur(s2 + 1, 0);&#10;        for(int t=0; t&lt;=s2; t++) {&#10;            int notTaken = prev[t];&#10;            int taken = 0;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken + taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[s2];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Dp 24 Burst Balloons<br><br></b> <a href='https://leetcode.com/problems/burst-balloons/' target='_blank'>LeetCode 312</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [3,1,5,8], Output: 167</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> MCM Pattern. Add 1 at the beginning and end. Loop lengths from 1 to N. Iterate start `i` and end `j`. Then iterate `k` from `i` to `j`, meaning balloon `k` is the LAST one to burst in the range `[i, j]`. The coins collected are `nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxCoins(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    nums.insert(nums.begin(), 1);&#10;    nums.push_back(1);&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 2, vector&lt;int&gt;(n + 2, 0));&#10;    for(int i=n; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=n; j++) {&#10;            if(i &gt; j) continue;&#10;            int maxi = INT_MIN;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];&#10;                maxi = max(maxi, cost);&#10;            }&#10;            dp[i][j] = maxi;&#10;        }&#10;    }&#10;    return dp[1][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Dp 25 Palindrome Partitioning Ii<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning-ii/' target='_blank'>LeetCode 132</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = 'aab', Output: 1</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Front Partitioning. `dp[i]` is the minimum cuts for `s[i...n-1]`. To compute `dp[i]`, iterate `j` from `i` to `n-1`. If `s[i...j]` is a palindrome, then `cost = 1 + dp[j+1]`. `dp[i]` is the minimum of these costs. Return `dp[0] - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string&amp; s, int i, int j) {&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;int minCut(string s) {&#10;    int n = s.length();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int minCuts = INT_MAX;&#10;        for(int j=i; j&lt;n; j++) {&#10;            if(isPalindrome(s, i, j)) {&#10;                int cost = 1 + dp[j+1];&#10;                minCuts = min(minCuts, cost);&#10;            }&#10;        }&#10;        dp[i] = minCuts;&#10;    }&#10;    return dp[0] - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Dp 26 Evaluate Boolean Expression To True<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> MCM DP pattern.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> MCM DP. `dp[i][j][isTrue]` stores the number of ways to evaluate `S[i..j]` to boolean `isTrue`. Iterate length, start, and partition `k`. Calculate T/F ways based on the operator at `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countWays(int N, string S){&#10;    int mod = 1003;&#10;    vector&lt;vector&lt;vector&lt;long long&gt;&gt;&gt; dp(N, vector&lt;vector&lt;long long&gt;&gt;(N, vector&lt;long long&gt;(2, 0)));&#10;    for(int i=N-1; i&gt;=0; i-=2) {&#10;        for(int j=i; j&lt;N; j+=2) {&#10;            if(i == j) {&#10;                dp[i][j][1] = (S[i] == &#x27;T&#x27;);&#10;                dp[i][j][0] = (S[i] == &#x27;F&#x27;);&#10;                continue;&#10;            }&#10;            long long waysT = 0, waysF = 0;&#10;            for(int k=i+1; k&lt;=j-1; k+=2) {&#10;                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];&#10;                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];&#10;                if(S[k] == &#x27;&amp;&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;|&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;^&#x27;) {&#10;                    waysT = (waysT + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rT) % mod + (lF * rF) % mod) % mod;&#10;                }&#10;            }&#10;            dp[i][j][1] = waysT;&#10;            dp[i][j][0] = waysF;&#10;        }&#10;    }&#10;    return dp[0][N-1][1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Dp 27 Maximum Rectangle Area With All 1S<br><br></b> <a href='https://leetcode.com/problems/maximal-rectangle/' target='_blank'>LeetCode 85</a></td>
      <td rowspan="1"><b>Example 1:</b> Calculate largest area.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a histogram for each row. The height of the histogram is the consecutive 1s ending at that cell. For each row's histogram, use the 'Largest Rectangle in Histogram' stack algorithm.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size();&#10;    stack&lt;int&gt; st;&#10;    int maxA = 0;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int h = heights[st.top()]; st.pop();&#10;            int w = st.empty() ? i : i - st.top() - 1;&#10;            maxA = max(maxA, h * w);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxA;&#10;}&#10;int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int maxArea = 0;&#10;    vector&lt;int&gt; heights(matrix[0].size(), 0);&#10;    for(int i=0; i&lt;matrix.size(); i++) {&#10;        for(int j=0; j&lt;matrix[0].size(); j++) {&#10;            if(matrix[i][j] == &#x27;1&#x27;) heights[j]++;&#10;            else heights[j] = 0;&#10;        }&#10;        maxArea = max(maxArea, largestRectangleArea(heights));&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Dp 28 Count Square Submatrices With All Ones<br><br></b> <a href='https://leetcode.com/problems/count-square-submatrices-with-all-ones/' target='_blank'>LeetCode 1277</a></td>
      <td rowspan="1"><b>Example 1:</b> Return total count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i][j]` is the size of the largest square ending at `(i, j)`. It also represents the number of squares ending at `(i, j)`. `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1` if `matrix[i][j] == 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSquares(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int sum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(matrix[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                sum += dp[i][j];&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Dp 29 Word Break Dp<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> `s = "leetcode"`. Output: `true`.</td>
      <td><b>Time:</b> O(N^2 * max_word_length)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i]` is true if `s[0..i-1]` can be segmented. For each `i`, iterate `j` from 0 to `i-1`. If `dp[j]` is true and `s[j..i-1]` is in dict, then `dp[i] = true`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=i-1; j&gt;=0; j--) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Dp 30 Matrix Chain Multiplication<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Minimize scalar multiplications.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Standard MCM DP. `dp[i][j]` is min cost to multiply matrices from `i` to `j`. Iterate length of chain, start `i`, and partition `k`. `dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int matrixMultiplication(int N, int arr[]) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, 0));&#10;    for(int i=N-1; i&gt;=1; i--) {&#10;        for(int j=i+1; j&lt;N; j++) {&#10;            int mini = 1e9;&#10;            for(int k=i; k&lt;j; k++) {&#10;                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];&#10;                mini = min(mini, cost);&#10;            }&#10;            dp[i][j] = mini;&#10;        }&#10;    }&#10;    return dp[1][N-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Dp 31 Minimum Cost To Cut A Stick<br><br></b> <a href='https://leetcode.com/problems/minimum-cost-to-cut-a-stick/' target='_blank'>LeetCode 1547</a></td>
      <td rowspan="1"><b>Example 1:</b> Cost depends on current stick length.</td>
      <td><b>Time:</b> O(C^3) where C is number of cuts<br><b>Space:</b> O(C^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort cuts array and prepend 0, append `n`. Use MCM pattern. `dp[i][j]` is the minimum cost to cut the stick between cuts `i` and `j`. `dp[i][j] = min(cost + cuts[j+1] - cuts[i-1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minCost(int n, vector&lt;int&gt;&amp; cuts) {&#10;    cuts.push_back(0);&#10;    cuts.push_back(n);&#10;    sort(cuts.begin(), cuts.end());&#10;    int c = cuts.size() - 2;&#10;    vector&lt;vector&lt;int&gt;&gt; dp(c + 2, vector&lt;int&gt;(c + 2, 0));&#10;    for(int i=c; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=c; j++) {&#10;            if(i &gt; j) continue;&#10;            int mini = INT_MAX;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];&#10;                mini = min(mini, cost);&#10;            }&#10;            dp[i][j] = mini;&#10;        }&#10;    }&#10;    return dp[1][c];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Dp 32 Partition Array For Maximum Sum<br><br></b> <a href='https://leetcode.com/problems/partition-array-for-maximum-sum/' target='_blank'>LeetCode 1043</a></td>
      <td rowspan="1"><b>Example 1:</b> Front partitioning DP.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Front partitioning. `dp[i]` is max sum for `arr[i..n-1]`. For each `i`, iterate `j` up to `i+k-1`. Find `maxi` element in this window, and add `maxi * length + dp[j+1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumAfterPartitioning(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int max_val = 0;&#10;        int max_ans = 0;&#10;        int len = 0;&#10;        for(int j=i; j&lt;min(n, i + k); j++) {&#10;            len++;&#10;            max_val = max(max_val, arr[j]);&#10;            int sum = max_val * len + dp[j+1];&#10;            max_ans = max(max_ans, sum);&#10;        }&#10;        dp[i] = max_ans;&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Dp 33 Distinct Subsequences<br><br></b> <a href='https://leetcode.com/problems/distinct-subsequences/' target='_blank'>LeetCode 115</a></td>
      <td rowspan="1"><b>Example 1:</b> Subsequence match count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td><b>Integer Overflow:</b> Use double or long long, or cast to unsigned int.</td>
      <td><b>Explanation:</b> If characters match, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`. If they don't, `dp[i][j] = dp[i-1][j]`. Optimize to 1D array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numDistinct(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;double&gt; dp(m + 1, 0);&#10;    dp[0] = 1;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=m; j&gt;=1; j--) {&#10;            if(s[i-1] == t[j-1]) {&#10;                dp[j] = dp[j-1] + dp[j];&#10;            }&#10;        }&#10;    }&#10;    return (int)dp[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Dp 34 Wildcard Matching<br><br></b> <a href='https://leetcode.com/problems/wildcard-matching/' target='_blank'>LeetCode 44</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a 2D DP array where `dp[i][j]` means if `s[0..i-1]` matches `p[0..j-1]`. If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, `dp[i][j] = dp[i-1][j-1]`. If `p[j-1] == '*'`, it can match empty (`dp[i][j-1]`) or match one character (`dp[i-1][j]`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isMatch(string s, string p) {&#10;    int n = s.length(), m = p.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; dp(n + 1, vector&lt;bool&gt;(m + 1, false));&#10;    dp[0][0] = true;&#10;    for(int j = 1; j &lt;= m; j++) {&#10;        if(p[j-1] == &#x27;*&#x27;) dp[0][j] = dp[0][j-1];&#10;    }&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(p[j-1] == s[i-1] || p[j-1] == &#x27;?&#x27;) {&#10;                dp[i][j] = dp[i-1][j-1];&#10;            } else if(p[j-1] == &#x27;*&#x27;) {&#10;                dp[i][j] = dp[i-1][j] || dp[i][j-1];&#10;            }&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Dp 35 Best Time To Buy And Sell Stock Ii<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/' target='_blank'>LeetCode 122</a></td>
      <td rowspan="1"><b>Example 1:</b> Valley Peak approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Add the profit whenever the price is higher than the previous day. This is equivalent to capturing every upward slope.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        if(prices[i] &gt; prices[i-1]) {&#10;            profit += prices[i] - prices[i-1];&#10;        }&#10;    }&#10;    return profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Dp 36 Best Time To Buy And Sell Stock Iii<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/' target='_blank'>LeetCode 123</a></td>
      <td rowspan="1"><b>Example 1:</b> 3D DP / State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain four variables representing the max profit after first buy, first sell, second buy, and second sell. Update them iteratively.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;&#10;    for(int price : prices) {&#10;        buy1 = max(buy1, -price);&#10;        sell1 = max(sell1, buy1 + price);&#10;        buy2 = max(buy2, sell1 - price);&#10;        sell2 = max(sell2, buy2 + price);&#10;    }&#10;    return sell2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Dp 37 Best Time To Buy And Sell Stock Iv<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/' target='_blank'>LeetCode 188</a></td>
      <td rowspan="1"><b>Example 1:</b> DP with transactions.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N * K) or O(K)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If `k >= n/2`, it's equivalent to infinite transactions (Stock II). Else, use a DP array `dp[k][n]` where `dp[i][j]` is max profit using `i` transactions up to day `j`. Optimize inner loop by tracking `maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j-1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(int k, vector&lt;int&gt;&amp; prices) {&#10;    int n = prices.size();&#10;    if(n &lt;= 1) return 0;&#10;    if(k &gt;= n / 2) {&#10;        int profit = 0;&#10;        for(int i = 1; i &lt; n; i++) {&#10;            if(prices[i] &gt; prices[i-1]) profit += prices[i] - prices[i-1];&#10;        }&#10;        return profit;&#10;    }&#10;    vector&lt;int&gt; buy(k + 1, INT_MIN), sell(k + 1, 0);&#10;    for(int price : prices) {&#10;        for(int i = 1; i &lt;= k; i++) {&#10;            buy[i] = max(buy[i], sell[i-1] - price);&#10;            sell[i] = max(sell[i], buy[i] + price);&#10;        }&#10;    }&#10;    return sell[k];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Dp 38 Best Time To Buy And Sell Stock With Cooldown<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/' target='_blank'>LeetCode 309</a></td>
      <td rowspan="1"><b>Example 1:</b> State Machine DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain 3 states: `hold` (holding a stock), `sold` (just sold, entering cooldown next), `rest` (not holding, not in cooldown). Transitions: `hold = max(hold, rest - price)`, `sold = hold + price`, `rest = max(rest, sold_prev)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int hold = INT_MIN, sold = 0, rest = 0;&#10;    for(int price : prices) {&#10;        int prev_sold = sold;&#10;        sold = hold + price;&#10;        hold = max(hold, rest - price);&#10;        rest = max(rest, prev_sold);&#10;    }&#10;    return max(rest, sold);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Dp 39 Best Time To Buy And Sell Stock With Transaction Fee<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/' target='_blank'>LeetCode 714</a></td>
      <td rowspan="1"><b>Example 1:</b> DP State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to Stock II, but subtract `fee` when selling. Maintain `cash` (max profit not holding stock) and `hold` (max profit holding stock). `cash = max(cash, hold + price - fee)`, `hold = max(hold, cash - price)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices, int fee) {&#10;    int cash = 0, hold = -prices[0];&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        cash = max(cash, hold + prices[i] - fee);&#10;        hold = max(hold, cash - prices[i]);&#10;    }&#10;    return cash;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Dp 40 Longest Increasing Subsequence<br><br></b> <a href='https://leetcode.com/problems/longest-increasing-subsequence/' target='_blank'>LeetCode 300</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary Search with tails array.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain an array `tails` where `tails[i]` stores the smallest tail of all increasing subsequences of length `i+1`. Use binary search (`lower_bound`) to find the position to replace or append.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;int&gt; tails;&#10;    for(int num : nums) {&#10;        auto it = lower_bound(tails.begin(), tails.end(), num);&#10;        if(it == tails.end()) tails.push_back(num);&#10;        else *it = num;&#10;    }&#10;    return tails.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Dp 41 Largest Divisible Subset<br><br></b> <a href='https://leetcode.com/problems/largest-divisible-subset/' target='_blank'>LeetCode 368</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and LIS variant.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Then use LIS logic: `dp[i]` is max subset ending at `i`. If `nums[i] % nums[j] == 0`, `dp[i] = max(dp[i], dp[j] + 1)`. Also keep a `parent` array to reconstruct the subset.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; largestDivisibleSubset(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return {};&#10;    sort(nums.begin(), nums.end());&#10;    int n = nums.size(), max_len = 1, max_idx = 0;&#10;    vector&lt;int&gt; dp(n, 1), parent(n, -1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] % nums[j] == 0 &amp;&amp; dp[i] &lt; dp[j] + 1) {&#10;                dp[i] = dp[j] + 1;&#10;                parent[i] = j;&#10;            }&#10;        }&#10;        if(dp[i] &gt; max_len) {&#10;            max_len = dp[i];&#10;            max_idx = i;&#10;        }&#10;    }&#10;    vector&lt;int&gt; res;&#10;    while(max_idx != -1) {&#10;        res.push_back(nums[max_idx]);&#10;        max_idx = parent[max_idx];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Dp 42 Longest String Chain<br><br></b> <a href='https://leetcode.com/problems/longest-string-chain/' target='_blank'>LeetCode 1048</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort by length and use hash map.</td>
      <td><b>Time:</b> O(N log N + N * L^2) where L is max word length<br><b>Space:</b> O(N * L)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Sort words by length. Use a hash map `dp` to store the longest chain ending at `word`. For each word, try removing one character at a time to form `prev_word`. `dp[word] = max(dp[word], dp[prev_word] + 1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestStrChain(vector&lt;string&gt;&amp; words) {&#10;    sort(words.begin(), words.end(), [](const string&amp; a, const string&amp; b) {&#10;        return a.length() &lt; b.length();&#10;    });&#10;    unordered_map&lt;string, int&gt; dp;&#10;    int max_len = 1;&#10;    for(const string&amp; word : words) {&#10;        dp[word] = 1;&#10;        for(int i = 0; i &lt; word.length(); i++) {&#10;            string prev = word.substr(0, i) + word.substr(i + 1);&#10;            if(dp.find(prev) != dp.end()) {&#10;                dp[word] = max(dp[word], dp[prev] + 1);&#10;            }&#10;        }&#10;        max_len = max(max_len, dp[word]);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Dp 43 Longest Bitonic Subsequence<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> LIS from left + LIS from right.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Compute LIS ending at `i` from left to right (`inc[i]`). Compute LIS starting at `i` from right to left (`dec[i]`). The max bitonic subsequence length is `max(inc[i] + dec[i] - 1)` for all `i`. Sometimes pure increasing or pure decreasing is also bitonic depending on definition, adjust if necessary.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestBitonicSequence(vector&lt;int&gt; nums) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; inc(n, 1), dec(n, 1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) inc[i] = max(inc[i], inc[j] + 1);&#10;        }&#10;    }&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        for(int j = n - 1; j &gt; i; j--) {&#10;            if(nums[i] &gt; nums[j]) dec[i] = max(dec[i], dec[j] + 1);&#10;        }&#10;    }&#10;    int max_len = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        // Depending on problem variant, might require both to be &gt; 1 to be valid peak&#10;        max_len = max(max_len, inc[i] + dec[i] - 1);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">Dp 44 Number Of Longest Increasing Subsequence<br><br></b> <a href='https://leetcode.com/problems/number-of-longest-increasing-subsequence/' target='_blank'>LeetCode 673</a></td>
      <td rowspan="1"><b>Example 1:</b> Two DP arrays (Length and Count).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `lengths[i]` (length of LIS ending at i) and `counts[i]` (number of LIS ending at i). If `nums[i] > nums[j]`: if `lengths[j] + 1 > lengths[i]`, then `lengths[i] = lengths[j] + 1` and `counts[i] = counts[j]`. Else if `lengths[j] + 1 == lengths[i]`, then `counts[i] += counts[j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findNumberOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), max_len = 0, res = 0;&#10;    vector&lt;int&gt; len(n, 1), count(n, 1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) {&#10;                if(len[j] + 1 &gt; len[i]) {&#10;                    len[i] = len[j] + 1;&#10;                    count[i] = count[j];&#10;                } else if(len[j] + 1 == len[i]) {&#10;                    count[i] += count[j];&#10;                }&#10;            }&#10;        }&#10;        if(len[i] &gt; max_len) {&#10;            max_len = len[i];&#10;            res = count[i];&#10;        } else if(len[i] == max_len) {&#10;            res += count[i];&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">Dp 45 Matrix Chain Multiplication<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Interval DP.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use DP where `dp[i][j]` is min cost to multiply matrices from `i` to `j`. `dp[i][j] = min(dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j])` for all `i <= k < j`. Solve for subproblem lengths 2 to N.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int matrixMultiplication(int N, int arr[]) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, 0));&#10;    for(int len = 2; len &lt; N; len++) {&#10;        for(int i = 1; i &lt; N - len + 1; i++) {&#10;            int j = i + len - 1;&#10;            dp[i][j] = INT_MAX;&#10;            for(int k = i; k &lt; j; k++) {&#10;                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];&#10;                dp[i][j] = min(dp[i][j], cost);&#10;            }&#10;        }&#10;    }&#10;    return dp[1][N-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">Dp 46 Minimum Cost To Cut A Stick<br><br></b> <a href='https://leetcode.com/problems/minimum-cost-to-cut-a-stick/' target='_blank'>LeetCode 1547</a></td>
      <td rowspan="1"><b>Example 1:</b> Interval DP like Matrix Chain Multiplication.</td>
      <td><b>Time:</b> O(C^3) where C is number of cuts<br><b>Space:</b> O(C^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Add 0 and `n` to `cuts`, then sort. `dp[i][j]` is min cost to cut the sub-stick between `cuts[i]` and `cuts[j]`. Try all possible cuts `k` between `i` and `j`. `dp[i][j] = min(dp[i][k] + dp[k][j]) + cuts[j] - cuts[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minCost(int n, vector&lt;int&gt;&amp; cuts) {&#10;    cuts.push_back(0);&#10;    cuts.push_back(n);&#10;    sort(cuts.begin(), cuts.end());&#10;    int c = cuts.size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(c, vector&lt;int&gt;(c, 0));&#10;    for(int len = 2; len &lt; c; len++) {&#10;        for(int i = 0; i &lt; c - len; i++) {&#10;            int j = i + len;&#10;            dp[i][j] = INT_MAX;&#10;            for(int k = i + 1; k &lt; j; k++) {&#10;                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);&#10;            }&#10;        }&#10;    }&#10;    return dp[0][c-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">Dp 47 Burst Balloons<br><br></b> <a href='https://leetcode.com/problems/burst-balloons/' target='_blank'>LeetCode 312</a></td>
      <td rowspan="1"><b>Example 1:</b> Interval DP (Thinking backwards).</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Add 1 to both ends of `nums`. `dp[i][j]` is max coins from bursting balloons strictly between `i` and `j`. Guess which balloon `k` (between `i` and `j`) is the LAST one to burst. Coins gained = `nums[i] * nums[k] * nums[j]`. Total = `dp[i][k] + dp[k][j] + coins`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxCoins(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;int&gt; a = {1};&#10;    for(int num : nums) a.push_back(num);&#10;    a.push_back(1);&#10;    int n = a.size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(n, 0));&#10;    for(int len = 2; len &lt; n; len++) {&#10;        for(int i = 0; i &lt; n - len; i++) {&#10;            int j = i + len;&#10;            for(int k = i + 1; k &lt; j; k++) {&#10;                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);&#10;            }&#10;        }&#10;    }&#10;    return dp[0][n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">49</td>
      <td rowspan="1">Dp 48 Evaluate Boolean Expression To True<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 3D Interval DP.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2 * 2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i][j][isTrue]` is number of ways to evaluate substring `i..j` to boolean `isTrue`. Iterate `k` from `i+1` to `j-1` with step 2 (k is operator). Combine left (`i..k-1`) and right (`k+1..j`) results based on the operator.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countWays(int n, string s){&#10;    vector&lt;vector&lt;vector&lt;int&gt;&gt;&gt; dp(n, vector&lt;vector&lt;int&gt;&gt;(n, vector&lt;int&gt;(2, 0)));&#10;    for(int i=0; i&lt;n; i+=2) {&#10;        if(s[i] == &#x27;T&#x27;) dp[i][i][1] = 1;&#10;        else dp[i][i][0] = 1;&#10;    }&#10;    for(int len=3; len&lt;=n; len+=2) {&#10;        for(int i=0; i&lt;=n-len; i+=2) {&#10;            int j = i + len - 1;&#10;            for(int k=i+1; k&lt;j; k+=2) {&#10;                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];&#10;                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];&#10;                if(s[k] == &#x27;&amp;&#x27;) {&#10;                    dp[i][j][1] = (dp[i][j][1] + lT * rT) % 1003;&#10;                    dp[i][j][0] = (dp[i][j][0] + lF * rT + lT * rF + lF * rF) % 1003;&#10;                } else if(s[k] == &#x27;|&#x27;) {&#10;                    dp[i][j][1] = (dp[i][j][1] + lT * rT + lF * rT + lT * rF) % 1003;&#10;                    dp[i][j][0] = (dp[i][j][0] + lF * rF) % 1003;&#10;                } else if(s[k] == &#x27;^&#x27;) {&#10;                    dp[i][j][1] = (dp[i][j][1] + lT * rF + lF * rT) % 1003;&#10;                    dp[i][j][0] = (dp[i][j][0] + lT * rT + lF * rF) % 1003;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return dp[0][n-1][1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">50</td>
      <td rowspan="1">Dp 49 Palindrome Partitioning Ii<br><br></b> <a href='https://leetcode.com/problems/palindrome-partitioning-ii/' target='_blank'>LeetCode 132</a></td>
      <td rowspan="1"><b>Example 1:</b> 1D DP using Precomputed Palindrome Table.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Precompute a 2D boolean array `isPal` indicating if `s[i..j]` is palindrome. Then use 1D DP `cuts[i]` indicating min cuts for `s[0..i]`. `cuts[i] = min(cuts[i], cuts[j-1] + 1)` for all `j <= i` where `isPal[j][i]` is true. If `isPal[0][i]` is true, `cuts[i] = 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minCut(string s) {&#10;    int n = s.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; isPal(n, vector&lt;bool&gt;(n, false));&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        for(int j = i; j &lt; n; j++) {&#10;            if(s[i] == s[j] &amp;&amp; (j - i &lt;= 2 || isPal[i+1][j-1])) {&#10;                isPal[i][j] = true;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; cuts(n, 0);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(isPal[0][i]) cuts[i] = 0;&#10;        else {&#10;            cuts[i] = i;&#10;            for(int j = 1; j &lt;= i; j++) {&#10;                if(isPal[j][i]) cuts[i] = min(cuts[i], cuts[j-1] + 1);&#10;            }&#10;        }&#10;    }&#10;    return cuts[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">51</td>
      <td rowspan="1">Dp 50 Partition Array For Maximum Sum<br><br></b> <a href='https://leetcode.com/problems/partition-array-for-maximum-sum/' target='_blank'>LeetCode 1043</a></td>
      <td rowspan="1"><b>Example 1:</b> 1D DP.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i]` is max sum for prefix of length `i`. To find `dp[i]`, try all partition lengths `j` from 1 to `k`. Keep track of `max_val` in the last `j` elements. `dp[i] = max(dp[i], dp[i-j] + max_val * j)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumAfterPartitioning(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        int max_val = 0;&#10;        for(int j = 1; j &lt;= k &amp;&amp; i - j &gt;= 0; j++) {&#10;            max_val = max(max_val, arr[i - j]);&#10;            dp[i] = max(dp[i], dp[i - j] + max_val * j);&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">52</td>
      <td rowspan="1">Dp 51 Maximal Rectangle<br><br></b> <a href='https://leetcode.com/problems/maximal-rectangle/' target='_blank'>LeetCode 85</a></td>
      <td rowspan="1"><b>Example 1:</b> DP to convert to Largest Rectangle in Histogram.</td>
      <td><b>Time:</b> O(R * C)<br><b>Space:</b> O(C)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Treat each row as the base of a histogram. Calculate heights for each row (`heights[j]++` if `matrix[i][j]=='1'`, else `0`). Then compute Largest Rectangle in Histogram for each row and take the maximum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int r = matrix.size(), c = matrix[0].size();&#10;    vector&lt;int&gt; heights(c, 0);&#10;    int maxArea = 0;&#10;    for(int i = 0; i &lt; r; i++) {&#10;        for(int j = 0; j &lt; c; j++) {&#10;            heights[j] = matrix[i][j] == &#x27;1&#x27; ? heights[j] + 1 : 0;&#10;        }&#10;        stack&lt;int&gt; st;&#10;        for(int j = 0; j &lt;= c; j++) {&#10;            int h = (j == c) ? 0 : heights[j];&#10;            while(!st.empty() &amp;&amp; h &lt; heights[st.top()]) {&#10;                int height = heights[st.top()]; st.pop();&#10;                int width = st.empty() ? j : j - st.top() - 1;&#10;                maxArea = max(maxArea, height * width);&#10;            }&#10;            st.push(j);&#10;        }&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">53</td>
      <td rowspan="1">Dp 52 Count Square Submatrices With All Ones<br><br></b> <a href='https://leetcode.com/problems/count-square-submatrices-with-all-ones/' target='_blank'>LeetCode 1277</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(R * C)<br><b>Space:</b> O(R * C) or O(C) optimized</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i][j]` represents the side length of the maximum square whose bottom-right corner is at `(i, j)`. If `matrix[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. The number of squares ending here is exactly `dp[i][j]`. Sum all `dp[i][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSquares(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int r = matrix.size(), c = matrix[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(r, vector&lt;int&gt;(c, 0));&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; r; i++) {&#10;        for(int j = 0; j &lt; c; j++) {&#10;            if(matrix[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                ans += dp[i][j];&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">54</td>
      <td rowspan="1">Dp 53 Word Break<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> 1D DP.</td>
      <td><b>Time:</b> O(N * M * L) or O(N^2)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i]` is true if `s[0..i-1]` can be segmented. For each `i` from 1 to `N`, try each word in dictionary. If `s[i-len(word)..i-1] == word` and `dp[i-len(word)]` is true, then `dp[i] = true`. Or iterate `j` from 0 to `i` and check if `dp[j]` is true and `s[j..i-1]` is in dict.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    vector&lt;bool&gt; dp(s.length() + 1, false);&#10;    dp[0] = true;&#10;    for(int i = 1; i &lt;= s.length(); i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(s.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[s.length()];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">55</td>
      <td rowspan="1">Dp 54 Count Palindromic Subsequences<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D Interval DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If `s[i] == s[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. If `s[i] != s[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int countPS(string str) {&#10;    int n = str.length();&#10;    long long int mod = 1e9 + 7;&#10;    vector&lt;vector&lt;long long int&gt;&gt; dp(n, vector&lt;long long int&gt;(n, 0));&#10;    for(int i = 0; i &lt; n; i++) dp[i][i] = 1;&#10;    for(int len = 2; len &lt;= n; len++) {&#10;        for(int i = 0; i &lt;= n - len; i++) {&#10;            int j = i + len - 1;&#10;            if(str[i] == str[j]) {&#10;                dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % mod;&#10;            } else {&#10;                dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + mod) % mod;&#10;            }&#10;        }&#10;    }&#10;    return dp[0][n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">56</td>
      <td rowspan="1">Dp 55 Longest Alternating Subsequence<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two state DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain two lengths: `up` (ending with ascending) and `down` (ending with descending). Iterate array: if `arr[i] > arr[i-1]`, `up = down + 1`. If `arr[i] < arr[i-1]`, `down = up + 1`. Return `max(up, down)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int AlternatingaMaxLength(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return 0;&#10;    int up = 1, down = 1;&#10;    for(int i = 1; i &lt; nums.size(); i++) {&#10;        if(nums[i] &gt; nums[i-1]) up = down + 1;&#10;        else if(nums[i] &lt; nums[i-1]) down = up + 1;&#10;    }&#10;    return max(up, down);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">57</td>
      <td rowspan="1">Dp 56 Largest Square Formed In A Matrix<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Bottom-up DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i][j]` is side of max square ending at `(i, j)`. If `mat[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. Result is max over all `dp[i][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSquare(int n, int m, vector&lt;vector&lt;int&gt;&gt; mat) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(mat[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                ans = max(ans, dp[i][j]);&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">58</td>
      <td rowspan="1">Dp 57 Pairs With Specific Difference<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and DP or Greedy.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Iterate from end. If `arr[i] - arr[i-1] < K`, we pair them, add sum to answer, and `i -= 2`. Else, `i -= 1`. Greedy approach works because pairing larger numbers gives a larger sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {&#10;    sort(arr, arr + N);&#10;    int ans = 0;&#10;    for(int i = N - 1; i &gt; 0; ) {&#10;        if(arr[i] - arr[i-1] &lt; K) {&#10;            ans += arr[i] + arr[i-1];&#10;            i -= 2;&#10;        } else {&#10;            i--;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">59</td>
      <td rowspan="1">Dp 58 Maximum Path Sum In Matrix<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start from bottom row up. `dp[i][j] = matrix[i][j] + max(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1])`. The answer is max value in `dp[0]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maximumPath(int N, vector&lt;vector&lt;int&gt;&gt; Matrix) {&#10;    vector&lt;int&gt; prev(N, 0), curr(N, 0);&#10;    for(int j = 0; j &lt; N; j++) prev[j] = Matrix[N-1][j];&#10;    for(int i = N - 2; i &gt;= 0; i--) {&#10;        for(int j = 0; j &lt; N; j++) {&#10;            int up = Matrix[i][j] + prev[j];&#10;            int ld = Matrix[i][j] + (j &gt; 0 ? prev[j-1] : 0);&#10;            int rd = Matrix[i][j] + (j &lt; N - 1 ? prev[j+1] : 0);&#10;            curr[j] = max({up, ld, rd});&#10;        }&#10;        prev = curr;&#10;    }&#10;    int ans = 0;&#10;    for(int j = 0; j &lt; N; j++) ans = max(ans, prev[j]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">60</td>
      <td rowspan="1">Dp 59 Maximum Difference Of Zeros And Ones In Binary String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Kadane's Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Convert '0' to 1 and '1' to -1. Find the maximum subarray sum using Kadane's algorithm. If max sum is negative, it means string has all 1s, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubstring(string S) {&#10;    int mx = INT_MIN, curr = 0;&#10;    for(char c : S) {&#10;        int val = c == &#x27;0&#x27; ? 1 : -1;&#10;        curr = max(val, curr + val);&#10;        mx = max(mx, curr);&#10;    }&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">61</td>
      <td rowspan="1">Dp 60 Minimum Number Of Jumps<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Greedy tracking bounds.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `maxReach`, `steps`, and `jumps`. At each step `i`, `maxReach = max(maxReach, i + arr[i])`. Decrement `steps`. If `steps == 0`, `jumps++` and `steps = maxReach - i`. If `i >= maxReach`, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minJumps(int arr[], int n) {&#10;    if(n &lt;= 1) return 0;&#10;    if(arr[0] == 0) return -1;&#10;    int maxReach = arr[0], steps = arr[0], jumps = 1;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(i == n - 1) return jumps;&#10;        maxReach = max(maxReach, i + arr[i]);&#10;        steps--;&#10;        if(steps == 0) {&#10;            jumps++;&#10;            if(i &gt;= maxReach) return -1;&#10;            steps = maxReach - i;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">62</td>
      <td rowspan="1">Dp 61 Minimum Removals From Array To Make Max Min K<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-removals3851/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP after sorting.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. We want to find the longest subarray `arr[i..j]` such that `arr[j] - arr[i] <= K`. `dp[i]` could store the max `j` for index `i`. Or use Binary Search (`upper_bound`) for each `i` to find the valid `j`, maximizing `j - i + 1`. Total removed = `N - max_length`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removals(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    sort(arr.begin(), arr.end());&#10;    int maxLen = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int j = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - 1;&#10;        maxLen = max(maxLen, j - i + 1);&#10;    }&#10;    return n - maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">63</td>
      <td rowspan="1">Dp 62 Longest Common Substring<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i][j]` is the length of longest common suffix of `S1[0..i-1]` and `S2[0..j-1]`. If `S1[i-1] == S2[j-1]`, `dp[i][j] = dp[i-1][j-1] + 1`. Else, `dp[i][j] = 0`. Max value in `dp` table is answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubstr(string S1, string S2, int n, int m) {&#10;    vector&lt;int&gt; prev(m + 1, 0), curr(m + 1, 0);&#10;    int ans = 0;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(S1[i-1] == S2[j-1]) {&#10;                curr[j] = prev[j-1] + 1;&#10;                ans = max(ans, curr[j]);&#10;            } else {&#10;                curr[j] = 0;&#10;            }&#10;        }&#10;        prev = curr;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">64</td>
      <td rowspan="1">Dp 63 Reach A Given Score<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Unbounded Knapsack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> `dp[i]` represents number of ways to reach score `i`. Init `dp[0] = 1`. For each score option (3, 5, 10), iterate from option to `n`, `dp[i] += dp[i - option]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int count(long long int n) {&#10;    vector&lt;long long int&gt; dp(n + 1, 0);&#10;    dp[0] = 1;&#10;    vector&lt;int&gt; scores = {3, 5, 10};&#10;    for(int s : scores) {&#10;        for(int i = s; i &lt;= n; i++) {&#10;            dp[i] += dp[i - s];&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
