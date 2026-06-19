# Strings Revision Table

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
      <td rowspan="1">Str 05 Longest Palindromic Substring<br><br></b> <a href='https://leetcode.com/problems/longest-palindromic-substring/' target='_blank'>LeetCode 5</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: s = 'babad', Output: 'bab'</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><code>#include <string></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Expand Around Center. A palindrome mirrors around its center. There are 2N-1 centers (each letter, and between each pair of letters). Expand outward as long as it remains a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestPalindrome(string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, end = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expandAroundCenter(s, i, i);&#10;        int len2 = expandAroundCenter(s, i, i + 1);&#10;        int len = max(len1, len2);&#10;        if (len &gt; end - start) {&#10;            start = i - (len - 1) / 2;&#10;            end = i + len / 2;&#10;        }&#10;    }&#10;    return s.substr(start, end - start + 1);&#10;}&#10;int expandAroundCenter(string s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Str 06 Longest Common Prefix<br><br></b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: strs = ['flower','flow','flight'], Output: 'fl'</td>
      <td><b>Time:</b> O(N log N * M)<br><b>Space:</b> O(1) auxiliary</td>
      <td><code>#include <algorithm></code></td>
      <td><b>Empty array:</b> Handled with an initial emptiness check.</td>
      <td><b>Explanation:</b> Sort the array of strings. Compare only the first and last strings in the sorted array, as they will have the most differing characters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestCommonPrefix(vector&lt;string&gt;&amp; strs) {&#10;    if(strs.empty()) return &quot;&quot;;&#10;    sort(strs.begin(), strs.end());&#10;    string first = strs[0], last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; first[i] == last[i]) i++;&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
