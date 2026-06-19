# Heaps Revision Table

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
      <td>Heap 01 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td><b>Example 1:</b> Input: nums = [3,2,1,5,6,4], k = 2, Output: 5<br><br><b>Note (Constraint):</b> Can you solve it without sorting?</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td><code>std::priority_queue</code> / <code>heapq</code></td>
      <td><b>Min-Heap sizing:</b> By strictly keeping the size to `k`, the `k` largest elements are trapped inside, with the smallest of them right at the top.</td>
      <td><b>Explanation:</b> Use a Min-Heap of size K. When the heap exceeds size K, pop the minimum element. The top of the heap will be the Kth largest.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;&#10;int findKthLargest(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::priority_queue&lt;int, std::vector&lt;int&gt;, std::greater&lt;int&gt;&gt; minHeap;&#10;    for(int num : nums) {&#10;        minHeap.push(num);&#10;        if(minHeap.size() &gt; k) {&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    return minHeap.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Heap 02 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td><b>Example 1:</b> Input: lists = [[1,4,5],[1,3,4],[2,6]], Output: [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td>Custom Comparator</td>
      <td><b>Pointer Compare:</b> Priority queues need a custom comparator to sort `ListNode*` by their `val`.</td>
      <td><b>Explanation:</b> Push the head of each list into a Min-Heap. Repeatedly pop the smallest node, attach it to the result list, and push its `next` node into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;&#10;struct Compare {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;&#10;ListNode* mergeKLists(std::vector&lt;ListNode*&gt;&amp; lists) {&#10;    std::priority_queue&lt;ListNode*, std::vector&lt;ListNode*&gt;, Compare&gt; pq;&#10;    for (auto list : lists) {&#10;        if (list) pq.push(list);&#10;    }&#10;    &#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    &#10;    while (!pq.empty()) {&#10;        ListNode* node = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = node;&#10;        tail = tail-&gt;next;&#10;        if (node-&gt;next) pq.push(node-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Heap 03 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td><b>Example 1:</b> Input: nums = [1,1,1,2,2,3], k = 2, Output: [1,2]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td><code>std::priority_queue</code>, <code>heapq</code></td>
      <td><b>Min-Heap capacity:</b> If heap size exceeds `k`, pop the top (which is the element with the lowest frequency currently in the heap).</td>
      <td><b>Explanation:</b> Use a Hash Map to count frequencies. Use a Min-Heap of size `k` to keep track of the top `k` elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;#include &lt;queue&gt;&#10;std::vector&lt;int&gt; topKFrequent(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    std::priority_queue&lt;std::pair&lt;int, int&gt;, std::vector&lt;std::pair&lt;int, int&gt;&gt;, std::greater&lt;std::pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto it : mpp) {&#10;        pq.push({it.second, it.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Heaps 04 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td><b>Example 1:</b> Input: lists=[[1,4,5],[1,3,4],[2,6]], Output: [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td><b>Custom Comparator:</b> In C++, define a struct to compare ListNode* values.</td>
      <td><b>Explanation:</b> Use a Min-Heap. Push the head of each linked list into the Priority Queue. Continuously pop the smallest, append it to result, and push its `next` node into the PQ.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct compare {&#10;    bool operator()(const ListNode* l, const ListNode* r) { return l-&gt;val &gt; r-&gt;val; }&#10;};&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, compare&gt; pq;&#10;    for(auto l : lists) if(l) pq.push(l);&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(!pq.empty()) {&#10;        tail-&gt;next = pq.top(); pq.pop();&#10;        tail = tail-&gt;next;&#10;        if(tail-&gt;next) pq.push(tail-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Heap 06 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td><b>Example 1:</b> Input: nums = [3,2,1,5,6,4], k = 2. Output: 5</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min-Heap of size K. Push elements into the heap. If heap size exceeds K, pop the minimum element. The top of the heap at the end is the Kth largest element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(vector&lt;int&gt;&amp; nums, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;    for(int num : nums) {&#10;        minH.push(num);&#10;        if(minH.size() &gt; k) minH.pop();&#10;    }&#10;    return minH.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Heap 07 Kth Smallest Element In A Sorted Matrix<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/' target='_blank'>LeetCode 378</a></td>
      <td><b>Example 1:</b> Binary search on range.</td>
      <td><b>Time:</b> O(N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the value range `[matrix[0][0], matrix[n-1][n-1]]`. Count elements less than or equal to `mid` using two pointers (start from bottom-left). If count >= k, search left half, else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countLessOrEqual(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int mid, int n) {&#10;    int count = 0, row = n - 1, col = 0;&#10;    while(row &gt;= 0 &amp;&amp; col &lt; n) {&#10;        if(matrix[row][col] &lt;= mid) { count += row + 1; col++; }&#10;        else row--;&#10;    }&#10;    return count;&#10;}&#10;int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    int low = matrix[0][0], high = matrix[n-1][n-1];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countLessOrEqual(matrix, mid, n) &gt;= k) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Heap 08 Find Median From Data Stream<br><br></b> <a href='https://leetcode.com/problems/find-median-from-data-stream/' target='_blank'>LeetCode 295</a></td>
      <td><b>Example 1:</b> Two heaps.</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain two heaps: a max-heap for the smaller half of numbers and a min-heap for the larger half. Balance them such that the max-heap has at most 1 more element than the min-heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxH;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;public:&#10;    void addNum(int num) {&#10;        maxH.push(num);&#10;        minH.push(maxH.top());&#10;        maxH.pop();&#10;        if(maxH.size() &lt; minH.size()) {&#10;            maxH.push(minH.top());&#10;            minH.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        if(maxH.size() &gt; minH.size()) return maxH.top();&#10;        return (maxH.top() + minH.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Heap 09 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td><b>Example 1:</b> Use Min-Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td><b>Empty lists:</b> Ignore nullptrs.</td>
      <td><b>Explanation:</b> Push the heads of all K lists into a Min-Heap. Pop the smallest node, append it to result, and if it has a next node, push the next node into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct comp { bool operator()(ListNode* a, ListNode* b) { return a-&gt;val &gt; b-&gt;val; } };&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, comp&gt; pq;&#10;    for(auto head : lists) if(head) pq.push(head);&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(!pq.empty()) {&#10;        ListNode* curr = pq.top(); pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Heap 10 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td><b>Example 1:</b> Output: elements.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a map. Use a Min-Heap of size K, storing pairs `(freq, num)`. If size > K, pop. Heap will contain the top K elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topKFrequent(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; minH;&#10;    for(auto it : mpp) {&#10;        minH.push({it.second, it.first});&#10;        if(minH.size() &gt; k) minH.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!minH.empty()) {&#10;        ans.push_back(minH.top().second);&#10;        minH.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Heap 11 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td><b>Example 1:</b> `s = "tree"`. Output: `"eert"`.</td>
      <td><b>Time:</b> O(N log 26)<br><b>Space:</b> O(26)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Hash map to store frequencies, then max-heap to process them in descending order of frequency.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; mpp;&#10;    for(char c : s) mpp[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto it : mpp) pq.push({it.second, it.first});&#10;    string ans = &quot;&quot;;&#10;    while(!pq.empty()) {&#10;        ans += string(pq.top().first, pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Heap 12 Replace Each Array Element By Its Corresponding Rank<br><br></b> <a href='https://leetcode.com/problems/rank-transform-of-an-array/' target='_blank'>LeetCode 1331</a></td>
      <td><b>Example 1:</b> Input: [40,10,20,30], Output: [4,1,2,3]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Create a copy of array, sort it, and remove duplicates. Use a hash map to map each unique value to its rank. Replace elements in original array using map.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; arrayRankTransform(vector&lt;int&gt;&amp; arr) {&#10;    set&lt;int&gt; st(arr.begin(), arr.end());&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int rank = 1;&#10;    for(int num : st) mpp[num] = rank++;&#10;    vector&lt;int&gt; ans;&#10;    for(int num : arr) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Heap 13 Task Scheduler<br><br></b> <a href='https://leetcode.com/problems/task-scheduler/' target='_blank'>LeetCode 621</a></td>
      <td><b>Example 1:</b> Greedy placement.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Find max frequency `max_f`. Calculate idle slots `(max_f - 1) * n`. Iterate remaining frequencies and subtract from idle slots. Return `tasks.length + max(0, idle_slots)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int leastInterval(vector&lt;char&gt;&amp; tasks, int n) {&#10;    vector&lt;int&gt; freq(26, 0);&#10;    int max_f = 0, count_max = 0;&#10;    for(char c : tasks) {&#10;        freq[c - &#x27;A&#x27;]++;&#10;        if(freq[c - &#x27;A&#x27;] &gt; max_f) {&#10;            max_f = freq[c - &#x27;A&#x27;];&#10;            count_max = 1;&#10;        } else if(freq[c - &#x27;A&#x27;] == max_f) count_max++;&#10;    }&#10;    int ans = (max_f - 1) * (n + 1) + count_max;&#10;    return max(ans, (int)tasks.size());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Heap 14 Hand Of Straights<br><br></b> <a href='https://leetcode.com/problems/hand-of-straights/' target='_blank'>LeetCode 846</a></td>
      <td><b>Example 1:</b> Form consecutive sequences.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a map (TreeMap in C++) to store frequencies. Iterate through map. If a number has count > 0, we must form a group starting from it. Decrement counts of `num, num+1, ..., num+groupSize-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isNStraightHand(vector&lt;int&gt;&amp; hand, int groupSize) {&#10;    if(hand.size() % groupSize != 0) return false;&#10;    map&lt;int, int&gt; mpp;&#10;    for(int card : hand) mpp[card]++;&#10;    for(auto it : mpp) {&#10;        if(it.second &gt; 0) {&#10;            int count = it.second;&#10;            for(int i=0; i&lt;groupSize; i++) {&#10;                if(mpp[it.first + i] &lt; count) return false;&#10;                mpp[it.first + i] -= count;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Heap 15 Design Twitter<br><br></b> <a href='https://leetcode.com/problems/design-twitter/' target='_blank'>LeetCode 355</a></td>
      <td><b>Example 1:</b> Object oriented design.</td>
      <td><b>Time:</b> O(N log 10)<br><b>Space:</b> O(U + T)</td>
      <td><code>#include <unordered_map>\n#include <unordered_set>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map to map user to their followees. Use another map to map user to their tweets. For news feed, use a Max-Heap to extract the 10 most recent tweets from the user and their followees.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; followers;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets;&#10;    int time = 0;&#10;public:&#10;    Twitter() {}&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int f : followers[userId]) {&#10;            for(auto t : tweets[f]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; ans;&#10;        while(!pq.empty() &amp;&amp; ans.size() &lt; 10) {&#10;            ans.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return ans;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        followers[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        followers[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Heap 24 Kth Largest Element In A Stream<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-a-stream/' target='_blank'>LeetCode 703</a></td>
      <td><b>Example 1:</b> Min-heap of size K.</td>
      <td><b>Time:</b> O(N log K) for init, O(log K) for add<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size exactly `k`. The top of the min-heap will always represent the kth largest element. For every new element added, if the heap size is less than `k`, push it. If the heap is of size `k` and the new element is greater than the top, pop the top and push the new element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class KthLargest {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    int k;&#10;public:&#10;    KthLargest(int k, vector&lt;int&gt;&amp; nums) {&#10;        this-&gt;k = k;&#10;        for(int num : nums) {&#10;            pq.push(num);&#10;            if(pq.size() &gt; k) pq.pop();&#10;        }&#10;    }&#10;    int add(int val) {&#10;        pq.push(val);&#10;        if(pq.size() &gt; k) pq.pop();&#10;        return pq.top();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Heap 25 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td><b>Example 1:</b> Min-heap or Quickselect.</td>
      <td><b>Time:</b> O(N log K) Heap, O(N) avg Quickselect<br><b>Space:</b> O(K) Heap, O(1) Quickselect</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Min-heap: Keep a min-heap of size K. The root is the Kth largest. Quickselect: Partition the array like in Quicksort, recursively searching only the partition containing the target index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(vector&lt;int&gt;&amp; nums, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int num : nums) {&#10;        pq.push(num);&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Heap 26 K Closest Points To Origin<br><br></b> <a href='https://leetcode.com/problems/k-closest-points-to-origin/' target='_blank'>LeetCode 973</a></td>
      <td><b>Example 1:</b> Max-heap of pairs.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a max-heap of size `k` to store pairs of `(distance, point_index)`. Iterate over all points, push into heap. If heap size exceeds `k`, pop the max element. The heap will eventually hold the `k` points with minimum distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; kClosest(vector&lt;vector&lt;int&gt;&gt;&amp; points, int k) {&#10;    priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; points.size(); i++) {&#10;        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];&#10;        pq.push({dist, i});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(points[pq.top().second]);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Heap 27 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td><b>Example 1:</b> Hash map + Min-heap or Bucket sort.</td>
      <td><b>Time:</b> O(N log K) Heap, O(N) Bucket Sort<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a hash map. Use a min-heap of size `k` storing pairs of `(frequency, element)`. Or use bucket sort where index is frequency and value is list of elements with that frequency.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topKFrequent(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; counts;&#10;    for(int num : nums) counts[num]++;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto&amp; p : counts) {&#10;        pq.push({p.second, p.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Heap 28 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td><b>Example 1:</b> Hash map + Max-heap or Sort.</td>
      <td><b>Time:</b> O(N log M) where M is unique characters<br><b>Space:</b> O(M)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies of each character. Store pairs of `(frequency, character)` in a max-heap (or sort an array). Construct the result string by popping from the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; counts;&#10;    for(char c : s) counts[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto&amp; p : counts) pq.push({p.second, p.first});&#10;    string res = &quot;&quot;;&#10;    while(!pq.empty()) {&#10;        res += string(pq.top().first, pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Heap 29 Find Median From Data Stream<br><br></b> <a href='https://leetcode.com/problems/find-median-from-data-stream/' target='_blank'>LeetCode 295</a></td>
      <td><b>Example 1:</b> Two heaps (Max-heap for lower half, Min-heap for upper half).</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use two heaps: a max-heap for the smaller half of numbers, and a min-heap for the larger half. Keep the sizes balanced (either equal, or max-heap has 1 more). Median is root of max-heap (odd total) or average of both roots (even total).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxHeap;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minHeap;&#10;public:&#10;    MedianFinder() {}&#10;    void addNum(int num) {&#10;        maxHeap.push(num);&#10;        minHeap.push(maxHeap.top());&#10;        maxHeap.pop();&#10;        if(maxHeap.size() &lt; minHeap.size()) {&#10;            maxHeap.push(minHeap.top());&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        return maxHeap.size() &gt; minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Heap 30 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td><b>Example 1:</b> Min-heap of list nodes.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Push the head of each list into a min-heap. Extract the minimum node, append it to the merged list, and push its next node (if any) into the min-heap. Repeat until heap is empty.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct comp {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, comp&gt; pq;&#10;    for(ListNode* node : lists) {&#10;        if(node) pq.push(node);&#10;    }&#10;    ListNode dummy(0);&#10;    ListNode* tail = &amp;dummy;&#10;    while(!pq.empty()) {&#10;        ListNode* curr = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy.next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Heap 31 Task Scheduler<br><br></b> <a href='https://leetcode.com/problems/task-scheduler/' target='_blank'>LeetCode 621</a></td>
      <td><b>Example 1:</b> Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> See greedy_37_task_scheduler.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Heap 32 Design Twitter<br><br></b> <a href='https://leetcode.com/problems/design-twitter/' target='_blank'>LeetCode 355</a></td>
      <td><b>Example 1:</b> Heap to merge multiple sorted lists.</td>
      <td><b>Time:</b> O(K log K) for feed where K is 10.<br><b>Space:</b> O(Total Tweets + Follow Relations)</td>
      <td><code>#include <unordered_map>\n#include <unordered_set>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a timestamp for tweets. Each user has a list of tweets and a set of followed users. To get the news feed, gather the most recent tweets from the user and all followees using a max-heap (like merging K sorted lists).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    int time;&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; follows;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets; // time, tweetId&#10;public:&#10;    Twitter() { time = 0; }&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int followee : follows[userId]) {&#10;            for(auto t : tweets[followee]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; res;&#10;        for(int i = 0; i &lt; 10 &amp;&amp; !pq.empty(); i++) {&#10;            res.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return res;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        if(followerId != followeeId) follows[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        follows[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Heap 33 Reorganize String<br><br></b> <a href='https://leetcode.com/problems/reorganize-string/' target='_blank'>LeetCode 767</a></td>
      <td><b>Example 1:</b> Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> See greedy_38_reorganize_string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Heap 25 Smallest Range In K Lists<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N * K * log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K, storing the first element of each list along with its list index and element index. Keep track of the `max_val` currently in the heap. The current range is `[heap_min, max_val]`. Extract the min, update the smallest range if needed, and insert the next element from the extracted element's list. Update `max_val` with the new element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">pair&lt;int,int&gt; findSmallestRange(int KSortedArray[][N], int n, int k) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int mx = INT_MIN;&#10;    for(int i = 0; i &lt; k; i++) {&#10;        pq.push({KSortedArray[i][0], i, 0});&#10;        mx = max(mx, KSortedArray[i][0]);&#10;    }&#10;    int range = INT_MAX, start = -1, end = -1;&#10;    while(!pq.empty()) {&#10;        auto curr = pq.top();&#10;        pq.pop();&#10;        int mn = curr[0];&#10;        int row = curr[1], col = curr[2];&#10;        if(mx - mn &lt; range) {&#10;            range = mx - mn;&#10;            start = mn; end = mx;&#10;        }&#10;        if(col + 1 &lt; n) {&#10;            pq.push({KSortedArray[row][col+1], row, col+1});&#10;            mx = max(mx, KSortedArray[row][col+1]);&#10;        } else {&#10;            break;&#10;        }&#10;    }&#10;    return {start, end};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Heap 26 Merge K Sorted Linked Lists<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N * K * log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Create a min-heap and push the head of each linked list into it. Pop the minimum element, append it to the result list, and if the popped node has a next node, push the next node into the heap. Continue until the heap is empty.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct compare {&#10;    bool operator()(Node* a, Node* b) {&#10;        return a-&gt;data &gt; b-&gt;data;&#10;    }&#10;};&#10;Node * mergeKLists(Node *arr[], int K) {&#10;    priority_queue&lt;Node*, vector&lt;Node*&gt;, compare&gt; pq;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        if(arr[i]) pq.push(arr[i]);&#10;    }&#10;    Node* dummy = new Node(0);&#10;    Node* tail = dummy;&#10;    while(!pq.empty()) {&#10;        Node* curr = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Heap 27 Reorganize String<br><br></b> <a href='https://leetcode.com/problems/reorganize-string/' target='_blank'>LeetCode 767</a></td>
      <td><b>Example 1:</b> Max-Heap.</td>
      <td><b>Time:</b> O(N log(26))<br><b>Space:</b> O(26)</td>
      <td><code>#include <queue>\n#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count character frequencies. Push pairs `(freq, char)` to a max-heap. Pop two most frequent distinct characters, append to result, decrement frequencies, and push back if frequency > 0. If at the end one character remains with freq > 1, return empty string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reorganizeString(string s) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : s) count[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto&amp; pair : count) pq.push({pair.second, pair.first});&#10;    string res = &quot;&quot;;&#10;    while(pq.size() &gt;= 2) {&#10;        auto [freq1, char1] = pq.top(); pq.pop();&#10;        auto [freq2, char2] = pq.top(); pq.pop();&#10;        res += char1; res += char2;&#10;        if(--freq1 &gt; 0) pq.push({freq1, char1});&#10;        if(--freq2 &gt; 0) pq.push({freq2, char2});&#10;    }&#10;    if(!pq.empty()) {&#10;        auto [freq, char_] = pq.top();&#10;        if(freq &gt; 1) return &quot;&quot;;&#10;        res += char_;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Heap 28 Kth Largest Sum Contiguous Subarray<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate all subarrays using two nested loops. Maintain a min-heap of size K to store the top K sums. If the heap size < K, push the current sum. If the heap size == K and current sum > heap top, pop and push current sum. The top of the heap is the Kth largest sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargest(vector&lt;int&gt; &amp;Arr, int N, int K) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        int sum = 0;&#10;        for(int j = i; j &lt; N; j++) {&#10;            sum += Arr[j];&#10;            if(pq.size() &lt; K) pq.push(sum);&#10;            else if(sum &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(sum);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Heap 29 Minimum Sum Of Two Numbers Formed From Digits Of An Array<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-sum4058/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Sort or Min-Heap.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort the array. Build two strings representing the two numbers by picking digits alternately from the sorted array. Add the two large numbers as strings or build the result dynamically.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string solve(int arr[], int n) {&#10;    sort(arr, arr + n);&#10;    string a = &quot;&quot;, b = &quot;&quot;;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) a += to_string(arr[i]);&#10;        else b += to_string(arr[i]);&#10;    }&#10;    string res = &quot;&quot;;&#10;    int i = a.length() - 1, j = b.length() - 1, carry = 0;&#10;    while(i &gt;= 0 || j &gt;= 0 || carry) {&#10;        int sum = carry;&#10;        if(i &gt;= 0) sum += a[i--] - &#x27;0&#x27;;&#10;        if(j &gt;= 0) sum += b[j--] - &#x27;0&#x27;;&#10;        res += to_string(sum % 10);&#10;        carry = sum / 10;&#10;    }&#10;    while(res.length() &gt; 1 &amp;&amp; res.back() == &#x27;0&#x27;) res.pop_back();&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Heap 30 K Th Smallest Element In A 2D Array Sorted Row Wise And Column Wise<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/' target='_blank'>LeetCode 378</a></td>
      <td><b>Example 1:</b> Binary Search or Min-Heap.</td>
      <td><b>Time:</b> O(K log N) or O(N log(max-min))<br><b>Space:</b> O(N) or O(1)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Min-heap: Push the first element of each row. Pop `K-1` times, pushing the next element in the row of the popped element. The `K`th popped element is the answer. Binary search: search space `matrix[0][0]` to `matrix[n-1][n-1]`. Count elements <= `mid` using two pointers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    for(int i = 0; i &lt; min(n, k); i++) pq.push({matrix[i][0], i, 0});&#10;    while(k-- &gt; 1) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int r = curr[1], c = curr[2];&#10;        if(c + 1 &lt; n) pq.push({matrix[r][c+1], r, c+1});&#10;    }&#10;    return pq.top()[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Heap 31 Is Binary Tree Heap<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Tree Traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> First, check if the tree is complete by counting nodes and ensuring no node's index `i > count`. Then check if every node satisfies the max-heap property (`node.val >= left.val` and `node.val >= right.val`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countNodes(Node* root) {&#10;    if(!root) return 0;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}&#10;bool isCBT(Node* root, int index, int count) {&#10;    if(!root) return true;&#10;    if(index &gt;= count) return false;&#10;    return isCBT(root-&gt;left, 2 * index + 1, count) &amp;&amp; isCBT(root-&gt;right, 2 * index + 2, count);&#10;}&#10;bool isMaxOrder(Node* root) {&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) return true;&#10;    if(!root-&gt;right) return root-&gt;data &gt;= root-&gt;left-&gt;data;&#10;    return (root-&gt;data &gt;= root-&gt;left-&gt;data) &amp;&amp; (root-&gt;data &gt;= root-&gt;right-&gt;data) &amp;&amp; isMaxOrder(root-&gt;left) &amp;&amp; isMaxOrder(root-&gt;right);&#10;}&#10;bool isHeap(struct Node* tree) {&#10;    int count = countNodes(tree);&#10;    return isCBT(tree, 0, count) &amp;&amp; isMaxOrder(tree);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Heap 32 Convert Min Heap To Max Heap<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666738710/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Heapify.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(log N) for recursion</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Apply the standard max-heapify process starting from the last non-leaf node `(N/2 - 1)` down to the root. This takes O(N) time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void maxHeapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, left = 2 * i + 1, right = 2 * i + 2;&#10;    if(left &lt; n &amp;&amp; arr[left] &gt; arr[largest]) largest = left;&#10;    if(right &lt; n &amp;&amp; arr[right] &gt; arr[largest]) largest = right;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        maxHeapify(arr, n, largest);&#10;    }&#10;}&#10;void convertMinToMaxHeap(vector&lt;int&gt; &amp;arr, int N) {&#10;    for(int i = (N - 2) / 2; i &gt;= 0; i--) {&#10;        maxHeapify(arr, N, i);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Heap 33 Minimum Cost Of Ropes<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min-Heap Greedy.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a min-heap. Pop two minimum length ropes, add them up, add sum to total cost, and push the merged rope back to the heap. Repeat until one rope remains.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long minCost(long long arr[], long long n) {&#10;    priority_queue&lt;long long, vector&lt;long long&gt;, greater&lt;long long&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) pq.push(arr[i]);&#10;    long long cost = 0;&#10;    while(pq.size() &gt; 1) {&#10;        long long a = pq.top(); pq.pop();&#10;        long long b = pq.top(); pq.pop();&#10;        long long sum = a + b;&#10;        cost += sum;&#10;        pq.push(sum);&#10;    }&#10;    return cost;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Heap 34 K Th Largest Element In A Stream<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min-Heap of size K.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K. While processing the stream, if heap size is < K, push current element. If heap size == K and current element is > heap top, pop and push current element. Append heap top to result if size is K, else append -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kthLargest(int k, int arr[], int n) {&#10;    vector&lt;int&gt; res;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &gt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;        if(pq.size() &lt; k) res.push_back(-1);&#10;        else res.push_back(pq.top());&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Heap 06 Kth Largest Element In A Stream<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K. For each element in the stream, push it to the heap. If the heap size exceeds K, pop the top (minimum) element. The top of the heap is the Kth largest element. If the size is less than K, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kthLargest(int k, int arr[], int n) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    vector&lt;int&gt; res;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        pq.push(arr[i]);&#10;        if(pq.size() &gt; k) pq.pop();&#10;        if(pq.size() &lt; k) res.push_back(-1);&#10;        else res.push_back(pq.top());&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Heap 07 Merge K Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(K^2 log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a min-heap that stores a tuple: (value, array_index, element_index). Push the first element of each of the K arrays into the heap. While the heap is not empty, pop the minimum element, add it to the result, and if the array from which it was popped has more elements, push the next element to the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Element {&#10;public:&#10;    int val, row, col;&#10;    Element(int v, int r, int c) : val(v), row(r), col(c) {}&#10;};&#10;struct Compare {&#10;    bool operator()(Element a, Element b) {&#10;        return a.val &gt; b.val;&#10;    }&#10;};&#10;vector&lt;int&gt; mergeKArrays(vector&lt;vector&lt;int&gt;&gt; arr, int K) {&#10;    priority_queue&lt;Element, vector&lt;Element&gt;, Compare&gt; pq;&#10;    vector&lt;int&gt; res;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        pq.push(Element(arr[i][0], i, 0));&#10;    }&#10;    while(!pq.empty()) {&#10;        Element curr = pq.top();&#10;        pq.pop();&#10;        res.push_back(curr.val);&#10;        if(curr.col + 1 &lt; K) {&#10;            pq.push(Element(arr[curr.row][curr.col + 1], curr.row, curr.col + 1));&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Heap 08 Reorganize String<br><br></b> <a href='https://leetcode.com/problems/reorganize-string/' target='_blank'>LeetCode 767</a></td>
      <td><b>Example 1:</b> Max Heap for frequencies.</td>
      <td><b>Time:</b> O(N log A)<br><b>Space:</b> O(A)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Count character frequencies. Use a max-heap to store (count, char). Pop the top two most frequent characters, append them to the result, decrement their counts, and push them back if count > 0. If one character is left and its count > 1, it's impossible.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reorganizeString(string s) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : s) count[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto it : count) pq.push({it.second, it.first});&#10;    string res = &quot;&quot;;&#10;    while(pq.size() &gt; 1) {&#10;        auto top1 = pq.top(); pq.pop();&#10;        auto top2 = pq.top(); pq.pop();&#10;        res += top1.second;&#10;        res += top2.second;&#10;        if(--top1.first &gt; 0) pq.push(top1);&#10;        if(--top2.first &gt; 0) pq.push(top2);&#10;    }&#10;    if(!pq.empty()) {&#10;        if(pq.top().first &gt; 1) return &quot;&quot;;&#10;        res += pq.top().second;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Heap 09 Find Median From Data Stream<br><br></b> <a href='https://leetcode.com/problems/find-median-from-data-stream/' target='_blank'>LeetCode 295</a></td>
      <td><b>Example 1:</b> Two Heaps.</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain two heaps: a max-heap for the smaller half of the numbers, and a min-heap for the larger half. Ensure the max-heap has either the same size or one more element than the min-heap. The median is either the top of the max-heap or the average of the tops.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxHeap;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minHeap;&#10;public:&#10;    MedianFinder() {}&#10;    void addNum(int num) {&#10;        if(maxHeap.empty() || num &lt;= maxHeap.top()) {&#10;            maxHeap.push(num);&#10;        } else {&#10;            minHeap.push(num);&#10;        }&#10;        if(maxHeap.size() &gt; minHeap.size() + 1) {&#10;            minHeap.push(maxHeap.top());&#10;            maxHeap.pop();&#10;        } else if(minHeap.size() &gt; maxHeap.size()) {&#10;            maxHeap.push(minHeap.top());&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        if(maxHeap.size() == minHeap.size()) {&#10;            return (maxHeap.top() + minHeap.top()) / 2.0;&#10;        }&#10;        return maxHeap.top();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Heap 10 Smallest Range Covering Elements From K Lists<br><br></b> <a href='https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/' target='_blank'>LeetCode 632</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a min-heap storing `(value, list_idx, elem_idx)`. Also maintain the `current_max` of the elements currently in the heap. The current range is `[heap_top, current_max]`. Pop the min, push the next element from its list, and update `current_max`. Continue until any list is exhausted.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; smallestRange(vector&lt;vector&lt;int&gt;&gt;&amp; nums) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int currMax = INT_MIN;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        pq.push({nums[i][0], i, 0});&#10;        currMax = max(currMax, nums[i][0]);&#10;    }&#10;    vector&lt;int&gt; ans = {pq.top()[0], currMax};&#10;    while(true) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int val = curr[0], r = curr[1], c = curr[2];&#10;        if(currMax - val &lt; ans[1] - ans[0]) {&#10;            ans = {val, currMax};&#10;        }&#10;        if(c + 1 == nums[r].size()) break;&#10;        pq.push({nums[r][c + 1], r, c + 1});&#10;        currMax = max(currMax, nums[r][c + 1]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Heap 11 Kth Smallest Element In A Sorted Matrix<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/' target='_blank'>LeetCode 378</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(K log N)<br><b>Space:</b> O(N)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to merging K sorted arrays. Push the first element of each row into a min-heap. Pop the minimum element `K-1` times, pushing the next element from the popped element's row. The Kth popped element is the answer. (Binary Search is also optimal here).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) pq.push({matrix[i][0], i, 0});&#10;    for(int i = 0; i &lt; k - 1; i++) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int r = curr[1], c = curr[2];&#10;        if(c + 1 &lt; n) pq.push({matrix[r][c + 1], r, c + 1});&#10;    }&#10;    return pq.top()[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Heap 12 Minimum Cost Of Ropes<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Insert all lengths into a min-heap. While heap size > 1, extract the two minimum elements, add them, add their sum to the total cost, and insert their sum back into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long minCost(long long arr[], long long n) {&#10;    priority_queue&lt;long long, vector&lt;long long&gt;, greater&lt;long long&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) pq.push(arr[i]);&#10;    long long cost = 0;&#10;    while(pq.size() &gt; 1) {&#10;        long long a = pq.top(); pq.pop();&#10;        long long b = pq.top(); pq.pop();&#10;        cost += (a + b);&#10;        pq.push(a + b);&#10;    }&#10;    return cost;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Heap 13 K Closest Points To Origin<br><br></b> <a href='https://leetcode.com/problems/k-closest-points-to-origin/' target='_blank'>LeetCode 973</a></td>
      <td><b>Example 1:</b> Max Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a max-heap of size K to store `(distance_squared, index)`. For each point, if the heap size is < K, push it. Otherwise, if its distance is less than the max-heap's top distance, pop the top and push the new point.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; kClosest(vector&lt;vector&lt;int&gt;&gt;&amp; points, int k) {&#10;    priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; points.size(); i++) {&#10;        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];&#10;        pq.push({dist, i});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(points[pq.top().second]);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Heap 14 K Largest Elements<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size K. Iterate through the array. If the heap has < K elements, push. Else if the current element > heap's top, pop the top and push the current element. The heap will contain the K largest elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kLargest(int arr[], int n, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        pq.push(arr[i]);&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top());&#10;        pq.pop();&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Heap 15 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td><b>Example 1:</b> Min Heap with Frequencies.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td>Priority Queue, Hash Map</td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a hash map. Maintain a min-heap of size K storing `(frequency, element)`. Push each pair into the heap. If size > K, pop. The remaining elements in the heap are the top K frequent.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topKFrequent(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    for(int num : nums) count[num]++;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto it : count) {&#10;        pq.push({it.second, it.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Heaps 05 Kth Smallest Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Max Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Max Heap of size K. Iterate through the array. For the first K elements, insert them into the heap. For the remaining elements, if the element is smaller than the top of the heap, pop the top and insert the element. The top of the heap will be the Kth smallest element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(int arr[], int l, int r, int k) {&#10;    priority_queue&lt;int&gt; pq;&#10;    for(int i = l; i &lt;= r; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &lt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Heaps 06 Kth Largest Element In A Stream<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a Min Heap of size K. As elements arrive, add them to the heap if the heap has less than K elements. If the heap has K elements and the new element is greater than the top, pop the top and insert the new element. Print the top if heap size is K, else -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kthLargest(int k, int arr[], int n) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &gt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;        if(pq.size() &lt; k) ans.push_back(-1);&#10;        else ans.push_back(pq.top());&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Heaps 07 Merge Two Binary Max Heaps<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Append and Heapify.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a new array by appending the two arrays. Then call `heapify` starting from the last non-leaf node `(n/2 - 1)` down to the root `0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void heapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, l = 2 * i + 1, r = 2 * i + 2;&#10;    if(l &lt; n &amp;&amp; arr[l] &gt; arr[largest]) largest = l;&#10;    if(r &lt; n &amp;&amp; arr[r] &gt; arr[largest]) largest = r;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        heapify(arr, n, largest);&#10;    }&#10;}&#10;vector&lt;int&gt; mergeHeaps(vector&lt;int&gt; &amp;a, vector&lt;int&gt; &amp;b, int n, int m) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i : a) ans.push_back(i);&#10;    for(int i : b) ans.push_back(i);&#10;    int total = n + m;&#10;    for(int i = total / 2 - 1; i &gt;= 0; i--) {&#10;        heapify(ans, total, i);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Heaps 08 Kth Largest Sum Contiguous Subarray<br><br></b> <a href='https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Prefix sum + Min Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(N + K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through all possible subarrays and calculate their sums using a prefix sum array. Maintain a Min Heap of size K to keep track of the top K sums. At the end, the top of the Min Heap is the K-th largest sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargestSum(int arr[], int n, int k) {&#10;    vector&lt;int&gt; sum(n + 1, 0);&#10;    for(int i = 1; i &lt;= n; i++) sum[i] = sum[i - 1] + arr[i - 1];&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = i; j &lt;= n; j++) {&#10;            int x = sum[j] - sum[i - 1];&#10;            if(pq.size() &lt; k) pq.push(x);&#10;            else if(x &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(x);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>49</td>
      <td>Heaps 09 Reorganize String<br><br></b> <a href='https://leetcode.com/problems/reorganize-string/' target='_blank'>LeetCode 767</a></td>
      <td><b>Example 1:</b> Max Heap.</td>
      <td><b>Time:</b> O(N log 26)<br><b>Space:</b> O(26)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Count character frequencies. Use a Max Heap storing `(freq, char)`. Pop the top element, add it to the result, decrement its frequency, and temporarily store it (so it can't be picked in the next iteration). If the stored element has `freq > 0`, push it back. If the heap is empty but the stored element is not, it's impossible.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reorganizeString(string s) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : s) count[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto it : count) pq.push({it.second, it.first});&#10;    string res = &quot;&quot;;&#10;    pair&lt;int, char&gt; prev = {-1, &#x27;#&#x27;};&#10;    while(!pq.empty()) {&#10;        auto curr = pq.top(); pq.pop();&#10;        res += curr.second;&#10;        curr.first--;&#10;        if(prev.first &gt; 0) pq.push(prev);&#10;        prev = curr;&#10;    }&#10;    return res.length() == s.length() ? res : &quot;&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>50</td>
      <td>Heaps 10 Merge K Sorted Arrays<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(K^2 log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min Heap to store the first element of each array along with its 2D index. Extract the minimum element, add it to the result, and insert the next element from the same array into the Min Heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; mergeKArrays(vector&lt;vector&lt;int&gt;&gt; arr, int K) {&#10;    priority_queue&lt;pair&lt;int, pair&lt;int, int&gt;&gt;, vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;, greater&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;&gt; pq;&#10;    for(int i = 0; i &lt; K; i++) pq.push({arr[i][0], {i, 0}});&#10;    vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        auto curr = pq.top(); pq.pop();&#10;        ans.push_back(curr.first);&#10;        int i = curr.second.first, j = curr.second.second;&#10;        if(j + 1 &lt; K) pq.push({arr[i][j + 1], {i, j + 1}});&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>51</td>
      <td>Heaps 11 Smallest Range In K Lists<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap + Sliding Window.</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(K)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Similar to merging K sorted arrays, use a Min Heap storing `(value, list_idx, element_idx)`. Also maintain the `max_val` seen so far among the current elements. The range is `[min_heap_top, max_val]`. Update the range if the difference is smaller. Pop the min and push the next element from the same list, updating `max_val`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">pair&lt;int,int&gt; findSmallestRange(int KSortedArray[][N], int n, int k) {&#10;    priority_queue&lt;pair&lt;int, pair&lt;int, int&gt;&gt;, vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;, greater&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt;&gt; pq;&#10;    int max_val = INT_MIN, range_min = INT_MAX, range_max = INT_MAX, range = INT_MAX;&#10;    for(int i = 0; i &lt; k; i++) {&#10;        pq.push({KSortedArray[i][0], {i, 0}});&#10;        max_val = max(max_val, KSortedArray[i][0]);&#10;    }&#10;    while(true) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int min_val = curr.first, r = curr.second.first, c = curr.second.second;&#10;        if(max_val - min_val &lt; range) {&#10;            range = max_val - min_val;&#10;            range_min = min_val;&#10;            range_max = max_val;&#10;        }&#10;        if(c + 1 == n) break;&#10;        pq.push({KSortedArray[r][c + 1], {r, c + 1}});&#10;        max_val = max(max_val, KSortedArray[r][c + 1]);&#10;    }&#10;    return {range_min, range_max};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>52</td>
      <td>Heaps 12 Minimum Cost Of Ropes<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Priority Queue</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min Heap to always pick the two smallest ropes. Add their sum to the total cost and insert the merged rope back into the heap. Repeat until one rope is left.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long minCost(long long arr[], long long n) {&#10;    priority_queue&lt;long long, vector&lt;long long&gt;, greater&lt;long long&gt;&gt; pq;&#10;    for(long long i = 0; i &lt; n; i++) pq.push(arr[i]);&#10;    long long cost = 0;&#10;    while(pq.size() &gt; 1) {&#10;        long long a = pq.top(); pq.pop();&#10;        long long b = pq.top(); pq.pop();&#10;        cost += (a + b);&#10;        pq.push(a + b);&#10;    }&#10;    return cost;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>53</td>
      <td>Heaps 13 Convert Bst To Min Heap<br><br></b> <a href='https://www.geeksforgeeks.org/convert-bst-min-heap/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Inorder + Preorder.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Since a BST inorder gives sorted values, store the inorder traversal in an array. The requirement says left subtree elements < right subtree elements, which matches a Preorder traversal (Root, Left, Right) since we want the smallest element at the root. So do a Preorder traversal of the tree and replace nodes with array elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(Node* root, vector&lt;int&gt;&amp; arr) {&#10;    if(!root) return;&#10;    inorder(root-&gt;left, arr);&#10;    arr.push_back(root-&gt;data);&#10;    inorder(root-&gt;right, arr);&#10;}&#10;void preorderFill(Node* root, vector&lt;int&gt;&amp; arr, int&amp; i) {&#10;    if(!root) return;&#10;    root-&gt;data = arr[i++];&#10;    preorderFill(root-&gt;left, arr, i);&#10;    preorderFill(root-&gt;right, arr, i);&#10;}&#10;void convertToMinHeapUtil(Node* root) {&#10;    vector&lt;int&gt; arr;&#10;    inorder(root, arr);&#10;    int i = 0;&#10;    preorderFill(root, arr, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>54</td>
      <td>Heaps 14 Check If A Binary Tree Is Heap<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use recursion to check two properties: 1. Is it a Complete Binary Tree? (Count nodes and ensure index of any node is < total count). 2. Is it a Max Heap? (Parent data >= children data).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countNodes(Node* root) {&#10;    if(!root) return 0;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}&#10;bool isCBT(Node* root, int index, int count) {&#10;    if(!root) return true;&#10;    if(index &gt;= count) return false;&#10;    return isCBT(root-&gt;left, 2 * index + 1, count) &amp;&amp; isCBT(root-&gt;right, 2 * index + 2, count);&#10;}&#10;bool isMaxOrder(Node* root) {&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) return true;&#10;    if(!root-&gt;right) return root-&gt;data &gt;= root-&gt;left-&gt;data;&#10;    return (root-&gt;data &gt;= root-&gt;left-&gt;data &amp;&amp; root-&gt;data &gt;= root-&gt;right-&gt;data) &amp;&amp; isMaxOrder(root-&gt;left) &amp;&amp; isMaxOrder(root-&gt;right);&#10;}&#10;bool isHeap(struct Node* tree) {&#10;    int count = countNodes(tree);&#10;    return isCBT(tree, 0, count) &amp;&amp; isMaxOrder(tree);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
