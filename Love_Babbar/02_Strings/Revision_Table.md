# 02 Strings Revision Table

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
      <td rowspan="1">Hash 01 Sort Characters By Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-characters-by-frequency/" target="_blank">LeetCode 451</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b> </b> Hash Map + Priority Queue / Sorting.</td>
      <td><b>Time:</b> O(N log K) where K is unique chars<br><b>Space:</b> O(K)</td>
      <td>Optimal: Count frequencies using a hash map. Add pairs `(freq, char)` to a max heap or vector and sort. Reconstruct string.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; freq;&#10;    for(char c : s) freq[c]++;&#10;    vector&lt;pair&lt;int, char&gt;&gt; v;&#10;    for(auto it : freq) v.push_back({it.second, it.first});&#10;    sort(v.rbegin(), v.rend());&#10;    string ans = &quot;&quot;;&#10;    for(auto it : v) {&#10;        ans += string(it.first, it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Str 02 Valid Palindrome<br><br></b> <a href="https://leetcode.com/problems/valid-palindrome/" target="_blank">LeetCode 125</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "A man, a plan, a canal: Panama"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Two-pointer approach skipping non-alphanumeric characters. Compare characters from both ends.<br><br><b>Dependencies:</b> <code>std::isalnum</code>, <code>std::tolower</code></td>
      <td><b>Edge Cases:</b> <b>All Non-Alphanumeric:</b> Pointers might cross without any comparisons. Loop condition `left < right` safely handles it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(std::string s) {&#10;    int left = 0, right = s.length() - 1;&#10;    while (left &lt; right) {&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[left])) left++;&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[right])) right--;&#10;        if (std::tolower(s[left]) != std::tolower(s[right])) return false;&#10;        left++; right--;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Str 03 Valid Anagram<br><br></b> <a href="https://leetcode.com/problems/valid-anagram/" target="_blank">LeetCode 242</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, SDE Sheet, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "anagram", t = "nagaram"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a frequency array of size 26. Increment for `s`, decrement for `t`. Check if all counts are 0.</td>
      <td><b>Edge Cases:</b> <b>Length Mismatch:</b> If lengths differ, return false immediately to prevent boundary issues.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isAnagram(std::string s, std::string t) {&#10;    if(s.length() != t.length()) return false;&#10;    std::vector&lt;int&gt; freq(26, 0);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        freq[s[i] - &#x27;a&#x27;]++;&#10;        freq[t[i] - &#x27;a&#x27;]--;&#10;    }&#10;    for(int count : freq) {&#10;        if(count != 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Str 04 Longest Common Prefix<br><br></b> <a href="https://leetcode.com/problems/longest-common-prefix/" target="_blank">LeetCode 14</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Apna College, SDE Sheet, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> strs = ["flower","flow","flight"]<br><b>Output:</b> "fl"</td>
      <td><b>Time:</b> O(N log N * M) (Constraint)<br><b>Space:</b> O(1) / O(M)</td>
      <td>Sort the array. The common prefix will be constrained by the first and last strings in the sorted array.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>No Match:</b> If the first character of `first` and `last` string doesn't match, loop breaks immediately, returning "".<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::string longestCommonPrefix(std::vector&lt;std::string&gt;&amp; strs) {&#10;    if (strs.empty()) return &quot;&quot;;&#10;    std::sort(strs.begin(), strs.end());&#10;    std::string first = strs.front();&#10;    std::string last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; i &lt; last.size() &amp;&amp; first[i] == last[i]) {&#10;        i++;&#10;    }&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Str 05 Longest Palindromic Substring<br><br></b> <a href="https://leetcode.com/problems/longest-palindromic-substring/" target="_blank">LeetCode 5</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Apna College, SDE Sheet, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "babad"<br><b>Output:</b> "bab"</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Expand Around Center. A palindrome can have an odd (center is 1 char) or even (center is between 2 chars) length. Test both.</td>
      <td><b>Edge Cases:</b> <b>Substr Math:</b> `start` is calculated as `i - (len - 1) / 2` to safely encompass both odd and even length centers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int expand(std::string&amp; s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}&#10;&#10;std::string longestPalindrome(std::string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, max_len = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expand(s, i, i);&#10;        int len2 = expand(s, i, i + 1);&#10;        int len = std::max(len1, len2);&#10;        if (len &gt; max_len) {&#10;            max_len = len;&#10;            start = i - (len - 1) / 2;&#10;        }&#10;    }&#10;    return s.substr(start, max_len);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Str 06 Kmp Algorithm<br><br></b> <a href="https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/" target="_blank">LeetCode 28</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> haystack = 'sadbutsad', needle = 'sad'<br><b>Output:</b> 0</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>Compute the LPS (Longest Proper Prefix which is also Suffix) array for the needle. Use the LPS array to skip characters while matching with the haystack, reducing time to O(N+M).<br><br><b>Dependencies:</b> <code>#include <vector></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int strStr(string haystack, string needle) {&#10;    if(needle.empty()) return 0;&#10;    int m = needle.length(), n = haystack.length();&#10;    vector&lt;int&gt; lps(m, 0);&#10;    int len = 0, i = 1;&#10;    while(i &lt; m) {&#10;        if(needle[i] == needle[len]) lps[i++] = ++len;&#10;        else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else lps[i++] = 0;&#10;        }&#10;    }&#10;    i = 0; int j = 0;&#10;    while(i &lt; n) {&#10;        if(needle[j] == haystack[i]) { i++; j++; }&#10;        if(j == m) return i - j;&#10;        else if(i &lt; n &amp;&amp; needle[j] != haystack[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Str 07 Rabin Karp<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4cea159/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Return array of starting indices.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Compute hash for pattern and first window of text. Slide window: subtract leading char's hash contribution, shift, and add trailing char. If hashes match, explicitly check strings to avoid collisions.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    vector&lt;int&gt; res;&#10;    int d = 256, q = 101;&#10;    int m = pat.length(), n = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    for(i=0; i&lt;m-1; i++) h = (h * d) % q;&#10;    for(i=0; i&lt;m; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for(i=0; i&lt;=n-m; i++) {&#10;        if(p == t) {&#10;            for(j=0; j&lt;m; j++) if(txt[i+j] != pat[j]) break;&#10;            if(j == m) res.push_back(i+1); // 1-based index usually&#10;        }&#10;        if(i &lt; n-m) {&#10;            t = (d * (t - txt[i] * h) + txt[i+m]) % q;&#10;            if(t &lt; 0) t += q;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Str 08 Reverse A String<br><br></b> <a href="https://leetcode.com/problems/reverse-string/" target="_blank">LeetCode 344</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers swap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers, `left` at the beginning and `right` at the end of the string. Swap the characters at these pointers and move them towards each other until they meet.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void reverseString(vector&lt;char&gt;&amp; s) {&#10;    int left = 0, right = s.size() - 1;&#10;    while(left &lt; right) {&#10;        swap(s[left++], s[right--]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Str 09 Palindrome String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindrome-string0817/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers, `left` at the beginning and `right` at the end of the string. Compare the characters at these pointers. If they are different, return 0. Move pointers towards each other. If all characters match, return 1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPalindrome(string S) {&#10;    int left = 0, right = S.length() - 1;&#10;    while(left &lt; right) {&#10;        if(S[left] != S[right]) return 0;&#10;        left++; right--;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Str 10 Find Duplicate Characters In A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-duplicate-characters-in-a-string/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Frequency array or Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a hash map or frequency array to count occurrences of each character. Then, iterate through the map/array and print characters with a count greater than 1.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDups(string str) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : str) count[c]++;&#10;    for(auto it : count) {&#10;        if(it.second &gt; 1) cout &lt;&lt; it.first &lt;&lt; &quot;, count = &quot; &lt;&lt; it.second &lt;&lt; &quot;\n&quot;;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Str 11 A Program To Check If Strings Are Rotations Of Each Other<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Concatenate and find.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If the lengths are different, return false. Otherwise, concatenate `s1` with itself (`s1 + s1`). If `s2` is a rotation of `s1`, it must be a substring of the concatenated string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool areRotations(string s1, string s2) {&#10;    if(s1.length() != s2.length()) return false;&#10;    string temp = s1 + s1;&#10;    return (temp.find(s2) != string::npos);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Str 12 Check If A String Is A Valid Shuffle Of Two Distinct Strings<br><br></b> <a href="https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings" target="_blank">Article</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Three pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>If lengths don't match, return false. Use three pointers `i`, `j`, `k` for `str1`, `str2`, and `str3`. Traverse `str3`. If `str3[k] == str1[i]`, increment `i` and `k`. Else if `str3[k] == str2[j]`, increment `j` and `k`. Else, it's not a valid shuffle. After the loop, check if both `str1` and `str2` are fully traversed.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkShuffle(string str1, string str2, string str3) {&#10;    if(str1.length() + str2.length() != str3.length()) return false;&#10;    int i = 0, j = 0, k = 0;&#10;    while(k &lt; str3.length()) {&#10;        if(i &lt; str1.length() &amp;&amp; str1[i] == str3[k]) i++;&#10;        else if(j &lt; str2.length() &amp;&amp; str2[j] == str3[k]) j++;&#10;        else return false;&#10;        k++;&#10;    }&#10;    return (i == str1.length() &amp;&amp; j == str2.length());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Str 13 Count And Say<br><br></b> <a href="https://leetcode.com/problems/count-and-say/" target="_blank">LeetCode 38</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Recursive generation.</td>
      <td><b>Time:</b> O(N * L) where L is max length of string<br><b>Space:</b> O(L)</td>
      <td>Start with `res = '1'`. For `n-1` times, iterate through `res` and count consecutive identical characters. Append the count and the character to a new string. Replace `res` with the new string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string countAndSay(int n) {&#10;    if(n == 1) return &quot;1&quot;;&#10;    string s = &quot;1&quot;;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        string temp = &quot;&quot;;&#10;        int count = 1;&#10;        for(int j = 1; j &lt; s.length(); j++) {&#10;            if(s[j] == s[j - 1]) count++;&#10;            else {&#10;                temp += to_string(count) + s[j - 1];&#10;                count = 1;&#10;            }&#10;        }&#10;        temp += to_string(count) + s.back();&#10;        s = temp;&#10;    }&#10;    return s;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Str 14 Longest Palindrome In A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Expand around center.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>For each character, treat it as the center of an odd-length palindrome and expand outwards. Also treat it and the next character as the center of an even-length palindrome and expand outwards. Keep track of the longest palindrome found.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestPalindrome(string S){&#10;    int start = 0, maxLen = 1, n = S.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int l = i, r = i;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;        l = i; r = i + 1;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;    }&#10;    return S.substr(start, maxLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Str 15 Find Longest Recurring Subsequence In String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Modified LCS.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2) or O(N)</td>
      <td>This is a variation of Longest Common Subsequence (LCS). Find LCS of `str` with itself, but with the restriction that when characters match, their indices must not be the same (`i != j`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestRepeatingSubsequence(string str) {&#10;    int n = str.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(str[i-1] == str[j-1] &amp;&amp; i != j) {&#10;                dp[i][j] = 1 + dp[i-1][j-1];&#10;            } else {&#10;                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);&#10;            }&#10;        }&#10;    }&#10;    return dp[n][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Str 16 Print All Subsequences Of A String<br><br></b> <a href="https://www.geeksforgeeks.org/print-subsequences-string/" target="_blank">Article</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Recursive choice (include/exclude).</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N) recursion stack</td>
      <td>Use recursion. At each character, you have two choices: either include it in the current subsequence or exclude it. When you reach the end of the string, print/store the formed subsequence.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string s, string curr, int i, vector&lt;string&gt;&amp; res) {&#10;    if(i == s.length()) {&#10;        if(curr != &quot;&quot;) res.push_back(curr);&#10;        return;&#10;    }&#10;    solve(s, curr, i + 1, res);&#10;    solve(s, curr + s[i], i + 1, res);&#10;}&#10;vector&lt;string&gt; allSubsequences(string s) {&#10;    vector&lt;string&gt; res;&#10;    solve(s, &quot;&quot;, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Str 17 Split The Binary String Into Substrings With Equal Number Of 0S And 1S<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Counter logic.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the string, maintain a count that increments for '0' and decrements for '1' (or vice versa). Whenever the count becomes 0, it means we have found a balanced substring, so increment the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubStr(string str) {&#10;    int count0 = 0, count1 = 0, ans = 0;&#10;    for(char c : str) {&#10;        if(c == &#x27;0&#x27;) count0++;&#10;        else count1++;&#10;        if(count0 == count1) ans++;&#10;    }&#10;    if(count0 != count1) return -1;&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Str 18 Word Wrap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/word-wrap1646/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> DP approach.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Use Dynamic Programming. `dp[i]` represents the minimum cost to wrap words from index `i` to the end. Iterate backward and try placing different numbers of words on the current line.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solveWordWrap(vector&lt;int&gt;nums, int k) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; dp(n, 0);&#10;    dp[n - 1] = 0;&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        int currlen = -1;&#10;        dp[i] = INT_MAX;&#10;        for(int j = i; j &lt; n; j++) {&#10;            currlen += (nums[j] + 1);&#10;            if(currlen &gt; k) break;&#10;            if(j == n - 1) dp[i] = 0;&#10;            else {&#10;                int cost = (k - currlen) * (k - currlen) + dp[j + 1];&#10;                dp[i] = min(dp[i], cost);&#10;            }&#10;        }&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Str 19 Edit Distance<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/edit-distance3702/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> DP Table.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>Create a 2D DP array. If characters match, `dp[i][j] = dp[i-1][j-1]`. If not, `dp[i][j] = 1 + min(replace, insert, delete)`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int editDistance(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 0; i &lt;= n; i++) dp[i][0] = i;&#10;    for(int j = 0; j &lt;= m; j++) dp[0][j] = j;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];&#10;            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Str 20 Next Permutation<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/next-permutation5226/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Swap and Reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse from right to find the first element smaller than the element to its right. Then, find the smallest element to its right that is greater than it. Swap them, and reverse the subarray after the first element's index.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; nextPermutation(int N, vector&lt;int&gt; arr){&#10;    int i = N - 2;&#10;    while(i &gt;= 0 &amp;&amp; arr[i] &gt;= arr[i + 1]) i--;&#10;    if(i &gt;= 0) {&#10;        int j = N - 1;&#10;        while(arr[j] &lt;= arr[i]) j--;&#10;        swap(arr[i], arr[j]);&#10;    }&#10;    reverse(arr.begin() + i + 1, arr.end());&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Str 21 Parenthesis Checker<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a stack to keep track of opening brackets. If a closing bracket is encountered, check if it matches the top of the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool ispar(string x) {&#10;    stack&lt;char&gt; s;&#10;    for(char c : x) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) s.push(c);&#10;        else {&#10;            if(s.empty()) return false;&#10;            if(c == &#x27;)&#x27; &amp;&amp; s.top() != &#x27;(&#x27;) return false;&#10;            if(c == &#x27;}&#x27; &amp;&amp; s.top() != &#x27;{&#x27;) return false;&#10;            if(c == &#x27;]&#x27; &amp;&amp; s.top() != &#x27;[&#x27;) return false;&#10;            s.pop();&#10;        }&#10;    }&#10;    return s.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Str 22 Word Break<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/word-break1352/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> SDE Sheet, Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Use `dp[i]` to indicate if `A[0..i]` can be segmented. For each `i`, check all prefixes `A[0..j]`. If `dp[j]` is true and `A[j..i]` is in the dictionary, then `dp[i]` is true.<br><br><b>Dependencies:</b> DP, Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int wordBreak(string A, vector&lt;string&gt; &amp;B) {&#10;    unordered_set&lt;string&gt; dict(B.begin(), B.end());&#10;    int n = A.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(A.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n] ? 1 : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Str 23 Rabin Karp Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Rolling Hash.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Compute the hash for the pattern and for the first window of text. Slide the window by removing the leading character's hash and adding the trailing character's hash. If hashes match, check the characters one by one.</td>
      <td><b>Edge Cases:</b> Collisions in Hash<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    int d = 256, q = 101;&#10;    int M = pat.length(), N = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    vector&lt;int&gt; res;&#10;    for (i = 0; i &lt; M - 1; i++) h = (h * d) % q;&#10;    for (i = 0; i &lt; M; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for (i = 0; i &lt;= N - M; i++) {&#10;        if (p == t) {&#10;            for (j = 0; j &lt; M; j++) {&#10;                if (txt[i + j] != pat[j]) break;&#10;            }&#10;            if (j == M) res.push_back(i + 1);&#10;        }&#10;        if (i &lt; N - M) {&#10;            t = (d * (t - txt[i] * h) + txt[i + M]) % q;&#10;            if (t &lt; 0) t = (t + q);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Str 24 Kmp Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/search-pattern0205/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> LPS Array.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>Construct an LPS (Longest Proper Prefix which is also Suffix) array for the pattern. Use it to skip unnecessary comparisons while traversing the text.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void computeLPS(string pat, int M, int* lps) {&#10;    int len = 0, i = 1;&#10;    lps[0] = 0;&#10;    while(i &lt; M) {&#10;        if(pat[i] == pat[len]) {&#10;            len++; lps[i] = len; i++;&#10;        } else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else { lps[i] = 0; i++; }&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; search(string pat, string txt) {&#10;    int M = pat.length(), N = txt.length();&#10;    int lps[M];&#10;    computeLPS(pat, M, lps);&#10;    int i = 0, j = 0;&#10;    vector&lt;int&gt; res;&#10;    while((N - i) &gt;= (M - j)) {&#10;        if(pat[j] == txt[i]) { j++; i++; }&#10;        if(j == M) {&#10;            res.push_back(i - j + 1);&#10;            j = lps[j - 1];&#10;        } else if(i &lt; N &amp;&amp; pat[j] != txt[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Str 25 Convert A Sentence Into Its Equivalent Mobile Numeric Keypad Sequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Dictionary Mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Store the sequence for every character in an array from A to Z, and for space. For each character in the input string, append its corresponding sequence to the result.</td>
      <td><b>Edge Cases:</b> Spaces<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string printSequence(string S) {&#10;    string str[] = {&quot;2&quot;, &quot;22&quot;, &quot;222&quot;, &quot;3&quot;, &quot;33&quot;, &quot;333&quot;, &quot;4&quot;, &quot;44&quot;, &quot;444&quot;, &quot;5&quot;, &quot;55&quot;, &quot;555&quot;, &quot;6&quot;, &quot;66&quot;, &quot;666&quot;, &quot;7&quot;, &quot;77&quot;, &quot;777&quot;, &quot;7777&quot;, &quot;8&quot;, &quot;88&quot;, &quot;888&quot;, &quot;9&quot;, &quot;99&quot;, &quot;999&quot;, &quot;9999&quot;};&#10;    string output = &quot;&quot;;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27; &#x27;) output += &quot;0&quot;;&#10;        else output += str[S[i] - &#x27;A&#x27;];&#10;    }&#10;    return output;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Str 26 Count The Reversals<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Remove all balanced brackets using a stack. The remaining string will be of the form `}}...{{...`. The required reversals will be `ceil(open_count/2) + ceil(close_count/2)`.<br><br><b>Dependencies:</b> Stack</td>
      <td><b>Edge Cases:</b> Odd length string<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countRev(string s) {&#10;    if(s.length() % 2 != 0) return -1;&#10;    stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;{&#x27;) st.push(c);&#10;        else {&#10;            if(!st.empty() &amp;&amp; st.top() == &#x27;{&#x27;) st.pop();&#10;            else st.push(c);&#10;        }&#10;    }&#10;    int open = 0, close = 0;&#10;    while(!st.empty()) {&#10;        if(st.top() == &#x27;{&#x27;) open++;&#10;        else close++;&#10;        st.pop();&#10;    }&#10;    return ceil(open / 2.0) + ceil(close / 2.0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Str 27 Count Palindromic Subsequences<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Dynamic Programming.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Use DP. `dp[i][j]` stores the count of palindromic subsequences in `str[i..j]`. If `str[i] == str[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. Else, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int countPS(string str) {&#10;    long long int MOD = 1e9 + 7;&#10;    int n = str.length();&#10;    vector&lt;vector&lt;long long int&gt;&gt; dp(n, vector&lt;long long int&gt;(n, 0));&#10;    for(int i = 0; i &lt; n; i++) dp[i][i] = 1;&#10;    for(int len = 2; len &lt;= n; len++) {&#10;        for(int i = 0; i &lt;= n - len; i++) {&#10;            int j = i + len - 1;&#10;            if(str[i] == str[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;&#10;            else dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD;&#10;        }&#10;    }&#10;    return dp[0][n - 1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Str 28 Count Of Number Of Given String In 2D Character Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(R * C * 4^L)<br><b>Space:</b> O(L)</td>
      <td>Use DFS. For each cell, if it matches the first character of the word, start a DFS to look for the rest of the word in all 4 directions. Keep track of visited cells.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int dfs(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string&amp; target, int r, int c, int idx) {&#10;    if(idx == target.length()) return 1;&#10;    if(r &lt; 0 || r &gt;= mat.size() || c &lt; 0 || c &gt;= mat[0].size() || mat[r][c] != target[idx]) return 0;&#10;    char temp = mat[r][c];&#10;    mat[r][c] = &#x27;#&#x27;;&#10;    int found = dfs(mat, target, r + 1, c, idx + 1) +&#10;                dfs(mat, target, r - 1, c, idx + 1) +&#10;                dfs(mat, target, r, c + 1, idx + 1) +&#10;                dfs(mat, target, r, c - 1, idx + 1);&#10;    mat[r][c] = temp;&#10;    return found;&#10;}&#10;int findOccurrence(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string target) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; mat.size(); i++) {&#10;        for(int j = 0; j &lt; mat[0].size(); j++) {&#10;            if(mat[i][j] == target[0]) {&#10;                count += dfs(mat, target, i, j, 0);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Str 29 Search A Word In A 2D Grid Of Characters<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> 8 Directions Loop.</td>
      <td><b>Time:</b> O(N * M * 8 * L)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the grid. For each matching starting character, check all 8 directions to see if the full word exists in a straight line.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; searchWord(vector&lt;vector&lt;char&gt;&gt; grid, string word){&#10;    int R = grid.size(), C = grid[0].size(), L = word.length();&#10;    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};&#10;    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(int r = 0; r &lt; R; r++) {&#10;        for(int c = 0; c &lt; C; c++) {&#10;            if(grid[r][c] == word[0]) {&#10;                for(int dir = 0; dir &lt; 8; dir++) {&#10;                    int k, currR = r + dr[dir], currC = c + dc[dir];&#10;                    for(k = 1; k &lt; L; k++) {&#10;                        if(currR &lt; 0 || currR &gt;= R || currC &lt; 0 || currC &gt;= C) break;&#10;                        if(grid[currR][currC] != word[k]) break;&#10;                        currR += dr[dir]; currC += dc[dir];&#10;                    }&#10;                    if(k == L) {&#10;                        ans.push_back({r, c});&#10;                        break;&#10;                    }&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Str 30 Boyer Moore Algorithm For Pattern Searching<br><br></b> <a href="https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Bad Character Heuristic.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(256)</td>
      <td>Create a Bad Character table for the pattern, which stores the last occurrence of each character. Align pattern with text. Compare from right to left. If mismatch, shift the pattern so that the mismatched character in text aligns with its last occurrence in the pattern. If not present, shift pattern past it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void search(string txt, string pat) {&#10;    int m = pat.length(), n = txt.length();&#10;    int badChar[256];&#10;    for(int i = 0; i &lt; 256; i++) badChar[i] = -1;&#10;    for(int i = 0; i &lt; m; i++) badChar[(int)pat[i]] = i;&#10;    int s = 0;&#10;    while(s &lt;= (n - m)) {&#10;        int j = m - 1;&#10;        while(j &gt;= 0 &amp;&amp; pat[j] == txt[s + j]) j--;&#10;        if(j &lt; 0) {&#10;            cout &lt;&lt; &quot;Pattern occurs at shift = &quot; &lt;&lt; s &lt;&lt; endl;&#10;            s += (s + m &lt; n) ? m - badChar[txt[s + m]] : 1;&#10;        } else {&#10;            s += max(1, j - badChar[txt[s + j]]);&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Str 31 Roman Number To Integer<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Value mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Map each Roman numeral to its integer value. Iterate from right to left. If a character is smaller than its right character, subtract its value, else add it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int romanToDecimal(string &amp;str) {&#10;    unordered_map&lt;char, int&gt; m = {{&#x27;I&#x27;, 1}, {&#x27;V&#x27;, 5}, {&#x27;X&#x27;, 10}, {&#x27;L&#x27;, 50}, {&#x27;C&#x27;, 100}, {&#x27;D&#x27;, 500}, {&#x27;M&#x27;, 1000}};&#10;    int ans = 0, n = str.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i + 1 &lt; n &amp;&amp; m[str[i]] &lt; m[str[i+1]]) ans -= m[str[i]];&#10;        else ans += m[str[i]];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Str 32 Number Of Flips To Make Binary String Alternate<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Two target strings.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>There are only two possible alternating strings for length N: starting with '0' (`010101...`) and starting with '1' (`101010...`). Count the differences between the given string and both of these. The minimum count is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFlips(string S) {&#10;    int count1 = 0, count2 = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(i % 2 == 0) {&#10;            if(S[i] != &#x27;0&#x27;) count1++;&#10;            if(S[i] != &#x27;1&#x27;) count2++;&#10;        } else {&#10;            if(S[i] != &#x27;1&#x27;) count1++;&#10;            if(S[i] != &#x27;0&#x27;) count2++;&#10;        }&#10;    }&#10;    return min(count1, count2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Str 33 Find The First Repeated Word In String<br><br></b> <a href="https://www.geeksforgeeks.org/find-first-repeated-word-string/" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Split the string into words. Iterate through the words. If a word is already in the hash set, it is the first repeated word. Return it. Else, add it to the hash set.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string firstRepeatedWord(string s) {&#10;    unordered_set&lt;string&gt; st;&#10;    string word = &quot;&quot;;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(s[i] == &#x27; &#x27; || s[i] == &#x27;\t&#x27; || s[i] == &#x27;,&#x27; || s[i] == &#x27;:&#x27; || s[i] == &#x27;.&#x27; || s[i] == &#x27;-&#x27;) {&#10;            if(word != &quot;&quot;) {&#10;                if(st.find(word) != st.end()) return word;&#10;                st.insert(word);&#10;                word = &quot;&quot;;&#10;            }&#10;        } else word += s[i];&#10;    }&#10;    if(word != &quot;&quot; &amp;&amp; st.find(word) != st.end()) return word;&#10;    return &quot;No Repetition&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Str 34 Minimum Swaps For Bracket Balancing<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td rowspan="1"><b>Example 1:</b> Track balance.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Keep track of the number of opening and closing brackets, and an `imbalance` counter. When encountering `[`, decrease imbalance. When encountering `]`, increase imbalance. The number of swaps is updated when an imbalance is found and we find the next `[`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumNumberOfSwaps(string S){&#10;    int open = 0, close = 0, fault = 0, ans = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27;]&#x27;) {&#10;            close++;&#10;            fault = close - open;&#10;        } else {&#10;            open++;&#10;            if(fault &gt; 0) {&#10;                ans += fault;&#10;                fault--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Str 35 Isomorphic Strings<br><br></b> <a href="https://leetcode.com/problems/isomorphic-strings/" target="_blank">LeetCode 205</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> Hash Maps.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two arrays to map characters from `s` to `t` and `t` to `s`. If `s[i]` is mapped to a character other than `t[i]`, or `t[i]` is mapped to a character other than `s[i]`, return false. Else, create the mappings.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isIsomorphic(string s, string t) {&#10;    vector&lt;int&gt; m1(256, -1), m2(256, -1);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(m1[s[i]] != m2[t[i]]) return false;&#10;        m1[s[i]] = i;&#10;        m2[t[i]] = i;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Str 36 Reverse Words In A String<br><br></b> <a href="https://leetcode.com/problems/reverse-words-in-a-string/" target="_blank">LeetCode 151</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output string</td>
      <td>Iterate from right to left. Find the end of a word, then the start of a word. Extract the word and append it to the result string along with a space. Finally, remove the trailing space.</td>
      <td><b>Edge Cases:</b> Multiple spaces between words<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reverseWords(string s) {&#10;    string result = &quot;&quot;;&#10;    int i = s.length() - 1;&#10;    while(i &gt;= 0) {&#10;        while(i &gt;= 0 &amp;&amp; s[i] == &#x27; &#x27;) i--;&#10;        if(i &lt; 0) break;&#10;        int j = i;&#10;        while(i &gt;= 0 &amp;&amp; s[i] != &#x27; &#x27;) i--;&#10;        result += s.substr(i + 1, j - i) + &quot; &quot;;&#10;    }&#10;    if(!result.empty()) result.pop_back();&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Str 37 Rotate String<br><br></b> <a href="https://leetcode.com/problems/rotate-string/" target="_blank">LeetCode 796</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td rowspan="1"><b>Example 1:</b> String Concatenation.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If the lengths of `s` and `goal` are not equal, return false. Otherwise, concatenate `s` with itself (`s + s`). If `goal` is a substring of `s + s`, then it's a rotated string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool rotateString(string s, string goal) {&#10;    if(s.length() != goal.length()) return false;&#10;    string doubleS = s + s;&#10;    return doubleS.find(goal) != string::npos;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Str 38 String To Integer Atoi<br><br></b> <a href="https://leetcode.com/problems/string-to-integer-atoi/" target="_blank">LeetCode 8</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td rowspan="1"><b>Example 1:</b> Step-by-step parsing.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>1. Ignore leading whitespaces. 2. Check for optional '+' or '-'. 3. Read digits until a non-digit or end of string. 4. Build the integer, checking for 32-bit integer overflow/underflow at each step.</td>
      <td><b>Edge Cases:</b> Overflow/Underflow<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int myAtoi(string s) {&#10;    int i = 0, n = s.length(), sign = 1;&#10;    long long ans = 0;&#10;    while(i &lt; n &amp;&amp; s[i] == &#x27; &#x27;) i++;&#10;    if(i &lt; n &amp;&amp; (s[i] == &#x27;+&#x27; || s[i] == &#x27;-&#x27;)) {&#10;        sign = (s[i] == &#x27;-&#x27;) ? -1 : 1;&#10;        i++;&#10;    }&#10;    while(i &lt; n &amp;&amp; isdigit(s[i])) {&#10;        ans = ans * 10 + (s[i] - &#x27;0&#x27;);&#10;        if(sign == 1 &amp;&amp; ans &gt; INT_MAX) return INT_MAX;&#10;        if(sign == -1 &amp;&amp; -ans &lt; INT_MIN) return INT_MIN;&#10;        i++;&#10;    }&#10;    return sign * ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
