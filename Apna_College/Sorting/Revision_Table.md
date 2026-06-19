# Sorting Revision Table

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
      <td rowspan="1">Sort 02 Merge Sort<br><br></b> <a href='https://leetcode.com/problems/sort-an-array/' target='_blank'>LeetCode 912</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [5,2,3,1], Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>In-place illusion:</b> True Merge Sort requires `O(N)` auxiliary space for the `temp` merge array. An in-place version exists but degrades time complexity.</td>
      <td><b>Explanation:</b> Divide and Conquer. Split array into halves until size 1. Merge sorted halves using a temporary array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSort(arr, low, mid);&#10;    mergeSort(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sort 03 Quick Sort<br><br></b> <a href='https://leetcode.com/problems/sort-an-array/' target='_blank'>LeetCode 912</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [5,2,3,1], Output: [1,2,3,5]</td>
      <td><b>Time:</b> O(N log N) Avg, O(N<sup>2</sup>) Worst<br><b>Space:</b> O(log N)</td>
      <td><code>std::swap</code></td>
      <td><b>Worst Case:</b> If array is already sorted and we pick the first element as pivot, it devolves to `O(N^2)`. Randomizing the pivot mitigates this.</td>
      <td><b>Explanation:</b> Divide and Conquer. Pick a pivot (e.g., first element), partition elements smaller to the left and larger to the right. Recurse.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;int partition(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int pivot = arr[low];&#10;    int i = low, j = high;&#10;    while(i &lt; j) {&#10;        while(arr[i] &lt;= pivot &amp;&amp; i &lt;= high - 1) i++;&#10;        while(arr[j] &gt; pivot &amp;&amp; j &gt;= low + 1) j--;&#10;        if(i &lt; j) std::swap(arr[i], arr[j]);&#10;    }&#10;    std::swap(arr[low], arr[j]);&#10;    return j;&#10;}&#10;void quickSort(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &lt; high) {&#10;        int pIndex = partition(arr, low, high);&#10;        quickSort(arr, low, pIndex - 1);&#10;        quickSort(arr, pIndex + 1, high);&#10;    }&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
