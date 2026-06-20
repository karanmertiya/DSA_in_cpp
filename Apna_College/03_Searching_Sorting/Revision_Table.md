# 03 Searching Sorting Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 15%;">Complexity</th>
      <th style="width: 35%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Arr 01 Search A 2D Matrix<br><br></b> <a href="https://leetcode.com/problems/search-a-2d-matrix/" target="_blank">LeetCode 74</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Apna College, Love Babbar</details></td>
      <td><b></b> <br><b>Input:</b> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log(m * n))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Optimal: Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(!matrix.size()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int low = 0, high = (m * n) - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + (high - low) / 2);&#10;        if(matrix[mid/n][mid % n] == target) return true;&#10;        if(matrix[mid/n][mid % n] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Sort 02 Merge Sort<br><br></b> <a href="https://leetcode.com/problems/sort-an-array/" target="_blank">LeetCode 912</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, Apna College</details></td>
      <td><b></b> <br><b>Input:</b> nums = [5,2,3,1]<br><b>Output:</b> [1,2,3,5]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Divide and Conquer. Split array into halves until size 1. Merge sorted halves using a temporary array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSort(arr, low, mid);&#10;    mergeSort(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Bs 03 Find Minimum In Rotated Sorted Array<br><br></b> <a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/" target="_blank">LeetCode 153</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Apna College, Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums = [3,4,5,1,2]<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Optimal: Binary Search. Compare mid with right pointer. If nums[mid] > nums[right], the min is in the right half. Else, the min is in the left half including mid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMin(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &gt; nums[right]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return nums[left];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Bs 04 Find Peak Element<br><br></b> <a href="https://leetcode.com/problems/find-peak-element/" target="_blank">LeetCode 162</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Apna College, Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Optimal: Binary Search. If nums[mid] < nums[mid+1], we are on an ascending slope, so a peak must be to the right. Otherwise, we are on a descending slope, peak is to the left (including mid).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPeakElement(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &lt; nums[mid+1]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return left;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
