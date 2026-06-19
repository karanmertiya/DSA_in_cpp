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
      <td>1</td>
      <td>Bs 01 Binary Search<br><br></b> <a href='https://leetcode.com/problems/binary-search/' target='_blank'>LeetCode 704</a></td>
      <td><b>Example 1:</b> Input: nums = [-1,0,3,5,9,12], target = 9, Output: 4</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Mid Overflow:</b> Use `mid = low + (high - low) / 2` to avoid integer overflow if boundaries are large.</td>
      <td><b>Explanation:</b> Standard Iterative approach. Maintain `low` and `high` boundaries, shrinking the search space by half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        else if(nums[mid] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Bs 02 Lower Bound<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: arr = [1,2,8,10,11,12,19], target = 0, Output: 0</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::lower_bound</code> internal alternative</td>
      <td><b>Not Found:</b> If all elements are smaller, `ans` stays `N`.</td>
      <td><b>Explanation:</b> When `nums[mid] >= target`, it is a potential answer. Store it and search left (`high = mid - 1`) for smaller potentials.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int lowerBound(std::vector&lt;int&gt; arr, int n, int x) {&#10;    int low = 0, high = n - 1;&#10;    int ans = n;&#10;    while (low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if (arr[mid] &gt;= x) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Bs 03 Find First And Last Position Of Element<br><br></b> <a href='https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/' target='_blank'>LeetCode 34</a></td>
      <td><b>Example 1:</b> Input: nums = [5,7,7,8,8,10], target = 8, Output: [3,4]</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Empty Array:</b> Naturally skips loop and returns `[-1, -1]`.</td>
      <td><b>Explanation:</b> Run Binary Search twice. Once to find the first occurrence (bias left), once to find the last occurrence (bias right).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int findBound(std::vector&lt;int&gt;&amp; nums, int target, bool isFirst) {&#10;    int low = 0, high = nums.size() - 1, ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) {&#10;            ans = mid;&#10;            if(isFirst) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else if(nums[mid] &lt; target) {&#10;            low = mid + 1;&#10;        } else {&#10;            high = mid - 1;&#10;        }&#10;    }&#10;    return ans;&#10;}&#10;&#10;std::vector&lt;int&gt; searchRange(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    return {findBound(nums, target, true), findBound(nums, target, false)};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Bs 04 Search In Rotated Sorted Array<br><br></b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array/' target='_blank'>LeetCode 33</a></td>
      <td><b>Example 1:</b> Input: nums = [4,5,6,7,0,1,2], target = 0, Output: 4</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Duplicate Values:</b> If duplicates existed (which they don't in this specific leetcode), we would need to handle `nums[low] == nums[mid] == nums[high]` by shrinking bounds.</td>
      <td><b>Explanation:</b> Identify the sorted half. Check if target lies within the boundaries of the sorted half. If yes, shrink to that half; else, shrink to the other.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        &#10;        // Left half sorted&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } &#10;        // Right half sorted&#10;        else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Bs 05 Koko Eating Bananas<br><br></b> <a href='https://leetcode.com/problems/koko-eating-bananas/' target='_blank'>LeetCode 875</a></td>
      <td><b>Example 1:</b> Input: piles = [3,6,7,11], h = 8, Output: 4<br><br><b>Note (Constraint):</b> Binary Search on Answers.</td>
      <td><b>Time:</b> O(N log(Max(P))) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><code>std::ceil</code> / ceiling math</td>
      <td><b>Ceiling Math:</b> Use `(pile + mid - 1) / mid` to simulate ceiling division without float casting overhead.</td>
      <td><b>Explanation:</b> Search space is `1` to `max(piles)`. For a mid `k`, calculate hours required. If `hours <= h`, it's a valid answer, but search left for smaller `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;bool canEat(std::vector&lt;int&gt;&amp; piles, int k, int h) {&#10;    long long hours = 0;&#10;    for(int pile : piles) {&#10;        hours += (pile + k - 1) / k;&#10;    }&#10;    return hours &lt;= h;&#10;}&#10;&#10;int minEatingSpeed(std::vector&lt;int&gt;&amp; piles, int h) {&#10;    int low = 1, high = *std::max_element(piles.begin(), piles.end());&#10;    int ans = high;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canEat(piles, mid, h)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Bs 06 Find Minimum In Rotated Sorted Array<br><br></b> <a href='https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/' target='_blank'>LeetCode 153</a></td>
      <td><b>Example 1:</b> Input: nums = [3,4,5,1,2], Output: 1</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Fully sorted array:</b> Loop naturally converges to the first element.</td>
      <td><b>Explanation:</b> Binary Search. Compare mid with right pointer. If nums[mid] > nums[right], the min is in the right half. Else, the min is in the left half including mid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMin(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &gt; nums[right]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return nums[left];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Bs 07 Find Peak Element<br><br></b> <a href='https://leetcode.com/problems/find-peak-element/' target='_blank'>LeetCode 162</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3,1], Output: 2</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Peak at boundaries:</b> The binary search logic intrinsically handles edges by shrinking bounds away from negative slopes.</td>
      <td><b>Explanation:</b> Binary Search. If nums[mid] < nums[mid+1], we are on an ascending slope, so a peak must be to the right. Otherwise, we are on a descending slope, peak is to the left (including mid).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPeakElement(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &lt; nums[mid+1]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return left;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Bs 08 Search A 2D Matrix<br><br></b> <a href='https://leetcode.com/problems/search-a-2d-matrix/' target='_blank'>LeetCode 74</a></td>
      <td><b>Example 1:</b> Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3, Output: true</td>
      <td><b>Time:</b> O(log(M * N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Treat the 2D matrix as a 1D flattened array. The element at `index` is at `matrix[index / cols][index % cols]`. Perform standard binary search.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(matrix.empty() || matrix[0].empty()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int left = 0, right = m * n - 1;&#10;    while(left &lt;= right) {&#10;        int mid = left + (right - left) / 2;&#10;        int val = matrix[mid / n][mid % n];&#10;        if(val == target) return true;&#10;        if(val &lt; target) left = mid + 1;&#10;        else right = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Bs 07 Median Of Two Sorted Arrays<br><br></b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a></td>
      <td><b>Example 1:</b> Input: nums1 = [1,3], nums2 = [2], Output: 2.00000</td>
      <td><b>Time:</b> O(log(min(m, n)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Different sizes / One empty:</b> Always binary search on the smaller array to avoid out-of-bounds.</td>
      <td><b>Explanation:</b> Binary Search on the smaller array. Partition both arrays such that the left half has `(m+n+1)/2` elements. Find the valid partition where `max(left1) <= min(right2)` and `max(left2) <= min(right1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int n1 = nums1.size(), n2 = nums2.size();&#10;    int low = 0, high = n1;&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = (n1 + n2 + 1) / 2 - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];&#10;        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];&#10;        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) {&#10;            if((n1 + n2) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2.0;&#10;            else return max(left1, left2);&#10;        }&#10;        else if(left1 &gt; right2) high = cut1 - 1;&#10;        else low = cut1 + 1;&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Bs 08 Allocate Minimum Number Of Pages<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N=4, A=[12,34,67,90], M=2, Output: 113</td>
      <td><b>Time:</b> O(N * log(sum(A) - max(A)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>M > N:</b> Impossible to allocate at least one book to each student, return -1.</td>
      <td><b>Explanation:</b> Binary Search on Answer. The search space for pages is from `max(A)` to `sum(A)`. For a given `mid`, check if books can be allocated to `<= M` students without any student exceeding `mid` pages.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int A[], int N, int M, int maxPages) {&#10;    int students = 1, currentPages = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        if(A[i] &gt; maxPages) return false;&#10;        if(currentPages + A[i] &gt; maxPages) {&#10;            students++; currentPages = A[i];&#10;        } else {&#10;            currentPages += A[i];&#10;        }&#10;    }&#10;    return students &lt;= M;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    int low = 0, high = 0, ans = -1;&#10;    for(int i=0; i&lt;N; i++) { low = max(low, A[i]); high += A[i]; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(A, N, M, mid)) {&#10;            ans = mid; high = mid - 1;&#10;        } else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Bs 10 Kth Element Of Two Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 5, Output: 6</td>
      <td><b>Time:</b> O(log(min(n, m)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the smaller array. Similar to Median of two sorted arrays, but the left partition size is strictly `k`. Search space for `cut1` is `[max(0, k-m), min(k, n)]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = k - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];&#10;        int right1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int right2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) return max(left1, left2);&#10;        else if(left1 &gt; right2) high = cut1 - 1;&#10;        else low = cut1 + 1;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Bs 11 Find Minimum In Rotated Sorted Array<br><br></b> <a href='https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/' target='_blank'>LeetCode 153</a></td>
      <td><b>Example 1:</b> Input: nums = [3,4,5,1,2], Output: 1</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary Search. If `nums[low] <= nums[high]`, the array is sorted, return `nums[low]`. Else, if `nums[low] <= nums[mid]`, the left half is sorted, the minimum is in the right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMin(vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, high = nums.size() - 1;&#10;    int ans = INT_MAX;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(nums[low] &lt;= nums[high]) { ans = min(ans, nums[low]); break; }&#10;        if(nums[low] &lt;= nums[mid]) { ans = min(ans, nums[low]); low = mid + 1; }&#10;        else { ans = min(ans, nums[mid]); high = mid - 1; }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Bs 12 Search In Rotated Sorted Array<br><br></b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array/' target='_blank'>LeetCode 33</a></td>
      <td><b>Example 1:</b> Input: nums = [4,5,6,7,0,1,2], target = 0, Output: 4</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary Search. Identify which half is sorted. If left half is sorted and target is in its range, move `high = mid - 1`, else `low = mid + 1`. Symmetrically for right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Bs 13 Search In Rotated Sorted Array Ii<br><br></b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array-ii/' target='_blank'>LeetCode 81</a></td>
      <td><b>Example 1:</b> Input: nums = [2,5,6,0,0,1,2], target = 0, Output: true</td>
      <td><b>Time:</b> O(log N) average, O(N) worst case<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Duplicates causing ambiguity:</b> Shrink bounds safely.</td>
      <td><b>Explanation:</b> If `nums[low] == nums[mid] == nums[high]`, shrink the search space by `low++` and `high--`. Otherwise, proceed with the standard rotated binary search.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool search(vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(nums[mid] == target) return true;&#10;        if(nums[low] == nums[mid] &amp;&amp; nums[mid] == nums[high]) {&#10;            low++; high--; continue;&#10;        }&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Bs 14 Find Peak Element<br><br></b> <a href='https://leetcode.com/problems/find-peak-element/' target='_blank'>LeetCode 162</a></td>
      <td><b>Example 1:</b> Input: nums = [1,2,3,1], Output: 2</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary Search. If `nums[mid] > nums[mid + 1]`, we are on a descending slope, so a peak must be to the left (or is `mid`). Else, we are on an ascending slope, peak is to the right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPeakElement(vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] &gt; nums[mid + 1]) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Bs 15 Find First And Last Position Of Element In Sorted Array<br><br></b> <a href='https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/' target='_blank'>LeetCode 34</a></td>
      <td><b>Example 1:</b> Input: nums = [5,7,7,8,8,10], target = 8, Output: [3,4]</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use lower_bound for the first occurrence. Use upper_bound - 1 for the last occurrence. Validate if the target actually exists at the lower_bound index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; searchRange(vector&lt;int&gt;&amp; nums, int target) {&#10;    auto lb = lower_bound(nums.begin(), nums.end(), target);&#10;    auto ub = upper_bound(nums.begin(), nums.end(), target);&#10;    if(lb == nums.end() || *lb != target) return {-1, -1};&#10;    return {(int)(lb - nums.begin()), (int)(ub - nums.begin() - 1)};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Bs 16 Koko Eating Bananas<br><br></b> <a href='https://leetcode.com/problems/koko-eating-bananas/' target='_blank'>LeetCode 875</a></td>
      <td><b>Example 1:</b> Input: piles = [3,6,7,11], h = 8, Output: 4</td>
      <td><b>Time:</b> O(N log(max(P)))<br><b>Space:</b> O(1)</td>
      <td><code>#include <math.h></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the answer. Minimum speed is 1, maximum is `max(piles)`. For a given speed `mid`, calculate total hours `sum(ceil(pile / mid))`. If `<= h`, search lower half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long getHours(vector&lt;int&gt;&amp; piles, int speed) {&#10;    long long totalHours = 0;&#10;    for(int p : piles) totalHours += ceil((double)p / speed);&#10;    return totalHours;&#10;}&#10;int minEatingSpeed(vector&lt;int&gt;&amp; piles, int h) {&#10;    int low = 1, high = 0;&#10;    for(int p : piles) high = max(high, p);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(getHours(piles, mid) &lt;= h) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Bs 17 Minimum Days To Make M Bouquets<br><br></b> <a href='https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/' target='_blank'>LeetCode 1482</a></td>
      <td><b>Example 1:</b> Find day threshold.</td>
      <td><b>Time:</b> O(N log(maxD - minD))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on days from `min(bloom)` to `max(bloom)`. Count consecutive bloomed flowers, if it reaches `k`, form a bouquet. Return minimum valid day.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(vector&lt;int&gt;&amp; bloomDay, int m, int k, int day) {&#10;    int count = 0, bouquets = 0;&#10;    for(int d : bloomDay) {&#10;        if(d &lt;= day) count++;&#10;        else {&#10;            bouquets += count / k;&#10;            count = 0;&#10;        }&#10;    }&#10;    bouquets += count / k;&#10;    return bouquets &gt;= m;&#10;}&#10;int minDays(vector&lt;int&gt;&amp; bloomDay, int m, int k) {&#10;    if((long long)m * k &gt; bloomDay.size()) return -1;&#10;    int low = 1e9, high = 0;&#10;    for(int d : bloomDay) { low = min(low, d); high = max(high, d); }&#10;    int ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(bloomDay, m, k, mid)) { ans = mid; high = mid - 1; }&#10;        else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Bs 18 Find The Smallest Divisor Given A Threshold<br><br></b> <a href='https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/' target='_blank'>LeetCode 1283</a></td>
      <td><b>Example 1:</b> Summing ceils.</td>
      <td><b>Time:</b> O(N log(max(nums)))<br><b>Space:</b> O(1)</td>
      <td><code>#include <math.h></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search the divisor from 1 to `max(nums)`. Compute `sum(ceil(num / mid))`. If sum <= threshold, shrink high.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int smallestDivisor(vector&lt;int&gt;&amp; nums, int threshold) {&#10;    int low = 1, high = *max_element(nums.begin(), nums.end());&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        long long sum = 0;&#10;        for(int num : nums) sum += ceil((double)num / mid);&#10;        if(sum &lt;= threshold) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Bs 19 Capacity To Ship Packages Within D Days<br><br></b> <a href='https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/' target='_blank'>LeetCode 1011</a></td>
      <td><b>Example 1:</b> Find ship capacity.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on capacity. Low = `max(weights)`, High = `sum(weights)`. Iterate through packages and accumulate weight, increment day if limit is exceeded.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canShip(vector&lt;int&gt;&amp; weights, int days, int cap) {&#10;    int d = 1, load = 0;&#10;    for(int w : weights) {&#10;        if(load + w &gt; cap) { d++; load = w; }&#10;        else load += w;&#10;    }&#10;    return d &lt;= days;&#10;}&#10;int shipWithinDays(vector&lt;int&gt;&amp; weights, int days) {&#10;    int low = 0, high = 0;&#10;    for(int w : weights) { low = max(low, w); high += w; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canShip(weights, days, mid)) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Bs 25 Minimum Number Of Days To Make M Bouquets<br><br></b> <a href='https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/' target='_blank'>LeetCode 1482</a></td>
      <td><b>Example 1:</b> Binary search on answer.</td>
      <td><b>Time:</b> O(N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Impossible:</b> If m * k > n, return -1.</td>
      <td><b>Explanation:</b> Binary search on days from `min(bloomDay)` to `max(bloomDay)`. For a given `day`, count consecutive flowers that have bloomed. If count reaches `k`, increment bouquet count and reset flower count. If `bouquets >= m`, move `high = mid - 1`, else `low = mid + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool possible(vector&lt;int&gt;&amp; bloomDay, int day, int m, int k) {&#10;    int count = 0, noOfB = 0;&#10;    for(int i=0; i&lt;bloomDay.size(); i++) {&#10;        if(bloomDay[i] &lt;= day) {&#10;            count++;&#10;        } else {&#10;            noOfB += (count / k);&#10;            count = 0;&#10;        }&#10;    }&#10;    noOfB += (count / k);&#10;    return noOfB &gt;= m;&#10;}&#10;int minDays(vector&lt;int&gt;&amp; bloomDay, int m, int k) {&#10;    long long val = m * 1LL * k * 1LL;&#10;    if(val &gt; bloomDay.size()) return -1;&#10;    int mini = INT_MAX, maxi = INT_MIN;&#10;    for(int i=0; i&lt;bloomDay.size(); i++) {&#10;        mini = min(mini, bloomDay[i]);&#10;        maxi = max(maxi, bloomDay[i]);&#10;    }&#10;    int low = mini, high = maxi;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(possible(bloomDay, mid, m, k)) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Bs 26 Find The Smallest Divisor Given A Threshold<br><br></b> <a href='https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/' target='_blank'>LeetCode 1283</a></td>
      <td><b>Example 1:</b> Binary search divisor.</td>
      <td><b>Time:</b> O(N log(Max))<br><b>Space:</b> O(1)</td>
      <td><code>#include <cmath></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search for divisor from `1` to `max(nums)`. For a divisor `mid`, sum `ceil(num / mid)`. If sum <= threshold, move `high = mid - 1`, else `low = mid + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int sumByD(vector&lt;int&gt;&amp; nums, int d) {&#10;    int sum = 0;&#10;    for(int num : nums) {&#10;        sum += ceil((double)num / (double)d);&#10;    }&#10;    return sum;&#10;}&#10;int smallestDivisor(vector&lt;int&gt;&amp; nums, int threshold) {&#10;    int low = 1, high = *max_element(nums.begin(), nums.end());&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(sumByD(nums, mid) &lt;= threshold) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Bs 27 Capacity To Ship Packages Within D Days<br><br></b> <a href='https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/' target='_blank'>LeetCode 1011</a></td>
      <td><b>Example 1:</b> Binary search capacity.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search for capacity from `max(weights)` to `sum(weights)`. For a capacity `mid`, calculate days required to ship. If required days <= D, move `high = mid - 1`, else `low = mid + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDays(vector&lt;int&gt;&amp; weights, int cap) {&#10;    int days = 1, load = 0;&#10;    for(int i=0; i&lt;weights.size(); i++) {&#10;        if(load + weights[i] &gt; cap) {&#10;            days += 1;&#10;            load = weights[i];&#10;        } else {&#10;            load += weights[i];&#10;        }&#10;    }&#10;    return days;&#10;}&#10;int shipWithinDays(vector&lt;int&gt;&amp; weights, int days) {&#10;    int low = *max_element(weights.begin(), weights.end());&#10;    int high = accumulate(weights.begin(), weights.end(), 0);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(findDays(weights, mid) &lt;= days) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Bs 28 Kth Missing Positive Number<br><br></b> <a href='https://leetcode.com/problems/kth-missing-positive-number/' target='_blank'>LeetCode 1539</a></td>
      <td><b>Example 1:</b> Calculate missing.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search. At index `mid`, the number of missing elements before `arr[mid]` is `arr[mid] - (mid + 1)`. If this is < `k`, search right `low = mid + 1`. Else search left `high = mid - 1`. Ans is `high + 1 + k` or `low + k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthPositive(vector&lt;int&gt;&amp; arr, int k) {&#10;    int low = 0, high = arr.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int missing = arr[mid] - (mid + 1);&#10;        if(missing &lt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low + k;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Bs 29 Aggressive Cows<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/aggressive-cows/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Minimax binary search.</td>
      <td><b>Time:</b> O(N log N + N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the stalls. Binary search for distance from `1` to `max-min`. For a distance `mid`, check if we can place all `C` cows such that distance between any two is >= `mid`. If possible, move `low = mid + 1` to maximize it, else `high = mid - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canWePlace(vector&lt;int&gt;&amp; stalls, int dist, int cows) {&#10;    int n = stalls.size();&#10;    int cntCows = 1;&#10;    int last = stalls[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        if(stalls[i] - last &gt;= dist) {&#10;            cntCows++;&#10;            last = stalls[i];&#10;        }&#10;    }&#10;    return cntCows &gt;= cows;&#10;}&#10;int aggressiveCows(vector&lt;int&gt;&amp; stalls, int k) {&#10;    sort(stalls.begin(), stalls.end());&#10;    int n = stalls.size();&#10;    int low = 1, high = stalls[n-1] - stalls[0];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canWePlace(stalls, mid, k)) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Bs 30 Allocate Books<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Minimizing max pages.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Impossible:</b> If m > n, return -1.</td>
      <td><b>Explanation:</b> Binary search on max pages from `max(arr)` to `sum(arr)`. For a `mid` value, count how many students are needed. If `students > m`, we need to increase limit `low = mid + 1`. Else, `high = mid - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countStudents(int arr[], int n, int pages) {&#10;    int students = 1, pagesStudent = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(pagesStudent + arr[i] &lt;= pages) {&#10;            pagesStudent += arr[i];&#10;        } else {&#10;            students++;&#10;            pagesStudent = arr[i];&#10;        }&#10;    }&#10;    return students;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    int low = *max_element(A, A + N);&#10;    int high = accumulate(A, A + N, 0);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int students = countStudents(A, N, mid);&#10;        if(students &gt; M) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Bs 31 Split Array Largest Sum<br><br></b> <a href='https://leetcode.com/problems/split-array-largest-sum/' target='_blank'>LeetCode 410</a></td>
      <td><b>Example 1:</b> Equivalent to allocate books.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Identical logic to Allocate Books. Binary search from `max(nums)` to `sum(nums)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPartitions(vector&lt;int&gt;&amp; a, int maxSum) {&#10;    int n = a.size(), partitions = 1, subarraySum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(subarraySum + a[i] &lt;= maxSum) {&#10;            subarraySum += a[i];&#10;        } else {&#10;            partitions++;&#10;            subarraySum = a[i];&#10;        }&#10;    }&#10;    return partitions;&#10;}&#10;int splitArray(vector&lt;int&gt;&amp; nums, int k) {&#10;    int low = *max_element(nums.begin(), nums.end());&#10;    int high = accumulate(nums.begin(), nums.end(), 0);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int partitions = countPartitions(nums, mid);&#10;        if(partitions &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Bs 32 Painters Partition Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Minimax identical to book allocation.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Identical to Allocate Books and Split Array Largest Sum. Binary search `max(boards)` to `sum(boards)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPainters(vector&lt;int&gt;&amp; boards, int time) {&#10;    int painters = 1, boardsPainter = 0;&#10;    for(int i=0; i&lt;boards.size(); i++) {&#10;        if(boardsPainter + boards[i] &lt;= time) {&#10;            boardsPainter += boards[i];&#10;        } else {&#10;            painters++;&#10;            boardsPainter = boards[i];&#10;        }&#10;    }&#10;    return painters;&#10;}&#10;int findLargestMinDistance(vector&lt;int&gt; &amp;boards, int k) {&#10;    int low = *max_element(boards.begin(), boards.end());&#10;    long long high = accumulate(boards.begin(), boards.end(), 0LL);&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        int painters = countPainters(boards, mid);&#10;        if(painters &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Bs 33 Minimize Max Distance To Gas Station<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Double binary search.</td>
      <td><b>Time:</b> O(N log(MaxDist / 1e-6))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the real answer (distance) with a precision (e.g., 1e-6). For a given `mid` distance, count how many gas stations need to be inserted in each gap: `ceil((stations[i+1] - stations[i]) / mid) - 1`. If total needed > k, `low = mid`, else `high = mid`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfGasStationsRequired(double dist, vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size(), cnt = 0;&#10;    for(int i=1; i&lt;n; i++) {&#10;        int numberInBetween = ((arr[i] - arr[i-1]) / dist);&#10;        if((arr[i] - arr[i-1]) == (dist * numberInBetween)) {&#10;            numberInBetween--;&#10;        }&#10;        cnt += numberInBetween;&#10;    }&#10;    return cnt;&#10;}&#10;double findSmallestMaxDist(vector&lt;int&gt; &amp;stations, int k) {&#10;    int n = stations.size();&#10;    double low = 0;&#10;    double high = 0;&#10;    for(int i=0; i&lt;n-1; i++) high = max(high, (double)(stations[i+1] - stations[i]));&#10;    double diff = 1e-6;&#10;    while(high - low &gt; diff) {&#10;        double mid = low + (high - low) / (2.0);&#10;        int cnt = numberOfGasStationsRequired(mid, stations);&#10;        if(cnt &gt; k) low = mid;&#10;        else high = mid;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Bs 34 Median Of Two Sorted Arrays<br><br></b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a></td>
      <td><b>Example 1:</b> Input: nums1 = [1,3], nums2 = [2], Output: 2.0</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Odd/Even Length:</b> Handle average for even total length.</td>
      <td><b>Explanation:</b> Binary search on the smaller array to find a partition such that left halves of both arrays contain half of total elements, and `maxLeft <= minRight`. Use `INT_MIN` and `INT_MAX` for out-of-bound partitions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int n1 = nums1.size(), n2 = nums2.size();&#10;    int low = 0, high = n1;&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = (n1 + n2 + 1) / 2 - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];&#10;        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];&#10;        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) {&#10;            if((n1 + n2) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2.0;&#10;            else return max(left1, left2);&#10;        } else if(left1 &gt; right2) {&#10;            high = cut1 - 1;&#10;        } else {&#10;            low = cut1 + 1;&#10;        }&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Bs 35 Median Of Two Sorted Arrays<br><br></b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a></td>
      <td><b>Example 1:</b> Binary search on smaller array.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Ensure `nums1` is the smaller array. Partition both arrays such that the left half has `(n+m+1)/2` elements. Use binary search on `nums1` to find the correct partition where `max(left1) <= min(right2)` and `max(left2) <= min(right1)`. The median depends on whether total elements is odd or even.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int n = nums1.size(), m = nums2.size();&#10;    int low = 0, high = n;&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = (n + m + 1) / 2 - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];&#10;        int right1 = cut1 == n ? INT_MAX : nums1[cut1];&#10;        int right2 = cut2 == m ? INT_MAX : nums2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) {&#10;            if((n + m) % 2 == 0) return (max(left1, left2) + min(right1, right2)) / 2.0;&#10;            else return max(left1, left2);&#10;        } else if(left1 &gt; right2) {&#10;            high = cut1 - 1;&#10;        } else {&#10;            low = cut1 + 1;&#10;        }&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Bs 36 Kth Element Of Two Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Generalization of median.</td>
      <td><b>Time:</b> O(log(min(N, M, K)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to Median of 2 sorted arrays. Apply binary search on the smaller array. The partition requires `cut1 + cut2 = k`. Boundaries for `cut1` are `max(0, k - m)` and `min(k, n)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = k - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];&#10;        int right1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int right2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) {&#10;            return max(left1, left2);&#10;        } else if(left1 &gt; right2) {&#10;            high = cut1 - 1;&#10;        } else {&#10;            low = cut1 + 1;&#10;        }&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Bs 37 Search In A 2D Matrix Ii<br><br></b> <a href='https://leetcode.com/problems/search-a-2d-matrix-ii/' target='_blank'>LeetCode 240</a></td>
      <td><b>Example 1:</b> Start from top right.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start from the top-right corner. If `target == current`, return true. If `target < current`, move left (`c--`). If `target > current`, move down (`r++`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    int r = 0, c = matrix[0].size() - 1;&#10;    while(r &lt; matrix.size() &amp;&amp; c &gt;= 0) {&#10;        if(matrix[r][c] == target) return true;&#10;        else if(matrix[r][c] &gt; target) c--;&#10;        else r++;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Bs 38 Find A Peak Element Ii<br><br></b> <a href='https://leetcode.com/problems/find-a-peak-element-ii/' target='_blank'>LeetCode 1901</a></td>
      <td><b>Example 1:</b> Binary search on columns.</td>
      <td><b>Time:</b> O(N log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on columns. Find middle column, find max element in this column. Compare it with its left and right neighbors. If it's > both, it's a peak. If left is greater, peak exists in left half. Else, peak exists in right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxElemRow(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int col) {&#10;    int maxVal = -1, row = -1;&#10;    for(int i=0; i&lt;mat.size(); i++) {&#10;        if(mat[i][col] &gt; maxVal) {&#10;            maxVal = mat[i][col];&#10;            row = i;&#10;        }&#10;    }&#10;    return row;&#10;}&#10;vector&lt;int&gt; findPeakGrid(vector&lt;vector&lt;int&gt;&gt;&amp; mat) {&#10;    int n = mat.size(), m = mat[0].size();&#10;    int low = 0, high = m - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int row = maxElemRow(mat, mid);&#10;        int left = mid - 1 &gt;= 0 ? mat[row][mid-1] : -1;&#10;        int right = mid + 1 &lt; m ? mat[row][mid+1] : -1;&#10;        if(mat[row][mid] &gt; left &amp;&amp; mat[row][mid] &gt; right) return {row, mid};&#10;        else if(mat[row][mid] &lt; left) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return {-1, -1};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Bs 39 Matrix Median<br><br></b> <a href='https://www.interviewbit.com/problems/matrix-median/' target='_blank'>InterviewBit</a></td>
      <td><b>Example 1:</b> Binary search on answer range.</td>
      <td><b>Time:</b> O(32 * N log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the value range `[1, 10^9]`. For a candidate `mid`, count how many numbers are `<= mid` across all rows using `upper_bound`. If count `> (N*M)/2`, `mid` could be median, search lower. Else search higher.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSmallerThanMid(vector&lt;int&gt;&amp; row, int mid) {&#10;    int l = 0, h = row.size() - 1;&#10;    while(l &lt;= h) {&#10;        int md = (l + h) / 2;&#10;        if(row[md] &lt;= mid) l = md + 1;&#10;        else h = md - 1;&#10;    }&#10;    return l;&#10;}&#10;int findMedian(vector&lt;vector&lt;int&gt; &gt; &amp;A) {&#10;    int low = 1, high = 1e9;&#10;    int n = A.size(), m = A[0].size();&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int cnt = 0;&#10;        for(int i=0; i&lt;n; i++) {&#10;            cnt += countSmallerThanMid(A[i], mid);&#10;        }&#10;        if(cnt &lt;= (n * m) / 2) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Bs 40 Kth Smallest Number In Multiplication Table<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/' target='_blank'>LeetCode 668</a></td>
      <td><b>Example 1:</b> Binary Search on answer.</td>
      <td><b>Time:</b> O(m * log(m*n))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on range `[1, m*n]`. For a value `mid`, the number of elements `<= mid` in row `i` is `min(mid / i, n)`. Sum this for all rows to get total count. If count >= k, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthNumber(int m, int n, int k) {&#10;    int low = 1, high = m * n;&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        int count = 0;&#10;        for(int i=1; i&lt;=m; i++) {&#10;            count += min(mid / i, n);&#10;        }&#10;        if(count &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Bs 41 Find K Th Smallest Pair Distance<br><br></b> <a href='https://leetcode.com/problems/find-k-th-smallest-pair-distance/' target='_blank'>LeetCode 719</a></td>
      <td><b>Example 1:</b> Sort and binary search on distance.</td>
      <td><b>Time:</b> O(N log N + N log(max_dist))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Binary search on distance `[0, nums.back() - nums.front()]`. For a candidate `mid`, count pairs with distance `<= mid` using a sliding window. If count >= k, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPairs(vector&lt;int&gt;&amp; nums, int mid) {&#10;    int count = 0, l = 0;&#10;    for(int r = 0; r &lt; nums.size(); r++) {&#10;        while(nums[r] - nums[l] &gt; mid) l++;&#10;        count += (r - l);&#10;    }&#10;    return count;&#10;}&#10;int smallestDistancePair(vector&lt;int&gt;&amp; nums, int k) {&#10;    sort(nums.begin(), nums.end());&#10;    int low = 0, high = nums.back() - nums.front();&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countPairs(nums, mid) &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Bs 42 Split Array Largest Sum<br><br></b> <a href='https://leetcode.com/problems/split-array-largest-sum/' target='_blank'>LeetCode 410</a></td>
      <td><b>Example 1:</b> Binary search on answer.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search the max subarray sum `[max(nums), sum(nums)]`. For a `mid`, greedily split array. If subarrays needed `<= k`, `mid` is possible, search lower. Else search higher.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int splitArray(vector&lt;int&gt;&amp; nums, int k) {&#10;    int low = 0, high = 0;&#10;    for(int n : nums) {&#10;        low = max(low, n);&#10;        high += n;&#10;    }&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        int pieces = 1, currentSum = 0;&#10;        for(int n : nums) {&#10;            if(currentSum + n &gt; mid) {&#10;                currentSum = n;&#10;                pieces++;&#10;            } else {&#10;                currentSum += n;&#10;            }&#10;        }&#10;        if(pieces &lt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Bs 43 Minimum Number Of Days To Make M Bouquets<br><br></b> <a href='https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/' target='_blank'>LeetCode 1482</a></td>
      <td><b>Example 1:</b> Binary search on days.</td>
      <td><b>Time:</b> O(N log(max_day))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If `m * k > n`, return -1. Binary search on days `[min(bloomDay), max(bloomDay)]`. For a given day, count adjacent bloomed flowers. Every `k` consecutive bloomed flowers make 1 bouquet. If total bouquets >= m, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDays(vector&lt;int&gt;&amp; bloomDay, int m, int k) {&#10;    long long val = 1LL * m * k;&#10;    if(val &gt; bloomDay.size()) return -1;&#10;    int low = *min_element(bloomDay.begin(), bloomDay.end());&#10;    int high = *max_element(bloomDay.begin(), bloomDay.end());&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int bouquets = 0, count = 0;&#10;        for(int i=0; i&lt;bloomDay.size(); i++) {&#10;            if(bloomDay[i] &lt;= mid) {&#10;                count++;&#10;                if(count == k) {&#10;                    bouquets++;&#10;                    count = 0;&#10;                }&#10;            } else {&#10;                count = 0;&#10;            }&#10;        }&#10;        if(bouquets &gt;= m) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Bs 44 Capacity To Ship Packages Within D Days<br><br></b> <a href='https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/' target='_blank'>LeetCode 1011</a></td>
      <td><b>Example 1:</b> Same as split array.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on capacity `[max(weights), sum(weights)]`. For a `mid` capacity, greedily load packages. If a package makes sum > capacity, increment days and start new load. If `days <= D`, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int shipWithinDays(vector&lt;int&gt;&amp; weights, int days) {&#10;    int low = *max_element(weights.begin(), weights.end());&#10;    int high = 0;&#10;    for(int w : weights) high += w;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int d = 1, load = 0;&#10;        for(int w : weights) {&#10;            if(load + w &gt; mid) {&#10;                d++;&#10;                load = w;&#10;            } else {&#10;                load += w;&#10;            }&#10;        }&#10;        if(d &lt;= days) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Bs 41 Book Allocation Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Search space for max pages is `max(arr)` to `sum(arr)`. Use binary search. For a `mid` value, count how many students are needed. If `students > M`, we need to increase max pages (`low = mid + 1`), else we can try to decrease (`high = mid - 1`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int A[], int N, int M, long long mid) {&#10;    int students = 1;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        if(sum + A[i] &gt; mid) {&#10;            students++;&#10;            sum = A[i];&#10;            if(students &gt; M || A[i] &gt; mid) return false;&#10;        } else {&#10;            sum += A[i];&#10;        }&#10;    }&#10;    return true;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    long long sum = 0, mx = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        sum += A[i];&#10;        mx = max(mx, 1LL * A[i]);&#10;    }&#10;    long long low = mx, high = sum, ans = -1;&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        if(isPossible(A, N, M, mid)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Bs 42 Painters Partition Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to Book Allocation. Find if it's possible to paint all boards within `mid` time using at most `K` painters. Search space from `max(arr)` to `sum(arr)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int arr[], int n, int k, long long mid) {&#10;    int painters = 1;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(sum + arr[i] &gt; mid) {&#10;            painters++;&#10;            sum = arr[i];&#10;            if(painters &gt; k || arr[i] &gt; mid) return false;&#10;        } else {&#10;            sum += arr[i];&#10;        }&#10;    }&#10;    return true;&#10;}&#10;long long minTime(int arr[], int n, int k) {&#10;    long long low = 0, high = 0, ans = -1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        low = max(low, 1LL * arr[i]);&#10;        high += arr[i];&#10;    }&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        if(isPossible(arr, n, k, mid)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Bs 43 Aggressive Cows<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/aggressive-cows/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(N log N + N log(max_val))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Maximize the minimum distance. Search space from `1` to `max(arr) - min(arr)`. Function `isPossible(mid)` checks if we can place `K` cows such that distance between any two is at least `mid`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int stalls[], int n, int k, int mid) {&#10;    int cows = 1, lastPos = stalls[0];&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(stalls[i] - lastPos &gt;= mid) {&#10;            cows++;&#10;            lastPos = stalls[i];&#10;            if(cows == k) return true;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;int solve(int n, int k, vector&lt;int&gt;&amp; stalls) {&#10;    sort(stalls.begin(), stalls.end());&#10;    int low = 1, high = stalls[n-1] - stalls[0], ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(&amp;stalls[0], n, k, mid)) {&#10;            ans = mid;&#10;            low = mid + 1;&#10;        } else {&#10;            high = mid - 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Bs 44 Roti Prata Spoj<br><br></b> <a href='https://www.spoj.com/problems/PRATA/' target='_blank'>SPOJ</a></td>
      <td><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(L * log(max_time))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Search space is `0` to `max_time`, where `max_time` is the time taken by the fastest cook to make all `P` pratas alone. `isPossible(mid)` checks if the total pratas made by all cooks in `mid` time is at least `P`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(vector&lt;int&gt;&amp; rank, int p, int mid) {&#10;    int count = 0;&#10;    for(int r : rank) {&#10;        int time = 0, j = 1;&#10;        while(time + r * j &lt;= mid) {&#10;            count++;&#10;            time += r * j;&#10;            j++;&#10;        }&#10;        if(count &gt;= p) return true;&#10;    }&#10;    return count &gt;= p;&#10;}&#10;int minTime(int p, vector&lt;int&gt;&amp; rank) {&#10;    int low = 0, high = 1e8, ans = -1; // high could be rank[0] * P * (P+1) / 2&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(rank, p, mid)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Bs 45 Double Helix Spoj<br><br></b> <a href='https://www.spoj.com/problems/ANARC05B/' target='_blank'>SPOJ</a></td>
      <td><b>Example 1:</b> Two Pointers / Binary Search.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers to traverse both sorted arrays simultaneously. Accumulate sums `sum1` and `sum2`. When elements match (intersection), add `max(sum1, sum2) + element` to the total answer and reset `sum1` and `sum2`. After the loop, add the remaining max sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxPathSum(vector&lt;int&gt;&amp; arr1, vector&lt;int&gt;&amp; arr2) {&#10;    long long sum1 = 0, sum2 = 0, ans = 0;&#10;    int i = 0, j = 0, n = arr1.size(), m = arr2.size();&#10;    while(i &lt; n &amp;&amp; j &lt; m) {&#10;        if(arr1[i] &lt; arr2[j]) sum1 += arr1[i++];&#10;        else if(arr1[i] &gt; arr2[j]) sum2 += arr2[j++];&#10;        else {&#10;            ans += max(sum1, sum2) + arr1[i];&#10;            sum1 = 0; sum2 = 0;&#10;            i++; j++;&#10;        }&#10;    }&#10;    while(i &lt; n) sum1 += arr1[i++];&#10;    while(j &lt; m) sum2 += arr2[j++];&#10;    ans += max(sum1, sum2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Bs 46 Subset Sums Spoj<br><br></b> <a href='https://www.spoj.com/problems/SUBSUMS/' target='_blank'>SPOJ</a></td>
      <td><b>Example 1:</b> Meet in the Middle.</td>
      <td><b>Time:</b> O(2^(N/2) * log(2^(N/2)))<br><b>Space:</b> O(2^(N/2))</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Divide the array into two halves. Find all possible subset sums for both halves (`sum1` and `sum2`). Sort `sum2`. For each sum in `sum1`, we need to find the number of elements in `sum2` that satisfy `A - sum <= x <= B - sum`. This can be done using Binary Search (`upper_bound` - `lower_bound`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void getSubsetSums(vector&lt;int&gt;&amp; arr, int st, int end, long long sum, vector&lt;long long&gt;&amp; res) {&#10;    if(st &gt; end) {&#10;        res.push_back(sum);&#10;        return;&#10;    }&#10;    getSubsetSums(arr, st + 1, end, sum + arr[st], res);&#10;    getSubsetSums(arr, st + 1, end, sum, res);&#10;}&#10;long long solve(vector&lt;int&gt;&amp; arr, long long A, long long B) {&#10;    int n = arr.size();&#10;    vector&lt;long long&gt; left, right;&#10;    getSubsetSums(arr, 0, n / 2 - 1, 0, left);&#10;    getSubsetSums(arr, n / 2, n - 1, 0, right);&#10;    sort(right.begin(), right.end());&#10;    long long count = 0;&#10;    for(long long x : left) {&#10;        auto low = lower_bound(right.begin(), right.end(), A - x);&#10;        auto high = upper_bound(right.begin(), right.end(), B - x);&#10;        count += (high - low);&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Bs 47 Inversion Count<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Merge Sort.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Modify Merge Sort. While merging two sorted halves, if `left[i] > right[j]`, then there are `mid - i + 1` inversions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], long long temp[], int left, int mid, int right) {&#10;    long long inv_count = 0;&#10;    int i = left, j = mid, k = left;&#10;    while(i &lt;= mid - 1 &amp;&amp; j &lt;= right) {&#10;        if(arr[i] &lt;= arr[j]) temp[k++] = arr[i++];&#10;        else {&#10;            temp[k++] = arr[j++];&#10;            inv_count = inv_count + (mid - i);&#10;        }&#10;    }&#10;    while(i &lt;= mid - 1) temp[k++] = arr[i++];&#10;    while(j &lt;= right) temp[k++] = arr[j++];&#10;    for(i = left; i &lt;= right; i++) arr[i] = temp[i];&#10;    return inv_count;&#10;}&#10;long long mergeSort(long long arr[], long long temp[], int left, int right) {&#10;    long long inv_count = 0;&#10;    if(right &gt; left) {&#10;        int mid = (right + left) / 2;&#10;        inv_count += mergeSort(arr, temp, left, mid);&#10;        inv_count += mergeSort(arr, temp, mid + 1, right);&#10;        inv_count += merge(arr, temp, left, mid + 1, right);&#10;    }&#10;    return inv_count;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    long long temp[N];&#10;    return mergeSort(arr, temp, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Bs 48 Allocate Minimum Number Of Pages<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Search space for max pages is `max(arr)` to `sum(arr)`. Use binary search. For a `mid` value, count how many students are needed. If `students > M`, we need to increase max pages (`low = mid + 1`), else we can try to decrease (`high = mid - 1`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int A[], int N, int M, long long mid) {&#10;    int students = 1;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        if(sum + A[i] &gt; mid) {&#10;            students++;&#10;            sum = A[i];&#10;            if(students &gt; M || A[i] &gt; mid) return false;&#10;        } else {&#10;            sum += A[i];&#10;        }&#10;    }&#10;    return true;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    long long sum = 0, mx = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        sum += A[i];&#10;        mx = max(mx, 1LL * A[i]);&#10;    }&#10;    long long low = mx, high = sum, ans = -1;&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        if(isPossible(A, N, M, mid)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>49</td>
      <td>Bs 49 Smallest Factorial Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log_5(N) * log(5*N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Trailing zeros depend on number of 5s. Find count of 5s in `mid!`. Use binary search on the number. Low = 0, high = 5*N. If `check(mid) >= n`, `ans = mid` and `high = mid - 1`. Else `low = mid + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool check(int p, int n) {&#10;    int count = 0, temp = p, f = 5;&#10;    while(f &lt;= temp) {&#10;        count += temp / f;&#10;        f *= 5;&#10;    }&#10;    return count &gt;= n;&#10;}&#10;int findNum(int n) {&#10;    if(n == 1) return 5;&#10;    int low = 0, high = 5 * n;&#10;    int ans = 0;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(check(mid, n)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>50</td>
      <td>Bs 50 K Th Element Of Two Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Ensure arr1 is smaller. Binary search on arr1. `cut1` is between `max(0, k-m)` and `min(k, n)`. `cut2 = k - cut1`. Compare `l1 <= r2` and `l2 <= r1`. If so, return `max(l1, l2)`. Else adjust `low` and `high`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = k - cut1;&#10;        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];&#10;        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];&#10;        int r1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int r2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(l1 &lt;= r2 &amp;&amp; l2 &lt;= r1) return max(l1, l2);&#10;        else if(l1 &gt; r2) high = cut1 - 1;&#10;        else low = cut1 + 1;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
