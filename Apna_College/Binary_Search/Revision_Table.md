# Binary Search Revision Table

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
      <td rowspan="1">Bs 01 Binary Search<br><br></b> <a href='https://leetcode.com/problems/binary-search/' target='_blank'>LeetCode 704</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [-1,0,3,5,9,12], target = 9, Output: 4</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Mid Overflow:</b> Use `mid = low + (high - low) / 2` to avoid integer overflow if boundaries are large.</td>
      <td><b>Explanation:</b> Standard Iterative approach. Maintain `low` and `high` boundaries, shrinking the search space by half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        else if(nums[mid] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bs 02 Lower Bound<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [1,2,8,10,11,12,19], target = 0, Output: 0</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::lower_bound</code> internal alternative</td>
      <td><b>Not Found:</b> If all elements are smaller, `ans` stays `N`.</td>
      <td><b>Explanation:</b> When `nums[mid] >= target`, it is a potential answer. Store it and search left (`high = mid - 1`) for smaller potentials.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int lowerBound(std::vector&lt;int&gt; arr, int n, int x) {&#10;    int low = 0, high = n - 1;&#10;    int ans = n;&#10;    while (low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if (arr[mid] &gt;= x) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
