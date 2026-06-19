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
  </tbody>
</table>
