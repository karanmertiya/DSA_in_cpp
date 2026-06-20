# Step 02 Sorting Revision Table

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
      <td>Sort 01 Selection Sort<br><br></b> <a href='https://www.geeksforgeeks.org/problems/selection-sort/1' target='_blank'>GeeksforGeeks</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {4, 1, 3, 9, 7}, Output: 1 3 4 7 9<br><br><b>Note (Constraint):</b> In-place sorting.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::swap</code></td>
      <td><b>Worst Case:</b> Always `O(N^2)` even if the array is already sorted.</td>
      <td><b>Explanation:</b> Find the minimum element in the unsorted array and swap it with the element at the beginning.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;void selectionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt; n - 1; i++) {&#10;        int min_idx = i;&#10;        for (int j = i + 1; j &lt; n; j++) {&#10;            if (arr[j] &lt; arr[min_idx]) {&#10;                min_idx = j;&#10;            }&#10;        }&#10;        std::swap(arr[i], arr[min_idx]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Sort 02 Bubble Sort<br><br></b> <a href='https://www.geeksforgeeks.org/problems/bubble-sort/1' target='_blank'>GeeksforGeeks</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {4, 1, 3, 9, 7}, Output: 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Best Case Check:</b> Adding `did_swap` flag makes Best Case time `O(N)` for already sorted arrays.</td>
      <td><b>Explanation:</b> Repeatedly swap adjacent elements if they are in the wrong order. Push the maximum element to the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;void bubbleSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = n - 1; i &gt;= 0; i--) {&#10;        bool did_swap = false;&#10;        for (int j = 0; j &lt;= i - 1; j++) {&#10;            if (arr[j] &gt; arr[j + 1]) {&#10;                std::swap(arr[j], arr[j + 1]);&#10;                did_swap = true;&#10;            }&#10;        }&#10;        if (!did_swap) break;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Sort 03 Insertion Sort<br><br></b> <a href='https://www.geeksforgeeks.org/problems/insertion-sort/1' target='_blank'>GeeksforGeeks</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {4, 1, 3, 9, 7}, Output: 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Online Algorithm:</b> Good for data coming in one by one. `O(N)` best case time.</td>
      <td><b>Explanation:</b> Takes an element and places it in its correct position within the previously sorted part of the array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;void insertionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt;= n - 1; i++) {&#10;        int j = i;&#10;        while (j &gt; 0 &amp;&amp; arr[j - 1] &gt; arr[j]) {&#10;            std::swap(arr[j - 1], arr[j]);&#10;            j--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Sort 04 Merge Sort<br><br></b> <a href='https://www.geeksforgeeks.org/problems/merge-sort/1' target='_blank'>GeeksforGeeks</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {4, 1, 3, 9, 7}, Output: 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Extra array for merging</td>
      <td><b>Stable Sort:</b> Maintains relative order of equal elements. Requires `O(N)` extra space to merge.</td>
      <td><b>Explanation:</b> Recursively split array in half, sort them, and merge the sorted halves.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;&#10;void mergeSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if (low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSortHelper(arr, low, mid);&#10;    mergeSortHelper(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}&#10;&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr) {&#10;    mergeSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Sort 05 Quick Sort<br><br></b> <a href='https://www.geeksforgeeks.org/problems/quick-sort/1' target='_blank'>GeeksforGeeks</a></td>
      <td><b>Example 1:</b> Input: N = 5, arr[] = {4, 1, 3, 9, 7}, Output: 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Worst Case:</b> `O(N^2)` if array is already sorted and pivot is extreme. Avoided by randomized pivot.</td>
      <td><b>Explanation:</b> Pick a pivot. Place smaller elements left and larger right. Recursively sort partitions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;utility&gt;&#10;&#10;int partition(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int pivot = arr[low];&#10;    int i = low, j = high;&#10;    while(i &lt; j) {&#10;        while(arr[i] &lt;= pivot &amp;&amp; i &lt;= high - 1) i++;&#10;        while(arr[j] &gt; pivot &amp;&amp; j &gt;= low + 1) j--;&#10;        if(i &lt; j) std::swap(arr[i], arr[j]);&#10;    }&#10;    std::swap(arr[low], arr[j]);&#10;    return j;&#10;}&#10;&#10;void quickSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &lt; high) {&#10;        int pIndex = partition(arr, low, high);&#10;        quickSortHelper(arr, low, pIndex - 1);&#10;        quickSortHelper(arr, pIndex + 1, high);&#10;    }&#10;}&#10;&#10;void quickSort(std::vector&lt;int&gt;&amp; arr) {&#10;    quickSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Sort 06 Merge Sort<br><br></b> <a href='https://leetcode.com/problems/sort-an-array/' target='_blank'>LeetCode 912</a></td>
      <td><b>Example 1:</b> Input: nums = [5,2,3,1], Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>In-place illusion:</b> True Merge Sort requires `O(N)` auxiliary space for the `temp` merge array. An in-place version exists but degrades time complexity.</td>
      <td><b>Explanation:</b> Divide and Conquer. Split array into halves until size 1. Merge sorted halves using a temporary array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSort(arr, low, mid);&#10;    mergeSort(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
