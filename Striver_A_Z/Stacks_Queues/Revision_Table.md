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
      <td>1</td>
      <td>Sq 02 Valid Parentheses<br><br></b> <a href='https://leetcode.com/problems/valid-parentheses/' target='_blank'>LeetCode 20</a></td>
      <td><b>Example 1:</b> Input: s = "()[]{}", Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>std::stack</code></td>
      <td><b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.</td>
      <td><b>Explanation:</b> Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;stack&gt;&#10;bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Sq 03 Next Greater Element I<br><br></b> <a href='https://leetcode.com/problems/next-greater-element-i/' target='_blank'>LeetCode 496</a></td>
      <td><b>Example 1:</b> Input: nums1 = [4,1,2], nums2 = [1,3,4,2], Output: [-1,3,-1]</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N)</td>
      <td><code>std::stack</code>, <code>std::unordered_map</code></td>
      <td><b>No greater element:</b> If stack becomes empty after popping smaller elements, there is no NGE, store `-1`.</td>
      <td><b>Explanation:</b> Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;stack&gt;&#10;#include &lt;unordered_map&gt;&#10;std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    std::stack&lt;int&gt; st;&#10;    for(int i = nums2.size() - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= nums2[i]) st.pop();&#10;        if(st.empty()) mpp[nums2[i]] = -1;&#10;        else mpp[nums2[i]] = st.top();&#10;        st.push(nums2[i]);&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    for(int num : nums1) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Sq 03 Min Stack<br><br></b> <a href='https://leetcode.com/problems/min-stack/' target='_blank'>LeetCode 155</a></td>
      <td><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Sq 04 Sliding Window Maximum<br><br></b> <a href='https://leetcode.com/problems/sliding-window-maximum/' target='_blank'>LeetCode 239</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,-1,-3,5,3,6,7], k = 3, Output: [3,3,5,5,6,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><code>#include <deque></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Deque. Store indices in a double-ended queue. Maintain elements in strictly decreasing order. Pop front if it's out of window bounds. Add nums[dq.front()] to answer once window reaches size k.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    deque&lt;int&gt; dq;&#10;    vector&lt;int&gt; ans;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i-k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k-1) ans.push_back(nums[dq.front()]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Sq 05 Lru Cache<br><br></b> <a href='https://leetcode.com/problems/lru-cache/' target='_blank'>LeetCode 146</a></td>
      <td><b>Example 1:</b> Design question.</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(Capacity)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Hash Map and a Doubly Linked List. The Map stores `key -> Node*`. The DLL maintains recency (head is most recent, tail is least recent). Update DLL pointers on access/insert.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class LRUCache {&#10;    struct Node {&#10;        int key, val;&#10;        Node *prev, *next;&#10;        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}&#10;    };&#10;    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);&#10;    int cap;&#10;    unordered_map&lt;int, Node*&gt; m;&#10;    void addNode(Node* newnode) {&#10;        Node* temp = head-&gt;next;&#10;        newnode-&gt;next = temp; newnode-&gt;prev = head;&#10;        head-&gt;next = newnode; temp-&gt;prev = newnode;&#10;    }&#10;    void deleteNode(Node* delnode) {&#10;        Node* delprev = delnode-&gt;prev, *delnext = delnode-&gt;next;&#10;        delprev-&gt;next = delnext; delnext-&gt;prev = delprev;&#10;    }&#10;public:&#10;    LRUCache(int capacity) {&#10;        cap = capacity; head-&gt;next = tail; tail-&gt;prev = head;&#10;    }&#10;    int get(int key) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* resnode = m[key];&#10;            int res = resnode-&gt;val;&#10;            m.erase(key); deleteNode(resnode); addNode(resnode);&#10;            m[key] = head-&gt;next;&#10;            return res;&#10;        }&#10;        return -1;&#10;    }&#10;    void put(int key, int value) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* existing = m[key];&#10;            m.erase(key); deleteNode(existing);&#10;        }&#10;        if(m.size() == cap) {&#10;            m.erase(tail-&gt;prev-&gt;key); deleteNode(tail-&gt;prev);&#10;        }&#10;        addNode(new Node(key, value));&#10;        m[key] = head-&gt;next;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Sq 06 Largest Rectangle In Histogram<br><br></b> <a href='https://leetcode.com/problems/largest-rectangle-in-histogram/' target='_blank'>LeetCode 84</a></td>
      <td><b>Example 1:</b> Input: heights = [2,1,5,6,2,3], Output: 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Sq 18 Next Smaller Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/fab3281cefac7140ca15e21505beddf7e4323e08/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from right to left. Use a monotonic stack. Pop elements from the stack that are greater than or equal to the current element. The top of the stack is the next smaller element. Push the current element to the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; help_classmate(vector&lt;int&gt; arr, int n) {&#10;    vector&lt;int&gt; ans(n, -1);&#10;    stack&lt;int&gt; s;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!s.empty() &amp;&amp; s.top() &gt;= arr[i]) s.pop();&#10;        if(!s.empty()) ans[i] = s.top();&#10;        s.push(arr[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Sq 19 Lru Cache<br><br></b> <a href='https://leetcode.com/problems/lru-cache/' target='_blank'>LeetCode 146</a></td>
      <td><b>Example 1:</b> Doubly Linked List + Hash Map.</td>
      <td><b>Time:</b> O(1) for get and put<br><b>Space:</b> O(Capacity)</td>
      <td>Hash Map, Doubly Linked List</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map to store keys to Node pointers. Use a doubly linked list to track the usage history. The head of the DLL represents the most recently used, and the tail represents the least recently used. On `get` or `put`, move the accessed node to the head. If capacity is exceeded, remove the node before the tail.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class LRUCache {&#10;    struct Node {&#10;        int key, val;&#10;        Node *prev, *next;&#10;        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}&#10;    };&#10;    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);&#10;    int cap;&#10;    unordered_map&lt;int, Node*&gt; m;&#10;    void addNode(Node* newnode) {&#10;        Node* temp = head-&gt;next;&#10;        newnode-&gt;next = temp;&#10;        newnode-&gt;prev = head;&#10;        head-&gt;next = newnode;&#10;        temp-&gt;prev = newnode;&#10;    }&#10;    void deleteNode(Node* delnode) {&#10;        Node* delprev = delnode-&gt;prev;&#10;        Node* delnext = delnode-&gt;next;&#10;        delprev-&gt;next = delnext;&#10;        delnext-&gt;prev = delprev;&#10;    }&#10;public:&#10;    LRUCache(int capacity) {&#10;        cap = capacity;&#10;        head-&gt;next = tail;&#10;        tail-&gt;prev = head;&#10;    }&#10;    int get(int key) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* resnode = m[key];&#10;            int res = resnode-&gt;val;&#10;            m.erase(key);&#10;            deleteNode(resnode);&#10;            addNode(resnode);&#10;            m[key] = head-&gt;next;&#10;            return res;&#10;        }&#10;        return -1;&#10;    }&#10;    void put(int key, int value) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* existingnode = m[key];&#10;            m.erase(key);&#10;            deleteNode(existingnode);&#10;        }&#10;        if(m.size() == cap) {&#10;            m.erase(tail-&gt;prev-&gt;key);&#10;            deleteNode(tail-&gt;prev);&#10;        }&#10;        addNode(new Node(key, value));&#10;        m[key] = head-&gt;next;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Sq 20 Lfu Cache<br><br></b> <a href='https://leetcode.com/problems/lfu-cache/' target='_blank'>LeetCode 460</a></td>
      <td><b>Example 1:</b> Hash Maps + Doubly Linked Lists.</td>
      <td><b>Time:</b> O(1) for get and put<br><b>Space:</b> O(Capacity)</td>
      <td>Hash Maps, Doubly Linked List</td>
      <td>-</td>
      <td><b>Explanation:</b> Maintain a `minFreq` variable. Use one hash map to map `key` to its Node. Use another hash map to map `frequency` to a Doubly Linked List of Nodes with that frequency. When accessing an element, increase its frequency and move it to the corresponding DLL. If capacity is reached, remove the least recently used element from the DLL at `minFreq`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    int key, value, cnt;&#10;    Node *next, *prev;&#10;    Node(int _key, int _value) { key = _key; value = _value; cnt = 1; }&#10;};&#10;struct List {&#10;    int size;&#10;    Node *head, *tail;&#10;    List() { head = new Node(0, 0); tail = new Node(0, 0); head-&gt;next = tail; tail-&gt;prev = head; size = 0; }&#10;    void addFront(Node* node) {&#10;        Node* temp = head-&gt;next;&#10;        node-&gt;next = temp; node-&gt;prev = head;&#10;        head-&gt;next = node; temp-&gt;prev = node;&#10;        size++;&#10;    }&#10;    void removeNode(Node* node) {&#10;        Node* delprev = node-&gt;prev; Node* delnext = node-&gt;next;&#10;        delprev-&gt;next = delnext; delnext-&gt;prev = delprev;&#10;        size--;&#10;    }&#10;};&#10;class LFUCache {&#10;    map&lt;int, Node*&gt; keyNode;&#10;    map&lt;int, List*&gt; freqListMap;&#10;    int maxSizeCache, minFreq, curSize;&#10;public:&#10;    LFUCache(int capacity) { maxSizeCache = capacity; minFreq = 0; curSize = 0; }&#10;    void updateFreqListMap(Node* node) {&#10;        keyNode.erase(node-&gt;key);&#10;        freqListMap[node-&gt;cnt]-&gt;removeNode(node);&#10;        if(node-&gt;cnt == minFreq &amp;&amp; freqListMap[node-&gt;cnt]-&gt;size == 0) minFreq++;&#10;        List* nextHigherFreqList = new List();&#10;        if(freqListMap.find(node-&gt;cnt + 1) != freqListMap.end()) nextHigherFreqList = freqListMap[node-&gt;cnt + 1];&#10;        node-&gt;cnt += 1;&#10;        nextHigherFreqList-&gt;addFront(node);&#10;        freqListMap[node-&gt;cnt] = nextHigherFreqList;&#10;        keyNode[node-&gt;key] = node;&#10;    }&#10;    int get(int key) {&#10;        if(keyNode.find(key) != keyNode.end()) {&#10;            Node* node = keyNode[key]; int val = node-&gt;value;&#10;            updateFreqListMap(node);&#10;            return val;&#10;        }&#10;        return -1;&#10;    }&#10;    void put(int key, int value) {&#10;        if(maxSizeCache == 0) return;&#10;        if(keyNode.find(key) != keyNode.end()) {&#10;            Node* node = keyNode[key]; node-&gt;value = value;&#10;            updateFreqListMap(node);&#10;        } else {&#10;            if(curSize == maxSizeCache) {&#10;                List* list = freqListMap[minFreq];&#10;                keyNode.erase(list-&gt;tail-&gt;prev-&gt;key);&#10;                freqListMap[minFreq]-&gt;removeNode(list-&gt;tail-&gt;prev);&#10;                curSize--;&#10;            }&#10;            curSize++; minFreq = 1;&#10;            List* listFreq = new List();&#10;            if(freqListMap.find(minFreq) != freqListMap.end()) listFreq = freqListMap[minFreq];&#10;            Node* node = new Node(key, value);&#10;            listFreq-&gt;addFront(node);&#10;            keyNode[key] = node;&#10;            freqListMap[minFreq] = listFreq;&#10;        }&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Sq 21 Largest Rectangle In Histogram<br><br></b> <a href='https://leetcode.com/problems/largest-rectangle-in-histogram/' target='_blank'>LeetCode 84</a></td>
      <td><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack to keep track of the indices of the bars in increasing order of height. If the current bar is shorter than the top of the stack, pop bars and calculate the area for each popped bar as the shortest bar. The width is `i - stack.top() - 1`. If stack is empty, width is `i`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; s;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!s.empty() &amp;&amp; (i == n || heights[s.top()] &gt;= heights[i])) {&#10;            int height = heights[s.top()];&#10;            s.pop();&#10;            int width = s.empty() ? i : i - s.top() - 1;&#10;            maxArea = max(maxArea, height * width);&#10;        }&#10;        s.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Sq 22 Maximal Rectangle<br><br></b> <a href='https://leetcode.com/problems/maximal-rectangle/' target='_blank'>LeetCode 85</a></td>
      <td><b>Example 1:</b> Largest Rectangle in Histogram reduction.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(cols)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Treat each row as the base of a histogram. The height of each bar is the number of consecutive 1s above it. Apply the Largest Rectangle in Histogram algorithm for each row and maintain the maximum area.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; s;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!s.empty() &amp;&amp; (i == n || heights[s.top()] &gt;= heights[i])) {&#10;            int height = heights[s.top()];&#10;            s.pop();&#10;            int width = s.empty() ? i : i - s.top() - 1;&#10;            maxArea = max(maxArea, height * width);&#10;        }&#10;        s.push(i);&#10;    }&#10;    return maxArea;&#10;}&#10;int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int rows = matrix.size(), cols = matrix[0].size();&#10;    vector&lt;int&gt; heights(cols, 0);&#10;    int maxArea = 0;&#10;    for(int i = 0; i &lt; rows; i++) {&#10;        for(int j = 0; j &lt; cols; j++) {&#10;            if(matrix[i][j] == &#x27;1&#x27;) heights[j]++;&#10;            else heights[j] = 0;&#10;        }&#10;        maxArea = max(maxArea, largestRectangleArea(heights));&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Sq 23 Online Stock Span<br><br></b> <a href='https://leetcode.com/problems/online-stock-span/' target='_blank'>LeetCode 901</a></td>
      <td><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack of pairs `(price, span)`. When a new price comes in, initialize its span to 1. Pop elements from the stack while the top element's price is `<= price`, adding their spans to the current span. Push `(price, span)` to the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class StockSpanner {&#10;    stack&lt;pair&lt;int, int&gt;&gt; s;&#10;public:&#10;    StockSpanner() {}&#10;    int next(int price) {&#10;        int span = 1;&#10;        while(!s.empty() &amp;&amp; s.top().first &lt;= price) {&#10;            span += s.top().second;&#10;            s.pop();&#10;        }&#10;        s.push({price, span});&#10;        return span;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Sq 24 Celebrity Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two Pointers / Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack or two pointers. If using two pointers: `left = 0`, `right = N - 1`. If `knows(left, right)`, then `left` cannot be the celebrity, so `left++`. Else, `right` cannot be the celebrity, so `right--`. The remaining person `left` is a potential candidate. Verify by checking if `left` knows no one and everyone knows `left`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int celebrity(vector&lt;vector&lt;int&gt; &gt;&amp; M, int n) {&#10;    int left = 0, right = n - 1;&#10;    while(left &lt; right) {&#10;        if(M[left][right] == 1) left++;&#10;        else right--;&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i != left &amp;&amp; (M[left][i] == 1 || M[i][left] == 0)) return -1;&#10;    }&#10;    return left;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Sq 25 Rotten Oranges<br><br></b> <a href='https://leetcode.com/problems/rotting-oranges/' target='_blank'>LeetCode 994</a></td>
      <td><b>Example 1:</b> BFS.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(rows * cols)</td>
      <td>Queue</td>
      <td>Grid without fresh oranges</td>
      <td><b>Explanation:</b> Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int orangesRotting(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    int vis[n][m];&#10;    int cntFresh = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == 2) {&#10;                q.push({{i, j}, 0});&#10;                vis[i][j] = 2;&#10;            } else {&#10;                vis[i][j] = 0;&#10;            }&#10;            if(grid[i][j] == 1) cntFresh++;&#10;        }&#10;    }&#10;    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;&#10;    while(!q.empty()) {&#10;        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;&#10;        tm = max(tm, t); q.pop();&#10;        for(int i = 0; i &lt; 4; i++) {&#10;            int nrow = r + drow[i], ncol = c + dcol[i];&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; vis[nrow][ncol] != 2 &amp;&amp; grid[nrow][ncol] == 1) {&#10;                q.push({{nrow, ncol}, t + 1});&#10;                vis[nrow][ncol] = 2;&#10;                cnt++;&#10;            }&#10;        }&#10;    }&#10;    if(cnt != cntFresh) return -1;&#10;    return tm;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Sq 26 Sliding Window Maximum<br><br></b> <a href='https://leetcode.com/problems/sliding-window-maximum/' target='_blank'>LeetCode 239</a></td>
      <td><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Deque</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a double-ended queue (deque) to store indices. Maintain indices in the deque such that the elements they correspond to are in decreasing order. The front of the deque will always be the maximum for the current window. Remove indices from the front if they are out of the window (`i - k`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    deque&lt;int&gt; dq;&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt; nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) ans.push_back(nums[dq.front()]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
