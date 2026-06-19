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
      <td rowspan="1">Dp 11 Matrix Chain Multiplication<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=5, arr=[40, 20, 30, 10, 30], Output: 26000</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td><code>#include <vector></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Partition DP. Try partitioning the matrices at every possible split `k` between `i` and `j`. Cost is `arr[i-1]*arr[k]*arr[j]`. Take the minimum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int f(int i, int j, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; dp) {&#10;    if(i == j) return 0;&#10;    if(dp[i][j] != -1) return dp[i][j];&#10;    int mini = 1e9;&#10;    for(int k=i; k&lt;j; k++) {&#10;        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);&#10;        mini = min(mini, steps);&#10;    }&#10;    return dp[i][j] = mini;&#10;}&#10;int matrixMultiplication(int N, vector&lt;int&gt;&amp; arr) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, -1));&#10;    return f(1, N-1, arr, dp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Dp 12 Subset Sum Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: set=[3,34,4,12,5,2], sum=9, Output: True</td>
      <td><b>Time:</b> O(N * Sum)<br><b>Space:</b> O(Sum) space optimized</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSubsetSum(vector&lt;int&gt;arr, int sum) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; prev(sum+1, false), cur(sum+1, false);&#10;    prev[0] = cur[0] = true;&#10;    if(arr[0] &lt;= sum) prev[arr[0]] = true;&#10;    for(int ind=1; ind&lt;n; ind++) {&#10;        for(int target=1; target&lt;=sum; target++) {&#10;            bool notTaken = prev[target];&#10;            bool taken = false;&#10;            if(arr[ind] &lt;= target) taken = prev[target - arr[ind]];&#10;            cur[target] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Dp 13 Word Break<br><br></b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s='leetcode', wordDict=['leet', 'code'], Output: true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> 1D DP array. `dp[i]` is true if string up to index `i` can be broken. Loop `i` from 1 to N, loop `j` from 0 to i. If `dp[j]` is true and `s[j...i]` is in dict, then `dp[i] = true`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.size();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(s.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true; break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
