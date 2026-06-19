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
      <td>Bs 09 Search In Rotated Sorted Array<br><br></b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array/' target='_blank'>LeetCode 33</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Find which half is sorted. If left half is sorted, check if target lies in it. If yes, search left, else search right. If right half is sorted, check if target lies in it. If yes, search right, else search left.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(target &gt;= nums[low] &amp;&amp; target &lt; nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else {&#10;            if(target &gt; nums[mid] &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Bs 14 Find Missing And Repeating<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Math or XOR.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use the array elements as indices. For each element `abs(Arr[i])`, negate the value at index `abs(Arr[i]) - 1`. If the value is already negative, it's the repeating element. After the loop, the index with a positive value corresponds to the missing element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findTwoElement(vector&lt;int&gt; arr, int n) {&#10;    vector&lt;int&gt; ans(2);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int val = abs(arr[i]);&#10;        if(arr[val - 1] &lt; 0) ans[0] = val;&#10;        else arr[val - 1] = -arr[val - 1];&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(arr[i] &gt; 0) {&#10;            ans[1] = i + 1;&#10;            break;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Bs 15 Majority Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Moore's Voting Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Moore's Voting Algorithm to find a candidate for majority element. Then count the occurrences of the candidate in the array to verify if it appears more than N/2 times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(int a[], int size) {&#10;    int count = 0, candidate = -1;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(count == 0) {&#10;            candidate = a[i];&#10;            count = 1;&#10;        } else if(a[i] == candidate) count++;&#10;        else count--;&#10;    }&#10;    count = 0;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(a[i] == candidate) count++;&#10;    }&#10;    if(count &gt; size / 2) return candidate;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Bs 18 Find Four Elements That Sum To A Given Value<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two loops and two pointers.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Use two nested loops for the first two elements. Then use two pointers for the remaining two elements to find the target sum. Skip duplicates at all levels.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt; &amp;arr, int k) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = arr.size();&#10;    sort(arr.begin(), arr.end());&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; arr[i] == arr[i-1]) continue;&#10;        for(int j = i + 1; j &lt; n; j++) {&#10;            if(j &gt; i + 1 &amp;&amp; arr[j] == arr[j-1]) continue;&#10;            int left = j + 1, right = n - 1;&#10;            while(left &lt; right) {&#10;                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];&#10;                if(sum == k) {&#10;                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});&#10;                    left++; right--;&#10;                    while(left &lt; right &amp;&amp; arr[left] == arr[left-1]) left++;&#10;                    while(left &lt; right &amp;&amp; arr[right] == arr[right+1]) right--;&#10;                } else if(sum &lt; k) left++;&#10;                else right--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Bs 19 Median Of Two Sorted Arrays<br><br></b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a></td>
      <td><b>Example 1:</b> Binary Search on smaller array.</td>
      <td><b>Time:</b> O(log(min(M, N)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Ensure `nums1` is the smaller array. Do binary search on `nums1` to find a partition such that the left half has `(m+n+1)/2` elements. Calculate the maximums of left halves and minimums of right halves. If `maxLeft1 <= minRight2` and `maxLeft2 <= minRight1`, the partition is correct. The median depends on whether `m+n` is even or odd.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums2.size() &lt; nums1.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int n1 = nums1.size(), n2 = nums2.size();&#10;    int low = 0, high = n1;&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) &gt;&gt; 1;&#10;        int cut2 = (n1 + n2 + 1) / 2 - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];&#10;        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];&#10;        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];&#10;        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) {&#10;            if((n1 + n2) % 2 == 0)&#10;                return (max(left1, left2) + min(right1, right2)) / 2.0;&#10;            else&#10;                return max(left1, left2);&#10;        } else if(left1 &gt; right2) {&#10;            high = cut1 - 1;&#10;        } else {&#10;            low = cut1 + 1;&#10;        }&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Bs 20 Kth Element Of Two Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search on smaller array.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to median of two sorted arrays. Do binary search on the smaller array for a partition such that the total number of elements on the left side is `k`. Ensure `cut1` is between `max(0, k-m)` and `min(k, n)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) &gt;&gt; 1;&#10;        int cut2 = k - cut1;&#10;        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];&#10;        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];&#10;        int r1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int r2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(l1 &lt;= r2 &amp;&amp; l2 &lt;= r1) {&#10;            return max(l1, l2);&#10;        } else if(l1 &gt; r2) {&#10;            high = cut1 - 1;&#10;        } else {&#10;            low = cut1 + 1;&#10;        }&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Bs 21 Find Nth Root Of M<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(N * log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Search space is `[1, m]`. Check `mid^n`. Since `mid^n` can overflow, use a custom power function that returns 1 if `mid^n == m`, 0 if `< m`, and 2 if `> m`. Adjust `low` and `high` accordingly.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int func(int mid, int n, int m) {&#10;    long long ans = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        ans *= mid;&#10;        if(ans &gt; m) return 2;&#10;    }&#10;    if(ans == m) return 1;&#10;    return 0;&#10;}&#10;int NthRoot(int n, int m) {&#10;    int low = 1, high = m;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int midN = func(mid, n, m);&#10;        if(midN == 1) return mid;&#10;        else if(midN == 0) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
