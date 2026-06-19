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
      <td>1</td>
      <td>Arr 01 Largest Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/largest-element-in-array/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: A = [1, 8, 7, 56, 90], Output: 90</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Initialization:</b> Initialize `max_val` with the first element or negative infinity.</td>
      <td><b>Explanation:</b> Iterate through the array maintaining a variable for the maximum element seen so far.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int max_val = arr[0];&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &gt; max_val) {&#10;            max_val = arr[i];&#10;        }&#10;    }&#10;    return max_val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Arr 02 Second Largest Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/second-largest3735/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: arr = [12, 35, 1, 10, 34, 1], Output: 34<br><br><b>Note (Constraint):</b> Find it in a single pass O(N) time.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>No Second Largest:</b> If all elements are same or array size < 2, return -1.</td>
      <td><b>Explanation:</b> Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int print2largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int largest = -1, second_largest = -1;&#10;    for (int num : arr) {&#10;        if (num &gt; largest) {&#10;            second_largest = largest;&#10;            largest = num;&#10;        } else if (num &gt; second_largest &amp;&amp; num != largest) {&#10;            second_largest = num;&#10;        }&#10;    }&#10;    return second_largest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Arr 03 Check If Array Is Sorted And Rotated<br><br></b> <a href='https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/' target='_blank'>LeetCode 1752</a></td>
      <td><b>Example 1:</b> Input: nums = [3,4,5,1,2], Output: true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Circular Check:</b> We must also check the boundary between the last and first element `nums[n-1] > nums[0]`.</td>
      <td><b>Explanation:</b> Count the number of "breaks" where `nums[i] > nums[i+1]`. For a sorted and rotated array, there can be at most 1 break.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;bool check(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, n = nums.size();&#10;    for (int i = 0; i &lt; n; i++) {&#10;        if (nums[i] &gt; nums[(i + 1) % n]) {&#10;            count++;&#10;        }&#10;    }&#10;    return count &lt;= 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Arr 04 Remove Duplicates From Sorted Array<br><br></b> <a href='https://leetcode.com/problems/remove-duplicates-from-sorted-array/' target='_blank'>LeetCode 26</a></td>
      <td><b>Example 1:</b> Input: nums = [1,1,2], Output: 2, nums = [1,2,_]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Empty Array:</b> Handled automatically if `n=0`.</td>
      <td><b>Explanation:</b> Two-pointer approach. Pointer `i` keeps track of unique elements, pointer `j` scans the array to find new unique elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int removeDuplicates(std::vector&lt;int&gt;&amp; nums) {&#10;    if (nums.empty()) return 0;&#10;    int i = 0;&#10;    for (int j = 1; j &lt; nums.size(); j++) {&#10;        if (nums[j] != nums[i]) {&#10;            i++;&#10;            nums[i] = nums[j];&#10;        }&#10;    }&#10;    return i + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Arr 05 Rotate Array<br><br></b> <a href='https://leetcode.com/problems/rotate-array/' target='_blank'>LeetCode 189</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3,4,5,6,7], k = 3, Output: [5,6,7,1,2,3,4]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::reverse</code></td>
      <td><b>K > N:</b> k might be greater than array length, so perform `k = k % n` first.</td>
      <td><b>Explanation:</b> Reverse Algorithm. Reverse the whole array, then reverse the first `k` elements, then reverse the remaining `N-k` elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void rotate(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    std::reverse(nums.begin(), nums.end());&#10;    std::reverse(nums.begin(), nums.begin() + k);&#10;    std::reverse(nums.begin() + k, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Arr 06 Move Zeroes<br><br></b> <a href='https://leetcode.com/problems/move-zeroes/' target='_blank'>LeetCode 283</a></td>
      <td><b>Example 1:</b> Input: nums = [0,1,0,3,12], Output: [1,3,12,0,0]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::swap</code></td>
      <td><b>No zeroes:</b> Swaps element with itself initially, no overhead.</td>
      <td><b>Explanation:</b> Two-pointer approach (Snowball method). Pointer `i` tracks the first zero found, pointer `j` scans for non-zeroes to swap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void moveZeroes(std::vector&lt;int&gt;&amp; nums) {&#10;    int i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(nums[j] != 0) {&#10;            std::swap(nums[i], nums[j]);&#10;            i++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Arr 07 Missing Number<br><br></b> <a href='https://leetcode.com/problems/missing-number/' target='_blank'>LeetCode 268</a></td>
      <td><b>Example 1:</b> Input: nums = [3,0,1], Output: 2</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Mathematical Sum alternative:</b> Gaussian sum formula `N*(N+1)/2` can cause integer overflow, XOR completely bypasses overflow risks.</td>
      <td><b>Explanation:</b> Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int missingNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int res = nums.size();&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        res ^= i ^ nums[i];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Arr 08 Max Consecutive Ones<br><br></b> <a href='https://leetcode.com/problems/max-consecutive-ones/' target='_blank'>LeetCode 485</a></td>
      <td><b>Example 1:</b> Input: nums = [1,1,0,1,1,1], Output: 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::max</code></td>
      <td><b>Trailing Ones:</b> Must perform a final max check outside the loop or update max dynamically inside.</td>
      <td><b>Explanation:</b> Iterate while counting 1s. If a 0 is found, update max count and reset current count to 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int findMaxConsecutiveOnes(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_cnt = 0, current_cnt = 0;&#10;    for(int num : nums) {&#10;        if(num == 1) {&#10;            current_cnt++;&#10;            max_cnt = std::max(max_cnt, current_cnt);&#10;        } else {&#10;            current_cnt = 0;&#10;        }&#10;    }&#10;    return max_cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Arr 09 Single Number<br><br></b> <a href='https://leetcode.com/problems/single-number/' target='_blank'>LeetCode 136</a></td>
      <td><b>Example 1:</b> Input: nums = [4,1,2,1,2], Output: 4<br><br><b>Note (Constraint):</b> Linear runtime and constant extra space.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Single Element array:</b> The loop just processes one element and returns it.</td>
      <td><b>Explanation:</b> XOR property: `A ^ A = 0` and `A ^ 0 = A`. XOR all elements together, duplicates cancel out, leaving only the single element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int singleNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int result = 0;&#10;    for(int num : nums) {&#10;        result ^= num;&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Arr 10 Sort Colors Dnf<br><br></b> <a href='https://leetcode.com/problems/sort-colors/' target='_blank'>LeetCode 75</a></td>
      <td><b>Example 1:</b> Input: nums = [2,0,2,1,1,0], Output: [0,0,1,1,2,2]<br><br><b>Note (Constraint):</b> Do not use library sort. Use single pass.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::swap</code></td>
      <td><b>Mid pointer increment:</b> When swapping with `high`, we do NOT increment `mid` because the swapped element from `high` needs to be evaluated.</td>
      <td><b>Explanation:</b> Dutch National Flag Algorithm (3 pointers). `low` tracks 0s, `mid` scans array, `high` tracks 2s. Swap elements to maintain sections.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void sortColors(std::vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, mid = 0, high = nums.size() - 1;&#10;    while (mid &lt;= high) {&#10;        if (nums[mid] == 0) {&#10;            std::swap(nums[low], nums[mid]);&#10;            low++; mid++;&#10;        } else if (nums[mid] == 1) {&#10;            mid++;&#10;        } else {&#10;            std::swap(nums[mid], nums[high]);&#10;            high--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Arr 11 Majority Element<br><br></b> <a href='https://leetcode.com/problems/majority-element/' target='_blank'>LeetCode 169</a></td>
      <td><b>Example 1:</b> Input: nums = [2,2,1,1,1,2,2], Output: 2</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Verification phase:</b> If it's not guaranteed a majority exists, a second `O(N)` pass is required to count the candidate. (Leetcode guarantees it exists).</td>
      <td><b>Explanation:</b> Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, candidate = 0;&#10;    for (int num : nums) {&#10;        if (count == 0) candidate = num;&#10;        if (num == candidate) count++;&#10;        else count--;&#10;    }&#10;    return candidate;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Arr 12 Kadanes Algorithm Max Subarray Sum<br><br></b> <a href='https://leetcode.com/problems/maximum-subarray/' target='_blank'>LeetCode 53</a></td>
      <td><b>Example 1:</b> Input: nums = [-2,1,-3,4,-1,2,1,-5,4], Output: 6 (Subarray [4,-1,2,1])</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::max</code></td>
      <td><b>All Negative Numbers:</b> Initialize `max_sum` with `INT_MIN` or `nums[0]` so it can correctly return the smallest negative number instead of 0.</td>
      <td><b>Explanation:</b> Kadane's Algorithm. Keep a running sum. If sum becomes negative, reset it to 0 (a negative prefix will never help a future subarray).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;#include &lt;limits.h&gt;&#10;&#10;int maxSubArray(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_sum = INT_MIN;&#10;    int current_sum = 0;&#10;    for(int num : nums) {&#10;        current_sum += num;&#10;        max_sum = std::max(max_sum, current_sum);&#10;        if(current_sum &lt; 0) current_sum = 0;&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Arr 13 Best Time To Buy And Sell Stock<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock/' target='_blank'>LeetCode 121</a></td>
      <td><b>Example 1:</b> Input: prices = [7,1,5,3,6,4], Output: 5</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::max</code>, <code>std::min</code></td>
      <td><b>No Profit Possible:</b> `max_profit` initializes at 0. If price strictly decreases, it never updates and naturally returns 0.</td>
      <td><b>Explanation:</b> Iterate while keeping track of the minimum price seen so far. Subtract this min from the current price to find potential profit.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int maxProfit(std::vector&lt;int&gt;&amp; prices) {&#10;    int min_price = prices[0];&#10;    int max_profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        max_profit = std::max(max_profit, prices[i] - min_price);&#10;        min_price = std::min(min_price, prices[i]);&#10;    }&#10;    return max_profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Arr 14 Rearrange Array Elements By Sign<br><br></b> <a href='https://leetcode.com/problems/rearrange-array-elements-by-sign/' target='_blank'>LeetCode 2149</a></td>
      <td><b>Example 1:</b> Input: nums = [3,1,-2,-5,2,-4], Output: [3,-2,1,-5,2,-4]<br><br><b>Note (Constraint):</b> Maintain relative order.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>-</td>
      <td><b>In-Place Attempt:</b> Doing this in-place `O(1)` space while maintaining relative order drops Time to `O(N^2)`. The optimal tradeoff is `O(N)` space.</td>
      <td><b>Explanation:</b> Use two pointers, `pos_idx` starting at 0, `neg_idx` starting at 1. Traverse and place elements directly into a new result array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;int&gt; rearrangeArray(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; ans(nums.size());&#10;    int pos_idx = 0, neg_idx = 1;&#10;    for (int num : nums) {&#10;        if (num &gt; 0) {&#10;            ans[pos_idx] = num;&#10;            pos_idx += 2;&#10;        } else {&#10;            ans[neg_idx] = num;&#10;            neg_idx += 2;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Arr 15 Next Permutation<br><br></b> <a href='https://leetcode.com/problems/next-permutation/' target='_blank'>LeetCode 31</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [1,3,2]<br><b>Example 2:</b> Input: nums = [3,2,1], Output: [1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>std::reverse</code></td>
      <td><b>Last Permutation:</b> If break point is not found (`i < 0`), it means the array is sorted descending. Just reverse the entire array to get the lowest permutation.</td>
      <td><b>Explanation:</b> 1. Find break point (i) where arr[i] < arr[i+1]. 2. Swap it with smallest element > arr[i] from the back. 3. Reverse the right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void nextPermutation(std::vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), i = n - 2;&#10;    while (i &gt;= 0 &amp;&amp; nums[i] &gt;= nums[i + 1]) i--;&#10;    &#10;    if (i &gt;= 0) {&#10;        int j = n - 1;&#10;        while (nums[j] &lt;= nums[i]) j--;&#10;        std::swap(nums[i], nums[j]);&#10;    }&#10;    std::reverse(nums.begin() + i + 1, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Arr 16 Pascals Triangle<br><br></b> <a href='https://leetcode.com/problems/pascals-triangle/' target='_blank'>LeetCode 118</a></td>
      <td><b>Example 1:</b> Input: numRows = 5, Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(N<sup>2</sup>) (Constraint)</td>
      <td>-</td>
      <td><b>Boundary 1s:</b> First and last elements of every row are always 1. Pre-filling row with 1s avoids out-of-bounds checks.</td>
      <td><b>Explanation:</b> Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; generate(int numRows) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans(numRows);&#10;    for(int i = 0; i &lt; numRows; i++) {&#10;        ans[i].resize(i + 1, 1);&#10;        for(int j = 1; j &lt; i; j++) {&#10;            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Arr 17 Majority Element Ii<br><br></b> <a href='https://leetcode.com/problems/majority-element-ii/' target='_blank'>LeetCode 229</a></td>
      <td><b>Example 1:</b> Input: nums = [3,2,3], Output: [3]<br><br><b>Note (Constraint):</b> Time O(N), Space O(1).</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Verification phase required:</b> We MUST perform a second pass to count occurrences of `candidate1` and `candidate2` because it's not guaranteed they appear > N/3 times.</td>
      <td><b>Explanation:</b> Extended Moore's Voting Algorithm. At most TWO elements can appear > N/3 times. Track two candidates and two counters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;int&gt; majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;&#10;    for(int num : nums) {&#10;        if(cnt1 == 0 &amp;&amp; num != el2) {&#10;            cnt1 = 1; el1 = num;&#10;        } else if(cnt2 == 0 &amp;&amp; num != el1) {&#10;            cnt2 = 1; el2 = num;&#10;        } else if(num == el1) cnt1++;&#10;        else if(num == el2) cnt2++;&#10;        else {&#10;            cnt1--; cnt2--;&#10;        }&#10;    }&#10;    cnt1 = 0; cnt2 = 0;&#10;    for(int num : nums) {&#10;        if(num == el1) cnt1++;&#10;        if(num == el2) cnt2++;&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    if(cnt1 &gt; nums.size() / 3) ans.push_back(el1);&#10;    if(cnt2 &gt; nums.size() / 3) ans.push_back(el2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Arr 18 3Sum<br><br></b> <a href='https://leetcode.com/problems/3sum/' target='_blank'>LeetCode 15</a></td>
      <td><b>Example 1:</b> Input: nums = [-1,0,1,2,-1,-4], Output: [[-1,-1,2],[-1,0,1]]<br><br><b>Note (Constraint):</b> Solution set must not contain duplicate triplets.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Trade-off)</td>
      <td><code>std::sort</code></td>
      <td><b>Duplicate skipping:</b> To prevent duplicate triplets, skip identical adjacent elements for `i`, `j`, and `k`.</td>
      <td><b>Explanation:</b> Sort the array. Use a loop to fix `i`, then use a Two-Pointer approach (`j`, `k`) for the remaining array to find sum `0 - nums[i]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; threeSum(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::sort(nums.begin(), nums.end());&#10;    int n = nums.size();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        int j = i + 1, k = n - 1;&#10;        while(j &lt; k) {&#10;            int sum = nums[i] + nums[j] + nums[k];&#10;            if(sum &lt; 0) j++;&#10;            else if(sum &gt; 0) k--;&#10;            else {&#10;                ans.push_back({nums[i], nums[j], nums[k]});&#10;                j++; k--;&#10;                while(j &lt; k &amp;&amp; nums[j] == nums[j-1]) j++;&#10;                while(j &lt; k &amp;&amp; nums[k] == nums[k+1]) k--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Arr 19 Merge Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td><b>Example 1:</b> Input: intervals = [[1,3],[2,6],[8,10],[15,18]], Output: [[1,6],[8,10],[15,18]]</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><code>std::sort</code></td>
      <td><b>Subsumed Intervals:</b> `[1,4]` and `[2,3]` -> using `max()` prevents shrinking the end time to `3`.</td>
      <td><b>Explanation:</b> Sort the intervals based on the start time. Iterate and merge: if current start <= previous end, update previous end to `max(prev_end, curr_end)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; merge(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if (intervals.empty()) return {};&#10;    std::sort(intervals.begin(), intervals.end());&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; merged;&#10;    merged.push_back(intervals[0]);&#10;    for (int i = 1; i &lt; intervals.size(); i++) {&#10;        if (intervals[i][0] &lt;= merged.back()[1]) {&#10;            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);&#10;        } else {&#10;            merged.push_back(intervals[i]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Arr 20 Leaders In An Array<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: A = [16,17,4,3,5,2], Output: [17,5,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output</td>
      <td><code>#include <algorithm></code></td>
      <td><b>Rightmost element:</b> Always a leader.</td>
      <td><b>Explanation:</b> Traverse the array from right to left. Keep track of the maximum element seen so far. If the current element is greater than or equal to the max, it's a leader. Reverse the collected leaders at the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; leaders(int a[], int n){&#10;    vector&lt;int&gt; ans;&#10;    int maxi = a[n - 1];&#10;    ans.push_back(maxi);&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        if(a[i] &gt;= maxi) {&#10;            ans.push_back(a[i]);&#10;            maxi = a[i];&#10;        }&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Arr 21 Set Matrix Zeroes<br><br></b> <a href='https://leetcode.com/problems/set-matrix-zeroes/' target='_blank'>LeetCode 73</a></td>
      <td><b>Example 1:</b> Input: matrix = [[1,1,1],[1,0,1],[1,1,1]], Output: [[1,0,1],[0,0,0],[1,0,1]]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Zeros in first row/col:</b> Handled accurately by checking `col0` flag at the end.</td>
      <td><b>Explanation:</b> Use the first row and first column as marker arrays to save space. We need a separate variable for the first column (or row) to avoid overlapping states.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void setZeroes(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size(), col0 = 1;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(matrix[i][0] == 0) col0 = 0;&#10;        for(int j=1; j&lt;m; j++)&#10;            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;&#10;    }&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        for(int j=m-1; j&gt;=1; j--)&#10;            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;&#10;        if(col0 == 0) matrix[i][0] = 0;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Arr 22 Rotate Image<br><br></b> <a href='https://leetcode.com/problems/rotate-image/' target='_blank'>LeetCode 48</a></td>
      <td><b>Example 1:</b> Input: matrix = [[1,2,3],[4,5,6],[7,8,9]], Output: [[7,4,1],[8,5,2],[9,6,3]]</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><code>#include <algorithm></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Transpose the matrix (swap matrix[i][j] with matrix[j][i]), then reverse every row.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;i; j++) std::swap(matrix[i][j], matrix[j][i]);&#10;    }&#10;    for(int i=0; i&lt;n; i++) std::reverse(matrix[i].begin(), matrix[i].end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Arr 23 Spiral Matrix<br><br></b> <a href='https://leetcode.com/problems/spiral-matrix/' target='_blank'>LeetCode 54</a></td>
      <td><b>Example 1:</b> Input: matrix = [[1,2,3],[4,5,6],[7,8,9]], Output: [1,2,3,6,9,8,7,4,5]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) for output</td>
      <td>-</td>
      <td><b>Single row/col matrix:</b> Internal boundary checks prevent duplicate counting.</td>
      <td><b>Explanation:</b> Maintain 4 pointers: top, bottom, left, right. Traverse Top row, Right col, Bottom row, Left col, shrinking boundaries inwards.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; spiralOrder(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    vector&lt;int&gt; ans;&#10;    int top=0, left=0, bottom=matrix.size()-1, right=matrix[0].size()-1;&#10;    while(top&lt;=bottom &amp;&amp; left&lt;=right) {&#10;        for(int i=left; i&lt;=right; i++) ans.push_back(matrix[top][i]);&#10;        top++;&#10;        for(int i=top; i&lt;=bottom; i++) ans.push_back(matrix[i][right]);&#10;        right--;&#10;        if(top&lt;=bottom) {&#10;            for(int i=right; i&gt;=left; i--) ans.push_back(matrix[bottom][i]);&#10;            bottom--;&#10;        }&#10;        if(left&lt;=right) {&#10;            for(int i=bottom; i&gt;=top; i--) ans.push_back(matrix[i][left]);&#10;            left++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Arr 24 4Sum<br><br></b> <a href='https://leetcode.com/problems/4sum/' target='_blank'>LeetCode 18</a></td>
      <td><b>Example 1:</b> Input: nums = [1,0,-1,0,-2,2], target = 0, Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1) auxiliary</td>
      <td><code>#include <algorithm></code></td>
      <td><b>Integer Overflow:</b> Use `long long` when computing sum of 4 integers.</td>
      <td><b>Explanation:</b> Sort array. Use 2 nested loops (i, j) for the first two numbers, and Two Pointers (k, l) for the remaining two. Skip duplicates carefully.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt;&amp; nums, int target) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = nums.size(); sort(nums.begin(), nums.end());&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(i&gt;0 &amp;&amp; nums[i]==nums[i-1]) continue;&#10;        for(int j=i+1; j&lt;n; j++) {&#10;            if(j&gt;i+1 &amp;&amp; nums[j]==nums[j-1]) continue;&#10;            int k = j+1, l = n-1;&#10;            while(k &lt; l) {&#10;                long long sum = nums[i] + nums[j]; sum += nums[k]; sum += nums[l];&#10;                if(sum == target) {&#10;                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});&#10;                    k++; l--;&#10;                    while(k&lt;l &amp;&amp; nums[k]==nums[k-1]) k++;&#10;                    while(k&lt;l &amp;&amp; nums[l]==nums[l+1]) l--;&#10;                } else if(sum &lt; target) k++;&#10;                else l--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Arr 25 Count Subarrays With Given Xor K<br><br></b> <a href='https://www.interviewbit.com/problems/subarray-with-given-xor/' target='_blank'>InterviewBit</a></td>
      <td><b>Example 1:</b> Input: A = [4, 2, 2, 6, 4], B = 6, Output: 4</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map></code></td>
      <td><b>XOR exactly equals B:</b> Insert `mpp[0] = 1` initially to cover subarrays starting from index 0.</td>
      <td><b>Explanation:</b> Use a Hash Map to store the frequency of prefix XORs. For each element, current XOR `xr ^= A[i]`. We need `xr ^ B`. If it exists in map, add its frequency to count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solve(vector&lt;int&gt; &amp;A, int B) {&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int xr = 0, count = 0;&#10;    mpp[xr]++;&#10;    for(int i=0; i&lt;A.size(); i++) {&#10;        xr ^= A[i];&#10;        int x = xr ^ B;&#10;        if(mpp.find(x) != mpp.end()) count += mpp[x];&#10;        mpp[xr]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Arr 26 Find The Duplicate Number<br><br></b> <a href='https://leetcode.com/problems/find-the-duplicate-number/' target='_blank'>LeetCode 287</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,4,2,2], Output: 2</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Floyd's Tortoise and Hare (Cycle Detection). Fast and slow pointer. Guaranteed cycle because of Pigeonhole Principle (numbers map to index ranges).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDuplicate(vector&lt;int&gt;&amp; nums) {&#10;    int slow = nums[0], fast = nums[0];&#10;    do {&#10;        slow = nums[slow];&#10;        fast = nums[nums[fast]];&#10;    } while(slow != fast);&#10;    fast = nums[0];&#10;    while(slow != fast) {&#10;        slow = nums[slow];&#10;        fast = nums[fast];&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Arr 27 Find Missing And Repeating<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 2, Arr[] = {2, 2}, Output: 2 1</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Integer Overflow:</b> Summing squares of 10^5 elements exceeds 32-bit INT, requiring long long.</td>
      <td><b>Explanation:</b> Mathematical approach. Diff = Sum_N - Sum_Arr = Missing - Repeating. SumSqDiff = SumSq_N - SumSq_Arr = Missing^2 - Repeating^2. Use formulas to solve for both.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findTwoElement(vector&lt;int&gt; arr, int n) {&#10;    long long N = n;&#10;    long long S_N = (N * (N+1)) / 2;&#10;    long long Sq_N = (N * (N+1) * (2*N+1)) / 6;&#10;    long long S = 0, Sq = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        S += arr[i]; Sq += (long long)arr[i] * (long long)arr[i];&#10;    }&#10;    long long val1 = S_N - S; // X - Y&#10;    long long val2 = Sq_N - Sq; // X^2 - Y^2&#10;    val2 = val2 / val1; // X + Y&#10;    long long x = (val1 + val2) / 2;&#10;    long long y = x - val1;&#10;    return {(int)y, (int)x};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Arr 28 Merge Two Sorted Arrays Without Extra Space<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> arr1=[1,3,5,7], arr2=[0,2,6,8,9], Output: arr1=[0,1,2,3], arr2=[5,6,7,8,9]</td>
      <td><b>Time:</b> O((N+M) log(N+M))<br><b>Space:</b> O(1)</td>
      <td><code>#include <algorithm></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Start pointers at end of arr1 (i) and beginning of arr2 (j). Swap if arr1[i] > arr2[j]. Afterwards, individually sort arr1 and arr2. Time is bounded by sorting.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(long long arr1[], long long arr2[], int n, int m) {&#10;    int left = n - 1, right = 0;&#10;    while(left &gt;= 0 &amp;&amp; right &lt; m) {&#10;        if(arr1[left] &gt; arr2[right]) { swap(arr1[left], arr2[right]); left--; right++; }&#10;        else break;&#10;    }&#10;    sort(arr1, arr1 + n); sort(arr2, arr2 + m);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Arr 29 Maximum Product Subarray<br><br></b> <a href='https://leetcode.com/problems/maximum-product-subarray/' target='_blank'>LeetCode 152</a></td>
      <td><b>Example 1:</b> Input: nums = [2,3,-2,4], Output: 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>Odd negative numbers:</b> Checking both prefix and suffix elegantly covers the case where we drop one negative.</td>
      <td><b>Explanation:</b> Maintain prefix and suffix products. If a 0 is encountered, reset the product to 1. The max overall is the answer since negatives cancel out in pairs.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProduct(vector&lt;int&gt;&amp; nums) {&#10;    double pref = 1, suff = 1, ans = INT_MIN;&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= nums[i];&#10;        suff *= nums[n-i-1];&#10;        ans = max({ans, pref, suff});&#10;    }&#10;    return (int)ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Arr 30 Count Inversions<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {2, 4, 1, 3, 5}, Output: 3</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N) auxiliary</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Merge Sort approach. While merging two sorted halves, if left[i] > right[j], it forms an inversion with all remaining elements in the left half (mid - i + 1).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], int low, int mid, int high) {&#10;    vector&lt;long long&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    long long cnt = 0;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else { temp.push_back(arr[right++]); cnt += (mid - left + 1); }&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;    return cnt;&#10;}&#10;long long mergeSort(long long arr[], int low, int high) {&#10;    long long cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    return mergeSort(arr, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Arr 31 Reverse Pairs<br><br></b> <a href='https://leetcode.com/problems/reverse-pairs/' target='_blank'>LeetCode 493</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,2,3,1], Output: 2</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Integer Overflow:</b> Use long long when doubling nums[j].</td>
      <td><b>Explanation:</b> Modified Merge Sort. Before merging, loop through left and right halves. If left[i] > 2 * right[j], increment j. Number of pairs is (j - (mid+1)).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;}&#10;int countPairs(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    int right = mid + 1, cnt = 0;&#10;    for(int i = low; i &lt;= mid; i++) {&#10;        while(right &lt;= high &amp;&amp; arr[i] &gt; 2LL * arr[right]) right++;&#10;        cnt += (right - (mid + 1));&#10;    }&#10;    return cnt;&#10;}&#10;int mergeSort(vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += countPairs(arr, low, mid, high);&#10;    merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;int reversePairs(vector&lt;int&gt;&amp; nums) {&#10;    return mergeSort(nums, 0, nums.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Arr 21 Merge Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td><b>Example 1:</b> Input: intervals = [[1,3],[2,6],[8,10],[15,18]], Output: [[1,6],[8,10],[15,18]]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Empty Array:</b> Return empty array.</td>
      <td><b>Explanation:</b> Sort the intervals based on the starting times. Iterate through the intervals, if the current interval overlaps with the last merged interval, update the end time of the last merged interval.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; merge(vector&lt;vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if(intervals.empty()) return {};&#10;    sort(intervals.begin(), intervals.end());&#10;    vector&lt;vector&lt;int&gt;&gt; merged;&#10;    for(auto interval : intervals) {&#10;        if(merged.empty() || merged.back()[1] &lt; interval[0]) {&#10;            merged.push_back(interval);&#10;        } else {&#10;            merged.back()[1] = max(merged.back()[1], interval[1]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Arr 22 Next Permutation<br><br></b> <a href='https://leetcode.com/problems/next-permutation/' target='_blank'>LeetCode 31</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3], Output: [1,3,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Array is sorted in descending order:</b> Step 1 fails. Simply reverse the entire array.</td>
      <td><b>Explanation:</b> 1. Find the largest index k such that nums[k] < nums[k + 1]. 2. Find the largest index l greater than k such that nums[k] < nums[l]. 3. Swap nums[k] and nums[l]. 4. Reverse the sub-array nums[k + 1:].<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void nextPermutation(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), k = -1, l = -1;&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        if(nums[i] &lt; nums[i + 1]) { k = i; break; }&#10;    }&#10;    if(k &lt; 0) { reverse(nums.begin(), nums.end()); return; }&#10;    for(int i = n - 1; i &gt; k; i--) {&#10;        if(nums[i] &gt; nums[k]) { l = i; break; }&#10;    }&#10;    swap(nums[k], nums[l]);&#10;    reverse(nums.begin() + k + 1, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Arr 23 Count Inversions<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {2, 4, 1, 3, 5}, Output: 3</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Merge Sort. While merging two sorted halves, if `left[i] > right[j]`, then all elements from `left[i]` to `left[mid]` will form inversions with `right[j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], long long temp[], int left, int mid, int right) {&#10;    int i = left, j = mid, k = left;&#10;    long long inv_count = 0;&#10;    while(i &lt;= mid - 1 &amp;&amp; j &lt;= right) {&#10;        if(arr[i] &lt;= arr[j]) temp[k++] = arr[i++];&#10;        else { temp[k++] = arr[j++]; inv_count = inv_count + (mid - i); }&#10;    }&#10;    while(i &lt;= mid - 1) temp[k++] = arr[i++];&#10;    while(j &lt;= right) temp[k++] = arr[j++];&#10;    for(i = left; i &lt;= right; i++) arr[i] = temp[i];&#10;    return inv_count;&#10;}&#10;long long _mergeSort(long long arr[], long long temp[], int left, int right) {&#10;    long long inv_count = 0;&#10;    if(right &gt; left) {&#10;        int mid = (right + left) / 2;&#10;        inv_count += _mergeSort(arr, temp, left, mid);&#10;        inv_count += _mergeSort(arr, temp, mid + 1, right);&#10;        inv_count += merge(arr, temp, left, mid + 1, right);&#10;    }&#10;    return inv_count;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    long long temp[N];&#10;    return _mergeSort(arr, temp, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Arr 24 Reverse Pairs<br><br></b> <a href='https://leetcode.com/problems/reverse-pairs/' target='_blank'>LeetCode 493</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,2,3,1], Output: 2</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Merge Sort. Before merging, iterate through the left half and right half. For each element in left, find the number of elements in right such that `left[i] > 2 * right[j]`. Add this count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int merge(vector&lt;int&gt;&amp; nums, int low, int mid, int high) {&#10;    int count = 0, j = mid + 1;&#10;    for(int i = low; i &lt;= mid; i++) {&#10;        while(j &lt;= high &amp;&amp; nums[i] &gt; 2LL * nums[j]) j++;&#10;        count += (j - (mid + 1));&#10;    }&#10;    vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(nums[left] &lt;= nums[right]) temp.push_back(nums[left++]);&#10;        else temp.push_back(nums[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(nums[left++]);&#10;    while(right &lt;= high) temp.push_back(nums[right++]);&#10;    for(int i = low; i &lt;= high; i++) nums[i] = temp[i - low];&#10;    return count;&#10;}&#10;int mergeSort(vector&lt;int&gt;&amp; nums, int low, int high) {&#10;    if(low &gt;= high) return 0;&#10;    int mid = low + (high - low) / 2;&#10;    int inv = mergeSort(nums, low, mid);&#10;    inv += mergeSort(nums, mid + 1, high);&#10;    inv += merge(nums, low, mid, high);&#10;    return inv;&#10;}&#10;int reversePairs(vector&lt;int&gt;&amp; nums) {&#10;    return mergeSort(nums, 0, nums.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Arr 25 Maximum Product Subarray<br><br></b> <a href='https://leetcode.com/problems/maximum-product-subarray/' target='_blank'>LeetCode 152</a></td>
      <td><b>Example 1:</b> Input: nums = [2,3,-2,4], Output: 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Zeroes in array:</b> When 0 is encountered, reset running product.</td>
      <td><b>Explanation:</b> Maintain the prefix product and suffix product. If a zero is encountered, reset the product to 1. The maximum product will be the maximum of all prefix and suffix products.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProduct(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    double pre = 1, suff = 1;&#10;    double ans = INT_MIN;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pre == 0) pre = 1;&#10;        if(suff == 0) suff = 1;&#10;        pre *= nums[i];&#10;        suff *= nums[n - i - 1];&#10;        ans = max({ans, pre, suff});&#10;    }&#10;    return (int)ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Arr 26 Majority Element Ii<br><br></b> <a href='https://leetcode.com/problems/majority-element-ii/' target='_blank'>LeetCode 229</a></td>
      <td><b>Example 1:</b> Input: nums = [3,2,3], Output: [3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Extended Boyer-Moore Voting Algorithm. There can be at most 2 elements appearing more than n/3 times. Maintain two candidate elements and their counts.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; majorityElement(vector&lt;int&gt;&amp; nums) {&#10;    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;&#10;    for(int el : nums) {&#10;        if(el == num1) c1++;&#10;        else if(el == num2) c2++;&#10;        else if(c1 == 0) { num1 = el; c1 = 1; }&#10;        else if(c2 == 0) { num2 = el; c2 = 1; }&#10;        else { c1--; c2--; }&#10;    }&#10;    c1 = 0; c2 = 0;&#10;    for(int el : nums) {&#10;        if(el == num1) c1++;&#10;        else if(el == num2) c2++;&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    if(c1 &gt; nums.size() / 3) ans.push_back(num1);&#10;    if(c2 &gt; nums.size() / 3) ans.push_back(num2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Arr 27 Grid Unique Paths<br><br></b> <a href='https://leetcode.com/problems/unique-paths/' target='_blank'>LeetCode 62</a></td>
      <td><b>Example 1:</b> Input: m = 3, n = 7, Output: 28</td>
      <td><b>Time:</b> O(m-1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Combinatorics approach. The total number of steps to reach the bottom-right corner is (m - 1) + (n - 1) = m + n - 2. Out of these steps, we need to choose (m - 1) downward steps (or n - 1 rightward steps). The number of paths is (m + n - 2) C (m - 1).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int uniquePaths(int m, int n) {&#10;    int N = n + m - 2;&#10;    int r = m - 1;&#10;    double res = 1;&#10;    for(int i = 1; i &lt;= r; i++) {&#10;        res = res * (N - r + i) / i;&#10;    }&#10;    return (int)res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Arr 28 Search A 2D Matrix<br><br></b> <a href='https://leetcode.com/problems/search-a-2d-matrix/' target='_blank'>LeetCode 74</a></td>
      <td><b>Example 1:</b> Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3, Output: true</td>
      <td><b>Time:</b> O(log(m * n))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Empty Matrix:</b> Return false.</td>
      <td><b>Explanation:</b> Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(!matrix.size()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int low = 0, high = (m * n) - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + (high - low) / 2);&#10;        if(matrix[mid/n][mid % n] == target) return true;&#10;        if(matrix[mid/n][mid % n] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Arr 29 Pow X N<br><br></b> <a href='https://leetcode.com/problems/powx-n/' target='_blank'>LeetCode 50</a></td>
      <td><b>Example 1:</b> Input: x = 2.00000, n = 10, Output: 1024.00000</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>n = INT_MIN:</b> Cast n to long long before making it positive to avoid overflow.</td>
      <td><b>Explanation:</b> Binary Exponentiation. If n is even, `x^n = (x*x)^(n/2)`. If n is odd, `x^n = x * x^(n-1)`. Handles negative powers by computing `1 / pow(x, -n)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    while(nn &gt; 0) {&#10;        if(nn % 2 == 1) {&#10;            ans = ans * x;&#10;            nn = nn - 1;&#10;        } else {&#10;            x = x * x;&#10;            nn = nn / 2;&#10;        }&#10;    }&#10;    if(n &lt; 0) ans = (double)(1.0) / (double)(ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Arr 30 Find The Duplicate Number<br><br></b> <a href='https://leetcode.com/problems/find-the-duplicate-number/' target='_blank'>LeetCode 287</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,4,2,2], Output: 2</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Floyd's Tortoise and Hare (Cycle Detection). Treat the array values as pointers to the next index. Since there's a duplicate, a cycle must exist. Find the intersection point of slow and fast pointers, then find the entrance to the cycle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDuplicate(vector&lt;int&gt;&amp; nums) {&#10;    int slow = nums[0], fast = nums[0];&#10;    do {&#10;        slow = nums[slow];&#10;        fast = nums[nums[fast]];&#10;    } while(slow != fast);&#10;    fast = nums[0];&#10;    while(slow != fast) {&#10;        slow = nums[slow];&#10;        fast = nums[fast];&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Array 43 Minimum Number Of Jumps<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Greedy tracking bounds.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `maxReach`, `steps`, and `jumps`. At each step `i`, `maxReach = max(maxReach, i + arr[i])`. Decrement `steps`. If `steps == 0`, `jumps++` and `steps = maxReach - i`. If `i >= maxReach`, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minJumps(int arr[], int n) {&#10;    if(n &lt;= 1) return 0;&#10;    if(arr[0] == 0) return -1;&#10;    int maxReach = arr[0], steps = arr[0], jumps = 1;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(i == n - 1) return jumps;&#10;        maxReach = max(maxReach, i + arr[i]);&#10;        steps--;&#10;        if(steps == 0) {&#10;            jumps++;&#10;            if(i &gt;= maxReach) return -1;&#10;            steps = maxReach - i;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Array 44 Find Duplicate In An Array Of N 1 Integers<br><br></b> <a href='https://leetcode.com/problems/find-the-duplicate-number/' target='_blank'>LeetCode 287</a></td>
      <td><b>Example 1:</b> Floyd's cycle finding.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Floyd's Tortoise and Hare algorithm. Initialize `slow = nums[0]` and `fast = nums[0]`. Move `slow` by 1 step (`nums[slow]`) and `fast` by 2 steps (`nums[nums[fast]]`). They will meet in a cycle. Then, reset `slow` to `nums[0]` and move both by 1 step until they meet. The meeting point is the duplicate.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDuplicate(vector&lt;int&gt;&amp; nums) {&#10;    int slow = nums[0], fast = nums[0];&#10;    do {&#10;        slow = nums[slow];&#10;        fast = nums[nums[fast]];&#10;    } while(slow != fast);&#10;    slow = nums[0];&#10;    while(slow != fast) {&#10;        slow = nums[slow];&#10;        fast = nums[fast];&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Array 45 Merge Two Sorted Arrays Without Extra Space<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Gap method (Shell sort idea).</td>
      <td><b>Time:</b> O((N + M) log(N + M))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use the Gap method. Initial gap is `ceil((n + m) / 2)`. Iterate with two pointers separated by `gap`. If `left` and `right` elements are out of order, swap them. Reduce `gap` by `ceil(gap / 2)` until `gap == 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(long long arr1[], long long arr2[], int n, int m) {&#10;    int len = n + m;&#10;    int gap = (len / 2) + (len % 2);&#10;    while(gap &gt; 0) {&#10;        int left = 0, right = left + gap;&#10;        while(right &lt; len) {&#10;            int arr1Left = left &lt; n ? arr1[left] : arr2[left - n];&#10;            int arr2Right = right &lt; n ? arr1[right] : arr2[right - n];&#10;            if(arr1Left &gt; arr2Right) {&#10;                if(left &lt; n &amp;&amp; right &lt; n) swap(arr1[left], arr1[right]);&#10;                else if(left &lt; n &amp;&amp; right &gt;= n) swap(arr1[left], arr2[right - n]);&#10;                else swap(arr2[left - n], arr2[right - n]);&#10;            }&#10;            left++; right++;&#10;        }&#10;        if(gap &lt;= 1) break;&#10;        gap = (gap / 2) + (gap % 2);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Array 46 Kadanes Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Keep tracking current sum.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `max_sum` and `curr_sum`. For each element, `curr_sum = max(element, curr_sum + element)`. `max_sum = max(max_sum, curr_sum)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxSubarraySum(int arr[], int n) {&#10;    long long maxSum = arr[0], currSum = arr[0];&#10;    for(int i = 1; i &lt; n; i++) {&#10;        currSum = max((long long)arr[i], currSum + arr[i]);&#10;        maxSum = max(maxSum, currSum);&#10;    }&#10;    return maxSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Array 47 Merge Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td><b>Example 1:</b> Sort and merge.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the intervals based on the starting time. Create a result list and add the first interval. For subsequent intervals, if the current interval's start time is <= the last merged interval's end time, update the end time of the last merged interval to `max(last.end, current.end)`. Else, add the current interval to the result list.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; merge(vector&lt;vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if(intervals.empty()) return {};&#10;    sort(intervals.begin(), intervals.end());&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    res.push_back(intervals[0]);&#10;    for(int i = 1; i &lt; intervals.size(); i++) {&#10;        if(intervals[i][0] &lt;= res.back()[1]) {&#10;            res.back()[1] = max(res.back()[1], intervals[i][1]);&#10;        } else {&#10;            res.push_back(intervals[i]);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Array 48 Next Permutation<br><br></b> <a href='https://leetcode.com/problems/next-permutation/' target='_blank'>LeetCode 31</a></td>
      <td><b>Example 1:</b> From right to left.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 1. Find largest index `k` such that `nums[k] < nums[k + 1]`. If no such index exists, the permutation is the last permutation, reverse it. 2. Find the largest index `l` greater than `k` such that `nums[k] < nums[l]`. 3. Swap `nums[k]` and `nums[l]`. 4. Reverse the sub-array `nums[k + 1:]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void nextPermutation(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), k, l;&#10;    for(k = n - 2; k &gt;= 0; k--) {&#10;        if(nums[k] &lt; nums[k + 1]) break;&#10;    }&#10;    if(k &lt; 0) {&#10;        reverse(nums.begin(), nums.end());&#10;    } else {&#10;        for(l = n - 1; l &gt; k; l--) {&#10;            if(nums[l] &gt; nums[k]) break;&#10;        }&#10;        swap(nums[k], nums[l]);&#10;        reverse(nums.begin() + k + 1, nums.end());&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Array 49 Count Inversions<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Merge Sort.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Modify Merge Sort. While merging two sorted halves, if `left[i] > right[j]`, then there are `mid - i + 1` inversions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], long long temp[], int left, int mid, int right) {&#10;    long long inv_count = 0;&#10;    int i = left, j = mid, k = left;&#10;    while(i &lt;= mid - 1 &amp;&amp; j &lt;= right) {&#10;        if(arr[i] &lt;= arr[j]) temp[k++] = arr[i++];&#10;        else {&#10;            temp[k++] = arr[j++];&#10;            inv_count = inv_count + (mid - i);&#10;        }&#10;    }&#10;    while(i &lt;= mid - 1) temp[k++] = arr[i++];&#10;    while(j &lt;= right) temp[k++] = arr[j++];&#10;    for(i = left; i &lt;= right; i++) arr[i] = temp[i];&#10;    return inv_count;&#10;}&#10;long long mergeSort(long long arr[], long long temp[], int left, int right) {&#10;    long long inv_count = 0;&#10;    if(right &gt; left) {&#10;        int mid = (right + left) / 2;&#10;        inv_count += mergeSort(arr, temp, left, mid);&#10;        inv_count += mergeSort(arr, temp, mid + 1, right);&#10;        inv_count += merge(arr, temp, left, mid + 1, right);&#10;    }&#10;    return inv_count;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    long long temp[N];&#10;    return mergeSort(arr, temp, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>49</td>
      <td>Array 50 Best Time To Buy And Sell Stock<br><br></b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock/' target='_blank'>LeetCode 121</a></td>
      <td><b>Example 1:</b> Keep track of minimum.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain `min_price` seen so far and calculate potential profit for each day: `prices[i] - min_price`. Update `max_profit` if this profit is greater.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int minPrice = INT_MAX, maxProf = 0;&#10;    for(int p : prices) {&#10;        minPrice = min(minPrice, p);&#10;        maxProf = max(maxProf, p - minPrice);&#10;    }&#10;    return maxProf;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>50</td>
      <td>Array 51 Count Pairs With Given Sum<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map to store the frequencies of the elements seen so far. For each element `x`, check if `K - x` is in the hash map. If it is, add its frequency to the `count`. Finally, increment the frequency of `x` in the hash map.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getPairsCount(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int count = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(m.find(k - arr[i]) != m.end()) {&#10;            count += m[k - arr[i]];&#10;        }&#10;        m[arr[i]]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>51</td>
      <td>Array 52 Common Elements In Three Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/common-elements1132/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Three pointers.</td>
      <td><b>Time:</b> O(N1 + N2 + N3)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use three pointers `i`, `j`, `k` for the three arrays. If `A[i] == B[j] == C[k]`, it's a common element, add it to the result (handling duplicates), and increment all three pointers. Else, increment the pointer that points to the smallest value.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {&#10;    vector&lt;int&gt; res;&#10;    int i = 0, j = 0, k = 0;&#10;    while(i &lt; n1 &amp;&amp; j &lt; n2 &amp;&amp; k &lt; n3) {&#10;        if(A[i] == B[j] &amp;&amp; B[j] == C[k]) {&#10;            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);&#10;            i++; j++; k++;&#10;        } else if(A[i] &lt;= B[j] &amp;&amp; A[i] &lt;= C[k]) i++;&#10;        else if(B[j] &lt;= A[i] &amp;&amp; B[j] &lt;= C[k]) j++;&#10;        else k++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>52</td>
      <td>Arr 36 Rearrange Array Alternately<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/rearrange-array-alternately-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Math-based encoding O(1) space.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> To achieve O(1) space, encode two values into one using `arr[i] += (arr[max_idx] % max_elem) * max_elem`. Iterate with two pointers `max_idx` and `min_idx`. At the end, divide every element by `max_elem`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rearrange(long long *arr, int n) {&#10;    int min_idx = 0, max_idx = n - 1;&#10;    long long max_elem = arr[n - 1] + 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) {&#10;            arr[i] += (arr[max_idx] % max_elem) * max_elem;&#10;            max_idx--;&#10;        } else {&#10;            arr[i] += (arr[min_idx] % max_elem) * max_elem;&#10;            min_idx++;&#10;        }&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        arr[i] = arr[i] / max_elem;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>53</td>
      <td>Arr 37 Count Inversions<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Modified Merge Sort.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Merge Sort. During the merge step, if `arr[i] > arr[j]`, then there are `(mid - i + 1)` inversions because the left array is sorted, so all elements after `i` in the left array will also be greater than `arr[j]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], long long temp[], int left, int mid, int right) {&#10;    int i = left, j = mid, k = left;&#10;    long long inv_count = 0;&#10;    while((i &lt;= mid - 1) &amp;&amp; (j &lt;= right)) {&#10;        if(arr[i] &lt;= arr[j]) {&#10;            temp[k++] = arr[i++];&#10;        } else {&#10;            temp[k++] = arr[j++];&#10;            inv_count += (mid - i);&#10;        }&#10;    }&#10;    while(i &lt;= mid - 1) temp[k++] = arr[i++];&#10;    while(j &lt;= right) temp[k++] = arr[j++];&#10;    for(i = left; i &lt;= right; i++) arr[i] = temp[i];&#10;    return inv_count;&#10;}&#10;long long mergeSort(long long arr[], long long temp[], int left, int right) {&#10;    long long mid, inv_count = 0;&#10;    if(right &gt; left) {&#10;        mid = (right + left) / 2;&#10;        inv_count += mergeSort(arr, temp, left, mid);&#10;        inv_count += mergeSort(arr, temp, mid + 1, right);&#10;        inv_count += merge(arr, temp, left, mid + 1, right);&#10;    }&#10;    return inv_count;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    long long temp[N];&#10;    return mergeSort(arr, temp, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>54</td>
      <td>Arr 38 Find All Pairs On Integer Array Whose Sum Is Equal To Given Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Frequency Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Map</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map to store frequencies. For each element `num`, check if `K - num` exists in the map. If so, add its frequency to the count. Then increment the frequency of `num` in the map.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getPairsCount(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int count = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(m.find(k - arr[i]) != m.end()) {&#10;            count += m[k - arr[i]];&#10;        }&#10;        m[arr[i]]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>55</td>
      <td>Arr 39 Find Common Elements In Three Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/common-elements1132/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> 3 Pointers.</td>
      <td><b>Time:</b> O(N1 + N2 + N3)<br><b>Space:</b> O(1) extra space</td>
      <td>-</td>
      <td>Duplicates in arrays</td>
      <td><b>Explanation:</b> Maintain three pointers `i`, `j`, `k` for the three arrays. If `A[i] == B[j] == C[k]`, add to result and increment all three. Otherwise, increment the pointer of the smallest element. Skip duplicates.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector &lt;int&gt; commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {&#10;    int i = 0, j = 0, k = 0;&#10;    vector&lt;int&gt; res;&#10;    while(i &lt; n1 &amp;&amp; j &lt; n2 &amp;&amp; k &lt; n3) {&#10;        if(A[i] == B[j] &amp;&amp; B[j] == C[k]) {&#10;            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);&#10;            i++; j++; k++;&#10;        } else if(A[i] &lt; B[j]) i++;&#10;        else if(B[j] &lt; C[k]) j++;&#10;        else k++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>56</td>
      <td>Arr 40 Rearrange Array In Alternating Positive And Negative Items<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and--ve-nos1401/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Extra Space Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>Unequal count of positive and negative</td>
      <td><b>Explanation:</b> Collect all positive numbers in one array and all negative numbers in another. Overwrite the original array by picking elements alternatively from the two arrays.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rearrange(int arr[], int n) {&#10;    vector&lt;int&gt; pos, neg;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(arr[i] &gt;= 0) pos.push_back(arr[i]);&#10;        else neg.push_back(arr[i]);&#10;    }&#10;    int i = 0, j = 0, k = 0;&#10;    while(i &lt; pos.size() &amp;&amp; j &lt; neg.size()) {&#10;        arr[k++] = pos[i++];&#10;        arr[k++] = neg[j++];&#10;    }&#10;    while(i &lt; pos.size()) arr[k++] = pos[i++];&#10;    while(j &lt; neg.size()) arr[k++] = neg[j++];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>57</td>
      <td>Arr 41 Subarray With 0 Sum<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prefix Sum with HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the array and calculate the prefix sum. If the prefix sum is 0 or it already exists in a hash set, it means a subarray with sum 0 exists.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool subArrayExists(int arr[], int n) {&#10;    unordered_set&lt;int&gt; sumSet;&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += arr[i];&#10;        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;&#10;        sumSet.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>58</td>
      <td>Arr 42 Factorial Of A Large Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Array based multiplication.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N log(N!))</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use an array to store the result. Initially, it holds 1. Multiply the array by numbers from 2 to N. The multiplication is done school-style by carrying over remainders to the next index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; factorial(int N) {&#10;    vector&lt;int&gt; res;&#10;    res.push_back(1);&#10;    for(int x = 2; x &lt;= N; x++) {&#10;        int carry = 0;&#10;        for(int i = 0; i &lt; res.size(); i++) {&#10;            int prod = res[i] * x + carry;&#10;            res[i] = prod % 10;&#10;            carry = prod / 10;&#10;        }&#10;        while(carry) {&#10;            res.push_back(carry % 10);&#10;            carry /= 10;&#10;        }&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>59</td>
      <td>Arr 43 Maximum Product Subarray<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prefix and Suffix iteration.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Zero elements</td>
      <td><b>Explanation:</b> Iterate from left to right calculating prefix product, and right to left calculating suffix product. If either is 0, reset it to 1. The max product will be the max of all prefix and suffix products.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxProduct(vector&lt;int&gt; arr, int n) {&#10;    long long max_prod = INT_MIN;&#10;    long long pref = 1, suff = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= arr[i];&#10;        suff *= arr[n - i - 1];&#10;        max_prod = max({max_prod, pref, suff});&#10;    }&#10;    return max_prod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>60</td>
      <td>Arr 44 Longest Consecutive Subsequence<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Hash Set.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Insert all elements into a hash set. For each element, check if `element - 1` exists. If not, it's the start of a sequence. Then increment to find consecutive elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findLongestConseqSubseq(int arr[], int N) {&#10;    unordered_set&lt;int&gt; s;&#10;    for(int i = 0; i &lt; N; i++) s.insert(arr[i]);&#10;    int longest = 0;&#10;    for(int num : s) {&#10;        if(s.find(num - 1) == s.end()) {&#10;            int curr = num;&#10;            int count = 1;&#10;            while(s.find(curr + 1) != s.end()) {&#10;                curr++;&#10;                count++;&#10;            }&#10;            longest = max(longest, count);&#10;        }&#10;    }&#10;    return longest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>61</td>
      <td>Arr 45 Minimum Swaps And K Together<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> First count all elements <= k (let's say `cnt`). This will be the window size. Find elements > k in the first window. Then slide the window, updating the number of elements > k. The minimum among all windows is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minSwap(int arr[], int n, int k) {&#10;    int cnt = 0;&#10;    for(int i = 0; i &lt; n; i++) if(arr[i] &lt;= k) cnt++;&#10;    int bad = 0;&#10;    for(int i = 0; i &lt; cnt; i++) if(arr[i] &gt; k) bad++;&#10;    int ans = bad;&#10;    for(int i = 0, j = cnt; j &lt; n; i++, j++) {&#10;        if(arr[i] &gt; k) bad--;&#10;        if(arr[j] &gt; k) bad++;&#10;        ans = min(ans, bad);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>62</td>
      <td>Greedy 05 Fractional Knapsack<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort by value/weight ratio.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort items in descending order of value/weight ratio. Greedily pick items with the highest ratio first. If an item cannot fit completely, take the fraction that fits.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Item { int value; int weight; };&#10;bool static comp(Item a, Item b) {&#10;    double r1 = (double)a.value / (double)a.weight;&#10;    double r2 = (double)b.value / (double)b.weight;&#10;    return r1 &gt; r2;&#10;}&#10;double fractionalKnapsack(int W, Item arr[], int n) {&#10;    sort(arr, arr + n, comp);&#10;    double currWeight = 0, finalValue = 0.0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(currWeight + arr[i].weight &lt;= W) {&#10;            currWeight += arr[i].weight;&#10;            finalValue += arr[i].value;&#10;        } else {&#10;            double remain = W - currWeight;&#10;            finalValue += (arr[i].value / (double)arr[i].weight) * remain;&#10;            break;&#10;        }&#10;    }&#10;    return finalValue;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>63</td>
      <td>Greedy 06 Choose And Swap<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Track first occurrences.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Store the first occurrence index of all characters. Iterate the string, for each character check if there is a lexicographically smaller character that appears later in the string. If so, swap them and break.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string chooseandswap(string a) {&#10;    set&lt;char&gt; s;&#10;    for(char c : a) s.insert(c);&#10;    for(int i = 0; i &lt; a.length(); i++) {&#10;        s.erase(a[i]);&#10;        if(s.empty()) break;&#10;        char ch = *s.begin();&#10;        if(ch &lt; a[i]) {&#10;            char ch1 = a[i], ch2 = ch;&#10;            for(int j = 0; j &lt; a.length(); j++) {&#10;                if(a[j] == ch1) a[j] = ch2;&#10;                else if(a[j] == ch2) a[j] = ch1;&#10;            }&#10;            break;&#10;        }&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>64</td>
      <td>Greedy 07 Maximum Trains For Which Stoppage Can Be Provided<br><br></b> <a href='https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Activity Selection on each platform.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Group trains by platform. For each platform, this reduces to the Activity Selection Problem. Sort the trains by departure time and greedily pick non-overlapping trains.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Train { int arr, dep, plat; };&#10;bool comp(Train a, Train b) { return a.dep &lt; b.dep; }&#10;int maxStop(vector&lt;Train&gt;&amp; trains, int n, int m) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; platforms(m + 1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        platforms[trains[i].plat].push_back({trains[i].dep, trains[i].arr});&#10;    }&#10;    int count = 0;&#10;    for(int i = 1; i &lt;= m; i++) {&#10;        if(platforms[i].size() == 0) continue;&#10;        sort(platforms[i].begin(), platforms[i].end());&#10;        count++;&#10;        int lastDep = platforms[i][0].first;&#10;        for(int j = 1; j &lt; platforms[i].size(); j++) {&#10;            if(platforms[i][j].second &gt;= lastDep) {&#10;                count++;&#10;                lastDep = platforms[i][j].first;&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>65</td>
      <td>Greedy 08 Minimum Platforms<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort arrival and departure times separately.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort arrival and departure arrays separately. Use two pointers, one for arrival and one for departure. If arrival < departure, a platform is needed, so increment count. If arrival >= departure, a platform is freed, so decrement count. Track the maximum count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPlatform(int arr[], int dep[], int n) {&#10;    sort(arr, arr + n);&#10;    sort(dep, dep + n);&#10;    int plat_needed = 1, result = 1;&#10;    int i = 1, j = 0;&#10;    while(i &lt; n &amp;&amp; j &lt; n) {&#10;        if(arr[i] &lt;= dep[j]) {&#10;            plat_needed++;&#10;            i++;&#10;        } else if(arr[i] &gt; dep[j]) {&#10;            plat_needed--;&#10;            j++;&#10;        }&#10;        if(plat_needed &gt; result) result = plat_needed;&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>66</td>
      <td>Greedy 09 Buy Maximum Stocks If I Stocks Can Be Bought On I Th Day<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort by price.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Store pairs of (price, day). Sort by price. Greedily buy as many stocks as possible on the day with the lowest price, bounded by the maximum allowed on that day (which is 'day') and the remaining money.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int buyMaximumProducts(int n, int k, int price[]) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; v;&#10;    for(int i = 0; i &lt; n; i++) v.push_back({price[i], i + 1});&#10;    sort(v.begin(), v.end());&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int amount = min(v[i].second, k / v[i].first);&#10;        ans += amount;&#10;        k -= amount * v[i].first;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>67</td>
      <td>Greedy 10 Shop In Candy Store<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort and pick from ends.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the candies by price. For minimum cost, buy the cheapest and take K most expensive for free. For maximum cost, buy the most expensive and take K cheapest for free.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; candyStore(int candies[], int N, int K) {&#10;    sort(candies, candies + N);&#10;    int minCost = 0, maxCost = 0;&#10;    int i = 0, j = N - 1;&#10;    while(i &lt;= j) {&#10;        minCost += candies[i];&#10;        i++; j -= K;&#10;    }&#10;    i = N - 1; j = 0;&#10;    while(j &lt;= i) {&#10;        maxCost += candies[i];&#10;        i--; j += K;&#10;    }&#10;    return {minCost, maxCost};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>68</td>
      <td>Greedy 11 Minimize Cash Flow Among A Given Set Of Friends Who Have Borrowed Money From Each Other<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimize-cash-flow/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Net amounts.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Calculate the net amount for each person by subtracting incoming debts from outgoing debts. Find the person with maximum net credit and maximum net debit. Settle their amounts, and repeat recursively or iteratively until all net amounts are zero.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getMin(int arr[], int n) {&#10;    int minInd = 0;&#10;    for(int i = 1; i &lt; n; i++) if(arr[i] &lt; arr[minInd]) minInd = i;&#10;    return minInd;&#10;}&#10;int getMax(int arr[], int n) {&#10;    int maxInd = 0;&#10;    for(int i = 1; i &lt; n; i++) if(arr[i] &gt; arr[maxInd]) maxInd = i;&#10;    return maxInd;&#10;}&#10;void minCashFlowRec(int amount[], int n, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    int mxCredit = getMax(amount, n), mxDebit = getMin(amount, n);&#10;    if(amount[mxCredit] == 0 &amp;&amp; amount[mxDebit] == 0) return;&#10;    int minVal = min(-amount[mxDebit], amount[mxCredit]);&#10;    amount[mxCredit] -= minVal;&#10;    amount[mxDebit] += minVal;&#10;    ans[mxDebit][mxCredit] = minVal;&#10;    minCashFlowRec(amount, n, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; minCashFlow(vector&lt;vector&lt;int&gt;&gt;&amp; graph, int n) {&#10;    int amount[n] = {0};&#10;    for(int p = 0; p &lt; n; p++) {&#10;        for(int i = 0; i &lt; n; i++) {&#10;            amount[p] += (graph[i][p] - graph[p][i]);&#10;        }&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans(n, vector&lt;int&gt;(n, 0));&#10;    minCashFlowRec(amount, n, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>69</td>
      <td>Greedy 12 Minimum Cost To Cut A Board Into Squares<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort costs.</td>
      <td><b>Time:</b> O(M log M + N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort all vertical and horizontal cuts in descending order. Maintain counts of horizontal and vertical pieces. Greedily pick the cut with the highest cost. If a horizontal cut is made, its total cost is `cut_cost * vertical_pieces`. Update the counts.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumCostOfBreaking(vector&lt;int&gt; X, vector&lt;int&gt; Y, int M, int N) {&#10;    sort(X.begin(), X.end(), greater&lt;int&gt;());&#10;    sort(Y.begin(), Y.end(), greater&lt;int&gt;());&#10;    int hzntl = 1, vert = 1;&#10;    int i = 0, j = 0, res = 0;&#10;    while(i &lt; M - 1 &amp;&amp; j &lt; N - 1) {&#10;        if(X[i] &gt; Y[j]) {&#10;            res += X[i] * vert;&#10;            hzntl++; i++;&#10;        } else {&#10;            res += Y[j] * hzntl;&#10;            vert++; j++;&#10;        }&#10;    }&#10;    int total = 0;&#10;    while(i &lt; M - 1) total += X[i++];&#10;    res += total * vert;&#10;    total = 0;&#10;    while(j &lt; N - 1) total += Y[j++];&#10;    res += total * hzntl;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>70</td>
      <td>Greedy 13 Survival On Island<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Math.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If total required food > max food you can buy in S days excluding Sundays, return -1. Else, total required food is `S * M`. Minimum days = `ceil((S * M) / N)`. Also handle the edge case where `N < M` or if survival > 6 days and `(N * 6) < (M * 7)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumDays(int S, int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    if(S &gt; 6 &amp;&amp; (N * 6) &lt; (M * 7)) return -1;&#10;    int total = S * M;&#10;    return ceil((double)total / N);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>71</td>
      <td>Greedy 14 Maximum Meetings In One Room<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Activity Selection.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Store `(start, end, index)`. Sort by end time. Pick the first meeting. For subsequent meetings, if `start > last_picked_end`, pick it and update `last_picked_end`. Return sorted indices.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Meeting { int s, e, pos; };&#10;bool comp(Meeting a, Meeting b) {&#10;    if(a.e == b.e) return a.pos &lt; b.pos;&#10;    return a.e &lt; b.e;&#10;}&#10;vector&lt;int&gt; maxMeetings(int N, vector&lt;int&gt;&amp; S, vector&lt;int&gt;&amp; F) {&#10;    vector&lt;Meeting&gt; m(N);&#10;    for(int i = 0; i &lt; N; i++) { m[i].s = S[i]; m[i].e = F[i]; m[i].pos = i + 1; }&#10;    sort(m.begin(), m.end(), comp);&#10;    vector&lt;int&gt; ans;&#10;    ans.push_back(m[0].pos);&#10;    int last_e = m[0].e;&#10;    for(int i = 1; i &lt; N; i++) {&#10;        if(m[i].s &gt; last_e) {&#10;            ans.push_back(m[i].pos);&#10;            last_e = m[i].e;&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>72</td>
      <td>Arr 46 Trapping Rain Water<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers, left and right. Maintain left_max and right_max. If `arr[left] <= arr[right]`, the water trapped depends on left_max. If `arr[left] > left_max`, update left_max, else add `left_max - arr[left]` to answer and increment left. Repeat for right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long trappingWater(int arr[], int n) {&#10;    int left = 0, right = n - 1;&#10;    int left_max = 0, right_max = 0;&#10;    long long res = 0;&#10;    while(left &lt;= right) {&#10;        if(arr[left] &lt;= arr[right]) {&#10;            if(arr[left] &gt;= left_max) left_max = arr[left];&#10;            else res += left_max - arr[left];&#10;            left++;&#10;        } else {&#10;            if(arr[right] &gt;= right_max) right_max = arr[right];&#10;            else res += right_max - arr[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>73</td>
      <td>Arr 47 Chocolate Distribution Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort and Slide.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Find the minimum difference between `A[i+M-1]` and `A[i]` for all possible `i` from `0` to `N-M`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long findMinDiff(vector&lt;long long&gt; a, long long n, long long m){&#10;    sort(a.begin(), a.end());&#10;    long long min_diff = LLONG_MAX;&#10;    for(int i = 0; i + m - 1 &lt; n; i++) {&#10;        if(a[i + m - 1] - a[i] &lt; min_diff) {&#10;            min_diff = a[i + m - 1] - a[i];&#10;        }&#10;    }&#10;    return min_diff;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>74</td>
      <td>Arr 48 Smallest Subarray With Sum Greater Than X<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a sliding window. Add elements to `curr_sum` and increment `end`. When `curr_sum > x`, update `min_len` and subtract `arr[start]`, increment `start`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int smallestSubWithSum(int arr[], int n, int x) {&#10;    int curr_sum = 0, min_len = n + 1;&#10;    int start = 0, end = 0;&#10;    while(end &lt; n) {&#10;        while(curr_sum &lt;= x &amp;&amp; end &lt; n) curr_sum += arr[end++];&#10;        while(curr_sum &gt; x &amp;&amp; start &lt; n) {&#10;            min_len = min(min_len, end - start);&#10;            curr_sum -= arr[start++];&#10;        }&#10;    }&#10;    return (min_len == n + 1) ? 0 : min_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>75</td>
      <td>Arr 49 Three Way Partitioning<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/three-way-partitioning/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Dutch National Flag algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use three pointers: `low`, `mid`, `high`. If `arr[mid] < a`, swap `arr[low]` and `arr[mid]`, increment both. If `arr[mid] > b`, swap `arr[mid]` and `arr[high]`, decrement `high`. Else increment `mid`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void threeWayPartition(vector&lt;int&gt;&amp; array, int a, int b) {&#10;    int low = 0, mid = 0, high = array.size() - 1;&#10;    while(mid &lt;= high) {&#10;        if(array[mid] &lt; a) {&#10;            swap(array[low], array[mid]);&#10;            low++; mid++;&#10;        } else if(array[mid] &gt; b) {&#10;            swap(array[mid], array[high]);&#10;            high--;&#10;        } else {&#10;            mid++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>76</td>
      <td>Arr 50 Minimum Swaps And K Together<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> First count all elements <= k (let's say `cnt`). This will be the window size. Find elements > k in the first window. Then slide the window, updating the number of elements > k. The minimum among all windows is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minSwap(int arr[], int n, int k) {&#10;    int cnt = 0;&#10;    for(int i = 0; i &lt; n; i++) if(arr[i] &lt;= k) cnt++;&#10;    int bad = 0;&#10;    for(int i = 0; i &lt; cnt; i++) if(arr[i] &gt; k) bad++;&#10;    int ans = bad;&#10;    for(int i = 0, j = cnt; j &lt; n; i++, j++) {&#10;        if(arr[i] &gt; k) bad--;&#10;        if(arr[j] &gt; k) bad++;&#10;        ans = min(ans, bad);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>77</td>
      <td>Arr 51 Palindromic Array<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Check individual numbers.</td>
      <td><b>Time:</b> O(N * d)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through each number in the array. For each number, reverse its digits to check if it's a palindrome. If any number is not, return 0. If all are, return 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int N) {&#10;    int rev = 0, temp = N;&#10;    while(temp &gt; 0) {&#10;        rev = rev * 10 + temp % 10;&#10;        temp /= 10;&#10;    }&#10;    return rev == N;&#10;}&#10;int PalinArray(int a[], int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(!isPalindrome(a[i])) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>78</td>
      <td>Arr 52 Find The Median<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-the-median0527/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort array.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. If the size is odd, the median is the middle element. If the size is even, the median is the average of the two middle elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int find_median(vector&lt;int&gt; v) {&#10;    sort(v.begin(), v.end());&#10;    int n = v.size();&#10;    if(n % 2 != 0) return v[n / 2];&#10;    else return (v[n / 2 - 1] + v[n / 2]) / 2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>79</td>
      <td>Arr 53 Median Of Two Sorted Arrays Of Different Sizes<br><br></b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Binary Search on the smaller array. Partition both arrays such that the number of elements on the left side is equal to or one more than the right side. Check if `maxLeftX <= minRightY` and `maxLeftY <= minRightX`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int x = nums1.size(), y = nums2.size();&#10;    int low = 0, high = x;&#10;    while(low &lt;= high) {&#10;        int partitionX = (low + high) / 2;&#10;        int partitionY = (x + y + 1) / 2 - partitionX;&#10;        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];&#10;        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];&#10;        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];&#10;        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];&#10;        if(maxLeftX &lt;= minRightY &amp;&amp; maxLeftY &lt;= minRightX) {&#10;            if((x + y) % 2 == 0) return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;&#10;            else return max(maxLeftX, maxLeftY);&#10;        } else if(maxLeftX &gt; minRightY) high = partitionX - 1;&#10;        else low = partitionX + 1;&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>80</td>
      <td>Arr 54 Count More Than N K Occurences<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-element-occurences/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> HashMap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Map</td>
      <td>-</td>
      <td><b>Explanation:</b> Store the frequencies of all elements in a hash map. Iterate through the hash map and count the number of elements having frequency greater than `N/k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countOccurence(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    for(int i = 0; i &lt; n; i++) count[arr[i]]++;&#10;    int res = 0;&#10;    int target = n / k;&#10;    for(auto it : count) {&#10;        if(it.second &gt; target) res++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>81</td>
      <td>Arr 55 Find Maximum Product Subarray<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prefix and suffix loop.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Zero in array</td>
      <td><b>Explanation:</b> Iterate from left to right calculating prefix product, and from right to left calculating suffix product. If either is 0, reset it to 1. Track the max across all steps.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxProduct(vector&lt;int&gt; arr, int n) {&#10;    long long max_prod = INT_MIN;&#10;    long long pref = 1, suff = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= arr[i];&#10;        suff *= arr[n - i - 1];&#10;        max_prod = max({max_prod, pref, suff});&#10;    }&#10;    return max_prod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>82</td>
      <td>Arr 56 Find The Missing Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sum formula.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Calculate the sum of first N natural numbers using `N*(N+1)/2`. Subtract the sum of all elements in the array from it. The result is the missing number.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(vector&lt;int&gt;&amp; array, int n) {&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; n - 1; i++) sum += array[i];&#10;    long long expectedSum = (long long)n * (n + 1) / 2;&#10;    return expectedSum - sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>83</td>
      <td>Arr 59 Longest Subarray With Sum K Positives And Negatives<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Map</td>
      <td>Zeroes and negatives</td>
      <td><b>Explanation:</b> Use a hash map to store the first occurrence of each prefix sum. While iterating, if `current_sum == K`, max length is `i+1`. If `current_sum - K` exists in the hash map, update max length with `i - map[current_sum - K]`. If `current_sum` is not in map, insert it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(int A[],  int N, int K) {&#10;    unordered_map&lt;long long, int&gt; preSumMap;&#10;    long long sum = 0;&#10;    int maxLen = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        sum += A[i];&#10;        if(sum == K) maxLen = max(maxLen, i + 1);&#10;        long long rem = sum - K;&#10;        if(preSumMap.find(rem) != preSumMap.end()) {&#10;            maxLen = max(maxLen, i - preSumMap[rem]);&#10;        }&#10;        if(preSumMap.find(sum) == preSumMap.end()) {&#10;            preSumMap[sum] = i;&#10;        }&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>84</td>
      <td>Arr 60 Majority Element Ii<br><br></b> <a href='https://leetcode.com/problems/majority-element-ii/' target='_blank'>LeetCode 229</a></td>
      <td><b>Example 1:</b> Extended Boyer Moore's Voting Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Since at most two elements can appear more than n/3 times, maintain two potential candidates (`num1`, `num2`) and their counts. Iterate through the array updating candidates and counts. After finding the candidates, iterate again to count their actual occurrences and check if they exceed n/3.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; majorityElement(vector&lt;int&gt;&amp; nums) {&#10;    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;&#10;    for(int x : nums) {&#10;        if(x == num1) c1++;&#10;        else if(x == num2) c2++;&#10;        else if(c1 == 0) { num1 = x; c1 = 1; }&#10;        else if(c2 == 0) { num2 = x; c2 = 1; }&#10;        else { c1--; c2--; }&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    c1 = 0; c2 = 0;&#10;    for(int x : nums) {&#10;        if(x == num1) c1++;&#10;        else if(x == num2) c2++;&#10;    }&#10;    if(c1 &gt; nums.size() / 3) ans.push_back(num1);&#10;    if(c2 &gt; nums.size() / 3) ans.push_back(num2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>85</td>
      <td>Arr 61 3Sum<br><br></b> <a href='https://leetcode.com/problems/3sum/' target='_blank'>LeetCode 15</a></td>
      <td><b>Example 1:</b> Sort + Two Pointers.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1) excluding output</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Fix the first element `nums[i]`. Use two pointers (`left = i+1`, `right = n-1`) to find the remaining two elements that sum to `-nums[i]`. Skip duplicates for `i`, `left`, and `right` to ensure unique triplets.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; threeSum(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    sort(nums.begin(), nums.end());&#10;    int n = nums.size();&#10;    for(int i = 0; i &lt; n - 2; i++) {&#10;        if(i == 0 || (i &gt; 0 &amp;&amp; nums[i] != nums[i-1])) {&#10;            int low = i + 1, high = n - 1, sum = 0 - nums[i];&#10;            while(low &lt; high) {&#10;                if(nums[low] + nums[high] == sum) {&#10;                    ans.push_back({nums[i], nums[low], nums[high]});&#10;                    while(low &lt; high &amp;&amp; nums[low] == nums[low+1]) low++;&#10;                    while(low &lt; high &amp;&amp; nums[high] == nums[high-1]) high--;&#10;                    low++; high--;&#10;                } else if(nums[low] + nums[high] &lt; sum) low++;&#10;                else high--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>86</td>
      <td>Arr 64 Merge Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td><b>Example 1:</b> Sort and Merge.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the intervals by their start times. Iterate through them. If the result list is empty or the current interval's start is > the last interval's end, append it. Otherwise, update the last interval's end to the maximum of its end and current end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; merge(vector&lt;vector&lt;int&gt;&gt;&amp; intervals) {&#10;    sort(intervals.begin(), intervals.end());&#10;    vector&lt;vector&lt;int&gt;&gt; merged;&#10;    for(auto interval : intervals) {&#10;        if(merged.empty() || merged.back()[1] &lt; interval[0]) {&#10;            merged.push_back(interval);&#10;        } else {&#10;            merged.back()[1] = max(merged.back()[1], interval[1]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>87</td>
      <td>Arr 65 Merge Sorted Array Without Extra Space<br><br></b> <a href='https://leetcode.com/problems/merge-sorted-array/' target='_blank'>LeetCode 88</a></td>
      <td><b>Example 1:</b> Two pointers from end.</td>
      <td><b>Time:</b> O(M + N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Since `nums1` has enough space at the end, use three pointers: `p1` at the end of valid elements in `nums1` (m-1), `p2` at the end of `nums2` (n-1), and `p` at the very end of `nums1` (m+n-1). Compare elements at `p1` and `p2`, put the larger one at `p`, and decrement pointers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; nums1, int m, vector&lt;int&gt;&amp; nums2, int n) {&#10;    int p1 = m - 1, p2 = n - 1, p = m + n - 1;&#10;    while(p1 &gt;= 0 &amp;&amp; p2 &gt;= 0) {&#10;        if(nums1[p1] &gt; nums2[p2]) nums1[p--] = nums1[p1--];&#10;        else nums1[p--] = nums2[p2--];&#10;    }&#10;    while(p2 &gt;= 0) nums1[p--] = nums2[p2--];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
