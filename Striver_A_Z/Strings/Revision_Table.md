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
      <td>1</td>
      <td>Str 01 Valid Palindrome<br><br></b> <a href='https://leetcode.com/problems/valid-palindrome/' target='_blank'>LeetCode 125</a></td>
      <td><b>Example 1:</b> Input: s = "A man, a plan, a canal: Panama", Output: true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><code>std::isalnum</code>, <code>std::tolower</code></td>
      <td><b>All Non-Alphanumeric:</b> Pointers might cross without any comparisons. Loop condition `left < right` safely handles it.</td>
      <td><b>Explanation:</b> Two-pointer approach skipping non-alphanumeric characters. Compare characters from both ends.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;cctype&gt;&#10;&#10;bool isPalindrome(std::string s) {&#10;    int left = 0, right = s.length() - 1;&#10;    while (left &lt; right) {&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[left])) left++;&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[right])) right--;&#10;        if (std::tolower(s[left]) != std::tolower(s[right])) return false;&#10;        left++; right--;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Str 02 Valid Anagram<br><br></b> <a href='https://leetcode.com/problems/valid-anagram/' target='_blank'>LeetCode 242</a></td>
      <td><b>Example 1:</b> Input: s = "anagram", t = "nagaram", Output: true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Length Mismatch:</b> If lengths differ, return false immediately to prevent boundary issues.</td>
      <td><b>Explanation:</b> Use a frequency array of size 26. Increment for `s`, decrement for `t`. Check if all counts are 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;vector&gt;&#10;&#10;bool isAnagram(std::string s, std::string t) {&#10;    if(s.length() != t.length()) return false;&#10;    std::vector&lt;int&gt; freq(26, 0);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        freq[s[i] - &#x27;a&#x27;]++;&#10;        freq[t[i] - &#x27;a&#x27;]--;&#10;    }&#10;    for(int count : freq) {&#10;        if(count != 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Str 03 Longest Common Prefix<br><br></b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a></td>
      <td><b>Example 1:</b> Input: strs = ["flower","flow","flight"], Output: "fl"</td>
      <td><b>Time:</b> O(N log N * M) (Constraint)<br><b>Space:</b> O(1) / O(M)</td>
      <td><code>std::sort</code></td>
      <td><b>No Match:</b> If the first character of `first` and `last` string doesn't match, loop breaks immediately, returning "".</td>
      <td><b>Explanation:</b> Sort the array. The common prefix will be constrained by the first and last strings in the sorted array.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;vector&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;std::string longestCommonPrefix(std::vector&lt;std::string&gt;&amp; strs) {&#10;    if (strs.empty()) return &quot;&quot;;&#10;    std::sort(strs.begin(), strs.end());&#10;    std::string first = strs.front();&#10;    std::string last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; i &lt; last.size() &amp;&amp; first[i] == last[i]) {&#10;        i++;&#10;    }&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Str 04 Longest Palindromic Substring<br><br></b> <a href='https://leetcode.com/problems/longest-palindromic-substring/' target='_blank'>LeetCode 5</a></td>
      <td><b>Example 1:</b> Input: s = "babad", Output: "bab"</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Substr Math:</b> `start` is calculated as `i - (len - 1) / 2` to safely encompass both odd and even length centers.</td>
      <td><b>Explanation:</b> Expand Around Center. A palindrome can have an odd (center is 1 char) or even (center is between 2 chars) length. Test both.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int expand(std::string&amp; s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}&#10;&#10;std::string longestPalindrome(std::string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, max_len = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expand(s, i, i);&#10;        int len2 = expand(s, i, i + 1);&#10;        int len = std::max(len1, len2);&#10;        if (len &gt; max_len) {&#10;            max_len = len;&#10;            start = i - (len - 1) / 2;&#10;        }&#10;    }&#10;    return s.substr(start, max_len);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Str 05 Longest Palindromic Substring<br><br></b> <a href='https://leetcode.com/problems/longest-palindromic-substring/' target='_blank'>LeetCode 5</a></td>
      <td><b>Example 1:</b> Input: s = 'babad', Output: 'bab'</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><code>#include <string></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Expand Around Center. A palindrome mirrors around its center. There are 2N-1 centers (each letter, and between each pair of letters). Expand outward as long as it remains a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestPalindrome(string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, end = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expandAroundCenter(s, i, i);&#10;        int len2 = expandAroundCenter(s, i, i + 1);&#10;        int len = max(len1, len2);&#10;        if (len &gt; end - start) {&#10;            start = i - (len - 1) / 2;&#10;            end = i + len / 2;&#10;        }&#10;    }&#10;    return s.substr(start, end - start + 1);&#10;}&#10;int expandAroundCenter(string s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Str 06 Longest Common Prefix<br><br></b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a></td>
      <td><b>Example 1:</b> Input: strs = ['flower','flow','flight'], Output: 'fl'</td>
      <td><b>Time:</b> O(N log N * M)<br><b>Space:</b> O(1) auxiliary</td>
      <td><code>#include <algorithm></code></td>
      <td><b>Empty array:</b> Handled with an initial emptiness check.</td>
      <td><b>Explanation:</b> Sort the array of strings. Compare only the first and last strings in the sorted array, as they will have the most differing characters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestCommonPrefix(vector&lt;string&gt;&amp; strs) {&#10;    if(strs.empty()) return &quot;&quot;;&#10;    sort(strs.begin(), strs.end());&#10;    string first = strs[0], last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; first[i] == last[i]) i++;&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Str 07 Kmp Algorithm<br><br></b> <a href='https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/' target='_blank'>LeetCode 28</a></td>
      <td><b>Example 1:</b> Input: haystack = 'sadbutsad', needle = 'sad', Output: 0</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td><code>#include <vector></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Compute the LPS (Longest Proper Prefix which is also Suffix) array for the needle. Use the LPS array to skip characters while matching with the haystack, reducing time to O(N+M).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int strStr(string haystack, string needle) {&#10;    if(needle.empty()) return 0;&#10;    int m = needle.length(), n = haystack.length();&#10;    vector&lt;int&gt; lps(m, 0);&#10;    int len = 0, i = 1;&#10;    while(i &lt; m) {&#10;        if(needle[i] == needle[len]) lps[i++] = ++len;&#10;        else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else lps[i++] = 0;&#10;        }&#10;    }&#10;    i = 0; int j = 0;&#10;    while(i &lt; n) {&#10;        if(needle[j] == haystack[i]) { i++; j++; }&#10;        if(j == m) return i - j;&#10;        else if(i &lt; n &amp;&amp; needle[j] != haystack[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Str 08 Rabin Karp<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4cea159/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Return array of starting indices.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Compute hash for pattern and first window of text. Slide window: subtract leading char's hash contribution, shift, and add trailing char. If hashes match, explicitly check strings to avoid collisions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    vector&lt;int&gt; res;&#10;    int d = 256, q = 101;&#10;    int m = pat.length(), n = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    for(i=0; i&lt;m-1; i++) h = (h * d) % q;&#10;    for(i=0; i&lt;m; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for(i=0; i&lt;=n-m; i++) {&#10;        if(p == t) {&#10;            for(j=0; j&lt;m; j++) if(txt[i+j] != pat[j]) break;&#10;            if(j == m) res.push_back(i+1); // 1-based index usually&#10;        }&#10;        if(i &lt; n-m) {&#10;            t = (d * (t - txt[i] * h) + txt[i+m]) % q;&#10;            if(t &lt; 0) t += q;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Str 13 Edit Distance<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/edit-distance3702/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DP Table.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>DP</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a 2D DP array. If characters match, `dp[i][j] = dp[i-1][j-1]`. If not, `dp[i][j] = 1 + min(replace, insert, delete)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int editDistance(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 0; i &lt;= n; i++) dp[i][0] = i;&#10;    for(int j = 0; j &lt;= m; j++) dp[0][j] = j;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];&#10;            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Str 14 Next Permutation<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/next-permutation5226/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Swap and Reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Traverse from right to find the first element smaller than the element to its right. Then, find the smallest element to its right that is greater than it. Swap them, and reverse the subarray after the first element's index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; nextPermutation(int N, vector&lt;int&gt; arr){&#10;    int i = N - 2;&#10;    while(i &gt;= 0 &amp;&amp; arr[i] &gt;= arr[i + 1]) i--;&#10;    if(i &gt;= 0) {&#10;        int j = N - 1;&#10;        while(arr[j] &lt;= arr[i]) j--;&#10;        swap(arr[i], arr[j]);&#10;    }&#10;    reverse(arr.begin() + i + 1, arr.end());&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Str 15 Parenthesis Checker<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack to keep track of opening brackets. If a closing bracket is encountered, check if it matches the top of the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool ispar(string x) {&#10;    stack&lt;char&gt; s;&#10;    for(char c : x) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) s.push(c);&#10;        else {&#10;            if(s.empty()) return false;&#10;            if(c == &#x27;)&#x27; &amp;&amp; s.top() != &#x27;(&#x27;) return false;&#10;            if(c == &#x27;}&#x27; &amp;&amp; s.top() != &#x27;{&#x27;) return false;&#10;            if(c == &#x27;]&#x27; &amp;&amp; s.top() != &#x27;[&#x27;) return false;&#10;            s.pop();&#10;        }&#10;    }&#10;    return s.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Str 16 Word Break<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/word-break1352/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>DP, Hash Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Use `dp[i]` to indicate if `A[0..i]` can be segmented. For each `i`, check all prefixes `A[0..j]`. If `dp[j]` is true and `A[j..i]` is in the dictionary, then `dp[i]` is true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int wordBreak(string A, vector&lt;string&gt; &amp;B) {&#10;    unordered_set&lt;string&gt; dict(B.begin(), B.end());&#10;    int n = A.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(A.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n] ? 1 : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Str 17 Rabin Karp Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Rolling Hash.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Collisions in Hash</td>
      <td><b>Explanation:</b> Compute the hash for the pattern and for the first window of text. Slide the window by removing the leading character's hash and adding the trailing character's hash. If hashes match, check the characters one by one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    int d = 256, q = 101;&#10;    int M = pat.length(), N = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    vector&lt;int&gt; res;&#10;    for (i = 0; i &lt; M - 1; i++) h = (h * d) % q;&#10;    for (i = 0; i &lt; M; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for (i = 0; i &lt;= N - M; i++) {&#10;        if (p == t) {&#10;            for (j = 0; j &lt; M; j++) {&#10;                if (txt[i + j] != pat[j]) break;&#10;            }&#10;            if (j == M) res.push_back(i + 1);&#10;        }&#10;        if (i &lt; N - M) {&#10;            t = (d * (t - txt[i] * h) + txt[i + M]) % q;&#10;            if (t &lt; 0) t = (t + q);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Str 18 Kmp Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/search-pattern0205/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> LPS Array.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Construct an LPS (Longest Proper Prefix which is also Suffix) array for the pattern. Use it to skip unnecessary comparisons while traversing the text.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void computeLPS(string pat, int M, int* lps) {&#10;    int len = 0, i = 1;&#10;    lps[0] = 0;&#10;    while(i &lt; M) {&#10;        if(pat[i] == pat[len]) {&#10;            len++; lps[i] = len; i++;&#10;        } else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else { lps[i] = 0; i++; }&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; search(string pat, string txt) {&#10;    int M = pat.length(), N = txt.length();&#10;    int lps[M];&#10;    computeLPS(pat, M, lps);&#10;    int i = 0, j = 0;&#10;    vector&lt;int&gt; res;&#10;    while((N - i) &gt;= (M - j)) {&#10;        if(pat[j] == txt[i]) { j++; i++; }&#10;        if(j == M) {&#10;            res.push_back(i - j + 1);&#10;            j = lps[j - 1];&#10;        } else if(i &lt; N &amp;&amp; pat[j] != txt[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Str 26 Roman Number To Integer<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Value mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Map each Roman numeral to its integer value. Iterate from right to left. If a character is smaller than its right character, subtract its value, else add it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int romanToDecimal(string &amp;str) {&#10;    unordered_map&lt;char, int&gt; m = {{&#x27;I&#x27;, 1}, {&#x27;V&#x27;, 5}, {&#x27;X&#x27;, 10}, {&#x27;L&#x27;, 50}, {&#x27;C&#x27;, 100}, {&#x27;D&#x27;, 500}, {&#x27;M&#x27;, 1000}};&#10;    int ans = 0, n = str.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i + 1 &lt; n &amp;&amp; m[str[i]] &lt; m[str[i+1]]) ans -= m[str[i]];&#10;        else ans += m[str[i]];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Str 27 Longest Common Prefix<br><br></b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a></td>
      <td><b>Example 1:</b> Sort array.</td>
      <td><b>Time:</b> O(N log N * M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Empty Array</td>
      <td><b>Explanation:</b> Sort the array of strings. Compare the first and the last string in the sorted array, as they will be the most different. The common prefix of these two will be the common prefix for all.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestCommonPrefix(vector&lt;string&gt;&amp; strs) {&#10;    if(strs.empty()) return &quot;&quot;;&#10;    sort(strs.begin(), strs.end());&#10;    string first = strs[0], last = strs[strs.size() - 1];&#10;    int i = 0;&#10;    while(i &lt; first.length() &amp;&amp; first[i] == last[i]) i++;&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Str 31 Valid Palindrome<br><br></b> <a href='https://leetcode.com/problems/valid-palindrome/' target='_blank'>LeetCode 125</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers, `left` starting at 0 and `right` starting at `n-1`. Skip non-alphanumeric characters. Compare the characters at `left` and `right` after converting to lowercase. If they mismatch, return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s) {&#10;    int left = 0, right = s.length() - 1;&#10;    while(left &lt; right) {&#10;        while(left &lt; right &amp;&amp; !isalnum(s[left])) left++;&#10;        while(left &lt; right &amp;&amp; !isalnum(s[right])) right--;&#10;        if(tolower(s[left]) != tolower(s[right])) return false;&#10;        left++; right--;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Str 32 Valid Anagram<br><br></b> <a href='https://leetcode.com/problems/valid-anagram/' target='_blank'>LeetCode 242</a></td>
      <td><b>Example 1:</b> Frequency Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If lengths differ, return false. Create an array of size 26. Increment counts for characters in `s` and decrement for characters in `t`. If all counts are 0, it's an anagram.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isAnagram(string s, string t) {&#10;    if(s.length() != t.length()) return false;&#10;    vector&lt;int&gt; count(26, 0);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        count[s[i] - &#x27;a&#x27;]++;&#10;        count[t[i] - &#x27;a&#x27;]--;&#10;    }&#10;    for(int i = 0; i &lt; 26; i++) {&#10;        if(count[i] != 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Str 33 Isomorphic Strings<br><br></b> <a href='https://leetcode.com/problems/isomorphic-strings/' target='_blank'>LeetCode 205</a></td>
      <td><b>Example 1:</b> Hash Maps.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two arrays to map characters from `s` to `t` and `t` to `s`. If `s[i]` is mapped to a character other than `t[i]`, or `t[i]` is mapped to a character other than `s[i]`, return false. Else, create the mappings.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isIsomorphic(string s, string t) {&#10;    vector&lt;int&gt; m1(256, -1), m2(256, -1);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(m1[s[i]] != m2[t[i]]) return false;&#10;        m1[s[i]] = i;&#10;        m2[t[i]] = i;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Str 34 Reverse Words In A String<br><br></b> <a href='https://leetcode.com/problems/reverse-words-in-a-string/' target='_blank'>LeetCode 151</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output string</td>
      <td>-</td>
      <td>Multiple spaces between words</td>
      <td><b>Explanation:</b> Iterate from right to left. Find the end of a word, then the start of a word. Extract the word and append it to the result string along with a space. Finally, remove the trailing space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reverseWords(string s) {&#10;    string result = &quot;&quot;;&#10;    int i = s.length() - 1;&#10;    while(i &gt;= 0) {&#10;        while(i &gt;= 0 &amp;&amp; s[i] == &#x27; &#x27;) i--;&#10;        if(i &lt; 0) break;&#10;        int j = i;&#10;        while(i &gt;= 0 &amp;&amp; s[i] != &#x27; &#x27;) i--;&#10;        result += s.substr(i + 1, j - i) + &quot; &quot;;&#10;    }&#10;    if(!result.empty()) result.pop_back();&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Str 35 Rotate String<br><br></b> <a href='https://leetcode.com/problems/rotate-string/' target='_blank'>LeetCode 796</a></td>
      <td><b>Example 1:</b> String Concatenation.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If the lengths of `s` and `goal` are not equal, return false. Otherwise, concatenate `s` with itself (`s + s`). If `goal` is a substring of `s + s`, then it's a rotated string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool rotateString(string s, string goal) {&#10;    if(s.length() != goal.length()) return false;&#10;    string doubleS = s + s;&#10;    return doubleS.find(goal) != string::npos;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Str 36 Largest Odd Number In String<br><br></b> <a href='https://leetcode.com/problems/largest-odd-number-in-string/' target='_blank'>LeetCode 1903</a></td>
      <td><b>Example 1:</b> Iterate from right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) excluding output</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from the end of the string. The first odd digit found marks the end of the largest odd integer (since picking all digits from index 0 to this odd digit yields the largest value). Return the substring `num[0..i]`. If no odd digit is found, return empty string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string largestOddNumber(string num) {&#10;    for(int i = num.length() - 1; i &gt;= 0; i--) {&#10;        if((num[i] - &#x27;0&#x27;) % 2 != 0) return num.substr(0, i + 1);&#10;    }&#10;    return &quot;&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Str 37 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td><b>Example 1:</b> Bucket Sort or Priority Queue.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a map. Then, sort the map entries by frequency in descending order, or use a Max Heap, or use Bucket Sort (where index is frequency and value is a list of characters). Build the new string by appending each character `freq` times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; freq;&#10;    for(char c : s) freq[c]++;&#10;    vector&lt;pair&lt;int, char&gt;&gt; v;&#10;    for(auto it : freq) v.push_back({it.second, it.first});&#10;    sort(v.rbegin(), v.rend());&#10;    string ans = &quot;&quot;;&#10;    for(auto it : v) {&#10;        ans += string(it.first, it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Str 38 Maximum Nesting Depth Of The Parentheses<br><br></b> <a href='https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/' target='_blank'>LeetCode 1614</a></td>
      <td><b>Example 1:</b> Counter tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string. Maintain a `current_depth` counter. If we see `(`, increment the counter and update `max_depth`. If we see `)`, decrement the counter. Ignore other characters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(string s) {&#10;    int maxD = 0, curD = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) {&#10;            curD++;&#10;            maxD = max(maxD, curD);&#10;        } else if(c == &#x27;)&#x27;) {&#10;            curD--;&#10;        }&#10;    }&#10;    return maxD;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Str 39 String To Integer Atoi<br><br></b> <a href='https://leetcode.com/problems/string-to-integer-atoi/' target='_blank'>LeetCode 8</a></td>
      <td><b>Example 1:</b> Step-by-step parsing.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Overflow/Underflow</td>
      <td><b>Explanation:</b> 1. Ignore leading whitespaces. 2. Check for optional '+' or '-'. 3. Read digits until a non-digit or end of string. 4. Build the integer, checking for 32-bit integer overflow/underflow at each step.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int myAtoi(string s) {&#10;    int i = 0, n = s.length(), sign = 1;&#10;    long long ans = 0;&#10;    while(i &lt; n &amp;&amp; s[i] == &#x27; &#x27;) i++;&#10;    if(i &lt; n &amp;&amp; (s[i] == &#x27;+&#x27; || s[i] == &#x27;-&#x27;)) {&#10;        sign = (s[i] == &#x27;-&#x27;) ? -1 : 1;&#10;        i++;&#10;    }&#10;    while(i &lt; n &amp;&amp; isdigit(s[i])) {&#10;        ans = ans * 10 + (s[i] - &#x27;0&#x27;);&#10;        if(sign == 1 &amp;&amp; ans &gt; INT_MAX) return INT_MAX;&#10;        if(sign == -1 &amp;&amp; -ans &lt; INT_MIN) return INT_MIN;&#10;        i++;&#10;    }&#10;    return sign * ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Str 40 Count And Say<br><br></b> <a href='https://leetcode.com/problems/count-and-say/' target='_blank'>LeetCode 38</a></td>
      <td><b>Example 1:</b> Recursive/Iterative Generation.</td>
      <td><b>Time:</b> O(N * max_len)<br><b>Space:</b> O(max_len)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start with "1". For `n-1` times, generate the next string by counting consecutive identical characters and appending `count` followed by the `character`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string countAndSay(int n) {&#10;    if(n == 1) return &quot;1&quot;;&#10;    string s = countAndSay(n - 1);&#10;    string res = &quot;&quot;;&#10;    int count = 1;&#10;    for(int i = 1; i &lt; s.length(); i++) {&#10;        if(s[i] == s[i-1]) count++;&#10;        else {&#10;            res += to_string(count) + s[i-1];&#10;            count = 1;&#10;        }&#10;    }&#10;    res += to_string(count) + s.back();&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
