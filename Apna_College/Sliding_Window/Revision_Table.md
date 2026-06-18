# Sliding Window Revision Table

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
      <td rowspan="1">Sw 01 Max Sum Subarray Size K<br><br></b> <a href='https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [2, 1, 5, 1, 3, 2], K = 3, Output: 9 ([5, 1, 3])<br><br><b>Note (Constraint):</b> Fixed size sliding window.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Initial Window:</b> Calculate the first K elements manually before starting the sliding loop.</td>
      <td><b>Explanation:</b> Fixed Sliding Window: Maintain a window of size K. Slide it by adding the next element and subtracting the first element of the previous window.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;long long maximumSumSubarray(int K, std::vector&lt;int&gt;&amp; arr) {&#10;    long long max_sum = 0, current_sum = 0;&#10;    for(int i=0; i&lt;K; i++) current_sum += arr[i];&#10;    max_sum = current_sum;&#10;    &#10;    for(int i=K; i&lt;arr.size(); i++) {&#10;        current_sum += arr[i] - arr[i-K];&#10;        max_sum = std::max(max_sum, current_sum);&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
