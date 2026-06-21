# Day 13 14 Stacks Queues Revision Table

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
      <td>Sw 01 Sliding Window Maximum<br><br></b> <a href="https://leetcode.com/problems/sliding-window-maximum/" target="_blank">LeetCode 239</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Apna College, Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><b>Dependencies:</b> <code>#include <deque></code><br><b>Explanation:</b> Use a deque to store indices. The deque maintains elements in decreasing order. Remove elements from the back if they are smaller than the current element. Remove elements from the front if they are out of the window. The front element is the maximum of the current window.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(nums[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Ll 02 Lru Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lru-cache/" target="_blank">LeetCode 146</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b>Example 1:</b> Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Included for chapter coverage completeness. See sq_31_lru_cache.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Ll 03 Lfu Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lfu-cache/" target="_blank">LeetCode 460</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b>Example 1:</b> Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Included for chapter coverage completeness. See sq_32_lfu_cache.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Sq 04 Valid Parentheses<br><br></b> <a href="https://leetcode.com/problems/valid-parentheses/" target="_blank">LeetCode 20</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> s = "()[]{}"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> <code>std::stack</code><br><b>Explanation:</b> Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Sq 05 Next Greater Element I<br><br></b> <a href="https://leetcode.com/problems/next-greater-element-i/" target="_blank">LeetCode 496</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> nums1 = [4,1,2], nums2 = [1,3,4,2]<br><b>Output:</b> [-1,3,-1]</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> <code>std::stack</code>, <code>std::unordered_map</code><br><b>Explanation:</b> Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    std::stack&lt;int&gt; st;&#10;    for(int i = nums2.size() - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= nums2[i]) st.pop();&#10;        if(st.empty()) mpp[nums2[i]] = -1;&#10;        else mpp[nums2[i]] = st.top();&#10;        st.push(nums2[i]);&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    for(int num : nums1) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Sq 06 Min Stack<br><br></b> <a href="https://leetcode.com/problems/min-stack/" target="_blank">LeetCode 155</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> <code>#include <stack></code><br><b>Explanation:</b> Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Sq 07 Largest Rectangle In Histogram<br><br></b> <a href="https://leetcode.com/problems/largest-rectangle-in-histogram/" target="_blank">LeetCode 84</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Striver A Z, Love Babbar</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> heights = [2,1,5,6,2,3]<br><b>Output:</b> 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> <code>#include <stack></code><br><b>Explanation:</b> Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Sq 08 Online Stock Span<br><br></b> <a href="https://leetcode.com/problems/online-stock-span/" target="_blank">LeetCode 901</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td><b>Dependencies:</b> Stack<br><b>Explanation:</b> Use a stack of pairs `(price, span)`. When a new price comes in, initialize its span to 1. Pop elements from the stack while the top element's price is `<= price`, adding their spans to the current span. Push `(price, span)` to the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class StockSpanner {&#10;    stack&lt;pair&lt;int, int&gt;&gt; s;&#10;public:&#10;    StockSpanner() {}&#10;    int next(int price) {&#10;        int span = 1;&#10;        while(!s.empty() &amp;&amp; s.top().first &lt;= price) {&#10;            span += s.top().second;&#10;            s.pop();&#10;        }&#10;        s.push({price, span});&#10;        return span;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Sq 09 Rotten Oranges<br><br></b> <a href="https://leetcode.com/problems/rotting-oranges/" target="_blank">LeetCode 994</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b>Example 1:</b> BFS.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(rows * cols)</td>
      <td><b>Dependencies:</b> Queue<br><b>Explanation:</b> Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int orangesRotting(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    int vis[n][m];&#10;    int cntFresh = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == 2) {&#10;                q.push({{i, j}, 0});&#10;                vis[i][j] = 2;&#10;            } else {&#10;                vis[i][j] = 0;&#10;            }&#10;            if(grid[i][j] == 1) cntFresh++;&#10;        }&#10;    }&#10;    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;&#10;    while(!q.empty()) {&#10;        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;&#10;        tm = max(tm, t); q.pop();&#10;        for(int i = 0; i &lt; 4; i++) {&#10;            int nrow = r + drow[i], ncol = c + dcol[i];&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; vis[nrow][ncol] != 2 &amp;&amp; grid[nrow][ncol] == 1) {&#10;                q.push({{nrow, ncol}, t + 1});&#10;                vis[nrow][ncol] = 2;&#10;                cnt++;&#10;            }&#10;        }&#10;    }&#10;    if(cnt != cntFresh) return -1;&#10;    return tm;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
