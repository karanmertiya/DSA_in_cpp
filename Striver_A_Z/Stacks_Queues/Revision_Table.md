# Stacks Queues Revision Table

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
      <td rowspan="1">Sq 02 Valid Parentheses<br><br></b> <a href='https://leetcode.com/problems/valid-parentheses/' target='_blank'>LeetCode 20</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = "()[]{}", Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>std::stack</code></td>
      <td><b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.</td>
      <td><b>Explanation:</b> Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;stack&gt;&#10;bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 03 Next Greater Element I<br><br></b> <a href='https://leetcode.com/problems/next-greater-element-i/' target='_blank'>LeetCode 496</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums1 = [4,1,2], nums2 = [1,3,4,2], Output: [-1,3,-1]</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N)</td>
      <td><code>std::stack</code>, <code>std::unordered_map</code></td>
      <td><b>No greater element:</b> If stack becomes empty after popping smaller elements, there is no NGE, store `-1`.</td>
      <td><b>Explanation:</b> Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;stack&gt;&#10;#include &lt;unordered_map&gt;&#10;std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    std::stack&lt;int&gt; st;&#10;    for(int i = nums2.size() - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= nums2[i]) st.pop();&#10;        if(st.empty()) mpp[nums2[i]] = -1;&#10;        else mpp[nums2[i]] = st.top();&#10;        st.push(nums2[i]);&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    for(int num : nums1) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sq 03 Min Stack<br><br></b> <a href='https://leetcode.com/problems/min-stack/' target='_blank'>LeetCode 155</a></td>
      <td rowspan="1"><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sq 04 Sliding Window Maximum<br><br></b> <a href='https://leetcode.com/problems/sliding-window-maximum/' target='_blank'>LeetCode 239</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [1,3,-1,-3,5,3,6,7], k = 3, Output: [3,3,5,5,6,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><code>#include <deque></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Deque. Store indices in a double-ended queue. Maintain elements in strictly decreasing order. Pop front if it's out of window bounds. Add nums[dq.front()] to answer once window reaches size k.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    deque&lt;int&gt; dq;&#10;    vector&lt;int&gt; ans;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i-k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k-1) ans.push_back(nums[dq.front()]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sq 05 Lru Cache<br><br></b> <a href='https://leetcode.com/problems/lru-cache/' target='_blank'>LeetCode 146</a></td>
      <td rowspan="1"><b>Example 1:</b> Design question.</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(Capacity)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Hash Map and a Doubly Linked List. The Map stores `key -> Node*`. The DLL maintains recency (head is most recent, tail is least recent). Update DLL pointers on access/insert.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class LRUCache {&#10;    struct Node {&#10;        int key, val;&#10;        Node *prev, *next;&#10;        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}&#10;    };&#10;    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);&#10;    int cap;&#10;    unordered_map&lt;int, Node*&gt; m;&#10;    void addNode(Node* newnode) {&#10;        Node* temp = head-&gt;next;&#10;        newnode-&gt;next = temp; newnode-&gt;prev = head;&#10;        head-&gt;next = newnode; temp-&gt;prev = newnode;&#10;    }&#10;    void deleteNode(Node* delnode) {&#10;        Node* delprev = delnode-&gt;prev, *delnext = delnode-&gt;next;&#10;        delprev-&gt;next = delnext; delnext-&gt;prev = delprev;&#10;    }&#10;public:&#10;    LRUCache(int capacity) {&#10;        cap = capacity; head-&gt;next = tail; tail-&gt;prev = head;&#10;    }&#10;    int get(int key) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* resnode = m[key];&#10;            int res = resnode-&gt;val;&#10;            m.erase(key); deleteNode(resnode); addNode(resnode);&#10;            m[key] = head-&gt;next;&#10;            return res;&#10;        }&#10;        return -1;&#10;    }&#10;    void put(int key, int value) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* existing = m[key];&#10;            m.erase(key); deleteNode(existing);&#10;        }&#10;        if(m.size() == cap) {&#10;            m.erase(tail-&gt;prev-&gt;key); deleteNode(tail-&gt;prev);&#10;        }&#10;        addNode(new Node(key, value));&#10;        m[key] = head-&gt;next;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sq 06 Largest Rectangle In Histogram<br><br></b> <a href='https://leetcode.com/problems/largest-rectangle-in-histogram/' target='_blank'>LeetCode 84</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: heights = [2,1,5,6,2,3], Output: 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
