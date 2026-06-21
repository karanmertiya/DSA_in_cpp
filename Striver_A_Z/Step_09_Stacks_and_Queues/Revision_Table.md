# Step 09 Stacks and Queues Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 20%;">Example & Constraints</th>
      <th style="width: 10%;">Complexity</th>
      <th style="width: 20%;">Approach & Dependencies</th>
      <th style="width: 30%;">Logic & Edge Cases</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="1">1</td>
      <td rowspan="1">Sq 01 Valid Parentheses<br><br></b> <a href="https://leetcode.com/problems/valid-parentheses/" target="_blank">LeetCode 20</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "()[]{}"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><b>Dependencies:</b> <code>std::stack</code></td>
      <td><b>Edge Cases:</b> <b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 02 Next Greater Element I<br><br></b> <a href="https://leetcode.com/problems/next-greater-element-i/" target="_blank">LeetCode 496</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums1 = [4,1,2], nums2 = [1,3,4,2]<br><b>Output:</b> [-1,3,-1]</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N)</td>
      <td>Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.<br><br><b>Dependencies:</b> <code>std::stack</code>, <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>No greater element:</b> If stack becomes empty after popping smaller elements, there is no NGE, store `-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    std::stack&lt;int&gt; st;&#10;    for(int i = nums2.size() - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= nums2[i]) st.pop();&#10;        if(st.empty()) mpp[nums2[i]] = -1;&#10;        else mpp[nums2[i]] = st.top();&#10;        st.push(nums2[i]);&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    for(int num : nums1) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sq 03 Min Stack<br><br></b> <a href="https://leetcode.com/problems/min-stack/" target="_blank">LeetCode 155</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td rowspan="1"><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td>Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sq 04 Largest Rectangle In Histogram<br><br></b> <a href="https://leetcode.com/problems/largest-rectangle-in-histogram/" target="_blank">LeetCode 84</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> heights = [2,1,5,6,2,3]<br><b>Output:</b> 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sq 05 Celebrity Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers or Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Push all elements (0 to N-1) into a stack. Pop two elements `A` and `B`. If `A` knows `B`, `A` cannot be a celebrity, push `B` back. If `A` does not know `B`, `B` cannot be a celebrity, push `A` back. The remaining element is a potential celebrity. Verify it by checking if everyone knows it and it knows no one.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int celebrity(vector&lt;vector&lt;int&gt; &gt;&amp; M, int n) {&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; n; i++) st.push(i);&#10;    while(st.size() &gt; 1) {&#10;        int a = st.top(); st.pop();&#10;        int b = st.top(); st.pop();&#10;        if(M[a][b] == 1) st.push(b);&#10;        else st.push(a);&#10;    }&#10;    if(st.empty()) return -1;&#10;    int pot = st.top();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i != pot &amp;&amp; (M[pot][i] == 1 || M[i][pot] == 0)) return -1;&#10;    }&#10;    return pot;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sq 06 Next Smaller Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/fab3281cefac7140ca15e21505beddf7e4323e08/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from right to left. Use a monotonic stack. Pop elements from the stack that are greater than or equal to the current element. The top of the stack is the next smaller element. Push the current element to the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; help_classmate(vector&lt;int&gt; arr, int n) {&#10;    vector&lt;int&gt; ans(n, -1);&#10;    stack&lt;int&gt; s;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!s.empty() &amp;&amp; s.top() &gt;= arr[i]) s.pop();&#10;        if(!s.empty()) ans[i] = s.top();&#10;        s.push(arr[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Sq 07 Maximal Rectangle<br><br></b> <a href="https://leetcode.com/problems/maximal-rectangle/" target="_blank">LeetCode 85</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Largest Rectangle in Histogram reduction.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(cols)</td>
      <td>Treat each row as the base of a histogram. The height of each bar is the number of consecutive 1s above it. Apply the Largest Rectangle in Histogram algorithm for each row and maintain the maximum area.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; s;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!s.empty() &amp;&amp; (i == n || heights[s.top()] &gt;= heights[i])) {&#10;            int height = heights[s.top()];&#10;            s.pop();&#10;            int width = s.empty() ? i : i - s.top() - 1;&#10;            maxArea = max(maxArea, height * width);&#10;        }&#10;        s.push(i);&#10;    }&#10;    return maxArea;&#10;}&#10;int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int rows = matrix.size(), cols = matrix[0].size();&#10;    vector&lt;int&gt; heights(cols, 0);&#10;    int maxArea = 0;&#10;    for(int i = 0; i &lt; rows; i++) {&#10;        for(int j = 0; j &lt; cols; j++) {&#10;            if(matrix[i][j] == &#x27;1&#x27;) heights[j]++;&#10;            else heights[j] = 0;&#10;        }&#10;        maxArea = max(maxArea, largestRectangleArea(heights));&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Sq 08 Online Stock Span<br><br></b> <a href="https://leetcode.com/problems/online-stock-span/" target="_blank">LeetCode 901</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td>Use a stack of pairs `(price, span)`. When a new price comes in, initialize its span to 1. Pop elements from the stack while the top element's price is `<= price`, adding their spans to the current span. Push `(price, span)` to the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class StockSpanner {&#10;    stack&lt;pair&lt;int, int&gt;&gt; s;&#10;public:&#10;    StockSpanner() {}&#10;    int next(int price) {&#10;        int span = 1;&#10;        while(!s.empty() &amp;&amp; s.top().first &lt;= price) {&#10;            span += s.top().second;&#10;            s.pop();&#10;        }&#10;        s.push({price, span});&#10;        return span;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Sq 09 Rotten Oranges<br><br></b> <a href="https://leetcode.com/problems/rotting-oranges/" target="_blank">LeetCode 994</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> BFS.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(rows * cols)</td>
      <td>Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.<br><br><b>Dependencies:</b> Queue</td>
      <td><b>Edge Cases:</b> Grid without fresh oranges<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int orangesRotting(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    int vis[n][m];&#10;    int cntFresh = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == 2) {&#10;                q.push({{i, j}, 0});&#10;                vis[i][j] = 2;&#10;            } else {&#10;                vis[i][j] = 0;&#10;            }&#10;            if(grid[i][j] == 1) cntFresh++;&#10;        }&#10;    }&#10;    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;&#10;    while(!q.empty()) {&#10;        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;&#10;        tm = max(tm, t); q.pop();&#10;        for(int i = 0; i &lt; 4; i++) {&#10;            int nrow = r + drow[i], ncol = c + dcol[i];&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; vis[nrow][ncol] != 2 &amp;&amp; grid[nrow][ncol] == 1) {&#10;                q.push({{nrow, ncol}, t + 1});&#10;                vis[nrow][ncol] = 2;&#10;                cnt++;&#10;            }&#10;        }&#10;    }&#10;    if(cnt != cntFresh) return -1;&#10;    return tm;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
