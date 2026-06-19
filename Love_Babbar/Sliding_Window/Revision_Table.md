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
      <td rowspan="1">Sw 03 Trapping Rain Water<br><br></b> <a href='https://leetcode.com/problems/trapping-rain-water/' target='_blank'>LeetCode 42</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: height = [0,1,0,2,1,0,1,3,2,1,2,1], Output: 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Local Maxima:</b> Water trapped at `i` relies on the absolute minimum of the highest bars to its left and right.</td>
      <td><b>Explanation:</b> Two pointers `left` and `right`. Maintain `left_max` and `right_max`. Move the pointer pointing to the smaller max, adding trapped water.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;int trap(std::vector&lt;int&gt;&amp; height) {&#10;    int n = height.size();&#10;    int left = 0, right = n - 1;&#10;    int res = 0, maxLeft = 0, maxRight = 0;&#10;    while (left &lt;= right) {&#10;        if (height[left] &lt;= height[right]) {&#10;            if (height[left] &gt;= maxLeft) maxLeft = height[left];&#10;            else res += maxLeft - height[left];&#10;            left++;&#10;        } else {&#10;            if (height[right] &gt;= maxRight) maxRight = height[right];&#10;            else res += maxRight - height[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
