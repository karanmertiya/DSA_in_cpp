# 07 Stacks and Queues Revision Table

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
      <td rowspan="1">Sw 01 Sliding Window Maximum<br><br></b> <a href="https://leetcode.com/problems/sliding-window-maximum/" target="_blank">LeetCode 239</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Apna College, Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Use a deque to store indices. The deque maintains elements in decreasing order. Remove elements from the back if they are smaller than the current element. Remove elements from the front if they are out of the window. The front element is the maximum of the current window.<br><br><b>Dependencies:</b> <code>#include <deque></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(nums[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 02 Valid Parentheses<br><br></b> <a href="https://leetcode.com/problems/valid-parentheses/" target="_blank">LeetCode 20</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet, Apna College</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "()[]{}"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><b>Dependencies:</b> <code>std::stack</code></td>
      <td><b>Edge Cases:</b> <b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
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
      <td rowspan="1">Sq 05 Reverse A String Using Stack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Push and pop.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Push all characters of the string into a stack. Then pop them out one by one. The popped characters will be in reversed order.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">char* reverse(char *S, int len) {&#10;    stack&lt;char&gt; st;&#10;    for(int i = 0; i &lt; len; i++) {&#10;        st.push(S[i]);&#10;    }&#10;    for(int i = 0; i &lt; len; i++) {&#10;        S[i] = st.top();&#10;        st.pop();&#10;    }&#10;    return S;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sq 06 Design A Stack That Supports Getmin<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/special-stack/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Formula approach.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>To achieve O(1) space, when pushing `x < minEle`, push `2 * x - minEle` and update `minEle = x`. When popping `y`, if `y < minEle`, then `minEle = 2 * minEle - y`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minEle;&#10;void push(stack&lt;int&gt;&amp; s, int a){&#10;    if(s.empty()) { s.push(a); minEle = a; }&#10;    else if(a &lt; minEle) { s.push(2 * a - minEle); minEle = a; }&#10;    else { s.push(a); }&#10;}&#10;bool isFull(stack&lt;int&gt;&amp; s, int n){&#10;    return s.size() == n;&#10;}&#10;bool isEmpty(stack&lt;int&gt;&amp; s){&#10;    return s.empty();&#10;}&#10;int pop(stack&lt;int&gt;&amp; s){&#10;    if(s.empty()) return -1;&#10;    int top = s.top();&#10;    s.pop();&#10;    if(top &lt; minEle) {&#10;        int prevMin = minEle;&#10;        minEle = 2 * minEle - top;&#10;        return prevMin;&#10;    }&#10;    return top;&#10;}&#10;int getMin(stack&lt;int&gt;&amp; s){&#10;    return minEle;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Sq 07 Next Greater Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Decreasing stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from right to left. Use a stack to keep track of elements. Pop from the stack while the top element is less than or equal to the current element. If stack is empty, NGE is -1, else it's the stack top. Push current element.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; nextLargerElement(vector&lt;long long&gt; arr, int n){&#10;    vector&lt;long long&gt; res(n);&#10;    stack&lt;long long&gt; st;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= arr[i]) st.pop();&#10;        if(st.empty()) res[i] = -1;&#10;        else res[i] = st.top();&#10;        st.push(arr[i]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Sq 08 Celebrity Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers or Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Push all elements (0 to N-1) into a stack. Pop two elements `A` and `B`. If `A` knows `B`, `A` cannot be a celebrity, push `B` back. If `A` does not know `B`, `B` cannot be a celebrity, push `A` back. The remaining element is a potential celebrity. Verify it by checking if everyone knows it and it knows no one.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int celebrity(vector&lt;vector&lt;int&gt; &gt;&amp; M, int n) {&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; n; i++) st.push(i);&#10;    while(st.size() &gt; 1) {&#10;        int a = st.top(); st.pop();&#10;        int b = st.top(); st.pop();&#10;        if(M[a][b] == 1) st.push(b);&#10;        else st.push(a);&#10;    }&#10;    if(st.empty()) return -1;&#10;    int pot = st.top();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i != pot &amp;&amp; (M[pot][i] == 1 || M[i][pot] == 0)) return -1;&#10;    }&#10;    return pot;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Sq 09 Arithmetic Expression Evaluation<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/arithmetic-expression-evaluation/0" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Two stacks (operands and operators).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use two stacks: one for numbers and one for operators. Process the expression character by character. If it's a number, push to numbers stack. If it's `(`, push to operators stack. If it's `)`, solve until `(`. If it's an operator, solve while top of operators stack has same or greater precedence, then push.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int precedence(char op) {&#10;    if(op == &#x27;+&#x27;||op == &#x27;-&#x27;) return 1;&#10;    if(op == &#x27;*&#x27;||op == &#x27;/&#x27;) return 2;&#10;    return 0;&#10;}&#10;int applyOp(int a, int b, char op) {&#10;    switch(op){ &#10;        case &#x27;+&#x27;: return a + b;&#10;        case &#x27;-&#x27;: return a - b;&#10;        case &#x27;*&#x27;: return a * b;&#10;        case &#x27;/&#x27;: return a / b;&#10;    }&#10;    return 0;&#10;}&#10;int evaluate(string tokens){&#10;    int i;&#10;    stack &lt;int&gt; values;&#10;    stack &lt;char&gt; ops;&#10;    for(i = 0; i &lt; tokens.length(); i++){&#10;        if(tokens[i] == &#x27; &#x27;) continue;&#10;        else if(tokens[i] == &#x27;(&#x27;){&#10;            ops.push(tokens[i]);&#10;        } else if(isdigit(tokens[i])){&#10;            int val = 0;&#10;            while(i &lt; tokens.length() &amp;&amp; isdigit(tokens[i])) {&#10;                val = (val*10) + (tokens[i]-&#x27;0&#x27;);&#10;                i++;&#10;            }&#10;            values.push(val);&#10;            i--;&#10;        } else if(tokens[i] == &#x27;)&#x27;) {&#10;            while(!ops.empty() &amp;&amp; ops.top() != &#x27;(&#x27;) {&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            if(!ops.empty()) ops.pop();&#10;        } else {&#10;            while(!ops.empty() &amp;&amp; precedence(ops.top()) &gt;= precedence(tokens[i])){&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            ops.push(tokens[i]);&#10;        }&#10;    }&#10;    while(!ops.empty()){&#10;        int val2 = values.top(); values.pop();&#10;        int val1 = values.top(); values.pop();&#10;        char op = ops.top(); ops.pop();&#10;        values.push(applyOp(val1, val2, op));&#10;    }&#10;    return values.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Sq 10 Evaluation Of Postfix Expression<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Stack of operands.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate through the string. If it's a number, push it to stack. If it's an operator, pop two numbers from stack, apply the operator, and push the result back to stack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evaluatePostfix(string S) {&#10;    stack&lt;int&gt; st;&#10;    for(char c : S) {&#10;        if(isdigit(c)) {&#10;            st.push(c - &#x27;0&#x27;);&#10;        } else {&#10;            int op2 = st.top(); st.pop();&#10;            int op1 = st.top(); st.pop();&#10;            if(c == &#x27;+&#x27;) st.push(op1 + op2);&#10;            else if(c == &#x27;-&#x27;) st.push(op1 - op2);&#10;            else if(c == &#x27;*&#x27;) st.push(op1 * op2);&#10;            else if(c == &#x27;/&#x27;) st.push(op1 / op2);&#10;        }&#10;    }&#10;    return st.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Sq 11 Insert An Element At Its Bottom In A Given Stack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Recursive push.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use recursion. If the stack is empty, push the element. Otherwise, pop the top element, recursively call the function, and then push the popped element back.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">stack&lt;int&gt; insertAtBottom(stack&lt;int&gt; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return St;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    St = insertAtBottom(St, X);&#10;    St.push(top);&#10;    return St;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Sq 12 Reverse A Stack Using Recursion<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-stack/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Recursive pop and insertAtBottom.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Recursively pop all elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `insertAtBottom` to push the elements at the bottom.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertAtBottom(stack&lt;int&gt;&amp; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    insertAtBottom(St, X);&#10;    St.push(top);&#10;}&#10;void Reverse(stack&lt;int&gt; &amp;St) {&#10;    if(St.empty()) return;&#10;    int top = St.top();&#10;    St.pop();&#10;    Reverse(St);&#10;    insertAtBottom(St, top);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Sq 13 Maximum Rectangular Area In A Histogram<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Next Smaller Element on left and right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a stack to find Next Smaller Element (NSE) and Previous Smaller Element (PSE) for each bar. Then, the width of the rectangle with bar `i` as the minimum height is `NSE[i] - PSE[i] - 1`. The area is `height[i] * width`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long getMaxArea(long long arr[], int n) {&#10;    stack&lt;int&gt; st;&#10;    long long max_area = 0;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || arr[st.top()] &gt;= arr[i])) {&#10;            long long height = arr[st.top()];&#10;            st.pop();&#10;            long long width = st.empty() ? i : i - st.top() - 1;&#10;            max_area = max(max_area, height * width);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Sq 14 Next Smaller Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/fab3281cefac7140ca15e21505beddf7e4323e08/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from right to left. Use a monotonic stack. Pop elements from the stack that are greater than or equal to the current element. The top of the stack is the next smaller element. Push the current element to the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; help_classmate(vector&lt;int&gt; arr, int n) {&#10;    vector&lt;int&gt; ans(n, -1);&#10;    stack&lt;int&gt; s;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!s.empty() &amp;&amp; s.top() &gt;= arr[i]) s.pop();&#10;        if(!s.empty()) ans[i] = s.top();&#10;        s.push(arr[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Sq 15 Maximal Rectangle<br><br></b> <a href="https://leetcode.com/problems/maximal-rectangle/" target="_blank">LeetCode 85</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Largest Rectangle in Histogram reduction.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(cols)</td>
      <td>Treat each row as the base of a histogram. The height of each bar is the number of consecutive 1s above it. Apply the Largest Rectangle in Histogram algorithm for each row and maintain the maximum area.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; s;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!s.empty() &amp;&amp; (i == n || heights[s.top()] &gt;= heights[i])) {&#10;            int height = heights[s.top()];&#10;            s.pop();&#10;            int width = s.empty() ? i : i - s.top() - 1;&#10;            maxArea = max(maxArea, height * width);&#10;        }&#10;        s.push(i);&#10;    }&#10;    return maxArea;&#10;}&#10;int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int rows = matrix.size(), cols = matrix[0].size();&#10;    vector&lt;int&gt; heights(cols, 0);&#10;    int maxArea = 0;&#10;    for(int i = 0; i &lt; rows; i++) {&#10;        for(int j = 0; j &lt; cols; j++) {&#10;            if(matrix[i][j] == &#x27;1&#x27;) heights[j]++;&#10;            else heights[j] = 0;&#10;        }&#10;        maxArea = max(maxArea, largestRectangleArea(heights));&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Sq 16 Rotten Oranges<br><br></b> <a href="https://leetcode.com/problems/rotting-oranges/" target="_blank">LeetCode 994</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> BFS.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(rows * cols)</td>
      <td>Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.<br><br><b>Dependencies:</b> Queue</td>
      <td><b>Edge Cases:</b> Grid without fresh oranges<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int orangesRotting(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    int vis[n][m];&#10;    int cntFresh = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == 2) {&#10;                q.push({{i, j}, 0});&#10;                vis[i][j] = 2;&#10;            } else {&#10;                vis[i][j] = 0;&#10;            }&#10;            if(grid[i][j] == 1) cntFresh++;&#10;        }&#10;    }&#10;    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;&#10;    while(!q.empty()) {&#10;        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;&#10;        tm = max(tm, t); q.pop();&#10;        for(int i = 0; i &lt; 4; i++) {&#10;            int nrow = r + drow[i], ncol = c + dcol[i];&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; vis[nrow][ncol] != 2 &amp;&amp; grid[nrow][ncol] == 1) {&#10;                q.push({{nrow, ncol}, t + 1});&#10;                vis[nrow][ncol] = 2;&#10;                cnt++;&#10;            }&#10;        }&#10;    }&#10;    if(cnt != cntFresh) return -1;&#10;    return tm;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
