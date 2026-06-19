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
      <td>Str 9 Reverse A String<br><br></b> <a href='https://leetcode.com/problems/reverse-string/' target='_blank'>LeetCode 344</a></td>
      <td><b>Example 1:</b> Two pointers swap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers, `left` at the beginning and `right` at the end of the string. Swap the characters at these pointers and move them towards each other until they meet.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void reverseString(vector&lt;char&gt;&amp; s) {&#10;    int left = 0, right = s.size() - 1;&#10;    while(left &lt; right) {&#10;        swap(s[left++], s[right--]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Str 10 Palindrome String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/palindrome-string0817/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers, `left` at the beginning and `right` at the end of the string. Compare the characters at these pointers. If they are different, return 0. Move pointers towards each other. If all characters match, return 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPalindrome(string S) {&#10;    int left = 0, right = S.length() - 1;&#10;    while(left &lt; right) {&#10;        if(S[left] != S[right]) return 0;&#10;        left++; right--;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Str 11 Find Duplicate Characters In A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-duplicate-characters-in-a-string/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Frequency array or Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><code>#include <unordered_map></code></td>
      <td>-</td>
      <td><b>Explanation:</b> Use a hash map or frequency array to count occurrences of each character. Then, iterate through the map/array and print characters with a count greater than 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDups(string str) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : str) count[c]++;&#10;    for(auto it : count) {&#10;        if(it.second &gt; 1) cout &lt;&lt; it.first &lt;&lt; &quot;, count = &quot; &lt;&lt; it.second &lt;&lt; &quot;\n&quot;;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Str 12 Why Strings Are Immutable In Java<br><br></b> <a href='https://www.geeksforgeeks.org/java-string-is-immutable-what-exactly-is-the-meaning/' target='_blank'>Article</a></td>
      <td><b>Example 1:</b> String Pool, Security, Thread Safety.</td>
      <td><b>Time:</b> -<br><b>Space:</b> -</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> 1. **String Pool**: Allows caching of string literals, saving memory. 2. **Security**: Strings are used as arguments for network connections, database URLs, etc. Immutability prevents malicious tampering. 3. **Thread Safety**: Immutable objects are inherently thread-safe and can be shared among multiple threads without synchronization. 4. **Caching Hashcode**: Immutability guarantees the hashcode will never change, making it suitable for keys in HashMaps.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">/* Conceptual topic */</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Str 13 A Program To Check If Strings Are Rotations Of Each Other<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Concatenate and find.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If the lengths are different, return false. Otherwise, concatenate `s1` with itself (`s1 + s1`). If `s2` is a rotation of `s1`, it must be a substring of the concatenated string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool areRotations(string s1, string s2) {&#10;    if(s1.length() != s2.length()) return false;&#10;    string temp = s1 + s1;&#10;    return (temp.find(s2) != string::npos);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Str 14 Check If A String Is A Valid Shuffle Of Two Distinct Strings<br><br></b> <a href='https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings' target='_blank'>Article</a></td>
      <td><b>Example 1:</b> Three pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If lengths don't match, return false. Use three pointers `i`, `j`, `k` for `str1`, `str2`, and `str3`. Traverse `str3`. If `str3[k] == str1[i]`, increment `i` and `k`. Else if `str3[k] == str2[j]`, increment `j` and `k`. Else, it's not a valid shuffle. After the loop, check if both `str1` and `str2` are fully traversed.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkShuffle(string str1, string str2, string str3) {&#10;    if(str1.length() + str2.length() != str3.length()) return false;&#10;    int i = 0, j = 0, k = 0;&#10;    while(k &lt; str3.length()) {&#10;        if(i &lt; str1.length() &amp;&amp; str1[i] == str3[k]) i++;&#10;        else if(j &lt; str2.length() &amp;&amp; str2[j] == str3[k]) j++;&#10;        else return false;&#10;        k++;&#10;    }&#10;    return (i == str1.length() &amp;&amp; j == str2.length());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Str 15 Count And Say<br><br></b> <a href='https://leetcode.com/problems/count-and-say/' target='_blank'>LeetCode 38</a></td>
      <td><b>Example 1:</b> Recursive generation.</td>
      <td><b>Time:</b> O(N * L) where L is max length of string<br><b>Space:</b> O(L)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start with `res = '1'`. For `n-1` times, iterate through `res` and count consecutive identical characters. Append the count and the character to a new string. Replace `res` with the new string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string countAndSay(int n) {&#10;    if(n == 1) return &quot;1&quot;;&#10;    string s = &quot;1&quot;;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        string temp = &quot;&quot;;&#10;        int count = 1;&#10;        for(int j = 1; j &lt; s.length(); j++) {&#10;            if(s[j] == s[j - 1]) count++;&#10;            else {&#10;                temp += to_string(count) + s[j - 1];&#10;                count = 1;&#10;            }&#10;        }&#10;        temp += to_string(count) + s.back();&#10;        s = temp;&#10;    }&#10;    return s;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Str 16 Longest Palindrome In A String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Expand around center.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> For each character, treat it as the center of an odd-length palindrome and expand outwards. Also treat it and the next character as the center of an even-length palindrome and expand outwards. Keep track of the longest palindrome found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestPalindrome(string S){&#10;    int start = 0, maxLen = 1, n = S.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int l = i, r = i;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;        l = i; r = i + 1;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;    }&#10;    return S.substr(start, maxLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Str 17 Find Longest Recurring Subsequence In String<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Modified LCS.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2) or O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> This is a variation of Longest Common Subsequence (LCS). Find LCS of `str` with itself, but with the restriction that when characters match, their indices must not be the same (`i != j`).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestRepeatingSubsequence(string str) {&#10;    int n = str.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(str[i-1] == str[j-1] &amp;&amp; i != j) {&#10;                dp[i][j] = 1 + dp[i-1][j-1];&#10;            } else {&#10;                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);&#10;            }&#10;        }&#10;    }&#10;    return dp[n][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Str 18 Print All Subsequences Of A String<br><br></b> <a href='https://www.geeksforgeeks.org/print-subsequences-string/' target='_blank'>Article</a></td>
      <td><b>Example 1:</b> Recursive choice (include/exclude).</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N) recursion stack</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use recursion. At each character, you have two choices: either include it in the current subsequence or exclude it. When you reach the end of the string, print/store the formed subsequence.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string s, string curr, int i, vector&lt;string&gt;&amp; res) {&#10;    if(i == s.length()) {&#10;        if(curr != &quot;&quot;) res.push_back(curr);&#10;        return;&#10;    }&#10;    solve(s, curr, i + 1, res);&#10;    solve(s, curr + s[i], i + 1, res);&#10;}&#10;vector&lt;string&gt; allSubsequences(string s) {&#10;    vector&lt;string&gt; res;&#10;    solve(s, &quot;&quot;, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Str 11 Split The Binary String Into Substrings With Equal Number Of 0S And 1S<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Counter logic.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string, maintain a count that increments for '0' and decrements for '1' (or vice versa). Whenever the count becomes 0, it means we have found a balanced substring, so increment the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubStr(string str) {&#10;    int count0 = 0, count1 = 0, ans = 0;&#10;    for(char c : str) {&#10;        if(c == &#x27;0&#x27;) count0++;&#10;        else count1++;&#10;        if(count0 == count1) ans++;&#10;    }&#10;    if(count0 != count1) return -1;&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Str 12 Word Wrap<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/word-wrap1646/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DP approach.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>DP</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Dynamic Programming. `dp[i]` represents the minimum cost to wrap words from index `i` to the end. Iterate backward and try placing different numbers of words on the current line.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solveWordWrap(vector&lt;int&gt;nums, int k) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; dp(n, 0);&#10;    dp[n - 1] = 0;&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        int currlen = -1;&#10;        dp[i] = INT_MAX;&#10;        for(int j = i; j &lt; n; j++) {&#10;            currlen += (nums[j] + 1);&#10;            if(currlen &gt; k) break;&#10;            if(j == n - 1) dp[i] = 0;&#10;            else {&#10;                int cost = (k - currlen) * (k - currlen) + dp[j + 1];&#10;                dp[i] = min(dp[i], cost);&#10;            }&#10;        }&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Str 13 Edit Distance<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/edit-distance3702/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DP Table.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>DP</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a 2D DP array. If characters match, `dp[i][j] = dp[i-1][j-1]`. If not, `dp[i][j] = 1 + min(replace, insert, delete)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int editDistance(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 0; i &lt;= n; i++) dp[i][0] = i;&#10;    for(int j = 0; j &lt;= m; j++) dp[0][j] = j;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];&#10;            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Str 14 Next Permutation<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/next-permutation5226/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Swap and Reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Traverse from right to find the first element smaller than the element to its right. Then, find the smallest element to its right that is greater than it. Swap them, and reverse the subarray after the first element's index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; nextPermutation(int N, vector&lt;int&gt; arr){&#10;    int i = N - 2;&#10;    while(i &gt;= 0 &amp;&amp; arr[i] &gt;= arr[i + 1]) i--;&#10;    if(i &gt;= 0) {&#10;        int j = N - 1;&#10;        while(arr[j] &lt;= arr[i]) j--;&#10;        swap(arr[i], arr[j]);&#10;    }&#10;    reverse(arr.begin() + i + 1, arr.end());&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>23</td>
      <td>Str 15 Parenthesis Checker<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>-</td>
      <td><b>Explanation:</b> Use a stack to keep track of opening brackets. If a closing bracket is encountered, check if it matches the top of the stack.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool ispar(string x) {&#10;    stack&lt;char&gt; s;&#10;    for(char c : x) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) s.push(c);&#10;        else {&#10;            if(s.empty()) return false;&#10;            if(c == &#x27;)&#x27; &amp;&amp; s.top() != &#x27;(&#x27;) return false;&#10;            if(c == &#x27;}&#x27; &amp;&amp; s.top() != &#x27;{&#x27;) return false;&#10;            if(c == &#x27;]&#x27; &amp;&amp; s.top() != &#x27;[&#x27;) return false;&#10;            s.pop();&#10;        }&#10;    }&#10;    return s.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>24</td>
      <td>Str 16 Word Break<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/word-break1352/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>DP, Hash Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Use `dp[i]` to indicate if `A[0..i]` can be segmented. For each `i`, check all prefixes `A[0..j]`. If `dp[j]` is true and `A[j..i]` is in the dictionary, then `dp[i]` is true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int wordBreak(string A, vector&lt;string&gt; &amp;B) {&#10;    unordered_set&lt;string&gt; dict(B.begin(), B.end());&#10;    int n = A.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(A.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n] ? 1 : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>25</td>
      <td>Str 17 Rabin Karp Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Rolling Hash.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Collisions in Hash</td>
      <td><b>Explanation:</b> Compute the hash for the pattern and for the first window of text. Slide the window by removing the leading character's hash and adding the trailing character's hash. If hashes match, check the characters one by one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    int d = 256, q = 101;&#10;    int M = pat.length(), N = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    vector&lt;int&gt; res;&#10;    for (i = 0; i &lt; M - 1; i++) h = (h * d) % q;&#10;    for (i = 0; i &lt; M; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for (i = 0; i &lt;= N - M; i++) {&#10;        if (p == t) {&#10;            for (j = 0; j &lt; M; j++) {&#10;                if (txt[i + j] != pat[j]) break;&#10;            }&#10;            if (j == M) res.push_back(i + 1);&#10;        }&#10;        if (i &lt; N - M) {&#10;            t = (d * (t - txt[i] * h) + txt[i + M]) % q;&#10;            if (t &lt; 0) t = (t + q);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>26</td>
      <td>Str 18 Kmp Algorithm<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/search-pattern0205/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> LPS Array.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Construct an LPS (Longest Proper Prefix which is also Suffix) array for the pattern. Use it to skip unnecessary comparisons while traversing the text.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void computeLPS(string pat, int M, int* lps) {&#10;    int len = 0, i = 1;&#10;    lps[0] = 0;&#10;    while(i &lt; M) {&#10;        if(pat[i] == pat[len]) {&#10;            len++; lps[i] = len; i++;&#10;        } else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else { lps[i] = 0; i++; }&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; search(string pat, string txt) {&#10;    int M = pat.length(), N = txt.length();&#10;    int lps[M];&#10;    computeLPS(pat, M, lps);&#10;    int i = 0, j = 0;&#10;    vector&lt;int&gt; res;&#10;    while((N - i) &gt;= (M - j)) {&#10;        if(pat[j] == txt[i]) { j++; i++; }&#10;        if(j == M) {&#10;            res.push_back(i - j + 1);&#10;            j = lps[j - 1];&#10;        } else if(i &lt; N &amp;&amp; pat[j] != txt[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>27</td>
      <td>Str 19 Convert A Sentence Into Its Equivalent Mobile Numeric Keypad Sequence<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Dictionary Mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Spaces</td>
      <td><b>Explanation:</b> Store the sequence for every character in an array from A to Z, and for space. For each character in the input string, append its corresponding sequence to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string printSequence(string S) {&#10;    string str[] = {&quot;2&quot;, &quot;22&quot;, &quot;222&quot;, &quot;3&quot;, &quot;33&quot;, &quot;333&quot;, &quot;4&quot;, &quot;44&quot;, &quot;444&quot;, &quot;5&quot;, &quot;55&quot;, &quot;555&quot;, &quot;6&quot;, &quot;66&quot;, &quot;666&quot;, &quot;7&quot;, &quot;77&quot;, &quot;777&quot;, &quot;7777&quot;, &quot;8&quot;, &quot;88&quot;, &quot;888&quot;, &quot;9&quot;, &quot;99&quot;, &quot;999&quot;, &quot;9999&quot;};&#10;    string output = &quot;&quot;;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27; &#x27;) output += &quot;0&quot;;&#10;        else output += str[S[i] - &#x27;A&#x27;];&#10;    }&#10;    return output;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>28</td>
      <td>Str 20 Count The Reversals<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>Odd length string</td>
      <td><b>Explanation:</b> Remove all balanced brackets using a stack. The remaining string will be of the form `}}...{{...`. The required reversals will be `ceil(open_count/2) + ceil(close_count/2)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countRev(string s) {&#10;    if(s.length() % 2 != 0) return -1;&#10;    stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;{&#x27;) st.push(c);&#10;        else {&#10;            if(!st.empty() &amp;&amp; st.top() == &#x27;{&#x27;) st.pop();&#10;            else st.push(c);&#10;        }&#10;    }&#10;    int open = 0, close = 0;&#10;    while(!st.empty()) {&#10;        if(st.top() == &#x27;{&#x27;) open++;&#10;        else close++;&#10;        st.pop();&#10;    }&#10;    return ceil(open / 2.0) + ceil(close / 2.0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>29</td>
      <td>Str 21 Minimum Number Of Bracket Reversals Needed To Make An Expression Balanced<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Stack logic.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Stack</td>
      <td>Odd length</td>
      <td><b>Explanation:</b> If the length of string is odd, return -1. Remove all balanced parts. The remaining string looks like `}}}{{{`. The number of reversals needed is `ceil(close/2) + ceil(open/2)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countRev(string s) {&#10;    if(s.length() % 2 != 0) return -1;&#10;    stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;{&#x27;) st.push(c);&#10;        else {&#10;            if(!st.empty() &amp;&amp; st.top() == &#x27;{&#x27;) st.pop();&#10;            else st.push(c);&#10;        }&#10;    }&#10;    int open = 0, close = 0;&#10;    while(!st.empty()) {&#10;        if(st.top() == &#x27;{&#x27;) open++;&#10;        else close++;&#10;        st.pop();&#10;    }&#10;    return ceil(open / 2.0) + ceil(close / 2.0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>30</td>
      <td>Str 22 Count Palindromic Subsequences<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Dynamic Programming.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>DP</td>
      <td>-</td>
      <td><b>Explanation:</b> Use DP. `dp[i][j]` stores the count of palindromic subsequences in `str[i..j]`. If `str[i] == str[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. Else, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int countPS(string str) {&#10;    long long int MOD = 1e9 + 7;&#10;    int n = str.length();&#10;    vector&lt;vector&lt;long long int&gt;&gt; dp(n, vector&lt;long long int&gt;(n, 0));&#10;    for(int i = 0; i &lt; n; i++) dp[i][i] = 1;&#10;    for(int len = 2; len &lt;= n; len++) {&#10;        for(int i = 0; i &lt;= n - len; i++) {&#10;            int j = i + len - 1;&#10;            if(str[i] == str[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;&#10;            else dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD;&#10;        }&#10;    }&#10;    return dp[0][n - 1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>31</td>
      <td>Str 23 Count Of Number Of Given String In 2D Character Array<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(R * C * 4^L)<br><b>Space:</b> O(L)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use DFS. For each cell, if it matches the first character of the word, start a DFS to look for the rest of the word in all 4 directions. Keep track of visited cells.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int dfs(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string&amp; target, int r, int c, int idx) {&#10;    if(idx == target.length()) return 1;&#10;    if(r &lt; 0 || r &gt;= mat.size() || c &lt; 0 || c &gt;= mat[0].size() || mat[r][c] != target[idx]) return 0;&#10;    char temp = mat[r][c];&#10;    mat[r][c] = &#x27;#&#x27;;&#10;    int found = dfs(mat, target, r + 1, c, idx + 1) +&#10;                dfs(mat, target, r - 1, c, idx + 1) +&#10;                dfs(mat, target, r, c + 1, idx + 1) +&#10;                dfs(mat, target, r, c - 1, idx + 1);&#10;    mat[r][c] = temp;&#10;    return found;&#10;}&#10;int findOccurrence(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string target) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; mat.size(); i++) {&#10;        for(int j = 0; j &lt; mat[0].size(); j++) {&#10;            if(mat[i][j] == target[0]) {&#10;                count += dfs(mat, target, i, j, 0);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>32</td>
      <td>Str 24 Search A Word In A 2D Grid Of Characters<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> 8 Directions Loop.</td>
      <td><b>Time:</b> O(N * M * 8 * L)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the grid. For each matching starting character, check all 8 directions to see if the full word exists in a straight line.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; searchWord(vector&lt;vector&lt;char&gt;&gt; grid, string word){&#10;    int R = grid.size(), C = grid[0].size(), L = word.length();&#10;    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};&#10;    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(int r = 0; r &lt; R; r++) {&#10;        for(int c = 0; c &lt; C; c++) {&#10;            if(grid[r][c] == word[0]) {&#10;                for(int dir = 0; dir &lt; 8; dir++) {&#10;                    int k, currR = r + dr[dir], currC = c + dc[dir];&#10;                    for(k = 1; k &lt; L; k++) {&#10;                        if(currR &lt; 0 || currR &gt;= R || currC &lt; 0 || currC &gt;= C) break;&#10;                        if(grid[currR][currC] != word[k]) break;&#10;                        currR += dr[dir]; currC += dc[dir];&#10;                    }&#10;                    if(k == L) {&#10;                        ans.push_back({r, c});&#10;                        break;&#10;                    }&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>33</td>
      <td>Str 25 Boyer Moore Algorithm For Pattern Searching<br><br></b> <a href='https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Bad Character Heuristic.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(256)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Create a Bad Character table for the pattern, which stores the last occurrence of each character. Align pattern with text. Compare from right to left. If mismatch, shift the pattern so that the mismatched character in text aligns with its last occurrence in the pattern. If not present, shift pattern past it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void search(string txt, string pat) {&#10;    int m = pat.length(), n = txt.length();&#10;    int badChar[256];&#10;    for(int i = 0; i &lt; 256; i++) badChar[i] = -1;&#10;    for(int i = 0; i &lt; m; i++) badChar[(int)pat[i]] = i;&#10;    int s = 0;&#10;    while(s &lt;= (n - m)) {&#10;        int j = m - 1;&#10;        while(j &gt;= 0 &amp;&amp; pat[j] == txt[s + j]) j--;&#10;        if(j &lt; 0) {&#10;            cout &lt;&lt; &quot;Pattern occurs at shift = &quot; &lt;&lt; s &lt;&lt; endl;&#10;            s += (s + m &lt; n) ? m - badChar[txt[s + m]] : 1;&#10;        } else {&#10;            s += max(1, j - badChar[txt[s + j]]);&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>34</td>
      <td>Str 26 Roman Number To Integer<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Value mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Map each Roman numeral to its integer value. Iterate from right to left. If a character is smaller than its right character, subtract its value, else add it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int romanToDecimal(string &amp;str) {&#10;    unordered_map&lt;char, int&gt; m = {{&#x27;I&#x27;, 1}, {&#x27;V&#x27;, 5}, {&#x27;X&#x27;, 10}, {&#x27;L&#x27;, 50}, {&#x27;C&#x27;, 100}, {&#x27;D&#x27;, 500}, {&#x27;M&#x27;, 1000}};&#10;    int ans = 0, n = str.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i + 1 &lt; n &amp;&amp; m[str[i]] &lt; m[str[i+1]]) ans -= m[str[i]];&#10;        else ans += m[str[i]];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>35</td>
      <td>Str 27 Longest Common Prefix<br><br></b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a></td>
      <td><b>Example 1:</b> Sort array.</td>
      <td><b>Time:</b> O(N log N * M)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Empty Array</td>
      <td><b>Explanation:</b> Sort the array of strings. Compare the first and the last string in the sorted array, as they will be the most different. The common prefix of these two will be the common prefix for all.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestCommonPrefix(vector&lt;string&gt;&amp; strs) {&#10;    if(strs.empty()) return &quot;&quot;;&#10;    sort(strs.begin(), strs.end());&#10;    string first = strs[0], last = strs[strs.size() - 1];&#10;    int i = 0;&#10;    while(i &lt; first.length() &amp;&amp; first[i] == last[i]) i++;&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>36</td>
      <td>Str 28 Number Of Flips To Make Binary String Alternate<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Two target strings.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> There are only two possible alternating strings for length N: starting with '0' (`010101...`) and starting with '1' (`101010...`). Count the differences between the given string and both of these. The minimum count is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFlips(string S) {&#10;    int count1 = 0, count2 = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(i % 2 == 0) {&#10;            if(S[i] != &#x27;0&#x27;) count1++;&#10;            if(S[i] != &#x27;1&#x27;) count2++;&#10;        } else {&#10;            if(S[i] != &#x27;1&#x27;) count1++;&#10;            if(S[i] != &#x27;0&#x27;) count2++;&#10;        }&#10;    }&#10;    return min(count1, count2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>37</td>
      <td>Str 29 Find The First Repeated Word In String<br><br></b> <a href='https://www.geeksforgeeks.org/find-first-repeated-word-string/' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Hash Set</td>
      <td>-</td>
      <td><b>Explanation:</b> Split the string into words. Iterate through the words. If a word is already in the hash set, it is the first repeated word. Return it. Else, add it to the hash set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string firstRepeatedWord(string s) {&#10;    unordered_set&lt;string&gt; st;&#10;    string word = &quot;&quot;;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(s[i] == &#x27; &#x27; || s[i] == &#x27;\t&#x27; || s[i] == &#x27;,&#x27; || s[i] == &#x27;:&#x27; || s[i] == &#x27;.&#x27; || s[i] == &#x27;-&#x27;) {&#10;            if(word != &quot;&quot;) {&#10;                if(st.find(word) != st.end()) return word;&#10;                st.insert(word);&#10;                word = &quot;&quot;;&#10;            }&#10;        } else word += s[i];&#10;    }&#10;    if(word != &quot;&quot; &amp;&amp; st.find(word) != st.end()) return word;&#10;    return &quot;No Repetition&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>38</td>
      <td>Str 30 Minimum Swaps For Bracket Balancing<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Track balance.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Keep track of the number of opening and closing brackets, and an `imbalance` counter. When encountering `[`, decrease imbalance. When encountering `]`, increase imbalance. The number of swaps is updated when an imbalance is found and we find the next `[`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumNumberOfSwaps(string S){&#10;    int open = 0, close = 0, fault = 0, ans = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27;]&#x27;) {&#10;            close++;&#10;            fault = close - open;&#10;        } else {&#10;            open++;&#10;            if(fault &gt; 0) {&#10;                ans += fault;&#10;                fault--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>39</td>
      <td>Str 31 Valid Palindrome<br><br></b> <a href='https://leetcode.com/problems/valid-palindrome/' target='_blank'>LeetCode 125</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two pointers, `left` starting at 0 and `right` starting at `n-1`. Skip non-alphanumeric characters. Compare the characters at `left` and `right` after converting to lowercase. If they mismatch, return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s) {&#10;    int left = 0, right = s.length() - 1;&#10;    while(left &lt; right) {&#10;        while(left &lt; right &amp;&amp; !isalnum(s[left])) left++;&#10;        while(left &lt; right &amp;&amp; !isalnum(s[right])) right--;&#10;        if(tolower(s[left]) != tolower(s[right])) return false;&#10;        left++; right--;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>40</td>
      <td>Str 32 Valid Anagram<br><br></b> <a href='https://leetcode.com/problems/valid-anagram/' target='_blank'>LeetCode 242</a></td>
      <td><b>Example 1:</b> Frequency Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If lengths differ, return false. Create an array of size 26. Increment counts for characters in `s` and decrement for characters in `t`. If all counts are 0, it's an anagram.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isAnagram(string s, string t) {&#10;    if(s.length() != t.length()) return false;&#10;    vector&lt;int&gt; count(26, 0);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        count[s[i] - &#x27;a&#x27;]++;&#10;        count[t[i] - &#x27;a&#x27;]--;&#10;    }&#10;    for(int i = 0; i &lt; 26; i++) {&#10;        if(count[i] != 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>41</td>
      <td>Str 33 Isomorphic Strings<br><br></b> <a href='https://leetcode.com/problems/isomorphic-strings/' target='_blank'>LeetCode 205</a></td>
      <td><b>Example 1:</b> Hash Maps.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use two arrays to map characters from `s` to `t` and `t` to `s`. If `s[i]` is mapped to a character other than `t[i]`, or `t[i]` is mapped to a character other than `s[i]`, return false. Else, create the mappings.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isIsomorphic(string s, string t) {&#10;    vector&lt;int&gt; m1(256, -1), m2(256, -1);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(m1[s[i]] != m2[t[i]]) return false;&#10;        m1[s[i]] = i;&#10;        m2[t[i]] = i;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>42</td>
      <td>Str 34 Reverse Words In A String<br><br></b> <a href='https://leetcode.com/problems/reverse-words-in-a-string/' target='_blank'>LeetCode 151</a></td>
      <td><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output string</td>
      <td>-</td>
      <td>Multiple spaces between words</td>
      <td><b>Explanation:</b> Iterate from right to left. Find the end of a word, then the start of a word. Extract the word and append it to the result string along with a space. Finally, remove the trailing space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reverseWords(string s) {&#10;    string result = &quot;&quot;;&#10;    int i = s.length() - 1;&#10;    while(i &gt;= 0) {&#10;        while(i &gt;= 0 &amp;&amp; s[i] == &#x27; &#x27;) i--;&#10;        if(i &lt; 0) break;&#10;        int j = i;&#10;        while(i &gt;= 0 &amp;&amp; s[i] != &#x27; &#x27;) i--;&#10;        result += s.substr(i + 1, j - i) + &quot; &quot;;&#10;    }&#10;    if(!result.empty()) result.pop_back();&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>43</td>
      <td>Str 35 Rotate String<br><br></b> <a href='https://leetcode.com/problems/rotate-string/' target='_blank'>LeetCode 796</a></td>
      <td><b>Example 1:</b> String Concatenation.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> If the lengths of `s` and `goal` are not equal, return false. Otherwise, concatenate `s` with itself (`s + s`). If `goal` is a substring of `s + s`, then it's a rotated string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool rotateString(string s, string goal) {&#10;    if(s.length() != goal.length()) return false;&#10;    string doubleS = s + s;&#10;    return doubleS.find(goal) != string::npos;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>44</td>
      <td>Str 36 Largest Odd Number In String<br><br></b> <a href='https://leetcode.com/problems/largest-odd-number-in-string/' target='_blank'>LeetCode 1903</a></td>
      <td><b>Example 1:</b> Iterate from right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) excluding output</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from the end of the string. The first odd digit found marks the end of the largest odd integer (since picking all digits from index 0 to this odd digit yields the largest value). Return the substring `num[0..i]`. If no odd digit is found, return empty string.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string largestOddNumber(string num) {&#10;    for(int i = num.length() - 1; i &gt;= 0; i--) {&#10;        if((num[i] - &#x27;0&#x27;) % 2 != 0) return num.substr(0, i + 1);&#10;    }&#10;    return &quot;&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>45</td>
      <td>Str 37 Sort Characters By Frequency<br><br></b> <a href='https://leetcode.com/problems/sort-characters-by-frequency/' target='_blank'>LeetCode 451</a></td>
      <td><b>Example 1:</b> Bucket Sort or Priority Queue.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Count frequencies using a map. Then, sort the map entries by frequency in descending order, or use a Max Heap, or use Bucket Sort (where index is frequency and value is a list of characters). Build the new string by appending each character `freq` times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; freq;&#10;    for(char c : s) freq[c]++;&#10;    vector&lt;pair&lt;int, char&gt;&gt; v;&#10;    for(auto it : freq) v.push_back({it.second, it.first});&#10;    sort(v.rbegin(), v.rend());&#10;    string ans = &quot;&quot;;&#10;    for(auto it : v) {&#10;        ans += string(it.first, it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>46</td>
      <td>Str 38 Maximum Nesting Depth Of The Parentheses<br><br></b> <a href='https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/' target='_blank'>LeetCode 1614</a></td>
      <td><b>Example 1:</b> Counter tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate through the string. Maintain a `current_depth` counter. If we see `(`, increment the counter and update `max_depth`. If we see `)`, decrement the counter. Ignore other characters.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(string s) {&#10;    int maxD = 0, curD = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) {&#10;            curD++;&#10;            maxD = max(maxD, curD);&#10;        } else if(c == &#x27;)&#x27;) {&#10;            curD--;&#10;        }&#10;    }&#10;    return maxD;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>47</td>
      <td>Str 39 String To Integer Atoi<br><br></b> <a href='https://leetcode.com/problems/string-to-integer-atoi/' target='_blank'>LeetCode 8</a></td>
      <td><b>Example 1:</b> Step-by-step parsing.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Overflow/Underflow</td>
      <td><b>Explanation:</b> 1. Ignore leading whitespaces. 2. Check for optional '+' or '-'. 3. Read digits until a non-digit or end of string. 4. Build the integer, checking for 32-bit integer overflow/underflow at each step.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int myAtoi(string s) {&#10;    int i = 0, n = s.length(), sign = 1;&#10;    long long ans = 0;&#10;    while(i &lt; n &amp;&amp; s[i] == &#x27; &#x27;) i++;&#10;    if(i &lt; n &amp;&amp; (s[i] == &#x27;+&#x27; || s[i] == &#x27;-&#x27;)) {&#10;        sign = (s[i] == &#x27;-&#x27;) ? -1 : 1;&#10;        i++;&#10;    }&#10;    while(i &lt; n &amp;&amp; isdigit(s[i])) {&#10;        ans = ans * 10 + (s[i] - &#x27;0&#x27;);&#10;        if(sign == 1 &amp;&amp; ans &gt; INT_MAX) return INT_MAX;&#10;        if(sign == -1 &amp;&amp; -ans &lt; INT_MIN) return INT_MIN;&#10;        i++;&#10;    }&#10;    return sign * ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>48</td>
      <td>Str 40 Count And Say<br><br></b> <a href='https://leetcode.com/problems/count-and-say/' target='_blank'>LeetCode 38</a></td>
      <td><b>Example 1:</b> Recursive/Iterative Generation.</td>
      <td><b>Time:</b> O(N * max_len)<br><b>Space:</b> O(max_len)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Start with "1". For `n-1` times, generate the next string by counting consecutive identical characters and appending `count` followed by the `character`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string countAndSay(int n) {&#10;    if(n == 1) return &quot;1&quot;;&#10;    string s = countAndSay(n - 1);&#10;    string res = &quot;&quot;;&#10;    int count = 1;&#10;    for(int i = 1; i &lt; s.length(); i++) {&#10;        if(s[i] == s[i-1]) count++;&#10;        else {&#10;            res += to_string(count) + s[i-1];&#10;            count = 1;&#10;        }&#10;    }&#10;    res += to_string(count) + s.back();&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
