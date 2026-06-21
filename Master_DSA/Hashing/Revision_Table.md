# Hashing Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 20%;">Example & Constraints</th>
      <th style="width: 10%;">Complexity</th>
      <th style="width: 20%;">Approach & Dependencies</th>
      <th style="width: 30%;">Logic & Edge Cases</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="2">1</td>
      <td rowspan="2">Hash 01 Count Frequencies<br><br></b> <a href="https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> arr = [10, 5, 10, 15, 10, 5]<br><b>Output:</b> 10->3, 5->2, 15->1<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use two nested loops to count frequency of each element, marking visited ones.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void countFreq(vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; visited(n, false);&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(visited[i]) continue;&#10;        int count = 1;&#10;        for(int j=i+1; j&lt;n; j++) {&#10;            if(arr[i] == arr[j]) {&#10;                visited[j] = true;&#10;                count++;&#10;            }&#10;        }&#10;        cout &lt;&lt; arr[i] &lt;&lt; &quot; &quot; &lt;&lt; count &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Use two nested loops to count occurrences. Mark visited elements to avoid recounting.</td>
      <td><b>Edge Cases:</b> <b>Marking Checked:</b> Requires mutating array or extra boolean array to track checked elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">\n\n\n\nvoid countFreq(std::vector&lt;int&gt;&amp; arr) {\n    std::unordered_map&lt;int, int&gt; freq;\n    for(int num : arr) {\n        freq[num]++;\n    }\n    for(auto it : freq) {\n        std::cout &lt;&lt; it.first &lt;&lt; \&quot; \&quot; &lt;&lt; it.second &lt;&lt; \&quot;\\n\&quot;;\n    }\n}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Hash 02 Highest Lowest Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-array-by-increasing-frequency/" target="_blank">LeetCode 1636</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 10, 15, 10, 5]<br><b>Output:</b> Highest=10, Lowest=15<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Build a frequency map, then iterate through the map to find the max and min frequencies.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Set min_freq to `INT_MAX` properly to allow map values to overwrite it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findHighLowFreq(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : arr) freq[num]++;&#10;    &#10;    int max_f = 0, min_f = INT_MAX;&#10;    int max_ele = 0, min_ele = 0;&#10;    &#10;    for(auto it : freq) {&#10;        if(it.second &gt; max_f) { max_f = it.second; max_ele = it.first; }&#10;        if(it.second &lt; min_f) { min_f = it.second; min_ele = it.first; }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">3</td>
      <td rowspan="2">Hash 03 Intersection Of Two Arrays<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-arrays/" target="_blank">LeetCode 349</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums1 = [1,2,2,1], nums2 = [2,2]<br><b>Output:</b> [2]<br><br><b> </b> 1 &le; N, M &le; 1000</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(min(N, M))</td>
      <td><b>Approach 1:</b><br>Brute Force: Iterate through the first array and check each element in the second array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; intersection(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    vector&lt;int&gt; res;&#10;    for(int i=0; i&lt;nums1.size(); i++) {&#10;        bool found = false;&#10;        for(int j=0; j&lt;nums2.size(); j++) {&#10;            if(nums1[i] == nums2[j]) { found = true; break; }&#10;        }&#10;        if(found &amp;&amp; find(res.begin(), res.end(), nums1[i]) == res.end()) {&#10;            res.push_back(nums1[i]);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Store elements of the first array in a Hash Set, then iterate over the second array to find matches.<br><br><b>Dependencies:</b> <code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Match Prevention:</b> Erase matched elements from the set immediately to prevent duplicate intersections.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; intersection(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_set&lt;int&gt; s(nums1.begin(), nums1.end());&#10;    std::vector&lt;int&gt; res;&#10;    for(int num : nums2) {&#10;        if(s.find(num) != s.end()) {&#10;            res.push_back(num);&#10;            s.erase(num); // Ensure uniqueness&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Hash 04 Union Of Two Arrays<br><br></b> <a href="https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> a = [1, 2, 3], b = [2, 3, 4]<br><b>Output:</b> [1, 2, 3, 4]<br><br><b> </b> Arrays may not be sorted.</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N + M) (Trade-off)</td>
      <td>Optimal: Insert all elements from both arrays into a Hash Set. The Set natively drops duplicates.<br><br><b>Dependencies:</b> <code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Edge Cases:</b> <b>Unordered Limitation:</b> If the problem expects sorted union, `std::set` must be used increasing time to `O((N+M)log(N+M))`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; findUnion(std::vector&lt;int&gt;&amp; a, std::vector&lt;int&gt;&amp; b) {&#10;    std::unordered_set&lt;int&gt; s;&#10;    for(int num : a) s.insert(num);&#10;    for(int num : b) s.insert(num);&#10;    &#10;    std::vector&lt;int&gt; res(s.begin(), s.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Hash 05 Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [4, 2, -3, 1, 6]<br><b>Output:</b> true (2, -3, 1)<br><br><b> </b> Array contains positive and negative integers.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Use a Prefix Sum and a Hash Set. If a prefix sum repeats, or equals 0, a 0-sum subarray exists between the identical prefix sums.<br><br><b>Dependencies:</b> <code>std::unordered_set</code></td>
      <td><b>Edge Cases:</b> <b>Zero Prefix Edge Case:</b> If `sum == 0` during traversal, the subarray naturally started from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasZeroSumSubarray(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_set&lt;int&gt; prefix_sums;&#10;    int sum = 0;&#10;    for(int num : arr) {&#10;        sum += num;&#10;        if(sum == 0 || prefix_sums.find(sum) != prefix_sums.end()) {&#10;            return true;&#10;        }&#10;        prefix_sums.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Hash 06 Subarray Sum Equals K<br><br></b> <a href="https://leetcode.com/problems/subarray-sum-equals-k/" target="_blank">LeetCode 560</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,1,1], k = 2<br><b>Output:</b> 2<br><br><b> </b> Negative numbers allowed, preventing pure Sliding Window approaches.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Generate all possible subarrays and compute their sums.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int subarraySum(vector&lt;int&gt;&amp; nums, int k) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        int sum = 0;&#10;        for(int j=i; j&lt;nums.size(); j++) {&#10;            sum += nums[j];&#10;            if(sum == k) count++;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Maintain a Hash Map of `prefix_sum` -> `frequency`. If `curr_sum - k` exists in the map, add its frequency to the count.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Base Case Injection:</b> Must initialize map with `(0, 1)` to correctly count subarrays starting natively from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int subarraySum(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; prefix_freq;&#10;    prefix_freq[0] = 1; // Base case for subarrays starting at index 0&#10;    &#10;    int count = 0, sum = 0;&#10;    for(int num : nums) {&#10;        sum += num;&#10;        int remove = sum - k;&#10;        if(prefix_freq.find(remove) != prefix_freq.end()) {&#10;            count += prefix_freq[remove];&#10;        }&#10;        prefix_freq[sum]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Hash 07 Longest Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [15,-2,2,-8,1,7,10,23]<br><b>Output:</b> 5<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Store `prefix_sum` -> `index` in Hash Map. If sum repeats, calculate distance `i - hash[sum]`.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Longest Policy:</b> We only insert `sum` into the map if it doesn't exist to preserve the earliest index and maximize distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; prefix_index;&#10;    int max_len = 0, sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == 0) {&#10;            max_len = i + 1;&#10;        } else if(prefix_index.find(sum) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[sum]);&#10;        } else {&#10;            prefix_index[sum] = i; // Store only first occurrence&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Hash 08 Longest Subarray With Sum K<br><br></b> <a href="https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 2, 7, 1, 9], k = 15<br><b>Output:</b> 4<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Prefix Sum Map storing indices. Check if `sum - K` exists in map and calculate index difference.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Zero Elements Rule:</b> Never overwrite existing prefix sums in the map, otherwise arrays with zero elements will shorten the max length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(std::vector&lt;int&gt;&amp; arr, int k) {&#10;    std::unordered_map&lt;long long, int&gt; prefix_index;&#10;    int max_len = 0;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == k) {&#10;            max_len = i + 1;&#10;        }&#10;        long long needed = sum - k;&#10;        if(prefix_index.find(needed) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[needed]);&#10;        }&#10;        if(prefix_index.find(sum) == prefix_index.end()) {&#10;            prefix_index[sum] = i;&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Hash 09 Two Sum<br><br></b> <a href="https://leetcode.com/problems/two-sum/" target="_blank">LeetCode 1</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [2,7,11,15], target = 9<br><b>Output:</b> [0,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Iterate while storing numbers and their indices in a hash map. Check if `target - num` already exists.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Elements:</b> Storing elements as we iterate safely handles duplicates (e.g., target 6, array [3,3]).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; twoSum(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        int needed = target - nums[i];&#10;        if(mpp.find(needed) != mpp.end()) {&#10;            return {mpp[needed], i};&#10;        }&#10;        mpp[nums[i]] = i;&#10;    }&#10;    return {};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Hash 10 Group Anagrams<br><br></b> <a href="https://leetcode.com/problems/group-anagrams/" target="_blank">LeetCode 49</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> strs = ["eat","tea","tan","ate","nat","bat"]<br><b>Output:</b> [["bat"],["nat","tan"],["ate","eat","tea"]]</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td>Optimal: Use a hash map where the key is the sorted version of the string, and the value is a list of anagrams.<br><br><b>Dependencies:</b> <code>std::unordered_map</code>, <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Empty Strings:</b> Safely handled since an empty string sorted is still empty, forming a valid key.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;std::string&gt;&gt; groupAnagrams(std::vector&lt;std::string&gt;&amp; strs) {&#10;    std::unordered_map&lt;std::string, std::vector&lt;std::string&gt;&gt; mpp;&#10;    for(std::string s : strs) {&#10;        std::string key = s;&#10;        std::sort(key.begin(), key.end());&#10;        mpp[key].push_back(s);&#10;    }&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    for(auto it : mpp) {&#10;        ans.push_back(it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Hash 11 Longest Consecutive Sequence<br><br></b> <a href="https://leetcode.com/problems/longest-consecutive-sequence/" target="_blank">LeetCode 128</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [100,4,200,1,3,2]<br><b>Output:</b> 4 (The sequence is [1, 2, 3, 4])</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array first, then count consecutive elements linearly.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestConsecutive(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return 0;&#10;    sort(nums.begin(), nums.end());&#10;    int longest = 1, current = 1;&#10;    for(int i=1; i&lt;nums.size(); i++) {&#10;        if(nums[i] == nums[i-1]) continue;&#10;        if(nums[i] == nums[i-1] + 1) current++;&#10;        else {&#10;            longest = max(longest, current);&#10;            current = 1;&#10;        }&#10;    }&#10;    return max(longest, current);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 2:</b><br>Optimal: Insert all elements into a Hash Set. Iterate through elements. If `num - 1` is NOT in the set, it's the start of a sequence. Count forwards.<br><br><b>Dependencies:</b> <code>std::unordered_set</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Elements:</b> Handled automatically by the Set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestConsecutive(std::vector&lt;int&gt;&amp; nums) {&#10;    std::unordered_set&lt;int&gt; st(nums.begin(), nums.end());&#10;    int max_len = 0;&#10;    for(int num : st) {&#10;        if(st.find(num - 1) == st.end()) {&#10;            int curr_num = num;&#10;            int curr_len = 1;&#10;            while(st.find(curr_num + 1) != st.end()) {&#10;                curr_num++;&#10;                curr_len++;&#10;            }&#10;            max_len = std::max(max_len, curr_len);&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Hash 12 Longest Subarray With 0 Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Maintain the prefix sum and a hash map storing the first occurrence index of each prefix sum. If sum is 0, length is `i+1`. If sum is in the map, length is `i - map[sum]`. Update max length.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(vector&lt;int&gt;&amp; A, int n) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int maxi = 0, sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += A[i];&#10;        if(sum == 0) maxi = i + 1;&#10;        else {&#10;            if(m.find(sum) != m.end()) {&#10;                maxi = max(maxi, i - m[sum]);&#10;            } else {&#10;                m[sum] = i;&#10;            }&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Hash 13 Sort Characters By Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-characters-by-frequency/" target="_blank">LeetCode 451</a></td>
      <td rowspan="1"><b> </b> Hash Map + Priority Queue / Sorting.</td>
      <td><b>Time:</b> O(N log K) where K is unique chars<br><b>Space:</b> O(K)</td>
      <td>Optimal: Count frequencies using a hash map. Add pairs `(freq, char)` to a max heap or vector and sort. Reconstruct string.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; freq;&#10;    for(char c : s) freq[c]++;&#10;    vector&lt;pair&lt;int, char&gt;&gt; v;&#10;    for(auto it : freq) v.push_back({it.second, it.first});&#10;    sort(v.rbegin(), v.rend());&#10;    string ans = &quot;&quot;;&#10;    for(auto it : v) {&#10;        ans += string(it.first, it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Hash 14 Count Distinct Elements In Every Window<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Optimal: Use a hash map to keep track of element frequencies in the window of size K. The number of distinct elements is the size of the hash map. As window slides, increment frequency of new element, decrement frequency of outgoing element. If frequency becomes 0, remove it from map.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; countDistinct(int A[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; k; i++) m[A[i]]++;&#10;    ans.push_back(m.size());&#10;    for(int i = k; i &lt; n; i++) {&#10;        m[A[i - k]]--;&#10;        if(m[A[i - k]] == 0) m.erase(A[i - k]);&#10;        m[A[i]]++;&#10;        ans.push_back(m.size());&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Hash 15 Design Hashset<br><br></b> <a href="https://leetcode.com/problems/design-hashset/" target="_blank">LeetCode 705</a></td>
      <td rowspan="1"><b> </b> Array of Linked Lists (Chaining).</td>
      <td><b>Time:</b> O(1) average, O(N) worst case<br><b>Space:</b> O(N)</td>
      <td>Optimal: Use a large array (e.g., size 10000) of linked lists or vectors. The hash function maps `key` to `key % 10000`. To add, if not present in the bucket, append it. To remove, find and erase. To contain, iterate through bucket.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MyHashSet {&#10;    vector&lt;list&lt;int&gt;&gt; buckets;&#10;    int size = 10000;&#10;public:&#10;    MyHashSet() {&#10;        buckets.resize(size);&#10;    }&#10;    void add(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it == buckets[i].end()) buckets[i].push_back(key);&#10;    }&#10;    void remove(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it != buckets[i].end()) buckets[i].erase(it);&#10;    }&#10;    bool contains(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        return it != buckets[i].end();&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>
