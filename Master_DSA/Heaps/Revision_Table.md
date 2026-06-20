# Heaps Revision Table

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
      <td>Heap 01 Kth Largest Element In An Array<br><br></b> <a href="https://leetcode.com/problems/kth-largest-element-in-an-array/" target="_blank">LeetCode 215</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: nums = [3,2,1,5,6,4], k = 2, Output: 5<br><br>**Note (Constraint):** Can you solve it without sorting?</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td><b>Explanation:</b> Use a Min-Heap of size K. When the heap exceeds size K, pop the minimum element. The top of the heap will be the Kth largest.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::priority_queue&lt;int, std::vector&lt;int&gt;, std::greater&lt;int&gt;&gt; minHeap;&#10;    for(int num : nums) {&#10;        minHeap.push(num);&#10;        if(minHeap.size() &gt; k) {&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    return minHeap.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Heap 02 Merge K Sorted Lists<br><br></b> <a href="https://leetcode.com/problems/merge-k-sorted-lists/" target="_blank">LeetCode 23</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Apna College, Striver A Z</details></td>
      <td>**Example 1:** Input: lists = [[1,4,5],[1,3,4],[2,6]], Output: [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td><b>Explanation:</b> Push the head of each list into a Min-Heap. Repeatedly pop the smallest node, attach it to the result list, and push its `next` node into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Compare {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;&#10;ListNode* mergeKLists(std::vector&lt;ListNode*&gt;&amp; lists) {&#10;    std::priority_queue&lt;ListNode*, std::vector&lt;ListNode*&gt;, Compare&gt; pq;&#10;    for (auto list : lists) {&#10;        if (list) pq.push(list);&#10;    }&#10;    &#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    &#10;    while (!pq.empty()) {&#10;        ListNode* node = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = node;&#10;        tail = tail-&gt;next;&#10;        if (node-&gt;next) pq.push(node-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Heap 03 Top K Frequent Elements<br><br></b> <a href="https://leetcode.com/problems/top-k-frequent-elements/" target="_blank">LeetCode 347</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Input: nums = [1,1,1,2,2,3], k = 2, Output: [1,2]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a Hash Map to count frequencies. Use a Min-Heap of size `k` to keep track of the top `k` elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; topKFrequent(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    std::priority_queue&lt;std::pair&lt;int, int&gt;, std::vector&lt;std::pair&lt;int, int&gt;&gt;, std::greater&lt;std::pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto it : mpp) {&#10;        pq.push({it.second, it.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Heap 04 Kth Smallest Element In A Sorted Matrix<br><br></b> <a href="https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/" target="_blank">LeetCode 378</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Binary search on range.</td>
      <td><b>Time:</b> O(N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Binary search on the value range `[matrix[0][0], matrix[n-1][n-1]]`. Count elements less than or equal to `mid` using two pointers (start from bottom-left). If count >= k, search left half, else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countLessOrEqual(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int mid, int n) {&#10;    int count = 0, row = n - 1, col = 0;&#10;    while(row &gt;= 0 &amp;&amp; col &lt; n) {&#10;        if(matrix[row][col] &lt;= mid) { count += row + 1; col++; }&#10;        else row--;&#10;    }&#10;    return count;&#10;}&#10;int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    int low = matrix[0][0], high = matrix[n-1][n-1];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countLessOrEqual(matrix, mid, n) &gt;= k) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Heap 05 Find Median From Data Stream<br><br></b> <a href="https://leetcode.com/problems/find-median-from-data-stream/" target="_blank">LeetCode 295</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Two heaps.</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Maintain two heaps: a max-heap for the smaller half of numbers and a min-heap for the larger half. Balance them such that the max-heap has at most 1 more element than the min-heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxH;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;public:&#10;    void addNum(int num) {&#10;        maxH.push(num);&#10;        minH.push(maxH.top());&#10;        maxH.pop();&#10;        if(maxH.size() &lt; minH.size()) {&#10;            maxH.push(minH.top());&#10;            minH.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        if(maxH.size() &gt; minH.size()) return maxH.top();&#10;        return (maxH.top() + minH.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Heap 06 Replace Each Array Element By Its Corresponding Rank<br><br></b> <a href="https://leetcode.com/problems/rank-transform-of-an-array/" target="_blank">LeetCode 1331</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Input: [40,10,20,30], Output: [4,1,2,3]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Create a copy of array, sort it, and remove duplicates. Use a hash map to map each unique value to its rank. Replace elements in original array using map.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; arrayRankTransform(vector&lt;int&gt;&amp; arr) {&#10;    set&lt;int&gt; st(arr.begin(), arr.end());&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int rank = 1;&#10;    for(int num : st) mpp[num] = rank++;&#10;    vector&lt;int&gt; ans;&#10;    for(int num : arr) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Heap 07 Task Scheduler<br><br></b> <a href="https://leetcode.com/problems/task-scheduler/" target="_blank">LeetCode 621</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Greedy placement.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Find max frequency `max_f`. Calculate idle slots `(max_f - 1) * n`. Iterate remaining frequencies and subtract from idle slots. Return `tasks.length + max(0, idle_slots)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int leastInterval(vector&lt;char&gt;&amp; tasks, int n) {&#10;    vector&lt;int&gt; freq(26, 0);&#10;    int max_f = 0, count_max = 0;&#10;    for(char c : tasks) {&#10;        freq[c - &#x27;A&#x27;]++;&#10;        if(freq[c - &#x27;A&#x27;] &gt; max_f) {&#10;            max_f = freq[c - &#x27;A&#x27;];&#10;            count_max = 1;&#10;        } else if(freq[c - &#x27;A&#x27;] == max_f) count_max++;&#10;    }&#10;    int ans = (max_f - 1) * (n + 1) + count_max;&#10;    return max(ans, (int)tasks.size());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Heap 08 Hand Of Straights<br><br></b> <a href="https://leetcode.com/problems/hand-of-straights/" target="_blank">LeetCode 846</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Form consecutive sequences.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a map (TreeMap in C++) to store frequencies. Iterate through map. If a number has count > 0, we must form a group starting from it. Decrement counts of `num, num+1, ..., num+groupSize-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isNStraightHand(vector&lt;int&gt;&amp; hand, int groupSize) {&#10;    if(hand.size() % groupSize != 0) return false;&#10;    map&lt;int, int&gt; mpp;&#10;    for(int card : hand) mpp[card]++;&#10;    for(auto it : mpp) {&#10;        if(it.second &gt; 0) {&#10;            int count = it.second;&#10;            for(int i=0; i&lt;groupSize; i++) {&#10;                if(mpp[it.first + i] &lt; count) return false;&#10;                mpp[it.first + i] -= count;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Heap 09 Design Twitter<br><br></b> <a href="https://leetcode.com/problems/design-twitter/" target="_blank">LeetCode 355</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Object oriented design.</td>
      <td><b>Time:</b> O(N log 10)<br><b>Space:</b> O(U + T)</td>
      <td><b>Explanation:</b> Use a hash map to map user to their followees. Use another map to map user to their tweets. For news feed, use a Max-Heap to extract the 10 most recent tweets from the user and their followees.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; followers;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets;&#10;    int time = 0;&#10;public:&#10;    Twitter() {}&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int f : followers[userId]) {&#10;            for(auto t : tweets[f]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; ans;&#10;        while(!pq.empty() &amp;&amp; ans.size() &lt; 10) {&#10;            ans.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return ans;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        followers[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        followers[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Heap 10 Kth Largest Element In A Stream<br><br></b> <a href="https://leetcode.com/problems/kth-largest-element-in-a-stream/" target="_blank">LeetCode 703</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td>**Example 1:** Min-heap of size K.</td>
      <td><b>Time:</b> O(N log K) for init, O(log K) for add<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a min-heap of size exactly `k`. The top of the min-heap will always represent the kth largest element. For every new element added, if the heap size is less than `k`, push it. If the heap is of size `k` and the new element is greater than the top, pop the top and push the new element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class KthLargest {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    int k;&#10;public:&#10;    KthLargest(int k, vector&lt;int&gt;&amp; nums) {&#10;        this-&gt;k = k;&#10;        for(int num : nums) {&#10;            pq.push(num);&#10;            if(pq.size() &gt; k) pq.pop();&#10;        }&#10;    }&#10;    int add(int val) {&#10;        pq.push(val);&#10;        if(pq.size() &gt; k) pq.pop();&#10;        return pq.top();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Heap 11 K Closest Points To Origin<br><br></b> <a href="https://leetcode.com/problems/k-closest-points-to-origin/" target="_blank">LeetCode 973</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Max-heap of pairs.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Use a max-heap of size `k` to store pairs of `(distance, point_index)`. Iterate over all points, push into heap. If heap size exceeds `k`, pop the max element. The heap will eventually hold the `k` points with minimum distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; kClosest(vector&lt;vector&lt;int&gt;&gt;&amp; points, int k) {&#10;    priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; points.size(); i++) {&#10;        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];&#10;        pq.push({dist, i});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(points[pq.top().second]);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Heap 12 Reorganize String<br><br></b> <a href="https://leetcode.com/problems/reorganize-string/" target="_blank">LeetCode 767</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26)</td>
      <td><b>Explanation:</b> See greedy_38_reorganize_string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Heap 13 Smallest Range In K Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Min-Heap.</td>
      <td><b>Time:</b> O(N * K * log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K, storing the first element of each list along with its list index and element index. Keep track of the `max_val` currently in the heap. The current range is `[heap_min, max_val]`. Extract the min, update the smallest range if needed, and insert the next element from the extracted element's list. Update `max_val` with the new element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">pair&lt;int,int&gt; findSmallestRange(int KSortedArray[][N], int n, int k) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int mx = INT_MIN;&#10;    for(int i = 0; i &lt; k; i++) {&#10;        pq.push({KSortedArray[i][0], i, 0});&#10;        mx = max(mx, KSortedArray[i][0]);&#10;    }&#10;    int range = INT_MAX, start = -1, end = -1;&#10;    while(!pq.empty()) {&#10;        auto curr = pq.top();&#10;        pq.pop();&#10;        int mn = curr[0];&#10;        int row = curr[1], col = curr[2];&#10;        if(mx - mn &lt; range) {&#10;            range = mx - mn;&#10;            start = mn; end = mx;&#10;        }&#10;        if(col + 1 &lt; n) {&#10;            pq.push({KSortedArray[row][col+1], row, col+1});&#10;            mx = max(mx, KSortedArray[row][col+1]);&#10;        } else {&#10;            break;&#10;        }&#10;    }&#10;    return {start, end};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Heap 14 Kth Largest Sum Contiguous Subarray<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Min-Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Iterate all subarrays using two nested loops. Maintain a min-heap of size K to store the top K sums. If the heap size < K, push the current sum. If the heap size == K and current sum > heap top, pop and push current sum. The top of the heap is the Kth largest sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargest(vector&lt;int&gt; &amp;Arr, int N, int K) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        int sum = 0;&#10;        for(int j = i; j &lt; N; j++) {&#10;            sum += Arr[j];&#10;            if(pq.size() &lt; K) pq.push(sum);&#10;            else if(sum &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(sum);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Heap 15 Minimum Sum Of Two Numbers Formed From Digits Of An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-sum4058/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Sort or Min-Heap.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Sort the array. Build two strings representing the two numbers by picking digits alternately from the sorted array. Add the two large numbers as strings or build the result dynamically.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string solve(int arr[], int n) {&#10;    sort(arr, arr + n);&#10;    string a = &quot;&quot;, b = &quot;&quot;;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) a += to_string(arr[i]);&#10;        else b += to_string(arr[i]);&#10;    }&#10;    string res = &quot;&quot;;&#10;    int i = a.length() - 1, j = b.length() - 1, carry = 0;&#10;    while(i &gt;= 0 || j &gt;= 0 || carry) {&#10;        int sum = carry;&#10;        if(i &gt;= 0) sum += a[i--] - &#x27;0&#x27;;&#10;        if(j &gt;= 0) sum += b[j--] - &#x27;0&#x27;;&#10;        res += to_string(sum % 10);&#10;        carry = sum / 10;&#10;    }&#10;    while(res.length() &gt; 1 &amp;&amp; res.back() == &#x27;0&#x27;) res.pop_back();&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Heap 16 Is Binary Tree Heap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Tree Traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td><b>Explanation:</b> First, check if the tree is complete by counting nodes and ensuring no node's index `i > count`. Then check if every node satisfies the max-heap property (`node.val >= left.val` and `node.val >= right.val`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countNodes(Node* root) {&#10;    if(!root) return 0;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}&#10;bool isCBT(Node* root, int index, int count) {&#10;    if(!root) return true;&#10;    if(index &gt;= count) return false;&#10;    return isCBT(root-&gt;left, 2 * index + 1, count) &amp;&amp; isCBT(root-&gt;right, 2 * index + 2, count);&#10;}&#10;bool isMaxOrder(Node* root) {&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) return true;&#10;    if(!root-&gt;right) return root-&gt;data &gt;= root-&gt;left-&gt;data;&#10;    return (root-&gt;data &gt;= root-&gt;left-&gt;data) &amp;&amp; (root-&gt;data &gt;= root-&gt;right-&gt;data) &amp;&amp; isMaxOrder(root-&gt;left) &amp;&amp; isMaxOrder(root-&gt;right);&#10;}&#10;bool isHeap(struct Node* tree) {&#10;    int count = countNodes(tree);&#10;    return isCBT(tree, 0, count) &amp;&amp; isMaxOrder(tree);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Heap 17 Convert Min Heap To Max Heap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666738710/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Heapify.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(log N) for recursion</td>
      <td><b>Explanation:</b> Apply the standard max-heapify process starting from the last non-leaf node `(N/2 - 1)` down to the root. This takes O(N) time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void maxHeapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, left = 2 * i + 1, right = 2 * i + 2;&#10;    if(left &lt; n &amp;&amp; arr[left] &gt; arr[largest]) largest = left;&#10;    if(right &lt; n &amp;&amp; arr[right] &gt; arr[largest]) largest = right;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        maxHeapify(arr, n, largest);&#10;    }&#10;}&#10;void convertMinToMaxHeap(vector&lt;int&gt; &amp;arr, int N) {&#10;    for(int i = (N - 2) / 2; i &gt;= 0; i--) {&#10;        maxHeapify(arr, N, i);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Heap 18 Minimum Cost Of Ropes<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Min-Heap Greedy.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use a min-heap. Pop two minimum length ropes, add them up, add sum to total cost, and push the merged rope back to the heap. Repeat until one rope remains.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long minCost(long long arr[], long long n) {&#10;    priority_queue&lt;long long, vector&lt;long long&gt;, greater&lt;long long&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) pq.push(arr[i]);&#10;    long long cost = 0;&#10;    while(pq.size() &gt; 1) {&#10;        long long a = pq.top(); pq.pop();&#10;        long long b = pq.top(); pq.pop();&#10;        long long sum = a + b;&#10;        cost += sum;&#10;        pq.push(sum);&#10;    }&#10;    return cost;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Heap 19 K Th Largest Element In A Stream<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Min-Heap of size K.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K. While processing the stream, if heap size is < K, push current element. If heap size == K and current element is > heap top, pop and push current element. Append heap top to result if size is K, else append -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kthLargest(int k, int arr[], int n) {&#10;    vector&lt;int&gt; res;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &gt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;        if(pq.size() &lt; k) res.push_back(-1);&#10;        else res.push_back(pq.top());&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Heap 20 Merge K Sorted Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Min Heap.</td>
      <td><b>Time:</b> O(K^2 log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Create a min-heap that stores a tuple: (value, array_index, element_index). Push the first element of each of the K arrays into the heap. While the heap is not empty, pop the minimum element, add it to the result, and if the array from which it was popped has more elements, push the next element to the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Element {&#10;public:&#10;    int val, row, col;&#10;    Element(int v, int r, int c) : val(v), row(r), col(c) {}&#10;};&#10;struct Compare {&#10;    bool operator()(Element a, Element b) {&#10;        return a.val &gt; b.val;&#10;    }&#10;};&#10;vector&lt;int&gt; mergeKArrays(vector&lt;vector&lt;int&gt;&gt; arr, int K) {&#10;    priority_queue&lt;Element, vector&lt;Element&gt;, Compare&gt; pq;&#10;    vector&lt;int&gt; res;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        pq.push(Element(arr[i][0], i, 0));&#10;    }&#10;    while(!pq.empty()) {&#10;        Element curr = pq.top();&#10;        pq.pop();&#10;        res.push_back(curr.val);&#10;        if(curr.col + 1 &lt; K) {&#10;            pq.push(Element(arr[curr.row][curr.col + 1], curr.row, curr.col + 1));&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Heap 21 Smallest Range Covering Elements From K Lists<br><br></b> <a href="https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/" target="_blank">LeetCode 632</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Use a min-heap storing `(value, list_idx, elem_idx)`. Also maintain the `current_max` of the elements currently in the heap. The current range is `[heap_top, current_max]`. Pop the min, push the next element from its list, and update `current_max`. Continue until any list is exhausted.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; smallestRange(vector&lt;vector&lt;int&gt;&gt;&amp; nums) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int currMax = INT_MIN;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        pq.push({nums[i][0], i, 0});&#10;        currMax = max(currMax, nums[i][0]);&#10;    }&#10;    vector&lt;int&gt; ans = {pq.top()[0], currMax};&#10;    while(true) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int val = curr[0], r = curr[1], c = curr[2];&#10;        if(currMax - val &lt; ans[1] - ans[0]) {&#10;            ans = {val, currMax};&#10;        }&#10;        if(c + 1 == nums[r].size()) break;&#10;        pq.push({nums[r][c + 1], r, c + 1});&#10;        currMax = max(currMax, nums[r][c + 1]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Heap 22 K Largest Elements<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K. Iterate through the array. If the heap has < K elements, push. Else if the current element > heap's top, pop the top and push the current element. The heap will contain the K largest elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kLargest(int arr[], int n, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        pq.push(arr[i]);&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top());&#10;        pq.pop();&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Heap 23 Kth Smallest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Max Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Use a Max Heap of size K. Iterate through the array. For the first K elements, insert them into the heap. For the remaining elements, if the element is smaller than the top of the heap, pop the top and insert the element. The top of the heap will be the Kth smallest element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(int arr[], int l, int r, int k) {&#10;    priority_queue&lt;int&gt; pq;&#10;    for(int i = l; i &lt;= r; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &lt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Heap 24 Merge Two Binary Max Heaps<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Append and Heapify.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td><b>Explanation:</b> Create a new array by appending the two arrays. Then call `heapify` starting from the last non-leaf node `(n/2 - 1)` down to the root `0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void heapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, l = 2 * i + 1, r = 2 * i + 2;&#10;    if(l &lt; n &amp;&amp; arr[l] &gt; arr[largest]) largest = l;&#10;    if(r &lt; n &amp;&amp; arr[r] &gt; arr[largest]) largest = r;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        heapify(arr, n, largest);&#10;    }&#10;}&#10;vector&lt;int&gt; mergeHeaps(vector&lt;int&gt; &amp;a, vector&lt;int&gt; &amp;b, int n, int m) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i : a) ans.push_back(i);&#10;    for(int i : b) ans.push_back(i);&#10;    int total = n + m;&#10;    for(int i = total / 2 - 1; i &gt;= 0; i--) {&#10;        heapify(ans, total, i);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Heap 25 Kth Largest Sum Contiguous Subarray<br><br></b> <a href="https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Prefix sum + Min Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(N + K)</td>
      <td><b>Explanation:</b> Iterate through all possible subarrays and calculate their sums using a prefix sum array. Maintain a Min Heap of size K to keep track of the top K sums. At the end, the top of the Min Heap is the K-th largest sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargestSum(int arr[], int n, int k) {&#10;    vector&lt;int&gt; sum(n + 1, 0);&#10;    for(int i = 1; i &lt;= n; i++) sum[i] = sum[i - 1] + arr[i - 1];&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = i; j &lt;= n; j++) {&#10;            int x = sum[j] - sum[i - 1];&#10;            if(pq.size() &lt; k) pq.push(x);&#10;            else if(x &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(x);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Heap 26 Convert Bst To Min Heap<br><br></b> <a href="https://www.geeksforgeeks.org/convert-bst-min-heap/" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td>**Example 1:** Inorder + Preorder.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Since a BST inorder gives sorted values, store the inorder traversal in an array. The requirement says left subtree elements < right subtree elements, which matches a Preorder traversal (Root, Left, Right) since we want the smallest element at the root. So do a Preorder traversal of the tree and replace nodes with array elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(Node* root, vector&lt;int&gt;&amp; arr) {&#10;    if(!root) return;&#10;    inorder(root-&gt;left, arr);&#10;    arr.push_back(root-&gt;data);&#10;    inorder(root-&gt;right, arr);&#10;}&#10;void preorderFill(Node* root, vector&lt;int&gt;&amp; arr, int&amp; i) {&#10;    if(!root) return;&#10;    root-&gt;data = arr[i++];&#10;    preorderFill(root-&gt;left, arr, i);&#10;    preorderFill(root-&gt;right, arr, i);&#10;}&#10;void convertToMinHeapUtil(Node* root) {&#10;    vector&lt;int&gt; arr;&#10;    inorder(root, arr);&#10;    int i = 0;&#10;    preorderFill(root, arr, i);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
