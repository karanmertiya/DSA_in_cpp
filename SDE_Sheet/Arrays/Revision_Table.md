# Arrays Revision Table

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
      <td rowspan="1">Arr 01 Largest Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/largest-element-in-array/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: A = [1, 8, 7, 56, 90], Output: 90</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Initialization:</b> Initialize `max_val` with the first element or negative infinity.</td>
      <td><b>Explanation:</b> Iterate through the array maintaining a variable for the maximum element seen so far.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int max_val = arr[0];&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &gt; max_val) {&#10;            max_val = arr[i];&#10;        }&#10;    }&#10;    return max_val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Arr 02 Second Largest Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/second-largest3735/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [12, 35, 1, 10, 34, 1], Output: 34<br><br><b>Note (Constraint):</b> Find it in a single pass O(N) time.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>No Second Largest:</b> If all elements are same or array size < 2, return -1.</td>
      <td><b>Explanation:</b> Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int print2largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int largest = -1, second_largest = -1;&#10;    for (int num : arr) {&#10;        if (num &gt; largest) {&#10;            second_largest = largest;&#10;            largest = num;&#10;        } else if (num &gt; second_largest &amp;&amp; num != largest) {&#10;            second_largest = num;&#10;        }&#10;    }&#10;    return second_largest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Arr 04 Remove Duplicates From Sorted Array<br><br></b> <a href='https://leetcode.com/problems/remove-duplicates-from-sorted-array/' target='_blank'>LeetCode 26</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,1,2], Output: 2, nums = [1,2,_]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Empty Array:</b> Handled automatically if `n=0`.</td>
      <td><b>Explanation:</b> Two-pointer approach. Pointer `i` keeps track of unique elements, pointer `j` scans the array to find new unique elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int removeDuplicates(std::vector&lt;int&gt;&amp; nums) {&#10;    if (nums.empty()) return 0;&#10;    int i = 0;&#10;    for (int j = 1; j &lt; nums.size(); j++) {&#10;        if (nums[j] != nums[i]) {&#10;            i++;&#10;            nums[i] = nums[j];&#10;        }&#10;    }&#10;    return i + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Arr 07 Missing Number<br><br></b> <a href='https://leetcode.com/problems/missing-number/' target='_blank'>LeetCode 268</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [3,0,1], Output: 2</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Mathematical Sum alternative:</b> Gaussian sum formula `N*(N+1)/2` can cause integer overflow, XOR completely bypasses overflow risks.</td>
      <td><b>Explanation:</b> Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int missingNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int res = nums.size();&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        res ^= i ^ nums[i];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Arr 09 Single Number<br><br></b> <a href='https://leetcode.com/problems/single-number/' target='_blank'>LeetCode 136</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [4,1,2,1,2], Output: 4<br><br><b>Note (Constraint):</b> Linear runtime and constant extra space.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Single Element array:</b> The loop just processes one element and returns it.</td>
      <td><b>Explanation:</b> XOR property: `A ^ A = 0` and `A ^ 0 = A`. XOR all elements together, duplicates cancel out, leaving only the single element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int singleNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int result = 0;&#10;    for(int num : nums) {&#10;        result ^= num;&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Arr 10 Sort Colors Dnf<br><br></b> <a href='https://leetcode.com/problems/sort-colors/' target='_blank'>LeetCode 75</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [2,0,2,1,1,0], Output: [0,0,1,1,2,2]<br><br><b>Note (Constraint):</b> Do not use library sort. Use single pass.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::swap</code></td>
      <td><b>Mid pointer increment:</b> When swapping with `high`, we do NOT increment `mid` because the swapped element from `high` needs to be evaluated.</td>
      <td><b>Explanation:</b> Dutch National Flag Algorithm (3 pointers). `low` tracks 0s, `mid` scans array, `high` tracks 2s. Swap elements to maintain sections.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void sortColors(std::vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, mid = 0, high = nums.size() - 1;&#10;    while (mid &lt;= high) {&#10;        if (nums[mid] == 0) {&#10;            std::swap(nums[low], nums[mid]);&#10;            low++; mid++;&#10;        } else if (nums[mid] == 1) {&#10;            mid++;&#10;        } else {&#10;            std::swap(nums[mid], nums[high]);&#10;            high--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Arr 11 Majority Element<br><br></b> <a href='https://leetcode.com/problems/majority-element/' target='_blank'>LeetCode 169</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [2,2,1,1,1,2,2], Output: 2</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Verification phase:</b> If it's not guaranteed a majority exists, a second `O(N)` pass is required to count the candidate. (Leetcode guarantees it exists).</td>
      <td><b>Explanation:</b> Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, candidate = 0;&#10;    for (int num : nums) {&#10;        if (count == 0) candidate = num;&#10;        if (num == candidate) count++;&#10;        else count--;&#10;    }&#10;    return candidate;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Arr 12 Kadanes Algorithm Max Subarray Sum<br><br></b> <a href='https://leetcode.com/problems/maximum-subarray/' target='_blank'>LeetCode 53</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [-2,1,-3,4,-1,2,1,-5,4], Output: 6 (Subarray [4,-1,2,1])</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::max</code></td>
      <td><b>All Negative Numbers:</b> Initialize `max_sum` with `INT_MIN` or `nums[0]` so it can correctly return the smallest negative number instead of 0.</td>
      <td><b>Explanation:</b> Kadane's Algorithm. Keep a running sum. If sum becomes negative, reset it to 0 (a negative prefix will never help a future subarray).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;#include &lt;limits.h&gt;&#10;&#10;int maxSubArray(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_sum = INT_MIN;&#10;    int current_sum = 0;&#10;    for(int num : nums) {&#10;        current_sum += num;&#10;        max_sum = std::max(max_sum, current_sum);&#10;        if(current_sum &lt; 0) current_sum = 0;&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Arr 13 Best Time To Buy And Sell Stock<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock/' target='_blank'>LeetCode 121</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: prices = [7,1,5,3,6,4], Output: 5</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::max</code>, <code>std::min</code></td>
      <td><b>No Profit Possible:</b> `max_profit` initializes at 0. If price strictly decreases, it never updates and naturally returns 0.</td>
      <td><b>Explanation:</b> Iterate while keeping track of the minimum price seen so far. Subtract this min from the current price to find potential profit.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int maxProfit(std::vector&lt;int&gt;&amp; prices) {&#10;    int min_price = prices[0];&#10;    int max_profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        max_profit = std::max(max_profit, prices[i] - min_price);&#10;        min_price = std::min(min_price, prices[i]);&#10;    }&#10;    return max_profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Arr 15 Next Permutation<br><br></b> <a href='https://leetcode.com/problems/next-permutation/' target='_blank'>LeetCode 31</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,2,3], Output: [1,3,2]<br><b>Example 2:</b> Input: nums = [3,2,1], Output: [1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::reverse</code></td>
      <td><b>Last Permutation:</b> If break point is not found (`i < 0`), it means the array is sorted descending. Just reverse the entire array to get the lowest permutation.</td>
      <td><b>Explanation:</b> 1. Find break point (i) where arr[i] < arr[i+1]. 2. Swap it with smallest element > arr[i] from the back. 3. Reverse the right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void nextPermutation(std::vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), i = n - 2;&#10;    while (i &gt;= 0 &amp;&amp; nums[i] &gt;= nums[i + 1]) i--;&#10;    &#10;    if (i &gt;= 0) {&#10;        int j = n - 1;&#10;        while (nums[j] &lt;= nums[i]) j--;&#10;        std::swap(nums[i], nums[j]);&#10;    }&#10;    std::reverse(nums.begin() + i + 1, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Arr 16 Pascals Triangle<br><br></b> <a href='https://leetcode.com/problems/pascals-triangle/' target='_blank'>LeetCode 118</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: numRows = 5, Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(N<sup>2</sup>) (Constraint)</td>
      <td>-</td>
      <td><b>Boundary 1s:</b> First and last elements of every row are always 1. Pre-filling row with 1s avoids out-of-bounds checks.</td>
      <td><b>Explanation:</b> Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; generate(int numRows) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans(numRows);&#10;    for(int i = 0; i &lt; numRows; i++) {&#10;        ans[i].resize(i + 1, 1);&#10;        for(int j = 1; j &lt; i; j++) {&#10;            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Arr 17 Majority Element Ii<br><br></b> <a href='https://leetcode.com/problems/majority-element-ii/' target='_blank'>LeetCode 229</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [3,2,3], Output: [3]<br><br><b>Note (Constraint):</b> Time O(N), Space O(1).</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Verification phase required:</b> We MUST perform a second pass to count occurrences of `candidate1` and `candidate2` because it's not guaranteed they appear > N/3 times.</td>
      <td><b>Explanation:</b> Extended Moore's Voting Algorithm. At most TWO elements can appear > N/3 times. Track two candidates and two counters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;int&gt; majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;&#10;    for(int num : nums) {&#10;        if(cnt1 == 0 &amp;&amp; num != el2) {&#10;            cnt1 = 1; el1 = num;&#10;        } else if(cnt2 == 0 &amp;&amp; num != el1) {&#10;            cnt2 = 1; el2 = num;&#10;        } else if(num == el1) cnt1++;&#10;        else if(num == el2) cnt2++;&#10;        else {&#10;            cnt1--; cnt2--;&#10;        }&#10;    }&#10;    cnt1 = 0; cnt2 = 0;&#10;    for(int num : nums) {&#10;        if(num == el1) cnt1++;&#10;        if(num == el2) cnt2++;&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    if(cnt1 &gt; nums.size() / 3) ans.push_back(el1);&#10;    if(cnt2 &gt; nums.size() / 3) ans.push_back(el2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Arr 18 3Sum<br><br></b> <a href='https://leetcode.com/problems/3sum/' target='_blank'>LeetCode 15</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [-1,0,1,2,-1,-4], Output: [[-1,-1,2],[-1,0,1]]<br><br><b>Note (Constraint):</b> Solution set must not contain duplicate triplets.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Trade-off)</td>
      <td><code>std::sort</code></td>
      <td><b>Duplicate skipping:</b> To prevent duplicate triplets, skip identical adjacent elements for `i`, `j`, and `k`.</td>
      <td><b>Explanation:</b> Sort the array. Use a loop to fix `i`, then use a Two-Pointer approach (`j`, `k`) for the remaining array to find sum `0 - nums[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; threeSum(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::sort(nums.begin(), nums.end());&#10;    int n = nums.size();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        int j = i + 1, k = n - 1;&#10;        while(j &lt; k) {&#10;            int sum = nums[i] + nums[j] + nums[k];&#10;            if(sum &lt; 0) j++;&#10;            else if(sum &gt; 0) k--;&#10;            else {&#10;                ans.push_back({nums[i], nums[j], nums[k]});&#10;                j++; k--;&#10;                while(j &lt; k &amp;&amp; nums[j] == nums[j-1]) j++;&#10;                while(j &lt; k &amp;&amp; nums[k] == nums[k+1]) k--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Arr 19 Merge Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: intervals = [[1,3],[2,6],[8,10],[15,18]], Output: [[1,6],[8,10],[15,18]]</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><code>std::sort</code></td>
      <td><b>Subsumed Intervals:</b> `[1,4]` and `[2,3]` -> using `max()` prevents shrinking the end time to `3`.</td>
      <td><b>Explanation:</b> Sort the intervals based on the start time. Iterate and merge: if current start <= previous end, update previous end to `max(prev_end, curr_end)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; merge(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if (intervals.empty()) return {};&#10;    std::sort(intervals.begin(), intervals.end());&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; merged;&#10;    merged.push_back(intervals[0]);&#10;    for (int i = 1; i &lt; intervals.size(); i++) {&#10;        if (intervals[i][0] &lt;= merged.back()[1]) {&#10;            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);&#10;        } else {&#10;            merged.push_back(intervals[i]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
