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
      <td rowspan="1">1</td>
      <td rowspan="1">Heap 01 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [3,2,1,5,6,4], k = 2, Output: 5<br><br><b>Note (Constraint):</b> Can you solve it without sorting?</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td><code>std::priority_queue</code> / <code>heapq</code></td>
      <td><b>Min-Heap sizing:</b> By strictly keeping the size to `k`, the `k` largest elements are trapped inside, with the smallest of them right at the top.</td>
      <td><b>Explanation:</b> Use a Min-Heap of size K. When the heap exceeds size K, pop the minimum element. The top of the heap will be the Kth largest.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;&#10;int findKthLargest(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::priority_queue&lt;int, std::vector&lt;int&gt;, std::greater&lt;int&gt;&gt; minHeap;&#10;    for(int num : nums) {&#10;        minHeap.push(num);&#10;        if(minHeap.size() &gt; k) {&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    return minHeap.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Heap 02 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: lists = [[1,4,5],[1,3,4],[2,6]], Output: [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td>Custom Comparator</td>
      <td><b>Pointer Compare:</b> Priority queues need a custom comparator to sort `ListNode*` by their `val`.</td>
      <td><b>Explanation:</b> Push the head of each list into a Min-Heap. Repeatedly pop the smallest node, attach it to the result list, and push its `next` node into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;queue&gt;&#10;&#10;struct Compare {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;&#10;ListNode* mergeKLists(std::vector&lt;ListNode*&gt;&amp; lists) {&#10;    std::priority_queue&lt;ListNode*, std::vector&lt;ListNode*&gt;, Compare&gt; pq;&#10;    for (auto list : lists) {&#10;        if (list) pq.push(list);&#10;    }&#10;    &#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    &#10;    while (!pq.empty()) {&#10;        ListNode* node = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = node;&#10;        tail = tail-&gt;next;&#10;        if (node-&gt;next) pq.push(node-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Heap 03 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,1,1,2,2,3], k = 2, Output: [1,2]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td><code>std::priority_queue</code>, <code>heapq</code></td>
      <td><b>Min-Heap capacity:</b> If heap size exceeds `k`, pop the top (which is the element with the lowest frequency currently in the heap).</td>
      <td><b>Explanation:</b> Use a Hash Map to count frequencies. Use a Min-Heap of size `k` to keep track of the top `k` elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;#include &lt;queue&gt;&#10;std::vector&lt;int&gt; topKFrequent(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    std::priority_queue&lt;std::pair&lt;int, int&gt;, std::vector&lt;std::pair&lt;int, int&gt;&gt;, std::greater&lt;std::pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto it : mpp) {&#10;        pq.push({it.second, it.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Heaps 04 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: lists=[[1,4,5],[1,3,4],[2,6]], Output: [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td><b>Custom Comparator:</b> In C++, define a struct to compare ListNode* values.</td>
      <td><b>Explanation:</b> Use a Min-Heap. Push the head of each linked list into the Priority Queue. Continuously pop the smallest, append it to result, and push its `next` node into the PQ.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct compare {&#10;    bool operator()(const ListNode* l, const ListNode* r) { return l-&gt;val &gt; r-&gt;val; }&#10;};&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, compare&gt; pq;&#10;    for(auto l : lists) if(l) pq.push(l);&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(!pq.empty()) {&#10;        tail-&gt;next = pq.top(); pq.pop();&#10;        tail = tail-&gt;next;&#10;        if(tail-&gt;next) pq.push(tail-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Heap 06 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [3,2,1,5,6,4], k = 2. Output: 5</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Min-Heap of size K. Push elements into the heap. If heap size exceeds K, pop the minimum element. The top of the heap at the end is the Kth largest element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(vector&lt;int&gt;&amp; nums, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;    for(int num : nums) {&#10;        minH.push(num);&#10;        if(minH.size() &gt; k) minH.pop();&#10;    }&#10;    return minH.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Heap 07 Kth Smallest Element In A Sorted Matrix<br><br></b> <a href='https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/' target='_blank'>LeetCode 378</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary search on range.</td>
      <td><b>Time:</b> O(N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Binary search on the value range `[matrix[0][0], matrix[n-1][n-1]]`. Count elements less than or equal to `mid` using two pointers (start from bottom-left). If count >= k, search left half, else search right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countLessOrEqual(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int mid, int n) {&#10;    int count = 0, row = n - 1, col = 0;&#10;    while(row &gt;= 0 &amp;&amp; col &lt; n) {&#10;        if(matrix[row][col] &lt;= mid) { count += row + 1; col++; }&#10;        else row--;&#10;    }&#10;    return count;&#10;}&#10;int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    int low = matrix[0][0], high = matrix[n-1][n-1];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countLessOrEqual(matrix, mid, n) &gt;= k) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Heap 08 Find Median From Data Stream<br><br></b> <a href='https://leetcode.com/problems/find-median-from-data-stream/' target='_blank'>LeetCode 295</a></td>
      <td rowspan="1"><b>Example 1:</b> Two heaps.</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain two heaps: a max-heap for the smaller half of numbers and a min-heap for the larger half. Balance them such that the max-heap has at most 1 more element than the min-heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxH;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;public:&#10;    void addNum(int num) {&#10;        maxH.push(num);&#10;        minH.push(maxH.top());&#10;        maxH.pop();&#10;        if(maxH.size() &lt; minH.size()) {&#10;            maxH.push(minH.top());&#10;            minH.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        if(maxH.size() &gt; minH.size()) return maxH.top();&#10;        return (maxH.top() + minH.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Heap 09 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> Use Min-Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td><b>Empty lists:</b> Ignore nullptrs.</td>
      <td><b>Explanation:</b> Push the heads of all K lists into a Min-Heap. Pop the smallest node, append it to result, and if it has a next node, push the next node into the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct comp { bool operator()(ListNode* a, ListNode* b) { return a-&gt;val &gt; b-&gt;val; } };&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, comp&gt; pq;&#10;    for(auto head : lists) if(head) pq.push(head);&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(!pq.empty()) {&#10;        ListNode* curr = pq.top(); pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Heap 10 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td rowspan="1"><b>Example 1:</b> Output: elements.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a map. Use a Min-Heap of size K, storing pairs `(freq, num)`. If size > K, pop. Heap will contain the top K elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topKFrequent(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; minH;&#10;    for(auto it : mpp) {&#10;        minH.push({it.second, it.first});&#10;        if(minH.size() &gt; k) minH.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!minH.empty()) {&#10;        ans.push_back(minH.top().second);&#10;        minH.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Heap 11 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td rowspan="1"><b>Example 1:</b> `s = "tree"`. Output: `"eert"`.</td>
      <td><b>Time:</b> O(N log 26)<br><b>Space:</b> O(26)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Hash map to store frequencies, then max-heap to process them in descending order of frequency.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; mpp;&#10;    for(char c : s) mpp[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto it : mpp) pq.push({it.second, it.first});&#10;    string ans = &quot;&quot;;&#10;    while(!pq.empty()) {&#10;        ans += string(pq.top().first, pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Heap 12 Replace Each Array Element By Its Corresponding Rank<br><br></b> <a href='https://leetcode.com/problems/rank-transform-of-an-array/' target='_blank'>LeetCode 1331</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: [40,10,20,30], Output: [4,1,2,3]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <set></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Create a copy of array, sort it, and remove duplicates. Use a hash map to map each unique value to its rank. Replace elements in original array using map.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; arrayRankTransform(vector&lt;int&gt;&amp; arr) {&#10;    set&lt;int&gt; st(arr.begin(), arr.end());&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int rank = 1;&#10;    for(int num : st) mpp[num] = rank++;&#10;    vector&lt;int&gt; ans;&#10;    for(int num : arr) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Heap 13 Task Scheduler<br><br></b> <a href='https://leetcode.com/problems/task-scheduler/' target='_blank'>LeetCode 621</a></td>
      <td rowspan="1"><b>Example 1:</b> Greedy placement.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Find max frequency `max_f`. Calculate idle slots `(max_f - 1) * n`. Iterate remaining frequencies and subtract from idle slots. Return `tasks.length + max(0, idle_slots)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int leastInterval(vector&lt;char&gt;&amp; tasks, int n) {&#10;    vector&lt;int&gt; freq(26, 0);&#10;    int max_f = 0, count_max = 0;&#10;    for(char c : tasks) {&#10;        freq[c - &#x27;A&#x27;]++;&#10;        if(freq[c - &#x27;A&#x27;] &gt; max_f) {&#10;            max_f = freq[c - &#x27;A&#x27;];&#10;            count_max = 1;&#10;        } else if(freq[c - &#x27;A&#x27;] == max_f) count_max++;&#10;    }&#10;    int ans = (max_f - 1) * (n + 1) + count_max;&#10;    return max(ans, (int)tasks.size());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Heap 14 Hand Of Straights<br><br></b> <a href='https://leetcode.com/problems/hand-of-straights/' target='_blank'>LeetCode 846</a></td>
      <td rowspan="1"><b>Example 1:</b> Form consecutive sequences.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a map (TreeMap in C++) to store frequencies. Iterate through map. If a number has count > 0, we must form a group starting from it. Decrement counts of `num, num+1, ..., num+groupSize-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isNStraightHand(vector&lt;int&gt;&amp; hand, int groupSize) {&#10;    if(hand.size() % groupSize != 0) return false;&#10;    map&lt;int, int&gt; mpp;&#10;    for(int card : hand) mpp[card]++;&#10;    for(auto it : mpp) {&#10;        if(it.second &gt; 0) {&#10;            int count = it.second;&#10;            for(int i=0; i&lt;groupSize; i++) {&#10;                if(mpp[it.first + i] &lt; count) return false;&#10;                mpp[it.first + i] -= count;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Heap 15 Design Twitter<br><br></b> <a href='https://leetcode.com/problems/design-twitter/' target='_blank'>LeetCode 355</a></td>
      <td rowspan="1"><b>Example 1:</b> Object oriented design.</td>
      <td><b>Time:</b> O(N log 10)<br><b>Space:</b> O(U + T)</td>
      <td><code>#include <unordered_map>\n#include <unordered_set>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map to map user to their followees. Use another map to map user to their tweets. For news feed, use a Max-Heap to extract the 10 most recent tweets from the user and their followees.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; followers;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets;&#10;    int time = 0;&#10;public:&#10;    Twitter() {}&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int f : followers[userId]) {&#10;            for(auto t : tweets[f]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; ans;&#10;        while(!pq.empty() &amp;&amp; ans.size() &lt; 10) {&#10;            ans.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return ans;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        followers[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        followers[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Heap 24 Kth Largest Element In A Stream<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-a-stream/' target='_blank'>LeetCode 703</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-heap of size K.</td>
      <td><b>Time:</b> O(N log K) for init, O(log K) for add<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a min-heap of size exactly `k`. The top of the min-heap will always represent the kth largest element. For every new element added, if the heap size is less than `k`, push it. If the heap is of size `k` and the new element is greater than the top, pop the top and push the new element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class KthLargest {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    int k;&#10;public:&#10;    KthLargest(int k, vector&lt;int&gt;&amp; nums) {&#10;        this-&gt;k = k;&#10;        for(int num : nums) {&#10;            pq.push(num);&#10;            if(pq.size() &gt; k) pq.pop();&#10;        }&#10;    }&#10;    int add(int val) {&#10;        pq.push(val);&#10;        if(pq.size() &gt; k) pq.pop();&#10;        return pq.top();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Heap 25 Kth Largest Element In An Array<br><br></b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-heap or Quickselect.</td>
      <td><b>Time:</b> O(N log K) Heap, O(N) avg Quickselect<br><b>Space:</b> O(K) Heap, O(1) Quickselect</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Min-heap: Keep a min-heap of size K. The root is the Kth largest. Quickselect: Partition the array like in Quicksort, recursively searching only the partition containing the target index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(vector&lt;int&gt;&amp; nums, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int num : nums) {&#10;        pq.push(num);&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Heap 26 K Closest Points To Origin<br><br></b> <a href='https://leetcode.com/problems/k-closest-points-to-origin/' target='_blank'>LeetCode 973</a></td>
      <td rowspan="1"><b>Example 1:</b> Max-heap of pairs.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a max-heap of size `k` to store pairs of `(distance, point_index)`. Iterate over all points, push into heap. If heap size exceeds `k`, pop the max element. The heap will eventually hold the `k` points with minimum distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; kClosest(vector&lt;vector&lt;int&gt;&gt;&amp; points, int k) {&#10;    priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; points.size(); i++) {&#10;        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];&#10;        pq.push({dist, i});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(points[pq.top().second]);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Heap 27 Top K Frequent Elements<br><br></b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a></td>
      <td rowspan="1"><b>Example 1:</b> Hash map + Min-heap or Bucket sort.</td>
      <td><b>Time:</b> O(N log K) Heap, O(N) Bucket Sort<br><b>Space:</b> O(N)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a hash map. Use a min-heap of size `k` storing pairs of `(frequency, element)`. Or use bucket sort where index is frequency and value is list of elements with that frequency.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topKFrequent(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; counts;&#10;    for(int num : nums) counts[num]++;&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto&amp; p : counts) {&#10;        pq.push({p.second, p.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Heap 28 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td rowspan="1"><b>Example 1:</b> Hash map + Max-heap or Sort.</td>
      <td><b>Time:</b> O(N log M) where M is unique characters<br><b>Space:</b> O(M)</td>
      <td><code>#include <unordered_map>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies of each character. Store pairs of `(frequency, character)` in a max-heap (or sort an array). Construct the result string by popping from the heap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; counts;&#10;    for(char c : s) counts[c]++;&#10;    priority_queue&lt;pair&lt;int, char&gt;&gt; pq;&#10;    for(auto&amp; p : counts) pq.push({p.second, p.first});&#10;    string res = &quot;&quot;;&#10;    while(!pq.empty()) {&#10;        res += string(pq.top().first, pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Heap 29 Find Median From Data Stream<br><br></b> <a href='https://leetcode.com/problems/find-median-from-data-stream/' target='_blank'>LeetCode 295</a></td>
      <td rowspan="1"><b>Example 1:</b> Two heaps (Max-heap for lower half, Min-heap for upper half).</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use two heaps: a max-heap for the smaller half of numbers, and a min-heap for the larger half. Keep the sizes balanced (either equal, or max-heap has 1 more). Median is root of max-heap (odd total) or average of both roots (even total).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxHeap;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minHeap;&#10;public:&#10;    MedianFinder() {}&#10;    void addNum(int num) {&#10;        maxHeap.push(num);&#10;        minHeap.push(maxHeap.top());&#10;        maxHeap.pop();&#10;        if(maxHeap.size() &lt; minHeap.size()) {&#10;            maxHeap.push(minHeap.top());&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        return maxHeap.size() &gt; minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Heap 30 Merge K Sorted Lists<br><br></b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-heap of list nodes.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td><code>#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Push the head of each list into a min-heap. Extract the minimum node, append it to the merged list, and push its next node (if any) into the min-heap. Repeat until heap is empty.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct comp {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;ListNode* mergeKLists(vector&lt;ListNode*&gt;&amp; lists) {&#10;    priority_queue&lt;ListNode*, vector&lt;ListNode*&gt;, comp&gt; pq;&#10;    for(ListNode* node : lists) {&#10;        if(node) pq.push(node);&#10;    }&#10;    ListNode dummy(0);&#10;    ListNode* tail = &amp;dummy;&#10;    while(!pq.empty()) {&#10;        ListNode* curr = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy.next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Heap 31 Task Scheduler<br><br></b> <a href='https://leetcode.com/problems/task-scheduler/' target='_blank'>LeetCode 621</a></td>
      <td rowspan="1"><b>Example 1:</b> Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> See greedy_37_task_scheduler.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Heap 32 Design Twitter<br><br></b> <a href='https://leetcode.com/problems/design-twitter/' target='_blank'>LeetCode 355</a></td>
      <td rowspan="1"><b>Example 1:</b> Heap to merge multiple sorted lists.</td>
      <td><b>Time:</b> O(K log K) for feed where K is 10.<br><b>Space:</b> O(Total Tweets + Follow Relations)</td>
      <td><code>#include <unordered_map>\n#include <unordered_set>\n#include <queue></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a timestamp for tweets. Each user has a list of tweets and a set of followed users. To get the news feed, gather the most recent tweets from the user and all followees using a max-heap (like merging K sorted lists).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    int time;&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; follows;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets; // time, tweetId&#10;public:&#10;    Twitter() { time = 0; }&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int followee : follows[userId]) {&#10;            for(auto t : tweets[followee]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; res;&#10;        for(int i = 0; i &lt; 10 &amp;&amp; !pq.empty(); i++) {&#10;            res.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return res;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        if(followerId != followeeId) follows[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        follows[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Heap 33 Reorganize String<br><br></b> <a href='https://leetcode.com/problems/reorganize-string/' target='_blank'>LeetCode 767</a></td>
      <td rowspan="1"><b>Example 1:</b> Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> See greedy_38_reorganize_string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
  </tbody>
</table>
