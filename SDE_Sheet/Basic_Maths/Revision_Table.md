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
      <td rowspan="1">1</td>
      <td rowspan="1">Math 01 Count Digits<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-digits5716/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N = 12345, Output: 5</td>
      <td><b>Time:</b> O(log10 N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>N=0:</b> Handled naturally if checking N > 0, otherwise special condition.</td>
      <td><b>Explanation:</b> Convert to string and return length, or repeatedly divide by 10. O(log10 N) time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evenlyDivides(int N){&#10;    if (N == 0) return 1;&#10;    int count = 0, temp = N;&#10;    while(temp &gt; 0) {&#10;        int digit = temp % 10;&#10;        if (digit != 0 &amp;&amp; N % digit == 0) count++;&#10;        temp /= 10;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Math 02 Reverse Integer<br><br></b> <a href='https://leetcode.com/problems/reverse-integer/' target='_blank'>LeetCode 7</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: x = 123, Output: 321</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>Overflow:</b> If ans > INT_MAX/10, return 0.</td>
      <td><b>Explanation:</b> Extract last digit using modulo, multiply answer by 10 and add. Check bounds for 32-bit integer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    int ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        if(ans &gt; INT_MAX/10 || ans &lt; INT_MIN/10) return 0;&#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Math 03 Palindrome Number<br><br></b> <a href='https://leetcode.com/problems/palindrome-number/' target='_blank'>LeetCode 9</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: x = 121, Output: true</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Negative Numbers:</b> Instant false. Trailing zeroes instant false.</td>
      <td><b>Explanation:</b> Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int x) {&#10;    if(x &lt; 0 || (x % 10 == 0 &amp;&amp; x != 0)) return false;&#10;    int reversedHalf = 0;&#10;    while(x &gt; reversedHalf) {&#10;        reversedHalf = reversedHalf * 10 + x % 10;&#10;        x /= 10;&#10;    }&#10;    return x == reversedHalf || x == reversedHalf / 10;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Math 04 Gcd Or Hcf<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: A = 4, B = 8, Output: 4</td>
      <td><b>Time:</b> O(log(min(a,b)))<br><b>Space:</b> O(1)</td>
      <td><code>#include <numeric></code></td>
      <td><b>One is 0:</b> Return the other number.</td>
      <td><b>Explanation:</b> Euclidean Algorithm. gcd(a, b) = gcd(b, a % b). Stop when one is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long gcd(long long a, long long b) {&#10;    while (a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        if (a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    return a == 0 ? b : a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Math 05 Check For Prime<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/prime-number2314/1' target='_blank'>GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N = 5, Output: 1</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>N=1:</b> Not prime.</td>
      <td><b>Explanation:</b> Check divisibility up to sqrt(N).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i=2; i*i&lt;=N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
