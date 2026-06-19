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
      <td>Sq 03 Min Stack<br><br></b> <a href='https://leetcode.com/problems/min-stack/' target='_blank'>LeetCode 155</a></td>
      <td><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Sq 04 Sliding Window Maximum<br><br></b> <a href='https://leetcode.com/problems/sliding-window-maximum/' target='_blank'>LeetCode 239</a></td>
      <td><b>Example 1:</b> Input: nums = [1,3,-1,-3,5,3,6,7], k = 3, Output: [3,3,5,5,6,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><code>#include <deque></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Deque. Store indices in a double-ended queue. Maintain elements in strictly decreasing order. Pop front if it's out of window bounds. Add nums[dq.front()] to answer once window reaches size k.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    deque&lt;int&gt; dq;&#10;    vector&lt;int&gt; ans;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i-k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k-1) ans.push_back(nums[dq.front()]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Sq 05 Lru Cache<br><br></b> <a href='https://leetcode.com/problems/lru-cache/' target='_blank'>LeetCode 146</a></td>
      <td><b>Example 1:</b> Design question.</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(Capacity)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a Hash Map and a Doubly Linked List. The Map stores `key -> Node*`. The DLL maintains recency (head is most recent, tail is least recent). Update DLL pointers on access/insert.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class LRUCache {&#10;    struct Node {&#10;        int key, val;&#10;        Node *prev, *next;&#10;        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}&#10;    };&#10;    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);&#10;    int cap;&#10;    unordered_map&lt;int, Node*&gt; m;&#10;    void addNode(Node* newnode) {&#10;        Node* temp = head-&gt;next;&#10;        newnode-&gt;next = temp; newnode-&gt;prev = head;&#10;        head-&gt;next = newnode; temp-&gt;prev = newnode;&#10;    }&#10;    void deleteNode(Node* delnode) {&#10;        Node* delprev = delnode-&gt;prev, *delnext = delnode-&gt;next;&#10;        delprev-&gt;next = delnext; delnext-&gt;prev = delprev;&#10;    }&#10;public:&#10;    LRUCache(int capacity) {&#10;        cap = capacity; head-&gt;next = tail; tail-&gt;prev = head;&#10;    }&#10;    int get(int key) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* resnode = m[key];&#10;            int res = resnode-&gt;val;&#10;            m.erase(key); deleteNode(resnode); addNode(resnode);&#10;            m[key] = head-&gt;next;&#10;            return res;&#10;        }&#10;        return -1;&#10;    }&#10;    void put(int key, int value) {&#10;        if(m.find(key) != m.end()) {&#10;            Node* existing = m[key];&#10;            m.erase(key); deleteNode(existing);&#10;        }&#10;        if(m.size() == cap) {&#10;            m.erase(tail-&gt;prev-&gt;key); deleteNode(tail-&gt;prev);&#10;        }&#10;        addNode(new Node(key, value));&#10;        m[key] = head-&gt;next;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Sq 06 Largest Rectangle In Histogram<br><br></b> <a href='https://leetcode.com/problems/largest-rectangle-in-histogram/' target='_blank'>LeetCode 84</a></td>
      <td><b>Example 1:</b> Input: heights = [2,1,5,6,2,3], Output: 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Sq 7 Reverse A String Using Stack<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Push and pop.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Push all characters of the string into a stack. Then pop them out one by one. The popped characters will be in reversed order.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">char* reverse(char *S, int len) {&#10;    stack&lt;char&gt; st;&#10;    for(int i = 0; i &lt; len; i++) {&#10;        st.push(S[i]);&#10;    }&#10;    for(int i = 0; i &lt; len; i++) {&#10;        S[i] = st.top();&#10;        st.pop();&#10;    }&#10;    return S;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Sq 8 Design A Stack That Supports Getmin<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/special-stack/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Formula approach.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> To achieve O(1) space, when pushing `x < minEle`, push `2 * x - minEle` and update `minEle = x`. When popping `y`, if `y < minEle`, then `minEle = 2 * minEle - y`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minEle;&#10;void push(stack&lt;int&gt;&amp; s, int a){&#10;    if(s.empty()) { s.push(a); minEle = a; }&#10;    else if(a &lt; minEle) { s.push(2 * a - minEle); minEle = a; }&#10;    else { s.push(a); }&#10;}&#10;bool isFull(stack&lt;int&gt;&amp; s, int n){&#10;    return s.size() == n;&#10;}&#10;bool isEmpty(stack&lt;int&gt;&amp; s){&#10;    return s.empty();&#10;}&#10;int pop(stack&lt;int&gt;&amp; s){&#10;    if(s.empty()) return -1;&#10;    int top = s.top();&#10;    s.pop();&#10;    if(top &lt; minEle) {&#10;        int prevMin = minEle;&#10;        minEle = 2 * minEle - top;&#10;        return prevMin;&#10;    }&#10;    return top;&#10;}&#10;int getMin(stack&lt;int&gt;&amp; s){&#10;    return minEle;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Sq 9 Next Greater Element<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Decreasing stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from right to left. Use a stack to keep track of elements. Pop from the stack while the top element is less than or equal to the current element. If stack is empty, NGE is -1, else it's the stack top. Push current element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; nextLargerElement(vector&lt;long long&gt; arr, int n){&#10;    vector&lt;long long&gt; res(n);&#10;    stack&lt;long long&gt; st;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= arr[i]) st.pop();&#10;        if(st.empty()) res[i] = -1;&#10;        else res[i] = st.top();&#10;        st.push(arr[i]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Sq 10 Celebrity Problem<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two pointers or Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><code>#include <stack></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Push all elements (0 to N-1) into a stack. Pop two elements `A` and `B`. If `A` knows `B`, `A` cannot be a celebrity, push `B` back. If `A` does not know `B`, `B` cannot be a celebrity, push `A` back. The remaining element is a potential celebrity. Verify it by checking if everyone knows it and it knows no one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int celebrity(vector&lt;vector&lt;int&gt; &gt;&amp; M, int n) {&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; n; i++) st.push(i);&#10;    while(st.size() &gt; 1) {&#10;        int a = st.top(); st.pop();&#10;        int b = st.top(); st.pop();&#10;        if(M[a][b] == 1) st.push(b);&#10;        else st.push(a);&#10;    }&#10;    if(st.empty()) return -1;&#10;    int pot = st.top();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i != pot &amp;&amp; (M[pot][i] == 1 || M[i][pot] == 0)) return -1;&#10;    }&#10;    return pot;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Sq 11 Arithmetic Expression Evaluation<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/arithmetic-expression-evaluation/0' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two stacks (operands and operators).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two stacks: one for numbers and one for operators. Process the expression character by character. If it's a number, push to numbers stack. If it's `(`, push to operators stack. If it's `)`, solve until `(`. If it's an operator, solve while top of operators stack has same or greater precedence, then push.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int precedence(char op) {&#10;    if(op == &#x27;+&#x27;||op == &#x27;-&#x27;) return 1;&#10;    if(op == &#x27;*&#x27;||op == &#x27;/&#x27;) return 2;&#10;    return 0;&#10;}&#10;int applyOp(int a, int b, char op) {&#10;    switch(op){ &#10;        case &#x27;+&#x27;: return a + b;&#10;        case &#x27;-&#x27;: return a - b;&#10;        case &#x27;*&#x27;: return a * b;&#10;        case &#x27;/&#x27;: return a / b;&#10;    }&#10;    return 0;&#10;}&#10;int evaluate(string tokens){&#10;    int i;&#10;    stack &lt;int&gt; values;&#10;    stack &lt;char&gt; ops;&#10;    for(i = 0; i &lt; tokens.length(); i++){&#10;        if(tokens[i] == &#x27; &#x27;) continue;&#10;        else if(tokens[i] == &#x27;(&#x27;){&#10;            ops.push(tokens[i]);&#10;        } else if(isdigit(tokens[i])){&#10;            int val = 0;&#10;            while(i &lt; tokens.length() &amp;&amp; isdigit(tokens[i])) {&#10;                val = (val*10) + (tokens[i]-&#x27;0&#x27;);&#10;                i++;&#10;            }&#10;            values.push(val);&#10;            i--;&#10;        } else if(tokens[i] == &#x27;)&#x27;) {&#10;            while(!ops.empty() &amp;&amp; ops.top() != &#x27;(&#x27;) {&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            if(!ops.empty()) ops.pop();&#10;        } else {&#10;            while(!ops.empty() &amp;&amp; precedence(ops.top()) &gt;= precedence(tokens[i])){&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            ops.push(tokens[i]);&#10;        }&#10;    }&#10;    while(!ops.empty()){&#10;        int val2 = values.top(); values.pop();&#10;        int val1 = values.top(); values.pop();&#10;        char op = ops.top(); ops.pop();&#10;        values.push(applyOp(val1, val2, op));&#10;    }&#10;    return values.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Sq 12 Evaluation Of Postfix Expression<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Stack of operands.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string. If it's a number, push it to stack. If it's an operator, pop two numbers from stack, apply the operator, and push the result back to stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evaluatePostfix(string S) {&#10;    stack&lt;int&gt; st;&#10;    for(char c : S) {&#10;        if(isdigit(c)) {&#10;            st.push(c - &#x27;0&#x27;);&#10;        } else {&#10;            int op2 = st.top(); st.pop();&#10;            int op1 = st.top(); st.pop();&#10;            if(c == &#x27;+&#x27;) st.push(op1 + op2);&#10;            else if(c == &#x27;-&#x27;) st.push(op1 - op2);&#10;            else if(c == &#x27;*&#x27;) st.push(op1 * op2);&#10;            else if(c == &#x27;/&#x27;) st.push(op1 / op2);&#10;        }&#10;    }&#10;    return st.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Sq 13 Insert An Element At Its Bottom In A Given Stack<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive push.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use recursion. If the stack is empty, push the element. Otherwise, pop the top element, recursively call the function, and then push the popped element back.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">stack&lt;int&gt; insertAtBottom(stack&lt;int&gt; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return St;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    St = insertAtBottom(St, X);&#10;    St.push(top);&#10;    return St;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Sq 14 Reverse A Stack Using Recursion<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/reverse-a-stack/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive pop and insertAtBottom.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recursively pop all elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `insertAtBottom` to push the elements at the bottom.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertAtBottom(stack&lt;int&gt;&amp; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    insertAtBottom(St, X);&#10;    St.push(top);&#10;}&#10;void Reverse(stack&lt;int&gt; &amp;St) {&#10;    if(St.empty()) return;&#10;    int top = St.top();&#10;    St.pop();&#10;    Reverse(St);&#10;    insertAtBottom(St, top);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Sq 15 Sort A Stack<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/sort-a-stack/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Recursive pop and sortedInsert.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Recursively pop elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `sortedInsert` to insert the element in its sorted position.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortedInsert(stack&lt;int&gt;&amp; s, int x) {&#10;    if(s.empty() || x &gt; s.top()) {&#10;        s.push(x);&#10;        return;&#10;    }&#10;    int temp = s.top();&#10;    s.pop();&#10;    sortedInsert(s, x);&#10;    s.push(temp);&#10;}&#10;void SortedStack::sort() {&#10;    if(s.empty()) return;&#10;    int temp = s.top();&#10;    s.pop();&#10;    sort();&#10;    sortedInsert(s, temp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Sq 16 Merge Overlapping Intervals<br><br></b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a></td>
      <td><b>Example 1:</b> Stack of intervals.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Sort intervals based on start time. Push first interval to stack. For each subsequent interval, if it overlaps with the stack top, pop the stack top, merge the two, and push back. Else, push it to stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; merge(vector&lt;vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if(intervals.empty()) return {};&#10;    sort(intervals.begin(), intervals.end());&#10;    stack&lt;vector&lt;int&gt;&gt; st;&#10;    st.push(intervals[0]);&#10;    for(int i = 1; i &lt; intervals.size(); i++) {&#10;        vector&lt;int&gt; top = st.top();&#10;        if(top[1] &gt;= intervals[i][0]) {&#10;            st.pop();&#10;            top[1] = max(top[1], intervals[i][1]);&#10;            st.push(top);&#10;        } else {&#10;            st.push(intervals[i]);&#10;        }&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    while(!st.empty()) {&#10;        res.push_back(st.top());&#10;        st.pop();&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Sq 17 Maximum Rectangular Area In A Histogram<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Next Smaller Element on left and right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack to find Next Smaller Element (NSE) and Previous Smaller Element (PSE) for each bar. Then, the width of the rectangle with bar `i` as the minimum height is `NSE[i] - PSE[i] - 1`. The area is `height[i] * width`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long getMaxArea(long long arr[], int n) {&#10;    stack&lt;int&gt; st;&#10;    long long max_area = 0;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || arr[st.top()] &gt;= arr[i])) {&#10;            long long height = arr[st.top()];&#10;            st.pop();&#10;            long long width = st.empty() ? i : i - st.top() - 1;&#10;            max_area = max(max_area, height * width);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
