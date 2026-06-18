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
      <td rowspan="1">Sq 01 Valid Parentheses<br><br></b> <a href='https://leetcode.com/problems/valid-parentheses/' target='_blank'>LeetCode 20</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = "()[]{}", Output: true<br><br><b>Note (Constraint):</b> Use LIFO behavior.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><code>std::stack</code></td>
      <td><b>Empty Stack pop:</b> Must check `!st.empty()` before popping to prevent segfaults when given extra closing brackets `)]}`.</td>
      <td><b>Explanation:</b> Use a Stack. Push opening brackets. For closing brackets, pop the stack and check if it matches the corresponding opening bracket.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;stack&gt;&#10;&#10;bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) {&#10;            st.push(c);&#10;        } else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top != &#x27;(&#x27;) ||&#10;               (c == &#x27;}&#x27; &amp;&amp; top != &#x27;{&#x27;) ||&#10;               (c == &#x27;]&#x27; &amp;&amp; top != &#x27;[&#x27;)) return false;&#10;            st.pop();&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 02 Implement Queue Using Stacks<br><br></b> <a href='https://leetcode.com/problems/implement-queue-using-stacks/' target='_blank'>LeetCode 232</a></td>
      <td rowspan="1"><b>Example 1:</b> `push(1)`, `push(2)`, `peek()` -> 1, `pop()` -> 1, `empty()` -> false.</td>
      <td><b>Time:</b> O(1) Amortized<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td><b>Amortized Transfer:</b> Reversing `input` into `output` takes `O(N)` but only happens rarely, making average pop operations `O(1)`.</td>
      <td><b>Explanation:</b> Amortized O(1). Maintain an `input` stack for pushes and an `output` stack for pops. Only transfer elements when `output` is empty.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;stack&gt;&#10;&#10;class MyQueue {&#10;    std::stack&lt;int&gt; input, output;&#10;public:&#10;    void push(int x) {&#10;        input.push(x);&#10;    }&#10;    &#10;    int pop() {&#10;        peek();&#10;        int val = output.top();&#10;        output.pop();&#10;        return val;&#10;    }&#10;    &#10;    int peek() {&#10;        if (output.empty()) {&#10;            while (!input.empty()) {&#10;                output.push(input.top());&#10;                input.pop();&#10;            }&#10;        }&#10;        return output.top();&#10;    }&#10;    &#10;    bool empty() {&#10;        return input.empty() &amp;&amp; output.empty();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sq 03 Next Greater Element I<br><br></b> <a href='https://leetcode.com/problems/next-greater-element-i/' target='_blank'>LeetCode 496</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [4,1,2], Output: [-1, 2, -1]<br><br><b>Note (Constraint):</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td>Monotonic Stack</td>
      <td><b>Linear Time:</b> Even with an inner `while` loop, every element is pushed and popped exactly once, guaranteeing overall `O(2N)` time.</td>
      <td><b>Explanation:</b> Iterate backwards maintaining a strictly decreasing Monotonic Stack. The top of the stack is the next greater element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;stack&gt;&#10;&#10;std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; res(nums.size(), -1);&#10;    std::stack&lt;int&gt; st;&#10;    for (int i = nums.size() - 1; i &gt;= 0; i--) {&#10;        while (!st.empty() &amp;&amp; st.top() &lt;= nums[i]) {&#10;            st.pop();&#10;        }&#10;        if (!st.empty()) {&#10;            res[i] = st.top();&#10;        }&#10;        st.push(nums[i]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
