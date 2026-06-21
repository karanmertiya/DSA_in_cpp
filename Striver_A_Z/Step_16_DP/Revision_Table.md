# Step 16 DP Revision Table

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
      <td>DP 01 Climbing Stairs<br><br></b> <a href="https://leetcode.com/problems/climbing-stairs/" target="_blank">LeetCode 70</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> n = 3<br><b>Output:</b> 3 (1+1+1, 1+2, 2+1)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Explanation:</b> Space Optimization (Bottom-Up): Since state `n` only depends on `n-1` and `n-2`, we only need two variables.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int climbStairs(int n) {&#10;    if (n &lt;= 1) return 1;&#10;    int prev2 = 1, prev = 1;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        int curr = prev + prev2;&#10;        prev2 = prev;&#10;        prev = curr;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>DP 02 Longest Common Subsequence<br><br></b> <a href="https://leetcode.com/problems/longest-common-subsequence/" target="_blank">LeetCode 1143</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> text1 = "abcde", text2 = "ace"<br><b>Output:</b> 3 ("ace")</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Trade-off)</td>
      <td><b>Dependencies:</b> <code>std::max</code><br><b>Explanation:</b> Tabulation (Bottom-Up). Use a 2D array where `dp[i][j]` represents the LCS of prefixes of length `i` and `j`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubsequence(std::string text1, std::string text2) {&#10;    int n = text1.length(), m = text2.length();&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; dp(n + 1, std::vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];&#10;            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>DP 03 Coin Change<br><br></b> <a href="https://leetcode.com/problems/coin-change/" target="_blank">LeetCode 322</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> coins = [1,2,5], amount = 11<br><b>Output:</b> 3 (5+5+1)</td>
      <td><b>Time:</b> O(Amount * N)<br><b>Space:</b> O(Amount)</td>
      <td><b>Dependencies:</b> <code>std::min</code><br><b>Explanation:</b> Unbounded Knapsack. State `dp[i]` is the min coins needed to make amount `i`. `dp[i] = min(dp[i], 1 + dp[i - coin])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int coinChange(std::vector&lt;int&gt;&amp; coins, int amount) {&#10;    std::vector&lt;int&gt; dp(amount + 1, amount + 1);&#10;    dp[0] = 0;&#10;    for(int i = 1; i &lt;= amount; i++) {&#10;        for(int coin : coins) {&#10;            if(i - coin &gt;= 0) {&#10;                dp[i] = std::min(dp[i], 1 + dp[i - coin]);&#10;            }&#10;        }&#10;    }&#10;    return dp[amount] &gt; amount ? -1 : dp[amount];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>DP 04 Longest Increasing Subsequence<br><br></b> <a href="https://leetcode.com/problems/longest-increasing-subsequence/" target="_blank">LeetCode 300</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums = [10,9,2,5,3,7,101,18]<br><b>Output:</b> 4 ([2,3,7,101])</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> <code>std::lower_bound</code> / <code>bisect_left</code><br><b>Explanation:</b> Binary Search Patience Sorting method. Maintain a `temp` array. If current element is larger than `temp.back()`, append. Else, replace the first element >= current.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLIS(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; temp;&#10;    for(int num : nums) {&#10;        auto it = std::lower_bound(temp.begin(), temp.end(), num);&#10;        if(it == temp.end()) temp.push_back(num);&#10;        else *it = num;&#10;    }&#10;    return temp.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>DP 05 House Robber<br><br></b> <a href="https://leetcode.com/problems/house-robber/" target="_blank">LeetCode 198</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3,1]<br><b>Output:</b> 4 (Rob house 1 and 3)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Dependencies:</b> <code>std::max</code><br><b>Explanation:</b> Space Optimized DP. Maintain two variables: `prev1` (max up to previous house) and `prev2` (max up to the house before previous). `curr = max(num + prev2, prev1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int rob(std::vector&lt;int&gt;&amp; nums) {&#10;    int prev1 = 0, prev2 = 0;&#10;    for(int num : nums) {&#10;        int curr = std::max(num + prev2, prev1);&#10;        prev2 = prev1;&#10;        prev1 = curr;&#10;    }&#10;    return prev1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>DP 06 01 Knapsack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> N=3, W=4, values[]={1,2,3}, weight[]={4,5,1}<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N * W)<br><b>Space:</b> O(W)</td>
      <td><b>Explanation:</b> 2D DP or 1D array space-optimized DP. Check take and not-take scenarios.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int knapSack(int W, int wt[], int val[], int n) {&#10;    vector&lt;int&gt; prev(W + 1, 0);&#10;    for(int w = wt[0]; w &lt;= W; w++) prev[w] = val[0];&#10;    for(int ind = 1; ind &lt; n; ind++) {&#10;        for(int w = W; w &gt;= 0; w--) {&#10;            int notTake = prev[w];&#10;            int take = INT_MIN;&#10;            if(wt[ind] &lt;= w) take = val[ind] + prev[w - wt[ind]];&#10;            prev[w] = max(take, notTake);&#10;        }&#10;    }&#10;    return prev[W];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>DP 07 Edit Distance<br><br></b> <a href="https://leetcode.com/problems/edit-distance/" target="_blank">LeetCode 72</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> word1 = 'horse', word2 = 'ros'<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td><b>Explanation:</b> 2D DP. If chars match, dp[i-1][j-1]. Else, 1 + min(insert, delete, replace).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDistance(string word1, string word2) {&#10;    int n = word1.size(), m = word2.size();&#10;    vector&lt;int&gt; prev(m+1, 0), cur(m+1, 0);&#10;    for(int j=0; j&lt;=m; j++) prev[j] = j;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        cur[0] = i;&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];&#10;            else cur[j] = 1 + min({prev[j], cur[j-1], prev[j-1]});&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>DP 08 Matrix Chain Multiplication<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, Apna College, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> N=5, arr=[40, 20, 30, 10, 30]<br><b>Output:</b> 26000</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td><b>Dependencies:</b> <code>#include <vector></code><br><b>Explanation:</b> Partition DP. Try partitioning the matrices at every possible split `k` between `i` and `j`. Cost is `arr[i-1]*arr[k]*arr[j]`. Take the minimum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int f(int i, int j, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; dp) {&#10;    if(i == j) return 0;&#10;    if(dp[i][j] != -1) return dp[i][j];&#10;    int mini = 1e9;&#10;    for(int k=i; k&lt;j; k++) {&#10;        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);&#10;        mini = min(mini, steps);&#10;    }&#10;    return dp[i][j] = mini;&#10;}&#10;int matrixMultiplication(int N, vector&lt;int&gt;&amp; arr) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, -1));&#10;    return f(1, N-1, arr, dp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>DP 09 Subset Sum Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> set=[3,34,4,12,5,2], sum=9<br><b>Output:</b> True</td>
      <td><b>Time:</b> O(N * Sum)<br><b>Space:</b> O(Sum) space optimized</td>
      <td><b>Explanation:</b> DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSubsetSum(vector&lt;int&gt;arr, int sum) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; prev(sum+1, false), cur(sum+1, false);&#10;    prev[0] = cur[0] = true;&#10;    if(arr[0] &lt;= sum) prev[arr[0]] = true;&#10;    for(int ind=1; ind&lt;n; ind++) {&#10;        for(int target=1; target&lt;=sum; target++) {&#10;            bool notTaken = prev[target];&#10;            bool taken = false;&#10;            if(arr[ind] &lt;= target) taken = prev[target - arr[ind]];&#10;            cur[target] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>DP 10 Minimum Path Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-path-sum/" target="_blank">LeetCode 64</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> grid = [[1,3,1],[1,5,1],[4,2,1]]<br><b>Output:</b> 7</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td><b>Explanation:</b> DP on Grids. Space optimize to 1D. `cur[j] = grid[i][j] + min(up, left)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;int&gt; prev(m, 0);&#10;    for(int i=0; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(m, 0);&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(i==0 &amp;&amp; j==0) cur[j] = grid[i][j];&#10;            else {&#10;                int up = grid[i][j], left = grid[i][j];&#10;                if(i&gt;0) up += prev[j]; else up += 1e9;&#10;                if(j&gt;0) left += cur[j-1]; else left += 1e9;&#10;                cur[j] = min(up, left);&#10;            }&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>DP 11 Triangle<br><br></b> <a href="https://leetcode.com/problems/triangle/" target="_blank">LeetCode 120</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b><br><b>Output:</b> 11</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Start from bottom row and move upwards. `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumTotal(vector&lt;vector&lt;int&gt;&gt;&amp; triangle) {&#10;    int n = triangle.size();&#10;    vector&lt;int&gt; front = triangle[n-1];&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=i; j&gt;=0; j--) {&#10;            cur[j] = triangle[i][j] + min(front[j], front[j+1]);&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>DP 12 Minimum Falling Path Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-falling-path-sum/" target="_blank">LeetCode 931</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b><br><b>Output:</b> 13</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Similar to minimum path sum, but we can fall diagonally. Space optimize by using previous row.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFallingPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    vector&lt;int&gt; prev = matrix[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=0; j&lt;n; j++) {&#10;            int up = matrix[i][j] + prev[j];&#10;            int ld = matrix[i][j] + (j&gt;0 ? prev[j-1] : 1e9);&#10;            int rd = matrix[i][j] + (j&lt;n-1 ? prev[j+1] : 1e9);&#10;            cur[j] = min({up, ld, rd});&#10;        }&#10;        prev = cur;&#10;    }&#10;    int mini = 1e9;&#10;    for(int j=0; j&lt;n; j++) mini = min(mini, prev[j]);&#10;    return mini;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>DP 13 Cherry Pickup II<br><br></b> <a href="https://leetcode.com/problems/cherry-pickup-ii/" target="_blank">LeetCode 1463</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> 3D DP.</td>
      <td><b>Time:</b> O(N * M * M * 9)<br><b>Space:</b> O(M * M)</td>
      <td><b>Explanation:</b> Robots move simultaneously. State is `dp[row][col1][col2]`. Try all 9 combinations of moves for both robots.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int cherryPickup(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; front(m, vector&lt;int&gt;(m, 0)), cur(m, vector&lt;int&gt;(m, 0));&#10;    for(int j1=0; j1&lt;m; j1++) {&#10;        for(int j2=0; j2&lt;m; j2++) {&#10;            if(j1 == j2) front[j1][j2] = grid[n-1][j1];&#10;            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];&#10;        }&#10;    }&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        for(int j1=0; j1&lt;m; j1++) {&#10;            for(int j2=0; j2&lt;m; j2++) {&#10;                int maxi = -1e9;&#10;                for(int dj1=-1; dj1&lt;=1; dj1++) {&#10;                    for(int dj2=-1; dj2&lt;=1; dj2++) {&#10;                        int val = 0;&#10;                        if(j1 == j2) val = grid[i][j1];&#10;                        else val = grid[i][j1] + grid[i][j2];&#10;                        if(j1+dj1&gt;=0 &amp;&amp; j1+dj1&lt;m &amp;&amp; j2+dj2&gt;=0 &amp;&amp; j2+dj2&lt;m)&#10;                            val += front[j1+dj1][j2+dj2];&#10;                        else val += -1e9;&#10;                        maxi = max(maxi, val);&#10;                    }&#10;                }&#10;                cur[j1][j2] = maxi;&#10;            }&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0][m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>DP 14 Partition Equal Subset Sum<br><br></b> <a href="https://leetcode.com/problems/partition-equal-subset-sum/" target="_blank">LeetCode 416</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b><br><b>Output:</b> True.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td><b>Explanation:</b> If total sum is odd, impossible. Else, find if there's a subset with sum `Total/2` using space-optimized DP.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canPartition(vector&lt;int&gt;&amp; nums) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum % 2 != 0) return false;&#10;    int target = sum / 2;&#10;    vector&lt;bool&gt; prev(target + 1, false);&#10;    prev[0] = true;&#10;    if(nums[0] &lt;= target) prev[nums[0]] = true;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;bool&gt; cur(target + 1, false);&#10;        cur[0] = true;&#10;        for(int t=1; t&lt;=target; t++) {&#10;            bool notTaken = prev[t];&#10;            bool taken = false;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[target];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>DP 15 Target Sum<br><br></b> <a href="https://leetcode.com/problems/target-sum/" target="_blank">LeetCode 494</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Count Subsets with Diff = target.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td><b>Explanation:</b> Subset sum variation. `S1 - S2 = target`, `S1 + S2 = totalSum`. So, `S1 = (target + totalSum) / 2`. Find subsets with this target sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTargetSumWays(vector&lt;int&gt;&amp; nums, int target) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum - target &lt; 0 || (sum - target) % 2 == 1) return 0;&#10;    int s2 = (sum - target) / 2;&#10;    vector&lt;int&gt; prev(s2 + 1, 0);&#10;    if(nums[0] == 0) prev[0] = 2;&#10;    else prev[0] = 1;&#10;    if(nums[0] != 0 &amp;&amp; nums[0] &lt;= s2) prev[nums[0]] = 1;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;int&gt; cur(s2 + 1, 0);&#10;        for(int t=0; t&lt;=s2; t++) {&#10;            int notTaken = prev[t];&#10;            int taken = 0;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken + taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[s2];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>DP 16 Burst Balloons<br><br></b> <a href="https://leetcode.com/problems/burst-balloons/" target="_blank">LeetCode 312</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums = [3,1,5,8]<br><b>Output:</b> 167</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td><b>Explanation:</b> MCM Pattern. Add 1 at the beginning and end. Loop lengths from 1 to N. Iterate start `i` and end `j`. Then iterate `k` from `i` to `j`, meaning balloon `k` is the LAST one to burst in the range `[i, j]`. The coins collected are `nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxCoins(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    nums.insert(nums.begin(), 1);&#10;    nums.push_back(1);&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 2, vector&lt;int&gt;(n + 2, 0));&#10;    for(int i=n; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=n; j++) {&#10;            if(i &gt; j) continue;&#10;            int maxi = INT_MIN;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];&#10;                maxi = max(maxi, cost);&#10;            }&#10;            dp[i][j] = maxi;&#10;        }&#10;    }&#10;    return dp[1][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>DP 17 Palindrome Partitioning II<br><br></b> <a href="https://leetcode.com/problems/palindrome-partitioning-ii/" target="_blank">LeetCode 132</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> s = 'aab'<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Front Partitioning. `dp[i]` is the minimum cuts for `s[i...n-1]`. To compute `dp[i]`, iterate `j` from `i` to `n-1`. If `s[i...j]` is a palindrome, then `cost = 1 + dp[j+1]`. `dp[i]` is the minimum of these costs. Return `dp[0] - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string&amp; s, int i, int j) {&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;int minCut(string s) {&#10;    int n = s.length();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int minCuts = INT_MAX;&#10;        for(int j=i; j&lt;n; j++) {&#10;            if(isPalindrome(s, i, j)) {&#10;                int cost = 1 + dp[j+1];&#10;                minCuts = min(minCuts, cost);&#10;            }&#10;        }&#10;        dp[i] = minCuts;&#10;    }&#10;    return dp[0] - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>DP 18 Evaluate Boolean Expression To True<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> MCM DP pattern.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td><b>Explanation:</b> MCM DP. `dp[i][j][isTrue]` stores the number of ways to evaluate `S[i..j]` to boolean `isTrue`. Iterate length, start, and partition `k`. Calculate T/F ways based on the operator at `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countWays(int N, string S){&#10;    int mod = 1003;&#10;    vector&lt;vector&lt;vector&lt;long long&gt;&gt;&gt; dp(N, vector&lt;vector&lt;long long&gt;&gt;(N, vector&lt;long long&gt;(2, 0)));&#10;    for(int i=N-1; i&gt;=0; i-=2) {&#10;        for(int j=i; j&lt;N; j+=2) {&#10;            if(i == j) {&#10;                dp[i][j][1] = (S[i] == &#x27;T&#x27;);&#10;                dp[i][j][0] = (S[i] == &#x27;F&#x27;);&#10;                continue;&#10;            }&#10;            long long waysT = 0, waysF = 0;&#10;            for(int k=i+1; k&lt;=j-1; k+=2) {&#10;                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];&#10;                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];&#10;                if(S[k] == &#x27;&amp;&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;|&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;^&#x27;) {&#10;                    waysT = (waysT + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rT) % mod + (lF * rF) % mod) % mod;&#10;                }&#10;            }&#10;            dp[i][j][1] = waysT;&#10;            dp[i][j][0] = waysF;&#10;        }&#10;    }&#10;    return dp[0][N-1][1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>DP 19 Count Square Submatrices With All Ones<br><br></b> <a href="https://leetcode.com/problems/count-square-submatrices-with-all-ones/" target="_blank">LeetCode 1277</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Return total count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td><b>Explanation:</b> `dp[i][j]` is the size of the largest square ending at `(i, j)`. It also represents the number of squares ending at `(i, j)`. `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1` if `matrix[i][j] == 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSquares(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int sum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(matrix[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                sum += dp[i][j];&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>DP 20 Minimum Cost To Cut A Stick<br><br></b> <a href="https://leetcode.com/problems/minimum-cost-to-cut-a-stick/" target="_blank">LeetCode 1547</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Cost depends on current stick length.</td>
      <td><b>Time:</b> O(C^3) where C is number of cuts<br><b>Space:</b> O(C^2)</td>
      <td><b>Explanation:</b> Sort cuts array and prepend 0, append `n`. Use MCM pattern. `dp[i][j]` is the minimum cost to cut the stick between cuts `i` and `j`. `dp[i][j] = min(cost + cuts[j+1] - cuts[i-1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minCost(int n, vector&lt;int&gt;&amp; cuts) {&#10;    cuts.push_back(0);&#10;    cuts.push_back(n);&#10;    sort(cuts.begin(), cuts.end());&#10;    int c = cuts.size() - 2;&#10;    vector&lt;vector&lt;int&gt;&gt; dp(c + 2, vector&lt;int&gt;(c + 2, 0));&#10;    for(int i=c; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=c; j++) {&#10;            if(i &gt; j) continue;&#10;            int mini = INT_MAX;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];&#10;                mini = min(mini, cost);&#10;            }&#10;            dp[i][j] = mini;&#10;        }&#10;    }&#10;    return dp[1][c];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>DP 21 Partition Array For Maximum Sum<br><br></b> <a href="https://leetcode.com/problems/partition-array-for-maximum-sum/" target="_blank">LeetCode 1043</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Front partitioning DP.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Front partitioning. `dp[i]` is max sum for `arr[i..n-1]`. For each `i`, iterate `j` up to `i+k-1`. Find `maxi` element in this window, and add `maxi * length + dp[j+1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumAfterPartitioning(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int max_val = 0;&#10;        int max_ans = 0;&#10;        int len = 0;&#10;        for(int j=i; j&lt;min(n, i + k); j++) {&#10;            len++;&#10;            max_val = max(max_val, arr[j]);&#10;            int sum = max_val * len + dp[j+1];&#10;            max_ans = max(max_ans, sum);&#10;        }&#10;        dp[i] = max_ans;&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>DP 22 Distinct Subsequences<br><br></b> <a href="https://leetcode.com/problems/distinct-subsequences/" target="_blank">LeetCode 115</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Subsequence match count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td><b>Explanation:</b> If characters match, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`. If they don't, `dp[i][j] = dp[i-1][j]`. Optimize to 1D array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numDistinct(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;double&gt; dp(m + 1, 0);&#10;    dp[0] = 1;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=m; j&gt;=1; j--) {&#10;            if(s[i-1] == t[j-1]) {&#10;                dp[j] = dp[j-1] + dp[j];&#10;            }&#10;        }&#10;    }&#10;    return (int)dp[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>DP 23 Wildcard Matching<br><br></b> <a href="https://leetcode.com/problems/wildcard-matching/" target="_blank">LeetCode 44</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td><b>Explanation:</b> Use a 2D DP array where `dp[i][j]` means if `s[0..i-1]` matches `p[0..j-1]`. If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, `dp[i][j] = dp[i-1][j-1]`. If `p[j-1] == '*'`, it can match empty (`dp[i][j-1]`) or match one character (`dp[i-1][j]`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isMatch(string s, string p) {&#10;    int n = s.length(), m = p.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; dp(n + 1, vector&lt;bool&gt;(m + 1, false));&#10;    dp[0][0] = true;&#10;    for(int j = 1; j &lt;= m; j++) {&#10;        if(p[j-1] == &#x27;*&#x27;) dp[0][j] = dp[0][j-1];&#10;    }&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(p[j-1] == s[i-1] || p[j-1] == &#x27;?&#x27;) {&#10;                dp[i][j] = dp[i-1][j-1];&#10;            } else if(p[j-1] == &#x27;*&#x27;) {&#10;                dp[i][j] = dp[i-1][j] || dp[i][j-1];&#10;            }&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>DP 24 Best Time To Buy And Sell Stock II<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/" target="_blank">LeetCode 122</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Valley Peak approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Add the profit whenever the price is higher than the previous day. This is equivalent to capturing every upward slope.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        if(prices[i] &gt; prices[i-1]) {&#10;            profit += prices[i] - prices[i-1];&#10;        }&#10;    }&#10;    return profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>DP 25 Best Time To Buy And Sell Stock III<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/" target="_blank">LeetCode 123</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> 3D DP / State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Maintain four variables representing the max profit after first buy, first sell, second buy, and second sell. Update them iteratively.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;&#10;    for(int price : prices) {&#10;        buy1 = max(buy1, -price);&#10;        sell1 = max(sell1, buy1 + price);&#10;        buy2 = max(buy2, sell1 - price);&#10;        sell2 = max(sell2, buy2 + price);&#10;    }&#10;    return sell2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>DP 26 Best Time To Buy And Sell Stock IV<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/" target="_blank">LeetCode 188</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> DP with transactions.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N * K) or O(K)</td>
      <td><b>Explanation:</b> If `k >= n/2`, it's equivalent to infinite transactions (Stock II). Else, use a DP array `dp[k][n]` where `dp[i][j]` is max profit using `i` transactions up to day `j`. Optimize inner loop by tracking `maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j-1])`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(int k, vector&lt;int&gt;&amp; prices) {&#10;    int n = prices.size();&#10;    if(n &lt;= 1) return 0;&#10;    if(k &gt;= n / 2) {&#10;        int profit = 0;&#10;        for(int i = 1; i &lt; n; i++) {&#10;            if(prices[i] &gt; prices[i-1]) profit += prices[i] - prices[i-1];&#10;        }&#10;        return profit;&#10;    }&#10;    vector&lt;int&gt; buy(k + 1, INT_MIN), sell(k + 1, 0);&#10;    for(int price : prices) {&#10;        for(int i = 1; i &lt;= k; i++) {&#10;            buy[i] = max(buy[i], sell[i-1] - price);&#10;            sell[i] = max(sell[i], buy[i] + price);&#10;        }&#10;    }&#10;    return sell[k];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>DP 27 Best Time To Buy And Sell Stock With Cooldown<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/" target="_blank">LeetCode 309</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> State Machine DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Maintain 3 states: `hold` (holding a stock), `sold` (just sold, entering cooldown next), `rest` (not holding, not in cooldown). Transitions: `hold = max(hold, rest - price)`, `sold = hold + price`, `rest = max(rest, sold_prev)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int hold = INT_MIN, sold = 0, rest = 0;&#10;    for(int price : prices) {&#10;        int prev_sold = sold;&#10;        sold = hold + price;&#10;        hold = max(hold, rest - price);&#10;        rest = max(rest, prev_sold);&#10;    }&#10;    return max(rest, sold);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>DP 28 Best Time To Buy And Sell Stock With Transaction Fee<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/" target="_blank">LeetCode 714</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> DP State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Similar to Stock II, but subtract `fee` when selling. Maintain `cash` (max profit not holding stock) and `hold` (max profit holding stock). `cash = max(cash, hold + price - fee)`, `hold = max(hold, cash - price)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices, int fee) {&#10;    int cash = 0, hold = -prices[0];&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        cash = max(cash, hold + prices[i] - fee);&#10;        hold = max(hold, cash - prices[i]);&#10;    }&#10;    return cash;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>DP 29 Largest Divisible Subset<br><br></b> <a href="https://leetcode.com/problems/largest-divisible-subset/" target="_blank">LeetCode 368</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Sort and LIS variant.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Sort the array. Then use LIS logic: `dp[i]` is max subset ending at `i`. If `nums[i] % nums[j] == 0`, `dp[i] = max(dp[i], dp[j] + 1)`. Also keep a `parent` array to reconstruct the subset.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; largestDivisibleSubset(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return {};&#10;    sort(nums.begin(), nums.end());&#10;    int n = nums.size(), max_len = 1, max_idx = 0;&#10;    vector&lt;int&gt; dp(n, 1), parent(n, -1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] % nums[j] == 0 &amp;&amp; dp[i] &lt; dp[j] + 1) {&#10;                dp[i] = dp[j] + 1;&#10;                parent[i] = j;&#10;            }&#10;        }&#10;        if(dp[i] &gt; max_len) {&#10;            max_len = dp[i];&#10;            max_idx = i;&#10;        }&#10;    }&#10;    vector&lt;int&gt; res;&#10;    while(max_idx != -1) {&#10;        res.push_back(nums[max_idx]);&#10;        max_idx = parent[max_idx];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>DP 30 Longest String Chain<br><br></b> <a href="https://leetcode.com/problems/longest-string-chain/" target="_blank">LeetCode 1048</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Sort by length and use hash map.</td>
      <td><b>Time:</b> O(N log N + N * L^2) where L is max word length<br><b>Space:</b> O(N * L)</td>
      <td><b>Dependencies:</b> <code>#include <unordered_map></code><br><b>Explanation:</b> Sort words by length. Use a hash map `dp` to store the longest chain ending at `word`. For each word, try removing one character at a time to form `prev_word`. `dp[word] = max(dp[word], dp[prev_word] + 1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestStrChain(vector&lt;string&gt;&amp; words) {&#10;    sort(words.begin(), words.end(), [](const string&amp; a, const string&amp; b) {&#10;        return a.length() &lt; b.length();&#10;    });&#10;    unordered_map&lt;string, int&gt; dp;&#10;    int max_len = 1;&#10;    for(const string&amp; word : words) {&#10;        dp[word] = 1;&#10;        for(int i = 0; i &lt; word.length(); i++) {&#10;            string prev = word.substr(0, i) + word.substr(i + 1);&#10;            if(dp.find(prev) != dp.end()) {&#10;                dp[word] = max(dp[word], dp[prev] + 1);&#10;            }&#10;        }&#10;        max_len = max(max_len, dp[word]);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>DP 31 Longest Bitonic Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> LIS from left + LIS from right.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Compute LIS ending at `i` from left to right (`inc[i]`). Compute LIS starting at `i` from right to left (`dec[i]`). The max bitonic subsequence length is `max(inc[i] + dec[i] - 1)` for all `i`. Sometimes pure increasing or pure decreasing is also bitonic depending on definition, adjust if necessary.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestBitonicSequence(vector&lt;int&gt; nums) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; inc(n, 1), dec(n, 1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) inc[i] = max(inc[i], inc[j] + 1);&#10;        }&#10;    }&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        for(int j = n - 1; j &gt; i; j--) {&#10;            if(nums[i] &gt; nums[j]) dec[i] = max(dec[i], dec[j] + 1);&#10;        }&#10;    }&#10;    int max_len = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        // Depending on problem variant, might require both to be &gt; 1 to be valid peak&#10;        max_len = max(max_len, inc[i] + dec[i] - 1);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>DP 32 Number Of Longest Increasing Subsequence<br><br></b> <a href="https://leetcode.com/problems/number-of-longest-increasing-subsequence/" target="_blank">LeetCode 673</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> Two DP arrays (Length and Count).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Maintain `lengths[i]` (length of LIS ending at i) and `counts[i]` (number of LIS ending at i). If `nums[i] > nums[j]`: if `lengths[j] + 1 > lengths[i]`, then `lengths[i] = lengths[j] + 1` and `counts[i] = counts[j]`. Else if `lengths[j] + 1 == lengths[i]`, then `counts[i] += counts[j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findNumberOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), max_len = 0, res = 0;&#10;    vector&lt;int&gt; len(n, 1), count(n, 1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) {&#10;                if(len[j] + 1 &gt; len[i]) {&#10;                    len[i] = len[j] + 1;&#10;                    count[i] = count[j];&#10;                } else if(len[j] + 1 == len[i]) {&#10;                    count[i] += count[j];&#10;                }&#10;            }&#10;        }&#10;        if(len[i] &gt; max_len) {&#10;            max_len = len[i];&#10;            res = count[i];&#10;        } else if(len[i] == max_len) {&#10;            res += count[i];&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>DP 33 Largest Square Formed In A Matrix<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Bottom-up DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td><b>Explanation:</b> `dp[i][j]` is side of max square ending at `(i, j)`. If `mat[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. Result is max over all `dp[i][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSquare(int n, int m, vector&lt;vector&lt;int&gt;&gt; mat) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(mat[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                ans = max(ans, dp[i][j]);&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>DP 34 Coin Change Maximum Ways<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/coin-change2448/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> 1D Tabulation.</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Create a `dp` array of size `N + 1` initialized to 0. `dp[0] = 1`. For each coin, iterate through all amounts from `coin` to `N` and update `dp[j] += dp[j - coin]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int count(int coins[], int N, int sum) {&#10;    vector&lt;long long int&gt; dp(sum + 1, 0);&#10;    dp[0] = 1;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        for(int j = coins[i]; j &lt;= sum; j++) {&#10;            dp[j] += dp[j - coins[i]];&#10;        }&#10;    }&#10;    return dp[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>DP 35 Palindromic Partitioning<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> 1D DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td><b>Explanation:</b> Create a `dp` array where `dp[i]` is min cuts for `str[0..i]`. Also use a 2D boolean DP to check if `str[j..i]` is a palindrome. If it is, `dp[i] = min(dp[i], dp[j-1] + 1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int palindromicPartition(string str) {&#10;    int n = str.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; isPal(n, vector&lt;bool&gt;(n, false));&#10;    vector&lt;int&gt; dp(n, 0);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int minCut = i;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            if(str[i] == str[j] &amp;&amp; (i - j &lt; 2 || isPal[j+1][i-1])) {&#10;                isPal[j][i] = true;&#10;                if(j == 0) minCut = 0;&#10;                else minCut = min(minCut, dp[j-1] + 1);&#10;            }&#10;        }&#10;        dp[i] = minCut;&#10;    }&#10;    return dp[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>DP 36 Maximum Sum Increasing Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> DP (LIS variant).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> DP<br><b>Explanation:</b> Variation of LIS. Create an array `msis` initialized with the given array values. For each `i` from 1 to `n-1`, for each `j` from 0 to `i-1`, if `arr[i] > arr[j]` and `msis[i] < msis[j] + arr[i]`, update `msis[i]`. The max in `msis` is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumIS(int arr[], int n) {&#10;    vector&lt;int&gt; msis(arr, arr + n);&#10;    int max_sum = msis[0];&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(arr[i] &gt; arr[j] &amp;&amp; msis[i] &lt; msis[j] + arr[i]) {&#10;                msis[i] = msis[j] + arr[i];&#10;            }&#10;        }&#10;        max_sum = max(max_sum, msis[i]);&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>DP 37 Egg Dropping Puzzle<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> DP + Binary Search / Math.</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td><b>Dependencies:</b> DP<br><b>Explanation:</b> Use DP. `dp[i][j]` is the min attempts with `i` eggs and `j` floors. Try dropping from every floor `x` from 1 to `j`. `res = 1 + max(dp[i-1][x-1] (breaks), dp[i][j-x] (doesn't break))`. Optimize this nested loop using Binary Search or use a different state `dp[m][k]` = floors checked with `m` moves and `k` eggs.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int eggDrop(int n, int k) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(k + 1, vector&lt;int&gt;(n + 1, 0));&#10;    int m = 0;&#10;    while(dp[m][n] &lt; k) {&#10;        m++;&#10;        for(int x = 1; x &lt;= n; x++) {&#10;            dp[m][x] = 1 + dp[m-1][x-1] + dp[m-1][x];&#10;        }&#10;    }&#10;    return m;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>DP 38 Maximum Length Chain Of Pairs<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/max-length-chain/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Sort and Greedy / DP.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> This is exactly the Activity Selection Problem. Sort the pairs by their second element. Iterate through the sorted pairs and keep track of the end of the last selected pair. If the next pair's start is > last end, select it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct val {&#10;    int first;&#10;    int second;&#10;};&#10;bool compare(struct val a, struct val b) {&#10;    return a.second &lt; b.second;&#10;}&#10;int maxChainLen(struct val p[], int n) {&#10;    sort(p, p + n, compare);&#10;    int count = 1;&#10;    int last_end = p[0].second;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(p[i].first &gt; last_end) {&#10;            count++;&#10;            last_end = p[i].second;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>DP 39 Minimum Insertions To Make String Palindrome<br><br></b> <a href="https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/" target="_blank">LeetCode 1312</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Longest Palindromic Subsequence.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td><b>Explanation:</b> Find the Longest Palindromic Subsequence (LPS). The minimum insertions required will be `string_length - LPS_length`. LPS is just LCS(s, reverse(s)).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minInsertions(string s) {&#10;    int n = s.length();&#10;    string t = s;&#10;    reverse(t.begin(), t.end());&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];&#10;            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);&#10;        }&#10;    }&#10;    return n - dp[n][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>DP 40 Print Longest Common Subsequence<br><br></b> <a href="https://www.geeksforgeeks.org/printing-longest-common-subsequence/" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> DP table backtracking.</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(M * N)</td>
      <td><b>Explanation:</b> Build the LCS DP table. Start from `dp[m][n]`. If `s1[i-1] == s2[j-1]`, include this character in the result and move diagonally to `dp[i-1][j-1]`. Otherwise, move to the maximum of `dp[i-1][j]` or `dp[i][j-1]`. Reverse the string at the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string printLCS(string s1, string s2) {&#10;    int m = s1.length(), n = s2.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(m + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= m; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];&#10;            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);&#10;        }&#10;    }&#10;    int i = m, j = n;&#10;    string res = &quot;&quot;;&#10;    while(i &gt; 0 &amp;&amp; j &gt; 0) {&#10;        if(s1[i-1] == s2[j-1]) {&#10;            res += s1[i-1];&#10;            i--; j--;&#10;        } else if(dp[i-1][j] &gt; dp[i][j-1]) i--;&#10;        else j--;&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
