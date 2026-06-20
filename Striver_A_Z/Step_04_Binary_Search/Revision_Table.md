# Step 04 Binary Search Revision Table

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
      <td>Bs 08 Allocate Minimum Number Of Pages<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N=4, A=[12,34,67,90], M=2, Output: 113</td>
      <td><b>Time:</b> O(N * log(sum(A) - max(A)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>M > N:</b> Impossible to allocate at least one book to each student, return -1.</td>
      <td><b>Explanation:</b> Binary Search on Answer. The search space for pages is from `max(A)` to `sum(A)`. For a given `mid`, check if books can be allocated to `<= M` students without any student exceeding `mid` pages.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int A[], int N, int M, int maxPages) {&#10;    int students = 1, currentPages = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        if(A[i] &gt; maxPages) return false;&#10;        if(currentPages + A[i] &gt; maxPages) {&#10;            students++; currentPages = A[i];&#10;        } else {&#10;            currentPages += A[i];&#10;        }&#10;    }&#10;    return students &lt;= M;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    int low = 0, high = 0, ans = -1;&#10;    for(int i=0; i&lt;N; i++) { low = max(low, A[i]); high += A[i]; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(A, N, M, mid)) {&#10;            ans = mid; high = mid - 1;&#10;        } else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Bs 09 Kth Element Of Two Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 5, Output: 6</td>
      <td><b>Time:</b> O(log(min(n, m)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the smaller array. Similar to Median of two sorted arrays, but the left partition size is strictly `k`. Search space for `cut1` is `[max(0, k-m), min(k, n)]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = k - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];&#10;        int right1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int right2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) return max(left1, left2);&#10;        else if(left1 &gt; right2) high = cut1 - 1;&#10;        else low = cut1 + 1;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Bs 10 Search In Rotated Sorted Array Ii<br><br></b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array-ii/' target='_blank'>LeetCode 81</a></td>
      <td><b>Example 1:</b> Input: nums = [2,5,6,0,0,1,2], target = 0, Output: true</td>
      <td><b>Time:</b> O(log N) average, O(N) worst case<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Duplicates causing ambiguity:</b> Shrink bounds safely.</td>
      <td><b>Explanation:</b> If `nums[low] == nums[mid] == nums[high]`, shrink the search space by `low++` and `high--`. Otherwise, proceed with the standard rotated binary search.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool search(vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(nums[mid] == target) return true;&#10;        if(nums[low] == nums[mid] &amp;&amp; nums[mid] == nums[high]) {&#10;            low++; high--; continue;&#10;        }&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Bs 11 Minimum Days To Make M Bouquets<br><br></b> <a href='https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/' target='_blank'>LeetCode 1482</a></td>
      <td><b>Example 1:</b> Find day threshold.</td>
      <td><b>Time:</b> O(N log(maxD - minD))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on days from `min(bloom)` to `max(bloom)`. Count consecutive bloomed flowers, if it reaches `k`, form a bouquet. Return minimum valid day.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(vector&lt;int&gt;&amp; bloomDay, int m, int k, int day) {&#10;    int count = 0, bouquets = 0;&#10;    for(int d : bloomDay) {&#10;        if(d &lt;= day) count++;&#10;        else {&#10;            bouquets += count / k;&#10;            count = 0;&#10;        }&#10;    }&#10;    bouquets += count / k;&#10;    return bouquets &gt;= m;&#10;}&#10;int minDays(vector&lt;int&gt;&amp; bloomDay, int m, int k) {&#10;    if((long long)m * k &gt; bloomDay.size()) return -1;&#10;    int low = 1e9, high = 0;&#10;    for(int d : bloomDay) { low = min(low, d); high = max(high, d); }&#10;    int ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(bloomDay, m, k, mid)) { ans = mid; high = mid - 1; }&#10;        else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Bs 12 Find The Smallest Divisor Given A Threshold<br><br></b> <a href='https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/' target='_blank'>LeetCode 1283</a></td>
      <td><b>Example 1:</b> Summing ceils.</td>
      <td><b>Time:</b> O(N log(max(nums)))<br><b>Space:</b> O(1)</td>
      <td><code>#include <math.h></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search the divisor from 1 to `max(nums)`. Compute `sum(ceil(num / mid))`. If sum <= threshold, shrink high.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int smallestDivisor(vector&lt;int&gt;&amp; nums, int threshold) {&#10;    int low = 1, high = *max_element(nums.begin(), nums.end());&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        long long sum = 0;&#10;        for(int num : nums) sum += ceil((double)num / mid);&#10;        if(sum &lt;= threshold) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Bs 13 Capacity To Ship Packages Within D Days<br><br></b> <a href='https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/' target='_blank'>LeetCode 1011</a></td>
      <td><b>Example 1:</b> Find ship capacity.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on capacity. Low = `max(weights)`, High = `sum(weights)`. Iterate through packages and accumulate weight, increment day if limit is exceeded.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canShip(vector&lt;int&gt;&amp; weights, int days, int cap) {&#10;    int d = 1, load = 0;&#10;    for(int w : weights) {&#10;        if(load + w &gt; cap) { d++; load = w; }&#10;        else load += w;&#10;    }&#10;    return d &lt;= days;&#10;}&#10;int shipWithinDays(vector&lt;int&gt;&amp; weights, int days) {&#10;    int low = 0, high = 0;&#10;    for(int w : weights) { low = max(low, w); high += w; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canShip(weights, days, mid)) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Bs 14 Kth Missing Positive Number<br><br></b> <a href='https://leetcode.com/problems/kth-missing-positive-number/' target='_blank'>LeetCode 1539</a></td>
      <td><b>Example 1:</b> Calculate missing.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search. At index `mid`, the number of missing elements before `arr[mid]` is `arr[mid] - (mid + 1)`. If this is < `k`, search right `low = mid + 1`. Else search left `high = mid - 1`. Ans is `high + 1 + k` or `low + k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthPositive(vector&lt;int&gt;&amp; arr, int k) {&#10;    int low = 0, high = arr.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int missing = arr[mid] - (mid + 1);&#10;        if(missing &lt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low + k;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Bs 15 Aggressive Cows<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/aggressive-cows/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Minimax binary search.</td>
      <td><b>Time:</b> O(N log N + N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the stalls. Binary search for distance from `1` to `max-min`. For a distance `mid`, check if we can place all `C` cows such that distance between any two is >= `mid`. If possible, move `low = mid + 1` to maximize it, else `high = mid - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canWePlace(vector&lt;int&gt;&amp; stalls, int dist, int cows) {&#10;    int n = stalls.size();&#10;    int cntCows = 1;&#10;    int last = stalls[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        if(stalls[i] - last &gt;= dist) {&#10;            cntCows++;&#10;            last = stalls[i];&#10;        }&#10;    }&#10;    return cntCows &gt;= cows;&#10;}&#10;int aggressiveCows(vector&lt;int&gt;&amp; stalls, int k) {&#10;    sort(stalls.begin(), stalls.end());&#10;    int n = stalls.size();&#10;    int low = 1, high = stalls[n-1] - stalls[0];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canWePlace(stalls, mid, k)) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Bs 16 Split Array Largest Sum<br><br></b> <a href='https://leetcode.com/problems/split-array-largest-sum/' target='_blank'>LeetCode 410</a></td>
      <td><b>Example 1:</b> Equivalent to allocate books.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Identical logic to Allocate Books. Binary search from `max(nums)` to `sum(nums)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPartitions(vector&lt;int&gt;&amp; a, int maxSum) {&#10;    int n = a.size(), partitions = 1, subarraySum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(subarraySum + a[i] &lt;= maxSum) {&#10;            subarraySum += a[i];&#10;        } else {&#10;            partitions++;&#10;            subarraySum = a[i];&#10;        }&#10;    }&#10;    return partitions;&#10;}&#10;int splitArray(vector&lt;int&gt;&amp; nums, int k) {&#10;    int low = *max_element(nums.begin(), nums.end());&#10;    int high = accumulate(nums.begin(), nums.end(), 0);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int partitions = countPartitions(nums, mid);&#10;        if(partitions &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Bs 17 Painters Partition Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Minimax identical to book allocation.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Identical to Allocate Books and Split Array Largest Sum. Binary search `max(boards)` to `sum(boards)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPainters(vector&lt;int&gt;&amp; boards, int time) {&#10;    int painters = 1, boardsPainter = 0;&#10;    for(int i=0; i&lt;boards.size(); i++) {&#10;        if(boardsPainter + boards[i] &lt;= time) {&#10;            boardsPainter += boards[i];&#10;        } else {&#10;            painters++;&#10;            boardsPainter = boards[i];&#10;        }&#10;    }&#10;    return painters;&#10;}&#10;int findLargestMinDistance(vector&lt;int&gt; &amp;boards, int k) {&#10;    int low = *max_element(boards.begin(), boards.end());&#10;    long long high = accumulate(boards.begin(), boards.end(), 0LL);&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        int painters = countPainters(boards, mid);&#10;        if(painters &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Bs 18 Minimize Max Distance To Gas Station<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Double binary search.</td>
      <td><b>Time:</b> O(N log(MaxDist / 1e-6))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the real answer (distance) with a precision (e.g., 1e-6). For a given `mid` distance, count how many gas stations need to be inserted in each gap: `ceil((stations[i+1] - stations[i]) / mid) - 1`. If total needed > k, `low = mid`, else `high = mid`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfGasStationsRequired(double dist, vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size(), cnt = 0;&#10;    for(int i=1; i&lt;n; i++) {&#10;        int numberInBetween = ((arr[i] - arr[i-1]) / dist);&#10;        if((arr[i] - arr[i-1]) == (dist * numberInBetween)) {&#10;            numberInBetween--;&#10;        }&#10;        cnt += numberInBetween;&#10;    }&#10;    return cnt;&#10;}&#10;double findSmallestMaxDist(vector&lt;int&gt; &amp;stations, int k) {&#10;    int n = stations.size();&#10;    double low = 0;&#10;    double high = 0;&#10;    for(int i=0; i&lt;n-1; i++) high = max(high, (double)(stations[i+1] - stations[i]));&#10;    double diff = 1e-6;&#10;    while(high - low &gt; diff) {&#10;        double mid = low + (high - low) / (2.0);&#10;        int cnt = numberOfGasStationsRequired(mid, stations);&#10;        if(cnt &gt; k) low = mid;&#10;        else high = mid;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Bs 19 Search In A 2D Matrix Ii<br><br></b> <a href='https://leetcode.com/problems/search-a-2d-matrix-ii/' target='_blank'>LeetCode 240</a></td>
      <td><b>Example 1:</b> Start from top right.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start from the top-right corner. If `target == current`, return true. If `target < current`, move left (`c--`). If `target > current`, move down (`r++`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    int r = 0, c = matrix[0].size() - 1;&#10;    while(r &lt; matrix.size() &amp;&amp; c &gt;= 0) {&#10;        if(matrix[r][c] == target) return true;&#10;        else if(matrix[r][c] &gt; target) c--;&#10;        else r++;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Bs 20 Find A Peak Element Ii<br><br></b> <a href='https://leetcode.com/problems/find-a-peak-element-ii/' target='_blank'>LeetCode 1901</a></td>
      <td><b>Example 1:</b> Binary search on columns.</td>
      <td><b>Time:</b> O(N log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on columns. Find middle column, find max element in this column. Compare it with its left and right neighbors. If it's > both, it's a peak. If left is greater, peak exists in left half. Else, peak exists in right half.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxElemRow(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int col) {&#10;    int maxVal = -1, row = -1;&#10;    for(int i=0; i&lt;mat.size(); i++) {&#10;        if(mat[i][col] &gt; maxVal) {&#10;            maxVal = mat[i][col];&#10;            row = i;&#10;        }&#10;    }&#10;    return row;&#10;}&#10;vector&lt;int&gt; findPeakGrid(vector&lt;vector&lt;int&gt;&gt;&amp; mat) {&#10;    int n = mat.size(), m = mat[0].size();&#10;    int low = 0, high = m - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int row = maxElemRow(mat, mid);&#10;        int left = mid - 1 &gt;= 0 ? mat[row][mid-1] : -1;&#10;        int right = mid + 1 &lt; m ? mat[row][mid+1] : -1;&#10;        if(mat[row][mid] &gt; left &amp;&amp; mat[row][mid] &gt; right) return {row, mid};&#10;        else if(mat[row][mid] &lt; left) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return {-1, -1};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Bs 21 Matrix Median<br><br></b> <a href='https://www.interviewbit.com/problems/matrix-median/' target='_blank'>InterviewBit</a></td>
      <td><b>Example 1:</b> Binary search on answer range.</td>
      <td><b>Time:</b> O(32 * N log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the value range `[1, 10^9]`. For a candidate `mid`, count how many numbers are `<= mid` across all rows using `upper_bound`. If count `> (N*M)/2`, `mid` could be median, search lower. Else search higher.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSmallerThanMid(vector&lt;int&gt;&amp; row, int mid) {&#10;    int l = 0, h = row.size() - 1;&#10;    while(l &lt;= h) {&#10;        int md = (l + h) / 2;&#10;        if(row[md] &lt;= mid) l = md + 1;&#10;        else h = md - 1;&#10;    }&#10;    return l;&#10;}&#10;int findMedian(vector&lt;vector&lt;int&gt; &gt; &amp;A) {&#10;    int low = 1, high = 1e9;&#10;    int n = A.size(), m = A[0].size();&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int cnt = 0;&#10;        for(int i=0; i&lt;n; i++) {&#10;            cnt += countSmallerThanMid(A[i], mid);&#10;        }&#10;        if(cnt &lt;= (n * m) / 2) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Bs 22 Kth Smallest Number In Multiplication Table<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/' target='_blank'>LeetCode 668</a></td>
      <td><b>Example 1:</b> Binary Search on answer.</td>
      <td><b>Time:</b> O(m * log(m*n))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on range `[1, m*n]`. For a value `mid`, the number of elements `<= mid` in row `i` is `min(mid / i, n)`. Sum this for all rows to get total count. If count >= k, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthNumber(int m, int n, int k) {&#10;    int low = 1, high = m * n;&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        int count = 0;&#10;        for(int i=1; i&lt;=m; i++) {&#10;            count += min(mid / i, n);&#10;        }&#10;        if(count &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Bs 23 Find K Th Smallest Pair Distance<br><br></b> <a href='https://leetcode.com/problems/find-k-th-smallest-pair-distance/' target='_blank'>LeetCode 719</a></td>
      <td><b>Example 1:</b> Sort and binary search on distance.</td>
      <td><b>Time:</b> O(N log N + N log(max_dist))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort array. Binary search on distance `[0, nums.back() - nums.front()]`. For a candidate `mid`, count pairs with distance `<= mid` using a sliding window. If count >= k, search left. Else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPairs(vector&lt;int&gt;&amp; nums, int mid) {&#10;    int count = 0, l = 0;&#10;    for(int r = 0; r &lt; nums.size(); r++) {&#10;        while(nums[r] - nums[l] &gt; mid) l++;&#10;        count += (r - l);&#10;    }&#10;    return count;&#10;}&#10;int smallestDistancePair(vector&lt;int&gt;&amp; nums, int k) {&#10;    sort(nums.begin(), nums.end());&#10;    int low = 0, high = nums.back() - nums.front();&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countPairs(nums, mid) &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Bs 24 Majority Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Moore's Voting Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Moore's Voting Algorithm to find a candidate for majority element. Then count the occurrences of the candidate in the array to verify if it appears more than N/2 times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(int a[], int size) {&#10;    int count = 0, candidate = -1;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(count == 0) {&#10;            candidate = a[i];&#10;            count = 1;&#10;        } else if(a[i] == candidate) count++;&#10;        else count--;&#10;    }&#10;    count = 0;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(a[i] == candidate) count++;&#10;    }&#10;    if(count &gt; size / 2) return candidate;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Bs 25 Find Four Elements That Sum To A Given Value<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two loops and two pointers.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Use two nested loops for the first two elements. Then use two pointers for the remaining two elements to find the target sum. Skip duplicates at all levels.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt; &amp;arr, int k) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = arr.size();&#10;    sort(arr.begin(), arr.end());&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; arr[i] == arr[i-1]) continue;&#10;        for(int j = i + 1; j &lt; n; j++) {&#10;            if(j &gt; i + 1 &amp;&amp; arr[j] == arr[j-1]) continue;&#10;            int left = j + 1, right = n - 1;&#10;            while(left &lt; right) {&#10;                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];&#10;                if(sum == k) {&#10;                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});&#10;                    left++; right--;&#10;                    while(left &lt; right &amp;&amp; arr[left] == arr[left-1]) left++;&#10;                    while(left &lt; right &amp;&amp; arr[right] == arr[right+1]) right--;&#10;                } else if(sum &lt; k) left++;&#10;                else right--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Bs 26 Find Nth Root Of M<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(N * log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Search space is `[1, m]`. Check `mid^n`. Since `mid^n` can overflow, use a custom power function that returns 1 if `mid^n == m`, 0 if `< m`, and 2 if `> m`. Adjust `low` and `high` accordingly.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int func(int mid, int n, int m) {&#10;    long long ans = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        ans *= mid;&#10;        if(ans &gt; m) return 2;&#10;    }&#10;    if(ans == m) return 1;&#10;    return 0;&#10;}&#10;int NthRoot(int n, int m) {&#10;    int low = 1, high = m;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int midN = func(mid, n, m);&#10;        if(midN == 1) return mid;&#10;        else if(midN == 0) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Bs 27 Row With Max 1S<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Lower Bound per row.</td>
      <td><b>Time:</b> O(N log M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Since rows are sorted, use binary search (`lower_bound` of 1) to find the first index of 1 in each row. The number of 1s is `m - index`. Keep track of the row with the maximum 1s.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lowerBound(vector&lt;int&gt; arr, int n, int x) {&#10;    int low = 0, high = n - 1, ans = n;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(arr[mid] &gt;= x) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}&#10;int rowWithMax1s(vector&lt;vector&lt;int&gt;&gt; arr, int n, int m) {&#10;    int max_cnt = 0, index = -1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int cnt_ones = m - lowerBound(arr[i], m, 1);&#10;        if(cnt_ones &gt; max_cnt) {&#10;            max_cnt = cnt_ones;&#10;            index = i;&#10;        }&#10;    }&#10;    return index;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
