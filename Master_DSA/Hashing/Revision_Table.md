# Hashing Revision Table

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
      <td rowspan="2">Hash 01 Count Frequencies<br><br></b> <a href='https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: arr = [10, 5, 10, 15, 10, 5], Output: 10->3, 5->2, 15->1<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>-</td>
      <td><b>Marking Checked:</b> Requires mutating array or extra boolean array to track checked elements.</td>
      <td><b>Explanation:</b> Use two nested loops to count occurrences. Mark visited elements to avoid recounting.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;iostream&gt;&#10;&#10;void countFreqBrute(std::vector&lt;int&gt;&amp; arr) {&#10;    std::vector&lt;bool&gt; visited(arr.size(), false);&#10;    for(int i=0; i&lt;arr.size(); i++) {&#10;        if(visited[i]) continue;&#10;        int count = 1;&#10;        for(int j=i+1; j&lt;arr.size(); j++) {&#10;            if(arr[i] == arr[j]) {&#10;                visited[j] = true;&#10;                count++;&#10;            }&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code> / <code>dict</code></td>
      <td><b>Unordered vs Ordered:</b> Unordered map gives `O(1)` operations but doesn't retain element sorting.</td>
      <td><b>Explanation:</b> Use a Hash Map to store the frequencies in a single pass.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;&#10;void countFreqOptimal(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : arr) {&#10;        freq[num]++;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Hash 02 Highest Lowest Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-array-by-increasing-frequency/' target='_blank'>LeetCode 1636</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [10, 5, 10, 15, 10, 5], Output: Highest=10, Lowest=15<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code></td>
      <td><b>Initialization:</b> Set min_freq to `INT_MAX` properly to allow map values to overwrite it.</td>
      <td><b>Explanation:</b> Build a frequency map, then iterate through the map to find the max and min frequencies.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;#include &lt;climits&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;void findHighLowFreq(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : arr) freq[num]++;&#10;    &#10;    int max_f = 0, min_f = INT_MAX;&#10;    int max_ele = 0, min_ele = 0;&#10;    &#10;    for(auto it : freq) {&#10;        if(it.second &gt; max_f) { max_f = it.second; max_ele = it.first; }&#10;        if(it.second &lt; min_f) { min_f = it.second; min_ele = it.first; }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Hash 03 Intersection Of Two Arrays<br><br></b> <a href='https://leetcode.com/problems/intersection-of-two-arrays/' target='_blank'>LeetCode 349</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums1 = [1,2,2,1], nums2 = [2,2], Output: [2]<br><br><b>Note (Constraint):</b> 1 &le; N, M &le; 1000</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Duplicate Match Prevention:</b> Erase matched elements from the set immediately to prevent duplicate intersections.</td>
      <td><b>Explanation:</b> Store elements of the first array in a Hash Set, then iterate over the second array to find matches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_set&gt;&#10;&#10;std::vector&lt;int&gt; intersection(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_set&lt;int&gt; s(nums1.begin(), nums1.end());&#10;    std::vector&lt;int&gt; res;&#10;    for(int num : nums2) {&#10;        if(s.find(num) != s.end()) {&#10;            res.push_back(num);&#10;            s.erase(num); // Ensure uniqueness&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Hash 04 Union Of Two Arrays<br><br></b> <a href='https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: a = [1, 2, 3], b = [2, 3, 4], Output: [1, 2, 3, 4]<br><br><b>Note (Constraint):</b> Arrays may not be sorted.</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N + M) (Trade-off)</td>
      <td><code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Unordered Limitation:</b> If the problem expects sorted union, `std::set` must be used increasing time to `O((N+M)log(N+M))`.</td>
      <td><b>Explanation:</b> Insert all elements from both arrays into a Hash Set. The Set natively drops duplicates.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_set&gt;&#10;&#10;std::vector&lt;int&gt; findUnion(std::vector&lt;int&gt;&amp; a, std::vector&lt;int&gt;&amp; b) {&#10;    std::unordered_set&lt;int&gt; s;&#10;    for(int num : a) s.insert(num);&#10;    for(int num : b) s.insert(num);&#10;    &#10;    std::vector&lt;int&gt; res(s.begin(), s.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Hash 05 Subarray With 0 Sum<br><br></b> <a href='https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [4, 2, -3, 1, 6], Output: true (2, -3, 1)<br><br><b>Note (Constraint):</b> Array contains positive and negative integers.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_set</code></td>
      <td><b>Zero Prefix Edge Case:</b> If `sum == 0` during traversal, the subarray naturally started from index 0.</td>
      <td><b>Explanation:</b> Use a Prefix Sum and a Hash Set. If a prefix sum repeats, or equals 0, a 0-sum subarray exists between the identical prefix sums.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_set&gt;&#10;&#10;bool hasZeroSumSubarray(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_set&lt;int&gt; prefix_sums;&#10;    int sum = 0;&#10;    for(int num : arr) {&#10;        sum += num;&#10;        if(sum == 0 || prefix_sums.find(sum) != prefix_sums.end()) {&#10;            return true;&#10;        }&#10;        prefix_sums.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Hash 06 Subarray Sum Equals K<br><br></b> <a href='https://leetcode.com/problems/subarray-sum-equals-k/' target='_blank'>LeetCode 560</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,1,1], k = 2, Output: 2<br><br><b>Note (Constraint):</b> Negative numbers allowed, preventing pure Sliding Window approaches.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code></td>
      <td><b>Base Case Injection:</b> Must initialize map with `(0, 1)` to correctly count subarrays starting natively from index 0.</td>
      <td><b>Explanation:</b> Maintain a Hash Map of `prefix_sum` -> `frequency`. If `curr_sum - k` exists in the map, add its frequency to the count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;&#10;int subarraySum(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; prefix_freq;&#10;    prefix_freq[0] = 1; // Base case for subarrays starting at index 0&#10;    &#10;    int count = 0, sum = 0;&#10;    for(int num : nums) {&#10;        sum += num;&#10;        int remove = sum - k;&#10;        if(prefix_freq.find(remove) != prefix_freq.end()) {&#10;            count += prefix_freq[remove];&#10;        }&#10;        prefix_freq[sum]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Hash 07 Longest Subarray With 0 Sum<br><br></b> <a href='https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [15,-2,2,-8,1,7,10,23], Output: 5<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code></td>
      <td><b>Longest Policy:</b> We only insert `sum` into the map if it doesn't exist to preserve the earliest index and maximize distance.</td>
      <td><b>Explanation:</b> Store `prefix_sum` -> `index` in Hash Map. If sum repeats, calculate distance `i - hash[sum]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int maxLen(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; prefix_index;&#10;    int max_len = 0, sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == 0) {&#10;            max_len = i + 1;&#10;        } else if(prefix_index.find(sum) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[sum]);&#10;        } else {&#10;            prefix_index[sum] = i; // Store only first occurrence&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Hash 08 Longest Subarray With Sum K<br><br></b> <a href='https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: arr = [10, 5, 2, 7, 1, 9], k = 15, Output: 4<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><code>std::unordered_map</code></td>
      <td><b>Zero Elements Rule:</b> Never overwrite existing prefix sums in the map, otherwise arrays with zero elements will shorten the max length.</td>
      <td><b>Explanation:</b> Prefix Sum Map storing indices. Check if `sum - K` exists in map and calculate index difference.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int lenOfLongSubarr(std::vector&lt;int&gt;&amp; arr, int k) {&#10;    std::unordered_map&lt;long long, int&gt; prefix_index;&#10;    int max_len = 0;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == k) {&#10;            max_len = i + 1;&#10;        }&#10;        long long needed = sum - k;&#10;        if(prefix_index.find(needed) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[needed]);&#10;        }&#10;        if(prefix_index.find(sum) == prefix_index.end()) {&#10;            prefix_index[sum] = i;&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
