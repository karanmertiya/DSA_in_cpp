# Basic Maths Revision Table

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
      <td rowspan="3">1</td>
      <td rowspan="3">Math 01 Count Digits</td>
      <td rowspan="3"><b>Example 1:</b> Input: N = 12345, Output: 5<br><b>Example 2:</b> Input: N = -8394, Output: 4<br><br><b>Note (Constraint):</b> -10<sup>9</sup> &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Sign Handle:</b><br><code>if (n == 0) return 1;</code><br><code>n = abs(n);</code></td>
      <td><b>Explanation:</b> Divide by 10 continuously until N becomes 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;cmath&gt;&#10;&#10;int countDigitsBrute(int n) {&#10;    // Edge Case: 0 has 1 digit, negative numbers require abs()&#10;    if (n == 0) return 1;&#10;    n = abs(n);&#10;    int cnt = 0;&#10;    while(n &gt; 0) {&#10;        cnt++;&#10;        n = n / 10;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(log10(N)) (Trade-off)</td>
      <td><b>Type Casting:</b><br><code>to_string()</code> / <code>str()</code></td>
      <td><b>Sign Handle:</b><br><code>n = abs(n);</code></td>
      <td><b>Explanation:</b> Convert number to string and return length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;cmath&gt;&#10;&#10;int countDigitsBetter(int n) {&#10;    if (n == 0) return 1;&#10;    // Trade-off: Allocates string memory&#10;    string s = to_string(abs(n));&#10;    return s.length();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Math Lib:</b><br><code>log10()</code></td>
      <td><b>Sign Handle:</b><br><code>n = abs(n);</code></td>
      <td><b>Explanation:</b> Use base-10 logarithm to find digit count mathematically.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;cmath&gt;&#10;&#10;int countDigitsOptimal(int n) {&#10;    if (n == 0) return 1;&#10;    n = abs(n);&#10;    int cnt = (int)(log10(n) + 1);&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Math 02 Reverse A Number</td>
      <td rowspan="2"><b>Example 1:</b> Input: N = 1234, Output: 4321<br><b>Example 2:</b> Input: N = -10400, Output: -401<br><br><b>Note (Constraint):</b> -2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(log10(N)) (Trade-off)</td>
      <td><b>String Lib:</b><br><code>reverse()</code>, <code>stoi()</code></td>
      <td><b>Negative Signs:</b> Reversing a '-' results in invalid parsing. Store sign, process <code>abs(n)</code>.</td>
      <td><b>Explanation:</b> Convert to string, reverse the string, and parse back to integer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;int reverseNumberBrute(int n) {&#10;    // Edge Case: Explicitly store and remove sign before string conversion&#10;    bool isNeg = n &lt; 0;&#10;    string s = to_string(abs(n));&#10;    reverse(s.begin(), s.end());&#10;    // Exception handling ignored for brevity in brute force&#10;    long long res = stoll(s);&#10;    if (res &gt; INT_MAX) return 0;&#10;    return isNeg ? -res : res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Data-type Agnostic Overflow Check:</b><br><code>temp / 10 != revNum</code></td>
      <td><b>Explanation:</b> Extract digits using modulo 10 and build the reversed number mathematically.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverseNumberOptimal(int n) {&#10;    int revNum = 0;&#10;    while(n != 0) {&#10;        int ld = n % 10;&#10;        // Edge Case: Type-agnostic overflow check utilizing reverse operation mismatch&#10;        int temp = revNum * 10 + ld;&#10;        if (temp / 10 != revNum) return 0;&#10;        revNum = temp;&#10;        n = n / 10;&#10;    }&#10;    return revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">3</td>
      <td rowspan="2">Math 03 Check Palindrome</td>
      <td rowspan="2"><b>Example 1:</b> Input: N = 121, Output: true<br><b>Example 2:</b> Input: N = -121, Output: false<br><br><b>Note (Constraint):</b> -2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(log10(N)) (Trade-off)</td>
      <td><b>String Lib:</b><br><code>to_string()</code>, <code>reverse()</code></td>
      <td><b>Negative Numbers:</b> Naturally handled by string equality (`-121` != `121-`)</td>
      <td><b>Explanation:</b> Convert the number to a string and compare it with its reversed version.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;string&gt;&#10;#include &lt;algorithm&gt;&#10;&#10;bool isPalindromeBrute(int n) {&#10;    string s1 = to_string(n);&#10;    string s2 = s1;&#10;    reverse(s2.begin(), s2.end());&#10;    return s1 == s2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>State Preservation:</b> Loop destroys `n`, requires `dup` variable.<br><b>Negative Signs:</b><br><code>if(n < 0) return false;</code></td>
      <td><b>Explanation:</b> Reverse the number mathematically and compare it to the original.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindromeOptimal(int n) {&#10;    // Edge Case: Negative numbers are strictly not palindromes&#10;    if (n &lt; 0) return false;&#10;    &#10;    int dup = n;&#10;    long long revNum = 0;&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        revNum = (revNum * 10) + ld;&#10;        n = n / 10;&#10;    }&#10;    return dup == revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Math 05 Armstrong Numbers</td>
      <td rowspan="1"><b>Example 1:</b> Input: N = 153, Output: true<br><b>Example 2:</b> Input: N = 1634, Output: true<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td><b>Math Lib:</b><br><code>log10()</code>, <code>pow()</code>, <code>round()</code></td>
      <td><b>Two-Pass Logic:</b> Requires digit count upfront (e.g. 1634 requires ^4).</td>
      <td><b>Explanation:</b> Extract digit count first, then mathematically sum digits raised to that count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;cmath&gt;&#10;&#10;bool isArmstrong(int n) {&#10;    int dup = n;&#10;    int sum = 0;&#10;    int digits = (int)(log10(n) + 1);&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        // Edge Case: pow() uses floats, round() ensures accuracy before int conversion&#10;        sum += round(pow(ld, digits));&#10;        n = n / 10;&#10;    }&#10;    return sum == dup;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">5</td>
      <td rowspan="2">Math 07 Check For Prime</td>
      <td rowspan="2"><b>Example 1:</b> Input: N = 11, Output: true<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(N) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>TLE Guarantee:</b> N=10^9 takes ~10<sup>9</sup> ops. Fails tight bounds.</td>
      <td><b>Explanation:</b> Iterate from 2 to N-1 and check divisibility.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeBrute(int n) {&#10;    if (n &lt;= 1) return false;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(&radic;N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Math Optimization:</b> <code>i * i <= n</code> prevents floating point <code>sqrt(n)</code> overhead.<br><br><b>Skipping Evens:</b> <code>if(n%2==0) return false;</code> halves the loop size.</td>
      <td><b>Explanation:</b> Iterate from 2 up to sqrt(N) checking divisor pairs.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeOptimal(int n) {&#10;    if(n &lt;= 1) return false;&#10;    if(n == 2) return true;&#10;    // Edge Case Optimization: Halve range by skipping evens&#10;    if(n % 2 == 0) return false;&#10;    // Edge Case Optimization: Avoid floating point sqrt overhead by squaring i&#10;    for(int i = 3; i * i &lt;= n; i += 2) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
