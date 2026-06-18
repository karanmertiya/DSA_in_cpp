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
      <td rowspan="1"><b>Example 1:</b> Input: nums = [-1,0,3,5,9,12], target = 9, Output: 4<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>4</sup></td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Mid Overflow:</b> Calculate mid as `low + (high - low) / 2` to prevent integer overflow for large arrays.</td>
      <td><b>Explanation:</b> Compare target with the middle element. If smaller, search the left half. If larger, search the right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        else if(nums[mid] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bs 02 Lower Bound And Upper Bound<br><br></b> <a href='https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/' target='_blank'>LeetCode 34</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [5,7,7,8,8,10], target = 8, Output: [3,4]<br><br><b>Note (Constraint):</b> Must be `O(log N)`.</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Biasing:</b> If `nums[mid] == target`, don't return. Record the index and continue searching left (for lower) or right (for upper).</td>
      <td><b>Explanation:</b> Perform two separate binary searches: one for the first occurrence (bias left) and one for the last (bias right).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;int&gt; searchRange(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    auto findBound = [&amp;](bool isFirst) {&#10;        int low = 0, high = nums.size() - 1, res = -1;&#10;        while(low &lt;= high) {&#10;            int mid = low + (high - low) / 2;&#10;            if(nums[mid] == target) {&#10;                res = mid;&#10;                if(isFirst) high = mid - 1; // Bias Left&#10;                else low = mid + 1;         // Bias Right&#10;            }&#10;            else if(nums[mid] &lt; target) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;        return res;&#10;    };&#10;    return {findBound(true), findBound(false)};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Bs 04 Binary Search On Answers Koko Eating Bananas<br><br></b> <a href='https://leetcode.com/problems/koko-eating-bananas/' target='_blank'>LeetCode 875</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: piles = [3,6,7,11], h = 8, Output: 4<br><br><b>Note (Constraint):</b> Binary Search on Answers.</td>
      <td><b>Time:</b> O(N log(Max(Pile))) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::ceil</code> / <code>math.ceil</code></td>
      <td><b>Answer Range:</b> The minimum speed is 1, and the maximum speed needed is the largest pile size (which finishes every pile in 1 hour).</td>
      <td><b>Explanation:</b> Search space is `1` to `max(piles)`. Calculate total hours for `mid`. If possible, try a slower speed (left half).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;#include &lt;cmath&gt;&#10;&#10;int minEatingSpeed(std::vector&lt;int&gt;&amp; piles, int h) {&#10;    auto canEat = [&amp;](int speed) {&#10;        long long hours = 0;&#10;        for(int p : piles) hours += std::ceil((double)p / speed);&#10;        return hours &lt;= h;&#10;    };&#10;    &#10;    int low = 1, high = *std::max_element(piles.begin(), piles.end());&#10;    int ans = high;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canEat(mid)) {&#10;            ans = mid;&#10;            high = mid - 1; // Try slower&#10;        } else {&#10;            low = mid + 1; // Need to eat faster&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
