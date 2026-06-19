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
  </tbody>
</table>
