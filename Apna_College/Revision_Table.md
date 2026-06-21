# Apna College Master Revision Table

## 03 Searching Sorting

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
      <td rowspan="1">1</td>
      <td rowspan="1">Arr 01 Search A 2D Matrix<br><br></b> <a href="https://leetcode.com/problems/search-a-2d-matrix/" target="_blank">LeetCode 74</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log(m * n))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.</td>
      <td><b>Edge Cases:</b> <b>Empty Matrix:</b> Return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(!matrix.size()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int low = 0, high = (m * n) - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + (high - low) / 2);&#10;        if(matrix[mid/n][mid % n] == target) return true;&#10;        if(matrix[mid/n][mid % n] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sort 02 Selection Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/selection-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9<br><br><b> </b> In-place sorting.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Find the minimum element in the unsorted array and swap it with the element at the beginning.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> Always `O(N^2)` even if the array is already sorted.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void selectionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt; n - 1; i++) {&#10;        int min_idx = i;&#10;        for (int j = i + 1; j &lt; n; j++) {&#10;            if (arr[j] &lt; arr[min_idx]) {&#10;                min_idx = j;&#10;            }&#10;        }&#10;        std::swap(arr[i], arr[min_idx]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sort 03 Bubble Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bubble-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>Repeatedly swap adjacent elements if they are in the wrong order. Push the maximum element to the end.</td>
      <td><b>Edge Cases:</b> <b>Best Case Check:</b> Adding `did_swap` flag makes Best Case time `O(N)` for already sorted arrays.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bubbleSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = n - 1; i &gt;= 1; i--) {&#10;        bool did_swap = false;&#10;        for (int j = 0; j &lt;= i - 1; j++) {&#10;            if (arr[j] &gt; arr[j + 1]) {&#10;                std::swap(arr[j], arr[j + 1]);&#10;                did_swap = true;&#10;            }&#10;        }&#10;        if (!did_swap) break;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sort 04 Insertion Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/insertion-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Takes an element and places it in its correct position within the previously sorted part of the array.</td>
      <td><b>Edge Cases:</b> <b>Online Algorithm:</b> Good for data coming in one by one. `O(N)` best case time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt;= n - 1; i++) {&#10;        int j = i;&#10;        while (j &gt; 0 &amp;&amp; arr[j - 1] &gt; arr[j]) {&#10;            std::swap(arr[j - 1], arr[j]);&#10;            j--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sort 05 Merge Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/merge-sort/1" target="_blank">GFG</a> | <a href="https://leetcode.com/problems/sort-an-array/" target="_blank">LC 912</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Recursively split array in half, sort them, and merge the sorted halves.<br><br><b>Dependencies:</b> Extra array for merging</td>
      <td><b>Edge Cases:</b> <b>Stable Sort:</b> Maintains relative order of equal elements. Requires `O(N)` extra space to merge.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;&#10;void mergeSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if (low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSortHelper(arr, low, mid);&#10;    mergeSortHelper(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}&#10;&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr) {&#10;    mergeSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sort 06 Quick Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/quick-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Pick a pivot. Place smaller elements left and larger right. Recursively sort partitions.</td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> `O(N^2)` if array is already sorted and pivot is extreme. Avoided by randomized pivot.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int partition(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int pivot = arr[low];&#10;    int i = low, j = high;&#10;    while(i &lt; j) {&#10;        while(arr[i] &lt;= pivot &amp;&amp; i &lt;= high - 1) i++;&#10;        while(arr[j] &gt; pivot &amp;&amp; j &gt;= low + 1) j--;&#10;        if(i &lt; j) std::swap(arr[i], arr[j]);&#10;    }&#10;    std::swap(arr[low], arr[j]);&#10;    return j;&#10;}&#10;&#10;void quickSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &lt; high) {&#10;        int pIndex = partition(arr, low, high);&#10;        quickSortHelper(arr, low, pIndex - 1);&#10;        quickSortHelper(arr, pIndex + 1, high);&#10;    }&#10;}&#10;&#10;void quickSort(std::vector&lt;int&gt;&amp; arr) {&#10;    quickSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Bs 07 Find Minimum In Rotated Sorted Array<br><br></b> <a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/" target="_blank">LeetCode 153</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [3,4,5,1,2]<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary Search. Compare mid with right pointer. If nums[mid] > nums[right], the min is in the right half. Else, the min is in the left half including mid.</td>
      <td><b>Edge Cases:</b> <b>Fully sorted array:</b> Loop naturally converges to the first element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMin(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &gt; nums[right]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return nums[left];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Bs 08 Find Peak Element<br><br></b> <a href="https://leetcode.com/problems/find-peak-element/" target="_blank">LeetCode 162</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary Search. If nums[mid] < nums[mid+1], we are on an ascending slope, so a peak must be to the right. Otherwise, we are on a descending slope, peak is to the left (including mid).</td>
      <td><b>Edge Cases:</b> <b>Peak at boundaries:</b> The binary search logic intrinsically handles edges by shrinking bounds away from negative slopes.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPeakElement(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &lt; nums[mid+1]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return left;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 02 Strings

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
      <td rowspan="1">1</td>
      <td rowspan="1">Str 01 Longest Common Prefix<br><br></b> <a href="https://leetcode.com/problems/longest-common-prefix/" target="_blank">LeetCode 14</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> strs = ["flower","flow","flight"]<br><b>Output:</b> "fl"</td>
      <td><b>Time:</b> O(N log N * M) (Constraint)<br><b>Space:</b> O(1) / O(M)</td>
      <td>Sort the array. The common prefix will be constrained by the first and last strings in the sorted array.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>No Match:</b> If the first character of `first` and `last` string doesn't match, loop breaks immediately, returning "".<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::string longestCommonPrefix(std::vector&lt;std::string&gt;&amp; strs) {&#10;    if (strs.empty()) return &quot;&quot;;&#10;    std::sort(strs.begin(), strs.end());&#10;    std::string first = strs.front();&#10;    std::string last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; i &lt; last.size() &amp;&amp; first[i] == last[i]) {&#10;        i++;&#10;    }&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Str 02 Longest Palindromic Substring<br><br></b> <a href="https://leetcode.com/problems/longest-palindromic-substring/" target="_blank">LeetCode 5</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "babad"<br><b>Output:</b> "bab"</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Expand Around Center. A palindrome can have an odd (center is 1 char) or even (center is between 2 chars) length. Test both.</td>
      <td><b>Edge Cases:</b> <b>Substr Math:</b> `start` is calculated as `i - (len - 1) / 2` to safely encompass both odd and even length centers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int expand(std::string&amp; s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}&#10;&#10;std::string longestPalindrome(std::string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, max_len = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expand(s, i, i);&#10;        int len2 = expand(s, i, i + 1);&#10;        int len = std::max(len1, len2);&#10;        if (len &gt; max_len) {&#10;            max_len = len;&#10;            start = i - (len - 1) / 2;&#10;        }&#10;    }&#10;    return s.substr(start, max_len);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 08 Stacks Queues

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
      <td rowspan="1">1</td>
      <td rowspan="1">Sw 01 Sliding Window Maximum<br><br></b> <a href="https://leetcode.com/problems/sliding-window-maximum/" target="_blank">LeetCode 239</a></td>
      <td rowspan="1"><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Use a deque to store indices. The deque maintains elements in decreasing order. Remove elements from the back if they are smaller than the current element. Remove elements from the front if they are out of the window. The front element is the maximum of the current window.<br><br><b>Dependencies:</b> <code>#include <deque></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(nums[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 02 Valid Parentheses<br><br></b> <a href="https://leetcode.com/problems/valid-parentheses/" target="_blank">LeetCode 20</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "()[]{}"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><b>Dependencies:</b> <code>std::stack</code></td>
      <td><b>Edge Cases:</b> <b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sq 03 Min Stack<br><br></b> <a href="https://leetcode.com/problems/min-stack/" target="_blank">LeetCode 155</a></td>
      <td rowspan="1"><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td>Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 14 DP

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
      <td rowspan="1">1</td>
      <td rowspan="1">Rec 01 Word Break<br><br></b> <a href="https://leetcode.com/problems/word-break/" target="_blank">LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = 'leetcode', wordDict = ['leet','code']<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td>Recursion with Memoization (or DP). For each index, try all possible word lengths. If a prefix exists in dict, recurse for the suffix. DP array `dp[i]` stores if `s[0...i-1]` is valid.<br><br><b>Dependencies:</b> <code>#include <unordered_set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">DP 02 Matrix Chain Multiplication<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N=5, arr=[40, 20, 30, 10, 30]<br><b>Output:</b> 26000</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>Partition DP. Try partitioning the matrices at every possible split `k` between `i` and `j`. Cost is `arr[i-1]*arr[k]*arr[j]`. Take the minimum.<br><br><b>Dependencies:</b> <code>#include <vector></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int f(int i, int j, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; dp) {&#10;    if(i == j) return 0;&#10;    if(dp[i][j] != -1) return dp[i][j];&#10;    int mini = 1e9;&#10;    for(int k=i; k&lt;j; k++) {&#10;        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);&#10;        mini = min(mini, steps);&#10;    }&#10;    return dp[i][j] = mini;&#10;}&#10;int matrixMultiplication(int N, vector&lt;int&gt;&amp; arr) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, -1));&#10;    return f(1, N-1, arr, dp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">DP 03 Subset Sum Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> set=[3,34,4,12,5,2], sum=9<br><b>Output:</b> True</td>
      <td><b>Time:</b> O(N * Sum)<br><b>Space:</b> O(Sum) space optimized</td>
      <td>DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSubsetSum(vector&lt;int&gt;arr, int sum) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; prev(sum+1, false), cur(sum+1, false);&#10;    prev[0] = cur[0] = true;&#10;    if(arr[0] &lt;= sum) prev[arr[0]] = true;&#10;    for(int ind=1; ind&lt;n; ind++) {&#10;        for(int target=1; target&lt;=sum; target++) {&#10;            bool notTaken = prev[target];&#10;            bool taken = false;&#10;            if(arr[ind] &lt;= target) taken = prev[target - arr[ind]];&#10;            cur[target] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[sum];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 07 Linked List

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
      <td rowspan="1">1</td>
      <td rowspan="1">Ll 01 Intersection Of Two Linked Lists<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/" target="_blank">LeetCode 160</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3<br><b>Output:</b> Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.</td>
      <td><b>Edge Cases:</b> <b>No Intersection:</b> If no intersection, both pointers will simultaneously hit `NULL` at the end of their second traversal.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Ll 02 Reverse Nodes In K Group<br><br></b> <a href="https://leetcode.com/problems/reverse-nodes-in-k-group/" target="_blank">LeetCode 25</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5], k = 2<br><b>Output:</b> [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.</td>
      <td><b>Edge Cases:</b> <b>Remaining nodes < K:</b> The loop terminates early, leaving the remaining list intact.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int count = 0; ListNode* dummy = new ListNode(0); dummy-&gt;next = head;&#10;    ListNode *cur = head, *nex, *pre = dummy;&#10;    while(cur) { count++; cur = cur-&gt;next; }&#10;    while(count &gt;= k) {&#10;        cur = pre-&gt;next;&#10;        nex = cur-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            cur-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = cur-&gt;next;&#10;        }&#10;        pre = cur;&#10;        count -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 09 Trees

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
      <td rowspan="1">1</td>
      <td rowspan="1">Tree 01 Lowest Common Ancestor Of A Binary Tree<br><br></b> <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/" target="_blank">LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If we find `p` or `q`, return it. If both left and right return non-null, current node is LCA.</td>
      <td><b>Edge Cases:</b> <b>Node is LCA:</b> If one is ancestor of other, it returns immediately.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if (!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if (!left) return right;&#10;    else if (!right) return left;&#10;    else return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Tree 02 Same Tree<br><br></b> <a href="https://leetcode.com/problems/same-tree/" target="_blank">LeetCode 100</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> p = [1,2,3], q = [1,2,3]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Traverse both trees simultaneously. If both nodes are null, true. If one is null or values mismatch, false.</td>
      <td><b>Edge Cases:</b> <b>Structural mismatch:</b> Safely handled by `!p || !q`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p &amp;&amp; !q) return true;&#10;    if(!p || !q || p-&gt;val != q-&gt;val) return false;&#10;    return isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Tree 03 Diameter Of Binary Tree<br><br></b> <a href="https://leetcode.com/problems/diameter-of-binary-tree/" target="_blank">LeetCode 543</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [1,2,3,4,5]<br><b>Output:</b> 3 (Path is [4,2,1,3] or [5,2,1,3])</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Modify the Height/Depth algorithm. Calculate `left_depth + right_depth` at every node to find max diameter, while returning standard height.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Path doesn't pass through root:</b> Handled correctly by tracking the global maximum `max_d` at every recursive step.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int height(TreeNode* node, int&amp; max_d) {&#10;    if(!node) return 0;&#10;    int left = height(node-&gt;left, max_d);&#10;    int right = height(node-&gt;right, max_d);&#10;    max_d = std::max(max_d, left + right);&#10;    return 1 + std::max(left, right);&#10;}&#10;int diameterOfBinaryTree(TreeNode* root) {&#10;    int max_d = 0;&#10;    height(root, max_d);&#10;    return max_d;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Tree 04 Construct Tree From Preorder And Inorder<br><br></b> <a href="https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/" target="_blank">LeetCode 105</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]<br><b>Output:</b> [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for Hash Map</td>
      <td>First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    unordered_map&lt;int, int&gt; inMap;&#10;    for(int i=0; i&lt;inorder.size(); i++) inMap[inorder[i]] = i;&#10;    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; pre, int preStart, int preEnd, vector&lt;int&gt;&amp; in, int inStart, int inEnd, unordered_map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(pre[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);&#10;    root-&gt;right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Tree 05 Maximum Path Sum<br><br></b> <a href="https://leetcode.com/problems/binary-tree-maximum-path-sum/" target="_blank">LeetCode 124</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [-10,9,20,null,null,15,7]<br><b>Output:</b> 42</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.<br><br><b>Dependencies:</b> <code>#include <limits.h></code></td>
      <td><b>Edge Cases:</b> <b>All Negative Nodes:</b> Initialization with `INT_MIN` properly returns the least negative node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxPathSum(TreeNode* root) {&#10;    int maxi = INT_MIN;&#10;    maxPathDown(root, maxi);&#10;    return maxi;&#10;}&#10;int maxPathDown(TreeNode* node, int&amp; maxi) {&#10;    if(!node) return 0;&#10;    int left = max(0, maxPathDown(node-&gt;left, maxi));&#10;    int right = max(0, maxPathDown(node-&gt;right, maxi));&#10;    maxi = max(maxi, left + right + node-&gt;val);&#10;    return max(left, right) + node-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Tree 06 Boundary Traversal<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return array of boundary nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isLeaf(TreeNode* root) { return !root-&gt;left &amp;&amp; !root-&gt;right; }&#10;void addLeft(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;left;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) res.push_back(cur-&gt;val);&#10;        if(cur-&gt;left) cur = cur-&gt;left;&#10;        else cur = cur-&gt;right;&#10;    }&#10;}&#10;void addRight(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;right;&#10;    vector&lt;int&gt; tmp;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) tmp.push_back(cur-&gt;val);&#10;        if(cur-&gt;right) cur = cur-&gt;right;&#10;        else cur = cur-&gt;left;&#10;    }&#10;    for(int i = tmp.size()-1; i&gt;=0; --i) res.push_back(tmp[i]);&#10;}&#10;void addLeaves(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    if(isLeaf(root)) { res.push_back(root-&gt;val); return; }&#10;    if(root-&gt;left) addLeaves(root-&gt;left, res);&#10;    if(root-&gt;right) addLeaves(root-&gt;right, res);&#10;}&#10;vector&lt;int&gt; boundary(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    if(!isLeaf(root)) res.push_back(root-&gt;val);&#10;    addLeft(root, res); addLeaves(root, res); addRight(root, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 10 Heaps

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
      <td rowspan="1">1</td>
      <td rowspan="1">Heap 01 Merge K Sorted Lists<br><br></b> <a href="https://leetcode.com/problems/merge-k-sorted-lists/" target="_blank">LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> lists = [[1,4,5],[1,3,4],[2,6]]<br><b>Output:</b> [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td>Push the head of each list into a Min-Heap. Repeatedly pop the smallest node, attach it to the result list, and push its `next` node into the heap.<br><br><b>Dependencies:</b> Custom Comparator</td>
      <td><b>Edge Cases:</b> <b>Pointer Compare:</b> Priority queues need a custom comparator to sort `ListNode*` by their `val`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Compare {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;&#10;ListNode* mergeKLists(std::vector&lt;ListNode*&gt;&amp; lists) {&#10;    std::priority_queue&lt;ListNode*, std::vector&lt;ListNode*&gt;, Compare&gt; pq;&#10;    for (auto list : lists) {&#10;        if (list) pq.push(list);&#10;    }&#10;    &#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    &#10;    while (!pq.empty()) {&#10;        ListNode* node = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = node;&#10;        tail = tail-&gt;next;&#10;        if (node-&gt;next) pq.push(node-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 13 Graphs

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
      <td rowspan="1">1</td>
      <td rowspan="1">Graph 01 Bellman Ford<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> V=3, S=0, Edges=[[0,1,5],[1,2,-2],[2,1,-3]]<br><b>Output:</b> [-1]</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td>Relax all edges V-1 times. To detect a negative cycle, relax one more time; if any distance updates, there's a negative cycle.</td>
      <td><b>Edge Cases:</b> <b>Disconnected Graphs:</b> Elements unreachable from source remain at 1e8.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bellman_ford(int V, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int S) {&#10;    vector&lt;int&gt; dist(V, 1e8);&#10;    dist[S] = 0;&#10;    for(int i=0; i&lt;V-1; i++) {&#10;        for(auto it: edges) {&#10;            int u = it[0], v = it[1], wt = it[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto it: edges) {&#10;        int u = it[0], v = it[1], wt = it[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return {-1};&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Graph 02 Floyd Warshall<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> Shortest paths for all pairs (i, j).</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(1) in-place</td>
      <td>Multi-source shortest path. Try to go from i to j via every possible vertex k. Update `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`.</td>
      <td><b>Edge Cases:</b> <b>Unreachable nodes:</b> Represented by -1. Replace with 1e9 before algorithm, then back to -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void shortest_distance(vector&lt;vector&lt;int&gt;&gt;&amp; matrix){&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == -1) matrix[i][j] = 1e9;&#10;            if(i == j) matrix[i][j] = 0;&#10;        }&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(matrix[i][k] != 1e9 &amp;&amp; matrix[k][j] != 1e9) {&#10;                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == 1e9) matrix[i][j] = -1;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Graph 03 Mst Prims<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return the scalar sum of the MST.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(E + V)</td>
      <td>Prim's Algorithm. Use a Min-Heap `(weight, node)`. Always pick the smallest available edge connecting the MST to an unvisited node.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int node = it.second, wt = it.first;&#10;        if(vis[node] == 1) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto it: adj[node]) {&#10;            int adjNode = it[0], edW = it[1];&#10;            if(!vis[adjNode]) pq.push({edW, adjNode});&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Graph 04 Strongly Connected Components Kosaraju<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return an integer count.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Kosaraju's Algo: 1) Sort nodes by finish time (Topo Sort DFS). 2) Transpose the graph (reverse edges). 3) DFS on transposed graph in order of finish time.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt;&amp; vis, vector&lt;vector&lt;int&gt;&gt;&amp; adj, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it: adj[node]) if(!vis[it]) dfs(it, vis, adj, st);&#10;    st.push(node);&#10;}&#10;void dfs3(int node, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adjT[]) {&#10;    vis[node] = 1;&#10;    for(auto it: adjT[node]) if(!vis[it]) dfs3(it, vis, adjT);&#10;}&#10;int kosaraju(int V, vector&lt;vector&lt;int&gt;&gt;&amp; adj) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) if(!vis[i]) dfs(i, vis, adj, st);&#10;    vector&lt;int&gt; adjT[V];&#10;    for(int i=0; i&lt;V; i++) {&#10;        vis[i] = 0;&#10;        for(auto it: adj[i]) adjT[it].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            scc++; dfs3(node, vis, adjT);&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## 12 Tries

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
      <td rowspan="1">1</td>
      <td rowspan="1">Trie 01 Implement Trie II<br><br></b> <a href="https://www.codingninjas.com/studio/problems/implement-trie_1387095" target="_blank">Coding Ninjas</a></td>
      <td rowspan="1"><b>Example 1:</b> Specialized Trie functions.</td>
      <td><b>Time:</b> O(len) per operation<br><b>Space:</b> O(N * len)</td>
      <td>Trie Nodes have a `cntEndWith` and `cntPrefix` integers. Increment `cntPrefix` dynamically as you insert, and `cntEndWith` at the final node. Decrement them during erase.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    int cntEndWith = 0;&#10;    int cntPrefix = 0;&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    void increaseEnd() { cntEndWith++; }&#10;    void increasePrefix() { cntPrefix++; }&#10;    void deleteEnd() { cntEndWith--; }&#10;    void reducePrefix() { cntPrefix--; }&#10;};&#10;class Trie {&#10;private: Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(!node-&gt;containsKey(word[i])) node-&gt;put(word[i], new Node());&#10;            node = node-&gt;get(word[i]);&#10;            node-&gt;increasePrefix();&#10;        }&#10;        node-&gt;increaseEnd();&#10;    }&#10;    int countWordsEqualTo(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(node-&gt;containsKey(word[i])) node = node-&gt;get(word[i]);&#10;            else return 0;&#10;        }&#10;        return node-&gt;cntEndWith;&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>


