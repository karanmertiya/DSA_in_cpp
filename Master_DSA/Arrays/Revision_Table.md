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
      <td rowspan="2">1</td>
      <td rowspan="2">Arr 01 Largest Element<br><br></b> <a href='https://www.geeksforgeeks.org/problems/largest-element-in-array/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: arr = [1, 8, 7, 56, 90], Output: 90<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N log N) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td><code>std::sort</code> / <code>.sort()</code></td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array and return the last element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int largestElementBrute(std::vector&lt;int&gt;&amp; arr) {&#10;    std::sort(arr.begin(), arr.end());&#10;    return arr.back();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Initialization:</b> Set max to `arr[0]` to handle negative arrays natively without relying on `INT_MIN`.</td>
      <td><b>Explanation:</b> Maintain a max variable and linearly scan the array updating it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int largestElementOptimal(std::vector&lt;int&gt;&amp; arr) {&#10;    int max_val = arr[0];&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &gt; max_val) {&#10;            max_val = arr[i];&#10;        }&#10;    }&#10;    return max_val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Arr 02 Check If Sorted<br><br></b> <a href='https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/' target='_blank'>LeetCode 1752</a><br><br><b>Variants:</b><br>- Rotated Sorted: Also check if the array was sorted but rotated.</td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [1, 2, 3, 4, 5], Output: true<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Length:</b> Return `true` automatically if size is 0 or 1.</td>
      <td><b>Explanation:</b> Linearly traverse and ensure `arr[i] <= arr[i+1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;bool isSorted(std::vector&lt;int&gt;&amp; arr) {&#10;    if (arr.size() &lt;= 1) return true;&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &lt; arr[i - 1]) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">3</td>
      <td rowspan="2">Arr 03 Remove Duplicates<br><br></b> <a href='https://leetcode.com/problems/remove-duplicates-from-sorted-array/' target='_blank'>LeetCode 26</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: arr = [1, 1, 2], Output: 2, arr = [1, 2, _]<br><br><b>Note (Constraint):</b> Array is sorted.</td>
      <td><b>Time:</b> O(N log N) (Trade-off)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::set</code> / <code>set()</code></td>
      <td><b>Set Ordering:</b> Uses ordered Set to maintain array sort order when writing back.</td>
      <td><b>Explanation:</b> Use an auxiliary HashSet to store unique elements, then put them back.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;set&gt;&#10;&#10;int removeDuplicatesBrute(std::vector&lt;int&gt;&amp; arr) {&#10;    std::set&lt;int&gt; unique_set(arr.begin(), arr.end());&#10;    int i = 0;&#10;    for (int it : unique_set) {&#10;        arr[i++] = it;&#10;    }&#10;    return unique_set.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>In-place Edit:</b> Mutates exactly up to index `i`, leaving trailing garbage intact as per standard.</td>
      <td><b>Explanation:</b> Two-pointer approach: Place unique elements at the `i` pointer while `j` scans.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int removeDuplicatesOptimal(std::vector&lt;int&gt;&amp; arr) {&#10;    if (arr.empty()) return 0;&#10;    int i = 0;&#10;    for (int j = 1; j &lt; arr.size(); j++) {&#10;        if (arr[i] != arr[j]) {&#10;            i++;&#10;            arr[i] = arr[j];&#10;        }&#10;    }&#10;    return i + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Arr 04 Rotate Array<br><br></b> <a href='https://leetcode.com/problems/rotate-array/' target='_blank'>LeetCode 189</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: nums = [1,2,3,4,5,6,7], k = 3, Output: [5,6,7,1,2,3,4]<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup>, 0 &le; k &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Extra Space</td>
      <td><b>Modulus Magic:</b> `(i + k) % n` wraps the index around safely.</td>
      <td><b>Explanation:</b> Use an extra array to place elements at `(i + k) % N`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void rotateBrute(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    std::vector&lt;int&gt; temp(n);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        temp[(i + k) % n] = nums[i];&#10;    }&#10;    nums = temp;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::reverse</code></td>
      <td><b>`k > N` Handle:</b> `k = k % n` strictly required if `k` exceeds array length.</td>
      <td><b>Explanation:</b> Reverse parts of the array: Reverse full array, reverse first `k`, reverse rest.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void rotateOptimal(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n; // Prevent out of bounds&#10;    std::reverse(nums.begin(), nums.end());&#10;    std::reverse(nums.begin(), nums.begin() + k);&#10;    std::reverse(nums.begin() + k, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Arr 05 Move Zeros<br><br></b> <a href='https://leetcode.com/problems/move-zeroes/' target='_blank'>LeetCode 283</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [0,1,0,3,12], Output: [1,3,12,0,0]<br><br><b>Note (Constraint):</b> Must be done in-place.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::swap</code></td>
      <td><b>Swapping:</b> Natively handles cases where array has no zeros.</td>
      <td><b>Explanation:</b> Two-pointer approach. Swap non-zero elements with the `zero_pointer`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;void moveZeroes(std::vector&lt;int&gt;&amp; nums) {&#10;    int zero_idx = 0;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(nums[i] != 0) {&#10;            std::swap(nums[zero_idx], nums[i]);&#10;            zero_idx++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Arr 06 Two Sum<br><br></b> <a href='https://leetcode.com/problems/two-sum/' target='_blank'>LeetCode 1</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: nums = [2,7,11,15], target = 9, Output: [0,1]<br><br><b>Note (Constraint):</b> 2 &le; N &le; 10<sup>4</sup></td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Nested loops to check all possible pairs.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;std::vector&lt;int&gt; twoSumBrute(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        for(int j=i+1; j&lt;nums.size(); j++) {&#10;            if(nums[i] + nums[j] == target) return {i, j};&#10;        }&#10;    }&#10;    return {};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code> / <code>dict</code></td>
      <td><b>One Pass:</b> Storing elements *after* checking ensures a number isn't used twice for itself.</td>
      <td><b>Explanation:</b> Use a Hash Map to store elements and their indices. Check for `target - current`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;&#10;std::vector&lt;int&gt; twoSumOptimal(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    std::unordered_map&lt;int, int&gt; hash;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        int needed = target - nums[i];&#10;        if(hash.find(needed) != hash.end()) {&#10;            return {hash[needed], i};&#10;        }&#10;        hash[nums[i]] = i;&#10;    }&#10;    return {};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Arr 07 Kadanes Algorithm<br><br></b> <a href='https://leetcode.com/problems/maximum-subarray/' target='_blank'>LeetCode 53</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: [-2,1,-3,4,-1,2,1,-5,4], Output: 6 ([4,-1,2,1])<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Negative Array Check:</b> Initialize `max_sum` with `INT_MIN` for arrays of all negative numbers.</td>
      <td><b>Explanation:</b> Check all possible subarrays and calculate their sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;#include &lt;climits&gt;&#10;&#10;int maxSubArrayBrute(std::vector&lt;int&gt;&amp; nums) {&#10;    int maxi = INT_MIN;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        int sum = 0;&#10;        for(int j=i; j&lt;nums.size(); j++) {&#10;            sum += nums[j];&#10;            maxi = std::max(maxi, sum);&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Reset Logic:</b> If subarray becomes a net negative, extending it will only harm the sum.</td>
      <td><b>Explanation:</b> Kadane's: Maintain `curr_sum`. If `curr_sum` drops below zero, reset it. Track maximum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;#include &lt;climits&gt;&#10;&#10;int maxSubArrayOptimal(std::vector&lt;int&gt;&amp; nums) {&#10;    int maxi = INT_MIN;&#10;    int sum = 0;&#10;    for(int num : nums) {&#10;        sum += num;&#10;        maxi = std::max(maxi, sum);&#10;        if (sum &lt; 0) sum = 0; // Reset condition&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">8</td>
      <td rowspan="2">Arr 08 Sort Colors<br><br></b> <a href='https://leetcode.com/problems/sort-colors/' target='_blank'>LeetCode 75</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: nums = [2,0,2,1,1,0], Output: [0,0,1,1,2,2]<br><br><b>Note (Constraint):</b> 1 &le; N &le; 300</td>
      <td><b>Time:</b> O(2N) &cong; O(N) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Two Passes:</b> Forces a double iteration through the memory block.</td>
      <td><b>Explanation:</b> Count 0s, 1s, and 2s, then overwrite the array linearly.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void sortColorsBetter(std::vector&lt;int&gt;&amp; nums) {&#10;    int c0 = 0, c1 = 0, c2 = 0;&#10;    for(int num : nums) {&#10;        if(num == 0) c0++;&#10;        else if(num == 1) c1++;&#10;        else c2++;&#10;    }&#10;    for(int i = 0; i &lt; c0; i++) nums[i] = 0;&#10;    for(int i = c0; i &lt; c0+c1; i++) nums[i] = 1;&#10;    for(int i = c0+c1; i &lt; nums.size(); i++) nums[i] = 2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::swap</code></td>
      <td><b>Strict Single Pass:</b> Swaps values into correct zones in exactly N steps.</td>
      <td><b>Explanation:</b> Dutch National Flag Algorithm: 3 Pointers (low, mid, high) sorting in a single pass.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;void sortColorsOptimal(std::vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, mid = 0, high = nums.size() - 1;&#10;    while(mid &lt;= high) {&#10;        if(nums[mid] == 0) {&#10;            std::swap(nums[low], nums[mid]);&#10;            low++; mid++;&#10;        } else if(nums[mid] == 1) {&#10;            mid++;&#10;        } else {&#10;            std::swap(nums[mid], nums[high]);&#10;            high--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
