# Master DSA Master Revision Table

## Basic Maths

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
      <td rowspan="3">1</td>
      <td rowspan="3">Math 01 Count Digits<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-digits5716/1" target="_blank">GFG</a></td>
      <td rowspan="3"><b>Example 1:</b> <br><b>Input:</b> N = 12345<br><b>Output:</b> 5</td>
      <td><b>Time:</b> O(log<sub>10</sub> N)<br><b>Space:</b> O(log<sub>10</sub> N)</td>
      <td><b>Approach 1:</b><br>Convert the absolute value of the number to a string and return its length.<br><br><b>Dependencies:</b> <code>#include &lt;string&gt;</code>
<code>#include &lt;cmath&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Negative Numbers:</b> Use abs(n) to avoid counting the minus sign.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    return to_string(abs(n)).length();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log<sub>10</sub> N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use a while loop to repeatedly divide the number by 10 and increment a counter.</td>
      <td><b>Edge Cases:</b> <b>Zero Case:</b> Handle 0 explicitly.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    if (n == 0) return 1;&#10;    int count = 0;&#10;    while(n != 0) {&#10;        count++;&#10;        n /= 10;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log<sub>10</sub> N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 3:</b><br>Use the base-10 logarithm function to find the number of digits mathematically.<br><br><b>Dependencies:</b> <code>#include &lt;cmath&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Zero Case:</b> Handle 0 explicitly since log10(0) is undefined.<br><b>Negative Numbers:</b> Use abs(n) before logarithm.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    if (n == 0) return 1;&#10;    return (int)(log10(abs(n)) + 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Math 02 Reverse Integer<br><br></b> <a href="https://leetcode.com/problems/reverse-integer/" target="_blank">LeetCode 7</a></td>
      <td rowspan="2"><b>Example 1:</b> <br><b>Input:</b> x = 123<br><b>Output:</b> 321</td>
      <td><b>Time:</b> O(log<sub>10</sub> x)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Optimal Approach: Use a 64-bit integer to naturally store the reversed number. A variant note explains how to do this strictly with 32-bit integers if long is not allowed.<br><br><b>Dependencies:</b> <code>#include &lt;limits.h&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Overflow:</b> Checked using 64-bit bounds or 32-bit variants.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    long long ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        &#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    if(ans &gt; INT_MAX || ans &lt; INT_MIN) return 0;&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log<sub>10</sub> x)<br><b>Space:</b> O(log<sub>10</sub> x)</td>
      <td><b>Approach 2:</b><br>Brute Force / String Approach: Convert to string, reverse, and then parse back to integer.<br><br><b>Dependencies:</b> <code>#include &lt;string&gt;</code>
<code>#include &lt;algorithm&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Overflow:</b> Must be caught via exception handling (stoll).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    string s = to_string(abs(x));&#10;    std::reverse(s.begin(), s.end());&#10;    try {&#10;        long long rev = stoll(s);&#10;        if (x &lt; 0) rev = -rev;&#10;        if (rev &gt; INT_MAX || rev &lt; INT_MIN) return 0;&#10;        return rev;&#10;    } catch (...) {&#10;        return 0;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Math 03 Palindrome Number<br><br></b> <a href="https://leetcode.com/problems/palindrome-number/" target="_blank">LeetCode 9</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> x = 121<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log<sub>10</sub> x)<br><b>Space:</b> O(1)</td>
      <td>Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.</td>
      <td><b>Edge Cases:</b> <b>Negative Numbers:</b> Instant false. Trailing zeroes instant false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int x) {&#10;    if(x &lt; 0 || (x % 10 == 0 &amp;&amp; x != 0)) return false;&#10;    int reversedHalf = 0;&#10;    while(x &gt; reversedHalf) {&#10;        reversedHalf = reversedHalf * 10 + x % 10;&#10;        x /= 10;&#10;    }&#10;    return x == reversedHalf || x == reversedHalf / 10;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Math 04 Gcd Or Hcf<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b>Example 1:</b> <br><b>Input:</b> A = 4, B = 8<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(min(a, b))<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Iterate from 1 to min(a, b) and find the highest number that divides both.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; lcmAndGcd(long long a, long long b) {&#10;    long long gcd = 1;&#10;    for(long long i = 1; i &lt;= min(a, b); i++) {&#10;        if(a % i == 0 &amp;&amp; b % i == 0) gcd = i;&#10;    }&#10;    long long lcm = (a / gcd) * b; // Divide first to prevent overflow&#10;    return {lcm, gcd};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log(min(a, b)))<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Euclidean Algorithm (Optimal): Repeatedly replace max(a,b) with max(a,b) % min(a,b). The final non-zero value is the GCD. Note: LCM can be found in O(1) extra time using formula: LCM(a,b) = (a*b) / GCD(a,b)<br><br><b>Dependencies:</b> <code>#include &lt;algorithm&gt;</code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; lcmAndGcd(long long a, long long b) {&#10;    long long original_a = a, original_b = b;&#10;    while(a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        if(a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    /* The non-zero value is the GCD. Since one of them is 0, we can just return a + b */&#10;    long long gcd = a + b; &#10;    long long lcm = (original_a / gcd) * original_b; // Divide first to prevent overflow&#10;    return {lcm, gcd};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Math 05 Check For Prime<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/prime-number2314/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N = 5<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td>Check divisibility up to sqrt(N). Iterating up to N (O(N) time) is unnecessary and inefficient since factors always appear in pairs.</td>
      <td><b>Edge Cases:</b> <b>N=1:</b> Not prime.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i=2; i*i&lt;=N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Math 06 Factorial Trailing Zeroes<br><br></b> <a href="https://leetcode.com/problems/factorial-trailing-zeroes/" target="_blank">LeetCode 172</a><br><br><details><summary>ℹ️ Concept / Details</summary>A trailing zero is produced by a factor of 10. Since 10 = 2 * 5, and 2s are more abundant than 5s in factorials, we only need to count the number of 5s.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 5<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(log_5(N))<br><b>Space:</b> O(1)</td>
      <td>Trailing zeroes are produced by 10s, which are pairs of 2 and 5. Since 2s are more frequent, we just count the number of 5s in prime factors of numbers up to N. This is `N/5 + N/25 + N/125 + ...`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trailingZeroes(int n) {&#10;    int count = 0;&#10;    while(n &gt; 0) {&#10;        count += n / 5;&#10;        n /= 5;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Math 07 Count Primes<br><br></b> <a href="https://leetcode.com/problems/count-primes/" target="_blank">LeetCode 204</a><br><br><details><summary>ℹ️ Concept / Details</summary><b>Sieve of Eratosthenes:</b> An ancient algorithm for finding all prime numbers up to any given limit. It iteratively marks as composite (i.e., not prime) the multiples of each prime.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 10<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td>Use the Sieve of Eratosthenes. Initialize a boolean array of size `n` with `true`. Mark `0` and `1` as `false`. For each `i` from `2` to `sqrt(n)`, if `i` is prime, mark its multiples as `false` starting from `i*i`. Finally, count the number of `true`s.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPrimes(int n) {&#10;    if(n &lt;= 2) return 0;&#10;    vector&lt;bool&gt; isPrime(n, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt; n; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt; n; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    int count = 0;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(isPrime[i]) count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Math 08 Valid Perfect Square<br><br></b> <a href="https://leetcode.com/problems/valid-perfect-square/" target="_blank">LeetCode 367</a><br><br><details><summary>ℹ️ Concept / Details</summary>A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself (e.g., 1, 4, 9, 16).</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> num = 16<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Use binary search from `1` to `num/2` or up to `46340` (sqrt of INT_MAX). If `mid * mid == num`, return true. Else if `mid * mid < num`, `low = mid + 1`. Else `high = mid - 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPerfectSquare(int num) {&#10;    if(num == 1) return true;&#10;    long long low = 1, high = num / 2;&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        if(mid * mid == num) return true;&#10;        else if(mid * mid &lt; num) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Math 09 Power Of Two<br><br></b> <a href="https://leetcode.com/problems/power-of-two/" target="_blank">LeetCode 231</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 1<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>If a number is a power of two, it has exactly one bit set in its binary representation. The expression `n & (n - 1)` clears the lowest set bit. Thus, if `n > 0` and `(n & (n - 1)) == 0`, it is a power of two.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwo(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">10</td>
      <td rowspan="2">Math 10 Power Of Three<br><br></b> <a href="https://leetcode.com/problems/power-of-three/" target="_blank">LeetCode 326</a></td>
      <td rowspan="2"><b>Example 1:</b> <br><b>Input:</b> n = 27<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log_3 N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>General Method: Repeatedly divide the number by 3 as long as it is divisible by 3. If it becomes 1, it's a power of 3.</td>
      <td><b>Edge Cases:</b> <b>N <= 0:</b> Not a power of 3.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfThree(int n) {&#10;    if (n &lt;= 0) return false;&#10;    while (n % 3 == 0) n /= 3;&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Since `n` is a 32-bit signed integer, the largest power of 3 that fits is `3^19 = 1162261467`. A number `n` is a power of 3 if `n > 0` and `1162261467 % n == 0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfThree(int n) {&#10;    return n &gt; 0 &amp;&amp; 1162261467 % n == 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Math 11 Power Of Four<br><br></b> <a href="https://leetcode.com/problems/power-of-four/" target="_blank">LeetCode 342</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 16<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>A power of 4 is also a power of 2, so `n > 0 && (n & (n-1)) == 0` must hold. Also, the single set bit must be at an even position (0-indexed). The mask `0x55555555` has 1s at all even positions. So `(n & 0x55555555) != 0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfFour(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0 &amp;&amp; (n &amp; 0x55555555) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Math 12 Add Digits<br><br></b> <a href="https://leetcode.com/problems/add-digits/" target="_blank">LeetCode 258</a><br><br><details><summary>ℹ️ Concept / Details</summary><b>Digital Root:</b> The digital root of a non-negative integer is the single-digit value obtained by an iterative process of summing digits. Formula: `1 + (n - 1) % 9`.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> num = 38<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>This is known as the digital root. The formula is `1 + (n - 1) % 9`. If `n == 0`, return `0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int addDigits(int num) {&#10;    if(num == 0) return 0;&#10;    return 1 + (num - 1) % 9;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Math 13 Ugly Number<br><br></b> <a href="https://leetcode.com/problems/ugly-number/" target="_blank">LeetCode 263</a><br><br><details><summary>ℹ️ Concept / Details</summary>An ugly number is a number whose only prime factors are 2, 3, and 5.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 6<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>If `n <= 0`, return false. Divide `n` by 2, 3, and 5 as long as it is divisible. If the remaining number is 1, it's an ugly number, else false.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isUgly(int n) {&#10;    if(n &lt;= 0) return false;&#10;    vector&lt;int&gt; primes = {2, 3, 5};&#10;    for(int p : primes) {&#10;        while(n % p == 0) n /= p;&#10;    }&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Math 14 Perfect Number<br><br></b> <a href="https://leetcode.com/problems/perfect-number/" target="_blank">LeetCode 507</a><br><br><details><summary>ℹ️ Concept / Details</summary>A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For example, 28 = 1 + 2 + 4 + 7 + 14.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> num = 28<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td>If `num <= 1`, return false. Iterate up to `sqrt(num)`. If `i` divides `num`, add `i` and `num/i` to the sum. After the loop, compare sum with `num`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPerfectNumber(int num) {&#10;    if(num &lt;= 1) return false;&#10;    int sum = 1;&#10;    for(int i = 2; i * i &lt;= num; i++) {&#10;        if(num % i == 0) {&#10;            sum += i;&#10;            if(i * i != num) sum += num / i;&#10;        }&#10;    }&#10;    return sum == num;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Math 15 Excel Sheet Column Title<br><br></b> <a href="https://leetcode.com/problems/excel-sheet-column-title/" target="_blank">LeetCode 168</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> columnNumber = 28<br><b>Output:</b> "AB"</td>
      <td><b>Time:</b> O(log_26(N))<br><b>Space:</b> O(1)</td>
      <td>This is essentially base 26 conversion, but 1-indexed (A=1, B=2, Z=26). To make it 0-indexed, decrement `columnNumber` by 1 at each step, get the remainder modulo 26, convert to character, and divide by 26.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string convertToTitle(int columnNumber) {&#10;    string res = &quot;&quot;;&#10;    while(columnNumber &gt; 0) {&#10;        columnNumber--;&#10;        res += (char)(&#x27;A&#x27; + (columnNumber % 26));&#10;        columnNumber /= 26;&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">16</td>
      <td rowspan="2">Math 16 Pow X N<br><br></b> <a href="https://leetcode.com/problems/powx-n/" target="_blank">LeetCode 50</a></td>
      <td rowspan="2"><b>Example 1:</b> <br><b>Input:</b> x = 2.00000, n = 10<br><b>Output:</b> 1024.00000</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Loop n times and multiply ans by x.</td>
      <td><b>Edge Cases:</b> TLE for large N.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    for(int i = 0; i &lt; nn; i++) {&#10;        ans *= x;&#10;    }&#10;    return n &lt; 0 ? 1.0 / ans : ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Optimal: Binary Exponentiation. If n is even, x = x*x, n = n/2. If odd, ans = ans*x, n = n-1.</td>
      <td><b>Edge Cases:</b> Negative power, n = INT_MIN<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    while(nn &gt; 0) {&#10;        if(nn % 2 == 1) {&#10;            ans = ans * x;&#10;            nn = nn - 1;&#10;        } else {&#10;            x = x * x;&#10;            nn = nn / 2;&#10;        }&#10;    }&#10;    if(n &lt; 0) ans = (double)(1.0) / (double)(ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Math 17 Sieve Of Eratosthenes<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N = 10<br><b>Output:</b> 2 3 5 7</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td>Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; sieveOfEratosthenes(int N) {&#10;    vector&lt;int&gt; primes;&#10;    vector&lt;bool&gt; isPrime(N + 1, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt;= N; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    for(int i = 2; i &lt;= N; i++) {&#10;        if(isPrime[i]) primes.push_back(i);&#10;    }&#10;    return primes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Math 18 Prime Factors<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/prime-factors5052/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N = 100<br><b>Output:</b> 2 2 5 5</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1) excluding output</td>
      <td>Iterate from `i = 2` to `sqrt(N)`. If `N % i == 0`, `i` is a prime factor. Add `i` to result, and repeatedly divide `N` by `i` until it's no longer divisible. After the loop, if `N > 1`, then `N` itself is a prime factor and should be added.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; AllPrimeFactors(int N) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(N % i == 0) {&#10;            ans.push_back(i);&#10;            while(N % i == 0) N /= i;&#10;        }&#10;    }&#10;    if(N &gt; 1) ans.push_back(N);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Math 19 Print All Divisors<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-all-divisors-of-a-number/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N = 36<br><b>Output:</b> 1 2 3 4 6 9 12 18 36</td>
      <td><b>Time:</b> O(sqrt(N) + k log k)<br><b>Space:</b> O(k)</td>
      <td>Iterate up to sqrt(N). If 'i' divides N, then 'N/i' is also a divisor. Iterating up to N (O(N) time) is unnecessary and inefficient.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void print_divisors(int n) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            ans.push_back(i);&#10;            if(n / i != i) ans.push_back(n / i);&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    for(int x : ans) cout &lt;&lt; x &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Math 20 Armstrong Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 153<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log<sub>10</sub>(N))<br><b>Space:</b> O(1)</td>
      <td>Extract each digit, cube it, and sum them up. If the sum equals the original number, it's an Armstrong number.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string armstrongNumber(int n) {&#10;    int original = n, sum = 0;&#10;    while(n &gt; 0) {&#10;        int digit = n % 10;&#10;        sum += (digit * digit * digit);&#10;        n /= 10;&#10;    }&#10;    return sum == original ? &quot;Yes&quot; : &quot;No&quot;;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Bit Manipulation

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
      <td rowspan="2">1</td>
      <td rowspan="2">Bit 01 Swap Two Numbers<br><br></b> <a href="https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> a=5, b=7<br><b>Output:</b> a=7, b=5<br><br><b> </b> 1 &le; a, b &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Use basic arithmetic (addition and subtraction) to swap.</td>
      <td><b>Edge Cases:</b> **Integer Overflow:** Addition `a + b` can overflow if numbers are near `INT_MAX`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void swapArithmetic(int &amp;a, int &amp;b) {&#10;    // Edge Case: Can overflow for massive 32-bit integers&#10;    a = a + b;&#10;    b = a - b;&#10;    a = a - b;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use XOR bitwise operation. XORing a number with itself is 0, and XORing with 0 is the number itself.</td>
      <td><b>Edge Cases:</b> **Optimal:** No overflow risk compared to arithmetic addition.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; get(int a, int b) {&#10;    a = a ^ b;&#10;    b = a ^ b;&#10;    a = a ^ b;&#10;    return {a, b};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Bit 02 Check Ith Bit Set<br><br></b> <a href="https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> N=4 (100 in binary), i=2<br><b>Output:</b> true<br><br><b> </b> 1 &le; N &le; 10<sup>9</sup>, 0 &le; i &le; 31</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Right shift N by K times and check if the least significant bit is 1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBitRightShift(int n, int k) {&#10;    return ((n &gt;&gt; k) &amp; 1) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Create a mask by left shifting 1 by K times and check if the bitwise AND with N is non-zero.</td>
      <td><b>Edge Cases:</b> **Shift Overflow:** Use `1LL` if K can exceed 31.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBit(int n, int k) {&#10;    return (n &amp; (1LL &lt;&lt; k)) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Bit 03 Operations Set Clear Toggle<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b><br>N=70, i=3 -> Set:78, Clear:62, Toggle:78<br><br><b> </b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.</td>
      <td><b>Edge Cases:</b> **Shift Overflow:** `1LL` used strictly to prevent overflow beyond 31 bits.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bitOperations(int n, int i) {&#10;    int setBit = n | (1LL &lt;&lt; i);&#10;    int clearBit = n &amp; ~(1LL &lt;&lt; i);&#10;    int toggleBit = n ^ (1LL &lt;&lt; i);&#10;    return {setBit, clearBit, toggleBit};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Bit 04 Copy Set Bits In Range<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b><br>X=44, Y=3, L=1, R=5<br><b>Output:</b> 47</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Create a mask of length (R - L + 1) with all 1s. Shift this mask to the left by (L - 1). AND this mask with Y to isolate the bits to be copied. Finally, OR this isolated value with X.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int setSetBit(int x, int y, int l, int r){&#10;    int mask = (1 &lt;&lt; (r - l + 1)) - 1;&#10;    mask = (mask &lt;&lt; (l - 1));&#10;    mask = mask &amp; y;&#10;    return x | mask;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">5</td>
      <td rowspan="2">Bit 05 Divide Two Integers<br><br></b> <a href="https://leetcode.com/problems/divide-two-integers/" target="_blank">LeetCode 29</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> dividend = 10, divisor = 3<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Iterative subtraction. Subtract divisor from dividend until dividend is smaller than divisor. Count the number of subtractions.</td>
      <td><b>Edge Cases:</b> **Time Limit Exceeded:** Too slow when dividend is `INT_MAX` and divisor is `1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int divideBrute(int dividend, int divisor) {&#10;    if (dividend == INT_MIN &amp;&amp; divisor == -1) return INT_MAX;&#10;    long long a = abs((long long)dividend);&#10;    long long b = abs((long long)divisor);&#10;    int res = 0;&#10;    while(a &gt;= b) {&#10;        a -= b;&#10;        res++;&#10;    }&#10;    return (dividend &gt; 0) == (divisor &gt; 0) ? res : -res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log^2 N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use left shift to find the largest multiple of divisor that fits into dividend. Subtract it and add the shifted value to quotient. Repeat until dividend < divisor.</td>
      <td><b>Edge Cases:</b> **INT_MIN:** Handle edge case `-2147483648 / -1 = 2147483647`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int divide(int dividend, int divisor) {&#10;    if(dividend == INT_MIN &amp;&amp; divisor == -1) return INT_MAX;&#10;    long long n = abs(dividend), d = abs(divisor), quotient = 0;&#10;    bool sign = (dividend &lt; 0) == (divisor &lt; 0);&#10;    while(n &gt;= d) {&#10;        long long temp = d, multiple = 1;&#10;        while(n &gt;= (temp &lt;&lt; 1)) {&#10;            temp &lt;&lt;= 1;&#10;            multiple &lt;&lt;= 1;&#10;        }&#10;        n -= temp;&#10;        quotient += multiple;&#10;    }&#10;    return sign ? quotient : -quotient;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Bit 06 Calculate Square<br><br></b> <a href="https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> n = 5<br><b>Output:</b> 25</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Repeated addition. Add `n` to a sum `n` times.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int squareBrute(int n) {&#10;    int sum = 0;&#10;    for(int i=0; i&lt;abs(n); i++) sum += abs(n);&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(log N) (Call stack)</td>
      <td><b>Approach 2:</b><br>If `n` is even, `n = 2*x`, then `n^2 = 4*x^2 = (x^2) << 2`. If `n` is odd, `n = 2*x + 1`, then `n^2 = 4*x^2 + 4*x + 1 = ((x^2 + x) << 2) + 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int square(int n) {&#10;    if(n == 0) return 0;&#10;    if(n &lt; 0) n = -n;&#10;    int x = n &gt;&gt; 1;&#10;    if(n &amp; 1) return ((square(x) &lt;&lt; 2) + (x &lt;&lt; 2) + 1);&#10;    else return (square(x) &lt;&lt; 2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Bit 07 Find Position Of Only Set Bit<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> N = 2<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(32)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Loop through all 32 bits, count set bits, and record the position. If count is strictly 1, return position, else -1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPositionBrute(int N) {&#10;    int count = 0, pos = -1, curr = 1;&#10;    while(N &gt; 0) {&#10;        if(N &amp; 1) {&#10;            count++;&#10;            pos = curr;&#10;        }&#10;        N &gt;&gt;= 1;&#10;        curr++;&#10;    }&#10;    return count == 1 ? pos : -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>First, check if `N` is a power of 2 using `N & (N - 1) == 0`. If yes, the position is `log2(N) + 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPosition(int N) {&#10;    if(N == 0 || (N &amp; (N - 1)) != 0) return -1;&#10;    return log2(N) + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">8</td>
      <td rowspan="2">Bit 08 Count Set Bits<br><br></b> <a href="https://leetcode.com/problems/number-of-1-bits/" target="_blank">LeetCode 191</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> N=11 (1011)<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(32) &cong; O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Iterate through all 32 bits and check if each is set by right shifting N and checking the 0th bit.</td>
      <td><b>Edge Cases:</b> **Static Loop Iterations:** Loop always runs 32 times regardless of number size.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeightLoop(uint32_t n) {&#10;    int count = 0;&#10;    while (n) {&#10;        count += (n &amp; 1);&#10;        n &gt;&gt;= 1;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(Set Bits)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use Brian Kernighan's algorithm: `n = n & (n - 1)` unsets the rightmost set bit. Keep doing this until `n` becomes 0.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeight(uint32_t n) {&#10;    int count = 0;&#10;    while (n) {&#10;        n &amp;= (n - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Bit 09 Minimum Bit Flips To Convert Number<br><br></b> <a href="https://leetcode.com/problems/minimum-bit-flips-to-convert-number/" target="_blank">LeetCode 2220</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> start=10 (1010), goal=7 (0111)<br><b>Output:</b> 3 flips</td>
      <td><b>Time:</b> O(Set Bits)<br><b>Space:</b> O(1)</td>
      <td>XOR `start` and `goal` to isolate differing bits, then count the set bits in the result.</td>
      <td><b>Edge Cases:</b> **XOR Magic:** XOR inherently maps identical bits to 0 and different bits to 1, instantly mapping the problem to Hamming Weight.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minBitFlips(int start, int goal) {&#10;    int xor_res = start ^ goal;&#10;    int count = 0;&#10;    // Brian Kernighan&#x27;s algorithm to count the mismatched bits&#10;    while(xor_res != 0) {&#10;        xor_res = xor_res &amp; (xor_res - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">10</td>
      <td rowspan="2">Bit 10 Single Number<br><br></b> <a href="https://leetcode.com/problems/single-number/" target="_blank">LeetCode 136</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> nums = [4,1,2,1,2]<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Use a Hash Map to count occurrences. Return the element with count 1.<br><br><b>Dependencies:</b> **Data Structure:**<br><code>std::unordered_map</code> / <code>dict</code></td>
      <td><b>Edge Cases:</b> **Memory Heavy:** Fails optimal space constraint due to dynamic hash mapping allocation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumberHash(vector&lt;int&gt;&amp; nums) {&#10;    unordered_map&lt;int, int&gt; counts;&#10;    for(int num : nums) counts[num]++;&#10;    for(auto it : counts) {&#10;        if(it.second == 1) return it.first;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use XOR bitwise operation. `X ^ X = 0` and `X ^ 0 = X`. XORing all elements pairs up the duplicates to 0, leaving the single element.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    int ans = 0;&#10;    for(int num : nums) {&#10;        ans ^= num;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Bit 11 Single Number II<br><br></b> <a href="https://leetcode.com/problems/single-number-ii/" target="_blank">LeetCode 137</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> nums = [2,2,3,2]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(32 * N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Count bits: For each bit position, count how many numbers have it set. If count is not divisible by 3, the single number has this bit set.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumberCount(vector&lt;int&gt;&amp; nums) {&#10;    int ans = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        int sum = 0;&#10;        for(int num : nums) {&#10;            if((num &gt;&gt; i) &amp; 1) sum++;&#10;        }&#10;        if(sum % 3 != 0) ans |= (1 &lt;&lt; i);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Use bitmask magic with `ones` and `twos`. `ones` keeps track of bits that appeared exactly once. `twos` tracks bits that appeared exactly twice. When a bit appears 3 times, both `ones` and `twos` are cleared.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    int ones = 0, twos = 0;&#10;    for(int n : nums) {&#10;        ones = (ones ^ n) &amp; ~twos;&#10;        twos = (twos ^ n) &amp; ~ones;&#10;    }&#10;    return ones;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Bit 12 Single Number III<br><br></b> <a href="https://leetcode.com/problems/single-number-iii/" target="_blank">LeetCode 260</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> nums = [1,2,1,3,2,5]<br><b>Output:</b> [3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>XOR all elements to get `x ^ y`. Find the rightmost set bit in this XOR result. This bit distinguishes `x` and `y`. Iterate through array again, divide numbers into two groups based on this bit, and XOR each group. The results are `x` and `y`.</td>
      <td><b>Edge Cases:</b> **Overflow:** Rightmost set bit can be found using `val & -(unsigned int)val`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    long long xor_all = 0;&#10;    for(int n : nums) xor_all ^= n;&#10;    long long rightmost_set_bit = xor_all &amp; -xor_all;&#10;    int x = 0, y = 0;&#10;    for(int n : nums) {&#10;        if(n &amp; rightmost_set_bit) x ^= n;&#10;        else y ^= n;&#10;    }&#10;    return {x, y};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">13</td>
      <td rowspan="2">Bit 13 Subsets<br><br></b> <a href="https://leetcode.com/problems/subsets/" target="_blank">LeetCode 78</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> nums = [1,2,3]<br><b>Output:</b> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * 2^N)</td>
      <td><b>Approach 1:</b><br>Recursive backtracking (include/exclude pattern).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int idx, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; curr, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    curr.push_back(nums[idx]);&#10;    solve(idx + 1, nums, curr, ans);&#10;    curr.pop_back();&#10;    solve(idx + 1, nums, curr, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsRec(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; curr;&#10;    solve(0, nums, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * 2^N)</td>
      <td><b>Approach 2:</b><br>Bit manipulation technique. For N elements, there are 2^N subsets. Count from 0 to 2^N - 1. For each number, its binary representation indicates which elements to include.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; subsets(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    int subsetsCount = 1 &lt;&lt; n;&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(int i=0; i&lt;subsetsCount; i++) {&#10;        vector&lt;int&gt; subset;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(i &amp; (1 &lt;&lt; j)) subset.push_back(nums[j]);&#10;        }&#10;        ans.push_back(subset);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">14</td>
      <td rowspan="2">Bit 14 Count Total Set Bits 1 To N<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b><br><br><b>Input:</b> N=4<br><b>Output:</b> 5<br>Explanation: 1(01) + 2(10) + 3(11) + 4(100) -> 1+1+2+1 = 5</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Loop from 1 to N and count set bits using Brian Kernighan's.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSetBitsBrute(int N) {&#10;    int total = 0;&#10;    for(int i=1; i&lt;=N; i++) {&#10;        int temp = i;&#10;        while(temp) {&#10;            temp &amp;= (temp - 1);&#10;            total++;&#10;        }&#10;    }&#10;    return total;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(log N)</td>
      <td><b>Approach 2:</b><br>Find largest power of 2 <= n (`x`). Bits up to `2^x - 1` are `x * 2^(x-1)`. The MSB of remaining numbers is `n - 2^x + 1`. Then recursively call for `n - 2^x`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestPowerOf2inRange(int n) {&#10;    int x = 0;&#10;    while((1 &lt;&lt; x) &lt;= n) x++;&#10;    return x - 1;&#10;}&#10;int countSetBits(int n) {&#10;    if(n &lt;= 0) return 0;&#10;    int x = largestPowerOf2inRange(n);&#10;    int bitsUpTo2x = x * (1 &lt;&lt; (x - 1));&#10;    int msbOfRest = n - (1 &lt;&lt; x) + 1;&#10;    int rest = n - (1 &lt;&lt; x);&#10;    return bitsUpTo2x + msbOfRest + countSetBits(rest);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Bit 15 Find The Original Array Of Prefix Xor<br><br></b> <a href="https://leetcode.com/problems/find-the-original-array-of-prefix-xor/" target="_blank">LeetCode 2433</a></td>
      <td rowspan="1"><b> </b> `pref = [5,2,0,3,1]`.<br><b>Output:</b> `[5,7,2,3,2]`.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Since `pref[i] = pref[i-1] ^ arr[i]`, we can find `arr[i]` by doing `pref[i-1] ^ pref[i]`. `arr[0] = pref[0]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findArray(vector&lt;int&gt;&amp; pref) {&#10;    vector&lt;int&gt; arr(pref.size());&#10;    arr[0] = pref[0];&#10;    for(int i=1; i&lt;pref.size(); i++) {&#10;        arr[i] = pref[i-1] ^ pref[i];&#10;    }&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Bit 16 Maximum Xor For Each Query<br><br></b> <a href="https://leetcode.com/problems/maximum-xor-for-each-query/" target="_blank">LeetCode 1829</a></td>
      <td rowspan="1"><b> </b> `nums = [0,1,1,3], maximumBit = 2`.<br><b>Output:</b> `[0,3,2,3]`.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>The maximum possible value is `(1 << maximumBit) - 1`. If current running XOR is `curr`, we want `k` such that `curr ^ k = max_val`. Thus `k = curr ^ max_val`. Do this iteratively backwards.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; getMaximumXor(vector&lt;int&gt;&amp; nums, int maximumBit) {&#10;    int curr = 0;&#10;    for(int n : nums) curr ^= n;&#10;    int max_val = (1 &lt;&lt; maximumBit) - 1;&#10;    vector&lt;int&gt; ans;&#10;    for(int i=nums.size()-1; i&gt;=0; i--) {&#10;        ans.push_back(curr ^ max_val);&#10;        curr ^= nums[i];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Bit 17 Minimum Flips To Make A Or B Equal To C<br><br></b> <a href="https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/" target="_blank">LeetCode 1318</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> a=2, b=6, c=5<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Iterate through 32 bits. If bit in `c` is 1, at least one of `a` or `b` needs to be 1. If both are 0, flip one (1 flip). If bit in `c` is 0, both `a` and `b` must be 0. Flips needed = bit of `a` + bit of `b`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFlips(int a, int b, int c) {&#10;    int flips = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        int bit_a = (a &gt;&gt; i) &amp; 1;&#10;        int bit_b = (b &gt;&gt; i) &amp; 1;&#10;        int bit_c = (c &gt;&gt; i) &amp; 1;&#10;        if(bit_c == 1) {&#10;            if(bit_a == 0 &amp;&amp; bit_b == 0) flips += 1;&#10;        } else {&#10;            flips += bit_a + bit_b;&#10;        }&#10;    }&#10;    return flips;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Bit 18 Number Of Steps To Reduce To Zero<br><br></b> <a href="https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/" target="_blank">LeetCode 1342</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> num = 14<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>If `num` is odd, subtract 1 (equivalent to clearing rightmost bit). If even, divide by 2 (equivalent to right shift).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfSteps(int num) {&#10;    if(num == 0) return 0;&#10;    int steps = 0;&#10;    while(num &gt; 0) {&#10;        if(num &amp; 1) num--;&#10;        else num &gt;&gt;= 1;&#10;        steps++;&#10;    }&#10;    return steps;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Bit 19 Decode Xored Array<br><br></b> <a href="https://leetcode.com/problems/decode-xored-array/" target="_blank">LeetCode 1720</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> encoded=[1,2,3], first=1<br><b>Output:</b> [1,0,2,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Since `encoded[i] = arr[i] ^ arr[i+1]`, it implies `arr[i+1] = arr[i] ^ encoded[i]`. We have `arr[0]`, so we can iteratively find the rest.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; decode(vector&lt;int&gt;&amp; encoded, int first) {&#10;    vector&lt;int&gt; arr(encoded.size() + 1);&#10;    arr[0] = first;&#10;    for(int i=0; i&lt;encoded.size(); i++) {&#10;        arr[i+1] = arr[i] ^ encoded[i];&#10;    }&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Bit 20 Longest Substring Vowels Even Counts<br><br></b> <a href="https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/" target="_blank">LeetCode 1371</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> s = "eleetminicoworoep"<br><b>Output:</b> 13</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(32) since only 5 bits used</td>
      <td>Use a 5-bit mask to represent the parity of counts for 'a','e','i','o','u'. If we encounter a vowel, flip its bit. If the same mask is seen again at index `i` (was previously seen at `j`), then the substring `s[j+1...i]` has even vowel counts. Use a hash map to store first occurrence of each mask.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTheLongestSubstring(string s) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    m[0] = -1;&#10;    int mask = 0, maxLen = 0;&#10;    for(int i=0; i&lt;s.length(); i++) {&#10;        if(s[i] == &#x27;a&#x27;) mask ^= (1 &lt;&lt; 0);&#10;        else if(s[i] == &#x27;e&#x27;) mask ^= (1 &lt;&lt; 1);&#10;        else if(s[i] == &#x27;i&#x27;) mask ^= (1 &lt;&lt; 2);&#10;        else if(s[i] == &#x27;o&#x27;) mask ^= (1 &lt;&lt; 3);&#10;        else if(s[i] == &#x27;u&#x27;) mask ^= (1 &lt;&lt; 4);&#10;        if(m.count(mask)) {&#10;            maxLen = max(maxLen, i - m[mask]);&#10;        } else {&#10;            m[mask] = i;&#10;        }&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Bit 21 Xor Queries Of A Subarray<br><br></b> <a href="https://leetcode.com/problems/xor-queries-of-a-subarray/" target="_blank">LeetCode 1310</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]<br><b>Output:</b> [2,7,14,8]</td>
      <td><b>Time:</b> O(N + Q)<br><b>Space:</b> O(N)</td>
      <td>Create a prefix XOR array. Query answer for `[L, R]` is `prefix[R] ^ prefix[L-1]`. If `L == 0`, answer is `prefix[R]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; xorQueries(vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; queries) {&#10;    vector&lt;int&gt; pref(arr.size());&#10;    pref[0] = arr[0];&#10;    for(int i=1; i&lt;arr.size(); i++) pref[i] = pref[i-1] ^ arr[i];&#10;    vector&lt;int&gt; ans;&#10;    for(auto q : queries) {&#10;        if(q[0] == 0) ans.push_back(pref[q[1]]);&#10;        else ans.push_back(pref[q[1]] ^ pref[q[0]-1]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Arrays

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
      <td rowspan="2">1</td>
      <td rowspan="2">Arr 01 Largest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-element-in-array/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> A = [1, 8, 7, 56, 90]<br><b>Output:</b> 90</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1) or O(N) depending on sort</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array and return the last element.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    std::sort(arr.begin(), arr.end());&#10;    return arr.back();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Iterate through the array maintaining a variable for the maximum element seen so far.</td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Initialize `max_val` with the first element or negative infinity.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int max_val = arr[0];&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &gt; max_val) {&#10;            max_val = arr[i];&#10;        }&#10;    }&#10;    return max_val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Arr 02 Second Largest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/second-largest3735/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> arr = [12, 35, 1, 10, 34, 1]<br><b>Output:</b> 34<br><br><b> </b> Find it in a single pass O(N) time.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array, then iterate from the back to find the first element smaller than the largest.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int print2largest(int arr[], int n) {&#10;    std::sort(arr, arr+n);&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        if(arr[i] != arr[n-1]) return arr[i];&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.</td>
      <td><b>Edge Cases:</b> <b>No Second Largest:</b> If all elements are same or array size < 2, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int print2largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int largest = -1, second_largest = -1;&#10;    for (int num : arr) {&#10;        if (num &gt; largest) {&#10;            second_largest = largest;&#10;            largest = num;&#10;        } else if (num &gt; second_largest &amp;&amp; num != largest) {&#10;            second_largest = num;&#10;        }&#10;    }&#10;    return second_largest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Arr 03 Check If Array Is Sorted And Rotated<br><br></b> <a href="https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/" target="_blank">LeetCode 1752</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,4,5,1,2]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Count the number of "breaks" where `nums[i] > nums[i+1]`. For a sorted and rotated array, there can be at most 1 break.</td>
      <td><b>Edge Cases:</b> <b>Circular Check:</b> We must also check the boundary between the last and first element `nums[n-1] > nums[0]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool check(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, n = nums.size();&#10;    for (int i = 0; i &lt; n; i++) {&#10;        if (nums[i] &gt; nums[(i + 1) % n]) {&#10;            count++;&#10;        }&#10;    }&#10;    return count &lt;= 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Arr 04 Remove Duplicates From Sorted Array<br><br></b> <a href="https://leetcode.com/problems/remove-duplicates-from-sorted-array/" target="_blank">LeetCode 26</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,1,2]<br><b>Output:</b> 2, nums = [1,2,_]</td>
      <td><b>Time:</b> O(N log N) or O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use a HashSet to store unique elements, then put them back into the array.<br><br><b>Dependencies:</b> std::set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeDuplicates(vector&lt;int&gt;&amp; nums) {&#10;    set&lt;int&gt; s;&#10;    for(int x : nums) s.insert(x);&#10;    int i = 0;&#10;    for(int x : s) nums[i++] = x;&#10;    return s.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Two-pointer approach. Pointer `i` keeps track of unique elements, pointer `j` scans the array to find new unique elements.</td>
      <td><b>Edge Cases:</b> <b>Empty Array:</b> Handled automatically if `n=0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeDuplicates(std::vector&lt;int&gt;&amp; nums) {&#10;    if (nums.empty()) return 0;&#10;    int i = 0;&#10;    for (int j = 1; j &lt; nums.size(); j++) {&#10;        if (nums[j] != nums[i]) {&#10;            i++;&#10;            nums[i] = nums[j];&#10;        }&#10;    }&#10;    return i + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">5</td>
      <td rowspan="2">Arr 05 Rotate Array<br><br></b> <a href="https://leetcode.com/problems/rotate-array/" target="_blank">LeetCode 189</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,2,3,4,5,6,7], k = 3<br><b>Output:</b> [5,6,7,1,2,3,4]</td>
      <td><b>Time:</b> O(N * K) or O(N)<br><b>Space:</b> O(1) or O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Rotate the array one by one, k times. Or use a temporary array of size N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    vector&lt;int&gt; temp(n);&#10;    for(int i=0; i&lt;n; i++) {&#10;        temp[(i+k)%n] = nums[i];&#10;    }&#10;    nums = temp;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Reverse Algorithm. Reverse the whole array, then reverse the first `k` elements, then reverse the remaining `N-k` elements.<br><br><b>Dependencies:</b> <code>std::reverse</code></td>
      <td><b>Edge Cases:</b> <b>K > N:</b> k might be greater than array length, so perform `k = k % n` first.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    std::reverse(nums.begin(), nums.end());&#10;    std::reverse(nums.begin(), nums.begin() + k);&#10;    std::reverse(nums.begin() + k, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Arr 06 Move Zeroes<br><br></b> <a href="https://leetcode.com/problems/move-zeroes/" target="_blank">LeetCode 283</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [0,1,0,3,12]<br><b>Output:</b> [1,3,12,0,0]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Two-pointer approach (Snowball method). Pointer `i` tracks the first zero found, pointer `j` scans for non-zeroes to swap.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>No zeroes:</b> Swaps element with itself initially, no overhead.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void moveZeroes(std::vector&lt;int&gt;&amp; nums) {&#10;    int i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(nums[j] != 0) {&#10;            std::swap(nums[i], nums[j]);&#10;            i++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Arr 07 Missing Number<br><br></b> <a href="https://leetcode.com/problems/missing-number/" target="_blank">LeetCode 268</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [3,0,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Linear search for each number from 0 to N inside the array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(vector&lt;int&gt;&amp; nums) {&#10;    for(int i=0; i&lt;=nums.size(); i++) {&#10;        bool found = false;&#10;        for(int x : nums) {&#10;            if(x == i) found = true;&#10;        }&#10;        if(!found) return i;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.</td>
      <td><b>Edge Cases:</b> <b>Mathematical Sum alternative:</b> Gaussian sum formula `N*(N+1)/2` can cause integer overflow, XOR completely bypasses overflow risks.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int res = nums.size();&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        res ^= i ^ nums[i];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Arr 08 Max Consecutive Ones<br><br></b> <a href="https://leetcode.com/problems/max-consecutive-ones/" target="_blank">LeetCode 485</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,1,0,1,1,1]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate while counting 1s. If a 0 is found, update max count and reset current count to 0.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Trailing Ones:</b> Must perform a final max check outside the loop or update max dynamically inside.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMaxConsecutiveOnes(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_cnt = 0, current_cnt = 0;&#10;    for(int num : nums) {&#10;        if(num == 1) {&#10;            current_cnt++;&#10;            max_cnt = std::max(max_cnt, current_cnt);&#10;        } else {&#10;            current_cnt = 0;&#10;        }&#10;    }&#10;    return max_cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">9</td>
      <td rowspan="2">Arr 09 Sort Colors Dnf<br><br></b> <a href="https://leetcode.com/problems/sort-colors/" target="_blank">LeetCode 75</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [2,0,2,1,1,0]<br><b>Output:</b> [0,0,1,1,2,2]<br><br><b> </b> Do not use library sort. Use single pass.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use any standard sorting algorithm like Merge Sort.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortColors(vector&lt;int&gt;&amp; nums) {&#10;    sort(nums.begin(), nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Dutch National Flag Algorithm (3 pointers). `low` tracks 0s, `mid` scans array, `high` tracks 2s. Swap elements to maintain sections.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Mid pointer increment:</b> When swapping with `high`, we do NOT increment `mid` because the swapped element from `high` needs to be evaluated.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortColors(std::vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, mid = 0, high = nums.size() - 1;&#10;    while (mid &lt;= high) {&#10;        if (nums[mid] == 0) {&#10;            std::swap(nums[low], nums[mid]);&#10;            low++; mid++;&#10;        } else if (nums[mid] == 1) {&#10;            mid++;&#10;        } else {&#10;            std::swap(nums[mid], nums[high]);&#10;            high--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">10</td>
      <td rowspan="2">Arr 10 Majority Element<br><br></b> <a href="https://leetcode.com/problems/majority-element/" target="_blank">LeetCode 169</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [2,2,1,1,1,2,2]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use two nested loops to count occurrences of each element.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        int cnt = 0;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(nums[j] == nums[i]) cnt++;&#10;        }&#10;        if(cnt &gt; n/2) return nums[i];&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Optimal: Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.</td>
      <td><b>Edge Cases:</b> <b>Verification phase:</b> If it's not guaranteed a majority exists, a second `O(N)` pass is required to count the candidate. (Leetcode guarantees it exists).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, candidate = 0;&#10;    for (int num : nums) {&#10;        if (count == 0) candidate = num;&#10;        if (num == candidate) count++;&#10;        else count--;&#10;    }&#10;    return candidate;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Arr 11 Kadanes Algorithm Max Subarray Sum<br><br></b> <a href="https://leetcode.com/problems/maximum-subarray/" target="_blank">LeetCode 53</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [-2,1,-3,4,-1,2,1,-5,4]<br><b>Output:</b> 6 (Subarray [4,-1,2,1])</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Generate all possible subarrays using three nested loops and find the maximum sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubArray(vector&lt;int&gt;&amp; nums) {&#10;    int maxi = INT_MIN;&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=i; j&lt;n; j++) {&#10;            int sum = 0;&#10;            for(int k=i; k&lt;=j; k++) sum += nums[k];&#10;            maxi = max(maxi, sum);&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Kadane's Algorithm. Keep a running sum. If sum becomes negative, reset it to 0 (a negative prefix will never help a future subarray).<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>All Negative Numbers:</b> Initialize `max_sum` with `INT_MIN` or `nums[0]` so it can correctly return the smallest negative number instead of 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubArray(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_sum = INT_MIN;&#10;    int current_sum = 0;&#10;    for(int num : nums) {&#10;        current_sum += num;&#10;        max_sum = std::max(max_sum, current_sum);&#10;        if(current_sum &lt; 0) current_sum = 0;&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Arr 12 Best Time To Buy And Sell Stock<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/" target="_blank">LeetCode 121</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> prices = [7,1,5,3,6,4]<br><b>Output:</b> 5</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate while keeping track of the minimum price seen so far. Subtract this min from the current price to find potential profit.<br><br><b>Dependencies:</b> <code>std::max</code>, <code>std::min</code></td>
      <td><b>Edge Cases:</b> <b>No Profit Possible:</b> `max_profit` initializes at 0. If price strictly decreases, it never updates and naturally returns 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(std::vector&lt;int&gt;&amp; prices) {&#10;    int min_price = prices[0];&#10;    int max_profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        max_profit = std::max(max_profit, prices[i] - min_price);&#10;        min_price = std::min(min_price, prices[i]);&#10;    }&#10;    return max_profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Arr 13 Rearrange Array Elements By Sign<br><br></b> <a href="https://leetcode.com/problems/rearrange-array-elements-by-sign/" target="_blank">LeetCode 2149</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,1,-2,-5,2,-4]<br><b>Output:</b> [3,-2,1,-5,2,-4]<br><br><b> </b> Maintain relative order.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>Optimal: Use two pointers, `pos_idx` starting at 0, `neg_idx` starting at 1. Traverse and place elements directly into a new result array.</td>
      <td><b>Edge Cases:</b> <b>In-Place Attempt:</b> Doing this in-place `O(1)` space while maintaining relative order drops Time to `O(N^2)`. The optimal tradeoff is `O(N)` space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; rearrangeArray(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; ans(nums.size());&#10;    int pos_idx = 0, neg_idx = 1;&#10;    for (int num : nums) {&#10;        if (num &gt; 0) {&#10;            ans[pos_idx] = num;&#10;            pos_idx += 2;&#10;        } else {&#10;            ans[neg_idx] = num;&#10;            neg_idx += 2;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Arr 14 Next Permutation<br><br></b> <a href="https://leetcode.com/problems/next-permutation/" target="_blank">LeetCode 31</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,2,3]<br><b>Output:</b> [1,3,2]<br><b> </b> <br><b>Input:</b> nums = [3,2,1]<br><b>Output:</b> [1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: 1. Find break point (i) where arr[i] < arr[i+1]. 2. Swap it with smallest element > arr[i] from the back. 3. Reverse the right half.<br><br><b>Dependencies:</b> <code>std::reverse</code></td>
      <td><b>Edge Cases:</b> <b>Last Permutation:</b> If break point is not found (`i < 0`), it means the array is sorted descending. Just reverse the entire array to get the lowest permutation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void nextPermutation(std::vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), i = n - 2;&#10;    while (i &gt;= 0 &amp;&amp; nums[i] &gt;= nums[i + 1]) i--;&#10;    &#10;    if (i &gt;= 0) {&#10;        int j = n - 1;&#10;        while (nums[j] &lt;= nums[i]) j--;&#10;        std::swap(nums[i], nums[j]);&#10;    }&#10;    std::reverse(nums.begin() + i + 1, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Arr 15 Pascals Triangle<br><br></b> <a href="https://leetcode.com/problems/pascals-triangle/" target="_blank">LeetCode 118</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> numRows = 5<br><b>Output:</b> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(N<sup>2</sup>) (Constraint)</td>
      <td>Optimal: Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.</td>
      <td><b>Edge Cases:</b> <b>Boundary 1s:</b> First and last elements of every row are always 1. Pre-filling row with 1s avoids out-of-bounds checks.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; generate(int numRows) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans(numRows);&#10;    for(int i = 0; i &lt; numRows; i++) {&#10;        ans[i].resize(i + 1, 1);&#10;        for(int j = 1; j &lt; i; j++) {&#10;            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Arr 16 Majority Element II<br><br></b> <a href="https://leetcode.com/problems/majority-element-ii/" target="_blank">LeetCode 229</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,2,3]<br><b>Output:</b> [3]<br><br><b> </b> Time O(N), Space O(1).</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Extended Moore's Voting Algorithm. At most TWO elements can appear > N/3 times. Track two candidates and two counters.</td>
      <td><b>Edge Cases:</b> <b>Verification phase required:</b> We MUST perform a second pass to count occurrences of `candidate1` and `candidate2` because it's not guaranteed they appear > N/3 times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;&#10;    for(int num : nums) {&#10;        if(cnt1 == 0 &amp;&amp; num != el2) {&#10;            cnt1 = 1; el1 = num;&#10;        } else if(cnt2 == 0 &amp;&amp; num != el1) {&#10;            cnt2 = 1; el2 = num;&#10;        } else if(num == el1) cnt1++;&#10;        else if(num == el2) cnt2++;&#10;        else {&#10;            cnt1--; cnt2--;&#10;        }&#10;    }&#10;    cnt1 = 0; cnt2 = 0;&#10;    for(int num : nums) {&#10;        if(num == el1) cnt1++;&#10;        if(num == el2) cnt2++;&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    if(cnt1 &gt; nums.size() / 3) ans.push_back(el1);&#10;    if(cnt2 &gt; nums.size() / 3) ans.push_back(el2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Arr 17 3Sum<br><br></b> <a href="https://leetcode.com/problems/3sum/" target="_blank">LeetCode 15</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [-1,0,1,2,-1,-4]<br><b>Output:</b> [[-1,-1,2],[-1,0,1]]<br><br><b> </b> Solution set must not contain duplicate triplets.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Trade-off)</td>
      <td>Optimal: Sort the array. Use a loop to fix `i`, then use a Two-Pointer approach (`j`, `k`) for the remaining array to find sum `0 - nums[i]`.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate skipping:</b> To prevent duplicate triplets, skip identical adjacent elements for `i`, `j`, and `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; threeSum(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::sort(nums.begin(), nums.end());&#10;    int n = nums.size();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        int j = i + 1, k = n - 1;&#10;        while(j &lt; k) {&#10;            int sum = nums[i] + nums[j] + nums[k];&#10;            if(sum &lt; 0) j++;&#10;            else if(sum &gt; 0) k--;&#10;            else {&#10;                ans.push_back({nums[i], nums[j], nums[k]});&#10;                j++; k--;&#10;                while(j &lt; k &amp;&amp; nums[j] == nums[j-1]) j++;&#10;                while(j &lt; k &amp;&amp; nums[k] == nums[k+1]) k--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Arr 18 Merge Intervals<br><br></b> <a href="https://leetcode.com/problems/merge-intervals/" target="_blank">LeetCode 56</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> intervals = [[1,3],[2,6],[8,10],[15,18]]<br><b>Output:</b> [[1,6],[8,10],[15,18]]</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Sort the intervals based on the start time. Iterate and merge: if current start <= previous end, update previous end to `max(prev_end, curr_end)`.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Subsumed Intervals:</b> `[1,4]` and `[2,3]` -> using `max()` prevents shrinking the end time to `3`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; merge(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if (intervals.empty()) return {};&#10;    std::sort(intervals.begin(), intervals.end());&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; merged;&#10;    merged.push_back(intervals[0]);&#10;    for (int i = 1; i &lt; intervals.size(); i++) {&#10;        if (intervals[i][0] &lt;= merged.back()[1]) {&#10;            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);&#10;        } else {&#10;            merged.push_back(intervals[i]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Arr 19 Leaders In An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> A = [16,17,4,3,5,2]<br><b>Output:</b> [17,5,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output</td>
      <td>Optimal: Traverse the array from right to left. Keep track of the maximum element seen so far. If the current element is greater than or equal to the max, it's a leader. Reverse the collected leaders at the end.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><b>Edge Cases:</b> <b>Rightmost element:</b> Always a leader.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; leaders(int a[], int n){&#10;    vector&lt;int&gt; ans;&#10;    int maxi = a[n - 1];&#10;    ans.push_back(maxi);&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        if(a[i] &gt;= maxi) {&#10;            ans.push_back(a[i]);&#10;            maxi = a[i];&#10;        }&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Arr 20 Set Matrix Zeroes<br><br></b> <a href="https://leetcode.com/problems/set-matrix-zeroes/" target="_blank">LeetCode 73</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,1,1],[1,0,1],[1,1,1]]<br><b>Output:</b> [[1,0,1],[0,0,0],[1,0,1]]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use the first row and first column as marker arrays to save space. We need a separate variable for the first column (or row) to avoid overlapping states.</td>
      <td><b>Edge Cases:</b> <b>Zeros in first row/col:</b> Handled accurately by checking `col0` flag at the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void setZeroes(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size(), col0 = 1;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(matrix[i][0] == 0) col0 = 0;&#10;        for(int j=1; j&lt;m; j++)&#10;            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;&#10;    }&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        for(int j=m-1; j&gt;=1; j--)&#10;            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;&#10;        if(col0 == 0) matrix[i][0] = 0;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Arr 21 Rotate Image<br><br></b> <a href="https://leetcode.com/problems/rotate-image/" target="_blank">LeetCode 48</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,2,3],[4,5,6],[7,8,9]]<br><b>Output:</b> [[7,4,1],[8,5,2],[9,6,3]]</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Transpose the matrix (swap matrix[i][j] with matrix[j][i]), then reverse every row.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;i; j++) std::swap(matrix[i][j], matrix[j][i]);&#10;    }&#10;    for(int i=0; i&lt;n; i++) std::reverse(matrix[i].begin(), matrix[i].end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Arr 22 Spiral Matrix<br><br></b> <a href="https://leetcode.com/problems/spiral-matrix/" target="_blank">LeetCode 54</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,2,3],[4,5,6],[7,8,9]]<br><b>Output:</b> [1,2,3,6,9,8,7,4,5]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) for output</td>
      <td>Optimal: Maintain 4 pointers: top, bottom, left, right. Traverse Top row, Right col, Bottom row, Left col, shrinking boundaries inwards.</td>
      <td><b>Edge Cases:</b> <b>Single row/col matrix:</b> Internal boundary checks prevent duplicate counting.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; spiralOrder(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    vector&lt;int&gt; ans;&#10;    int top=0, left=0, bottom=matrix.size()-1, right=matrix[0].size()-1;&#10;    while(top&lt;=bottom &amp;&amp; left&lt;=right) {&#10;        for(int i=left; i&lt;=right; i++) ans.push_back(matrix[top][i]);&#10;        top++;&#10;        for(int i=top; i&lt;=bottom; i++) ans.push_back(matrix[i][right]);&#10;        right--;&#10;        if(top&lt;=bottom) {&#10;            for(int i=right; i&gt;=left; i--) ans.push_back(matrix[bottom][i]);&#10;            bottom--;&#10;        }&#10;        if(left&lt;=right) {&#10;            for(int i=bottom; i&gt;=top; i--) ans.push_back(matrix[i][left]);&#10;            left++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Arr 23 4Sum<br><br></b> <a href="https://leetcode.com/problems/4sum/" target="_blank">LeetCode 18</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,0,-1,0,-2,2], target = 0<br><b>Output:</b> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1) auxiliary</td>
      <td>Optimal: Sort array. Use 2 nested loops (i, j) for the first two numbers, and Two Pointers (k, l) for the remaining two. Skip duplicates carefully.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Use `long long` when computing sum of 4 integers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt;&amp; nums, int target) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = nums.size(); sort(nums.begin(), nums.end());&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(i&gt;0 &amp;&amp; nums[i]==nums[i-1]) continue;&#10;        for(int j=i+1; j&lt;n; j++) {&#10;            if(j&gt;i+1 &amp;&amp; nums[j]==nums[j-1]) continue;&#10;            int k = j+1, l = n-1;&#10;            while(k &lt; l) {&#10;                long long sum = nums[i] + nums[j]; sum += nums[k]; sum += nums[l];&#10;                if(sum == target) {&#10;                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});&#10;                    k++; l--;&#10;                    while(k&lt;l &amp;&amp; nums[k]==nums[k-1]) k++;&#10;                    while(k&lt;l &amp;&amp; nums[l]==nums[l+1]) l--;&#10;                } else if(sum &lt; target) k++;&#10;                else l--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Arr 24 Count Subarrays With Given Xor K<br><br></b> <a href="https://www.interviewbit.com/problems/subarray-with-given-xor/" target="_blank">InterviewBit</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> A = [4, 2, 2, 6, 4], B = 6<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Use a Hash Map to store the frequency of prefix XORs. For each element, current XOR `xr ^= A[i]`. We need `xr ^ B`. If it exists in map, add its frequency to count.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><b>Edge Cases:</b> <b>XOR exactly equals B:</b> Insert `mpp[0] = 1` initially to cover subarrays starting from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solve(vector&lt;int&gt; &amp;A, int B) {&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int xr = 0, count = 0;&#10;    mpp[xr]++;&#10;    for(int i=0; i&lt;A.size(); i++) {&#10;        xr ^= A[i];&#10;        int x = xr ^ B;&#10;        if(mpp.find(x) != mpp.end()) count += mpp[x];&#10;        mpp[xr]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Arr 25 Find The Duplicate Number<br><br></b> <a href="https://leetcode.com/problems/find-the-duplicate-number/" target="_blank">LeetCode 287</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,3,4,2,2]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Floyd's Tortoise and Hare (Cycle Detection). Fast and slow pointer. Guaranteed cycle because of Pigeonhole Principle (numbers map to index ranges).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDuplicate(vector&lt;int&gt;&amp; nums) {&#10;    int slow = nums[0], fast = nums[0];&#10;    do {&#10;        slow = nums[slow];&#10;        fast = nums[nums[fast]];&#10;    } while(slow != fast);&#10;    fast = nums[0];&#10;    while(slow != fast) {&#10;        slow = nums[slow];&#10;        fast = nums[fast];&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Arr 26 Find Missing And Repeating<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 2, Arr[] = {2, 2}<br><b>Output:</b> 2 1</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Mathematical approach. Diff = Sum_N - Sum_Arr = Missing - Repeating. SumSqDiff = SumSq_N - SumSq_Arr = Missing^2 - Repeating^2. Use formulas to solve for both.</td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Summing squares of 10^5 elements exceeds 32-bit INT, requiring long long.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findTwoElement(vector&lt;int&gt; arr, int n) {&#10;    long long N = n;&#10;    long long S_N = (N * (N+1)) / 2;&#10;    long long Sq_N = (N * (N+1) * (2*N+1)) / 6;&#10;    long long S = 0, Sq = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        S += arr[i]; Sq += (long long)arr[i] * (long long)arr[i];&#10;    }&#10;    long long val1 = S_N - S; // X - Y&#10;    long long val2 = Sq_N - Sq; // X^2 - Y^2&#10;    val2 = val2 / val1; // X + Y&#10;    long long x = (val1 + val2) / 2;&#10;    long long y = x - val1;&#10;    return {(int)y, (int)x};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Arr 27 Merge Two Sorted Arrays Without Extra Space<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> arr1=[1,3,5,7], arr2=[0,2,6,8,9]<br><b>Output:</b> arr1=[0,1,2,3], arr2=[5,6,7,8,9]</td>
      <td><b>Time:</b> O((N+M) log(N+M))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Start pointers at end of arr1 (i) and beginning of arr2 (j). Swap if arr1[i] > arr2[j]. Afterwards, individually sort arr1 and arr2. Time is bounded by sorting.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(long long arr1[], long long arr2[], int n, int m) {&#10;    int left = n - 1, right = 0;&#10;    while(left &gt;= 0 &amp;&amp; right &lt; m) {&#10;        if(arr1[left] &gt; arr2[right]) { swap(arr1[left], arr2[right]); left--; right++; }&#10;        else break;&#10;    }&#10;    sort(arr1, arr1 + n); sort(arr2, arr2 + m);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Arr 28 Maximum Product Subarray<br><br></b> <a href="https://leetcode.com/problems/maximum-product-subarray/" target="_blank">LeetCode 152</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [2,3,-2,4]<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Maintain prefix and suffix products. If a 0 is encountered, reset the product to 1. The max overall is the answer since negatives cancel out in pairs.<br><br><b>Dependencies:</b> <code>#include <limits.h></code></td>
      <td><b>Edge Cases:</b> <b>Odd negative numbers:</b> Checking both prefix and suffix elegantly covers the case where we drop one negative.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProduct(vector&lt;int&gt;&amp; nums) {&#10;    double pref = 1, suff = 1, ans = INT_MIN;&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= nums[i];&#10;        suff *= nums[n-i-1];&#10;        ans = max({ans, pref, suff});&#10;    }&#10;    return (int)ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Arr 29 Count Inversions<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {2, 4, 1, 3, 5}<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N) auxiliary</td>
      <td>Optimal: Merge Sort approach. While merging two sorted halves, if left[i] > right[j], it forms an inversion with all remaining elements in the left half (mid - i + 1).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], int low, int mid, int high) {&#10;    vector&lt;long long&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    long long cnt = 0;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else { temp.push_back(arr[right++]); cnt += (mid - left + 1); }&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;    return cnt;&#10;}&#10;long long mergeSort(long long arr[], int low, int high) {&#10;    long long cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    return mergeSort(arr, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Arr 30 Reverse Pairs<br><br></b> <a href="https://leetcode.com/problems/reverse-pairs/" target="_blank">LeetCode 493</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,3,2,3,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Modified Merge Sort. Before merging, loop through left and right halves. If left[i] > 2 * right[j], increment j. Number of pairs is (j - (mid+1)).</td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Use long long when doubling nums[j].<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;}&#10;int countPairs(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    int right = mid + 1, cnt = 0;&#10;    for(int i = low; i &lt;= mid; i++) {&#10;        while(right &lt;= high &amp;&amp; arr[i] &gt; 2LL * arr[right]) right++;&#10;        cnt += (right - (mid + 1));&#10;    }&#10;    return cnt;&#10;}&#10;int mergeSort(vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += countPairs(arr, low, mid, high);&#10;    merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;int reversePairs(vector&lt;int&gt;&amp; nums) {&#10;    return mergeSort(nums, 0, nums.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Arr 31 Grid Unique Paths<br><br></b> <a href="https://leetcode.com/problems/unique-paths/" target="_blank">LeetCode 62</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> m = 3, n = 7<br><b>Output:</b> 28</td>
      <td><b>Time:</b> O(m-1)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Combinatorics approach. The total number of steps to reach the bottom-right corner is (m - 1) + (n - 1) = m + n - 2. Out of these steps, we need to choose (m - 1) downward steps (or n - 1 rightward steps). The number of paths is (m + n - 2) C (m - 1).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int uniquePaths(int m, int n) {&#10;    int N = n + m - 2;&#10;    int r = m - 1;&#10;    double res = 1;&#10;    for(int i = 1; i &lt;= r; i++) {&#10;        res = res * (N - r + i) / i;&#10;    }&#10;    return (int)res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Arr 32 Search A 2D Matrix<br><br></b> <a href="https://leetcode.com/problems/search-a-2d-matrix/" target="_blank">LeetCode 74</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log(m * n))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.</td>
      <td><b>Edge Cases:</b> <b>Empty Matrix:</b> Return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(!matrix.size()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int low = 0, high = (m * n) - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + (high - low) / 2);&#10;        if(matrix[mid/n][mid % n] == target) return true;&#10;        if(matrix[mid/n][mid % n] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Arr 33 Minimum Number Of Jumps<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Greedy tracking bounds.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Maintain `maxReach`, `steps`, and `jumps`. At each step `i`, `maxReach = max(maxReach, i + arr[i])`. Decrement `steps`. If `steps == 0`, `jumps++` and `steps = maxReach - i`. If `i >= maxReach`, return -1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minJumps(int arr[], int n) {&#10;    if(n &lt;= 1) return 0;&#10;    if(arr[0] == 0) return -1;&#10;    int maxReach = arr[0], steps = arr[0], jumps = 1;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(i == n - 1) return jumps;&#10;        maxReach = max(maxReach, i + arr[i]);&#10;        steps--;&#10;        if(steps == 0) {&#10;            jumps++;&#10;            if(i &gt;= maxReach) return -1;&#10;            steps = maxReach - i;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Arr 34 Kadanes Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Keep tracking current sum.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Maintain `max_sum` and `curr_sum`. For each element, `curr_sum = max(element, curr_sum + element)`. `max_sum = max(max_sum, curr_sum)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxSubarraySum(int arr[], int n) {&#10;    long long maxSum = arr[0], currSum = arr[0];&#10;    for(int i = 1; i &lt; n; i++) {&#10;        currSum = max((long long)arr[i], currSum + arr[i]);&#10;        maxSum = max(maxSum, currSum);&#10;    }&#10;    return maxSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Arr 35 Count Pairs With Given Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Use a hash map to store the frequencies of the elements seen so far. For each element `x`, check if `K - x` is in the hash map. If it is, add its frequency to the `count`. Finally, increment the frequency of `x` in the hash map.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getPairsCount(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int count = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(m.find(k - arr[i]) != m.end()) {&#10;            count += m[k - arr[i]];&#10;        }&#10;        m[arr[i]]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Arr 36 Common Elements In Three Sorted Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/common-elements1132/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Three pointers.</td>
      <td><b>Time:</b> O(N1 + N2 + N3)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use three pointers `i`, `j`, `k` for the three arrays. If `A[i] == B[j] == C[k]`, it's a common element, add it to the result (handling duplicates), and increment all three pointers. Else, increment the pointer that points to the smallest value.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {&#10;    vector&lt;int&gt; res;&#10;    int i = 0, j = 0, k = 0;&#10;    while(i &lt; n1 &amp;&amp; j &lt; n2 &amp;&amp; k &lt; n3) {&#10;        if(A[i] == B[j] &amp;&amp; B[j] == C[k]) {&#10;            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);&#10;            i++; j++; k++;&#10;        } else if(A[i] &lt;= B[j] &amp;&amp; A[i] &lt;= C[k]) i++;&#10;        else if(B[j] &lt;= A[i] &amp;&amp; B[j] &lt;= C[k]) j++;&#10;        else k++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Arr 37 Rearrange Array Alternately<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/rearrange-array-alternately-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Math-based encoding O(1) space.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: To achieve O(1) space, encode two values into one using `arr[i] += (arr[max_idx] % max_elem) * max_elem`. Iterate with two pointers `max_idx` and `min_idx`. At the end, divide every element by `max_elem`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rearrange(long long *arr, int n) {&#10;    int min_idx = 0, max_idx = n - 1;&#10;    long long max_elem = arr[n - 1] + 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) {&#10;            arr[i] += (arr[max_idx] % max_elem) * max_elem;&#10;            max_idx--;&#10;        } else {&#10;            arr[i] += (arr[min_idx] % max_elem) * max_elem;&#10;            min_idx++;&#10;        }&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        arr[i] = arr[i] / max_elem;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Arr 38 Rearrange Array In Alternating Positive And Negative Items<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and--ve-nos1401/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Extra Space Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Collect all positive numbers in one array and all negative numbers in another. Overwrite the original array by picking elements alternatively from the two arrays.</td>
      <td><b>Edge Cases:</b> Unequal count of positive and negative<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rearrange(int arr[], int n) {&#10;    vector&lt;int&gt; pos, neg;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(arr[i] &gt;= 0) pos.push_back(arr[i]);&#10;        else neg.push_back(arr[i]);&#10;    }&#10;    int i = 0, j = 0, k = 0;&#10;    while(i &lt; pos.size() &amp;&amp; j &lt; neg.size()) {&#10;        arr[k++] = pos[i++];&#10;        arr[k++] = neg[j++];&#10;    }&#10;    while(i &lt; pos.size()) arr[k++] = pos[i++];&#10;    while(j &lt; neg.size()) arr[k++] = neg[j++];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Arr 39 Subarray With 0 Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Prefix Sum with HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Iterate through the array and calculate the prefix sum. If the prefix sum is 0 or it already exists in a hash set, it means a subarray with sum 0 exists.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool subArrayExists(int arr[], int n) {&#10;    unordered_set&lt;int&gt; sumSet;&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += arr[i];&#10;        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;&#10;        sumSet.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Arr 40 Factorial Of A Large Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Array based multiplication.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N log(N!))</td>
      <td>Optimal: Use an array to store the result. Initially, it holds 1. Multiply the array by numbers from 2 to N. The multiplication is done school-style by carrying over remainders to the next index.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; factorial(int N) {&#10;    vector&lt;int&gt; res;&#10;    res.push_back(1);&#10;    for(int x = 2; x &lt;= N; x++) {&#10;        int carry = 0;&#10;        for(int i = 0; i &lt; res.size(); i++) {&#10;            int prod = res[i] * x + carry;&#10;            res[i] = prod % 10;&#10;            carry = prod / 10;&#10;        }&#10;        while(carry) {&#10;            res.push_back(carry % 10);&#10;            carry /= 10;&#10;        }&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Arr 41 Maximum Product Subarray<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Prefix and Suffix iteration.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate from left to right calculating prefix product, and right to left calculating suffix product. If either is 0, reset it to 1. The max product will be the max of all prefix and suffix products.</td>
      <td><b>Edge Cases:</b> Zero elements<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxProduct(vector&lt;int&gt; arr, int n) {&#10;    long long max_prod = INT_MIN;&#10;    long long pref = 1, suff = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= arr[i];&#10;        suff *= arr[n - i - 1];&#10;        max_prod = max({max_prod, pref, suff});&#10;    }&#10;    return max_prod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Arr 42 Longest Consecutive Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Set.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Insert all elements into a hash set. For each element, check if `element - 1` exists. If not, it's the start of a sequence. Then increment to find consecutive elements.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findLongestConseqSubseq(int arr[], int N) {&#10;    unordered_set&lt;int&gt; s;&#10;    for(int i = 0; i &lt; N; i++) s.insert(arr[i]);&#10;    int longest = 0;&#10;    for(int num : s) {&#10;        if(s.find(num - 1) == s.end()) {&#10;            int curr = num;&#10;            int count = 1;&#10;            while(s.find(curr + 1) != s.end()) {&#10;                curr++;&#10;                count++;&#10;            }&#10;            longest = max(longest, count);&#10;        }&#10;    }&#10;    return longest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Arr 43 Minimum Swaps And K Together<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: First count all elements <= k (let's say `cnt`). This will be the window size. Find elements > k in the first window. Then slide the window, updating the number of elements > k. The minimum among all windows is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minSwap(int arr[], int n, int k) {&#10;    int cnt = 0;&#10;    for(int i = 0; i &lt; n; i++) if(arr[i] &lt;= k) cnt++;&#10;    int bad = 0;&#10;    for(int i = 0; i &lt; cnt; i++) if(arr[i] &gt; k) bad++;&#10;    int ans = bad;&#10;    for(int i = 0, j = cnt; j &lt; n; i++, j++) {&#10;        if(arr[i] &gt; k) bad--;&#10;        if(arr[j] &gt; k) bad++;&#10;        ans = min(ans, bad);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Arr 44 Greedy 05 Fractional Knapsack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort by value/weight ratio.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort items in descending order of value/weight ratio. Greedily pick items with the highest ratio first. If an item cannot fit completely, take the fraction that fits.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Item { int value; int weight; };&#10;bool static comp(Item a, Item b) {&#10;    double r1 = (double)a.value / (double)a.weight;&#10;    double r2 = (double)b.value / (double)b.weight;&#10;    return r1 &gt; r2;&#10;}&#10;double fractionalKnapsack(int W, Item arr[], int n) {&#10;    sort(arr, arr + n, comp);&#10;    double currWeight = 0, finalValue = 0.0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(currWeight + arr[i].weight &lt;= W) {&#10;            currWeight += arr[i].weight;&#10;            finalValue += arr[i].value;&#10;        } else {&#10;            double remain = W - currWeight;&#10;            finalValue += (arr[i].value / (double)arr[i].weight) * remain;&#10;            break;&#10;        }&#10;    }&#10;    return finalValue;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">Arr 45 Greedy 06 Choose And Swap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Track first occurrences.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Store the first occurrence index of all characters. Iterate the string, for each character check if there is a lexicographically smaller character that appears later in the string. If so, swap them and break.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string chooseandswap(string a) {&#10;    set&lt;char&gt; s;&#10;    for(char c : a) s.insert(c);&#10;    for(int i = 0; i &lt; a.length(); i++) {&#10;        s.erase(a[i]);&#10;        if(s.empty()) break;&#10;        char ch = *s.begin();&#10;        if(ch &lt; a[i]) {&#10;            char ch1 = a[i], ch2 = ch;&#10;            for(int j = 0; j &lt; a.length(); j++) {&#10;                if(a[j] == ch1) a[j] = ch2;&#10;                else if(a[j] == ch2) a[j] = ch1;&#10;            }&#10;            break;&#10;        }&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">Arr 46 Greedy 07 Maximum Trains For Which Stoppage Can Be Provided<br><br></b> <a href="https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Activity Selection on each platform.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Group trains by platform. For each platform, this reduces to the Activity Selection Problem. Sort the trains by departure time and greedily pick non-overlapping trains.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Train { int arr, dep, plat; };&#10;bool comp(Train a, Train b) { return a.dep &lt; b.dep; }&#10;int maxStop(vector&lt;Train&gt;&amp; trains, int n, int m) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; platforms(m + 1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        platforms[trains[i].plat].push_back({trains[i].dep, trains[i].arr});&#10;    }&#10;    int count = 0;&#10;    for(int i = 1; i &lt;= m; i++) {&#10;        if(platforms[i].size() == 0) continue;&#10;        sort(platforms[i].begin(), platforms[i].end());&#10;        count++;&#10;        int lastDep = platforms[i][0].first;&#10;        for(int j = 1; j &lt; platforms[i].size(); j++) {&#10;            if(platforms[i][j].second &gt;= lastDep) {&#10;                count++;&#10;                lastDep = platforms[i][j].first;&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">Arr 47 Greedy 08 Minimum Platforms<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort arrival and departure times separately.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort arrival and departure arrays separately. Use two pointers, one for arrival and one for departure. If arrival < departure, a platform is needed, so increment count. If arrival >= departure, a platform is freed, so decrement count. Track the maximum count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPlatform(int arr[], int dep[], int n) {&#10;    sort(arr, arr + n);&#10;    sort(dep, dep + n);&#10;    int plat_needed = 1, result = 1;&#10;    int i = 1, j = 0;&#10;    while(i &lt; n &amp;&amp; j &lt; n) {&#10;        if(arr[i] &lt;= dep[j]) {&#10;            plat_needed++;&#10;            i++;&#10;        } else if(arr[i] &gt; dep[j]) {&#10;            plat_needed--;&#10;            j++;&#10;        }&#10;        if(plat_needed &gt; result) result = plat_needed;&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">Arr 48 Greedy 09 Buy Maximum Stocks If I Stocks Can Be Bought On I Th Day<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort by price.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Store pairs of (price, day). Sort by price. Greedily buy as many stocks as possible on the day with the lowest price, bounded by the maximum allowed on that day (which is 'day') and the remaining money.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int buyMaximumProducts(int n, int k, int price[]) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; v;&#10;    for(int i = 0; i &lt; n; i++) v.push_back({price[i], i + 1});&#10;    sort(v.begin(), v.end());&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int amount = min(v[i].second, k / v[i].first);&#10;        ans += amount;&#10;        k -= amount * v[i].first;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">49</td>
      <td rowspan="1">Arr 49 Greedy 10 Shop In Candy Store<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort and pick from ends.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the candies by price. For minimum cost, buy the cheapest and take K most expensive for free. For maximum cost, buy the most expensive and take K cheapest for free.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; candyStore(int candies[], int N, int K) {&#10;    sort(candies, candies + N);&#10;    int minCost = 0, maxCost = 0;&#10;    int i = 0, j = N - 1;&#10;    while(i &lt;= j) {&#10;        minCost += candies[i];&#10;        i++; j -= K;&#10;    }&#10;    i = N - 1; j = 0;&#10;    while(j &lt;= i) {&#10;        maxCost += candies[i];&#10;        i--; j += K;&#10;    }&#10;    return {minCost, maxCost};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">50</td>
      <td rowspan="1">Arr 50 Greedy 11 Minimize Cash Flow Among A Given Set Of Friends Who Have Borrowed Money From Each Other<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimize-cash-flow/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Net amounts.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Calculate the net amount for each person by subtracting incoming debts from outgoing debts. Find the person with maximum net credit and maximum net debit. Settle their amounts, and repeat recursively or iteratively until all net amounts are zero.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getMin(int arr[], int n) {&#10;    int minInd = 0;&#10;    for(int i = 1; i &lt; n; i++) if(arr[i] &lt; arr[minInd]) minInd = i;&#10;    return minInd;&#10;}&#10;int getMax(int arr[], int n) {&#10;    int maxInd = 0;&#10;    for(int i = 1; i &lt; n; i++) if(arr[i] &gt; arr[maxInd]) maxInd = i;&#10;    return maxInd;&#10;}&#10;void minCashFlowRec(int amount[], int n, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    int mxCredit = getMax(amount, n), mxDebit = getMin(amount, n);&#10;    if(amount[mxCredit] == 0 &amp;&amp; amount[mxDebit] == 0) return;&#10;    int minVal = min(-amount[mxDebit], amount[mxCredit]);&#10;    amount[mxCredit] -= minVal;&#10;    amount[mxDebit] += minVal;&#10;    ans[mxDebit][mxCredit] = minVal;&#10;    minCashFlowRec(amount, n, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; minCashFlow(vector&lt;vector&lt;int&gt;&gt;&amp; graph, int n) {&#10;    int amount[n] = {0};&#10;    for(int p = 0; p &lt; n; p++) {&#10;        for(int i = 0; i &lt; n; i++) {&#10;            amount[p] += (graph[i][p] - graph[p][i]);&#10;        }&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans(n, vector&lt;int&gt;(n, 0));&#10;    minCashFlowRec(amount, n, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">51</td>
      <td rowspan="1">Arr 51 Greedy 12 Minimum Cost To Cut A Board Into Squares<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort costs.</td>
      <td><b>Time:</b> O(M log M + N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort all vertical and horizontal cuts in descending order. Maintain counts of horizontal and vertical pieces. Greedily pick the cut with the highest cost. If a horizontal cut is made, its total cost is `cut_cost * vertical_pieces`. Update the counts.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumCostOfBreaking(vector&lt;int&gt; X, vector&lt;int&gt; Y, int M, int N) {&#10;    sort(X.begin(), X.end(), greater&lt;int&gt;());&#10;    sort(Y.begin(), Y.end(), greater&lt;int&gt;());&#10;    int hzntl = 1, vert = 1;&#10;    int i = 0, j = 0, res = 0;&#10;    while(i &lt; M - 1 &amp;&amp; j &lt; N - 1) {&#10;        if(X[i] &gt; Y[j]) {&#10;            res += X[i] * vert;&#10;            hzntl++; i++;&#10;        } else {&#10;            res += Y[j] * hzntl;&#10;            vert++; j++;&#10;        }&#10;    }&#10;    int total = 0;&#10;    while(i &lt; M - 1) total += X[i++];&#10;    res += total * vert;&#10;    total = 0;&#10;    while(j &lt; N - 1) total += Y[j++];&#10;    res += total * hzntl;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">52</td>
      <td rowspan="1">Arr 52 Greedy 13 Survival On Island<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Math.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Optimal: If total required food > max food you can buy in S days excluding Sundays, return -1. Else, total required food is `S * M`. Minimum days = `ceil((S * M) / N)`. Also handle the edge case where `N < M` or if survival > 6 days and `(N * 6) < (M * 7)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumDays(int S, int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    if(S &gt; 6 &amp;&amp; (N * 6) &lt; (M * 7)) return -1;&#10;    int total = S * M;&#10;    return ceil((double)total / N);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">53</td>
      <td rowspan="1">Arr 53 Greedy 14 Maximum Meetings In One Room<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Activity Selection.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Store `(start, end, index)`. Sort by end time. Pick the first meeting. For subsequent meetings, if `start > last_picked_end`, pick it and update `last_picked_end`. Return sorted indices.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Meeting { int s, e, pos; };&#10;bool comp(Meeting a, Meeting b) {&#10;    if(a.e == b.e) return a.pos &lt; b.pos;&#10;    return a.e &lt; b.e;&#10;}&#10;vector&lt;int&gt; maxMeetings(int N, vector&lt;int&gt;&amp; S, vector&lt;int&gt;&amp; F) {&#10;    vector&lt;Meeting&gt; m(N);&#10;    for(int i = 0; i &lt; N; i++) { m[i].s = S[i]; m[i].e = F[i]; m[i].pos = i + 1; }&#10;    sort(m.begin(), m.end(), comp);&#10;    vector&lt;int&gt; ans;&#10;    ans.push_back(m[0].pos);&#10;    int last_e = m[0].e;&#10;    for(int i = 1; i &lt; N; i++) {&#10;        if(m[i].s &gt; last_e) {&#10;            ans.push_back(m[i].pos);&#10;            last_e = m[i].e;&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">54</td>
      <td rowspan="1">Arr 54 Trapping Rain Water<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use two pointers, left and right. Maintain left_max and right_max. If `arr[left] <= arr[right]`, the water trapped depends on left_max. If `arr[left] > left_max`, update left_max, else add `left_max - arr[left]` to answer and increment left. Repeat for right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long trappingWater(int arr[], int n) {&#10;    int left = 0, right = n - 1;&#10;    int left_max = 0, right_max = 0;&#10;    long long res = 0;&#10;    while(left &lt;= right) {&#10;        if(arr[left] &lt;= arr[right]) {&#10;            if(arr[left] &gt;= left_max) left_max = arr[left];&#10;            else res += left_max - arr[left];&#10;            left++;&#10;        } else {&#10;            if(arr[right] &gt;= right_max) right_max = arr[right];&#10;            else res += right_max - arr[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">55</td>
      <td rowspan="1">Arr 55 Chocolate Distribution Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort and Slide.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the array. Find the minimum difference between `A[i+M-1]` and `A[i]` for all possible `i` from `0` to `N-M`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long findMinDiff(vector&lt;long long&gt; a, long long n, long long m){&#10;    sort(a.begin(), a.end());&#10;    long long min_diff = LLONG_MAX;&#10;    for(int i = 0; i + m - 1 &lt; n; i++) {&#10;        if(a[i + m - 1] - a[i] &lt; min_diff) {&#10;            min_diff = a[i + m - 1] - a[i];&#10;        }&#10;    }&#10;    return min_diff;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">56</td>
      <td rowspan="1">Arr 56 Smallest Subarray With Sum Greater Than X<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use a sliding window. Add elements to `curr_sum` and increment `end`. When `curr_sum > x`, update `min_len` and subtract `arr[start]`, increment `start`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int smallestSubWithSum(int arr[], int n, int x) {&#10;    int curr_sum = 0, min_len = n + 1;&#10;    int start = 0, end = 0;&#10;    while(end &lt; n) {&#10;        while(curr_sum &lt;= x &amp;&amp; end &lt; n) curr_sum += arr[end++];&#10;        while(curr_sum &gt; x &amp;&amp; start &lt; n) {&#10;            min_len = min(min_len, end - start);&#10;            curr_sum -= arr[start++];&#10;        }&#10;    }&#10;    return (min_len == n + 1) ? 0 : min_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">57</td>
      <td rowspan="1">Arr 57 Three Way Partitioning<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/three-way-partitioning/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Dutch National Flag algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use three pointers: `low`, `mid`, `high`. If `arr[mid] < a`, swap `arr[low]` and `arr[mid]`, increment both. If `arr[mid] > b`, swap `arr[mid]` and `arr[high]`, decrement `high`. Else increment `mid`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void threeWayPartition(vector&lt;int&gt;&amp; array, int a, int b) {&#10;    int low = 0, mid = 0, high = array.size() - 1;&#10;    while(mid &lt;= high) {&#10;        if(array[mid] &lt; a) {&#10;            swap(array[low], array[mid]);&#10;            low++; mid++;&#10;        } else if(array[mid] &gt; b) {&#10;            swap(array[mid], array[high]);&#10;            high--;&#10;        } else {&#10;            mid++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">58</td>
      <td rowspan="1">Arr 58 Palindromic Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Check individual numbers.</td>
      <td><b>Time:</b> O(N * d)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate through each number in the array. For each number, reverse its digits to check if it's a palindrome. If any number is not, return 0. If all are, return 1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int N) {&#10;    int rev = 0, temp = N;&#10;    while(temp &gt; 0) {&#10;        rev = rev * 10 + temp % 10;&#10;        temp /= 10;&#10;    }&#10;    return rev == N;&#10;}&#10;int PalinArray(int a[], int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(!isPalindrome(a[i])) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">59</td>
      <td rowspan="1">Arr 59 Find The Median<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-median0527/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort array.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the array. If the size is odd, the median is the middle element. If the size is even, the median is the average of the two middle elements.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int find_median(vector&lt;int&gt; v) {&#10;    sort(v.begin(), v.end());&#10;    int n = v.size();&#10;    if(n % 2 != 0) return v[n / 2];&#10;    else return (v[n / 2 - 1] + v[n / 2]) / 2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">60</td>
      <td rowspan="1">Arr 60 Median Of Two Sorted Arrays Of Different Sizes<br><br></b> <a href="https://leetcode.com/problems/median-of-two-sorted-arrays/" target="_blank">LeetCode 4</a></td>
      <td rowspan="1"><b> </b> Binary Search.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use Binary Search on the smaller array. Partition both arrays such that the number of elements on the left side is equal to or one more than the right side. Check if `maxLeftX <= minRightY` and `maxLeftY <= minRightX`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int x = nums1.size(), y = nums2.size();&#10;    int low = 0, high = x;&#10;    while(low &lt;= high) {&#10;        int partitionX = (low + high) / 2;&#10;        int partitionY = (x + y + 1) / 2 - partitionX;&#10;        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];&#10;        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];&#10;        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];&#10;        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];&#10;        if(maxLeftX &lt;= minRightY &amp;&amp; maxLeftY &lt;= minRightX) {&#10;            if((x + y) % 2 == 0) return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;&#10;            else return max(maxLeftX, maxLeftY);&#10;        } else if(maxLeftX &gt; minRightY) high = partitionX - 1;&#10;        else low = partitionX + 1;&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">61</td>
      <td rowspan="1">Arr 61 Count More Than N K Occurences<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-element-occurences/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> HashMap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Store the frequencies of all elements in a hash map. Iterate through the hash map and count the number of elements having frequency greater than `N/k`.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countOccurence(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    for(int i = 0; i &lt; n; i++) count[arr[i]]++;&#10;    int res = 0;&#10;    int target = n / k;&#10;    for(auto it : count) {&#10;        if(it.second &gt; target) res++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">62</td>
      <td rowspan="1">Arr 62 Find The Missing Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sum formula.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Calculate the sum of first N natural numbers using `N*(N+1)/2`. Subtract the sum of all elements in the array from it. The result is the missing number.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(vector&lt;int&gt;&amp; array, int n) {&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; n - 1; i++) sum += array[i];&#10;    long long expectedSum = (long long)n * (n + 1) / 2;&#10;    return expectedSum - sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">63</td>
      <td rowspan="1">Arr 63 Max Sum In Sub Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Adjacent pairs sum.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: The maximum sum of two smallest elements in any subarray will always be the maximum sum of adjacent elements. So, just iterate and find the max of `arr[i] + arr[i+1]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long pairWithMaxSum(long long arr[], long long N) {&#10;    long long maxi = 0;&#10;    for(long long i = 0; i &lt; N - 1; i++) {&#10;        maxi = max(maxi, arr[i] + arr[i+1]);&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">64</td>
      <td rowspan="1">Arr 64 Longest Subarray With Sum K Positives<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window / Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Since all elements are positive, use two pointers (sliding window). Expand `right` and add to sum. If sum > K, shrink `left` and subtract from sum. If sum == K, update max length.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(int A[],  int N, int K) {&#10;    int left = 0, right = 0;&#10;    long long sum = 0;&#10;    int maxLen = 0;&#10;    while(right &lt; N) {&#10;        sum += A[right];&#10;        while(sum &gt; K &amp;&amp; left &lt;= right) {&#10;            sum -= A[left];&#10;            left++;&#10;        }&#10;        if(sum == K) maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">65</td>
      <td rowspan="1">Arr 65 Merge Sorted Array Without Extra Space<br><br></b> <a href="https://leetcode.com/problems/merge-sorted-array/" target="_blank">LeetCode 88</a></td>
      <td rowspan="1"><b> </b> Two pointers from end.</td>
      <td><b>Time:</b> O(M + N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Since `nums1` has enough space at the end, use three pointers: `p1` at the end of valid elements in `nums1` (m-1), `p2` at the end of `nums2` (n-1), and `p` at the very end of `nums1` (m+n-1). Compare elements at `p1` and `p2`, put the larger one at `p`, and decrement pointers.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; nums1, int m, vector&lt;int&gt;&amp; nums2, int n) {&#10;    int p1 = m - 1, p2 = n - 1, p = m + n - 1;&#10;    while(p1 &gt;= 0 &amp;&amp; p2 &gt;= 0) {&#10;        if(nums1[p1] &gt; nums2[p2]) nums1[p--] = nums1[p1--];&#10;        else nums1[p--] = nums2[p2--];&#10;    }&#10;    while(p2 &gt;= 0) nums1[p--] = nums2[p2--];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Hashing

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
      <td rowspan="2">1</td>
      <td rowspan="2">Hash 01 Count Frequencies<br><br></b> <a href="https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> arr = [10, 5, 10, 15, 10, 5]<br><b>Output:</b> 10->3, 5->2, 15->1<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use two nested loops to count frequency of each element, marking visited ones.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void countFreq(vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; visited(n, false);&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(visited[i]) continue;&#10;        int count = 1;&#10;        for(int j=i+1; j&lt;n; j++) {&#10;            if(arr[i] == arr[j]) {&#10;                visited[j] = true;&#10;                count++;&#10;            }&#10;        }&#10;        cout &lt;&lt; arr[i] &lt;&lt; &quot; &quot; &lt;&lt; count &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Use two nested loops to count occurrences. Mark visited elements to avoid recounting.</td>
      <td><b>Edge Cases:</b> <b>Marking Checked:</b> Requires mutating array or extra boolean array to track checked elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">\n\n\n\nvoid countFreq(std::vector&lt;int&gt;&amp; arr) {\n    std::unordered_map&lt;int, int&gt; freq;\n    for(int num : arr) {\n        freq[num]++;\n    }\n    for(auto it : freq) {\n        std::cout &lt;&lt; it.first &lt;&lt; \&quot; \&quot; &lt;&lt; it.second &lt;&lt; \&quot;\\n\&quot;;\n    }\n}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Hash 02 Highest Lowest Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-array-by-increasing-frequency/" target="_blank">LeetCode 1636</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 10, 15, 10, 5]<br><b>Output:</b> Highest=10, Lowest=15<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Build a frequency map, then iterate through the map to find the max and min frequencies.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Set min_freq to `INT_MAX` properly to allow map values to overwrite it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findHighLowFreq(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : arr) freq[num]++;&#10;    &#10;    int max_f = 0, min_f = INT_MAX;&#10;    int max_ele = 0, min_ele = 0;&#10;    &#10;    for(auto it : freq) {&#10;        if(it.second &gt; max_f) { max_f = it.second; max_ele = it.first; }&#10;        if(it.second &lt; min_f) { min_f = it.second; min_ele = it.first; }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">3</td>
      <td rowspan="2">Hash 03 Intersection Of Two Arrays<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-arrays/" target="_blank">LeetCode 349</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums1 = [1,2,2,1], nums2 = [2,2]<br><b>Output:</b> [2]<br><br><b> </b> 1 &le; N, M &le; 1000</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(min(N, M))</td>
      <td><b>Approach 1:</b><br>Brute Force: Iterate through the first array and check each element in the second array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; intersection(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    vector&lt;int&gt; res;&#10;    for(int i=0; i&lt;nums1.size(); i++) {&#10;        bool found = false;&#10;        for(int j=0; j&lt;nums2.size(); j++) {&#10;            if(nums1[i] == nums2[j]) { found = true; break; }&#10;        }&#10;        if(found &amp;&amp; find(res.begin(), res.end(), nums1[i]) == res.end()) {&#10;            res.push_back(nums1[i]);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Store elements of the first array in a Hash Set, then iterate over the second array to find matches.<br><br><b>Dependencies:</b> <code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Match Prevention:</b> Erase matched elements from the set immediately to prevent duplicate intersections.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; intersection(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_set&lt;int&gt; s(nums1.begin(), nums1.end());&#10;    std::vector&lt;int&gt; res;&#10;    for(int num : nums2) {&#10;        if(s.find(num) != s.end()) {&#10;            res.push_back(num);&#10;            s.erase(num); // Ensure uniqueness&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Hash 04 Union Of Two Arrays<br><br></b> <a href="https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> a = [1, 2, 3], b = [2, 3, 4]<br><b>Output:</b> [1, 2, 3, 4]<br><br><b> </b> Arrays may not be sorted.</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N + M) (Trade-off)</td>
      <td>Optimal: Insert all elements from both arrays into a Hash Set. The Set natively drops duplicates.<br><br><b>Dependencies:</b> <code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Edge Cases:</b> <b>Unordered Limitation:</b> If the problem expects sorted union, `std::set` must be used increasing time to `O((N+M)log(N+M))`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; findUnion(std::vector&lt;int&gt;&amp; a, std::vector&lt;int&gt;&amp; b) {&#10;    std::unordered_set&lt;int&gt; s;&#10;    for(int num : a) s.insert(num);&#10;    for(int num : b) s.insert(num);&#10;    &#10;    std::vector&lt;int&gt; res(s.begin(), s.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Hash 05 Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [4, 2, -3, 1, 6]<br><b>Output:</b> true (2, -3, 1)<br><br><b> </b> Array contains positive and negative integers.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Use a Prefix Sum and a Hash Set. If a prefix sum repeats, or equals 0, a 0-sum subarray exists between the identical prefix sums.<br><br><b>Dependencies:</b> <code>std::unordered_set</code></td>
      <td><b>Edge Cases:</b> <b>Zero Prefix Edge Case:</b> If `sum == 0` during traversal, the subarray naturally started from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasZeroSumSubarray(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_set&lt;int&gt; prefix_sums;&#10;    int sum = 0;&#10;    for(int num : arr) {&#10;        sum += num;&#10;        if(sum == 0 || prefix_sums.find(sum) != prefix_sums.end()) {&#10;            return true;&#10;        }&#10;        prefix_sums.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Hash 06 Subarray Sum Equals K<br><br></b> <a href="https://leetcode.com/problems/subarray-sum-equals-k/" target="_blank">LeetCode 560</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,1,1], k = 2<br><b>Output:</b> 2<br><br><b> </b> Negative numbers allowed, preventing pure Sliding Window approaches.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Generate all possible subarrays and compute their sums.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int subarraySum(vector&lt;int&gt;&amp; nums, int k) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;nums.size(); i++) {&#10;        int sum = 0;&#10;        for(int j=i; j&lt;nums.size(); j++) {&#10;            sum += nums[j];&#10;            if(sum == k) count++;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Approach 2:</b><br>Optimal: Maintain a Hash Map of `prefix_sum` -> `frequency`. If `curr_sum - k` exists in the map, add its frequency to the count.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Base Case Injection:</b> Must initialize map with `(0, 1)` to correctly count subarrays starting natively from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int subarraySum(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; prefix_freq;&#10;    prefix_freq[0] = 1; // Base case for subarrays starting at index 0&#10;    &#10;    int count = 0, sum = 0;&#10;    for(int num : nums) {&#10;        sum += num;&#10;        int remove = sum - k;&#10;        if(prefix_freq.find(remove) != prefix_freq.end()) {&#10;            count += prefix_freq[remove];&#10;        }&#10;        prefix_freq[sum]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Hash 07 Longest Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [15,-2,2,-8,1,7,10,23]<br><b>Output:</b> 5<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Store `prefix_sum` -> `index` in Hash Map. If sum repeats, calculate distance `i - hash[sum]`.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Longest Policy:</b> We only insert `sum` into the map if it doesn't exist to preserve the earliest index and maximize distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; prefix_index;&#10;    int max_len = 0, sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == 0) {&#10;            max_len = i + 1;&#10;        } else if(prefix_index.find(sum) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[sum]);&#10;        } else {&#10;            prefix_index[sum] = i; // Store only first occurrence&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Hash 08 Longest Subarray With Sum K<br><br></b> <a href="https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 2, 7, 1, 9], k = 15<br><b>Output:</b> 4<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Prefix Sum Map storing indices. Check if `sum - K` exists in map and calculate index difference.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Zero Elements Rule:</b> Never overwrite existing prefix sums in the map, otherwise arrays with zero elements will shorten the max length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(std::vector&lt;int&gt;&amp; arr, int k) {&#10;    std::unordered_map&lt;long long, int&gt; prefix_index;&#10;    int max_len = 0;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == k) {&#10;            max_len = i + 1;&#10;        }&#10;        long long needed = sum - k;&#10;        if(prefix_index.find(needed) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[needed]);&#10;        }&#10;        if(prefix_index.find(sum) == prefix_index.end()) {&#10;            prefix_index[sum] = i;&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Hash 09 Two Sum<br><br></b> <a href="https://leetcode.com/problems/two-sum/" target="_blank">LeetCode 1</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [2,7,11,15], target = 9<br><b>Output:</b> [0,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Iterate while storing numbers and their indices in a hash map. Check if `target - num` already exists.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Elements:</b> Storing elements as we iterate safely handles duplicates (e.g., target 6, array [3,3]).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; twoSum(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        int needed = target - nums[i];&#10;        if(mpp.find(needed) != mpp.end()) {&#10;            return {mpp[needed], i};&#10;        }&#10;        mpp[nums[i]] = i;&#10;    }&#10;    return {};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Hash 10 Group Anagrams<br><br></b> <a href="https://leetcode.com/problems/group-anagrams/" target="_blank">LeetCode 49</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> strs = ["eat","tea","tan","ate","nat","bat"]<br><b>Output:</b> [["bat"],["nat","tan"],["ate","eat","tea"]]</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td>Optimal: Use a hash map where the key is the sorted version of the string, and the value is a list of anagrams.<br><br><b>Dependencies:</b> <code>std::unordered_map</code>, <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Empty Strings:</b> Safely handled since an empty string sorted is still empty, forming a valid key.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;std::string&gt;&gt; groupAnagrams(std::vector&lt;std::string&gt;&amp; strs) {&#10;    std::unordered_map&lt;std::string, std::vector&lt;std::string&gt;&gt; mpp;&#10;    for(std::string s : strs) {&#10;        std::string key = s;&#10;        std::sort(key.begin(), key.end());&#10;        mpp[key].push_back(s);&#10;    }&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    for(auto it : mpp) {&#10;        ans.push_back(it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Hash 11 Longest Consecutive Sequence<br><br></b> <a href="https://leetcode.com/problems/longest-consecutive-sequence/" target="_blank">LeetCode 128</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [100,4,200,1,3,2]<br><b>Output:</b> 4 (The sequence is [1, 2, 3, 4])</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array first, then count consecutive elements linearly.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestConsecutive(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return 0;&#10;    sort(nums.begin(), nums.end());&#10;    int longest = 1, current = 1;&#10;    for(int i=1; i&lt;nums.size(); i++) {&#10;        if(nums[i] == nums[i-1]) continue;&#10;        if(nums[i] == nums[i-1] + 1) current++;&#10;        else {&#10;            longest = max(longest, current);&#10;            current = 1;&#10;        }&#10;    }&#10;    return max(longest, current);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 2:</b><br>Optimal: Insert all elements into a Hash Set. Iterate through elements. If `num - 1` is NOT in the set, it's the start of a sequence. Count forwards.<br><br><b>Dependencies:</b> <code>std::unordered_set</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Elements:</b> Handled automatically by the Set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestConsecutive(std::vector&lt;int&gt;&amp; nums) {&#10;    std::unordered_set&lt;int&gt; st(nums.begin(), nums.end());&#10;    int max_len = 0;&#10;    for(int num : st) {&#10;        if(st.find(num - 1) == st.end()) {&#10;            int curr_num = num;&#10;            int curr_len = 1;&#10;            while(st.find(curr_num + 1) != st.end()) {&#10;                curr_num++;&#10;                curr_len++;&#10;            }&#10;            max_len = std::max(max_len, curr_len);&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Hash 12 Longest Subarray With 0 Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Maintain the prefix sum and a hash map storing the first occurrence index of each prefix sum. If sum is 0, length is `i+1`. If sum is in the map, length is `i - map[sum]`. Update max length.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(vector&lt;int&gt;&amp; A, int n) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int maxi = 0, sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += A[i];&#10;        if(sum == 0) maxi = i + 1;&#10;        else {&#10;            if(m.find(sum) != m.end()) {&#10;                maxi = max(maxi, i - m[sum]);&#10;            } else {&#10;                m[sum] = i;&#10;            }&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Hash 13 Sort Characters By Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-characters-by-frequency/" target="_blank">LeetCode 451</a></td>
      <td rowspan="1"><b> </b> Hash Map + Priority Queue / Sorting.</td>
      <td><b>Time:</b> O(N log K) where K is unique chars<br><b>Space:</b> O(K)</td>
      <td>Optimal: Count frequencies using a hash map. Add pairs `(freq, char)` to a max heap or vector and sort. Reconstruct string.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string frequencySort(string s) {&#10;    unordered_map&lt;char, int&gt; freq;&#10;    for(char c : s) freq[c]++;&#10;    vector&lt;pair&lt;int, char&gt;&gt; v;&#10;    for(auto it : freq) v.push_back({it.second, it.first});&#10;    sort(v.rbegin(), v.rend());&#10;    string ans = &quot;&quot;;&#10;    for(auto it : v) {&#10;        ans += string(it.first, it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Hash 14 Count Distinct Elements In Every Window<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Optimal: Use a hash map to keep track of element frequencies in the window of size K. The number of distinct elements is the size of the hash map. As window slides, increment frequency of new element, decrement frequency of outgoing element. If frequency becomes 0, remove it from map.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; countDistinct(int A[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; k; i++) m[A[i]]++;&#10;    ans.push_back(m.size());&#10;    for(int i = k; i &lt; n; i++) {&#10;        m[A[i - k]]--;&#10;        if(m[A[i - k]] == 0) m.erase(A[i - k]);&#10;        m[A[i]]++;&#10;        ans.push_back(m.size());&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Hash 15 Design Hashset<br><br></b> <a href="https://leetcode.com/problems/design-hashset/" target="_blank">LeetCode 705</a></td>
      <td rowspan="1"><b> </b> Array of Linked Lists (Chaining).</td>
      <td><b>Time:</b> O(1) average, O(N) worst case<br><b>Space:</b> O(N)</td>
      <td>Optimal: Use a large array (e.g., size 10000) of linked lists or vectors. The hash function maps `key` to `key % 10000`. To add, if not present in the bucket, append it. To remove, find and erase. To contain, iterate through bucket.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MyHashSet {&#10;    vector&lt;list&lt;int&gt;&gt; buckets;&#10;    int size = 10000;&#10;public:&#10;    MyHashSet() {&#10;        buckets.resize(size);&#10;    }&#10;    void add(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it == buckets[i].end()) buckets[i].push_back(key);&#10;    }&#10;    void remove(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        if(it != buckets[i].end()) buckets[i].erase(it);&#10;    }&#10;    bool contains(int key) {&#10;        int i = key % size;&#10;        auto it = find(buckets[i].begin(), buckets[i].end(), key);&#10;        return it != buckets[i].end();&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Strings

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
      <td rowspan="1">Str 01 Valid Palindrome<br><br></b> <a href="https://leetcode.com/problems/valid-palindrome/" target="_blank">LeetCode 125</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "A man, a plan, a canal: Panama"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Two-pointer approach skipping non-alphanumeric characters. Compare characters from both ends.<br><br><b>Dependencies:</b> <code>std::isalnum</code>, <code>std::tolower</code></td>
      <td><b>Edge Cases:</b> <b>All Non-Alphanumeric:</b> Pointers might cross without any comparisons. Loop condition `left < right` safely handles it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(std::string s) {&#10;    int left = 0, right = s.length() - 1;&#10;    while (left &lt; right) {&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[left])) left++;&#10;        while (left &lt; right &amp;&amp; !std::isalnum(s[right])) right--;&#10;        if (std::tolower(s[left]) != std::tolower(s[right])) return false;&#10;        left++; right--;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Str 02 Valid Anagram<br><br></b> <a href="https://leetcode.com/problems/valid-anagram/" target="_blank">LeetCode 242</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "anagram", t = "nagaram"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a frequency array of size 26. Increment for `s`, decrement for `t`. Check if all counts are 0.</td>
      <td><b>Edge Cases:</b> <b>Length Mismatch:</b> If lengths differ, return false immediately to prevent boundary issues.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isAnagram(std::string s, std::string t) {&#10;    if(s.length() != t.length()) return false;&#10;    std::vector&lt;int&gt; freq(26, 0);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        freq[s[i] - &#x27;a&#x27;]++;&#10;        freq[t[i] - &#x27;a&#x27;]--;&#10;    }&#10;    for(int count : freq) {&#10;        if(count != 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Str 03 Longest Common Prefix<br><br></b> <a href="https://leetcode.com/problems/longest-common-prefix/" target="_blank">LeetCode 14</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> strs = ["flower","flow","flight"]<br><b>Output:</b> "fl"</td>
      <td><b>Time:</b> O(N log N * M) (Constraint)<br><b>Space:</b> O(1) / O(M)</td>
      <td>Sort the array. The common prefix will be constrained by the first and last strings in the sorted array.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>No Match:</b> If the first character of `first` and `last` string doesn't match, loop breaks immediately, returning "".<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::string longestCommonPrefix(std::vector&lt;std::string&gt;&amp; strs) {&#10;    if (strs.empty()) return &quot;&quot;;&#10;    std::sort(strs.begin(), strs.end());&#10;    std::string first = strs.front();&#10;    std::string last = strs.back();&#10;    int i = 0;&#10;    while(i &lt; first.size() &amp;&amp; i &lt; last.size() &amp;&amp; first[i] == last[i]) {&#10;        i++;&#10;    }&#10;    return first.substr(0, i);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Str 04 Longest Palindromic Substring<br><br></b> <a href="https://leetcode.com/problems/longest-palindromic-substring/" target="_blank">LeetCode 5</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "babad"<br><b>Output:</b> "bab"</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Expand Around Center. A palindrome can have an odd (center is 1 char) or even (center is between 2 chars) length. Test both.</td>
      <td><b>Edge Cases:</b> <b>Substr Math:</b> `start` is calculated as `i - (len - 1) / 2` to safely encompass both odd and even length centers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int expand(std::string&amp; s, int left, int right) {&#10;    while (left &gt;= 0 &amp;&amp; right &lt; s.length() &amp;&amp; s[left] == s[right]) {&#10;        left--; right++;&#10;    }&#10;    return right - left - 1;&#10;}&#10;&#10;std::string longestPalindrome(std::string s) {&#10;    if (s.empty()) return &quot;&quot;;&#10;    int start = 0, max_len = 0;&#10;    for (int i = 0; i &lt; s.length(); i++) {&#10;        int len1 = expand(s, i, i);&#10;        int len2 = expand(s, i, i + 1);&#10;        int len = std::max(len1, len2);&#10;        if (len &gt; max_len) {&#10;            max_len = len;&#10;            start = i - (len - 1) / 2;&#10;        }&#10;    }&#10;    return s.substr(start, max_len);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Str 05 Kmp Algorithm<br><br></b> <a href="https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/" target="_blank">LeetCode 28</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> haystack = 'sadbutsad', needle = 'sad'<br><b>Output:</b> 0</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>Compute the LPS (Longest Proper Prefix which is also Suffix) array for the needle. Use the LPS array to skip characters while matching with the haystack, reducing time to O(N+M).<br><br><b>Dependencies:</b> <code>#include <vector></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int strStr(string haystack, string needle) {&#10;    if(needle.empty()) return 0;&#10;    int m = needle.length(), n = haystack.length();&#10;    vector&lt;int&gt; lps(m, 0);&#10;    int len = 0, i = 1;&#10;    while(i &lt; m) {&#10;        if(needle[i] == needle[len]) lps[i++] = ++len;&#10;        else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else lps[i++] = 0;&#10;        }&#10;    }&#10;    i = 0; int j = 0;&#10;    while(i &lt; n) {&#10;        if(needle[j] == haystack[i]) { i++; j++; }&#10;        if(j == m) return i - j;&#10;        else if(i &lt; n &amp;&amp; needle[j] != haystack[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Str 06 Rabin Karp<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4cea159/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return array of starting indices.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Compute hash for pattern and first window of text. Slide window: subtract leading char's hash contribution, shift, and add trailing char. If hashes match, explicitly check strings to avoid collisions.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    vector&lt;int&gt; res;&#10;    int d = 256, q = 101;&#10;    int m = pat.length(), n = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    for(i=0; i&lt;m-1; i++) h = (h * d) % q;&#10;    for(i=0; i&lt;m; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for(i=0; i&lt;=n-m; i++) {&#10;        if(p == t) {&#10;            for(j=0; j&lt;m; j++) if(txt[i+j] != pat[j]) break;&#10;            if(j == m) res.push_back(i+1); // 1-based index usually&#10;        }&#10;        if(i &lt; n-m) {&#10;            t = (d * (t - txt[i] * h) + txt[i+m]) % q;&#10;            if(t &lt; 0) t += q;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Str 07 Reverse A String<br><br></b> <a href="https://leetcode.com/problems/reverse-string/" target="_blank">LeetCode 344</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers swap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers, `left` at the beginning and `right` at the end of the string. Swap the characters at these pointers and move them towards each other until they meet.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void reverseString(vector&lt;char&gt;&amp; s) {&#10;    int left = 0, right = s.size() - 1;&#10;    while(left &lt; right) {&#10;        swap(s[left++], s[right--]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Str 08 Palindrome String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindrome-string0817/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers, `left` at the beginning and `right` at the end of the string. Compare the characters at these pointers. If they are different, return 0. Move pointers towards each other. If all characters match, return 1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPalindrome(string S) {&#10;    int left = 0, right = S.length() - 1;&#10;    while(left &lt; right) {&#10;        if(S[left] != S[right]) return 0;&#10;        left++; right--;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Str 09 Find Duplicate Characters In A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-duplicate-characters-in-a-string/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Frequency array or Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a hash map or frequency array to count occurrences of each character. Then, iterate through the map/array and print characters with a count greater than 1.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDups(string str) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    for(char c : str) count[c]++;&#10;    for(auto it : count) {&#10;        if(it.second &gt; 1) cout &lt;&lt; it.first &lt;&lt; &quot;, count = &quot; &lt;&lt; it.second &lt;&lt; &quot;\n&quot;;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Str 10 A Program To Check If Strings Are Rotations Of Each Other<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Concatenate and find.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If the lengths are different, return false. Otherwise, concatenate `s1` with itself (`s1 + s1`). If `s2` is a rotation of `s1`, it must be a substring of the concatenated string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool areRotations(string s1, string s2) {&#10;    if(s1.length() != s2.length()) return false;&#10;    string temp = s1 + s1;&#10;    return (temp.find(s2) != string::npos);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Str 11 Check If A String Is A Valid Shuffle Of Two Distinct Strings<br><br></b> <a href="https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings" target="_blank">Article</a></td>
      <td rowspan="1"><b>Example 1:</b> Three pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>If lengths don't match, return false. Use three pointers `i`, `j`, `k` for `str1`, `str2`, and `str3`. Traverse `str3`. If `str3[k] == str1[i]`, increment `i` and `k`. Else if `str3[k] == str2[j]`, increment `j` and `k`. Else, it's not a valid shuffle. After the loop, check if both `str1` and `str2` are fully traversed.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkShuffle(string str1, string str2, string str3) {&#10;    if(str1.length() + str2.length() != str3.length()) return false;&#10;    int i = 0, j = 0, k = 0;&#10;    while(k &lt; str3.length()) {&#10;        if(i &lt; str1.length() &amp;&amp; str1[i] == str3[k]) i++;&#10;        else if(j &lt; str2.length() &amp;&amp; str2[j] == str3[k]) j++;&#10;        else return false;&#10;        k++;&#10;    }&#10;    return (i == str1.length() &amp;&amp; j == str2.length());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Str 12 Count And Say<br><br></b> <a href="https://leetcode.com/problems/count-and-say/" target="_blank">LeetCode 38</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive generation.</td>
      <td><b>Time:</b> O(N * L) where L is max length of string<br><b>Space:</b> O(L)</td>
      <td>Start with `res = '1'`. For `n-1` times, iterate through `res` and count consecutive identical characters. Append the count and the character to a new string. Replace `res` with the new string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string countAndSay(int n) {&#10;    if(n == 1) return &quot;1&quot;;&#10;    string s = &quot;1&quot;;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        string temp = &quot;&quot;;&#10;        int count = 1;&#10;        for(int j = 1; j &lt; s.length(); j++) {&#10;            if(s[j] == s[j - 1]) count++;&#10;            else {&#10;                temp += to_string(count) + s[j - 1];&#10;                count = 1;&#10;            }&#10;        }&#10;        temp += to_string(count) + s.back();&#10;        s = temp;&#10;    }&#10;    return s;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Str 13 Longest Palindrome In A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Expand around center.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>For each character, treat it as the center of an odd-length palindrome and expand outwards. Also treat it and the next character as the center of an even-length palindrome and expand outwards. Keep track of the longest palindrome found.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string longestPalindrome(string S){&#10;    int start = 0, maxLen = 1, n = S.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int l = i, r = i;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;        l = i; r = i + 1;&#10;        while(l &gt;= 0 &amp;&amp; r &lt; n &amp;&amp; S[l] == S[r]) {&#10;            if(r - l + 1 &gt; maxLen) { start = l; maxLen = r - l + 1; }&#10;            l--; r++;&#10;        }&#10;    }&#10;    return S.substr(start, maxLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Str 14 Find Longest Recurring Subsequence In String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Modified LCS.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2) or O(N)</td>
      <td>This is a variation of Longest Common Subsequence (LCS). Find LCS of `str` with itself, but with the restriction that when characters match, their indices must not be the same (`i != j`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestRepeatingSubsequence(string str) {&#10;    int n = str.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(str[i-1] == str[j-1] &amp;&amp; i != j) {&#10;                dp[i][j] = 1 + dp[i-1][j-1];&#10;            } else {&#10;                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);&#10;            }&#10;        }&#10;    }&#10;    return dp[n][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Str 15 Print All Subsequences Of A String<br><br></b> <a href="https://www.geeksforgeeks.org/print-subsequences-string/" target="_blank">Article</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive choice (include/exclude).</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N) recursion stack</td>
      <td>Use recursion. At each character, you have two choices: either include it in the current subsequence or exclude it. When you reach the end of the string, print/store the formed subsequence.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string s, string curr, int i, vector&lt;string&gt;&amp; res) {&#10;    if(i == s.length()) {&#10;        if(curr != &quot;&quot;) res.push_back(curr);&#10;        return;&#10;    }&#10;    solve(s, curr, i + 1, res);&#10;    solve(s, curr + s[i], i + 1, res);&#10;}&#10;vector&lt;string&gt; allSubsequences(string s) {&#10;    vector&lt;string&gt; res;&#10;    solve(s, &quot;&quot;, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Str 16 Split The Binary String Into Substrings With Equal Number Of 0S And 1S<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Counter logic.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the string, maintain a count that increments for '0' and decrements for '1' (or vice versa). Whenever the count becomes 0, it means we have found a balanced substring, so increment the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubStr(string str) {&#10;    int count0 = 0, count1 = 0, ans = 0;&#10;    for(char c : str) {&#10;        if(c == &#x27;0&#x27;) count0++;&#10;        else count1++;&#10;        if(count0 == count1) ans++;&#10;    }&#10;    if(count0 != count1) return -1;&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Str 17 Word Wrap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/word-wrap1646/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP approach.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Use Dynamic Programming. `dp[i]` represents the minimum cost to wrap words from index `i` to the end. Iterate backward and try placing different numbers of words on the current line.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solveWordWrap(vector&lt;int&gt;nums, int k) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; dp(n, 0);&#10;    dp[n - 1] = 0;&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        int currlen = -1;&#10;        dp[i] = INT_MAX;&#10;        for(int j = i; j &lt; n; j++) {&#10;            currlen += (nums[j] + 1);&#10;            if(currlen &gt; k) break;&#10;            if(j == n - 1) dp[i] = 0;&#10;            else {&#10;                int cost = (k - currlen) * (k - currlen) + dp[j + 1];&#10;                dp[i] = min(dp[i], cost);&#10;            }&#10;        }&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Str 18 Edit Distance<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/edit-distance3702/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP Table.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>Create a 2D DP array. If characters match, `dp[i][j] = dp[i-1][j-1]`. If not, `dp[i][j] = 1 + min(replace, insert, delete)`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int editDistance(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 0; i &lt;= n; i++) dp[i][0] = i;&#10;    for(int j = 0; j &lt;= m; j++) dp[0][j] = j;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];&#10;            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Str 19 Next Permutation<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/next-permutation5226/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Swap and Reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse from right to find the first element smaller than the element to its right. Then, find the smallest element to its right that is greater than it. Swap them, and reverse the subarray after the first element's index.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; nextPermutation(int N, vector&lt;int&gt; arr){&#10;    int i = N - 2;&#10;    while(i &gt;= 0 &amp;&amp; arr[i] &gt;= arr[i + 1]) i--;&#10;    if(i &gt;= 0) {&#10;        int j = N - 1;&#10;        while(arr[j] &lt;= arr[i]) j--;&#10;        swap(arr[i], arr[j]);&#10;    }&#10;    reverse(arr.begin() + i + 1, arr.end());&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Str 20 Parenthesis Checker<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a stack to keep track of opening brackets. If a closing bracket is encountered, check if it matches the top of the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool ispar(string x) {&#10;    stack&lt;char&gt; s;&#10;    for(char c : x) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) s.push(c);&#10;        else {&#10;            if(s.empty()) return false;&#10;            if(c == &#x27;)&#x27; &amp;&amp; s.top() != &#x27;(&#x27;) return false;&#10;            if(c == &#x27;}&#x27; &amp;&amp; s.top() != &#x27;{&#x27;) return false;&#10;            if(c == &#x27;]&#x27; &amp;&amp; s.top() != &#x27;[&#x27;) return false;&#10;            s.pop();&#10;        }&#10;    }&#10;    return s.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Str 21 Word Break<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/word-break1352/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Use `dp[i]` to indicate if `A[0..i]` can be segmented. For each `i`, check all prefixes `A[0..j]`. If `dp[j]` is true and `A[j..i]` is in the dictionary, then `dp[i]` is true.<br><br><b>Dependencies:</b> DP, Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int wordBreak(string A, vector&lt;string&gt; &amp;B) {&#10;    unordered_set&lt;string&gt; dict(B.begin(), B.end());&#10;    int n = A.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(dp[j] &amp;&amp; dict.find(A.substr(j, i - j)) != dict.end()) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n] ? 1 : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Str 22 Rabin Karp Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Rolling Hash.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Compute the hash for the pattern and for the first window of text. Slide the window by removing the leading character's hash and adding the trailing character's hash. If hashes match, check the characters one by one.</td>
      <td><b>Edge Cases:</b> Collisions in Hash<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; search(string pat, string txt) {&#10;    int d = 256, q = 101;&#10;    int M = pat.length(), N = txt.length();&#10;    int i, j, p = 0, t = 0, h = 1;&#10;    vector&lt;int&gt; res;&#10;    for (i = 0; i &lt; M - 1; i++) h = (h * d) % q;&#10;    for (i = 0; i &lt; M; i++) {&#10;        p = (d * p + pat[i]) % q;&#10;        t = (d * t + txt[i]) % q;&#10;    }&#10;    for (i = 0; i &lt;= N - M; i++) {&#10;        if (p == t) {&#10;            for (j = 0; j &lt; M; j++) {&#10;                if (txt[i + j] != pat[j]) break;&#10;            }&#10;            if (j == M) res.push_back(i + 1);&#10;        }&#10;        if (i &lt; N - M) {&#10;            t = (d * (t - txt[i] * h) + txt[i + M]) % q;&#10;            if (t &lt; 0) t = (t + q);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Str 23 Kmp Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/search-pattern0205/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> LPS Array.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(M)</td>
      <td>Construct an LPS (Longest Proper Prefix which is also Suffix) array for the pattern. Use it to skip unnecessary comparisons while traversing the text.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void computeLPS(string pat, int M, int* lps) {&#10;    int len = 0, i = 1;&#10;    lps[0] = 0;&#10;    while(i &lt; M) {&#10;        if(pat[i] == pat[len]) {&#10;            len++; lps[i] = len; i++;&#10;        } else {&#10;            if(len != 0) len = lps[len - 1];&#10;            else { lps[i] = 0; i++; }&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; search(string pat, string txt) {&#10;    int M = pat.length(), N = txt.length();&#10;    int lps[M];&#10;    computeLPS(pat, M, lps);&#10;    int i = 0, j = 0;&#10;    vector&lt;int&gt; res;&#10;    while((N - i) &gt;= (M - j)) {&#10;        if(pat[j] == txt[i]) { j++; i++; }&#10;        if(j == M) {&#10;            res.push_back(i - j + 1);&#10;            j = lps[j - 1];&#10;        } else if(i &lt; N &amp;&amp; pat[j] != txt[i]) {&#10;            if(j != 0) j = lps[j - 1];&#10;            else i++;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Str 24 Convert A Sentence Into Its Equivalent Mobile Numeric Keypad Sequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Dictionary Mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Store the sequence for every character in an array from A to Z, and for space. For each character in the input string, append its corresponding sequence to the result.</td>
      <td><b>Edge Cases:</b> Spaces<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string printSequence(string S) {&#10;    string str[] = {&quot;2&quot;, &quot;22&quot;, &quot;222&quot;, &quot;3&quot;, &quot;33&quot;, &quot;333&quot;, &quot;4&quot;, &quot;44&quot;, &quot;444&quot;, &quot;5&quot;, &quot;55&quot;, &quot;555&quot;, &quot;6&quot;, &quot;66&quot;, &quot;666&quot;, &quot;7&quot;, &quot;77&quot;, &quot;777&quot;, &quot;7777&quot;, &quot;8&quot;, &quot;88&quot;, &quot;888&quot;, &quot;9&quot;, &quot;99&quot;, &quot;999&quot;, &quot;9999&quot;};&#10;    string output = &quot;&quot;;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27; &#x27;) output += &quot;0&quot;;&#10;        else output += str[S[i] - &#x27;A&#x27;];&#10;    }&#10;    return output;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Str 25 Count The Reversals<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Remove all balanced brackets using a stack. The remaining string will be of the form `}}...{{...`. The required reversals will be `ceil(open_count/2) + ceil(close_count/2)`.<br><br><b>Dependencies:</b> Stack</td>
      <td><b>Edge Cases:</b> Odd length string<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countRev(string s) {&#10;    if(s.length() % 2 != 0) return -1;&#10;    stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;{&#x27;) st.push(c);&#10;        else {&#10;            if(!st.empty() &amp;&amp; st.top() == &#x27;{&#x27;) st.pop();&#10;            else st.push(c);&#10;        }&#10;    }&#10;    int open = 0, close = 0;&#10;    while(!st.empty()) {&#10;        if(st.top() == &#x27;{&#x27;) open++;&#10;        else close++;&#10;        st.pop();&#10;    }&#10;    return ceil(open / 2.0) + ceil(close / 2.0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Str 26 Count Palindromic Subsequences<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Dynamic Programming.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Use DP. `dp[i][j]` stores the count of palindromic subsequences in `str[i..j]`. If `str[i] == str[j]`, `dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1`. Else, `dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int countPS(string str) {&#10;    long long int MOD = 1e9 + 7;&#10;    int n = str.length();&#10;    vector&lt;vector&lt;long long int&gt;&gt; dp(n, vector&lt;long long int&gt;(n, 0));&#10;    for(int i = 0; i &lt; n; i++) dp[i][i] = 1;&#10;    for(int len = 2; len &lt;= n; len++) {&#10;        for(int i = 0; i &lt;= n - len; i++) {&#10;            int j = i + len - 1;&#10;            if(str[i] == str[j]) dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD;&#10;            else dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD;&#10;        }&#10;    }&#10;    return dp[0][n - 1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Str 27 Count Of Number Of Given String In 2D Character Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(R * C * 4^L)<br><b>Space:</b> O(L)</td>
      <td>Use DFS. For each cell, if it matches the first character of the word, start a DFS to look for the rest of the word in all 4 directions. Keep track of visited cells.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int dfs(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string&amp; target, int r, int c, int idx) {&#10;    if(idx == target.length()) return 1;&#10;    if(r &lt; 0 || r &gt;= mat.size() || c &lt; 0 || c &gt;= mat[0].size() || mat[r][c] != target[idx]) return 0;&#10;    char temp = mat[r][c];&#10;    mat[r][c] = &#x27;#&#x27;;&#10;    int found = dfs(mat, target, r + 1, c, idx + 1) +&#10;                dfs(mat, target, r - 1, c, idx + 1) +&#10;                dfs(mat, target, r, c + 1, idx + 1) +&#10;                dfs(mat, target, r, c - 1, idx + 1);&#10;    mat[r][c] = temp;&#10;    return found;&#10;}&#10;int findOccurrence(vector&lt;vector&lt;char&gt;&gt;&amp; mat, string target) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; mat.size(); i++) {&#10;        for(int j = 0; j &lt; mat[0].size(); j++) {&#10;            if(mat[i][j] == target[0]) {&#10;                count += dfs(mat, target, i, j, 0);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Str 28 Search A Word In A 2D Grid Of Characters<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 8 Directions Loop.</td>
      <td><b>Time:</b> O(N * M * 8 * L)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the grid. For each matching starting character, check all 8 directions to see if the full word exists in a straight line.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; searchWord(vector&lt;vector&lt;char&gt;&gt; grid, string word){&#10;    int R = grid.size(), C = grid[0].size(), L = word.length();&#10;    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};&#10;    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(int r = 0; r &lt; R; r++) {&#10;        for(int c = 0; c &lt; C; c++) {&#10;            if(grid[r][c] == word[0]) {&#10;                for(int dir = 0; dir &lt; 8; dir++) {&#10;                    int k, currR = r + dr[dir], currC = c + dc[dir];&#10;                    for(k = 1; k &lt; L; k++) {&#10;                        if(currR &lt; 0 || currR &gt;= R || currC &lt; 0 || currC &gt;= C) break;&#10;                        if(grid[currR][currC] != word[k]) break;&#10;                        currR += dr[dir]; currC += dc[dir];&#10;                    }&#10;                    if(k == L) {&#10;                        ans.push_back({r, c});&#10;                        break;&#10;                    }&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Str 29 Boyer Moore Algorithm For Pattern Searching<br><br></b> <a href="https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Bad Character Heuristic.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(256)</td>
      <td>Create a Bad Character table for the pattern, which stores the last occurrence of each character. Align pattern with text. Compare from right to left. If mismatch, shift the pattern so that the mismatched character in text aligns with its last occurrence in the pattern. If not present, shift pattern past it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void search(string txt, string pat) {&#10;    int m = pat.length(), n = txt.length();&#10;    int badChar[256];&#10;    for(int i = 0; i &lt; 256; i++) badChar[i] = -1;&#10;    for(int i = 0; i &lt; m; i++) badChar[(int)pat[i]] = i;&#10;    int s = 0;&#10;    while(s &lt;= (n - m)) {&#10;        int j = m - 1;&#10;        while(j &gt;= 0 &amp;&amp; pat[j] == txt[s + j]) j--;&#10;        if(j &lt; 0) {&#10;            cout &lt;&lt; &quot;Pattern occurs at shift = &quot; &lt;&lt; s &lt;&lt; endl;&#10;            s += (s + m &lt; n) ? m - badChar[txt[s + m]] : 1;&#10;        } else {&#10;            s += max(1, j - badChar[txt[s + j]]);&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Str 30 Roman Number To Integer<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Value mapping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Map each Roman numeral to its integer value. Iterate from right to left. If a character is smaller than its right character, subtract its value, else add it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int romanToDecimal(string &amp;str) {&#10;    unordered_map&lt;char, int&gt; m = {{&#x27;I&#x27;, 1}, {&#x27;V&#x27;, 5}, {&#x27;X&#x27;, 10}, {&#x27;L&#x27;, 50}, {&#x27;C&#x27;, 100}, {&#x27;D&#x27;, 500}, {&#x27;M&#x27;, 1000}};&#10;    int ans = 0, n = str.length();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i + 1 &lt; n &amp;&amp; m[str[i]] &lt; m[str[i+1]]) ans -= m[str[i]];&#10;        else ans += m[str[i]];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Str 31 Number Of Flips To Make Binary String Alternate<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two target strings.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>There are only two possible alternating strings for length N: starting with '0' (`010101...`) and starting with '1' (`101010...`). Count the differences between the given string and both of these. The minimum count is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFlips(string S) {&#10;    int count1 = 0, count2 = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(i % 2 == 0) {&#10;            if(S[i] != &#x27;0&#x27;) count1++;&#10;            if(S[i] != &#x27;1&#x27;) count2++;&#10;        } else {&#10;            if(S[i] != &#x27;1&#x27;) count1++;&#10;            if(S[i] != &#x27;0&#x27;) count2++;&#10;        }&#10;    }&#10;    return min(count1, count2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Str 32 Find The First Repeated Word In String<br><br></b> <a href="https://www.geeksforgeeks.org/find-first-repeated-word-string/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Split the string into words. Iterate through the words. If a word is already in the hash set, it is the first repeated word. Return it. Else, add it to the hash set.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string firstRepeatedWord(string s) {&#10;    unordered_set&lt;string&gt; st;&#10;    string word = &quot;&quot;;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(s[i] == &#x27; &#x27; || s[i] == &#x27;\t&#x27; || s[i] == &#x27;,&#x27; || s[i] == &#x27;:&#x27; || s[i] == &#x27;.&#x27; || s[i] == &#x27;-&#x27;) {&#10;            if(word != &quot;&quot;) {&#10;                if(st.find(word) != st.end()) return word;&#10;                st.insert(word);&#10;                word = &quot;&quot;;&#10;            }&#10;        } else word += s[i];&#10;    }&#10;    if(word != &quot;&quot; &amp;&amp; st.find(word) != st.end()) return word;&#10;    return &quot;No Repetition&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Str 33 Minimum Swaps For Bracket Balancing<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Track balance.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Keep track of the number of opening and closing brackets, and an `imbalance` counter. When encountering `[`, decrease imbalance. When encountering `]`, increase imbalance. The number of swaps is updated when an imbalance is found and we find the next `[`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumNumberOfSwaps(string S){&#10;    int open = 0, close = 0, fault = 0, ans = 0;&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(S[i] == &#x27;]&#x27;) {&#10;            close++;&#10;            fault = close - open;&#10;        } else {&#10;            open++;&#10;            if(fault &gt; 0) {&#10;                ans += fault;&#10;                fault--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Str 34 Isomorphic Strings<br><br></b> <a href="https://leetcode.com/problems/isomorphic-strings/" target="_blank">LeetCode 205</a></td>
      <td rowspan="1"><b>Example 1:</b> Hash Maps.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two arrays to map characters from `s` to `t` and `t` to `s`. If `s[i]` is mapped to a character other than `t[i]`, or `t[i]` is mapped to a character other than `s[i]`, return false. Else, create the mappings.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isIsomorphic(string s, string t) {&#10;    vector&lt;int&gt; m1(256, -1), m2(256, -1);&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(m1[s[i]] != m2[t[i]]) return false;&#10;        m1[s[i]] = i;&#10;        m2[t[i]] = i;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Str 35 Reverse Words In A String<br><br></b> <a href="https://leetcode.com/problems/reverse-words-in-a-string/" target="_blank">LeetCode 151</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output string</td>
      <td>Iterate from right to left. Find the end of a word, then the start of a word. Extract the word and append it to the result string along with a space. Finally, remove the trailing space.</td>
      <td><b>Edge Cases:</b> Multiple spaces between words<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string reverseWords(string s) {&#10;    string result = &quot;&quot;;&#10;    int i = s.length() - 1;&#10;    while(i &gt;= 0) {&#10;        while(i &gt;= 0 &amp;&amp; s[i] == &#x27; &#x27;) i--;&#10;        if(i &lt; 0) break;&#10;        int j = i;&#10;        while(i &gt;= 0 &amp;&amp; s[i] != &#x27; &#x27;) i--;&#10;        result += s.substr(i + 1, j - i) + &quot; &quot;;&#10;    }&#10;    if(!result.empty()) result.pop_back();&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Str 36 Rotate String<br><br></b> <a href="https://leetcode.com/problems/rotate-string/" target="_blank">LeetCode 796</a></td>
      <td rowspan="1"><b>Example 1:</b> String Concatenation.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If the lengths of `s` and `goal` are not equal, return false. Otherwise, concatenate `s` with itself (`s + s`). If `goal` is a substring of `s + s`, then it's a rotated string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool rotateString(string s, string goal) {&#10;    if(s.length() != goal.length()) return false;&#10;    string doubleS = s + s;&#10;    return doubleS.find(goal) != string::npos;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Str 37 Largest Odd Number In String<br><br></b> <a href="https://leetcode.com/problems/largest-odd-number-in-string/" target="_blank">LeetCode 1903</a></td>
      <td rowspan="1"><b>Example 1:</b> Iterate from right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) excluding output</td>
      <td>Iterate from the end of the string. The first odd digit found marks the end of the largest odd integer (since picking all digits from index 0 to this odd digit yields the largest value). Return the substring `num[0..i]`. If no odd digit is found, return empty string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string largestOddNumber(string num) {&#10;    for(int i = num.length() - 1; i &gt;= 0; i--) {&#10;        if((num[i] - &#x27;0&#x27;) % 2 != 0) return num.substr(0, i + 1);&#10;    }&#10;    return &quot;&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Str 38 Maximum Nesting Depth Of The Parentheses<br><br></b> <a href="https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/" target="_blank">LeetCode 1614</a></td>
      <td rowspan="1"><b>Example 1:</b> Counter tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the string. Maintain a `current_depth` counter. If we see `(`, increment the counter and update `max_depth`. If we see `)`, decrement the counter. Ignore other characters.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(string s) {&#10;    int maxD = 0, curD = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) {&#10;            curD++;&#10;            maxD = max(maxD, curD);&#10;        } else if(c == &#x27;)&#x27;) {&#10;            curD--;&#10;        }&#10;    }&#10;    return maxD;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Str 39 String To Integer Atoi<br><br></b> <a href="https://leetcode.com/problems/string-to-integer-atoi/" target="_blank">LeetCode 8</a></td>
      <td rowspan="1"><b>Example 1:</b> Step-by-step parsing.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>1. Ignore leading whitespaces. 2. Check for optional '+' or '-'. 3. Read digits until a non-digit or end of string. 4. Build the integer, checking for 32-bit integer overflow/underflow at each step.</td>
      <td><b>Edge Cases:</b> Overflow/Underflow<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int myAtoi(string s) {&#10;    int i = 0, n = s.length(), sign = 1;&#10;    long long ans = 0;&#10;    while(i &lt; n &amp;&amp; s[i] == &#x27; &#x27;) i++;&#10;    if(i &lt; n &amp;&amp; (s[i] == &#x27;+&#x27; || s[i] == &#x27;-&#x27;)) {&#10;        sign = (s[i] == &#x27;-&#x27;) ? -1 : 1;&#10;        i++;&#10;    }&#10;    while(i &lt; n &amp;&amp; isdigit(s[i])) {&#10;        ans = ans * 10 + (s[i] - &#x27;0&#x27;);&#10;        if(sign == 1 &amp;&amp; ans &gt; INT_MAX) return INT_MAX;&#10;        if(sign == -1 &amp;&amp; -ans &lt; INT_MIN) return INT_MIN;&#10;        i++;&#10;    }&#10;    return sign * ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Sliding Window

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
      <td rowspan="1">Sw 01 Longest Substring Without Repeating Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/" target="_blank">LeetCode 3</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "abcabcbb"<br><b>Output:</b> 3 ("abc")</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(min(N, M))</td>
      <td>Sliding window with a Hash Map storing the latest index of each character. Move `left` pointer to `max(left, map[char] + 1)`.<br><br><b>Dependencies:</b> <code>std::vector</code> for frequency array</td>
      <td><b>Edge Cases:</b> <b>Pointer Leap:</b> `left` can only jump forward, thus `std::max(left, ...)` prevents `left` from going backward if an old duplicate is found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstring(std::string s) {&#10;    std::vector&lt;int&gt; mpp(256, -1);&#10;    int left = 0, right = 0, max_len = 0;&#10;    while(right &lt; s.length()) {&#10;        if(mpp[s[right]] != -1) {&#10;            left = std::max(left, mpp[s[right]] + 1);&#10;        }&#10;        mpp[s[right]] = right;&#10;        max_len = std::max(max_len, right - left + 1);&#10;        right++;&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sw 02 Trapping Rain Water<br><br></b> <a href="https://leetcode.com/problems/trapping-rain-water/" target="_blank">LeetCode 42</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> height = [0,1,0,2,1,0,1,3,2,1,2,1]<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Two pointers `left` and `right`. Maintain `left_max` and `right_max`. Move the pointer pointing to the smaller max, adding trapped water.</td>
      <td><b>Edge Cases:</b> <b>Local Maxima:</b> Water trapped at `i` relies on the absolute minimum of the highest bars to its left and right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trap(std::vector&lt;int&gt;&amp; height) {&#10;    int n = height.size();&#10;    int left = 0, right = n - 1;&#10;    int res = 0, maxLeft = 0, maxRight = 0;&#10;    while (left &lt;= right) {&#10;        if (height[left] &lt;= height[right]) {&#10;            if (height[left] &gt;= maxLeft) maxLeft = height[left];&#10;            else res += maxLeft - height[left];&#10;            left++;&#10;        } else {&#10;            if (height[right] &gt;= maxRight) maxRight = height[right];&#10;            else res += maxRight - height[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sw 03 Container With Most Water<br><br></b> <a href="https://leetcode.com/problems/container-with-most-water/" target="_blank">LeetCode 11</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> height = [1,8,6,2,5,4,8,3,7]<br><b>Output:</b> 49</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Two Pointers from ends. Area is `min(h[left], h[right]) * width`. Move the pointer with the smaller height to seek a potentially taller line.<br><br><b>Dependencies:</b> <code>std::max</code>, <code>std::min</code></td>
      <td><b>Edge Cases:</b> <b>Width vs Height Tradeoff:</b> By starting at maximum width, we only decrease width. Thus, we must only abandon a height if we hope to find a taller one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxArea(std::vector&lt;int&gt;&amp; height) {&#10;    int left = 0, right = height.size() - 1;&#10;    int max_area = 0;&#10;    while(left &lt; right) {&#10;        int area = std::min(height[left], height[right]) * (right - left);&#10;        max_area = std::max(max_area, area);&#10;        if(height[left] &lt; height[right]) left++;&#10;        else right--;&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sw 04 Count Occurrences Of Anagrams<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Fixed window and frequency map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26) = O(1)</td>
      <td>Maintain a frequency map of the pattern. Use a sliding window of size equal to the length of the pattern. Keep track of the number of characters fully matched (`count`). If `count` equals the number of unique characters in the pattern, an anagram is found.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(string pat, string txt) {&#10;    int k = pat.length(), n = txt.length();&#10;    if(k &gt; n) return 0;&#10;    vector&lt;int&gt; count(26, 0);&#10;    for(char c : pat) count[c - &#x27;a&#x27;]++;&#10;    int i = 0, j = 0, ans = 0;&#10;    int distinct = 0;&#10;    for(int x : count) if(x &gt; 0) distinct++;&#10;    while(j &lt; n) {&#10;        count[txt[j] - &#x27;a&#x27;]--;&#10;        if(count[txt[j] - &#x27;a&#x27;] == 0) distinct--;&#10;        if(j - i + 1 &lt; k) j++;&#10;        else if(j - i + 1 == k) {&#10;            if(distinct == 0) ans++;&#10;            count[txt[i] - &#x27;a&#x27;]++;&#10;            if(count[txt[i] - &#x27;a&#x27;] == 1) distinct++;&#10;            i++; j++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sw 05 Maximum Of All Subarrays Of Size K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Use a deque to store indices of elements. The deque will maintain elements in decreasing order. For each element, remove elements from the back of the deque that are smaller than the current element. Also, remove elements from the front that are out of the current window. The front of the deque will always have the maximum element of the current window.<br><br><b>Dependencies:</b> <code>#include <deque></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector &lt;int&gt; max_of_subarrays(int *arr, int n, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; arr[dq.back()] &lt;= arr[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(arr[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sw 06 Minimum Window Substring<br><br></b> <a href="https://leetcode.com/problems/minimum-window-substring/" target="_blank">LeetCode 76</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable sliding window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain a frequency map of `t`. Expand the window by moving `right`. When the window contains all characters of `t`, try to shrink it by moving `left` to find the minimum window. Keep track of the minimum window length and its starting index.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string minWindow(string s, string t) {&#10;    if(s.length() &lt; t.length()) return &quot;&quot;;&#10;    vector&lt;int&gt; count(128, 0);&#10;    for(char c : t) count[c]++;&#10;    int l = 0, r = 0, minLen = INT_MAX, minStart = 0, required = t.length();&#10;    while(r &lt; s.length()) {&#10;        if(count[s[r]] &gt; 0) required--;&#10;        count[s[r]]--;&#10;        r++;&#10;        while(required == 0) {&#10;            if(r - l &lt; minLen) {&#10;                minLen = r - l;&#10;                minStart = l;&#10;            }&#10;            count[s[l]]++;&#10;            if(count[s[l]] &gt; 0) required++;&#10;            l++;&#10;        }&#10;    }&#10;    return minLen == INT_MAX ? &quot;&quot; : s.substr(minStart, minLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Sw 07 Sliding Window Maximum<br><br></b> <a href="https://leetcode.com/problems/sliding-window-maximum/" target="_blank">LeetCode 239</a></td>
      <td rowspan="1"><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Use a deque to store indices. The deque maintains elements in decreasing order. Remove elements from the back if they are smaller than the current element. Remove elements from the front if they are out of the window. The front element is the maximum of the current window.<br><br><b>Dependencies:</b> <code>#include <deque></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(nums[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Sw 08 Longest K Unique Characters Substring<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable window and hash map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Maintain a hash map of character frequencies. Expand the window by moving `j`. If the number of unique characters exceeds `k`, shrink the window from the left (`i`) until the number of unique characters is `k`. Update the maximum length when exactly `k` unique characters are present.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestKSubstr(string s, int k) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    int i = 0, j = 0, maxLen = -1;&#10;    while(j &lt; s.length()) {&#10;        count[s[j]]++;&#10;        if(count.size() == k) maxLen = max(maxLen, j - i + 1);&#10;        else if(count.size() &gt; k) {&#10;            while(count.size() &gt; k) {&#10;                count[s[i]]--;&#10;                if(count[s[i]] == 0) count.erase(s[i]);&#10;                i++;&#10;            }&#10;        }&#10;        j++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Sw 09 Subarrays With K Different Integers<br><br></b> <a href="https://leetcode.com/problems/subarrays-with-k-different-integers/" target="_blank">LeetCode 992</a></td>
      <td rowspan="1"><b>Example 1:</b> Exact K = atMost(K) - atMost(K-1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Finding exact `k` distinct is hard directly. Instead, find subarrays with at most `k` distinct integers. The number of exact `k` is `atMost(k) - atMost(k - 1)`. The `atMost` function uses a sliding window.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int res = 0, i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(count[nums[j]] == 0) k--;&#10;        count[nums[j]]++;&#10;        while(k &lt; 0) {&#10;            count[nums[i]]--;&#10;            if(count[nums[i]] == 0) k++;&#10;            i++;&#10;        }&#10;        res += j - i + 1;&#10;    }&#10;    return res;&#10;}&#10;int subarraysWithKDistinct(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Sw 10 Minimum Size Subarray Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-size-subarray-sum/" target="_blank">LeetCode 209</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable sliding window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Add elements to the current sum. While the sum is >= target, update the minimum length and shrink the window from the left.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minSubArrayLen(int target, vector&lt;int&gt;&amp; nums) {&#10;    int l = 0, sum = 0, minLen = INT_MAX;&#10;    for(int r = 0; r &lt; nums.size(); r++) {&#10;        sum += nums[r];&#10;        while(sum &gt;= target) {&#10;            minLen = min(minLen, r - l + 1);&#10;            sum -= nums[l++];&#10;        }&#10;    }&#10;    return minLen == INT_MAX ? 0 : minLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Sw 11 Fruits Into Baskets<br><br></b> <a href="https://leetcode.com/problems/fruit-into-baskets/" target="_blank">LeetCode 904</a></td>
      <td rowspan="1"><b>Example 1:</b> Longest subarray with at most 2 distinct elements.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (at most 3 elements in map)</td>
      <td>This translates to finding the longest subarray with at most 2 distinct elements. Maintain a frequency map and use a sliding window. If distinct elements > 2, shrink the window until distinct elements <= 2.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int totalFruit(vector&lt;int&gt;&amp; fruits) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int l = 0, maxFruits = 0;&#10;    for(int r = 0; r &lt; fruits.size(); r++) {&#10;        count[fruits[r]]++;&#10;        while(count.size() &gt; 2) {&#10;            count[fruits[l]]--;&#10;            if(count[fruits[l]] == 0) count.erase(fruits[l]);&#10;            l++;&#10;        }&#10;        maxFruits = max(maxFruits, r - l + 1);&#10;    }&#10;    return maxFruits;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Sw 12 Max Consecutive Ones III<br><br></b> <a href="https://leetcode.com/problems/max-consecutive-ones-iii/" target="_blank">LeetCode 1004</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Expand the right pointer. If the element is 0, increment a zero counter. While the zero counter > k, shrink the window from the left by moving the left pointer and decrementing the zero counter if left element is 0. The max window size is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestOnes(vector&lt;int&gt;&amp; nums, int k) {&#10;    int left = 0, right = 0, zeroes = 0, maxLen = 0;&#10;    while(right &lt; nums.size()) {&#10;        if(nums[right] == 0) zeroes++;&#10;        while(zeroes &gt; k) {&#10;            if(nums[left] == 0) zeroes--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Sw 13 Longest Repeating Character Replacement<br><br></b> <a href="https://leetcode.com/problems/longest-repeating-character-replacement/" target="_blank">LeetCode 424</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Max Freq.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Maintain the character frequencies and the `max_freq` in the window. The number of replacements needed is `window_size - max_freq`. If this is > k, shrink the window from left and decrement the corresponding frequency.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int characterReplacement(string s, int k) {&#10;    vector&lt;int&gt; count(26, 0);&#10;    int left = 0, maxFreq = 0, maxLen = 0;&#10;    for(int right = 0; right &lt; s.length(); right++) {&#10;        count[s[right] - &#x27;A&#x27;]++;&#10;        maxFreq = max(maxFreq, count[s[right] - &#x27;A&#x27;]);&#10;        if((right - left + 1) - maxFreq &gt; k) {&#10;            count[s[left] - &#x27;A&#x27;]--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Sw 14 Binary Subarrays With Sum<br><br></b> <a href="https://leetcode.com/problems/binary-subarrays-with-sum/" target="_blank">LeetCode 930</a></td>
      <td rowspan="1"><b>Example 1:</b> atMost(goal) - atMost(goal - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use the helper function `atMost(goal)` which finds the number of subarrays with sum <= goal. The answer is `atMost(goal) - atMost(goal - 1)`. In `atMost`, use a sliding window to maintain the sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int goal) {&#10;    if(goal &lt; 0) return 0;&#10;    int left = 0, sum = 0, count = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        sum += nums[right];&#10;        while(sum &gt; goal) {&#10;            sum -= nums[left++];&#10;        }&#10;        count += (right - left + 1);&#10;    }&#10;    return count;&#10;}&#10;int numSubarraysWithSum(vector&lt;int&gt;&amp; nums, int goal) {&#10;    return atMost(nums, goal) - atMost(nums, goal - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Sw 15 Count Number Of Nice Subarrays<br><br></b> <a href="https://leetcode.com/problems/count-number-of-nice-subarrays/" target="_blank">LeetCode 1248</a></td>
      <td rowspan="1"><b>Example 1:</b> atMost(k) - atMost(k - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Replace all odd numbers with 1 and even numbers with 0. The problem then reduces to finding the number of subarrays with a sum equal to k. Use the `atMost(k) - atMost(k - 1)` sliding window approach.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    if(k &lt; 0) return 0;&#10;    int left = 0, count = 0, res = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        if(nums[right] % 2 != 0) count++;&#10;        while(count &gt; k) {&#10;            if(nums[left] % 2 != 0) count--;&#10;            left++;&#10;        }&#10;        res += (right - left + 1);&#10;    }&#10;    return res;&#10;}&#10;int numberOfSubarrays(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Sw 16 Number Of Substrings Containing All Three Characters<br><br></b> <a href="https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/" target="_blank">LeetCode 1358</a></td>
      <td rowspan="1"><b>Example 1:</b> Store last seen indices.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the string. Track the last seen indices of 'a', 'b', and 'c'. If all three have been seen, the number of valid substrings ending at the current index `i` is `1 + min(last_a, last_b, last_c)`. Add this to the total count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfSubstrings(string s) {&#10;    int last[3] = {-1, -1, -1};&#10;    int count = 0;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        last[s[i] - &#x27;a&#x27;] = i;&#10;        if(last[0] != -1 &amp;&amp; last[1] != -1 &amp;&amp; last[2] != -1) {&#10;            count += (1 + min({last[0], last[1], last[2]}));&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Sw 17 Maximum Points You Can Obtain From Cards<br><br></b> <a href="https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/" target="_blank">LeetCode 1423</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window on remaining cards.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Instead of picking cards from the ends, find the subarray of length `N - K` that has the minimum sum. Subtract this minimum sum from the total sum of the array. That gives the maximum score.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxScore(vector&lt;int&gt;&amp; cardPoints, int k) {&#10;    int n = cardPoints.size();&#10;    int totalSum = 0, windowSum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        totalSum += cardPoints[i];&#10;        if(i &lt; n - k) windowSum += cardPoints[i];&#10;    }&#10;    int minWindowSum = windowSum;&#10;    for(int i = n - k; i &lt; n; i++) {&#10;        windowSum += cardPoints[i] - cardPoints[i - (n - k)];&#10;        minWindowSum = min(minWindowSum, windowSum);&#10;    }&#10;    return totalSum - minWindowSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Sw 18 Find All Anagrams In A String<br><br></b> <a href="https://leetcode.com/problems/find-all-anagrams-in-a-string/" target="_blank">LeetCode 438</a></td>
      <td rowspan="1"><b>Example 1:</b> Fixed Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Create frequency arrays for `p` and a window of size `p.length()` in `s`. Slide the window across `s`, updating the window frequencies. If the arrays match, add the window's start index to the result.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findAnagrams(string s, string p) {&#10;    vector&lt;int&gt; ans;&#10;    if(p.length() &gt; s.length()) return ans;&#10;    vector&lt;int&gt; countP(26, 0), countS(26, 0);&#10;    for(int i = 0; i &lt; p.length(); i++) {&#10;        countP[p[i] - &#x27;a&#x27;]++;&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;    }&#10;    if(countP == countS) ans.push_back(0);&#10;    for(int i = p.length(); i &lt; s.length(); i++) {&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;        countS[s[i - p.length()] - &#x27;a&#x27;]--;&#10;        if(countP == countS) ans.push_back(i - p.length() + 1);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Sw 19 Permutation In String<br><br></b> <a href="https://leetcode.com/problems/permutation-in-string/" target="_blank">LeetCode 567</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Frequency Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window of size `len(s1)` over `s2`. Maintain frequency arrays for `s1` and the current window in `s2`. Compare arrays at each step.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkInclusion(string s1, string s2) {&#10;    if(s1.length() &gt; s2.length()) return false;&#10;    vector&lt;int&gt; count1(26, 0), count2(26, 0);&#10;    for(int i = 0; i &lt; s1.length(); i++) {&#10;        count1[s1[i] - &#x27;a&#x27;]++;&#10;        count2[s2[i] - &#x27;a&#x27;]++;&#10;    }&#10;    if(count1 == count2) return true;&#10;    for(int i = s1.length(); i &lt; s2.length(); i++) {&#10;        count2[s2[i] - &#x27;a&#x27;]++;&#10;        count2[s2[i - s1.length()] - &#x27;a&#x27;]--;&#10;        if(count1 == count2) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Sw 20 First Negative Integer In Every Window Of Size K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Queue.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Maintain a queue of negative integers in the current window. While moving the window, add new negative integers, remove old ones out of window. The front of queue is the first negative.<br><br><b>Dependencies:</b> Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; printFirstNegativeInteger(long long int A[], long long int N, long long int K) {&#10;    vector&lt;long long&gt; ans;&#10;    queue&lt;long long&gt; q;&#10;    for(long long i = 0; i &lt; K - 1; i++) {&#10;        if(A[i] &lt; 0) q.push(A[i]);&#10;    }&#10;    for(long long i = K - 1; i &lt; N; i++) {&#10;        if(A[i] &lt; 0) q.push(A[i]);&#10;        if(!q.empty()) ans.push_back(q.front());&#10;        else ans.push_back(0);&#10;        if(A[i - K + 1] &lt; 0 &amp;&amp; !q.empty() &amp;&amp; q.front() == A[i - K + 1]) q.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Sw 21 Count Occurrences Of Anagrams<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams1536/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Frequency Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window of size `pat.length()`. Keep frequency map of `pat`. Track `count` of distinct characters to match. While moving window, decrease `count` if char frequency matches. If `count == 0`, increment answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(string pat, string txt) {&#10;    unordered_map&lt;char, int&gt; m;&#10;    for(char c : pat) m[c]++;&#10;    int count = m.size(), ans = 0, k = pat.length();&#10;    int i = 0, j = 0;&#10;    while(j &lt; txt.length()) {&#10;        if(m.find(txt[j]) != m.end()) {&#10;            m[txt[j]]--;&#10;            if(m[txt[j]] == 0) count--;&#10;        }&#10;        if(j - i + 1 &lt; k) j++;&#10;        else if(j - i + 1 == k) {&#10;            if(count == 0) ans++;&#10;            if(m.find(txt[i]) != m.end()) {&#10;                m[txt[i]]++;&#10;                if(m[txt[i]] == 1) count++;&#10;            }&#10;            i++; j++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Sw 22 Smallest Window In A String Containing All The Characters Of Another String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Same as Minimum Window Substring. Use frequency map of `P` and a sliding window over `S`. Shrink window from left when all characters match to find the minimum length.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string smallestWindow (string s, string p) {&#10;    if(p.length() &gt; s.length()) return &quot;-1&quot;;&#10;    unordered_map&lt;char, int&gt; m;&#10;    for(char c : p) m[c]++;&#10;    int count = m.size(), i = 0, j = 0, minLen = INT_MAX, start = 0;&#10;    while(j &lt; s.length()) {&#10;        if(m.find(s[j]) != m.end()) {&#10;            m[s[j]]--;&#10;            if(m[s[j]] == 0) count--;&#10;        }&#10;        while(count == 0) {&#10;            if(j - i + 1 &lt; minLen) {&#10;                minLen = j - i + 1;&#10;                start = i;&#10;            }&#10;            if(m.find(s[i]) != m.end()) {&#10;                m[s[i]]++;&#10;                if(m[s[i]] &gt; 0) count++;&#10;            }&#10;            i++;&#10;        }&#10;        j++;&#10;    }&#10;    if(minLen == INT_MAX) return &quot;-1&quot;;&#10;    return s.substr(start, minLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Sw 23 Longest Substring With At Most K Distinct Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/" target="_blank">LeetCode 340</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Sliding window with hash map to count characters. While map size > k, shrink window from left.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstringKDistinct(string s, int k) {&#10;    unordered_map&lt;char, int&gt; m;&#10;    int left = 0, right = 0, maxLen = 0;&#10;    while(right &lt; s.length()) {&#10;        m[s[right]]++;&#10;        while(m.size() &gt; k) {&#10;            m[s[left]]--;&#10;            if(m[s[left]] == 0) m.erase(s[left]);&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Sorting

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
      <td rowspan="1">Sort 01 Selection Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/selection-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9<br><br><b> </b> In-place sorting.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Find the minimum element in the unsorted array and swap it with the element at the beginning.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> Always `O(N^2)` even if the array is already sorted.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void selectionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt; n - 1; i++) {&#10;        int min_idx = i;&#10;        for (int j = i + 1; j &lt; n; j++) {&#10;            if (arr[j] &lt; arr[min_idx]) {&#10;                min_idx = j;&#10;            }&#10;        }&#10;        std::swap(arr[i], arr[min_idx]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sort 02 Bubble Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bubble-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>Repeatedly swap adjacent elements if they are in the wrong order. Push the maximum element to the end.</td>
      <td><b>Edge Cases:</b> <b>Best Case Check:</b> Adding `did_swap` flag makes Best Case time `O(N)` for already sorted arrays.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bubbleSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = n - 1; i &gt;= 1; i--) {&#10;        bool did_swap = false;&#10;        for (int j = 0; j &lt;= i - 1; j++) {&#10;            if (arr[j] &gt; arr[j + 1]) {&#10;                std::swap(arr[j], arr[j + 1]);&#10;                did_swap = true;&#10;            }&#10;        }&#10;        if (!did_swap) break;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sort 03 Insertion Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/insertion-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Takes an element and places it in its correct position within the previously sorted part of the array.</td>
      <td><b>Edge Cases:</b> <b>Online Algorithm:</b> Good for data coming in one by one. `O(N)` best case time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt;= n - 1; i++) {&#10;        int j = i;&#10;        while (j &gt; 0 &amp;&amp; arr[j - 1] &gt; arr[j]) {&#10;            std::swap(arr[j - 1], arr[j]);&#10;            j--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sort 04 Merge Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/merge-sort/1" target="_blank">GFG</a> | <a href="https://leetcode.com/problems/sort-an-array/" target="_blank">LC 912</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Recursively split array in half, sort them, and merge the sorted halves.<br><br><b>Dependencies:</b> Extra array for merging</td>
      <td><b>Edge Cases:</b> <b>Stable Sort:</b> Maintains relative order of equal elements. Requires `O(N)` extra space to merge.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;&#10;void mergeSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if (low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSortHelper(arr, low, mid);&#10;    mergeSortHelper(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}&#10;&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr) {&#10;    mergeSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sort 05 Quick Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/quick-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Pick a pivot. Place smaller elements left and larger right. Recursively sort partitions.</td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> `O(N^2)` if array is already sorted and pivot is extreme. Avoided by randomized pivot.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int partition(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int pivot = arr[low];&#10;    int i = low, j = high;&#10;    while(i &lt; j) {&#10;        while(arr[i] &lt;= pivot &amp;&amp; i &lt;= high - 1) i++;&#10;        while(arr[j] &gt; pivot &amp;&amp; j &gt;= low + 1) j--;&#10;        if(i &lt; j) std::swap(arr[i], arr[j]);&#10;    }&#10;    std::swap(arr[low], arr[j]);&#10;    return j;&#10;}&#10;&#10;void quickSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &lt; high) {&#10;        int pIndex = partition(arr, low, high);&#10;        quickSortHelper(arr, low, pIndex - 1);&#10;        quickSortHelper(arr, pIndex + 1, high);&#10;    }&#10;}&#10;&#10;void quickSort(std::vector&lt;int&gt;&amp; arr) {&#10;    quickSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Binary Search

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
      <td rowspan="1">Bs 01 Binary Search<br><br></b> <a href="https://leetcode.com/problems/binary-search/" target="_blank">LeetCode 704</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [-1,0,3,5,9,12], target = 9<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Standard Iterative approach. Maintain `low` and `high` boundaries, shrinking the search space by half.</td>
      <td><b>Edge Cases:</b> <b>Mid Overflow:</b> Use `mid = low + (high - low) / 2` to avoid integer overflow if boundaries are large.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        else if(nums[mid] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bs 02 Lower Bound<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> arr = [1,2,8,10,11,12,19], target = 0<br><b>Output:</b> 0</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: When `nums[mid] >= target`, it is a potential answer. Store it and search left (`high = mid - 1`) for smaller potentials.<br><br><b>Dependencies:</b> <code>std::lower_bound</code> internal alternative</td>
      <td><b>Edge Cases:</b> <b>Not Found:</b> If all elements are smaller, `ans` stays `N`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lowerBound(std::vector&lt;int&gt; arr, int n, int x) {&#10;    int low = 0, high = n - 1;&#10;    int ans = n;&#10;    while (low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if (arr[mid] &gt;= x) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Bs 03 Find First And Last Position Of Element<br><br></b> <a href="https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/" target="_blank">LeetCode 34</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [5,7,7,8,8,10], target = 8<br><b>Output:</b> [3,4]</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Run Binary Search twice. Once to find the first occurrence (bias left), once to find the last occurrence (bias right).</td>
      <td><b>Edge Cases:</b> <b>Empty Array:</b> Naturally skips loop and returns `[-1, -1]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findBound(std::vector&lt;int&gt;&amp; nums, int target, bool isFirst) {&#10;    int low = 0, high = nums.size() - 1, ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) {&#10;            ans = mid;&#10;            if(isFirst) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else if(nums[mid] &lt; target) {&#10;            low = mid + 1;&#10;        } else {&#10;            high = mid - 1;&#10;        }&#10;    }&#10;    return ans;&#10;}&#10;&#10;std::vector&lt;int&gt; searchRange(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    return {findBound(nums, target, true), findBound(nums, target, false)};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Bs 04 Search In Rotated Sorted Array<br><br></b> <a href="https://leetcode.com/problems/search-in-rotated-sorted-array/" target="_blank">LeetCode 33</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [4,5,6,7,0,1,2], target = 0<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(log N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Identify the sorted half. Check if target lies within the boundaries of the sorted half. If yes, shrink to that half; else, shrink to the other.</td>
      <td><b>Edge Cases:</b> <b>Duplicate Values:</b> If duplicates existed (which they don't in this specific leetcode), we would need to handle `nums[low] == nums[mid] == nums[high]` by shrinking bounds.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(nums[mid] == target) return mid;&#10;        &#10;        // Left half sorted&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } &#10;        // Right half sorted&#10;        else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Bs 05 Koko Eating Bananas<br><br></b> <a href="https://leetcode.com/problems/koko-eating-bananas/" target="_blank">LeetCode 875</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> piles = [3,6,7,11], h = 8<br><b>Output:</b> 4<br><br><b>Note (Constraint):</b> Binary Search on Answers.</td>
      <td><b>Time:</b> O(N log(Max(P))) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Search space is `1` to `max(piles)`. For a mid `k`, calculate hours required. If `hours <= h`, it's a valid answer, but search left for smaller `k`.<br><br><b>Dependencies:</b> <code>std::ceil</code> / ceiling math</td>
      <td><b>Edge Cases:</b> <b>Ceiling Math:</b> Use `(pile + mid - 1) / mid` to simulate ceiling division without float casting overhead.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canEat(std::vector&lt;int&gt;&amp; piles, int k, int h) {&#10;    long long hours = 0;&#10;    for(int pile : piles) {&#10;        hours += (pile + k - 1) / k;&#10;    }&#10;    return hours &lt;= h;&#10;}&#10;&#10;int minEatingSpeed(std::vector&lt;int&gt;&amp; piles, int h) {&#10;    int low = 1, high = *std::max_element(piles.begin(), piles.end());&#10;    int ans = high;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canEat(piles, mid, h)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Bs 06 Find Minimum In Rotated Sorted Array<br><br></b> <a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/" target="_blank">LeetCode 153</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [3,4,5,1,2]<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary Search. Compare mid with right pointer. If nums[mid] > nums[right], the min is in the right half. Else, the min is in the left half including mid.</td>
      <td><b>Edge Cases:</b> <b>Fully sorted array:</b> Loop naturally converges to the first element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMin(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &gt; nums[right]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return nums[left];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Bs 07 Find Peak Element<br><br></b> <a href="https://leetcode.com/problems/find-peak-element/" target="_blank">LeetCode 162</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary Search. If nums[mid] < nums[mid+1], we are on an ascending slope, so a peak must be to the right. Otherwise, we are on a descending slope, peak is to the left (including mid).</td>
      <td><b>Edge Cases:</b> <b>Peak at boundaries:</b> The binary search logic intrinsically handles edges by shrinking bounds away from negative slopes.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPeakElement(vector&lt;int&gt;&amp; nums) {&#10;    int left = 0, right = nums.size() - 1;&#10;    while(left &lt; right) {&#10;        int mid = left + (right - left) / 2;&#10;        if(nums[mid] &lt; nums[mid+1]) left = mid + 1;&#10;        else right = mid;&#10;    }&#10;    return left;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Bs 08 Allocate Minimum Number Of Pages<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N=4, A=[12,34,67,90], M=2<br><b>Output:</b> 113</td>
      <td><b>Time:</b> O(N * log(sum(A) - max(A)))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary Search on Answer. The search space for pages is from `max(A)` to `sum(A)`. For a given `mid`, check if books can be allocated to `<= M` students without any student exceeding `mid` pages.</td>
      <td><b>Edge Cases:</b> <b>M > N:</b> Impossible to allocate at least one book to each student, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(int A[], int N, int M, int maxPages) {&#10;    int students = 1, currentPages = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        if(A[i] &gt; maxPages) return false;&#10;        if(currentPages + A[i] &gt; maxPages) {&#10;            students++; currentPages = A[i];&#10;        } else {&#10;            currentPages += A[i];&#10;        }&#10;    }&#10;    return students &lt;= M;&#10;}&#10;int findPages(int A[], int N, int M) {&#10;    if(M &gt; N) return -1;&#10;    int low = 0, high = 0, ans = -1;&#10;    for(int i=0; i&lt;N; i++) { low = max(low, A[i]); high += A[i]; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(A, N, M, mid)) {&#10;            ans = mid; high = mid - 1;&#10;        } else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Bs 09 Kth Element Of Two Sorted Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 5<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(log(min(n, m)))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on the smaller array. Similar to Median of two sorted arrays, but the left partition size is strictly `k`. Search space for `cut1` is `[max(0, k-m), min(k, n)]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthElement(int arr1[], int arr2[], int n, int m, int k) {&#10;    if(n &gt; m) return kthElement(arr2, arr1, m, n, k);&#10;    int low = max(0, k - m), high = min(k, n);&#10;    while(low &lt;= high) {&#10;        int cut1 = (low + high) / 2;&#10;        int cut2 = k - cut1;&#10;        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1-1];&#10;        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2-1];&#10;        int right1 = cut1 == n ? INT_MAX : arr1[cut1];&#10;        int right2 = cut2 == m ? INT_MAX : arr2[cut2];&#10;        if(left1 &lt;= right2 &amp;&amp; left2 &lt;= right1) return max(left1, left2);&#10;        else if(left1 &gt; right2) high = cut1 - 1;&#10;        else low = cut1 + 1;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Bs 10 Search In Rotated Sorted Array II<br><br></b> <a href="https://leetcode.com/problems/search-in-rotated-sorted-array-ii/" target="_blank">LeetCode 81</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [2,5,6,0,0,1,2], target = 0<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log N) average, O(N) worst case<br><b>Space:</b> O(1)</td>
      <td>Optimal: If `nums[low] == nums[mid] == nums[high]`, shrink the search space by `low++` and `high--`. Otherwise, proceed with the standard rotated binary search.</td>
      <td><b>Edge Cases:</b> <b>Duplicates causing ambiguity:</b> Shrink bounds safely.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool search(vector&lt;int&gt;&amp; nums, int target) {&#10;    int low = 0, high = nums.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(nums[mid] == target) return true;&#10;        if(nums[low] == nums[mid] &amp;&amp; nums[mid] == nums[high]) {&#10;            low++; high--; continue;&#10;        }&#10;        if(nums[low] &lt;= nums[mid]) {&#10;            if(nums[low] &lt;= target &amp;&amp; target &lt;= nums[mid]) high = mid - 1;&#10;            else low = mid + 1;&#10;        } else {&#10;            if(nums[mid] &lt;= target &amp;&amp; target &lt;= nums[high]) low = mid + 1;&#10;            else high = mid - 1;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Bs 11 Minimum Days To Make M Bouquets<br><br></b> <a href="https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/" target="_blank">LeetCode 1482</a></td>
      <td rowspan="1"><b>Example 1:</b> Find day threshold.</td>
      <td><b>Time:</b> O(N log(maxD - minD))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on days from `min(bloom)` to `max(bloom)`. Count consecutive bloomed flowers, if it reaches `k`, form a bouquet. Return minimum valid day.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(vector&lt;int&gt;&amp; bloomDay, int m, int k, int day) {&#10;    int count = 0, bouquets = 0;&#10;    for(int d : bloomDay) {&#10;        if(d &lt;= day) count++;&#10;        else {&#10;            bouquets += count / k;&#10;            count = 0;&#10;        }&#10;    }&#10;    bouquets += count / k;&#10;    return bouquets &gt;= m;&#10;}&#10;int minDays(vector&lt;int&gt;&amp; bloomDay, int m, int k) {&#10;    if((long long)m * k &gt; bloomDay.size()) return -1;&#10;    int low = 1e9, high = 0;&#10;    for(int d : bloomDay) { low = min(low, d); high = max(high, d); }&#10;    int ans = -1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(bloomDay, m, k, mid)) { ans = mid; high = mid - 1; }&#10;        else low = mid + 1;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Bs 12 Find The Smallest Divisor Given A Threshold<br><br></b> <a href="https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/" target="_blank">LeetCode 1283</a></td>
      <td rowspan="1"><b>Example 1:</b> Summing ceils.</td>
      <td><b>Time:</b> O(N log(max(nums)))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search the divisor from 1 to `max(nums)`. Compute `sum(ceil(num / mid))`. If sum <= threshold, shrink high.<br><br><b>Dependencies:</b> <code>#include <math.h></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int smallestDivisor(vector&lt;int&gt;&amp; nums, int threshold) {&#10;    int low = 1, high = *max_element(nums.begin(), nums.end());&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        long long sum = 0;&#10;        for(int num : nums) sum += ceil((double)num / mid);&#10;        if(sum &lt;= threshold) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Bs 13 Capacity To Ship Packages Within D Days<br><br></b> <a href="https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/" target="_blank">LeetCode 1011</a></td>
      <td rowspan="1"><b>Example 1:</b> Find ship capacity.</td>
      <td><b>Time:</b> O(N log(sum - max))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on capacity. Low = `max(weights)`, High = `sum(weights)`. Iterate through packages and accumulate weight, increment day if limit is exceeded.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canShip(vector&lt;int&gt;&amp; weights, int days, int cap) {&#10;    int d = 1, load = 0;&#10;    for(int w : weights) {&#10;        if(load + w &gt; cap) { d++; load = w; }&#10;        else load += w;&#10;    }&#10;    return d &lt;= days;&#10;}&#10;int shipWithinDays(vector&lt;int&gt;&amp; weights, int days) {&#10;    int low = 0, high = 0;&#10;    for(int w : weights) { low = max(low, w); high += w; }&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canShip(weights, days, mid)) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Bs 14 Kth Missing Positive Number<br><br></b> <a href="https://leetcode.com/problems/kth-missing-positive-number/" target="_blank">LeetCode 1539</a></td>
      <td rowspan="1"><b>Example 1:</b> Calculate missing.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search. At index `mid`, the number of missing elements before `arr[mid]` is `arr[mid] - (mid + 1)`. If this is < `k`, search right `low = mid + 1`. Else search left `high = mid - 1`. Ans is `high + 1 + k` or `low + k`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthPositive(vector&lt;int&gt;&amp; arr, int k) {&#10;    int low = 0, high = arr.size() - 1;&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int missing = arr[mid] - (mid + 1);&#10;        if(missing &lt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low + k;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Bs 15 Aggressive Cows<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/aggressive-cows/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Minimax binary search.</td>
      <td><b>Time:</b> O(N log N + N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the stalls. Binary search for distance from `1` to `max-min`. For a distance `mid`, check if we can place all `C` cows such that distance between any two is >= `mid`. If possible, move `low = mid + 1` to maximize it, else `high = mid - 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canWePlace(vector&lt;int&gt;&amp; stalls, int dist, int cows) {&#10;    int n = stalls.size();&#10;    int cntCows = 1;&#10;    int last = stalls[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        if(stalls[i] - last &gt;= dist) {&#10;            cntCows++;&#10;            last = stalls[i];&#10;        }&#10;    }&#10;    return cntCows &gt;= cows;&#10;}&#10;int aggressiveCows(vector&lt;int&gt;&amp; stalls, int k) {&#10;    sort(stalls.begin(), stalls.end());&#10;    int n = stalls.size();&#10;    int low = 1, high = stalls[n-1] - stalls[0];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(canWePlace(stalls, mid, k)) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Bs 16 Split Array Largest Sum<br><br></b> <a href="https://leetcode.com/problems/split-array-largest-sum/" target="_blank">LeetCode 410</a></td>
      <td rowspan="1"><b>Example 1:</b> Equivalent to allocate books.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Identical logic to Allocate Books. Binary search from `max(nums)` to `sum(nums)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPartitions(vector&lt;int&gt;&amp; a, int maxSum) {&#10;    int n = a.size(), partitions = 1, subarraySum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(subarraySum + a[i] &lt;= maxSum) {&#10;            subarraySum += a[i];&#10;        } else {&#10;            partitions++;&#10;            subarraySum = a[i];&#10;        }&#10;    }&#10;    return partitions;&#10;}&#10;int splitArray(vector&lt;int&gt;&amp; nums, int k) {&#10;    int low = *max_element(nums.begin(), nums.end());&#10;    int high = accumulate(nums.begin(), nums.end(), 0);&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int partitions = countPartitions(nums, mid);&#10;        if(partitions &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Bs 17 Painters Partition Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Minimax identical to book allocation.</td>
      <td><b>Time:</b> O(N log(Sum-Max))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Identical to Allocate Books and Split Array Largest Sum. Binary search `max(boards)` to `sum(boards)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPainters(vector&lt;int&gt;&amp; boards, int time) {&#10;    int painters = 1, boardsPainter = 0;&#10;    for(int i=0; i&lt;boards.size(); i++) {&#10;        if(boardsPainter + boards[i] &lt;= time) {&#10;            boardsPainter += boards[i];&#10;        } else {&#10;            painters++;&#10;            boardsPainter = boards[i];&#10;        }&#10;    }&#10;    return painters;&#10;}&#10;int findLargestMinDistance(vector&lt;int&gt; &amp;boards, int k) {&#10;    int low = *max_element(boards.begin(), boards.end());&#10;    long long high = accumulate(boards.begin(), boards.end(), 0LL);&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        int painters = countPainters(boards, mid);&#10;        if(painters &gt; k) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Bs 18 Minimize Max Distance To Gas Station<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Double binary search.</td>
      <td><b>Time:</b> O(N log(MaxDist / 1e-6))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on the real answer (distance) with a precision (e.g., 1e-6). For a given `mid` distance, count how many gas stations need to be inserted in each gap: `ceil((stations[i+1] - stations[i]) / mid) - 1`. If total needed > k, `low = mid`, else `high = mid`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfGasStationsRequired(double dist, vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size(), cnt = 0;&#10;    for(int i=1; i&lt;n; i++) {&#10;        int numberInBetween = ((arr[i] - arr[i-1]) / dist);&#10;        if((arr[i] - arr[i-1]) == (dist * numberInBetween)) {&#10;            numberInBetween--;&#10;        }&#10;        cnt += numberInBetween;&#10;    }&#10;    return cnt;&#10;}&#10;double findSmallestMaxDist(vector&lt;int&gt; &amp;stations, int k) {&#10;    int n = stations.size();&#10;    double low = 0;&#10;    double high = 0;&#10;    for(int i=0; i&lt;n-1; i++) high = max(high, (double)(stations[i+1] - stations[i]));&#10;    double diff = 1e-6;&#10;    while(high - low &gt; diff) {&#10;        double mid = low + (high - low) / (2.0);&#10;        int cnt = numberOfGasStationsRequired(mid, stations);&#10;        if(cnt &gt; k) low = mid;&#10;        else high = mid;&#10;    }&#10;    return high;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Bs 19 Search In A 2D Matrix II<br><br></b> <a href="https://leetcode.com/problems/search-a-2d-matrix-ii/" target="_blank">LeetCode 240</a></td>
      <td rowspan="1"><b>Example 1:</b> Start from top right.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Start from the top-right corner. If `target == current`, return true. If `target < current`, move left (`c--`). If `target > current`, move down (`r++`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    int r = 0, c = matrix[0].size() - 1;&#10;    while(r &lt; matrix.size() &amp;&amp; c &gt;= 0) {&#10;        if(matrix[r][c] == target) return true;&#10;        else if(matrix[r][c] &gt; target) c--;&#10;        else r++;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Bs 20 Find A Peak Element II<br><br></b> <a href="https://leetcode.com/problems/find-a-peak-element-ii/" target="_blank">LeetCode 1901</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary search on columns.</td>
      <td><b>Time:</b> O(N log M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on columns. Find middle column, find max element in this column. Compare it with its left and right neighbors. If it's > both, it's a peak. If left is greater, peak exists in left half. Else, peak exists in right half.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxElemRow(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int col) {&#10;    int maxVal = -1, row = -1;&#10;    for(int i=0; i&lt;mat.size(); i++) {&#10;        if(mat[i][col] &gt; maxVal) {&#10;            maxVal = mat[i][col];&#10;            row = i;&#10;        }&#10;    }&#10;    return row;&#10;}&#10;vector&lt;int&gt; findPeakGrid(vector&lt;vector&lt;int&gt;&gt;&amp; mat) {&#10;    int n = mat.size(), m = mat[0].size();&#10;    int low = 0, high = m - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int row = maxElemRow(mat, mid);&#10;        int left = mid - 1 &gt;= 0 ? mat[row][mid-1] : -1;&#10;        int right = mid + 1 &lt; m ? mat[row][mid+1] : -1;&#10;        if(mat[row][mid] &gt; left &amp;&amp; mat[row][mid] &gt; right) return {row, mid};&#10;        else if(mat[row][mid] &lt; left) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return {-1, -1};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Bs 21 Matrix Median<br><br></b> <a href="https://www.interviewbit.com/problems/matrix-median/" target="_blank">InterviewBit</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary search on answer range.</td>
      <td><b>Time:</b> O(32 * N log M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on the value range `[1, 10^9]`. For a candidate `mid`, count how many numbers are `<= mid` across all rows using `upper_bound`. If count `> (N*M)/2`, `mid` could be median, search lower. Else search higher.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSmallerThanMid(vector&lt;int&gt;&amp; row, int mid) {&#10;    int l = 0, h = row.size() - 1;&#10;    while(l &lt;= h) {&#10;        int md = (l + h) / 2;&#10;        if(row[md] &lt;= mid) l = md + 1;&#10;        else h = md - 1;&#10;    }&#10;    return l;&#10;}&#10;int findMedian(vector&lt;vector&lt;int&gt; &gt; &amp;A) {&#10;    int low = 1, high = 1e9;&#10;    int n = A.size(), m = A[0].size();&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        int cnt = 0;&#10;        for(int i=0; i&lt;n; i++) {&#10;            cnt += countSmallerThanMid(A[i], mid);&#10;        }&#10;        if(cnt &lt;= (n * m) / 2) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Bs 22 Kth Smallest Number In Multiplication Table<br><br></b> <a href="https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/" target="_blank">LeetCode 668</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary Search on answer.</td>
      <td><b>Time:</b> O(m * log(m*n))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Binary search on range `[1, m*n]`. For a value `mid`, the number of elements `<= mid` in row `i` is `min(mid / i, n)`. Sum this for all rows to get total count. If count >= k, search left. Else search right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthNumber(int m, int n, int k) {&#10;    int low = 1, high = m * n;&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        int count = 0;&#10;        for(int i=1; i&lt;=m; i++) {&#10;            count += min(mid / i, n);&#10;        }&#10;        if(count &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Bs 23 Find K Th Smallest Pair Distance<br><br></b> <a href="https://leetcode.com/problems/find-k-th-smallest-pair-distance/" target="_blank">LeetCode 719</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and binary search on distance.</td>
      <td><b>Time:</b> O(N log N + N log(max_dist))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort array. Binary search on distance `[0, nums.back() - nums.front()]`. For a candidate `mid`, count pairs with distance `<= mid` using a sliding window. If count >= k, search left. Else search right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPairs(vector&lt;int&gt;&amp; nums, int mid) {&#10;    int count = 0, l = 0;&#10;    for(int r = 0; r &lt; nums.size(); r++) {&#10;        while(nums[r] - nums[l] &gt; mid) l++;&#10;        count += (r - l);&#10;    }&#10;    return count;&#10;}&#10;int smallestDistancePair(vector&lt;int&gt;&amp; nums, int k) {&#10;    sort(nums.begin(), nums.end());&#10;    int low = 0, high = nums.back() - nums.front();&#10;    while(low &lt; high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countPairs(nums, mid) &gt;= k) high = mid;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Bs 24 Roti Prata Spoj<br><br></b> <a href="https://www.spoj.com/problems/PRATA/" target="_blank">SPOJ</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary Search on Answer.</td>
      <td><b>Time:</b> O(L * log(max_time))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Search space is `0` to `max_time`, where `max_time` is the time taken by the fastest cook to make all `P` pratas alone. `isPossible(mid)` checks if the total pratas made by all cooks in `mid` time is at least `P`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPossible(vector&lt;int&gt;&amp; rank, int p, int mid) {&#10;    int count = 0;&#10;    for(int r : rank) {&#10;        int time = 0, j = 1;&#10;        while(time + r * j &lt;= mid) {&#10;            count++;&#10;            time += r * j;&#10;            j++;&#10;        }&#10;        if(count &gt;= p) return true;&#10;    }&#10;    return count &gt;= p;&#10;}&#10;int minTime(int p, vector&lt;int&gt;&amp; rank) {&#10;    int low = 0, high = 1e8, ans = -1; // high could be rank[0] * P * (P+1) / 2&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(isPossible(rank, p, mid)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Bs 25 Double Helix Spoj<br><br></b> <a href="https://www.spoj.com/problems/ANARC05B/" target="_blank">SPOJ</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers / Binary Search.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use two pointers to traverse both sorted arrays simultaneously. Accumulate sums `sum1` and `sum2`. When elements match (intersection), add `max(sum1, sum2) + element` to the total answer and reset `sum1` and `sum2`. After the loop, add the remaining max sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxPathSum(vector&lt;int&gt;&amp; arr1, vector&lt;int&gt;&amp; arr2) {&#10;    long long sum1 = 0, sum2 = 0, ans = 0;&#10;    int i = 0, j = 0, n = arr1.size(), m = arr2.size();&#10;    while(i &lt; n &amp;&amp; j &lt; m) {&#10;        if(arr1[i] &lt; arr2[j]) sum1 += arr1[i++];&#10;        else if(arr1[i] &gt; arr2[j]) sum2 += arr2[j++];&#10;        else {&#10;            ans += max(sum1, sum2) + arr1[i];&#10;            sum1 = 0; sum2 = 0;&#10;            i++; j++;&#10;        }&#10;    }&#10;    while(i &lt; n) sum1 += arr1[i++];&#10;    while(j &lt; m) sum2 += arr2[j++];&#10;    ans += max(sum1, sum2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Bs 26 Subset Sums Spoj<br><br></b> <a href="https://www.spoj.com/problems/SUBSUMS/" target="_blank">SPOJ</a></td>
      <td rowspan="1"><b>Example 1:</b> Meet in the Middle.</td>
      <td><b>Time:</b> O(2^(N/2) * log(2^(N/2)))<br><b>Space:</b> O(2^(N/2))</td>
      <td>Optimal: Divide the array into two halves. Find all possible subset sums for both halves (`sum1` and `sum2`). Sort `sum2`. For each sum in `sum1`, we need to find the number of elements in `sum2` that satisfy `A - sum <= x <= B - sum`. This can be done using Binary Search (`upper_bound` - `lower_bound`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void getSubsetSums(vector&lt;int&gt;&amp; arr, int st, int end, long long sum, vector&lt;long long&gt;&amp; res) {&#10;    if(st &gt; end) {&#10;        res.push_back(sum);&#10;        return;&#10;    }&#10;    getSubsetSums(arr, st + 1, end, sum + arr[st], res);&#10;    getSubsetSums(arr, st + 1, end, sum, res);&#10;}&#10;long long solve(vector&lt;int&gt;&amp; arr, long long A, long long B) {&#10;    int n = arr.size();&#10;    vector&lt;long long&gt; left, right;&#10;    getSubsetSums(arr, 0, n / 2 - 1, 0, left);&#10;    getSubsetSums(arr, n / 2, n - 1, 0, right);&#10;    sort(right.begin(), right.end());&#10;    long long count = 0;&#10;    for(long long x : left) {&#10;        auto low = lower_bound(right.begin(), right.end(), A - x);&#10;        auto high = upper_bound(right.begin(), right.end(), B - x);&#10;        count += (high - low);&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Bs 27 Smallest Factorial Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log_5(N) * log(5*N))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Trailing zeros depend on number of 5s. Find count of 5s in `mid!`. Use binary search on the number. Low = 0, high = 5*N. If `check(mid) >= n`, `ans = mid` and `high = mid - 1`. Else `low = mid + 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool check(int p, int n) {&#10;    int count = 0, temp = p, f = 5;&#10;    while(f &lt;= temp) {&#10;        count += temp / f;&#10;        f *= 5;&#10;    }&#10;    return count &gt;= n;&#10;}&#10;int findNum(int n) {&#10;    if(n == 1) return 5;&#10;    int low = 0, high = 5 * n;&#10;    int ans = 0;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(check(mid, n)) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Bs 28 Value Equal To Index Value<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Linear scan.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate through the array. If the value at `i` is equal to `i + 1`, append it to the result array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; valueEqualToIndex(int arr[], int n) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(arr[i] == i + 1) ans.push_back(arr[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Bs 29 Count Squares<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-squares3649/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Square root.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Optimal: The number of perfect squares less than `N` is equal to `sqrt(N - 1)` rounded down.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSquares(int N) {&#10;    return sqrt(N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Bs 30 Middle Of Three<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/middle-of-three2926/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Simple if-else.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Compare the numbers. If A is between B and C, return A. If B is between A and C, return B. Else return C.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int middle(int A, int B, int C) {&#10;    if((A &lt; B &amp;&amp; B &lt; C) || (C &lt; B &amp;&amp; B &lt; A)) return B;&#10;    if((B &lt; A &amp;&amp; A &lt; C) || (C &lt; A &amp;&amp; A &lt; B)) return A;&#10;    return C;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Bs 31 Majority Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Moore's Voting Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use Moore's Voting Algorithm to find a candidate for majority element. Then count the occurrences of the candidate in the array to verify if it appears more than N/2 times.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(int a[], int size) {&#10;    int count = 0, candidate = -1;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(count == 0) {&#10;            candidate = a[i];&#10;            count = 1;&#10;        } else if(a[i] == candidate) count++;&#10;        else count--;&#10;    }&#10;    count = 0;&#10;    for(int i = 0; i &lt; size; i++) {&#10;        if(a[i] == candidate) count++;&#10;    }&#10;    if(count &gt; size / 2) return candidate;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Bs 32 Searching In An Array Where Adjacent Differ By At Most K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Jump Search.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Instead of linear search, we can jump ahead. The minimum jump we can make from index `i` to reach `x` is `abs(arr[i] - x) / k`. We jump this amount and check if we found it. Make sure jump is at least 1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(int arr[], int n, int x, int k) {&#10;    int i = 0;&#10;    while(i &lt; n) {&#10;        if(arr[i] == x) return i;&#10;        i = i + max(1, abs(arr[i] - x) / k);&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Bs 33 Find A Pair With The Given Difference<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and two pointers.</td>
      <td><b>Time:</b> O(L log L)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the array. Use two pointers `i = 0` and `j = 1`. If `arr[j] - arr[i] == N` and `i != j`, return true. If difference < N, `j++`. Else `i++`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool findPair(int arr[], int size, int n){&#10;    sort(arr, arr + size);&#10;    int i = 0, j = 1;&#10;    while(i &lt; size &amp;&amp; j &lt; size) {&#10;        if(i != j &amp;&amp; arr[j] - arr[i] == n) return true;&#10;        else if(arr[j] - arr[i] &lt; n) j++;&#10;        else i++;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Bs 34 Find Four Elements That Sum To A Given Value<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two loops and two pointers.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort the array. Use two nested loops for the first two elements. Then use two pointers for the remaining two elements to find the target sum. Skip duplicates at all levels.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt; &amp;arr, int k) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = arr.size();&#10;    sort(arr.begin(), arr.end());&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; arr[i] == arr[i-1]) continue;&#10;        for(int j = i + 1; j &lt; n; j++) {&#10;            if(j &gt; i + 1 &amp;&amp; arr[j] == arr[j-1]) continue;&#10;            int left = j + 1, right = n - 1;&#10;            while(left &lt; right) {&#10;                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];&#10;                if(sum == k) {&#10;                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});&#10;                    left++; right--;&#10;                    while(left &lt; right &amp;&amp; arr[left] == arr[left-1]) left++;&#10;                    while(left &lt; right &amp;&amp; arr[right] == arr[right+1]) right--;&#10;                } else if(sum &lt; k) left++;&#10;                else right--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Bs 35 Find Nth Root Of M<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(N * log M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Search space is `[1, m]`. Check `mid^n`. Since `mid^n` can overflow, use a custom power function that returns 1 if `mid^n == m`, 0 if `< m`, and 2 if `> m`. Adjust `low` and `high` accordingly.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int func(int mid, int n, int m) {&#10;    long long ans = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        ans *= mid;&#10;        if(ans &gt; m) return 2;&#10;    }&#10;    if(ans == m) return 1;&#10;    return 0;&#10;}&#10;int NthRoot(int n, int m) {&#10;    int low = 1, high = m;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        int midN = func(mid, n, m);&#10;        if(midN == 1) return mid;&#10;        else if(midN == 0) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Bs 36 Row With Max 1S<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Lower Bound per row.</td>
      <td><b>Time:</b> O(N log M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Since rows are sorted, use binary search (`lower_bound` of 1) to find the first index of 1 in each row. The number of 1s is `m - index`. Keep track of the row with the maximum 1s.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lowerBound(vector&lt;int&gt; arr, int n, int x) {&#10;    int low = 0, high = n - 1, ans = n;&#10;    while(low &lt;= high) {&#10;        int mid = (low + high) / 2;&#10;        if(arr[mid] &gt;= x) {&#10;            ans = mid;&#10;            high = mid - 1;&#10;        } else {&#10;            low = mid + 1;&#10;        }&#10;    }&#10;    return ans;&#10;}&#10;int rowWithMax1s(vector&lt;vector&lt;int&gt;&gt; arr, int n, int m) {&#10;    int max_cnt = 0, index = -1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int cnt_ones = m - lowerBound(arr[i], m, 1);&#10;        if(cnt_ones &gt; max_cnt) {&#10;            max_cnt = cnt_ones;&#10;            index = i;&#10;        }&#10;    }&#10;    return index;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Recursion

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
      <td rowspan="1">Rec 01 Combination Sum<br><br></b> <a href="https://leetcode.com/problems/combination-sum/" target="_blank">LeetCode 39</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> candidates = [2,3,6,7], target = 7<br><b>Output:</b> [[2,2,3],[7]]<br><br><b>Note (Constraint):</b> The same number may be chosen unlimited number of times.</td>
      <td><b>Time:</b> O(2<sup>T</sup>) (Trade-off)<br><b>Space:</b> O(T) (Trade-off)</td>
      <td>Pick/Non-Pick but when picking, we *do not* increment the index `i`, allowing the same element to be picked infinitely until `target < 0`.</td>
      <td><b>Edge Cases:</b> <b>Infinite Loop Prevention:</b> Base cases must immediately return if `target < 0` to prevent infinite recursion on the same index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, std::vector&lt;int&gt;&amp; arr, int target, std::vector&lt;int&gt;&amp; temp, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if (i == arr.size()) {&#10;        if (target == 0) ans.push_back(temp);&#10;        return;&#10;    }&#10;    // Pick (Stay on same index if valid)&#10;    if (arr[i] &lt;= target) {&#10;        temp.push_back(arr[i]);&#10;        solve(i, arr, target - arr[i], temp, ans);&#10;        temp.pop_back();&#10;    }&#10;    // Not Pick (Move to next)&#10;    solve(i + 1, arr, target, temp, ans);&#10;}&#10;&#10;std::vector&lt;std::vector&lt;int&gt;&gt; combinationSum(std::vector&lt;int&gt;&amp; candidates, int target) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::vector&lt;int&gt; temp;&#10;    solve(0, candidates, target, temp, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Rec 02 N Queens<br><br></b> <a href="https://leetcode.com/problems/n-queens/" target="_blank">LeetCode 51</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 4<br><b>Output:</b> [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br><br><b>Note (Constraint):</b> 1 &le; n &le; 9</td>
      <td><b>Time:</b> O(N!) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>Backtracking. Try placing a queen in each row of the current column. Use `O(1)` lookups (Hashing logic) via arrays to check if row/diagonals are safe.<br><br><b>Dependencies:</b> Hash Maps/Arrays for safety checks</td>
      <td><b>Edge Cases:</b> <b>Diagonal Math:</b> Lower diagonal is tracked via `row + col`, Upper diagonal via `(n - 1) + (col - row)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, int n, std::vector&lt;std::string&gt;&amp; board, std::vector&lt;std::vector&lt;std::string&gt;&gt;&amp; ans, std::vector&lt;int&gt;&amp; leftRow, std::vector&lt;int&gt;&amp; upperDiag, std::vector&lt;int&gt;&amp; lowerDiag) {&#10;    if (col == n) {&#10;        ans.push_back(board);&#10;        return;&#10;    }&#10;    for (int row = 0; row &lt; n; row++) {&#10;        if (leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            board[row][col] = &#x27;Q&#x27;;&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            &#10;            solve(col + 1, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;            &#10;            board[row][col] = &#x27;.&#x27;;&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;&#10;std::vector&lt;std::vector&lt;std::string&gt;&gt; solveNQueens(int n) {&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    std::vector&lt;std::string&gt; board(n, std::string(n, &#x27;.&#x27;));&#10;    std::vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, board, ans, leftRow, upperDiag, lowerDiag);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Rec 03 Permutations<br><br></b> <a href="https://leetcode.com/problems/permutations/" target="_blank">LeetCode 46</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3]<br><b>Output:</b> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td>Backtracking. Swap elements to generate permutations. For index `i`, swap it with every index from `i` to `n-1`, recurse, then backtrack (swap back).<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Backtracking necessity:</b> Without the second swap (backtrack), the array remains mutated for subsequent sibling recursion branches.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int idx, std::vector&lt;int&gt;&amp; nums, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(nums);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; nums.size(); i++) {&#10;        std::swap(nums[idx], nums[i]);&#10;        solve(idx + 1, nums, ans);&#10;        std::swap(nums[idx], nums[i]);&#10;    }&#10;}&#10;std::vector&lt;std::vector&lt;int&gt;&gt; permute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    solve(0, nums, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Rec 04 Sudoku Solver<br><br></b> <a href="https://leetcode.com/problems/sudoku-solver/" target="_blank">LeetCode 37</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> board with '.' for empty cells. Solve in-place.</td>
      <td><b>Time:</b> O(9^(n*n))<br><b>Space:</b> O(1) auxiliary</td>
      <td>Backtracking. Find first empty cell, try placing 1-9. Validate row, col, and 3x3 sub-grid. Recursively solve the rest. If it fails, backtrack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(vector&lt;vector&lt;char&gt;&gt;&amp; board, int row, int col, char c) {&#10;    for(int i=0; i&lt;9; i++) {&#10;        if(board[i][col] == c) return false;&#10;        if(board[row][i] == c) return false;&#10;        if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            if(board[i][j] == &#x27;.&#x27;) {&#10;                for(char c=&#x27;1&#x27;; c&lt;=&#x27;9&#x27;; c++) {&#10;                    if(isValid(board, i, j, c)) {&#10;                        board[i][j] = c;&#10;                        if(solve(board)) return true;&#10;                        else board[i][j] = &#x27;.&#x27;;&#10;                    }&#10;                }&#10;                return false;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}&#10;void solveSudoku(vector&lt;vector&lt;char&gt;&gt;&amp; board) {&#10;    solve(board);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Rec 05 M Coloring Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return true if possible.</td>
      <td><b>Time:</b> O(M^N)<br><b>Space:</b> O(N)</td>
      <td>Backtracking. Try coloring each node with color 1 to m. For a color, check if any adjacent node has the same color. If safe, assign and recurse for next node. If recursion returns false, backtrack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {&#10;    for(int k=0; k&lt;n; k++) {&#10;        if(k != node &amp;&amp; graph[k][node] == 1 &amp;&amp; color[k] == col) return false;&#10;    }&#10;    return true;&#10;}&#10;bool solve(int node, int color[], int m, int n, bool graph[101][101]) {&#10;    if(node == n) return true;&#10;    for(int i=1; i&lt;=m; i++) {&#10;        if(isSafe(node, color, graph, n, i)) {&#10;            color[node] = i;&#10;            if(solve(node + 1, color, m, n, graph)) return true;&#10;            color[node] = 0;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool graphColoring(bool graph[101][101], int m, int n) {&#10;    int color[n] = {0};&#10;    return solve(0, color, m, n, graph);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Rec 06 Rat In A Maze<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Lexicographical order paths.</td>
      <td><b>Time:</b> O(4^(N*N))<br><b>Space:</b> O(N*N)</td>
      <td>Backtracking. Explore 4 directions (D, L, R, U) in lexicographical order to get sorted paths naturally. Mark cell as visited, recurse, then unmark (backtrack).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int i, int j, vector&lt;vector&lt;int&gt;&gt; &amp;m, int n, vector&lt;string&gt; &amp;ans, string move, vector&lt;vector&lt;int&gt;&gt; &amp;vis, int di[], int dj[]) {&#10;    if(i == n-1 &amp;&amp; j == n-1) { ans.push_back(move); return; }&#10;    string dir = &quot;DLRU&quot;;&#10;    for(int ind = 0; ind &lt; 4; ind++) {&#10;        int nexti = i + di[ind];&#10;        int nextj = j + dj[ind];&#10;        if(nexti &gt;= 0 &amp;&amp; nextj &gt;= 0 &amp;&amp; nexti &lt; n &amp;&amp; nextj &lt; n &amp;&amp; !vis[nexti][nextj] &amp;&amp; m[nexti][nextj] == 1) {&#10;            vis[i][j] = 1;&#10;            solve(nexti, nextj, m, n, ans, move + dir[ind], vis, di, dj);&#10;            vis[i][j] = 0;&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; findPath(vector&lt;vector&lt;int&gt;&gt; &amp;m, int n) {&#10;    vector&lt;string&gt; ans;&#10;    vector&lt;vector&lt;int&gt;&gt; vis(n, vector&lt;int&gt;(n, 0));&#10;    int di[] = {1, 0, 0, -1};&#10;    int dj[] = {0, -1, 1, 0};&#10;    if(m[0][0] == 1) solve(0, 0, m, n, ans, &quot;&quot;, vis, di, dj);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Rec 07 Word Break<br><br></b> <a href="https://leetcode.com/problems/word-break/" target="_blank">LeetCode 139</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = 'leetcode', wordDict = ['leet','code']<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N)</td>
      <td>Recursion with Memoization (or DP). For each index, try all possible word lengths. If a prefix exists in dict, recurse for the suffix. DP array `dp[i]` stores if `s[0...i-1]` is valid.<br><br><b>Dependencies:</b> <code>#include <unordered_set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    int n = s.length();&#10;    vector&lt;bool&gt; dp(n + 1, false);&#10;    dp[0] = true;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=0; j&lt;i; j++) {&#10;            if(dp[j] &amp;&amp; dict.count(s.substr(j, i - j))) {&#10;                dp[i] = true;&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Rec 08 Word Break II<br><br></b> <a href="https://leetcode.com/problems/word-break-ii/" target="_blank">LeetCode 140</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of sentences.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td>Backtracking. Generate all combinations. At each step, if a prefix is in dict, recursively call for the rest of the string and append the prefix to the result of the recursive call.<br><br><b>Dependencies:</b> <code>#include <unordered_set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;string&gt; solve(string s, unordered_set&lt;string&gt;&amp; dict, unordered_map&lt;string, vector&lt;string&gt;&gt;&amp; memo) {&#10;    if(memo.count(s)) return memo[s];&#10;    if(s.empty()) return {&quot;&quot;};&#10;    vector&lt;string&gt; res;&#10;    for(int i=1; i&lt;=s.length(); i++) {&#10;        string word = s.substr(0, i);&#10;        if(dict.count(word)) {&#10;            vector&lt;string&gt; rem = solve(s.substr(i), dict, memo);&#10;            for(string str : rem) {&#10;                res.push_back(word + (str.empty() ? &quot;&quot; : &quot; &quot;) + str);&#10;            }&#10;        }&#10;    }&#10;    return memo[s] = res;&#10;}&#10;vector&lt;string&gt; wordBreak(string s, vector&lt;string&gt;&amp; wordDict) {&#10;    unordered_set&lt;string&gt; dict(wordDict.begin(), wordDict.end());&#10;    unordered_map&lt;string, vector&lt;string&gt;&gt; memo;&#10;    return solve(s, dict, memo);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Rec 09 Palindrome Partitioning<br><br></b> <a href="https://leetcode.com/problems/palindrome-partitioning/" target="_blank">LeetCode 131</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = 'aab'<br><b>Output:</b> [['a','a','b'],['aa','b']]</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>Backtracking. Try to partition the string at every index. If the prefix `s[start:i]` is a palindrome, add it to current path and recurse for the rest of the string `s[i:end]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string s, int start, int end) {&#10;    while(start &lt;= end) {&#10;        if(s[start++] != s[end--]) return false;&#10;    }&#10;    return true;&#10;}&#10;void solve(int index, string s, vector&lt;string&gt; &amp;path, vector&lt;vector&lt;string&gt;&gt; &amp;res) {&#10;    if(index == s.size()) {&#10;        res.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = index; i &lt; s.size(); ++i) {&#10;        if(isPalindrome(s, index, i)) {&#10;            path.push_back(s.substr(index, i - index + 1));&#10;            solve(i + 1, s, path, res);&#10;            path.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; partition(string s) {&#10;    vector&lt;vector&lt;string&gt;&gt; res;&#10;    vector&lt;string&gt; path;&#10;    solve(0, s, path, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Rec 10 Expression Add Operators<br><br></b> <a href="https://leetcode.com/problems/expression-add-operators/" target="_blank">LeetCode 282</a></td>
      <td rowspan="1"><b>Example 1:</b> Return expressions.</td>
      <td><b>Time:</b> O(N * 4^N)<br><b>Space:</b> O(N)</td>
      <td>Backtracking. Keep track of the evaluated sum so far, and the previous operand (for multiplication precedence). For '*', `newSum = sum - prev + prev * curr`. Handle leading zeros.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string num, int target, vector&lt;string&gt;&amp; ans, string path, long long eval, long long multed) {&#10;    if(ind == num.size()) {&#10;        if(eval == target) ans.push_back(path);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; num.size(); i++) {&#10;        if(i != ind &amp;&amp; num[ind] == &#x27;0&#x27;) break;&#10;        string curStr = num.substr(ind, i - ind + 1);&#10;        long long curNum = stoll(curStr);&#10;        if(ind == 0) {&#10;            solve(i + 1, num, target, ans, path + curStr, curNum, curNum);&#10;        } else {&#10;            solve(i + 1, num, target, ans, path + &quot;+&quot; + curStr, eval + curNum, curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;-&quot; + curStr, eval - curNum, -curNum);&#10;            solve(i + 1, num, target, ans, path + &quot;*&quot; + curStr, eval - multed + multed * curNum, multed * curNum);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; addOperators(string num, int target) {&#10;    vector&lt;string&gt; ans;&#10;    solve(0, num, target, ans, &quot;&quot;, 0, 0);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Rec 11 Subset Sums II<br><br></b> <a href="https://leetcode.com/problems/subsets-ii/" target="_blank">LeetCode 90</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> [[],[1],[1,2],[1,2,2],[2],[2,2]]</td>
      <td><b>Time:</b> O(2^N * N)<br><b>Space:</b> O(2^N * N)</td>
      <td>Sort array first to bring duplicates together. In recursive call, loop from `ind` to `n`. If `i > ind` and `nums[i] == nums[i-1]`, `continue` to skip duplicate recursive branches.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findSubsets(int ind, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    ans.push_back(ds);&#10;    for(int i = ind; i &lt; nums.size(); i++) {&#10;        if(i != ind &amp;&amp; nums[i] == nums[i - 1]) continue;&#10;        ds.push_back(nums[i]);&#10;        findSubsets(i + 1, nums, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsWithDup(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    sort(nums.begin(), nums.end());&#10;    findSubsets(0, nums, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Rec 12 Combination Sum II<br><br></b> <a href="https://leetcode.com/problems/combination-sum-ii/" target="_blank">LeetCode 40</a></td>
      <td rowspan="1"><b>Example 1:</b> Return unique combinations.</td>
      <td><b>Time:</b> O(2^N * k)<br><b>Space:</b> O(k * x)</td>
      <td>Sort the array. Recursive function iterates from `ind` to `n`. Skip duplicates (`if i > ind and arr[i] == arr[i-1]`). If `arr[i] > target`, break. Else add to path, subtract from target, and recurse.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findCombinations(int ind, int target, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; ans, vector&lt;int&gt;&amp; ds) {&#10;    if(target == 0) {&#10;        ans.push_back(ds);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; arr.size(); i++) {&#10;        if(i &gt; ind &amp;&amp; arr[i] == arr[i - 1]) continue;&#10;        if(arr[i] &gt; target) break;&#10;        ds.push_back(arr[i]);&#10;        findCombinations(i + 1, target - arr[i], arr, ans, ds);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum2(vector&lt;int&gt;&amp; candidates, int target) {&#10;    sort(candidates.begin(), candidates.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    findCombinations(0, target, candidates, ans, ds);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Rec 13 Combination Sum III<br><br></b> <a href="https://leetcode.com/problems/combination-sum-iii/" target="_blank">LeetCode 216</a></td>
      <td rowspan="1"><b>Example 1:</b> Return combinations.</td>
      <td><b>Time:</b> O(2^9)<br><b>Space:</b> O(k)</td>
      <td>Backtracking. Start from 1, go up to 9. Add the current number to the path and subtract from target. Stop when path size is `k` and `target` is 0.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int start, int k, int n, vector&lt;int&gt;&amp; ds, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(k == 0 &amp;&amp; n == 0) { ans.push_back(ds); return; }&#10;    if(k == 0 || n &lt; 0) return;&#10;    for(int i = start; i &lt;= 9; i++) {&#10;        ds.push_back(i);&#10;        solve(i + 1, k - 1, n - i, ds, ans);&#10;        ds.pop_back();&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum3(int k, int n) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; ds;&#10;    solve(1, k, n, ds, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Rec 14 Letter Combinations Of A Phone Number<br><br></b> <a href="https://leetcode.com/problems/letter-combinations-of-a-phone-number/" target="_blank">LeetCode 17</a></td>
      <td rowspan="1"><b>Example 1:</b> String combinations.</td>
      <td><b>Time:</b> O(4^N * N)<br><b>Space:</b> O(N)</td>
      <td>Backtracking. Create a mapping of digit to letters. Iterate through digits, for each digit loop through its mapped letters, append to current string, and recurse.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int ind, string digits, string mapping[], string path, vector&lt;string&gt;&amp; ans) {&#10;    if(ind == digits.length()) {&#10;        ans.push_back(path);&#10;        return;&#10;    }&#10;    int number = digits[ind] - &#x27;0&#x27;;&#10;    string value = mapping[number];&#10;    for(int i = 0; i &lt; value.length(); i++) {&#10;        solve(ind + 1, digits, mapping, path + value[i], ans);&#10;    }&#10;}&#10;vector&lt;string&gt; letterCombinations(string digits) {&#10;    if(digits.length() == 0) return {};&#10;    vector&lt;string&gt; ans;&#10;    string mapping[10] = {&quot;&quot;, &quot;&quot;, &quot;abc&quot;, &quot;def&quot;, &quot;ghi&quot;, &quot;jkl&quot;, &quot;mno&quot;, &quot;pqrs&quot;, &quot;tuv&quot;, &quot;wxyz&quot;};&#10;    solve(0, digits, mapping, &quot;&quot;, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Rec 15 Subset Sum I<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subset-sums2234/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Take / Not Take.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(2^N)</td>
      <td>Recursively either include `arr[ind]` in sum, or exclude it. If `ind == N`, add `sum` to result array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void func(int ind, int sum, vector&lt;int&gt;&amp; arr, int N, vector&lt;int&gt;&amp; sumSubset) {&#10;    if(ind == N) {&#10;        sumSubset.push_back(sum);&#10;        return;&#10;    }&#10;    func(ind + 1, sum + arr[ind], arr, N, sumSubset);&#10;    func(ind + 1, sum, arr, N, sumSubset);&#10;}&#10;vector&lt;int&gt; subsetSums(vector&lt;int&gt; arr, int N) {&#10;    vector&lt;int&gt; sumSubset;&#10;    func(0, 0, arr, N, sumSubset);&#10;    sort(sumSubset.begin(), sumSubset.end());&#10;    return sumSubset;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Rec 16 N Queens II<br><br></b> <a href="https://leetcode.com/problems/n-queens-ii/" target="_blank">LeetCode 52</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking with hashing.</td>
      <td><b>Time:</b> O(N!)<br><b>Space:</b> O(N)</td>
      <td>Use backtracking to place queens column by column. Use three hash arrays (or bitmasks) to track attacked rows, upper diagonals, and lower diagonals. If placing a queen is safe, update hashes, recurse for next column, and then backtrack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int col, int n, vector&lt;int&gt;&amp; leftRow, vector&lt;int&gt;&amp; upperDiag, vector&lt;int&gt;&amp; lowerDiag, int&amp; count) {&#10;    if(col == n) {&#10;        count++;&#10;        return;&#10;    }&#10;    for(int row = 0; row &lt; n; row++) {&#10;        if(leftRow[row] == 0 &amp;&amp; lowerDiag[row + col] == 0 &amp;&amp; upperDiag[n - 1 + col - row] == 0) {&#10;            leftRow[row] = 1;&#10;            lowerDiag[row + col] = 1;&#10;            upperDiag[n - 1 + col - row] = 1;&#10;            solve(col + 1, n, leftRow, upperDiag, lowerDiag, count);&#10;            leftRow[row] = 0;&#10;            lowerDiag[row + col] = 0;&#10;            upperDiag[n - 1 + col - row] = 0;&#10;        }&#10;    }&#10;}&#10;int totalNQueens(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; leftRow(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);&#10;    solve(0, n, leftRow, upperDiag, lowerDiag, count);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Rec 17 Word Search<br><br></b> <a href="https://leetcode.com/problems/word-search/" target="_blank">LeetCode 79</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking DFS.</td>
      <td><b>Time:</b> O(N * M * 4^L)<br><b>Space:</b> O(L) recursion stack</td>
      <td>Start DFS from each cell that matches the first letter of the word. In DFS, check 4 neighbors. Mark current cell as visited (e.g. change to '#') before moving to neighbors, and unmark (backtrack) after exploring.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(vector&lt;vector&lt;char&gt;&gt;&amp; board, int i, int j, string&amp; word, int idx) {&#10;    if(idx == word.length()) return true;&#10;    if(i &lt; 0 || i &gt;= board.size() || j &lt; 0 || j &gt;= board[0].size() || board[i][j] != word[idx]) return false;&#10;    char temp = board[i][j];&#10;    board[i][j] = &#x27;#&#x27;;&#10;    bool found = dfs(board, i+1, j, word, idx+1) ||&#10;                 dfs(board, i-1, j, word, idx+1) ||&#10;                 dfs(board, i, j+1, word, idx+1) ||&#10;                 dfs(board, i, j-1, word, idx+1);&#10;    board[i][j] = temp;&#10;    return found;&#10;}&#10;bool exist(vector&lt;vector&lt;char&gt;&gt;&amp; board, string word) {&#10;    for(int i = 0; i &lt; board.size(); i++) {&#10;        for(int j = 0; j &lt; board[0].size(); j++) {&#10;            if(board[i][j] == word[0] &amp;&amp; dfs(board, i, j, word, 0)) return true;&#10;        }&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Rec 18 K Th Symbol In Grammar<br><br></b> <a href="https://leetcode.com/problems/k-th-symbol-in-grammar/" target="_blank">LeetCode 779</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive division.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Row N has length 2^(N-1). The first half of row N is exactly same as row N-1. The second half of row N is the complement of row N-1. If k is in the first half (k <= mid), return solve(N-1, k). If k is in the second half, return !solve(N-1, k - mid).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthGrammar(int n, int k) {&#10;    if(n == 1 &amp;&amp; k == 1) return 0;&#10;    int mid = pow(2, n - 2);&#10;    if(k &lt;= mid) {&#10;        return kthGrammar(n - 1, k);&#10;    } else {&#10;        return !kthGrammar(n - 1, k - mid);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Rec 19 Beautiful Arrangement<br><br></b> <a href="https://leetcode.com/problems/beautiful-arrangement/" target="_blank">LeetCode 526</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(K) where K is number of valid permutations<br><b>Space:</b> O(N)</td>
      <td>Use an array to track visited numbers. Iterate from index 1 to n. For the current index, try placing an unvisited number. Check if the condition `(num % idx == 0 || idx % num == 0)` is met. If so, mark as visited, recurse to `idx + 1`, then backtrack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countArrangement(int n) {&#10;    int count = 0;&#10;    vector&lt;int&gt; visited(n + 1, 0);&#10;    function&lt;void(int)&gt; solve = [&amp;](int idx) {&#10;        if(idx &gt; n) {&#10;            count++;&#10;            return;&#10;        }&#10;        for(int i = 1; i &lt;= n; i++) {&#10;            if(!visited[i] &amp;&amp; (i % idx == 0 || idx % i == 0)) {&#10;                visited[i] = 1;&#10;                solve(idx + 1);&#10;                visited[i] = 0;&#10;            }&#10;        }&#10;    };&#10;    solve(1);&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Rec 20 Print All Permutations Of A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N! * N)<br><b>Space:</b> O(N)</td>
      <td>Convert string to char array and sort it. Use backtracking: pass a boolean visited array and a temporary string. If temporary string length equals original length, add to answer. Else, iterate through characters. To avoid duplicates, if `i > 0` and `s[i] == s[i-1]` and `!vis[i-1]`, skip. Otherwise, mark visited, append, recurse, unmark, pop.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string&amp; S, vector&lt;bool&gt;&amp; vis, string&amp; curr, vector&lt;string&gt;&amp; ans) {&#10;    if(curr.length() == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = 0; i &lt; S.length(); i++) {&#10;        if(vis[i] || (i &gt; 0 &amp;&amp; S[i] == S[i-1] &amp;&amp; !vis[i-1])) continue;&#10;        vis[i] = true;&#10;        curr.push_back(S[i]);&#10;        solve(S, vis, curr, ans);&#10;        curr.pop_back();&#10;        vis[i] = false;&#10;    }&#10;}&#10;vector&lt;string&gt; find_permutation(string S) {&#10;    sort(S.begin(), S.end());&#10;    vector&lt;string&gt; ans;&#10;    string curr = &quot;&quot;;&#10;    vector&lt;bool&gt; vis(S.length(), false);&#10;    solve(S, vis, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Rec 21 Remove Invalid Parentheses<br><br></b> <a href="https://leetcode.com/problems/remove-invalid-parentheses/" target="_blank">LeetCode 301</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion and Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>First find the number of misplaced left (`rm_l`) and right (`rm_r`) parentheses. Then use backtracking to try removing `rm_l` and `rm_r` parentheses. To avoid duplicates, skip identical adjacent characters. Finally, check if the resulting string is valid.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(string&amp; s) {&#10;    int count = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) count++;&#10;        else if(c == &#x27;)&#x27;) count--;&#10;        if(count &lt; 0) return false;&#10;    }&#10;    return count == 0;&#10;}&#10;void solve(string s, int start, int rm_l, int rm_r, vector&lt;string&gt;&amp; ans) {&#10;    if(rm_l == 0 &amp;&amp; rm_r == 0) {&#10;        if(isValid(s)) ans.push_back(s);&#10;        return;&#10;    }&#10;    for(int i = start; i &lt; s.length(); i++) {&#10;        if(i != start &amp;&amp; s[i] == s[i-1]) continue;&#10;        if(s[i] == &#x27;(&#x27; &amp;&amp; rm_l &gt; 0) {&#10;            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l - 1, rm_r, ans);&#10;        }&#10;        else if(s[i] == &#x27;)&#x27; &amp;&amp; rm_r &gt; 0) {&#10;            solve(s.substr(0, i) + s.substr(i + 1), i, rm_l, rm_r - 1, ans);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; removeInvalidParentheses(string s) {&#10;    int rm_l = 0, rm_r = 0;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27;) rm_l++;&#10;        else if(c == &#x27;)&#x27;) {&#10;            if(rm_l &gt; 0) rm_l--;&#10;            else rm_r++;&#10;        }&#10;    }&#10;    vector&lt;string&gt; ans;&#10;    solve(s, 0, rm_l, rm_r, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Rec 22 Matchsticks To Square<br><br></b> <a href="https://leetcode.com/problems/matchsticks-to-square/" target="_blank">LeetCode 473</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking to 4 subsets.</td>
      <td><b>Time:</b> O(4^N)<br><b>Space:</b> O(N)</td>
      <td>Calculate sum. If sum % 4 != 0, return false. Target side length is sum / 4. Sort matchsticks in descending order to optimize. Create an array `sides` of size 4. For each matchstick, try adding it to one of the 4 sides. If a side equals the target or is less, recurse.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool solve(vector&lt;int&gt;&amp; arr, vector&lt;int&gt;&amp; sides, int target, int ind) {&#10;    if(ind == arr.size()) {&#10;        return sides[0] == target &amp;&amp; sides[1] == target &amp;&amp; sides[2] == target;&#10;    }&#10;    for(int i = 0; i &lt; 4; i++) {&#10;        if(sides[i] + arr[ind] &lt;= target) {&#10;            sides[i] += arr[ind];&#10;            if(solve(arr, sides, target, ind + 1)) return true;&#10;            sides[i] -= arr[ind];&#10;        }&#10;        if(sides[i] == 0) break;&#10;    }&#10;    return false;&#10;}&#10;bool makesquare(vector&lt;int&gt;&amp; matchsticks) {&#10;    long long sum = 0;&#10;    for(int m : matchsticks) sum += m;&#10;    if(sum % 4 != 0 || matchsticks.size() &lt; 4) return false;&#10;    sort(matchsticks.rbegin(), matchsticks.rend());&#10;    vector&lt;int&gt; sides(4, 0);&#10;    return solve(matchsticks, sides, sum / 4, 0);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Rec 23 Tug Of War<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/tug-of-war/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>Keep track of the number of elements included in subset 1 and their sum. Recurse by including the current element in subset 1 or subset 2. Base case: if we reach end, check if subset 1 has `n/2` elements. If so, compute difference and update global minimum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDiff;&#10;void solve(vector&lt;int&gt;&amp; arr, int ind, int cnt, int sum1, int totalSum, int n) {&#10;    if(ind == n) {&#10;        if(cnt == n / 2) {&#10;            int sum2 = totalSum - sum1;&#10;            minDiff = min(minDiff, abs(sum1 - sum2));&#10;        }&#10;        return;&#10;    }&#10;    if(cnt &lt; n / 2) solve(arr, ind + 1, cnt + 1, sum1 + arr[ind], totalSum, n);&#10;    solve(arr, ind + 1, cnt, sum1, totalSum, n);&#10;}&#10;int tugOfWar(vector&lt;int&gt;&amp; arr) {&#10;    int totalSum = 0;&#10;    for(int x : arr) totalSum += x;&#10;    minDiff = INT_MAX;&#10;    solve(arr, 0, 0, 0, totalSum, arr.size());&#10;    return minDiff;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Rec 24 Find Paths From Corner Cell To Middle Cell<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/paths-from-corner-to-middle/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS / DFS for path finding.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Perform BFS or DFS starting from all 4 corners simultaneously or individually. At each cell `(r, c)`, the jump size is `val = grid[r][c]`. We can move to `(r+val, c)`, `(r-val, c)`, `(r, c+val)`, `(r, c-val)`. Target is `(N/2, N/2)`.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    vector&lt;vector&lt;bool&gt;&gt; vis(n, vector&lt;bool&gt;(n, false));&#10;    auto add = [&amp;](int r, int c) { q.push({r, c}); vis[r][c] = true; };&#10;    add(0, 0); add(0, n-1); add(n-1, 0); add(n-1, n-1);&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    while(!q.empty()) {&#10;        auto [r, c] = q.front(); q.pop();&#10;        if(r == n/2 &amp;&amp; c == n/2) { /* found path */ }&#10;        int val = grid[r][c];&#10;        for(int i=0; i&lt;4; i++) {&#10;            int nr = r + dr[i] * val, nc = c + dc[i] * val;&#10;            if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n &amp;&amp; !vis[nr][nc]) {&#10;                vis[nr][nc] = true;&#10;                q.push({nr, nc});&#10;            }&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Rec 25 Arithmetic Expressions<br><br></b> <a href="https://www.hackerrank.com/challenges/arithmetic-expressions/problem" target="_blank">HackerRank</a></td>
      <td rowspan="1"><b>Example 1:</b> DP with path reconstruction.</td>
      <td><b>Time:</b> O(N * 101)<br><b>Space:</b> O(N * 101)</td>
      <td>Use a DP table `dp[i][mod]` to store the operator used to reach remainder `mod` at index `i`. Iterate through the array, for each reachable mod from previous step, try `(mod + arr[i]) % 101`, `(mod - arr[i]) % 101`, `(mod * arr[i]) % 101`. Then backtrack from `dp[N-1][0]` to find the operators.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string arithmeticExpressions(vector&lt;int&gt; arr) {&#10;    int n = arr.size();&#10;    vector&lt;vector&lt;char&gt;&gt; dp(n, vector&lt;char&gt;(101, 0));&#10;    dp[0][arr[0] % 101] = &#x27; &#x27;;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; 101; j++) {&#10;            if(dp[i-1][j]) {&#10;                dp[i][(j + arr[i]) % 101] = &#x27;+&#x27;;&#10;                dp[i][(j - arr[i] % 101 + 101) % 101] = &#x27;-&#x27;;&#10;                dp[i][(j * arr[i]) % 101] = &#x27;*&#x27;;&#10;            }&#10;        }&#10;    }&#10;    string res = &quot;&quot;;&#10;    int curr = 0;&#10;    for(int i = n - 1; i &gt; 0; i--) {&#10;        char op = dp[i][curr];&#10;        res = op + to_string(arr[i]) + res;&#10;        for(int j = 0; j &lt; 101; j++) {&#10;            if(dp[i-1][j]) {&#10;                if(op == &#x27;+&#x27; &amp;&amp; (j + arr[i]) % 101 == curr) { curr = j; break; }&#10;                if(op == &#x27;-&#x27; &amp;&amp; (j - arr[i] % 101 + 101) % 101 == curr) { curr = j; break; }&#10;                if(op == &#x27;*&#x27; &amp;&amp; (j * arr[i]) % 101 == curr) { curr = j; break; }&#10;            }&#10;        }&#10;    }&#10;    return to_string(arr[0]) + res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Rec 26 Find All Possible Palindromic Partitions Of A String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N)</td>
      <td>Iterate through the string. Extract substring `S[ind..i]`. If it is a palindrome, add it to the current partition list and recursively call for `i+1`. When `ind == length`, push the partition list to the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPal(string&amp; s) {&#10;    int i = 0, j = s.length() - 1;&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;void solve(string&amp; S, int ind, vector&lt;string&gt;&amp; curr, vector&lt;vector&lt;string&gt;&gt;&amp; ans) {&#10;    if(ind == S.length()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = ind; i &lt; S.length(); i++) {&#10;        string sub = S.substr(ind, i - ind + 1);&#10;        if(isPal(sub)) {&#10;            curr.push_back(sub);&#10;            solve(S, i + 1, curr, ans);&#10;            curr.pop_back();&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; allPalindromicPerms(string S) {&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    vector&lt;string&gt; curr;&#10;    solve(S, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Rec 27 Partition Array To K Subsets<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(K * 2^N)<br><b>Space:</b> O(N)</td>
      <td>If total sum is not divisible by K, return false. Sort array in descending order. Use a boolean array `vis`. Helper function `solve(ind, currentSum, k)`: if `k == 1` return true. If `currentSum == target`, `solve(0, 0, k-1)`. Otherwise, iterate from `ind` to `N`, if `!vis[i]` and `currentSum + arr[i] <= target`, mark `vis[i] = true`, recurse, unmark.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool solve(int a[], int n, int k, int target, int currSum, int ind, vector&lt;bool&gt;&amp; vis) {&#10;    if(k == 1) return true;&#10;    if(currSum == target) return solve(a, n, k - 1, target, 0, 0, vis);&#10;    for(int i = ind; i &lt; n; i++) {&#10;        if(!vis[i] &amp;&amp; currSum + a[i] &lt;= target) {&#10;            vis[i] = true;&#10;            if(solve(a, n, k, target, currSum + a[i], i + 1, vis)) return true;&#10;            vis[i] = false;&#10;        }&#10;    }&#10;    return false;&#10;}&#10;bool isKPartitionPossible(int a[], int n, int k) {&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) sum += a[i];&#10;    if(sum % k != 0 || n &lt; k) return false;&#10;    vector&lt;bool&gt; vis(n, false);&#10;    return solve(a, n, k, sum / k, 0, 0, vis);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Rec 28 Longest Possible Route In A Matrix With Hurdles<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Backtracking.</td>
      <td><b>Time:</b> O(4^(N*M))<br><b>Space:</b> O(N*M)</td>
      <td>Use a global `max_dist` or pass it by reference. In `solve(r, c, dist)`, if `(r, c) == (dest_r, dest_c)`, `max_dist = max(max_dist, dist)` and return. Mark `(r, c)` as visited. Explore 4 directions. Unmark `(r, c)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDist;&#10;void solve(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int r, int c, int dr, int dc, int dist) {&#10;    if(r == dr &amp;&amp; c == dc) {&#10;        maxDist = max(maxDist, dist);&#10;        return;&#10;    }&#10;    mat[r][c] = 0; // mark visited&#10;    int dRow[] = {-1, 1, 0, 0};&#10;    int dCol[] = {0, 0, -1, 1};&#10;    for(int i = 0; i &lt; 4; i++) {&#10;        int nr = r + dRow[i];&#10;        int nc = c + dCol[i];&#10;        if(nr &gt;= 0 &amp;&amp; nr &lt; mat.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; mat[0].size() &amp;&amp; mat[nr][nc] == 1) {&#10;            solve(mat, nr, nc, dr, dc, dist + 1);&#10;        }&#10;    }&#10;    mat[r][c] = 1; // unmark&#10;}&#10;int longestPath(vector&lt;vector&lt;int&gt;&gt; mat, int xs, int ys, int xd, int yd) {&#10;    if(mat[xs][ys] == 0 || mat[xd][yd] == 0) return -1;&#10;    maxDist = -1;&#10;    solve(mat, xs, ys, xd, yd, 0);&#10;    return maxDist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Rec 29 Find Shortest Safe Route In A Path With Landmines<br><br></b> <a href="https://www.geeksforgeeks.org/find-shortest-safe-route-in-a-path-with-landmines/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS or Backtracking.</td>
      <td><b>Time:</b> O(R * C)<br><b>Space:</b> O(R * C)</td>
      <td>First, mark all adjacent cells of landmines as unsafe. Then start from each cell in the first column and use BFS or Backtracking to find the shortest path to the last column, avoiding unsafe cells.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findShortestPath(vector&lt;vector&lt;int&gt;&gt; &amp;mat) {&#10;    int R = mat.size(), C = mat[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; grid(R, vector&lt;int&gt;(C, 1));&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int i = 0; i &lt; R; i++) {&#10;        for(int j = 0; j &lt; C; j++) {&#10;            if(mat[i][j] == 0) {&#10;                grid[i][j] = 0;&#10;                for(int k = 0; k &lt; 4; k++) {&#10;                    int nr = i + dr[k], nc = j + dc[k];&#10;                    if(nr &gt;= 0 &amp;&amp; nr &lt; R &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; C) grid[nr][nc] = 0;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    vector&lt;vector&lt;bool&gt;&gt; vis(R, vector&lt;bool&gt;(C, false));&#10;    for(int i = 0; i &lt; R; i++) {&#10;        if(grid[i][0] == 1) {&#10;            q.push({{i, 0}, 1});&#10;            vis[i][0] = true;&#10;        }&#10;    }&#10;    while(!q.empty()) {&#10;        auto curr = q.front(); q.pop();&#10;        int r = curr.first.first, c = curr.first.second, dist = curr.second;&#10;        if(c == C - 1) return dist;&#10;        for(int k = 0; k &lt; 4; k++) {&#10;            int nr = r + dr[k], nc = c + dc[k];&#10;            if(nr &gt;= 0 &amp;&amp; nr &lt; R &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; C &amp;&amp; grid[nr][nc] == 1 &amp;&amp; !vis[nr][nc]) {&#10;                vis[nr][nc] = true;&#10;                q.push({{nr, nc}, dist + 1});&#10;            }&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Rec 30 Combinational Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(2^N * K)<br><b>Space:</b> O(K * X)</td>
      <td>Sort the array and remove duplicates. Use backtracking. At each step, either include the current element (and stay at the current element to allow unlimited picks) or move to the next element. Backtrack when sum < 0 or we reach the end.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(vector&lt;int&gt;&amp; arr, int sum, int idx, vector&lt;int&gt;&amp; curr, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(sum == 0) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    if(sum &lt; 0 || idx == arr.size()) return;&#10;    curr.push_back(arr[idx]);&#10;    solve(arr, sum - arr[idx], idx, curr, ans);&#10;    curr.pop_back();&#10;    solve(arr, sum, idx + 1, curr, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; combinationSum(vector&lt;int&gt; &amp;A, int B) {&#10;    sort(A.begin(), A.end());&#10;    A.erase(unique(A.begin(), A.end()), A.end());&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; curr;&#10;    solve(A, B, 0, curr, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Rec 31 Find Maximum Number Possible By Doing At Most K Swaps<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(N! / (N-K)!)<br><b>Space:</b> O(N)</td>
      <td>Use backtracking to try swapping each digit with every digit that appears after it and is greater than it. Keep track of the maximum string seen so far. Prune if swaps == 0.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string str, int k, string&amp; maxStr, int idx) {&#10;    if(k == 0 || idx == str.length() - 1) return;&#10;    char maxChar = str[idx];&#10;    for(int i = idx + 1; i &lt; str.length(); i++) {&#10;        if(maxChar &lt; str[i]) maxChar = str[i];&#10;    }&#10;    if(maxChar != str[idx]) k--;&#10;    for(int i = str.length() - 1; i &gt;= idx; i--) {&#10;        if(str[i] == maxChar) {&#10;            swap(str[idx], str[i]);&#10;            if(str &gt; maxStr) maxStr = str;&#10;            solve(str, k, maxStr, idx + 1);&#10;            swap(str[idx], str[i]);&#10;        }&#10;    }&#10;}&#10;string findMaximumNum(string str, int k) {&#10;    string maxStr = str;&#10;    solve(str, k, maxStr, 0);&#10;    return maxStr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Rec 32 Find If There Is A Path Of More Than K Length From A Source<br><br></b> <a href="https://www.geeksforgeeks.org/find-if-there-is-a-path-of-more-than-k-length-from-a-source/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS Backtracking.</td>
      <td><b>Time:</b> O(V!)<br><b>Space:</b> O(V)</td>
      <td>Use Backtracking to perform DFS traversal from the source. Mark the current vertex as visited, subtract the edge weight from `k`, and recursively call for all adjacent unvisited vertices. If `k <= 0`, return true. Backtrack by unmarking the vertex.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool pathMoreThanK(int src, int k, vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt;&amp; adj, vector&lt;bool&gt;&amp; vis) {&#10;    if(k &lt;= 0) return true;&#10;    vis[src] = true;&#10;    for(auto i : adj[src]) {&#10;        int v = i.first, w = i.second;&#10;        if(!vis[v]) {&#10;            if(pathMoreThanK(v, k - w, adj, vis)) return true;&#10;        }&#10;    }&#10;    vis[src] = false;&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Rec 33 Longest Possible Route In A Matrix With Hurdles<br><br></b> <a href="https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(4^(M*N))<br><b>Space:</b> O(M*N)</td>
      <td>Use Backtracking. Start from the source, mark it as visited, recursively find the longest path from all valid unvisited adjacent cells, add 1 to the maximum among them. Unmark the cell after returning.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findLongestPath(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int i, int j, int di, int dj, int curr, int&amp; max_dist, vector&lt;vector&lt;bool&gt;&gt;&amp; vis) {&#10;    if(i == di &amp;&amp; j == dj) {&#10;        max_dist = max(max_dist, curr);&#10;        return;&#10;    }&#10;    vis[i][j] = true;&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int k = 0; k &lt; 4; k++) {&#10;        int nr = i + dr[k], nc = j + dc[k];&#10;        if(nr &gt;= 0 &amp;&amp; nr &lt; mat.size() &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; mat[0].size() &amp;&amp; mat[nr][nc] == 1 &amp;&amp; !vis[nr][nc]) {&#10;            findLongestPath(mat, nr, nc, di, dj, curr + 1, max_dist, vis);&#10;        }&#10;    }&#10;    vis[i][j] = false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Rec 34 Print All Possible Paths From Top Left To Bottom Right Of A Mxn Matrix<br><br></b> <a href="https://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(2^(M+N))<br><b>Space:</b> O(M+N)</td>
      <td>Use simple DFS from top-left. From cell (i, j), we can move to (i+1, j) or (i, j+1). Keep track of the path elements in an array/list. When reaching bottom-right, print/save the path.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findPaths(vector&lt;vector&lt;int&gt;&gt;&amp; mat, int i, int j, vector&lt;int&gt;&amp; path, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(i == mat.size() - 1 &amp;&amp; j == mat[0].size() - 1) {&#10;        path.push_back(mat[i][j]);&#10;        ans.push_back(path);&#10;        path.pop_back();&#10;        return;&#10;    }&#10;    path.push_back(mat[i][j]);&#10;    if(i + 1 &lt; mat.size()) findPaths(mat, i + 1, j, path, ans);&#10;    if(j + 1 &lt; mat[0].size()) findPaths(mat, i, j + 1, path, ans);&#10;    path.pop_back();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Rec 35 Word Break Problem Using Backtracking<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/word-break-part-23249/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from current index. For each prefix, if it is in the dictionary, add it to the current sentence string, add a space, and recur for the suffix. If we reach the end of the string, add the current sentence to the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(string&amp; s, int idx, string curr, unordered_set&lt;string&gt;&amp; dict, vector&lt;string&gt;&amp; ans) {&#10;    if(idx == s.length()) {&#10;        curr.pop_back(); // Remove last space&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    for(int i = idx; i &lt; s.length(); i++) {&#10;        string word = s.substr(idx, i - idx + 1);&#10;        if(dict.find(word) != dict.end()) {&#10;            solve(s, i + 1, curr + word + &quot; &quot;, dict, ans);&#10;        }&#10;    }&#10;}&#10;vector&lt;string&gt; wordBreak(int n, vector&lt;string&gt;&amp; dict, string s) {&#10;    unordered_set&lt;string&gt; st(dict.begin(), dict.end());&#10;    vector&lt;string&gt; ans;&#10;    solve(s, 0, &quot;&quot;, st, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Rec 36 Print 1 To N Without Loop<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a recursive function. Call `f(N-1)` first and then print `N`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printTillN(int N) {&#10;    if(N == 0) return;&#10;    printTillN(N - 1);&#10;    cout &lt;&lt; N &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Rec 37 Print N To 1 Without Loop<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-n-to-1-without-loop/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a recursive function. Print `N` first and then call `f(N-1)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printNos(int N) {&#10;    if(N == 0) return;&#10;    cout &lt;&lt; N &lt;&lt; &quot; &quot;;&#10;    printNos(N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Rec 38 Sum Of First N Terms<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Math or Recursion.</td>
      <td><b>Time:</b> O(1) Math, O(N) Recursion<br><b>Space:</b> O(1) Math, O(N) Recursion</td>
      <td>The mathematical formula for the sum of cubes is `(n * (n + 1) / 2)^2`. Alternatively, use recursion `f(n) = n^3 + f(n-1)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long sumOfSeries(long long n) {&#10;    return (n * (n + 1) / 2) * (n * (n + 1) / 2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Rec 39 Find All Factorial Numbers Less Than Or Equal To N<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(K) where K! <= N<br><b>Space:</b> O(K)</td>
      <td>Maintain a current factorial value and an index `i`. At each recursive step, compute the next factorial by multiplying by `i`. If the next factorial is `<= n`, add it to the list and recurse.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findFactorials(long long n, long long i, long long fact, vector&lt;long long&gt;&amp; ans) {&#10;    if(fact &gt; n) return;&#10;    ans.push_back(fact);&#10;    findFactorials(n, i + 1, fact * (i + 1), ans);&#10;}&#10;vector&lt;long long&gt; factorialNumbers(long long N) {&#10;    vector&lt;long long&gt; ans;&#10;    findFactorials(N, 1, 1, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Rec 40 Reverse An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-an-array/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion with two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) recursive stack</td>
      <td>Swap `arr[l]` and `arr[r]` and then recursively call `reverse(arr, l+1, r-1)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void reverseArray(vector&lt;int&gt;&amp; arr, int l, int r) {&#10;    if(l &gt;= r) return;&#10;    swap(arr[l], arr[r]);&#10;    reverseArray(arr, l + 1, r - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Rec 41 Fibonacci Number<br><br></b> <a href="https://leetcode.com/problems/fibonacci-number/" target="_blank">LeetCode 509</a></td>
      <td rowspan="1"><b>Example 1:</b> Base Case.</td>
      <td><b>Time:</b> O(2^N)<br><b>Space:</b> O(N)</td>
      <td>Return `fib(n-1) + fib(n-2)` with base cases `fib(0) = 0`, `fib(1) = 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int fib(int n) {&#10;    if(n &lt;= 1) return n;&#10;    return fib(n - 1) + fib(n - 2);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Rec 42 Count Good Numbers<br><br></b> <a href="https://leetcode.com/problems/count-good-numbers/" target="_blank">LeetCode 1922</a></td>
      <td rowspan="1"><b>Example 1:</b> Modular Exponentiation.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>There are 5 even digits and 4 prime digits. At even indices we have 5 choices. At odd indices we have 4 choices. If `n` is even, we have `n/2` even indices and `n/2` odd indices. So answer is `(5^(n/2) * 4^(n/2)) % mod`. If `n` is odd, we have `n/2 + 1` even indices. So answer is `(5^(n/2 + 1) * 4^(n/2)) % mod`. Use binary exponentiation.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long power(long long x, long long y) {&#10;    long long res = 1;&#10;    long long mod = 1e9 + 7;&#10;    x = x % mod;&#10;    while(y &gt; 0) {&#10;        if(y % 2 == 1) res = (res * x) % mod;&#10;        y = y / 2;&#10;        x = (x * x) % mod;&#10;    }&#10;    return res;&#10;}&#10;int countGoodNumbers(long long n) {&#10;    long long mod = 1e9 + 7;&#10;    long long evenIndices = (n + 1) / 2;&#10;    long long oddIndices = n / 2;&#10;    return (power(5, evenIndices) * power(4, oddIndices)) % mod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Rec 43 Sort A Stack Using Recursion<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sort-a-stack/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive sort and insert.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Recursively pop elements until the stack is empty. When returning from the recursive call, use another recursive function `sortedInsert` to insert the popped element into its correct sorted position in the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortedInsert(stack&lt;int&gt;&amp; s, int element) {&#10;    if(s.empty() || element &gt; s.top()) {&#10;        s.push(element);&#10;        return;&#10;    }&#10;    int num = s.top();&#10;    s.pop();&#10;    sortedInsert(s, element);&#10;    s.push(num);&#10;}&#10;void sortStack(stack&lt;int&gt;&amp; s) {&#10;    if(s.empty()) return;&#10;    int num = s.top();&#10;    s.pop();&#10;    sortStack(s);&#10;    sortedInsert(s, num);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Linked Lists

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
      <td rowspan="1">Ll 01 Reverse Linked List<br><br></b> <a href="https://leetcode.com/problems/reverse-linked-list/" target="_blank">LeetCode 206</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5]<br><b>Output:</b> [5,4,3,2,1]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Iterative approach: Maintain three pointers (`prev`, `curr`, `next_node`). Re-point `curr->next` to `prev` and slide forward.</td>
      <td><b>Edge Cases:</b> <b>Null List:</b> Automatically handled because the `while` loop checks `curr != NULL`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseList(ListNode* head) {&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* next_node = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next_node;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Ll 02 Middle Of The Linked List<br><br></b> <a href="https://leetcode.com/problems/middle-of-the-linked-list/" target="_blank">LeetCode 876</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5,6]<br><b>Output:</b> [4,5,6]</td>
      <td><b>Time:</b> O(N/2) &cong; O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Use a slow pointer (moves 1 step) and a fast pointer (moves 2 steps). When fast reaches the end, slow is exactly at the middle.</td>
      <td><b>Edge Cases:</b> <b>Even/Odd Length:</b> Loop condition `fast != NULL && fast->next != NULL` handles both.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* middleNode(ListNode* head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Ll 03 Linked List Cycle<br><br></b> <a href="https://leetcode.com/problems/linked-list-cycle/" target="_blank">LeetCode 141</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [3,2,0,-4], pos = 1<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Tortoise and Hare algorithm. If there is a cycle, the fast pointer will eventually "lap" and collide with the slow pointer.</td>
      <td><b>Edge Cases:</b> <b>No Cycle:</b> Handled if `fast == NULL` or `fast->next == NULL`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasCycle(ListNode *head) {&#10;    ListNode* slow = head;&#10;    ListNode* fast = head;&#10;    while(fast != nullptr &amp;&amp; fast-&gt;next != nullptr) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Ll 04 Merge Two Sorted Lists<br><br></b> <a href="https://leetcode.com/problems/merge-two-sorted-lists/" target="_blank">LeetCode 21</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> list1 = [1,2,4], list2 = [1,3,4]<br><b>Output:</b> [1,1,2,3,4,4]</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Use a dummy node to easily handle the head of the new list. Compare `list1` and `list2`, attaching the smaller node to `tail`.</td>
      <td><b>Edge Cases:</b> <b>Leftover Nodes:</b> When one list exhausts, directly attach the entirety of the other list via `tail->next = list1 ? list1 : list2`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) {&#10;            tail-&gt;next = list1;&#10;            list1 = list1-&gt;next;&#10;        } else {&#10;            tail-&gt;next = list2;&#10;            list2 = list2-&gt;next;&#10;        }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    ListNode* res = dummy-&gt;next;&#10;    delete dummy;&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Ll 05 Remove Nth Node From End Of List<br><br></b> <a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list/" target="_blank">LeetCode 19</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5], n = 2<br><b>Output:</b> [1,2,3,5]</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Two-pointer approach. Move `fast` pointer `n` steps ahead. Then move both `slow` and `fast` until `fast` reaches the end. `slow` will be right before the target node.</td>
      <td><b>Edge Cases:</b> <b>Remove Head:</b> If `fast` becomes NULL after moving `n` steps, it means the head needs to be removed. Return `head->next`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* removeNthFromEnd(ListNode* head, int n) {&#10;    ListNode* fast = head;&#10;    ListNode* slow = head;&#10;    for(int i = 0; i &lt; n; i++) fast = fast-&gt;next;&#10;    if(!fast) return head-&gt;next;&#10;    while(fast-&gt;next) {&#10;        fast = fast-&gt;next;&#10;        slow = slow-&gt;next;&#10;    }&#10;    ListNode* delNode = slow-&gt;next;&#10;    slow-&gt;next = slow-&gt;next-&gt;next;&#10;    delete delNode;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Ll 06 Add Two Numbers<br><br></b> <a href="https://leetcode.com/problems/add-two-numbers/" target="_blank">LeetCode 2</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> l1 = [2,4,3], l2 = [5,6,4]<br><b>Output:</b> [7,0,8]</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td>Iterate through both lists, keeping a `carry`. Create new nodes for the `sum % 10`.</td>
      <td><b>Edge Cases:</b> <b>Leftover Carry:</b> After the loop, if `carry > 0`, we must append one last node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    ListNode* dummy = new ListNode();&#10;    ListNode* temp = dummy;&#10;    int carry = 0;&#10;    while(l1 || l2 || carry) {&#10;        int sum = carry;&#10;        if(l1) { sum += l1-&gt;val; l1 = l1-&gt;next; }&#10;        if(l2) { sum += l2-&gt;val; l2 = l2-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new ListNode(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Ll 07 Intersection Of Two Linked Lists<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-linked-lists/" target="_blank">LeetCode 160</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3<br><b>Output:</b> Intersected at '8'</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Two pointers `a` and `b`. Traverse `A` then `B`, and `B` then `A`. They will meet at the intersection node or `NULL`.</td>
      <td><b>Edge Cases:</b> <b>No Intersection:</b> If no intersection, both pointers will simultaneously hit `NULL` at the end of their second traversal.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {&#10;    ListNode *a = headA, *b = headB;&#10;    while(a != b) {&#10;        a = a ? a-&gt;next : headB;&#10;        b = b ? b-&gt;next : headA;&#10;    }&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Ll 08 Reverse Nodes In K Group<br><br></b> <a href="https://leetcode.com/problems/reverse-nodes-in-k-group/" target="_blank">LeetCode 25</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5], k = 2<br><b>Output:</b> [2,1,4,3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Find length of list. Traverse groups of size k. For each group, perform standard linked list reversal. Link the prev group's tail to the current reversed head.</td>
      <td><b>Edge Cases:</b> <b>Remaining nodes < K:</b> The loop terminates early, leaving the remaining list intact.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseKGroup(ListNode* head, int k) {&#10;    if(!head || k==1) return head;&#10;    int count = 0; ListNode* dummy = new ListNode(0); dummy-&gt;next = head;&#10;    ListNode *cur = head, *nex, *pre = dummy;&#10;    while(cur) { count++; cur = cur-&gt;next; }&#10;    while(count &gt;= k) {&#10;        cur = pre-&gt;next;&#10;        nex = cur-&gt;next;&#10;        for(int i=1; i&lt;k; i++) {&#10;            cur-&gt;next = nex-&gt;next;&#10;            nex-&gt;next = pre-&gt;next;&#10;            pre-&gt;next = nex;&#10;            nex = cur-&gt;next;&#10;        }&#10;        pre = cur;&#10;        count -= k;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Ll 09 Copy List With Random Pointer<br><br></b> <a href="https://leetcode.com/problems/copy-list-with-random-pointer/" target="_blank">LeetCode 138</a></td>
      <td rowspan="1"><b>Example 1:</b> Return a deep copy.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>3 Steps O(1) space. 1) Insert copy nodes right after original nodes. 2) Set random pointers for copy nodes: `iter->next->random = iter->random ? iter->random->next : NULL`. 3) Separate the two lists.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* copyRandomList(Node* head) {&#10;    if(!head) return NULL;&#10;    Node* iter = head;&#10;    while(iter) {&#10;        Node* copy = new Node(iter-&gt;val);&#10;        copy-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = copy;&#10;        iter = copy-&gt;next;&#10;    }&#10;    iter = head;&#10;    while(iter) {&#10;        if(iter-&gt;random) iter-&gt;next-&gt;random = iter-&gt;random-&gt;next;&#10;        iter = iter-&gt;next-&gt;next;&#10;    }&#10;    iter = head; Node* pseudoHead = new Node(0);&#10;    Node* copyIter = pseudoHead;&#10;    while(iter) {&#10;        Node* nextIter = iter-&gt;next-&gt;next;&#10;        copyIter-&gt;next = iter-&gt;next;&#10;        iter-&gt;next = nextIter;&#10;        copyIter = copyIter-&gt;next;&#10;        iter = nextIter;&#10;    }&#10;    return pseudoHead-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Ll 10 Rotate List<br><br></b> <a href="https://leetcode.com/problems/rotate-list/" target="_blank">LeetCode 61</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5], k = 2<br><b>Output:</b> [4,5,1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Compute the length of the list, and make it a circular list by connecting the last node to head. Then find the new break point `(length - k % length)`. Break the circle and return the new head.</td>
      <td><b>Edge Cases:</b> <b>k = 0 or empty list:</b> Return head immediately.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* rotateRight(ListNode* head, int k) {&#10;    if(!head || !head-&gt;next || k == 0) return head;&#10;    int len = 1;&#10;    ListNode* cur = head;&#10;    while(cur-&gt;next) {&#10;        len++;&#10;        cur = cur-&gt;next;&#10;    }&#10;    cur-&gt;next = head;&#10;    k = k % len;&#10;    k = len - k;&#10;    while(k--) cur = cur-&gt;next;&#10;    head = cur-&gt;next;&#10;    cur-&gt;next = NULL;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Ll 11 Flattening A Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursively merge.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N)</td>
      <td>Recursively flatten the `next` list, then merge the current list (`bottom` pointers) with the flattened `next` list, similar to merging two sorted linked lists.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* mergeTwoLists(Node* a, Node* b) {&#10;    Node* temp = new Node(0);&#10;    Node* res = temp;&#10;    while(a != NULL &amp;&amp; b != NULL) {&#10;        if(a-&gt;data &lt; b-&gt;data) { temp-&gt;bottom = a; temp = temp-&gt;bottom; a = a-&gt;bottom; }&#10;        else { temp-&gt;bottom = b; temp = temp-&gt;bottom; b = b-&gt;bottom; }&#10;    }&#10;    if(a) temp-&gt;bottom = a;&#10;    else temp-&gt;bottom = b;&#10;    return res-&gt;bottom;&#10;}&#10;Node *flatten(Node *root) {&#10;    if(root == NULL || root-&gt;next == NULL) return root;&#10;    root-&gt;next = flatten(root-&gt;next);&#10;    root = mergeTwoLists(root, root-&gt;next);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Ll 12 Sort A Linked List<br><br></b> <a href="https://leetcode.com/problems/sort-list/" target="_blank">LeetCode 148</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [4,2,1,3]<br><b>Output:</b> [1,2,3,4]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(log N)</td>
      <td>Merge Sort. Use fast/slow pointers to find the middle of the linked list. Split into two halves, recursively sort both halves, then merge the two sorted halves.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {&#10;    ListNode dummy(0);&#10;    ListNode* tail = &amp;dummy;&#10;    while(list1 &amp;&amp; list2) {&#10;        if(list1-&gt;val &lt; list2-&gt;val) { tail-&gt;next = list1; list1 = list1-&gt;next; }&#10;        else { tail-&gt;next = list2; list2 = list2-&gt;next; }&#10;        tail = tail-&gt;next;&#10;    }&#10;    tail-&gt;next = list1 ? list1 : list2;&#10;    return dummy.next;&#10;}&#10;ListNode* sortList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *slow = head, *fast = head-&gt;next;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    ListNode* mid = slow-&gt;next;&#10;    slow-&gt;next = NULL;&#10;    return mergeTwoLists(sortList(head), sortList(mid));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Ll 13 Find Pairs With Given Sum In Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointer approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Since it is a sorted DLL, set one pointer at the head and one at the tail. If sum == x, add to result and move both. If sum < x, move left pointer next. Else, move right pointer prev.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;pair&lt;int, int&gt;&gt; findPairsWithGivenSum(Node *head, int target) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; ans;&#10;    if(head == NULL) return ans;&#10;    Node* left = head;&#10;    Node* right = head;&#10;    while(right-&gt;next != NULL) right = right-&gt;next;&#10;    while(left != NULL &amp;&amp; right != NULL &amp;&amp; left-&gt;data &lt; right-&gt;data) {&#10;        if(left-&gt;data + right-&gt;data == target) {&#10;            ans.push_back({left-&gt;data, right-&gt;data});&#10;            left = left-&gt;next;&#10;            right = right-&gt;prev;&#10;        } else if(left-&gt;data + right-&gt;data &lt; target) {&#10;            left = left-&gt;next;&#10;        } else {&#10;            right = right-&gt;prev;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Ll 14 Remove Duplicates From Sorted Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Skip duplicates.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the DLL. While `next` node has the same value, bypass it by updating `curr->next` and `curr->next->prev`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node * removeDuplicates(struct Node *head) {&#10;    Node* curr = head;&#10;    while(curr != NULL) {&#10;        Node* nextNode = curr-&gt;next;&#10;        while(nextNode != NULL &amp;&amp; nextNode-&gt;data == curr-&gt;data) {&#10;            nextNode = nextNode-&gt;next;&#10;        }&#10;        curr-&gt;next = nextNode;&#10;        if(nextNode != NULL) nextNode-&gt;prev = curr;&#10;        curr = curr-&gt;next;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Ll 15 Reverse A Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Swap prev and next.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the DLL. For each node, swap its `prev` and `next` pointers. The new head will be the last node processed.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseDLL(Node * head) {&#10;    if(head == NULL || head-&gt;next == NULL) return head;&#10;    Node* curr = head;&#10;    Node* temp = NULL;&#10;    while(curr != NULL) {&#10;        temp = curr-&gt;prev;&#10;        curr-&gt;prev = curr-&gt;next;&#10;        curr-&gt;next = temp;&#10;        curr = curr-&gt;prev;&#10;    }&#10;    return temp-&gt;prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Ll 16 Delete All Occurrences Of A Key In Dll<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Update links.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the list. If `node->data == x`, update the `next` pointer of `node->prev` and `prev` pointer of `node->next`. If the node is head, update head.</td>
      <td><b>Edge Cases:</b> <b>Head deletion:</b> handled by reassigning head pointer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void deleteAllOccurOfX(struct Node** head_ref, int x) {&#10;    Node* curr = *head_ref;&#10;    while(curr != NULL) {&#10;        if(curr-&gt;data == x) {&#10;            if(curr == *head_ref) *head_ref = curr-&gt;next;&#10;            if(curr-&gt;prev != NULL) curr-&gt;prev-&gt;next = curr-&gt;next;&#10;            if(curr-&gt;next != NULL) curr-&gt;next-&gt;prev = curr-&gt;prev;&#10;            Node* toDelete = curr;&#10;            curr = curr-&gt;next;&#10;            free(toDelete);&#10;        } else {&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Ll 17 Swap Nodes In Pairs<br><br></b> <a href="https://leetcode.com/problems/swap-nodes-in-pairs/" target="_blank">LeetCode 24</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4]<br><b>Output:</b> [2,1,4,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a dummy node. Iteratively swap `curr` and `curr->next`. Keep track of `prev` to link the swapped pairs to the rest of the list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* swapPairs(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    dummy-&gt;next = head;&#10;    ListNode* prev = dummy;&#10;    while(prev-&gt;next != NULL &amp;&amp; prev-&gt;next-&gt;next != NULL) {&#10;        ListNode* first = prev-&gt;next;&#10;        ListNode* second = prev-&gt;next-&gt;next;&#10;        first-&gt;next = second-&gt;next;&#10;        second-&gt;next = first;&#10;        prev-&gt;next = second;&#10;        prev = first;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Ll 18 Odd Even Linked List<br><br></b> <a href="https://leetcode.com/problems/odd-even-linked-list/" target="_blank">LeetCode 328</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> head = [1,2,3,4,5]<br><b>Output:</b> [1,3,5,2,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain two pointers `odd` and `even`. Keep the `evenHead`. Loop to link `odd->next = even->next` and `even->next = odd->next`. Finally, link `odd->next = evenHead`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* oddEvenList(ListNode* head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    ListNode *odd = head, *even = head-&gt;next, *evenHead = even;&#10;    while(even &amp;&amp; even-&gt;next) {&#10;        odd-&gt;next = odd-&gt;next-&gt;next;&#10;        even-&gt;next = even-&gt;next-&gt;next;&#10;        odd = odd-&gt;next;&#10;        even = even-&gt;next;&#10;    }&#10;    odd-&gt;next = evenHead;&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Ll 19 Split Linked List In Parts<br><br></b> <a href="https://leetcode.com/problems/split-linked-list-in-parts/" target="_blank">LeetCode 725</a></td>
      <td rowspan="1"><b>Example 1:</b> Distribution math.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>First, calculate the length of the list. Then, determine base size `len / k` and extra nodes `len % k`. Iterate through the list, breaking it into parts of appropriate sizes.</td>
      <td><b>Edge Cases:</b> <b>k > length:</b> Fill remaining parts with null.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;ListNode*&gt; splitListToParts(ListNode* head, int k) {&#10;    int len = 0;&#10;    ListNode* curr = head;&#10;    while(curr) { len++; curr = curr-&gt;next; }&#10;    int partSize = len / k, extra = len % k;&#10;    vector&lt;ListNode*&gt; ans;&#10;    curr = head;&#10;    for(int i=0; i&lt;k; i++) {&#10;        ans.push_back(curr);&#10;        int currentPartSize = partSize + (extra &gt; 0 ? 1 : 0);&#10;        extra--;&#10;        for(int j=0; j&lt;currentPartSize - 1; j++) {&#10;            if(curr) curr = curr-&gt;next;&#10;        }&#10;        if(curr) {&#10;            ListNode* nextPart = curr-&gt;next;&#10;            curr-&gt;next = NULL;&#10;            curr = nextPart;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Ll 20 Add Two Numbers II<br><br></b> <a href="https://leetcode.com/problems/add-two-numbers-ii/" target="_blank">LeetCode 445</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack or reverse.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td>Use two stacks to store the digits of the lists. Pop from stacks, add along with carry, and construct the new list by inserting at the head.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {&#10;    stack&lt;int&gt; s1, s2;&#10;    while(l1) { s1.push(l1-&gt;val); l1 = l1-&gt;next; }&#10;    while(l2) { s2.push(l2-&gt;val); l2 = l2-&gt;next; }&#10;    int carry = 0;&#10;    ListNode* head = NULL;&#10;    while(!s1.empty() || !s2.empty() || carry) {&#10;        int sum = carry;&#10;        if(!s1.empty()) { sum += s1.top(); s1.pop(); }&#10;        if(!s2.empty()) { sum += s2.top(); s2.pop(); }&#10;        ListNode* node = new ListNode(sum % 10);&#10;        node-&gt;next = head;&#10;        head = node;&#10;        carry = sum / 10;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Ll 21 Insertion Sort List<br><br></b> <a href="https://leetcode.com/problems/insertion-sort-list/" target="_blank">LeetCode 147</a></td>
      <td rowspan="1"><b>Example 1:</b> Dummy head.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>Use a dummy head for the sorted part. For each node in the original list, iterate through the sorted part to find its correct position and insert it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* insertionSortList(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* curr = head;&#10;    while(curr) {&#10;        ListNode* prev = dummy;&#10;        while(prev-&gt;next &amp;&amp; prev-&gt;next-&gt;val &lt;= curr-&gt;val) {&#10;            prev = prev-&gt;next;&#10;        }&#10;        ListNode* next = curr-&gt;next;&#10;        curr-&gt;next = prev-&gt;next;&#10;        prev-&gt;next = curr;&#10;        curr = next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Ll 22 Partition List<br><br></b> <a href="https://leetcode.com/problems/partition-list/" target="_blank">LeetCode 86</a></td>
      <td rowspan="1"><b>Example 1:</b> Two lists then join.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain two separate linked lists: `before` and `after` with their own dummy heads. Iterate through original list, appending to `before` or `after` based on value. Then link `before` tail to `after` head.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* partition(ListNode* head, int x) {&#10;    ListNode* before_head = new ListNode(0);&#10;    ListNode* before = before_head;&#10;    ListNode* after_head = new ListNode(0);&#10;    ListNode* after = after_head;&#10;    while(head) {&#10;        if(head-&gt;val &lt; x) {&#10;            before-&gt;next = head;&#10;            before = before-&gt;next;&#10;        } else {&#10;            after-&gt;next = head;&#10;            after = after-&gt;next;&#10;        }&#10;        head = head-&gt;next;&#10;    }&#10;    after-&gt;next = NULL;&#10;    before-&gt;next = after_head-&gt;next;&#10;    return before_head-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Ll 23 Reverse Nodes In Even Length Groups<br><br></b> <a href="https://leetcode.com/problems/reverse-nodes-in-even-length-groups/" target="_blank">LeetCode 2074</a></td>
      <td rowspan="1"><b>Example 1:</b> Group tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the list while tracking the expected group length. First, count the actual number of nodes left in the current group. If the count is even, reverse this sublist and connect it to the previous part. If odd, just skip. Update lengths and pointers.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* reverseEvenLengthGroups(ListNode* head) {&#10;    int groupLen = 1;&#10;    ListNode* prev = nullptr;&#10;    ListNode* curr = head;&#10;    while(curr != nullptr) {&#10;        ListNode* temp = curr;&#10;        int count = 0;&#10;        while(count &lt; groupLen &amp;&amp; temp != nullptr) {&#10;            temp = temp-&gt;next;&#10;            count++;&#10;        }&#10;        if(count % 2 == 0) {&#10;            ListNode* groupPrev = nullptr;&#10;            ListNode* groupCurr = curr;&#10;            ListNode* nextNode = nullptr;&#10;            for(int i=0; i&lt;count; i++) {&#10;                nextNode = groupCurr-&gt;next;&#10;                groupCurr-&gt;next = groupPrev;&#10;                groupPrev = groupCurr;&#10;                groupCurr = nextNode;&#10;            }&#10;            prev-&gt;next = groupPrev;&#10;            curr-&gt;next = groupCurr;&#10;            prev = curr;&#10;            curr = groupCurr;&#10;        } else {&#10;            for(int i=0; i&lt;count; i++) {&#10;                prev = curr;&#10;                curr = curr-&gt;next;&#10;            }&#10;        }&#10;        groupLen++;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Ll 24 Swapping Nodes In A Linked List<br><br></b> <a href="https://leetcode.com/problems/swapping-nodes-in-a-linked-list/" target="_blank">LeetCode 1721</a></td>
      <td rowspan="1"><b>Example 1:</b> Two passes or three pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers. Move `fast` pointer `k-1` steps. `first_node` is at `fast`. Initialize `slow = head`. Move both `slow` and `fast` to the end. `slow` will be at `second_node`. Swap values.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* swapNodes(ListNode* head, int k) {&#10;    ListNode* fast = head;&#10;    for(int i=1; i&lt;k; i++) fast = fast-&gt;next;&#10;    ListNode* firstNode = fast;&#10;    ListNode* slow = head;&#10;    while(fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next;&#10;    }&#10;    swap(firstNode-&gt;val, slow-&gt;val);&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Ll 25 Merge Nodes In Between Zeros<br><br></b> <a href="https://leetcode.com/problems/merge-nodes-in-between-zeros/" target="_blank">LeetCode 2181</a></td>
      <td rowspan="1"><b>Example 1:</b> Accumulate and connect.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) extra space if we modify in-place</td>
      <td>Maintain a dummy node. Traverse the list. Maintain a running sum. When we encounter a 0 (and sum > 0), create a new node with `sum`, attach it to dummy list, reset `sum` to 0.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">ListNode* mergeNodes(ListNode* head) {&#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* currDummy = dummy;&#10;    ListNode* curr = head-&gt;next;&#10;    int sum = 0;&#10;    while(curr) {&#10;        if(curr-&gt;val == 0) {&#10;            currDummy-&gt;next = new ListNode(sum);&#10;            currDummy = currDummy-&gt;next;&#10;            sum = 0;&#10;        } else {&#10;            sum += curr-&gt;val;&#10;        }&#10;        curr = curr-&gt;next;&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Ll 26 Design Hashmap<br><br></b> <a href="https://leetcode.com/problems/design-hashmap/" target="_blank">LeetCode 706</a></td>
      <td rowspan="1"><b>Example 1:</b> Array of Linked Lists with Key-Value pairs.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(Number of elements)</td>
      <td>Similar to HashSet, but each node stores a `(key, value)` pair. On Put, if key exists, update value. Else insert new node. On Get, return value if key found, else -1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MyHashMap {&#10;    struct Node {&#10;        int key, val;&#10;        Node* next;&#10;        Node(int k, int v): key(k), val(v), next(nullptr) {}&#10;    };&#10;    vector&lt;Node*&gt; buckets;&#10;    int size = 10007;&#10;public:&#10;    MyHashMap() {&#10;        buckets.assign(size, nullptr);&#10;    }&#10;    void put(int key, int value) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        while(curr) {&#10;            if(curr-&gt;key == key) { curr-&gt;val = value; return; }&#10;            curr = curr-&gt;next;&#10;        }&#10;        Node* newNode = new Node(key, value);&#10;        newNode-&gt;next = buckets[idx];&#10;        buckets[idx] = newNode;&#10;    }&#10;    int get(int key) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        while(curr) {&#10;            if(curr-&gt;key == key) return curr-&gt;val;&#10;            curr = curr-&gt;next;&#10;        }&#10;        return -1;&#10;    }&#10;    void remove(int key) {&#10;        int idx = key % size;&#10;        Node* curr = buckets[idx];&#10;        Node* prev = nullptr;&#10;        while(curr) {&#10;            if(curr-&gt;key == key) {&#10;                if(prev) prev-&gt;next = curr-&gt;next;&#10;                else buckets[idx] = curr-&gt;next;&#10;                delete curr;&#10;                return;&#10;            }&#10;            prev = curr;&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Ll 27 Design Browser History<br><br></b> <a href="https://leetcode.com/problems/design-browser-history/" target="_blank">LeetCode 1472</a></td>
      <td rowspan="1"><b>Example 1:</b> Doubly Linked List.</td>
      <td><b>Time:</b> O(1) visit, O(steps) back/forward<br><b>Space:</b> O(N) for URLs</td>
      <td>Use a Doubly Linked List. Each visit creates a new node, clearing forward history. Back and forward operations just traverse the pointers up to `steps` times.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BrowserHistory {&#10;    struct Node {&#10;        string url;&#10;        Node *prev, *next;&#10;        Node(string u): url(u), prev(nullptr), next(nullptr) {}&#10;    };&#10;    Node* curr;&#10;public:&#10;    BrowserHistory(string homepage) {&#10;        curr = new Node(homepage);&#10;    }&#10;    void visit(string url) {&#10;        Node* newNode = new Node(url);&#10;        curr-&gt;next = newNode;&#10;        newNode-&gt;prev = curr;&#10;        curr = newNode;&#10;    }&#10;    string back(int steps) {&#10;        while(steps &gt; 0 &amp;&amp; curr-&gt;prev) {&#10;            curr = curr-&gt;prev;&#10;            steps--;&#10;        }&#10;        return curr-&gt;url;&#10;    }&#10;    string forward(int steps) {&#10;        while(steps &gt; 0 &amp;&amp; curr-&gt;next) {&#10;            curr = curr-&gt;next;&#10;            steps--;&#10;        }&#10;        return curr-&gt;url;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Ll 28 Lru Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lru-cache/" target="_blank">LeetCode 146</a></td>
      <td rowspan="1"><b>Example 1:</b> Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td>Included for chapter coverage completeness. See sq_31_lru_cache.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Ll 29 Lfu Cache Ll<br><br></b> <a href="https://leetcode.com/problems/lfu-cache/" target="_blank">LeetCode 460</a></td>
      <td rowspan="1"><b>Example 1:</b> Duplicate logic entry to ensure coverage.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(N)</td>
      <td>Included for chapter coverage completeness. See sq_32_lfu_cache.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// See Stacks and Queues module for full implementation.</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Ll 30 All Oone Data Structure<br><br></b> <a href="https://leetcode.com/problems/all-oone-data-structure/" target="_blank">LeetCode 432</a></td>
      <td rowspan="1"><b>Example 1:</b> Doubly linked list of frequency buckets.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td>Maintain a DLL where each node represents a specific frequency and contains a set of strings. Use a hash map mapping strings to their current bucket. On inc/dec, move the string to the adjacent bucket (create if necessary). Max is tail->prev, Min is head->next.<br><br><b>Dependencies:</b> <code>#include <unordered_set>\n#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class AllOne {&#10;    struct Bucket {&#10;        int count;&#10;        unordered_set&lt;string&gt; keys;&#10;        Bucket *prev, *next;&#10;        Bucket(int c): count(c), prev(nullptr), next(nullptr) {}&#10;    };&#10;    Bucket *head, *tail;&#10;    unordered_map&lt;string, Bucket*&gt; m;&#10;    void addBucket(Bucket* prev, Bucket* newBucket) {&#10;        newBucket-&gt;prev = prev;&#10;        newBucket-&gt;next = prev-&gt;next;&#10;        prev-&gt;next-&gt;prev = newBucket;&#10;        prev-&gt;next = newBucket;&#10;    }&#10;    void removeBucket(Bucket* bucket) {&#10;        bucket-&gt;prev-&gt;next = bucket-&gt;next;&#10;        bucket-&gt;next-&gt;prev = bucket-&gt;prev;&#10;        delete bucket;&#10;    }&#10;public:&#10;    AllOne() {&#10;        head = new Bucket(0); tail = new Bucket(0);&#10;        head-&gt;next = tail; tail-&gt;prev = head;&#10;    }&#10;    void inc(string key) {&#10;        if(m.find(key) != m.end()) {&#10;            Bucket* curr = m[key];&#10;            Bucket* nxt = curr-&gt;next;&#10;            if(nxt == tail || nxt-&gt;count != curr-&gt;count + 1) {&#10;                addBucket(curr, new Bucket(curr-&gt;count + 1));&#10;                nxt = curr-&gt;next;&#10;            }&#10;            nxt-&gt;keys.insert(key);&#10;            m[key] = nxt;&#10;            curr-&gt;keys.erase(key);&#10;            if(curr-&gt;keys.empty()) removeBucket(curr);&#10;        } else {&#10;            Bucket* nxt = head-&gt;next;&#10;            if(nxt == tail || nxt-&gt;count != 1) {&#10;                addBucket(head, new Bucket(1));&#10;                nxt = head-&gt;next;&#10;            }&#10;            nxt-&gt;keys.insert(key);&#10;            m[key] = nxt;&#10;        }&#10;    }&#10;    void dec(string key) {&#10;        Bucket* curr = m[key];&#10;        if(curr-&gt;count == 1) {&#10;            m.erase(key);&#10;        } else {&#10;            Bucket* prv = curr-&gt;prev;&#10;            if(prv == head || prv-&gt;count != curr-&gt;count - 1) {&#10;                addBucket(curr-&gt;prev, new Bucket(curr-&gt;count - 1));&#10;                prv = curr-&gt;prev;&#10;            }&#10;            prv-&gt;keys.insert(key);&#10;            m[key] = prv;&#10;        }&#10;        curr-&gt;keys.erase(key);&#10;        if(curr-&gt;keys.empty()) removeBucket(curr);&#10;    }&#10;    string getMaxKey() {&#10;        if(tail-&gt;prev == head) return &quot;&quot;;&#10;        return *(tail-&gt;prev-&gt;keys.begin());&#10;    }&#10;    string getMinKey() {&#10;        if(head-&gt;next == tail) return &quot;&quot;;&#10;        return *(head-&gt;next-&gt;keys.begin());&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Ll 31 Flatten A Multilevel Doubly Linked List<br><br></b> <a href="https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/" target="_blank">LeetCode 430</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS / Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the list. When a node has a child, find the tail of the child list. Connect the tail to `node->next`, and `node->next` to the child. Update `prev` pointers. Set `node->child` to `nullptr`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">/*&#10;// Definition for a Node.&#10;class Node {&#10;public:&#10;    int val;&#10;    Node* prev;&#10;    Node* next;&#10;    Node* child;&#10;};&#10;*/&#10;Node* flatten(Node* head) {&#10;    if(!head) return nullptr;&#10;    Node* curr = head;&#10;    while(curr) {&#10;        if(curr-&gt;child) {&#10;            Node* tail = curr-&gt;child;&#10;            while(tail-&gt;next) tail = tail-&gt;next;&#10;            tail-&gt;next = curr-&gt;next;&#10;            if(curr-&gt;next) curr-&gt;next-&gt;prev = tail;&#10;            curr-&gt;next = curr-&gt;child;&#10;            curr-&gt;child-&gt;prev = curr;&#10;            curr-&gt;child = nullptr;&#10;        }&#10;        curr = curr-&gt;next;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Ll 32 Multiply Two Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Traverse and compute numbers.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Traverse the first linked list and compute the number it represents modulo 10^9+7. Do the same for the second linked list. Multiply the two numbers and return the result modulo 10^9+7.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long multiplyTwoLists(Node *l1, Node *l2) {&#10;    long long num1 = 0, num2 = 0;&#10;    long long mod = 1e9 + 7;&#10;    while(l1) {&#10;        num1 = (num1 * 10 + l1-&gt;data) % mod;&#10;        l1 = l1-&gt;next;&#10;    }&#10;    while(l2) {&#10;        num2 = (num2 * 10 + l2-&gt;data) % mod;&#10;        l2 = l2-&gt;next;&#10;    }&#10;    return (num1 * num2) % mod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Ll 33 Delete Nodes Having Greater Value On Right<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Reverse, filter, reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Reverse the linked list. Traverse the reversed list and keep track of the maximum value seen so far. If a node's value is less than the maximum, delete it. Otherwise, update the maximum. Finally, reverse the list again.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseList(Node* head) {&#10;    Node* prev = NULL, *curr = head, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;Node *compute(Node *head) {&#10;    head = reverseList(head);&#10;    Node* curr = head;&#10;    int max_val = head-&gt;data;&#10;    while(curr &amp;&amp; curr-&gt;next) {&#10;        if(curr-&gt;next-&gt;data &lt; max_val) {&#10;            Node* temp = curr-&gt;next;&#10;            curr-&gt;next = temp-&gt;next;&#10;            delete temp;&#10;        } else {&#10;            curr = curr-&gt;next;&#10;            max_val = curr-&gt;data;&#10;        }&#10;    }&#10;    return reverseList(head);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Ll 34 Segregate Even And Odd Nodes In A Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers for even and odd.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Create two dummy nodes, one for the even list and one for the odd list. Traverse the original list and append even nodes to the even list and odd nodes to the odd list. Finally, connect the end of the even list to the head of the odd list and terminate the odd list with NULL.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* divide(int N, Node *head) {&#10;    Node* evenStart = NULL, *evenEnd = NULL;&#10;    Node* oddStart = NULL, *oddEnd = NULL;&#10;    Node* curr = head;&#10;    while(curr) {&#10;        int val = curr-&gt;data;&#10;        if(val % 2 == 0) {&#10;            if(!evenStart) { evenStart = curr; evenEnd = evenStart; }&#10;            else { evenEnd-&gt;next = curr; evenEnd = evenEnd-&gt;next; }&#10;        } else {&#10;            if(!oddStart) { oddStart = curr; oddEnd = oddStart; }&#10;            else { oddEnd-&gt;next = curr; oddEnd = oddEnd-&gt;next; }&#10;        }&#10;        curr = curr-&gt;next;&#10;    }&#10;    if(!oddStart || !evenStart) return head;&#10;    evenEnd-&gt;next = oddStart;&#10;    oddEnd-&gt;next = NULL;&#10;    return evenStart;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Ll 35 Nth Node From End Of Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers, `fast` and `slow`. Move `fast` `N` steps ahead. If `fast` becomes NULL before `N` steps, return -1 (N > length). Then move both `fast` and `slow` one step at a time until `fast` reaches the end. `slow` will be pointing to the Nth node from the end.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getNthFromLast(Node *head, int n) {&#10;    Node* fast = head;&#10;    Node* slow = head;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(!fast) return -1;&#10;        fast = fast-&gt;next;&#10;    }&#10;    while(fast) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next;&#10;    }&#10;    return slow-&gt;data;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Ll 36 First Non Repeating Character In A Stream<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Queue and frequency array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a queue to maintain the order of characters and an array to keep track of their frequencies. For each character, increment its frequency and push it to the queue. Then, while the queue is not empty and the frequency of the front character is greater than 1, pop it. If the queue is empty, append '#', else append the front character.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string FirstNonRepeating(string A) {&#10;    vector&lt;int&gt; freq(26, 0);&#10;    queue&lt;char&gt; q;&#10;    string res = &quot;&quot;;&#10;    for(char c : A) {&#10;        freq[c - &#x27;a&#x27;]++;&#10;        q.push(c);&#10;        while(!q.empty() &amp;&amp; freq[q.front() - &#x27;a&#x27;] &gt; 1) q.pop();&#10;        if(q.empty()) res += &#x27;#&#x27;;&#10;        else res += q.front();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Ll 37 Clone A Linked List With Next And Random Pointer<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Interleaving lists.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Create a copy of each node and insert it immediately after the original node. Then, set the random pointers for the copied nodes (`curr->next->arb = curr->arb ? curr->arb->next : NULL`). Finally, separate the original and copied lists.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node *copyList(Node *head) {&#10;    if(!head) return NULL;&#10;    Node* curr = head;&#10;    while(curr) {&#10;        Node* temp = new Node(curr-&gt;data);&#10;        temp-&gt;next = curr-&gt;next;&#10;        curr-&gt;next = temp;&#10;        curr = temp-&gt;next;&#10;    }&#10;    curr = head;&#10;    while(curr) {&#10;        if(curr-&gt;arb) curr-&gt;next-&gt;arb = curr-&gt;arb-&gt;next;&#10;        curr = curr-&gt;next-&gt;next;&#10;    }&#10;    curr = head;&#10;    Node* copyHead = head-&gt;next, *copyCurr = copyHead;&#10;    while(curr) {&#10;        curr-&gt;next = curr-&gt;next-&gt;next;&#10;        if(copyCurr-&gt;next) copyCurr-&gt;next = copyCurr-&gt;next-&gt;next;&#10;        curr = curr-&gt;next;&#10;        copyCurr = copyCurr-&gt;next;&#10;    }&#10;    return copyHead;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Ll 38 Merge K Sorted Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N * K * log K)<br><b>Space:</b> O(K)</td>
      <td>Create a min-heap and push the head of each linked list into it. Pop the minimum element, append it to the result list, and if the popped node has a next node, push the next node into the heap. Continue until the heap is empty.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct compare {&#10;    bool operator()(Node* a, Node* b) {&#10;        return a-&gt;data &gt; b-&gt;data;&#10;    }&#10;};&#10;Node * mergeKLists(Node *arr[], int K) {&#10;    priority_queue&lt;Node*, vector&lt;Node*&gt;, compare&gt; pq;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        if(arr[i]) pq.push(arr[i]);&#10;    }&#10;    Node* dummy = new Node(0);&#10;    Node* tail = dummy;&#10;    while(!pq.empty()) {&#10;        Node* curr = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = curr;&#10;        tail = tail-&gt;next;&#10;        if(curr-&gt;next) pq.push(curr-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Ll 39 Reverse A Linked List In Groups Of Given Size<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive grouping.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N/K)</td>
      <td>Reverse the first `k` nodes of the linked list iteratively. After reversing, the `head` pointer will be the end of the reversed group, and `curr` will point to the next node. Recursively call the function for `curr` and set `head->next` to the result.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct node *reverse (struct node *head, int k) {&#10;    if(!head) return NULL;&#10;    struct node* curr = head, *prev = NULL, *next = NULL;&#10;    int count = 0;&#10;    while(curr &amp;&amp; count &lt; k) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;        count++;&#10;    }&#10;    if(next) head-&gt;next = reverse(next, k);&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Ll 40 Split A Circular Linked List Into Two Halves<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Slow and Fast Pointer.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use slow and fast pointers to find the mid of the circular linked list. The slow pointer will point to the mid. Then break the list into two and make both circular.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void splitList(Node *head, Node **head1_ref, Node **head2_ref) {&#10;    Node *slow = head, *fast = head;&#10;    if(head == NULL) return;&#10;    while(fast-&gt;next != head &amp;&amp; fast-&gt;next-&gt;next != head) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;    }&#10;    if(fast-&gt;next-&gt;next == head) fast = fast-&gt;next;&#10;    *head1_ref = head;&#10;    if(head-&gt;next != head) *head2_ref = slow-&gt;next;&#10;    fast-&gt;next = slow-&gt;next;&#10;    slow-&gt;next = head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Ll 41 Check If Circular Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/circular-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Traverse to head.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the linked list starting from head. If we reach NULL, it's not circular. If we reach head again, it is circular.</td>
      <td><b>Edge Cases:</b> Empty list<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isCircular(Node *head) {&#10;    if(!head) return true;&#10;    Node *temp = head-&gt;next;&#10;    while(temp != NULL &amp;&amp; temp != head) {&#10;        temp = temp-&gt;next;&#10;    }&#10;    return (temp == head);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Ll 42 Count Triplets In A Sorted Doubly Linked List Whose Sum Is Equal To Given Value X<br><br></b> <a href="https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the list. For each node, use two pointers (left and right) on the remaining list to find pairs that sum to `x - node.data`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countTriplets(Node* head, int x) {&#10;    if(!head) return 0;&#10;    Node* curr, *first, *last;&#10;    int count = 0;&#10;    last = head;&#10;    while(last-&gt;next != NULL) last = last-&gt;next;&#10;    for(curr = head; curr != NULL; curr = curr-&gt;next) {&#10;        first = curr-&gt;next;&#10;        Node* right = last;&#10;        while(first != NULL &amp;&amp; right != NULL &amp;&amp; first != right &amp;&amp; right-&gt;next != first) {&#10;            if((curr-&gt;data + first-&gt;data + right-&gt;data) == x) {&#10;                count++;&#10;                first = first-&gt;next;&#10;                right = right-&gt;prev;&#10;            } else if((curr-&gt;data + first-&gt;data + right-&gt;data) &lt; x) {&#10;                first = first-&gt;next;&#10;            } else {&#10;                right = right-&gt;prev;&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Ll 43 Sort A K Sorted Doubly Linked List<br><br></b> <a href="https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Create a Min Heap of size k+1. Insert the first k+1 elements into the heap. Then, pop the minimum element, place it in the sorted list, and push the next element from the original list into the heap.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct compare {&#10;    bool operator()(Node* p1, Node* p2) {&#10;        return p1-&gt;data &gt; p2-&gt;data;&#10;    }&#10;};&#10;Node* sortAKSortedDLL(Node* head, int k) {&#10;    if(head == NULL) return head;&#10;    priority_queue&lt;Node*, vector&lt;Node*&gt;, compare&gt; pq;&#10;    Node* newHead = NULL, *last = NULL;&#10;    for(int i = 0; head != NULL &amp;&amp; i &lt;= k; i++) {&#10;        pq.push(head);&#10;        head = head-&gt;next;&#10;    }&#10;    while(!pq.empty()) {&#10;        if(newHead == NULL) {&#10;            newHead = pq.top();&#10;            newHead-&gt;prev = NULL;&#10;            last = newHead;&#10;        } else {&#10;            last-&gt;next = pq.top();&#10;            pq.top()-&gt;prev = last;&#10;            last = pq.top();&#10;        }&#10;        pq.pop();&#10;        if(head != NULL) {&#10;            pq.push(head);&#10;            head = head-&gt;next;&#10;        }&#10;    }&#10;    last-&gt;next = NULL;&#10;    return newHead;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Ll 44 Rotate Doubly Linked List By N Nodes<br><br></b> <a href="https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Traverse and link.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse to the Nth node. This will be the new tail. Its next will be the new head. Traverse to the end of the list and link it to the original head.</td>
      <td><b>Edge Cases:</b> N == 0<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node *rotateDLL(Node *start, int N) {&#10;    if (N == 0) return start;&#10;    Node* current = start;&#10;    int count = 1;&#10;    while(count &lt; N &amp;&amp; current != NULL) {&#10;        current = current-&gt;next;&#10;        count++;&#10;    }&#10;    if (current == NULL) return start;&#10;    Node* nthNode = current;&#10;    while (current-&gt;next != NULL) current = current-&gt;next;&#10;    current-&gt;next = start;&#10;    start-&gt;prev = current;&#10;    start = nthNode-&gt;next;&#10;    start-&gt;prev = NULL;&#10;    nthNode-&gt;next = NULL;&#10;    return start;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">Ll 45 Reverse A Doubly Linked List In Groups Of Given Size<br><br></b> <a href="https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursion.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N/K) recursion stack</td>
      <td>Similar to reversing singly linked list in groups of k. Keep track of prev, next, and current. Reverse k nodes, then recursively call for the rest of the list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* revListInGroupOfGivenSize(Node* head, int k) {&#10;    if(!head) return NULL;&#10;    Node *current = head, *next = NULL, *newHead = NULL;&#10;    int count = 0;&#10;    while(current != NULL &amp;&amp; count &lt; k) {&#10;        next = current-&gt;next;&#10;        current-&gt;prev = next;&#10;        current-&gt;next = newHead;&#10;        if(newHead != NULL) newHead-&gt;prev = current;&#10;        newHead = current;&#10;        current = next;&#10;        count++;&#10;    }&#10;    if(next != NULL) {&#10;        head-&gt;next = revListInGroupOfGivenSize(next, k);&#10;        head-&gt;next-&gt;prev = head;&#10;    }&#10;    return newHead;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">Ll 46 Can We Reverse A Linked List In Less Than On<br><br></b> N/A</td>
      <td rowspan="1"><b>Example 1:</b> Theoretical Question.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>No, it is not possible. To reverse a linked list, we must visit every single node at least once to change its pointer. Therefore, the minimum time complexity required is strictly O(N), where N is the number of nodes in the linked list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// It is not possible to reverse in less than O(n).</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">Ll 47 Find The First Node Of Loop In Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Floyd's Cycle Detection.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use Floyd's Cycle Detection to find if a cycle exists (slow and fast pointers meet). Then, move slow back to head, and advance both slow and fast by one step until they meet. The meeting point is the start of the loop.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findFirstNode(Node* head) {&#10;    Node *slow = head, *fast = head;&#10;    while(fast != NULL &amp;&amp; fast-&gt;next != NULL) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) {&#10;            slow = head;&#10;            while(slow != fast) {&#10;                slow = slow-&gt;next;&#10;                fast = fast-&gt;next;&#10;            }&#10;            return slow-&gt;data;&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">Ll 48 Detect Loop In Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Floyd's Cycle Detection.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use Floyd's Cycle Detection algorithm (Tortoise and Hare). Move `slow` by 1 and `fast` by 2. If they meet, a loop exists. If `fast` reaches NULL, there is no loop.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool detectLoop(Node* head) {&#10;    Node* slow = head, *fast = head;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">49</td>
      <td rowspan="1">Ll 49 Remove Loop In Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Floyd's Cycle Detection + Loop removal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use Floyd's Cycle Detection. If a loop is found, reset `slow` to head. Move both `slow` and `fast` by 1. The node where they meet is the start of the loop. Keep track of `fast`'s previous node to set its `next` to NULL.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void removeLoop(Node* head) {&#10;    if(!head || !head-&gt;next) return;&#10;    Node* slow = head, *fast = head;&#10;    while(fast &amp;&amp; fast-&gt;next) {&#10;        slow = slow-&gt;next;&#10;        fast = fast-&gt;next-&gt;next;&#10;        if(slow == fast) break;&#10;    }&#10;    if(slow == fast) {&#10;        slow = head;&#10;        if(slow == fast) {&#10;            while(fast-&gt;next != slow) fast = fast-&gt;next;&#10;        } else {&#10;            while(slow-&gt;next != fast-&gt;next) {&#10;                slow = slow-&gt;next;&#10;                fast = fast-&gt;next;&#10;            }&#10;        }&#10;        fast-&gt;next = NULL;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">50</td>
      <td rowspan="1">Ll 50 Remove Duplicates From An Unsorted Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Hash set.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a hash set to store the seen values. Iterate the list. If a node's value is in the set, skip it by updating the `next` pointer of the `prev` node. Else, add it to the set and update `prev`.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node * removeDuplicates(Node *head) {&#10;    if(!head) return NULL;&#10;    unordered_set&lt;int&gt; seen;&#10;    Node* curr = head, *prev = NULL;&#10;    while(curr) {&#10;        if(seen.find(curr-&gt;data) != seen.end()) {&#10;            prev-&gt;next = curr-&gt;next;&#10;            delete curr;&#10;            curr = prev-&gt;next;&#10;        } else {&#10;            seen.insert(curr-&gt;data);&#10;            prev = curr;&#10;            curr = curr-&gt;next;&#10;        }&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">51</td>
      <td rowspan="1">Ll 51 Move Last Element To Front Of A Given Linked List<br><br></b> <a href="https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Traverse the list to find the last node (`tail`) and the second last node (`sec_last`). Make `sec_last->next = NULL`, `tail->next = head`, and update `head = tail`.</td>
      <td><b>Edge Cases:</b> Empty list or Single node<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node *moveToFront(Node *head) {&#10;    if(!head || !head-&gt;next) return head;&#10;    Node *sec_last = NULL, *tail = head;&#10;    while(tail-&gt;next) {&#10;        sec_last = tail;&#10;        tail = tail-&gt;next;&#10;    }&#10;    sec_last-&gt;next = NULL;&#10;    tail-&gt;next = head;&#10;    return tail;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">52</td>
      <td rowspan="1">Ll 52 Add 1 To A Number Represented As Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Reverse, Add, Reverse.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Reverse the linked list. Add 1 to the first node, and propagate the carry if the value becomes 10. Once done, reverse the list back. If carry still remains at the end, add a new node.</td>
      <td><b>Edge Cases:</b> 999 -> 1000<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* reverseList(Node* head) {&#10;    Node* curr = head, *prev = NULL, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;Node* addOne(Node *head) {&#10;    head = reverseList(head);&#10;    Node* curr = head, *prev = NULL;&#10;    int carry = 1;&#10;    while(curr) {&#10;        int sum = curr-&gt;data + carry;&#10;        carry = sum / 10;&#10;        curr-&gt;data = sum % 10;&#10;        prev = curr;&#10;        curr = curr-&gt;next;&#10;    }&#10;    if(carry &gt; 0) prev-&gt;next = new Node(carry);&#10;    return reverseList(head);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">53</td>
      <td rowspan="1">Ll 53 Add Two Numbers Represented By Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Reverse, Add, Reverse.</td>
      <td><b>Time:</b> O(max(N, M))<br><b>Space:</b> O(max(N, M))</td>
      <td>Reverse both linked lists. Traverse both lists simultaneously, adding the data values of corresponding nodes along with the carry. Create new nodes for the sum and append them to the result list. Finally, reverse the result list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node* reverse(struct Node* head) {&#10;    Node* prev = NULL, *curr = head, *next = NULL;&#10;    while(curr) {&#10;        next = curr-&gt;next;&#10;        curr-&gt;next = prev;&#10;        prev = curr;&#10;        curr = next;&#10;    }&#10;    return prev;&#10;}&#10;struct Node* addTwoLists(struct Node* first, struct Node* second) {&#10;    first = reverse(first);&#10;    second = reverse(second);&#10;    Node* dummy = new Node(0), *temp = dummy;&#10;    int carry = 0;&#10;    while(first || second || carry) {&#10;        int sum = carry;&#10;        if(first) { sum += first-&gt;data; first = first-&gt;next; }&#10;        if(second) { sum += second-&gt;data; second = second-&gt;next; }&#10;        carry = sum / 10;&#10;        temp-&gt;next = new Node(sum % 10);&#10;        temp = temp-&gt;next;&#10;    }&#10;    return reverse(dummy-&gt;next);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">54</td>
      <td rowspan="1">Ll 54 Intersection Of Two Sorted Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td>Use two pointers, `ptr1` for the first list and `ptr2` for the second. If `ptr1->data < ptr2->data`, `ptr1++`. If `ptr2->data < ptr1->data`, `ptr2++`. If they are equal, add to the result list and advance both.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* findIntersection(Node* head1, Node* head2) {&#10;    Node* dummy = new Node(0), *temp = dummy;&#10;    Node* p1 = head1, *p2 = head2;&#10;    while(p1 &amp;&amp; p2) {&#10;        if(p1-&gt;data &lt; p2-&gt;data) p1 = p1-&gt;next;&#10;        else if(p2-&gt;data &lt; p1-&gt;data) p2 = p2-&gt;next;&#10;        else {&#10;            temp-&gt;next = new Node(p1-&gt;data);&#10;            temp = temp-&gt;next;&#10;            p1 = p1-&gt;next;&#10;            p2 = p2-&gt;next;&#10;        }&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">55</td>
      <td rowspan="1">Ll 55 Intersection Point In Y Shaped Linked Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two Pointers.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(1)</td>
      <td>Use two pointers `a` and `b`. Traverse both lists. When `a` reaches the end, redirect it to `head2`. When `b` reaches the end, redirect it to `head1`. They will meet at the intersection point or both become NULL.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int intersectPoint(Node* head1, Node* head2) {&#10;    Node* a = head1, *b = head2;&#10;    while(a != b) {&#10;        a = (a) ? a-&gt;next : head2;&#10;        b = (b) ? b-&gt;next : head1;&#10;    }&#10;    if(a) return a-&gt;data;&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Stacks Queues

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
      <td rowspan="1">Sq 01 Valid Parentheses<br><br></b> <a href="https://leetcode.com/problems/valid-parentheses/" target="_blank">LeetCode 20</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "()[]{}"<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a Stack. Push open brackets. If a closed bracket is found, verify it matches the top of the stack and pop.<br><br><b>Dependencies:</b> <code>std::stack</code></td>
      <td><b>Edge Cases:</b> <b>Empty Stack / Unmatched:</b> If a closed bracket arrives while the stack is empty, it's invalid. If stack is NOT empty at the end, it's invalid.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValid(std::string s) {&#10;    std::stack&lt;char&gt; st;&#10;    for(char c : s) {&#10;        if(c == &#x27;(&#x27; || c == &#x27;{&#x27; || c == &#x27;[&#x27;) st.push(c);&#10;        else {&#10;            if(st.empty()) return false;&#10;            char top = st.top();&#10;            if((c == &#x27;)&#x27; &amp;&amp; top == &#x27;(&#x27;) || &#10;               (c == &#x27;}&#x27; &amp;&amp; top == &#x27;{&#x27;) || &#10;               (c == &#x27;]&#x27; &amp;&amp; top == &#x27;[&#x27;)) {&#10;                st.pop();&#10;            } else return false;&#10;        }&#10;    }&#10;    return st.empty();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Sq 02 Next Greater Element I<br><br></b> <a href="https://leetcode.com/problems/next-greater-element-i/" target="_blank">LeetCode 496</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums1 = [4,1,2], nums2 = [1,3,4,2]<br><b>Output:</b> [-1,3,-1]</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N)</td>
      <td>Monotonic Stack traversing `nums2` from right to left. Maintain stack of elements in decreasing order.<br><br><b>Dependencies:</b> <code>std::stack</code>, <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>No greater element:</b> If stack becomes empty after popping smaller elements, there is no NGE, store `-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; nextGreaterElement(std::vector&lt;int&gt;&amp; nums1, std::vector&lt;int&gt;&amp; nums2) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    std::stack&lt;int&gt; st;&#10;    for(int i = nums2.size() - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= nums2[i]) st.pop();&#10;        if(st.empty()) mpp[nums2[i]] = -1;&#10;        else mpp[nums2[i]] = st.top();&#10;        st.push(nums2[i]);&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    for(int num : nums1) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Sq 03 Min Stack<br><br></b> <a href="https://leetcode.com/problems/min-stack/" target="_blank">LeetCode 155</a></td>
      <td rowspan="1"><b>Example 1:</b> MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3</td>
      <td><b>Time:</b> O(1) per operation<br><b>Space:</b> O(N)</td>
      <td>Store pairs of `(value, current_minimum)` in the stack. Alternatively, use math to encode the difference between the value and the minimum to achieve O(1) space auxiliary, but a stack of pairs is standard.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MinStack {&#10;    stack&lt;pair&lt;int, int&gt;&gt; st;&#10;public:&#10;    MinStack() {}&#10;    void push(int val) {&#10;        if(st.empty()) st.push({val, val});&#10;        else st.push({val, min(val, st.top().second)});&#10;    }&#10;    void pop() { st.pop(); }&#10;    int top() { return st.top().first; }&#10;    int getMin() { return st.top().second; }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Sq 04 Largest Rectangle In Histogram<br><br></b> <a href="https://leetcode.com/problems/largest-rectangle-in-histogram/" target="_blank">LeetCode 84</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> heights = [2,1,5,6,2,3]<br><b>Output:</b> 10</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Monotonic Stack. Find the next smaller element on the left and right for each bar. Area for bar `i` is `heights[i] * (right[i] - left[i] + 1)`. Alternatively, do it in a single pass stack loop.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;=n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || heights[st.top()] &gt;= heights[i])) {&#10;            int height = heights[st.top()]; st.pop();&#10;            int width = st.empty() ? i : i - st.top() - 1;&#10;            maxArea = max(maxArea, width * height);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Sq 05 Reverse A String Using Stack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Push and pop.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Push all characters of the string into a stack. Then pop them out one by one. The popped characters will be in reversed order.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">char* reverse(char *S, int len) {&#10;    stack&lt;char&gt; st;&#10;    for(int i = 0; i &lt; len; i++) {&#10;        st.push(S[i]);&#10;    }&#10;    for(int i = 0; i &lt; len; i++) {&#10;        S[i] = st.top();&#10;        st.pop();&#10;    }&#10;    return S;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Sq 06 Design A Stack That Supports Getmin<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/special-stack/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Formula approach.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>To achieve O(1) space, when pushing `x < minEle`, push `2 * x - minEle` and update `minEle = x`. When popping `y`, if `y < minEle`, then `minEle = 2 * minEle - y`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minEle;&#10;void push(stack&lt;int&gt;&amp; s, int a){&#10;    if(s.empty()) { s.push(a); minEle = a; }&#10;    else if(a &lt; minEle) { s.push(2 * a - minEle); minEle = a; }&#10;    else { s.push(a); }&#10;}&#10;bool isFull(stack&lt;int&gt;&amp; s, int n){&#10;    return s.size() == n;&#10;}&#10;bool isEmpty(stack&lt;int&gt;&amp; s){&#10;    return s.empty();&#10;}&#10;int pop(stack&lt;int&gt;&amp; s){&#10;    if(s.empty()) return -1;&#10;    int top = s.top();&#10;    s.pop();&#10;    if(top &lt; minEle) {&#10;        int prevMin = minEle;&#10;        minEle = 2 * minEle - top;&#10;        return prevMin;&#10;    }&#10;    return top;&#10;}&#10;int getMin(stack&lt;int&gt;&amp; s){&#10;    return minEle;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Sq 07 Next Greater Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Decreasing stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from right to left. Use a stack to keep track of elements. Pop from the stack while the top element is less than or equal to the current element. If stack is empty, NGE is -1, else it's the stack top. Push current element.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; nextLargerElement(vector&lt;long long&gt; arr, int n){&#10;    vector&lt;long long&gt; res(n);&#10;    stack&lt;long long&gt; st;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!st.empty() &amp;&amp; st.top() &lt;= arr[i]) st.pop();&#10;        if(st.empty()) res[i] = -1;&#10;        else res[i] = st.top();&#10;        st.push(arr[i]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Sq 08 Celebrity Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two pointers or Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Push all elements (0 to N-1) into a stack. Pop two elements `A` and `B`. If `A` knows `B`, `A` cannot be a celebrity, push `B` back. If `A` does not know `B`, `B` cannot be a celebrity, push `A` back. The remaining element is a potential celebrity. Verify it by checking if everyone knows it and it knows no one.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int celebrity(vector&lt;vector&lt;int&gt; &gt;&amp; M, int n) {&#10;    stack&lt;int&gt; st;&#10;    for(int i = 0; i &lt; n; i++) st.push(i);&#10;    while(st.size() &gt; 1) {&#10;        int a = st.top(); st.pop();&#10;        int b = st.top(); st.pop();&#10;        if(M[a][b] == 1) st.push(b);&#10;        else st.push(a);&#10;    }&#10;    if(st.empty()) return -1;&#10;    int pot = st.top();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i != pot &amp;&amp; (M[pot][i] == 1 || M[i][pot] == 0)) return -1;&#10;    }&#10;    return pot;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Sq 09 Arithmetic Expression Evaluation<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/arithmetic-expression-evaluation/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two stacks (operands and operators).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use two stacks: one for numbers and one for operators. Process the expression character by character. If it's a number, push to numbers stack. If it's `(`, push to operators stack. If it's `)`, solve until `(`. If it's an operator, solve while top of operators stack has same or greater precedence, then push.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int precedence(char op) {&#10;    if(op == &#x27;+&#x27;||op == &#x27;-&#x27;) return 1;&#10;    if(op == &#x27;*&#x27;||op == &#x27;/&#x27;) return 2;&#10;    return 0;&#10;}&#10;int applyOp(int a, int b, char op) {&#10;    switch(op){ &#10;        case &#x27;+&#x27;: return a + b;&#10;        case &#x27;-&#x27;: return a - b;&#10;        case &#x27;*&#x27;: return a * b;&#10;        case &#x27;/&#x27;: return a / b;&#10;    }&#10;    return 0;&#10;}&#10;int evaluate(string tokens){&#10;    int i;&#10;    stack &lt;int&gt; values;&#10;    stack &lt;char&gt; ops;&#10;    for(i = 0; i &lt; tokens.length(); i++){&#10;        if(tokens[i] == &#x27; &#x27;) continue;&#10;        else if(tokens[i] == &#x27;(&#x27;){&#10;            ops.push(tokens[i]);&#10;        } else if(isdigit(tokens[i])){&#10;            int val = 0;&#10;            while(i &lt; tokens.length() &amp;&amp; isdigit(tokens[i])) {&#10;                val = (val*10) + (tokens[i]-&#x27;0&#x27;);&#10;                i++;&#10;            }&#10;            values.push(val);&#10;            i--;&#10;        } else if(tokens[i] == &#x27;)&#x27;) {&#10;            while(!ops.empty() &amp;&amp; ops.top() != &#x27;(&#x27;) {&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            if(!ops.empty()) ops.pop();&#10;        } else {&#10;            while(!ops.empty() &amp;&amp; precedence(ops.top()) &gt;= precedence(tokens[i])){&#10;                int val2 = values.top(); values.pop();&#10;                int val1 = values.top(); values.pop();&#10;                char op = ops.top(); ops.pop();&#10;                values.push(applyOp(val1, val2, op));&#10;            }&#10;            ops.push(tokens[i]);&#10;        }&#10;    }&#10;    while(!ops.empty()){&#10;        int val2 = values.top(); values.pop();&#10;        int val1 = values.top(); values.pop();&#10;        char op = ops.top(); ops.pop();&#10;        values.push(applyOp(val1, val2, op));&#10;    }&#10;    return values.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Sq 10 Evaluation Of Postfix Expression<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack of operands.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate through the string. If it's a number, push it to stack. If it's an operator, pop two numbers from stack, apply the operator, and push the result back to stack.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evaluatePostfix(string S) {&#10;    stack&lt;int&gt; st;&#10;    for(char c : S) {&#10;        if(isdigit(c)) {&#10;            st.push(c - &#x27;0&#x27;);&#10;        } else {&#10;            int op2 = st.top(); st.pop();&#10;            int op1 = st.top(); st.pop();&#10;            if(c == &#x27;+&#x27;) st.push(op1 + op2);&#10;            else if(c == &#x27;-&#x27;) st.push(op1 - op2);&#10;            else if(c == &#x27;*&#x27;) st.push(op1 * op2);&#10;            else if(c == &#x27;/&#x27;) st.push(op1 / op2);&#10;        }&#10;    }&#10;    return st.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Sq 11 Insert An Element At Its Bottom In A Given Stack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive push.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use recursion. If the stack is empty, push the element. Otherwise, pop the top element, recursively call the function, and then push the popped element back.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">stack&lt;int&gt; insertAtBottom(stack&lt;int&gt; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return St;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    St = insertAtBottom(St, X);&#10;    St.push(top);&#10;    return St;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Sq 12 Reverse A Stack Using Recursion<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reverse-a-stack/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive pop and insertAtBottom.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Recursively pop all elements until the stack is empty. Then, as the recursion unwinds, use another recursive function `insertAtBottom` to push the elements at the bottom.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertAtBottom(stack&lt;int&gt;&amp; St, int X) {&#10;    if(St.empty()) {&#10;        St.push(X);&#10;        return;&#10;    }&#10;    int top = St.top();&#10;    St.pop();&#10;    insertAtBottom(St, X);&#10;    St.push(top);&#10;}&#10;void Reverse(stack&lt;int&gt; &amp;St) {&#10;    if(St.empty()) return;&#10;    int top = St.top();&#10;    St.pop();&#10;    Reverse(St);&#10;    insertAtBottom(St, top);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Sq 13 Maximum Rectangular Area In A Histogram<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Next Smaller Element on left and right.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a stack to find Next Smaller Element (NSE) and Previous Smaller Element (PSE) for each bar. Then, the width of the rectangle with bar `i` as the minimum height is `NSE[i] - PSE[i] - 1`. The area is `height[i] * width`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long getMaxArea(long long arr[], int n) {&#10;    stack&lt;int&gt; st;&#10;    long long max_area = 0;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!st.empty() &amp;&amp; (i == n || arr[st.top()] &gt;= arr[i])) {&#10;            long long height = arr[st.top()];&#10;            st.pop();&#10;            long long width = st.empty() ? i : i - st.top() - 1;&#10;            max_area = max(max_area, height * width);&#10;        }&#10;        st.push(i);&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Sq 14 Next Smaller Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/fab3281cefac7140ca15e21505beddf7e4323e08/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Iterate from right to left. Use a monotonic stack. Pop elements from the stack that are greater than or equal to the current element. The top of the stack is the next smaller element. Push the current element to the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; help_classmate(vector&lt;int&gt; arr, int n) {&#10;    vector&lt;int&gt; ans(n, -1);&#10;    stack&lt;int&gt; s;&#10;    for(int i = n - 1; i &gt;= 0; i--) {&#10;        while(!s.empty() &amp;&amp; s.top() &gt;= arr[i]) s.pop();&#10;        if(!s.empty()) ans[i] = s.top();&#10;        s.push(arr[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Sq 15 Maximal Rectangle<br><br></b> <a href="https://leetcode.com/problems/maximal-rectangle/" target="_blank">LeetCode 85</a></td>
      <td rowspan="1"><b>Example 1:</b> Largest Rectangle in Histogram reduction.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(cols)</td>
      <td>Treat each row as the base of a histogram. The height of each bar is the number of consecutive 1s above it. Apply the Largest Rectangle in Histogram algorithm for each row and maintain the maximum area.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestRectangleArea(vector&lt;int&gt;&amp; heights) {&#10;    int n = heights.size(), maxArea = 0;&#10;    stack&lt;int&gt; s;&#10;    for(int i = 0; i &lt;= n; i++) {&#10;        while(!s.empty() &amp;&amp; (i == n || heights[s.top()] &gt;= heights[i])) {&#10;            int height = heights[s.top()];&#10;            s.pop();&#10;            int width = s.empty() ? i : i - s.top() - 1;&#10;            maxArea = max(maxArea, height * width);&#10;        }&#10;        s.push(i);&#10;    }&#10;    return maxArea;&#10;}&#10;int maximalRectangle(vector&lt;vector&lt;char&gt;&gt;&amp; matrix) {&#10;    if(matrix.empty()) return 0;&#10;    int rows = matrix.size(), cols = matrix[0].size();&#10;    vector&lt;int&gt; heights(cols, 0);&#10;    int maxArea = 0;&#10;    for(int i = 0; i &lt; rows; i++) {&#10;        for(int j = 0; j &lt; cols; j++) {&#10;            if(matrix[i][j] == &#x27;1&#x27;) heights[j]++;&#10;            else heights[j] = 0;&#10;        }&#10;        maxArea = max(maxArea, largestRectangleArea(heights));&#10;    }&#10;    return maxArea;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Sq 16 Online Stock Span<br><br></b> <a href="https://leetcode.com/problems/online-stock-span/" target="_blank">LeetCode 901</a></td>
      <td rowspan="1"><b>Example 1:</b> Monotonic Stack.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(N)</td>
      <td>Use a stack of pairs `(price, span)`. When a new price comes in, initialize its span to 1. Pop elements from the stack while the top element's price is `<= price`, adding their spans to the current span. Push `(price, span)` to the stack.<br><br><b>Dependencies:</b> Stack</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class StockSpanner {&#10;    stack&lt;pair&lt;int, int&gt;&gt; s;&#10;public:&#10;    StockSpanner() {}&#10;    int next(int price) {&#10;        int span = 1;&#10;        while(!s.empty() &amp;&amp; s.top().first &lt;= price) {&#10;            span += s.top().second;&#10;            s.pop();&#10;        }&#10;        s.push({price, span});&#10;        return span;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Sq 17 Rotten Oranges<br><br></b> <a href="https://leetcode.com/problems/rotting-oranges/" target="_blank">LeetCode 994</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS.</td>
      <td><b>Time:</b> O(rows * cols)<br><b>Space:</b> O(rows * cols)</td>
      <td>Use a Queue for BFS. Find all initially rotten oranges and push them into the queue with time 0. Count total fresh oranges. Pop an orange, rot its adjacent fresh oranges, push them to the queue with `time + 1`, and decrement fresh count. Return the max time if fresh count is 0, else -1.<br><br><b>Dependencies:</b> Queue</td>
      <td><b>Edge Cases:</b> Grid without fresh oranges<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int orangesRotting(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    queue&lt;pair&lt;pair&lt;int, int&gt;, int&gt;&gt; q;&#10;    int vis[n][m];&#10;    int cntFresh = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == 2) {&#10;                q.push({{i, j}, 0});&#10;                vis[i][j] = 2;&#10;            } else {&#10;                vis[i][j] = 0;&#10;            }&#10;            if(grid[i][j] == 1) cntFresh++;&#10;        }&#10;    }&#10;    int tm = 0, drow[] = {-1, 0, 1, 0}, dcol[] = {0, 1, 0, -1}, cnt = 0;&#10;    while(!q.empty()) {&#10;        int r = q.front().first.first, c = q.front().first.second, t = q.front().second;&#10;        tm = max(tm, t); q.pop();&#10;        for(int i = 0; i &lt; 4; i++) {&#10;            int nrow = r + drow[i], ncol = c + dcol[i];&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; vis[nrow][ncol] != 2 &amp;&amp; grid[nrow][ncol] == 1) {&#10;                q.push({{nrow, ncol}, t + 1});&#10;                vis[nrow][ncol] = 2;&#10;                cnt++;&#10;            }&#10;        }&#10;    }&#10;    if(cnt != cntFresh) return -1;&#10;    return tm;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Trees

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
      <td rowspan="1">Tree 01 Binary Tree Inorder Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-inorder-traversal/" target="_blank">LeetCode 94</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [1,null,2,3]<br><b>Output:</b> [1,3,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Recursive approach. Traverse Left, process Root, then traverse Right.</td>
      <td><b>Edge Cases:</b> <b>Recursion Depth:</b> Worst-case skewed tree takes `O(N)` space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(TreeNode* root, std::vector&lt;int&gt;&amp; ans) {&#10;    if (!root) return;&#10;    inorder(root-&gt;left, ans);&#10;    ans.push_back(root-&gt;val);&#10;    inorder(root-&gt;right, ans);&#10;}&#10;std::vector&lt;int&gt; inorderTraversal(TreeNode* root) {&#10;    std::vector&lt;int&gt; ans;&#10;    inorder(root, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Tree 02 Maximum Depth Of Binary Tree<br><br></b> <a href="https://leetcode.com/problems/maximum-depth-of-binary-tree/" target="_blank">LeetCode 104</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [3,9,20,null,null,15,7]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H) &cong; O(N)</td>
      <td>Recursively find the max depth of left and right subtrees. The depth is `1 + max(left_depth, right_depth)`.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Null Root:</b> If empty (`root == NULL`), depth is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDepth(TreeNode* root) {&#10;    if (!root) return 0;&#10;    return 1 + std::max(maxDepth(root-&gt;left), maxDepth(root-&gt;right));&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Tree 03 Lowest Common Ancestor Of A Binary Tree<br><br></b> <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/" target="_blank">LeetCode 236</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>If we find `p` or `q`, return it. If both left and right return non-null, current node is LCA.</td>
      <td><b>Edge Cases:</b> <b>Node is LCA:</b> If one is ancestor of other, it returns immediately.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    if (!root || root == p || root == q) return root;&#10;    TreeNode* left = lowestCommonAncestor(root-&gt;left, p, q);&#10;    TreeNode* right = lowestCommonAncestor(root-&gt;right, p, q);&#10;    if (!left) return right;&#10;    else if (!right) return left;&#10;    else return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Tree 04 Same Tree<br><br></b> <a href="https://leetcode.com/problems/same-tree/" target="_blank">LeetCode 100</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> p = [1,2,3], q = [1,2,3]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Traverse both trees simultaneously. If both nodes are null, true. If one is null or values mismatch, false.</td>
      <td><b>Edge Cases:</b> <b>Structural mismatch:</b> Safely handled by `!p || !q`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSameTree(TreeNode* p, TreeNode* q) {&#10;    if(!p &amp;&amp; !q) return true;&#10;    if(!p || !q || p-&gt;val != q-&gt;val) return false;&#10;    return isSameTree(p-&gt;left, q-&gt;left) &amp;&amp; isSameTree(p-&gt;right, q-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Tree 05 Invert Binary Tree<br><br></b> <a href="https://leetcode.com/problems/invert-binary-tree/" target="_blank">LeetCode 226</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [4,2,7,1,3,6,9]<br><b>Output:</b> [4,7,2,9,6,3,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Recursively swap the left and right children of every node.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Empty Tree:</b> Returns null immediately.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* invertTree(TreeNode* root) {&#10;    if(!root) return nullptr;&#10;    std::swap(root-&gt;left, root-&gt;right);&#10;    invertTree(root-&gt;left);&#10;    invertTree(root-&gt;right);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Tree 06 Diameter Of Binary Tree<br><br></b> <a href="https://leetcode.com/problems/diameter-of-binary-tree/" target="_blank">LeetCode 543</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [1,2,3,4,5]<br><b>Output:</b> 3 (Path is [4,2,1,3] or [5,2,1,3])</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Modify the Height/Depth algorithm. Calculate `left_depth + right_depth` at every node to find max diameter, while returning standard height.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Path doesn't pass through root:</b> Handled correctly by tracking the global maximum `max_d` at every recursive step.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int height(TreeNode* node, int&amp; max_d) {&#10;    if(!node) return 0;&#10;    int left = height(node-&gt;left, max_d);&#10;    int right = height(node-&gt;right, max_d);&#10;    max_d = std::max(max_d, left + right);&#10;    return 1 + std::max(left, right);&#10;}&#10;int diameterOfBinaryTree(TreeNode* root) {&#10;    int max_d = 0;&#10;    height(root, max_d);&#10;    return max_d;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Tree 07 Balanced Binary Tree<br><br></b> <a href="https://leetcode.com/problems/balanced-binary-tree/" target="_blank">LeetCode 110</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [3,9,20,null,null,15,7]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Modify the Height algorithm. If the difference between `left` and `right` height is > 1, return `-1` to propagate the unbalanced signal.<br><br><b>Dependencies:</b> <code>std::abs</code></td>
      <td><b>Edge Cases:</b> <b>Early Exit:</b> Checking if `left == -1` or `right == -1` immediately breaks the recursion, optimizing time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int checkHeight(TreeNode* node) {&#10;    if(!node) return 0;&#10;    int left = checkHeight(node-&gt;left);&#10;    if(left == -1) return -1;&#10;    int right = checkHeight(node-&gt;right);&#10;    if(right == -1) return -1;&#10;    if(std::abs(left - right) &gt; 1) return -1;&#10;    return 1 + std::max(left, right);&#10;}&#10;bool isBalanced(TreeNode* root) {&#10;    return checkHeight(root) != -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Tree 08 Binary Search Tree Iterator<br><br></b> <a href="https://leetcode.com/problems/binary-search-tree-iterator/" target="_blank">LeetCode 173</a></td>
      <td rowspan="1"><b>Example 1:</b> next() returns smallest element.</td>
      <td><b>Time:</b> O(1) amortized<br><b>Space:</b> O(H)</td>
      <td>Use a stack to simulate in-order traversal. Push all left children initially. On next(), pop, return val, and push all left children of popped node's right child.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><b>Edge Cases:</b> <b>Empty Tree:</b> Stack is empty.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BSTIterator {&#10;    stack&lt;TreeNode*&gt; st;&#10;    void pushAll(TreeNode* node) {&#10;        while(node) {&#10;            st.push(node);&#10;            node = node-&gt;left;&#10;        }&#10;    }&#10;public:&#10;    BSTIterator(TreeNode* root) {&#10;        pushAll(root);&#10;    }&#10;    int next() {&#10;        TreeNode* tmpNode = st.top();&#10;        st.pop();&#10;        pushAll(tmpNode-&gt;right);&#10;        return tmpNode-&gt;val;&#10;    }&#10;    bool hasNext() {&#10;        return !st.empty();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Tree 09 Validate Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/validate-binary-search-tree/" target="_blank">LeetCode 98</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [2,1,3]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Recursive validation with min and max bounds for every node. Long long is used to avoid overflow.<br><br><b>Dependencies:</b> <code>#include <limits.h></code></td>
      <td><b>Edge Cases:</b> <b>Values reach INT bounds:</b> Use LLONG_MIN/LLONG_MAX bounds.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isValidBST(TreeNode* root, long minVal, long maxVal) {&#10;    if(!root) return true;&#10;    if(root-&gt;val &gt;= maxVal || root-&gt;val &lt;= minVal) return false;&#10;    return isValidBST(root-&gt;left, minVal, root-&gt;val) &amp;&amp; isValidBST(root-&gt;right, root-&gt;val, maxVal);&#10;}&#10;bool isValidBST(TreeNode* root) {&#10;    return isValidBST(root, LONG_MIN, LONG_MAX);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Tree 10 Construct Tree From Preorder And Inorder<br><br></b> <a href="https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/" target="_blank">LeetCode 105</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]<br><b>Output:</b> [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for Hash Map</td>
      <td>First element of preorder is the root. Find this element in inorder to split into left and right subtrees. Use a Hash Map to store inorder indices for O(1) lookups.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; preorder, vector&lt;int&gt;&amp; inorder) {&#10;    unordered_map&lt;int, int&gt; inMap;&#10;    for(int i=0; i&lt;inorder.size(); i++) inMap[inorder[i]] = i;&#10;    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; pre, int preStart, int preEnd, vector&lt;int&gt;&amp; in, int inStart, int inEnd, unordered_map&lt;int, int&gt;&amp; inMap) {&#10;    if(preStart &gt; preEnd || inStart &gt; inEnd) return NULL;&#10;    TreeNode* root = new TreeNode(pre[preStart]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = build(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);&#10;    root-&gt;right = build(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Tree 11 Maximum Path Sum<br><br></b> <a href="https://leetcode.com/problems/binary-tree-maximum-path-sum/" target="_blank">LeetCode 124</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [-10,9,20,null,null,15,7]<br><b>Output:</b> 42</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>DFS returning max path sum down a single branch. At any node, max path = `node.val + max(0, leftPath) + max(0, rightPath)`. Ignore negative branches.<br><br><b>Dependencies:</b> <code>#include <limits.h></code></td>
      <td><b>Edge Cases:</b> <b>All Negative Nodes:</b> Initialization with `INT_MIN` properly returns the least negative node.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxPathSum(TreeNode* root) {&#10;    int maxi = INT_MIN;&#10;    maxPathDown(root, maxi);&#10;    return maxi;&#10;}&#10;int maxPathDown(TreeNode* node, int&amp; maxi) {&#10;    if(!node) return 0;&#10;    int left = max(0, maxPathDown(node-&gt;left, maxi));&#10;    int right = max(0, maxPathDown(node-&gt;right, maxi));&#10;    maxi = max(maxi, left + right + node-&gt;val);&#10;    return max(left, right) + node-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Tree 12 Boundary Traversal<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return array of boundary nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>1) Add root if not leaf. 2) Traverse left boundary (excluding leaves). 3) Inorder traverse all leaves. 4) Traverse right boundary, reverse it, then add to answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isLeaf(TreeNode* root) { return !root-&gt;left &amp;&amp; !root-&gt;right; }&#10;void addLeft(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;left;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) res.push_back(cur-&gt;val);&#10;        if(cur-&gt;left) cur = cur-&gt;left;&#10;        else cur = cur-&gt;right;&#10;    }&#10;}&#10;void addRight(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    TreeNode* cur = root-&gt;right;&#10;    vector&lt;int&gt; tmp;&#10;    while(cur) {&#10;        if(!isLeaf(cur)) tmp.push_back(cur-&gt;val);&#10;        if(cur-&gt;right) cur = cur-&gt;right;&#10;        else cur = cur-&gt;left;&#10;    }&#10;    for(int i = tmp.size()-1; i&gt;=0; --i) res.push_back(tmp[i]);&#10;}&#10;void addLeaves(TreeNode* root, vector&lt;int&gt;&amp; res) {&#10;    if(isLeaf(root)) { res.push_back(root-&gt;val); return; }&#10;    if(root-&gt;left) addLeaves(root-&gt;left, res);&#10;    if(root-&gt;right) addLeaves(root-&gt;right, res);&#10;}&#10;vector&lt;int&gt; boundary(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    if(!isLeaf(root)) res.push_back(root-&gt;val);&#10;    addLeft(root, res); addLeaves(root, res); addRight(root, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Tree 13 Zigzag Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/" target="_blank">LeetCode 103</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [3,9,20,null,null,15,7]<br><b>Output:</b> [[3],[20,9],[15,7]]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Standard BFS Level Order Traversal with a boolean flag `leftToRight`. After finishing a level, if the flag is false, reverse the level array before adding to the result.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; zigzagLevelOrder(TreeNode* root) {&#10;    vector&lt;vector&lt;int&gt;&gt; result;&#10;    if(!root) return result;&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(root);&#10;    bool leftToRight = true;&#10;    while(!q.empty()) {&#10;        int size = q.size();&#10;        vector&lt;int&gt; row(size);&#10;        for(int i=0; i&lt;size; i++) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            int index = leftToRight ? i : (size - 1 - i);&#10;            row[index] = node-&gt;val;&#10;            if(node-&gt;left) q.push(node-&gt;left);&#10;            if(node-&gt;right) q.push(node-&gt;right);&#10;        }&#10;        leftToRight = !leftToRight;&#10;        result.push_back(row);&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Tree 14 Vertical Order Traversal<br><br></b> <a href="https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/" target="_blank">LeetCode 987</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> [[9],[3,15],[20],[7]]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Use a map structure: `map<int, map<int, multiset<int>>>` to store nodes mapped by their horizontal distance and level. BFS traversal ensures levels are processed top-down.<br><br><b>Dependencies:</b> <code>#include <map>\n#include <queue>\n#include <set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; verticalTraversal(TreeNode* root) {&#10;    map&lt;int, map&lt;int, multiset&lt;int&gt;&gt;&gt; nodes;&#10;    queue&lt;pair&lt;TreeNode*, pair&lt;int, int&gt;&gt;&gt; todo;&#10;    todo.push({root, {0, 0}});&#10;    while(!todo.empty()) {&#10;        auto p = todo.front(); todo.pop();&#10;        TreeNode* node = p.first;&#10;        int x = p.second.first, y = p.second.second;&#10;        nodes[x][y].insert(node-&gt;val);&#10;        if(node-&gt;left) todo.push({node-&gt;left, {x - 1, y + 1}});&#10;        if(node-&gt;right) todo.push({node-&gt;right, {x + 1, y + 1}});&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(auto p : nodes) {&#10;        vector&lt;int&gt; col;&#10;        for(auto q : p.second) {&#10;            col.insert(col.end(), q.second.begin(), q.second.end());&#10;        }&#10;        ans.push_back(col);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Tree 15 Top View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>BFS traversal maintaining horizontal distance (HD) from root. Use a map `hd -> value`. Only insert into the map if the HD is not already present, ensuring the top-most node is recorded.<br><br><b>Dependencies:</b> <code>#include <map>\n#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        if(mpp.find(line) == mpp.end()) mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Tree 16 Bottom View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return list of values.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>BFS traversal maintaining horizontal distance (HD). Map `hd -> value`. Always update the map value for a given HD so that the last node encountered (bottom-most) overrides previous ones.<br><br><b>Dependencies:</b> <code>#include <map>\n#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bottomView(Node *root) {&#10;    vector&lt;int&gt; ans;&#10;    if(root == NULL) return ans;&#10;    map&lt;int, int&gt; mpp;&#10;    queue&lt;pair&lt;Node*, int&gt;&gt; q;&#10;    q.push({root, 0});&#10;    while(!q.empty()) {&#10;        auto it = q.front(); q.pop();&#10;        Node* node = it.first;&#10;        int line = it.second;&#10;        mpp[line] = node-&gt;data;&#10;        if(node-&gt;left != NULL) q.push({node-&gt;left, line - 1});&#10;        if(node-&gt;right != NULL) q.push({node-&gt;right, line + 1});&#10;    }&#10;    for(auto it : mpp) ans.push_back(it.second);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Tree 17 Right View<br><br></b> <a href="https://leetcode.com/problems/binary-tree-right-side-view/" target="_blank">LeetCode 199</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> root = [1,2,3,null,5,null,4]<br><b>Output:</b> [1,3,4]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>DFS Traversing right child before left child. Maintain the current level. If `level == result.size()`, append the node value to the result list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(TreeNode *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;val);&#10;    recursion(root-&gt;right, level + 1, res);&#10;    recursion(root-&gt;left, level + 1, res);&#10;}&#10;vector&lt;int&gt; rightSideView(TreeNode *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Tree 18 Left View<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Print left-most node at each level.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>DFS Traversing left child before right child. Maintain the current level. If `level == result.size()`, append the node value to the result list.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void recursion(Node *root, int level, vector&lt;int&gt; &amp;res) {&#10;    if(root==NULL) return ;&#10;    if(res.size() == level) res.push_back(root-&gt;data);&#10;    recursion(root-&gt;left, level + 1, res);&#10;    recursion(root-&gt;right, level + 1, res);&#10;}&#10;vector&lt;int&gt; leftView(Node *root) {&#10;    vector&lt;int&gt; res;&#10;    recursion(root, 0, res);&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Tree 19 Construct Tree From Inorder And Postorder<br><br></b> <a href="https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/" target="_blank">LeetCode 106</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]<br><b>Output:</b> [3,9,20,null,null,15,7]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Store inorder indices in a HashMap. The last element in postorder is the root. Find this root in inorder map to determine left subtree size. Recursively build left and right subtrees by slicing array indices.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, int inStart, int inEnd, vector&lt;int&gt;&amp; postorder, int postStart, int postEnd, map&lt;int, int&gt;&amp; inMap) {&#10;    if(inStart &gt; inEnd || postStart &gt; postEnd) return NULL;&#10;    TreeNode* root = new TreeNode(postorder[postEnd]);&#10;    int inRoot = inMap[root-&gt;val];&#10;    int numsLeft = inRoot - inStart;&#10;    root-&gt;left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);&#10;    root-&gt;right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);&#10;    return root;&#10;}&#10;TreeNode* buildTree(vector&lt;int&gt;&amp; inorder, vector&lt;int&gt;&amp; postorder) {&#10;    map&lt;int, int&gt; inMap;&#10;    for(int i = 0; i &lt; inorder.size(); i++) inMap[inorder[i]] = i;&#10;    TreeNode* root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Tree 20 Serialize And Deserialize Binary Tree<br><br></b> <a href="https://leetcode.com/problems/serialize-and-deserialize-binary-tree/" target="_blank">LeetCode 297</a></td>
      <td rowspan="1"><b>Example 1:</b> Serialization/Deserialization.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use Level Order Traversal (BFS) using a queue. For serialization, append '#' for null nodes. For deserialization, split string by comma and use a queue to reconstruct the tree structure level by level.<br><br><b>Dependencies:</b> <code>#include <queue>\n#include <sstream></code></td>
      <td><b>Edge Cases:</b> <b>Empty Tree:</b> Serialized string is empty. Deserialize returns null.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Codec {&#10;public:&#10;    string serialize(TreeNode* root) {&#10;        if(!root) return &quot;&quot;;&#10;        string s = &quot;&quot;; queue&lt;TreeNode*&gt; q;&#10;        q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* curNode = q.front(); q.pop();&#10;            if(curNode==NULL) s.append(&quot;#,&quot;);&#10;            else { s.append(to_string(curNode-&gt;val) + &quot;,&quot;); q.push(curNode-&gt;left); q.push(curNode-&gt;right); }&#10;        }&#10;        return s;&#10;    }&#10;    TreeNode* deserialize(string data) {&#10;        if(data.empty()) return NULL;&#10;        stringstream s(data); string str;&#10;        getline(s, str, &#x27;,&#x27;);&#10;        TreeNode* root = new TreeNode(stoi(str));&#10;        queue&lt;TreeNode*&gt; q; q.push(root);&#10;        while(!q.empty()) {&#10;            TreeNode* node = q.front(); q.pop();&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;left = NULL;&#10;            else { TreeNode* leftNode = new TreeNode(stoi(str)); node-&gt;left = leftNode; q.push(leftNode); }&#10;            getline(s, str, &#x27;,&#x27;);&#10;            if(str == &quot;#&quot;) node-&gt;right = NULL;&#10;            else { TreeNode* rightNode = new TreeNode(stoi(str)); node-&gt;right = rightNode; q.push(rightNode); }&#10;        }&#10;        return root;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Tree 21 Flatten Binary Tree To Linked List<br><br></b> <a href="https://leetcode.com/problems/flatten-binary-tree-to-linked-list/" target="_blank">LeetCode 114</a></td>
      <td rowspan="1"><b>Example 1:</b> In-place flatten.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Morris Traversal. If node has a left child, find the rightmost node of the left subtree. Point its right to current node's right. Move current node's left to its right, and set left to null. Move to current's right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void flatten(TreeNode* root) {&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;left) {&#10;            TreeNode* pre = curr-&gt;left;&#10;            while(pre-&gt;right) pre = pre-&gt;right;&#10;            pre-&gt;right = curr-&gt;right;&#10;            curr-&gt;right = curr-&gt;left;&#10;            curr-&gt;left = NULL;&#10;        }&#10;        curr = curr-&gt;right;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Tree 22 Kth Smallest Element In A BST<br><br></b> <a href="https://leetcode.com/problems/kth-smallest-element-in-a-bst/" target="_blank">LeetCode 230</a></td>
      <td rowspan="1"><b>Example 1:</b> Inorder traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) using Morris Traversal</td>
      <td>Inorder traversal of BST gives sorted elements. Keep a counter, when it reaches K, store the result. Morris Traversal can do this in O(1) space.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(TreeNode* root, int k) {&#10;    int count = 0, ans = -1;&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;left == NULL) {&#10;            count++;&#10;            if(count == k) ans = curr-&gt;val;&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            TreeNode* pre = curr-&gt;left;&#10;            while(pre-&gt;right &amp;&amp; pre-&gt;right != curr) pre = pre-&gt;right;&#10;            if(pre-&gt;right == NULL) {&#10;                pre-&gt;right = curr;&#10;                curr = curr-&gt;left;&#10;            } else {&#10;                pre-&gt;right = NULL;&#10;                count++;&#10;                if(count == k) ans = curr-&gt;val;&#10;                curr = curr-&gt;right;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Tree 23 Lowest Common Ancestor Of A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/" target="_blank">LeetCode 235</a></td>
      <td rowspan="1"><b>Example 1:</b> Exploit BST property.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>If both `p` and `q` are less than root, LCA is in the left subtree. If both are greater, LCA is in the right subtree. Otherwise, the current node is the LCA.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {&#10;    while(root) {&#10;        if(root-&gt;val &gt; p-&gt;val &amp;&amp; root-&gt;val &gt; q-&gt;val) root = root-&gt;left;&#10;        else if(root-&gt;val &lt; p-&gt;val &amp;&amp; root-&gt;val &lt; q-&gt;val) root = root-&gt;right;&#10;        else return root;&#10;    }&#10;    return NULL;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Tree 24 Insert Into A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/insert-into-a-binary-search-tree/" target="_blank">LeetCode 701</a></td>
      <td rowspan="1"><b>Example 1:</b> Traverse and insert.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>Traverse left or right depending on the value. Keep track of parent. Insert as left or right child of parent when a null pointer is reached.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* insertIntoBST(TreeNode* root, int val) {&#10;    if(!root) return new TreeNode(val);&#10;    TreeNode* curr = root;&#10;    while(true) {&#10;        if(val &lt; curr-&gt;val) {&#10;            if(curr-&gt;left) curr = curr-&gt;left;&#10;            else { curr-&gt;left = new TreeNode(val); break; }&#10;        } else {&#10;            if(curr-&gt;right) curr = curr-&gt;right;&#10;            else { curr-&gt;right = new TreeNode(val); break; }&#10;        }&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Tree 25 Delete Node In A BST<br><br></b> <a href="https://leetcode.com/problems/delete-node-in-a-bst/" target="_blank">LeetCode 450</a></td>
      <td rowspan="1"><b>Example 1:</b> Locate and delete.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(H) or O(1)</td>
      <td>Find the node. If it has no left child, return right child. If no right, return left. If both exist, find the right child of the rightmost node in the left subtree, and point it to the node's right child. Return the node's left child.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* helper(TreeNode* root) {&#10;    if(!root-&gt;left) return root-&gt;right;&#10;    if(!root-&gt;right) return root-&gt;left;&#10;    TreeNode* rightChild = root-&gt;right;&#10;    TreeNode* lastRight = root-&gt;left;&#10;    while(lastRight-&gt;right) lastRight = lastRight-&gt;right;&#10;    lastRight-&gt;right = rightChild;&#10;    return root-&gt;left;&#10;}&#10;TreeNode* deleteNode(TreeNode* root, int key) {&#10;    if(!root) return NULL;&#10;    if(root-&gt;val == key) return helper(root);&#10;    TreeNode* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;val &gt; key) {&#10;            if(curr-&gt;left &amp;&amp; curr-&gt;left-&gt;val == key) {&#10;                curr-&gt;left = helper(curr-&gt;left);&#10;                break;&#10;            } else curr = curr-&gt;left;&#10;        } else {&#10;            if(curr-&gt;right &amp;&amp; curr-&gt;right-&gt;val == key) {&#10;                curr-&gt;right = helper(curr-&gt;right);&#10;                break;&#10;            } else curr = curr-&gt;right;&#10;        }&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Tree 26 Inorder Successor In BST<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Find next greater.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>Traverse BST. If `curr.val > node.val`, then `curr` is a potential successor, store it and move left to find smaller. Else, move right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* inOrderSuccessor(TreeNode *root, TreeNode *x) {&#10;    TreeNode* successor = NULL;&#10;    while(root) {&#10;        if(root-&gt;val &lt;= x-&gt;val) {&#10;            root = root-&gt;right;&#10;        } else {&#10;            successor = root;&#10;            root = root-&gt;left;&#10;        }&#10;    }&#10;    return successor;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Tree 27 Two Sum IV Input Is A BST<br><br></b> <a href="https://leetcode.com/problems/two-sum-iv-input-is-a-bst/" target="_blank">LeetCode 653</a></td>
      <td rowspan="1"><b>Example 1:</b> BST Iterator two pointer.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use two BST iterators: one for normal inorder (next) and one for reverse inorder (before). Apply two-pointer approach like in a sorted array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class BSTIterator {&#10;    stack&lt;TreeNode*&gt; st;&#10;    bool reverse;&#10;    void pushAll(TreeNode* node) {&#10;        while(node) {&#10;            st.push(node);&#10;            if(reverse) node = node-&gt;right;&#10;            else node = node-&gt;left;&#10;        }&#10;    }&#10;public:&#10;    BSTIterator(TreeNode* root, bool isReverse) {&#10;        reverse = isReverse;&#10;        pushAll(root);&#10;    }&#10;    int next() {&#10;        TreeNode* tmpNode = st.top();&#10;        st.pop();&#10;        if(reverse) pushAll(tmpNode-&gt;left);&#10;        else pushAll(tmpNode-&gt;right);&#10;        return tmpNode-&gt;val;&#10;    }&#10;};&#10;bool findTarget(TreeNode* root, int k) {&#10;    if(!root) return false;&#10;    BSTIterator l(root, false);&#10;    BSTIterator r(root, true);&#10;    int i = l.next();&#10;    int j = r.next();&#10;    while(i &lt; j) {&#10;        if(i + j == k) return true;&#10;        else if(i + j &lt; k) i = l.next();&#10;        else j = r.next();&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Tree 28 Recover Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/recover-binary-search-tree/" target="_blank">LeetCode 99</a></td>
      <td rowspan="1"><b>Example 1:</b> Inorder traversal tracking anomalies.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Inorder traversal of BST gives sorted array. If two are swapped, there will be 1 or 2 anomalies where `prev->val > curr->val`. First anomaly: `first = prev`, `middle = curr`. Second anomaly: `last = curr`. Swap `first` and `last` (or `first` and `middle` if adjacent).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode *first, *prev, *middle, *last;&#10;void inorder(TreeNode* root) {&#10;    if(root == NULL) return;&#10;    inorder(root-&gt;left);&#10;    if(prev != NULL &amp;&amp; (root-&gt;val &lt; prev-&gt;val)) {&#10;        if(first == NULL) {&#10;            first = prev;&#10;            middle = root;&#10;        } else {&#10;            last = root;&#10;        }&#10;    }&#10;    prev = root;&#10;    inorder(root-&gt;right);&#10;}&#10;void recoverTree(TreeNode* root) {&#10;    first = middle = last = NULL;&#10;    prev = new TreeNode(INT_MIN);&#10;    inorder(root);&#10;    if(first &amp;&amp; last) swap(first-&gt;val, last-&gt;val);&#10;    else if(first &amp;&amp; middle) swap(first-&gt;val, middle-&gt;val);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Tree 29 Largest BST In Binary Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-bst/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Bottom-up verification.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Return `[minNode, maxNode, maxSize]` from each subtree. For current node, if `left.max < node.val < right.min`, it's a BST. Return `[min(node.val, left.min), max(node.val, right.max), left.size + right.size + 1]`. Else, it's not a BST, return `[-inf, inf, max(left.size, right.size)]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class NodeValue {&#10;public:&#10;    int maxNode, minNode, maxSize;&#10;    NodeValue(int minNode, int maxNode, int maxSize) {&#10;        this-&gt;maxNode = maxNode;&#10;        this-&gt;minNode = minNode;&#10;        this-&gt;maxSize = maxSize;&#10;    }&#10;};&#10;NodeValue largestBSTSubtreeHelper(Node* root) {&#10;    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);&#10;    auto left = largestBSTSubtreeHelper(root-&gt;left);&#10;    auto right = largestBSTSubtreeHelper(root-&gt;right);&#10;    if(left.maxNode &lt; root-&gt;data &amp;&amp; root-&gt;data &lt; right.minNode) {&#10;        return NodeValue(min(root-&gt;data, left.minNode), max(root-&gt;data, right.maxNode), left.maxSize + right.maxSize + 1);&#10;    }&#10;    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));&#10;}&#10;int largestBst(Node *root) {&#10;    return largestBSTSubtreeHelper(root).maxSize;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Tree 30 Maximum Sum BST In Binary Tree<br><br></b> <a href="https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/" target="_blank">LeetCode 1373</a></td>
      <td rowspan="1"><b>Example 1:</b> Similar to largest BST.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Bottom-up traversal. Return `[isBST, minNode, maxNode, sum]`. Update global max sum when valid BST is found.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Info {&#10;    bool isBST;&#10;    int minNode, maxNode, sum;&#10;};&#10;int maxSum = 0;&#10;Info solve(TreeNode* root) {&#10;    if(!root) return {true, INT_MAX, INT_MIN, 0};&#10;    Info left = solve(root-&gt;left);&#10;    Info right = solve(root-&gt;right);&#10;    if(left.isBST &amp;&amp; right.isBST &amp;&amp; left.maxNode &lt; root-&gt;val &amp;&amp; root-&gt;val &lt; right.minNode) {&#10;        int currSum = left.sum + right.sum + root-&gt;val;&#10;        maxSum = max(maxSum, currSum);&#10;        return {true, min(root-&gt;val, left.minNode), max(root-&gt;val, right.maxNode), currSum};&#10;    }&#10;    return {false, INT_MIN, INT_MAX, max(left.sum, right.sum)};&#10;}&#10;int maxSumBST(TreeNode* root) {&#10;    maxSum = 0;&#10;    solve(root);&#10;    return maxSum &gt; 0 ? maxSum : 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Tree 31 Kth Largest Element In A BST<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Reverse inorder traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Kth largest is Kth element in reverse inorder traversal (Right, Root, Left). Maintain a counter `k`. When visiting a node, decrement `k`. If `k == 0`, current node is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ans = -1;&#10;void reverseInorder(Node* root, int&amp; k) {&#10;    if(!root || k == 0) return;&#10;    reverseInorder(root-&gt;right, k);&#10;    k--;&#10;    if(k == 0) {&#10;        ans = root-&gt;data;&#10;        return;&#10;    }&#10;    reverseInorder(root-&gt;left, k);&#10;}&#10;int kthLargest(Node *root, int K) {&#10;    ans = -1;&#10;    reverseInorder(root, K);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Tree 32 Predecessor And Successor In BST<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Search down the tree.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>For Successor: search for key. If node->val <= key, go right. If node->val > key, update succ = node, go left. For Predecessor: If node->val >= key, go left. If node->val < key, update pred = node, go right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findPreSuc(Node* root, Node*&amp; pre, Node*&amp; suc, int key) {&#10;    Node* curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;key &gt; key) {&#10;            suc = curr;&#10;            curr = curr-&gt;left;&#10;        } else {&#10;            curr = curr-&gt;right;&#10;        }&#10;    }&#10;    curr = root;&#10;    while(curr) {&#10;        if(curr-&gt;key &lt; key) {&#10;            pre = curr;&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            curr = curr-&gt;left;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Tree 33 Construct BST From Preorder Traversal<br><br></b> <a href="https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/" target="_blank">LeetCode 1008</a></td>
      <td rowspan="1"><b>Example 1:</b> Upper bound tracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use an upper bound value. `build(preorder, index, bound)`: If index >= len or preorder[index] > bound, return NULL. Create root with preorder[index]. `root->left = build(..., root->val)`. `root->right = build(..., bound)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* bstFromPreorder(vector&lt;int&gt;&amp; preorder) {&#10;    int i = 0;&#10;    return build(preorder, i, INT_MAX);&#10;}&#10;TreeNode* build(vector&lt;int&gt;&amp; A, int&amp; i, int bound) {&#10;    if(i == A.size() || A[i] &gt; bound) return NULL;&#10;    TreeNode* root = new TreeNode(A[i++]);&#10;    root-&gt;left = build(A, i, root-&gt;val);&#10;    root-&gt;right = build(A, i, bound);&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Tree 34 All Nodes Distance K In Binary Tree<br><br></b> <a href="https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/" target="_blank">LeetCode 863</a></td>
      <td rowspan="1"><b>Example 1:</b> Convert to graph or use parent pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Perform BFS/DFS to map each node to its parent. Then, start a BFS from the target node, visiting left, right, and parent. Track visited nodes. After `k` levels in BFS, the current queue holds the answer.<br><br><b>Dependencies:</b> <code>#include <unordered_map>\n#include <queue>\n#include <unordered_set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void markParents(TreeNode* root, unordered_map&lt;TreeNode*, TreeNode*&gt;&amp; parent_track) {&#10;    queue&lt;TreeNode*&gt; queue;&#10;    queue.push(root);&#10;    while(!queue.empty()) {&#10;        TreeNode* current = queue.front();&#10;        queue.pop();&#10;        if(current-&gt;left) {&#10;            parent_track[current-&gt;left] = current;&#10;            queue.push(current-&gt;left);&#10;        }&#10;        if(current-&gt;right) {&#10;            parent_track[current-&gt;right] = current;&#10;            queue.push(current-&gt;right);&#10;        }&#10;    }&#10;}&#10;vector&lt;int&gt; distanceK(TreeNode* root, TreeNode* target, int k) {&#10;    unordered_map&lt;TreeNode*, TreeNode*&gt; parent_track;&#10;    markParents(root, parent_track);&#10;    unordered_map&lt;TreeNode*, bool&gt; visited;&#10;    queue&lt;TreeNode*&gt; queue;&#10;    queue.push(target);&#10;    visited[target] = true;&#10;    int curr_level = 0;&#10;    while(!queue.empty()) {&#10;        int size = queue.size();&#10;        if(curr_level++ == k) break;&#10;        for(int i=0; i&lt;size; i++) {&#10;            TreeNode* current = queue.front();&#10;            queue.pop();&#10;            if(current-&gt;left &amp;&amp; !visited[current-&gt;left]) {&#10;                queue.push(current-&gt;left);&#10;                visited[current-&gt;left] = true;&#10;            }&#10;            if(current-&gt;right &amp;&amp; !visited[current-&gt;right]) {&#10;                queue.push(current-&gt;right);&#10;                visited[current-&gt;right] = true;&#10;            }&#10;            if(parent_track[current] &amp;&amp; !visited[parent_track[current]]) {&#10;                queue.push(parent_track[current]);&#10;                visited[parent_track[current]] = true;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; result;&#10;    while(!queue.empty()) {&#10;        TreeNode* current = queue.front(); queue.pop();&#10;        result.push_back(current-&gt;val);&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Tree 35 Amount Of Time For Binary Tree To Be Infected<br><br></b> <a href="https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/" target="_blank">LeetCode 2385</a></td>
      <td rowspan="1"><b>Example 1:</b> Parent pointers and BFS.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Same as 'Distance K' problem. Map parents. Find the start node. Perform BFS from start node. The time taken is the number of levels in BFS until all reachable nodes are visited.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* markParents(TreeNode* root, unordered_map&lt;TreeNode*, TreeNode*&gt;&amp; m, int start) {&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(root);&#10;    TreeNode* res;&#10;    while(!q.empty()) {&#10;        TreeNode* node = q.front(); q.pop();&#10;        if(node-&gt;val == start) res = node;&#10;        if(node-&gt;left) {&#10;            m[node-&gt;left] = node;&#10;            q.push(node-&gt;left);&#10;        }&#10;        if(node-&gt;right) {&#10;            m[node-&gt;right] = node;&#10;            q.push(node-&gt;right);&#10;        }&#10;    }&#10;    return res;&#10;}&#10;int amountOfTime(TreeNode* root, int start) {&#10;    unordered_map&lt;TreeNode*, TreeNode*&gt; m;&#10;    TreeNode* target = markParents(root, m, start);&#10;    unordered_map&lt;TreeNode*, int&gt; vis;&#10;    queue&lt;TreeNode*&gt; q;&#10;    q.push(target);&#10;    vis[target] = 1;&#10;    int maxi = 0;&#10;    while(!q.empty()) {&#10;        int sz = q.size();&#10;        int fl = 0;&#10;        for(int i=0; i&lt;sz; i++) {&#10;            auto node = q.front(); q.pop();&#10;            if(node-&gt;left &amp;&amp; !vis[node-&gt;left]) {&#10;                fl = 1;&#10;                vis[node-&gt;left] = 1;&#10;                q.push(node-&gt;left);&#10;            }&#10;            if(node-&gt;right &amp;&amp; !vis[node-&gt;right]) {&#10;                fl = 1;&#10;                vis[node-&gt;right] = 1;&#10;                q.push(node-&gt;right);&#10;            }&#10;            if(m[node] &amp;&amp; !vis[m[node]]) {&#10;                fl = 1;&#10;                vis[m[node]] = 1;&#10;                q.push(m[node]);&#10;            }&#10;        }&#10;        if(fl) maxi++;&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Tree 36 Count Complete Tree Nodes<br><br></b> <a href="https://leetcode.com/problems/count-complete-tree-nodes/" target="_blank">LeetCode 222</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive with Height check.</td>
      <td><b>Time:</b> O(log^2 N)<br><b>Space:</b> O(log N)</td>
      <td>Compute the left height (following left child) and right height (following right child) of the tree. If they are equal, the tree is a full binary tree, and the number of nodes is `2^h - 1`. If they are not equal, recursively count the nodes in the left and right subtrees and add 1 for the root.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int getLeftHeight(TreeNode* node) {&#10;    int h = 0;&#10;    while(node) {&#10;        h++;&#10;        node = node-&gt;left;&#10;    }&#10;    return h;&#10;}&#10;int getRightHeight(TreeNode* node) {&#10;    int h = 0;&#10;    while(node) {&#10;        h++;&#10;        node = node-&gt;right;&#10;    }&#10;    return h;&#10;}&#10;int countNodes(TreeNode* root) {&#10;    if(!root) return 0;&#10;    int lh = getLeftHeight(root);&#10;    int rh = getRightHeight(root);&#10;    if(lh == rh) return (1 &lt;&lt; lh) - 1;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Tree 37 Morris Preorder Traversal<br><br></b> <a href="https://leetcode.com/problems/binary-tree-preorder-traversal/" target="_blank">LeetCode 144</a></td>
      <td rowspan="1"><b>Example 1:</b> Threaded Binary Tree.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Similar to Morris Inorder. If left child is null, process current, move right. Else, find predecessor. If predecessor's right is null, process current, make thread, move left. If predecessor's right is current, remove thread, move right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; preorderTraversal(TreeNode* root) {&#10;    vector&lt;int&gt; preorder;&#10;    TreeNode* curr = root;&#10;    while(curr != NULL) {&#10;        if(curr-&gt;left == NULL) {&#10;            preorder.push_back(curr-&gt;val);&#10;            curr = curr-&gt;right;&#10;        } else {&#10;            TreeNode* prev = curr-&gt;left;&#10;            while(prev-&gt;right &amp;&amp; prev-&gt;right != curr) {&#10;                prev = prev-&gt;right;&#10;            }&#10;            if(prev-&gt;right == NULL) {&#10;                prev-&gt;right = curr;&#10;                preorder.push_back(curr-&gt;val);&#10;                curr = curr-&gt;left;&#10;            } else {&#10;                prev-&gt;right = NULL;&#10;                curr = curr-&gt;right;&#10;            }&#10;        }&#10;    }&#10;    return preorder;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Tree 38 Search In A Binary Search Tree<br><br></b> <a href="https://leetcode.com/problems/search-in-a-binary-search-tree/" target="_blank">LeetCode 700</a></td>
      <td rowspan="1"><b>Example 1:</b> Iterative or Recursive.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>Start at root. If root is null or its value is `val`, return root. If `val < root.val`, go left. Else go right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* searchBST(TreeNode* root, int val) {&#10;    while(root != NULL &amp;&amp; root-&gt;val != val) {&#10;        root = val &lt; root-&gt;val ? root-&gt;left : root-&gt;right;&#10;    }&#10;    return root;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Tree 39 Find Minimum In Binary Search Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Leftmost node.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>Traverse the left children until a node with no left child is reached. That node contains the minimum value.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minValue(TreeNode* root) {&#10;    if(root == NULL) return -1;&#10;    while(root-&gt;left != NULL) {&#10;        root = root-&gt;left;&#10;    }&#10;    return root-&gt;val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Tree 40 Inorder Successor In BST<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Iterative search.</td>
      <td><b>Time:</b> O(H)<br><b>Space:</b> O(1)</td>
      <td>Start from root. If `p.val >= root.val`, the successor must be in the right subtree (`root = root.right`). If `p.val < root.val`, the current root could be the successor, so record it and search the left subtree for a closer successor (`successor = root; root = root.left`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {&#10;    TreeNode* successor = NULL;&#10;    while(root != NULL) {&#10;        if(p-&gt;val &gt;= root-&gt;val) {&#10;            root = root-&gt;right;&#10;        } else {&#10;            successor = root;&#10;            root = root-&gt;left;&#10;        }&#10;    }&#10;    return successor;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Tree 41 Construct Binary Tree From String With Bracket Representation<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Iterate through string. If digit or sign, parse number and create node. If '(', continue. If node created, push to stack. If ')', pop from stack. If it has a parent, attach it (left first, then right).<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">TreeNode* treeFromString(string s) {&#10;    if(s.empty()) return NULL;&#10;    stack&lt;TreeNode*&gt; st;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        if(s[i] == &#x27;)&#x27;) {&#10;            st.pop();&#10;        } else if(s[i] &gt;= &#x27;0&#x27; &amp;&amp; s[i] &lt;= &#x27;9&#x27; || s[i] == &#x27;-&#x27;) {&#10;            int j = i;&#10;            while(j &lt; s.length() &amp;&amp; (s[j] &gt;= &#x27;0&#x27; &amp;&amp; s[j] &lt;= &#x27;9&#x27; || s[j] == &#x27;-&#x27;)) j++;&#10;            int num = stoi(s.substr(i, j - i));&#10;            TreeNode* node = new TreeNode(num);&#10;            if(!st.empty()) {&#10;                TreeNode* parent = st.top();&#10;                if(!parent-&gt;left) parent-&gt;left = node;&#10;                else parent-&gt;right = node;&#10;            }&#10;            st.push(node);&#10;            i = j - 1;&#10;        }&#10;    }&#10;    while(st.size() &gt; 1) st.pop();&#10;    return st.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Tree 42 Transform To Sum Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Postorder Traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Recursively get the sum of the left subtree and right subtree. Update current node's value to the sum of left and right. Return the old value of current node + sum of left + sum of right to the caller.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int toSumTree(TreeNode* root) {&#10;    if(!root) return 0;&#10;    int leftSum = toSumTree(root-&gt;left);&#10;    int rightSum = toSumTree(root-&gt;right);&#10;    int oldVal = root-&gt;val;&#10;    root-&gt;val = leftSum + rightSum;&#10;    return root-&gt;val + oldVal;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Tree 43 Diagonal Traversal Of Binary Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Queue based.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a queue. Push root. Then loop: Pop a node `curr`. While `curr` is not null, add its value to result, push `curr->left` to queue, and move to `curr->right`.<br><br><b>Dependencies:</b> Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; diagonal(Node *root) {&#10;    vector&lt;int&gt; res;&#10;    if(!root) return res;&#10;    queue&lt;Node*&gt; q;&#10;    q.push(root);&#10;    while(!q.empty()) {&#10;        Node* curr = q.front();&#10;        q.pop();&#10;        while(curr) {&#10;            res.push_back(curr-&gt;data);&#10;            if(curr-&gt;left) q.push(curr-&gt;left);&#10;            curr = curr-&gt;right;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Tree 44 Convert Binary Tree Into Doubly Linked List<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS Inorder, maintaining a `prev` pointer.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Perform Inorder traversal. Maintain a `prev` pointer (initially null). At each node: if `prev == null`, this node is the head of DLL. Else, `prev->right = node` and `node->left = prev`. Update `prev = node`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bToDLLHelper(Node* root, Node*&amp; head, Node*&amp; prev) {&#10;    if(!root) return;&#10;    bToDLLHelper(root-&gt;left, head, prev);&#10;    if(prev == NULL) {&#10;        head = root;&#10;    } else {&#10;        root-&gt;left = prev;&#10;        prev-&gt;right = root;&#10;    }&#10;    prev = root;&#10;    bToDLLHelper(root-&gt;right, head, prev);&#10;}&#10;Node *bToDLL(Node *root) {&#10;    Node* head = NULL;&#10;    Node* prev = NULL;&#10;    bToDLLHelper(root, head, prev);&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">Tree 45 Check If Tree Is Isomorphic<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Check swapped and unswapped subtrees.</td>
      <td><b>Time:</b> O(min(M, N))<br><b>Space:</b> O(min(H1, H2))</td>
      <td>Two trees are isomorphic if one can be obtained from another by a series of flips. If roots are null, return true. If values don't match, false. Then check `(isIsomorphic(n1.left, n2.left) && isIsomorphic(n1.right, n2.right))` OR `(isIsomorphic(n1.left, n2.right) && isIsomorphic(n1.right, n2.left))`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isIsomorphic(Node *root1, Node *root2) {&#10;    if(!root1 &amp;&amp; !root2) return true;&#10;    if(!root1 || !root2) return false;&#10;    if(root1-&gt;data != root2-&gt;data) return false;&#10;    bool no_swap = isIsomorphic(root1-&gt;left, root2-&gt;left) &amp;&amp; isIsomorphic(root1-&gt;right, root2-&gt;right);&#10;    bool swap_case = isIsomorphic(root1-&gt;left, root2-&gt;right) &amp;&amp; isIsomorphic(root1-&gt;right, root2-&gt;left);&#10;    return no_swap || swap_case;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">Tree 46 Min Distance Between Two Given Nodes Of A Binary Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Find LCA, then distance from LCA to nodes.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>1. Find LCA of the two nodes. 2. Find distance from LCA to node 1. 3. Find distance from LCA to node 2. 4. Return the sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* lca(Node* root, int a, int b) {&#10;    if(!root || root-&gt;data == a || root-&gt;data == b) return root;&#10;    Node* left = lca(root-&gt;left, a, b);&#10;    Node* right = lca(root-&gt;right, a, b);&#10;    if(!left) return right;&#10;    if(!right) return left;&#10;    return root;&#10;}&#10;int findDist(Node* root, int val, int dist) {&#10;    if(!root) return -1;&#10;    if(root-&gt;data == val) return dist;&#10;    int d = findDist(root-&gt;left, val, dist + 1);&#10;    if(d != -1) return d;&#10;    return findDist(root-&gt;right, val, dist + 1);&#10;}&#10;int findDist(Node* root, int a, int b) {&#10;    Node* lca_node = lca(root, a, b);&#10;    int d1 = findDist(lca_node, a, 0);&#10;    int d2 = findDist(lca_node, b, 0);&#10;    return d1 + d2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">Tree 47 Binary Tree To Cdll<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Inorder traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Perform an inorder traversal. Maintain a `prev` pointer. If `prev` is NULL, it's the `head`. Else, set `prev->right = curr` and `curr->left = prev`. Update `prev = curr`. Finally, connect `head` and `prev` (the tail).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(Node* root, Node*&amp; prev, Node*&amp; head) {&#10;    if(!root) return;&#10;    inorder(root-&gt;left, prev, head);&#10;    if(!head) head = root;&#10;    else {&#10;        prev-&gt;right = root;&#10;        root-&gt;left = prev;&#10;    }&#10;    prev = root;&#10;    inorder(root-&gt;right, prev, head);&#10;}&#10;Node* bTreeToCList(Node* root) {&#10;    Node* head = NULL;&#10;    Node* prev = NULL;&#10;    inorder(root, prev, head);&#10;    if(head &amp;&amp; prev) {&#10;        head-&gt;left = prev;&#10;        prev-&gt;right = head;&#10;    }&#10;    return head;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">Tree 48 Construct Tree From Inorder And Preorder<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/construct-tree-1/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Hash map for fast search.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>The first element in preorder is the root. Find this root in inorder using a hash map. Elements to the left in inorder form the left subtree, elements to the right form the right subtree. Recurse.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* buildTreeUtil(int in[], int pre[], int inSt, int inEnd, int&amp; preIdx, unordered_map&lt;int, int&gt;&amp; mp) {&#10;    if(inSt &gt; inEnd) return NULL;&#10;    int curr = pre[preIdx++];&#10;    Node* tNode = new Node(curr);&#10;    if(inSt == inEnd) return tNode;&#10;    int inIdx = mp[curr];&#10;    tNode-&gt;left = buildTreeUtil(in, pre, inSt, inIdx - 1, preIdx, mp);&#10;    tNode-&gt;right = buildTreeUtil(in, pre, inIdx + 1, inEnd, preIdx, mp);&#10;    return tNode;&#10;}&#10;Node* buildTree(int in[], int pre[], int n) {&#10;    unordered_map&lt;int, int&gt; mp;&#10;    for(int i = 0; i &lt; n; i++) mp[in[i]] = i;&#10;    int preIdx = 0;&#10;    return buildTreeUtil(in, pre, 0, n - 1, preIdx, mp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">49</td>
      <td rowspan="1">Tree 49 Minimum Swap Required To Convert Binary Tree To Binary Search Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Graph cycle detection on Inorder.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>The inorder traversal of a BST is sorted. First, get the inorder traversal of the given complete binary tree using array indices. Then, the problem reduces to finding the minimum swaps to sort an array. Use graph cycles to find min swaps.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(vector&lt;int&gt;&amp; a, vector&lt;int&gt;&amp; v, int n, int index) {&#10;    if(index &gt;= n) return;&#10;    inorder(a, v, n, 2 * index + 1);&#10;    v.push_back(a[index]);&#10;    inorder(a, v, n, 2 * index + 2);&#10;}&#10;int minSwaps(vector&lt;int&gt;&amp; A, int n) {&#10;    vector&lt;int&gt; v;&#10;    inorder(A, v, n, 0);&#10;    vector&lt;pair&lt;int, int&gt;&gt; t(n);&#10;    for(int i = 0; i &lt; n; i++) t[i] = {v[i], i};&#10;    sort(t.begin(), t.end());&#10;    int ans = 0;&#10;    vector&lt;bool&gt; vis(n, false);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(vis[i] || t[i].second == i) continue;&#10;        int cycle_size = 0, j = i;&#10;        while(!vis[j]) {&#10;            vis[j] = true;&#10;            j = t[j].second;&#10;            cycle_size++;&#10;        }&#10;        if(cycle_size &gt; 0) ans += (cycle_size - 1);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">50</td>
      <td rowspan="1">Tree 50 Check If Binary Tree Is Sum Tree Or Not<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sum-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive check.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use a recursive function. A leaf node is always a SumTree. For an internal node, calculate the sum of its left and right subtrees. If its value equals the sum, and both subtrees are SumTrees, return true.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">pair&lt;bool, int&gt; isSumTreeFast(Node* root) {&#10;    if(!root) return {true, 0};&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) return {true, root-&gt;data};&#10;    pair&lt;bool, int&gt; leftAns = isSumTreeFast(root-&gt;left);&#10;    pair&lt;bool, int&gt; rightAns = isSumTreeFast(root-&gt;right);&#10;    bool isSum = (root-&gt;data == leftAns.second + rightAns.second);&#10;    if(leftAns.first &amp;&amp; rightAns.first &amp;&amp; isSum) {&#10;        return {true, 2 * root-&gt;data};&#10;    } else {&#10;        return {false, 0};&#10;    }&#10;}&#10;bool isSumTree(Node* root) {&#10;    return isSumTreeFast(root).first;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">51</td>
      <td rowspan="1">Tree 51 Check If All Leaf Nodes Are At Same Level Or Not<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive check with global variable.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Traverse the tree, maintaining the current level. The first time a leaf is encountered, store its level. For subsequent leaves, compare their level with the stored level. If any mismatch occurs, return false.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkUtil(Node* root, int level, int&amp; leafLevel) {&#10;    if(!root) return true;&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) {&#10;        if(leafLevel == 0) {&#10;            leafLevel = level;&#10;            return true;&#10;        }&#10;        return (level == leafLevel);&#10;    }&#10;    return checkUtil(root-&gt;left, level + 1, leafLevel) &amp;&amp; checkUtil(root-&gt;right, level + 1, leafLevel);&#10;}&#10;bool check(Node *root) {&#10;    int leafLevel = 0;&#10;    return checkUtil(root, 1, leafLevel);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">52</td>
      <td rowspan="1">Tree 52 Check If A Binary Tree Contains Duplicate Subtrees Of Size 2 Or More<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> String serialization.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Serialize each subtree into a string. Use a hash map to store the frequencies of the serialized strings. If any string (of length > 3 to ignore leaves) has a frequency > 1, a duplicate subtree exists.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string solve(Node* root, unordered_map&lt;string, int&gt;&amp; m) {&#10;    if(!root) return &quot;$&quot;;&#10;    string s = &quot;&quot;;&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) {&#10;        s += to_string(root-&gt;data);&#10;        return s;&#10;    }&#10;    s = s + to_string(root-&gt;data) + &quot;-&quot; + solve(root-&gt;left, m) + &quot;-&quot; + solve(root-&gt;right, m);&#10;    m[s]++;&#10;    return s;&#10;}&#10;int dupSub(Node *root) {&#10;    unordered_map&lt;string, int&gt; m;&#10;    solve(root, m);&#10;    for(auto it : m) {&#10;        if(it.second &gt;= 2) return 1;&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">53</td>
      <td rowspan="1">Tree 53 Check If 2 Trees Are Mirror Or Not<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Stack and Queue.</td>
      <td><b>Time:</b> O(E)<br><b>Space:</b> O(E)</td>
      <td>Store the children of the first tree in a stack (LIFO) and the children of the second tree in a queue (FIFO) for each node using hash maps. Then compare if the stack top matches the queue front for all nodes.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int checkMirrorTree(int n, int e, int A[], int B[]) {&#10;    unordered_map&lt;int, stack&lt;int&gt;&gt; s;&#10;    unordered_map&lt;int, queue&lt;int&gt;&gt; q;&#10;    for(int i = 0; i &lt; 2 * e; i += 2) {&#10;        s[A[i]].push(A[i+1]);&#10;        q[B[i]].push(B[i+1]);&#10;    }&#10;    for(auto it : s) {&#10;        int node = it.first;&#10;        while(!s[node].empty() &amp;&amp; !q[node].empty()) {&#10;            if(s[node].top() != q[node].front()) return 0;&#10;            s[node].pop();&#10;            q[node].pop();&#10;        }&#10;        if(!s[node].empty() || !q[node].empty()) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">54</td>
      <td rowspan="1">Tree 54 Sum Of Nodes On The Longest Path From Root To Leaf Node<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use DFS. Keep track of the maximum length and the maximum sum. At each node, check if the current length is greater than max length. If so, update max length and max sum. If lengths are equal, update max sum if current sum is greater.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(Node* root, int sum, int&amp; maxSum, int len, int&amp; maxLen) {&#10;    if(!root) {&#10;        if(len &gt; maxLen) {&#10;            maxLen = len;&#10;            maxSum = sum;&#10;        } else if(len == maxLen) {&#10;            maxSum = max(sum, maxSum);&#10;        }&#10;        return;&#10;    }&#10;    sum = sum + root-&gt;data;&#10;    solve(root-&gt;left, sum, maxSum, len + 1, maxLen);&#10;    solve(root-&gt;right, sum, maxSum, len + 1, maxLen);&#10;}&#10;int sumOfLongRootToLeafPath(Node *root) {&#10;    int len = 0, maxLen = 0;&#10;    int sum = 0, maxSum = INT_MIN;&#10;    solve(root, sum, maxSum, len, maxLen);&#10;    return maxSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">55</td>
      <td rowspan="1">Tree 55 Kth Ancestor In A Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive backtracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use a recursive function. If the target node is found, return it. As you return back up the call stack, decrement `k`. When `k` becomes 0, the current node is the kth ancestor.</td>
      <td><b>Edge Cases:</b> k > depth<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">Node* solve(Node* root, int&amp; k, int node) {&#10;    if(!root) return NULL;&#10;    if(root-&gt;data == node) return root;&#10;    Node* left = solve(root-&gt;left, k, node);&#10;    Node* right = solve(root-&gt;right, k, node);&#10;    if(left || right) {&#10;        k--;&#10;        if(k == 0) {&#10;            k = INT_MAX;&#10;            return root;&#10;        }&#10;        return left ? left : right;&#10;    }&#10;    return NULL;&#10;}&#10;int kthAncestor(Node *root, int k, int node) {&#10;    Node* ans = solve(root, k, node);&#10;    if(!ans || ans-&gt;data == node) return -1;&#10;    return ans-&gt;data;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">56</td>
      <td rowspan="1">Tree 56 Find All Duplicate Subtrees In A Binary Tree<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Serialization + Hash Map.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Serialize each subtree into a string (e.g., using preorder traversal). Use a hash map to count the frequencies of these serialized strings. If a string appears exactly twice, add the root of that subtree to the result list.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string solve(Node* root, unordered_map&lt;string, int&gt;&amp; m, vector&lt;Node*&gt;&amp; ans) {&#10;    if(!root) return &quot;N&quot;;&#10;    string s = to_string(root-&gt;data) + &quot;,&quot; + solve(root-&gt;left, m, ans) + &quot;,&quot; + solve(root-&gt;right, m, ans);&#10;    m[s]++;&#10;    if(m[s] == 2) ans.push_back(root);&#10;    return s;&#10;}&#10;vector&lt;Node*&gt; printAllDups(Node* root) {&#10;    unordered_map&lt;string, int&gt; m;&#10;    vector&lt;Node*&gt; ans;&#10;    solve(root, m, ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">57</td>
      <td rowspan="1">Tree 57 Symmetric Tree<br><br></b> <a href="https://leetcode.com/problems/symmetric-tree/" target="_blank">LeetCode 101</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use a helper function `isMirror(left, right)`. The tree is symmetric if `root->left` and `root->right` are mirrors. Two trees are mirrors if their roots are equal and `left1->left` is mirror of `right1->right`, and `left1->right` is mirror of `right1->left`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isMirror(TreeNode* n1, TreeNode* n2) {&#10;    if(!n1 &amp;&amp; !n2) return true;&#10;    if(!n1 || !n2) return false;&#10;    return (n1-&gt;val == n2-&gt;val) &amp;&amp; isMirror(n1-&gt;left, n2-&gt;right) &amp;&amp; isMirror(n1-&gt;right, n2-&gt;left);&#10;}&#10;bool isSymmetric(TreeNode* root) {&#10;    if(!root) return true;&#10;    return isMirror(root-&gt;left, root-&gt;right);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">58</td>
      <td rowspan="1">Tree 58 Root To Node Path In Binary Tree<br><br></b> <a href="https://www.interviewbit.com/problems/path-to-given-node/" target="_blank">InterviewBit</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive backtracking.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>Use recursion. Push current node to the path array. If it's the target node, return true. Recursively search left and right subtrees. If either returns true, return true. If not found in either, pop the current node from the path array and return false.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool getPath(TreeNode* root, vector&lt;int&gt;&amp; arr, int x) {&#10;    if(!root) return false;&#10;    arr.push_back(root-&gt;val);&#10;    if(root-&gt;val == x) return true;&#10;    if(getPath(root-&gt;left, arr, x) || getPath(root-&gt;right, arr, x)) return true;&#10;    arr.pop_back();&#10;    return false;&#10;}&#10;vector&lt;int&gt; solve(TreeNode* A, int B) {&#10;    vector&lt;int&gt; arr;&#10;    if(!A) return arr;&#10;    getPath(A, arr, B);&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Heaps

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
      <td rowspan="1">Heap 01 Kth Largest Element In An Array<br><br></b> <a href="https://leetcode.com/problems/kth-largest-element-in-an-array/" target="_blank">LeetCode 215</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [3,2,1,5,6,4], k = 2<br><b>Output:</b> 5<br><br><b>Note (Constraint):</b> Can you solve it without sorting?</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td>Use a Min-Heap of size K. When the heap exceeds size K, pop the minimum element. The top of the heap will be the Kth largest.<br><br><b>Dependencies:</b> <code>std::priority_queue</code> / <code>heapq</code></td>
      <td><b>Edge Cases:</b> <b>Min-Heap sizing:</b> By strictly keeping the size to `k`, the `k` largest elements are trapped inside, with the smallest of them right at the top.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findKthLargest(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::priority_queue&lt;int, std::vector&lt;int&gt;, std::greater&lt;int&gt;&gt; minHeap;&#10;    for(int num : nums) {&#10;        minHeap.push(num);&#10;        if(minHeap.size() &gt; k) {&#10;            minHeap.pop();&#10;        }&#10;    }&#10;    return minHeap.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Heap 02 Merge K Sorted Lists<br><br></b> <a href="https://leetcode.com/problems/merge-k-sorted-lists/" target="_blank">LeetCode 23</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> lists = [[1,4,5],[1,3,4],[2,6]]<br><b>Output:</b> [1,1,2,3,4,4,5,6]</td>
      <td><b>Time:</b> O(N log K) (Constraint)<br><b>Space:</b> O(K) (Constraint)</td>
      <td>Push the head of each list into a Min-Heap. Repeatedly pop the smallest node, attach it to the result list, and push its `next` node into the heap.<br><br><b>Dependencies:</b> Custom Comparator</td>
      <td><b>Edge Cases:</b> <b>Pointer Compare:</b> Priority queues need a custom comparator to sort `ListNode*` by their `val`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Compare {&#10;    bool operator()(ListNode* a, ListNode* b) {&#10;        return a-&gt;val &gt; b-&gt;val;&#10;    }&#10;};&#10;&#10;ListNode* mergeKLists(std::vector&lt;ListNode*&gt;&amp; lists) {&#10;    std::priority_queue&lt;ListNode*, std::vector&lt;ListNode*&gt;, Compare&gt; pq;&#10;    for (auto list : lists) {&#10;        if (list) pq.push(list);&#10;    }&#10;    &#10;    ListNode* dummy = new ListNode(0);&#10;    ListNode* tail = dummy;&#10;    &#10;    while (!pq.empty()) {&#10;        ListNode* node = pq.top();&#10;        pq.pop();&#10;        tail-&gt;next = node;&#10;        tail = tail-&gt;next;&#10;        if (node-&gt;next) pq.push(node-&gt;next);&#10;    }&#10;    return dummy-&gt;next;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Heap 03 Top K Frequent Elements<br><br></b> <a href="https://leetcode.com/problems/top-k-frequent-elements/" target="_blank">LeetCode 347</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [1,1,1,2,2,3], k = 2<br><b>Output:</b> [1,2]</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(N)</td>
      <td>Use a Hash Map to count frequencies. Use a Min-Heap of size `k` to keep track of the top `k` elements.<br><br><b>Dependencies:</b> <code>std::priority_queue</code>, <code>heapq</code></td>
      <td><b>Edge Cases:</b> <b>Min-Heap capacity:</b> If heap size exceeds `k`, pop the top (which is the element with the lowest frequency currently in the heap).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; topKFrequent(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int num : nums) mpp[num]++;&#10;    std::priority_queue&lt;std::pair&lt;int, int&gt;, std::vector&lt;std::pair&lt;int, int&gt;&gt;, std::greater&lt;std::pair&lt;int, int&gt;&gt;&gt; pq;&#10;    for(auto it : mpp) {&#10;        pq.push({it.second, it.first});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top().second);&#10;        pq.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Heap 04 Kth Smallest Element In A Sorted Matrix<br><br></b> <a href="https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/" target="_blank">LeetCode 378</a></td>
      <td rowspan="1"><b>Example 1:</b> Binary search on range.</td>
      <td><b>Time:</b> O(N log(Max-Min))<br><b>Space:</b> O(1)</td>
      <td>Binary search on the value range `[matrix[0][0], matrix[n-1][n-1]]`. Count elements less than or equal to `mid` using two pointers (start from bottom-left). If count >= k, search left half, else search right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countLessOrEqual(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int mid, int n) {&#10;    int count = 0, row = n - 1, col = 0;&#10;    while(row &gt;= 0 &amp;&amp; col &lt; n) {&#10;        if(matrix[row][col] &lt;= mid) { count += row + 1; col++; }&#10;        else row--;&#10;    }&#10;    return count;&#10;}&#10;int kthSmallest(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int k) {&#10;    int n = matrix.size();&#10;    int low = matrix[0][0], high = matrix[n-1][n-1];&#10;    while(low &lt;= high) {&#10;        int mid = low + (high - low) / 2;&#10;        if(countLessOrEqual(matrix, mid, n) &gt;= k) high = mid - 1;&#10;        else low = mid + 1;&#10;    }&#10;    return low;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Heap 05 Find Median From Data Stream<br><br></b> <a href="https://leetcode.com/problems/find-median-from-data-stream/" target="_blank">LeetCode 295</a></td>
      <td rowspan="1"><b>Example 1:</b> Two heaps.</td>
      <td><b>Time:</b> O(log N) add, O(1) find<br><b>Space:</b> O(N)</td>
      <td>Maintain two heaps: a max-heap for the smaller half of numbers and a min-heap for the larger half. Balance them such that the max-heap has at most 1 more element than the min-heap.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class MedianFinder {&#10;    priority_queue&lt;int&gt; maxH;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; minH;&#10;public:&#10;    void addNum(int num) {&#10;        maxH.push(num);&#10;        minH.push(maxH.top());&#10;        maxH.pop();&#10;        if(maxH.size() &lt; minH.size()) {&#10;            maxH.push(minH.top());&#10;            minH.pop();&#10;        }&#10;    }&#10;    double findMedian() {&#10;        if(maxH.size() &gt; minH.size()) return maxH.top();&#10;        return (maxH.top() + minH.top()) / 2.0;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Heap 06 Replace Each Array Element By Its Corresponding Rank<br><br></b> <a href="https://leetcode.com/problems/rank-transform-of-an-array/" target="_blank">LeetCode 1331</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> [40,10,20,30]<br><b>Output:</b> [4,1,2,3]</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Create a copy of array, sort it, and remove duplicates. Use a hash map to map each unique value to its rank. Replace elements in original array using map.<br><br><b>Dependencies:</b> <code>#include <unordered_map>\n#include <set></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; arrayRankTransform(vector&lt;int&gt;&amp; arr) {&#10;    set&lt;int&gt; st(arr.begin(), arr.end());&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int rank = 1;&#10;    for(int num : st) mpp[num] = rank++;&#10;    vector&lt;int&gt; ans;&#10;    for(int num : arr) ans.push_back(mpp[num]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Heap 07 Task Scheduler<br><br></b> <a href="https://leetcode.com/problems/task-scheduler/" target="_blank">LeetCode 621</a></td>
      <td rowspan="1"><b>Example 1:</b> Greedy placement.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Find max frequency `max_f`. Calculate idle slots `(max_f - 1) * n`. Iterate remaining frequencies and subtract from idle slots. Return `tasks.length + max(0, idle_slots)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int leastInterval(vector&lt;char&gt;&amp; tasks, int n) {&#10;    vector&lt;int&gt; freq(26, 0);&#10;    int max_f = 0, count_max = 0;&#10;    for(char c : tasks) {&#10;        freq[c - &#x27;A&#x27;]++;&#10;        if(freq[c - &#x27;A&#x27;] &gt; max_f) {&#10;            max_f = freq[c - &#x27;A&#x27;];&#10;            count_max = 1;&#10;        } else if(freq[c - &#x27;A&#x27;] == max_f) count_max++;&#10;    }&#10;    int ans = (max_f - 1) * (n + 1) + count_max;&#10;    return max(ans, (int)tasks.size());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Heap 08 Hand Of Straights<br><br></b> <a href="https://leetcode.com/problems/hand-of-straights/" target="_blank">LeetCode 846</a></td>
      <td rowspan="1"><b>Example 1:</b> Form consecutive sequences.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Use a map (TreeMap in C++) to store frequencies. Iterate through map. If a number has count > 0, we must form a group starting from it. Decrement counts of `num, num+1, ..., num+groupSize-1`.<br><br><b>Dependencies:</b> <code>#include <map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isNStraightHand(vector&lt;int&gt;&amp; hand, int groupSize) {&#10;    if(hand.size() % groupSize != 0) return false;&#10;    map&lt;int, int&gt; mpp;&#10;    for(int card : hand) mpp[card]++;&#10;    for(auto it : mpp) {&#10;        if(it.second &gt; 0) {&#10;            int count = it.second;&#10;            for(int i=0; i&lt;groupSize; i++) {&#10;                if(mpp[it.first + i] &lt; count) return false;&#10;                mpp[it.first + i] -= count;&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Heap 09 Design Twitter<br><br></b> <a href="https://leetcode.com/problems/design-twitter/" target="_blank">LeetCode 355</a></td>
      <td rowspan="1"><b>Example 1:</b> Object oriented design.</td>
      <td><b>Time:</b> O(N log 10)<br><b>Space:</b> O(U + T)</td>
      <td>Use a hash map to map user to their followees. Use another map to map user to their tweets. For news feed, use a Max-Heap to extract the 10 most recent tweets from the user and their followees.<br><br><b>Dependencies:</b> <code>#include <unordered_map>\n#include <unordered_set>\n#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Twitter {&#10;    unordered_map&lt;int, unordered_set&lt;int&gt;&gt; followers;&#10;    unordered_map&lt;int, vector&lt;pair&lt;int, int&gt;&gt;&gt; tweets;&#10;    int time = 0;&#10;public:&#10;    Twitter() {}&#10;    void postTweet(int userId, int tweetId) {&#10;        tweets[userId].push_back({time++, tweetId});&#10;    }&#10;    vector&lt;int&gt; getNewsFeed(int userId) {&#10;        priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;        for(auto t : tweets[userId]) pq.push(t);&#10;        for(int f : followers[userId]) {&#10;            for(auto t : tweets[f]) pq.push(t);&#10;        }&#10;        vector&lt;int&gt; ans;&#10;        while(!pq.empty() &amp;&amp; ans.size() &lt; 10) {&#10;            ans.push_back(pq.top().second);&#10;            pq.pop();&#10;        }&#10;        return ans;&#10;    }&#10;    void follow(int followerId, int followeeId) {&#10;        followers[followerId].insert(followeeId);&#10;    }&#10;    void unfollow(int followerId, int followeeId) {&#10;        followers[followerId].erase(followeeId);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Heap 10 Kth Largest Element In A Stream<br><br></b> <a href="https://leetcode.com/problems/kth-largest-element-in-a-stream/" target="_blank">LeetCode 703</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-heap of size K.</td>
      <td><b>Time:</b> O(N log K) for init, O(log K) for add<br><b>Space:</b> O(K)</td>
      <td>Maintain a min-heap of size exactly `k`. The top of the min-heap will always represent the kth largest element. For every new element added, if the heap size is less than `k`, push it. If the heap is of size `k` and the new element is greater than the top, pop the top and push the new element.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class KthLargest {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    int k;&#10;public:&#10;    KthLargest(int k, vector&lt;int&gt;&amp; nums) {&#10;        this-&gt;k = k;&#10;        for(int num : nums) {&#10;            pq.push(num);&#10;            if(pq.size() &gt; k) pq.pop();&#10;        }&#10;    }&#10;    int add(int val) {&#10;        pq.push(val);&#10;        if(pq.size() &gt; k) pq.pop();&#10;        return pq.top();&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Heap 11 K Closest Points To Origin<br><br></b> <a href="https://leetcode.com/problems/k-closest-points-to-origin/" target="_blank">LeetCode 973</a></td>
      <td rowspan="1"><b>Example 1:</b> Max-heap of pairs.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Use a max-heap of size `k` to store pairs of `(distance, point_index)`. Iterate over all points, push into heap. If heap size exceeds `k`, pop the max element. The heap will eventually hold the `k` points with minimum distance.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; kClosest(vector&lt;vector&lt;int&gt;&gt;&amp; points, int k) {&#10;    priority_queue&lt;pair&lt;int, int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; points.size(); i++) {&#10;        int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];&#10;        pq.push({dist, i});&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    while(!pq.empty()) {&#10;        res.push_back(points[pq.top().second]);&#10;        pq.pop();&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Heap 12 Reorganize String<br><br></b> <a href="https://leetcode.com/problems/reorganize-string/" target="_blank">LeetCode 767</a></td>
      <td rowspan="1"><b>Example 1:</b> Duplicate logic entry. See Greedy chapter.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26)</td>
      <td>See greedy_38_reorganize_string.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">// Implementation provided in greedy chapter.</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Heap 13 Smallest Range In K Lists<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N * K * log K)<br><b>Space:</b> O(K)</td>
      <td>Maintain a min-heap of size K, storing the first element of each list along with its list index and element index. Keep track of the `max_val` currently in the heap. The current range is `[heap_min, max_val]`. Extract the min, update the smallest range if needed, and insert the next element from the extracted element's list. Update `max_val` with the new element.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">pair&lt;int,int&gt; findSmallestRange(int KSortedArray[][N], int n, int k) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int mx = INT_MIN;&#10;    for(int i = 0; i &lt; k; i++) {&#10;        pq.push({KSortedArray[i][0], i, 0});&#10;        mx = max(mx, KSortedArray[i][0]);&#10;    }&#10;    int range = INT_MAX, start = -1, end = -1;&#10;    while(!pq.empty()) {&#10;        auto curr = pq.top();&#10;        pq.pop();&#10;        int mn = curr[0];&#10;        int row = curr[1], col = curr[2];&#10;        if(mx - mn &lt; range) {&#10;            range = mx - mn;&#10;            start = mn; end = mx;&#10;        }&#10;        if(col + 1 &lt; n) {&#10;            pq.push({KSortedArray[row][col+1], row, col+1});&#10;            mx = max(mx, KSortedArray[row][col+1]);&#10;        } else {&#10;            break;&#10;        }&#10;    }&#10;    return {start, end};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Heap 14 Kth Largest Sum Contiguous Subarray<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(K)</td>
      <td>Iterate all subarrays using two nested loops. Maintain a min-heap of size K to store the top K sums. If the heap size < K, push the current sum. If the heap size == K and current sum > heap top, pop and push current sum. The top of the heap is the Kth largest sum.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargest(vector&lt;int&gt; &amp;Arr, int N, int K) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        int sum = 0;&#10;        for(int j = i; j &lt; N; j++) {&#10;            sum += Arr[j];&#10;            if(pq.size() &lt; K) pq.push(sum);&#10;            else if(sum &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(sum);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Heap 15 Minimum Sum Of Two Numbers Formed From Digits Of An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-sum4058/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort or Min-Heap.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Sort the array. Build two strings representing the two numbers by picking digits alternately from the sorted array. Add the two large numbers as strings or build the result dynamically.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string solve(int arr[], int n) {&#10;    sort(arr, arr + n);&#10;    string a = &quot;&quot;, b = &quot;&quot;;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) a += to_string(arr[i]);&#10;        else b += to_string(arr[i]);&#10;    }&#10;    string res = &quot;&quot;;&#10;    int i = a.length() - 1, j = b.length() - 1, carry = 0;&#10;    while(i &gt;= 0 || j &gt;= 0 || carry) {&#10;        int sum = carry;&#10;        if(i &gt;= 0) sum += a[i--] - &#x27;0&#x27;;&#10;        if(j &gt;= 0) sum += b[j--] - &#x27;0&#x27;;&#10;        res += to_string(sum % 10);&#10;        carry = sum / 10;&#10;    }&#10;    while(res.length() &gt; 1 &amp;&amp; res.back() == &#x27;0&#x27;) res.pop_back();&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Heap 16 Is Binary Tree Heap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Tree Traversal.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(H)</td>
      <td>First, check if the tree is complete by counting nodes and ensuring no node's index `i > count`. Then check if every node satisfies the max-heap property (`node.val >= left.val` and `node.val >= right.val`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countNodes(Node* root) {&#10;    if(!root) return 0;&#10;    return 1 + countNodes(root-&gt;left) + countNodes(root-&gt;right);&#10;}&#10;bool isCBT(Node* root, int index, int count) {&#10;    if(!root) return true;&#10;    if(index &gt;= count) return false;&#10;    return isCBT(root-&gt;left, 2 * index + 1, count) &amp;&amp; isCBT(root-&gt;right, 2 * index + 2, count);&#10;}&#10;bool isMaxOrder(Node* root) {&#10;    if(!root-&gt;left &amp;&amp; !root-&gt;right) return true;&#10;    if(!root-&gt;right) return root-&gt;data &gt;= root-&gt;left-&gt;data;&#10;    return (root-&gt;data &gt;= root-&gt;left-&gt;data) &amp;&amp; (root-&gt;data &gt;= root-&gt;right-&gt;data) &amp;&amp; isMaxOrder(root-&gt;left) &amp;&amp; isMaxOrder(root-&gt;right);&#10;}&#10;bool isHeap(struct Node* tree) {&#10;    int count = countNodes(tree);&#10;    return isCBT(tree, 0, count) &amp;&amp; isMaxOrder(tree);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Heap 17 Convert Min Heap To Max Heap<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666738710/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Heapify.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(log N) for recursion</td>
      <td>Apply the standard max-heapify process starting from the last non-leaf node `(N/2 - 1)` down to the root. This takes O(N) time.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void maxHeapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, left = 2 * i + 1, right = 2 * i + 2;&#10;    if(left &lt; n &amp;&amp; arr[left] &gt; arr[largest]) largest = left;&#10;    if(right &lt; n &amp;&amp; arr[right] &gt; arr[largest]) largest = right;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        maxHeapify(arr, n, largest);&#10;    }&#10;}&#10;void convertMinToMaxHeap(vector&lt;int&gt; &amp;arr, int N) {&#10;    for(int i = (N - 2) / 2; i &gt;= 0; i--) {&#10;        maxHeapify(arr, N, i);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Heap 18 Minimum Cost Of Ropes<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-Heap Greedy.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Use a min-heap. Pop two minimum length ropes, add them up, add sum to total cost, and push the merged rope back to the heap. Repeat until one rope remains.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long minCost(long long arr[], long long n) {&#10;    priority_queue&lt;long long, vector&lt;long long&gt;, greater&lt;long long&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) pq.push(arr[i]);&#10;    long long cost = 0;&#10;    while(pq.size() &gt; 1) {&#10;        long long a = pq.top(); pq.pop();&#10;        long long b = pq.top(); pq.pop();&#10;        long long sum = a + b;&#10;        cost += sum;&#10;        pq.push(sum);&#10;    }&#10;    return cost;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Heap 19 K Th Largest Element In A Stream<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min-Heap of size K.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Maintain a min-heap of size K. While processing the stream, if heap size is < K, push current element. If heap size == K and current element is > heap top, pop and push current element. Append heap top to result if size is K, else append -1.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kthLargest(int k, int arr[], int n) {&#10;    vector&lt;int&gt; res;&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &gt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;        if(pq.size() &lt; k) res.push_back(-1);&#10;        else res.push_back(pq.top());&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Heap 20 Merge K Sorted Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(K^2 log K)<br><b>Space:</b> O(K)</td>
      <td>Create a min-heap that stores a tuple: (value, array_index, element_index). Push the first element of each of the K arrays into the heap. While the heap is not empty, pop the minimum element, add it to the result, and if the array from which it was popped has more elements, push the next element to the heap.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class Element {&#10;public:&#10;    int val, row, col;&#10;    Element(int v, int r, int c) : val(v), row(r), col(c) {}&#10;};&#10;struct Compare {&#10;    bool operator()(Element a, Element b) {&#10;        return a.val &gt; b.val;&#10;    }&#10;};&#10;vector&lt;int&gt; mergeKArrays(vector&lt;vector&lt;int&gt;&gt; arr, int K) {&#10;    priority_queue&lt;Element, vector&lt;Element&gt;, Compare&gt; pq;&#10;    vector&lt;int&gt; res;&#10;    for(int i = 0; i &lt; K; i++) {&#10;        pq.push(Element(arr[i][0], i, 0));&#10;    }&#10;    while(!pq.empty()) {&#10;        Element curr = pq.top();&#10;        pq.pop();&#10;        res.push_back(curr.val);&#10;        if(curr.col + 1 &lt; K) {&#10;            pq.push(Element(arr[curr.row][curr.col + 1], curr.row, curr.col + 1));&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Heap 21 Smallest Range Covering Elements From K Lists<br><br></b> <a href="https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/" target="_blank">LeetCode 632</a></td>
      <td rowspan="1"><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Use a min-heap storing `(value, list_idx, elem_idx)`. Also maintain the `current_max` of the elements currently in the heap. The current range is `[heap_top, current_max]`. Pop the min, push the next element from its list, and update `current_max`. Continue until any list is exhausted.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; smallestRange(vector&lt;vector&lt;int&gt;&gt;&amp; nums) {&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    int currMax = INT_MIN;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        pq.push({nums[i][0], i, 0});&#10;        currMax = max(currMax, nums[i][0]);&#10;    }&#10;    vector&lt;int&gt; ans = {pq.top()[0], currMax};&#10;    while(true) {&#10;        auto curr = pq.top(); pq.pop();&#10;        int val = curr[0], r = curr[1], c = curr[2];&#10;        if(currMax - val &lt; ans[1] - ans[0]) {&#10;            ans = {val, currMax};&#10;        }&#10;        if(c + 1 == nums[r].size()) break;&#10;        pq.push({nums[r][c + 1], r, c + 1});&#10;        currMax = max(currMax, nums[r][c + 1]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Heap 22 K Largest Elements<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Min Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Maintain a min-heap of size K. Iterate through the array. If the heap has < K elements, push. Else if the current element > heap's top, pop the top and push the current element. The heap will contain the K largest elements.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; kLargest(int arr[], int n, int k) {&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        pq.push(arr[i]);&#10;        if(pq.size() &gt; k) pq.pop();&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    while(!pq.empty()) {&#10;        ans.push_back(pq.top());&#10;        pq.pop();&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Heap 23 Kth Smallest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Max Heap.</td>
      <td><b>Time:</b> O(N log K)<br><b>Space:</b> O(K)</td>
      <td>Use a Max Heap of size K. Iterate through the array. For the first K elements, insert them into the heap. For the remaining elements, if the element is smaller than the top of the heap, pop the top and insert the element. The top of the heap will be the Kth smallest element.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthSmallest(int arr[], int l, int r, int k) {&#10;    priority_queue&lt;int&gt; pq;&#10;    for(int i = l; i &lt;= r; i++) {&#10;        if(pq.size() &lt; k) pq.push(arr[i]);&#10;        else if(arr[i] &lt; pq.top()) {&#10;            pq.pop();&#10;            pq.push(arr[i]);&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Heap 24 Merge Two Binary Max Heaps<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Append and Heapify.</td>
      <td><b>Time:</b> O(N + M)<br><b>Space:</b> O(N + M)</td>
      <td>Create a new array by appending the two arrays. Then call `heapify` starting from the last non-leaf node `(n/2 - 1)` down to the root `0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void heapify(vector&lt;int&gt;&amp; arr, int n, int i) {&#10;    int largest = i, l = 2 * i + 1, r = 2 * i + 2;&#10;    if(l &lt; n &amp;&amp; arr[l] &gt; arr[largest]) largest = l;&#10;    if(r &lt; n &amp;&amp; arr[r] &gt; arr[largest]) largest = r;&#10;    if(largest != i) {&#10;        swap(arr[i], arr[largest]);&#10;        heapify(arr, n, largest);&#10;    }&#10;}&#10;vector&lt;int&gt; mergeHeaps(vector&lt;int&gt; &amp;a, vector&lt;int&gt; &amp;b, int n, int m) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i : a) ans.push_back(i);&#10;    for(int i : b) ans.push_back(i);&#10;    int total = n + m;&#10;    for(int i = total / 2 - 1; i &gt;= 0; i--) {&#10;        heapify(ans, total, i);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Heap 25 Kth Largest Sum Contiguous Subarray<br><br></b> <a href="https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Prefix sum + Min Heap.</td>
      <td><b>Time:</b> O(N^2 log K)<br><b>Space:</b> O(N + K)</td>
      <td>Iterate through all possible subarrays and calculate their sums using a prefix sum array. Maintain a Min Heap of size K to keep track of the top K sums. At the end, the top of the Min Heap is the K-th largest sum.<br><br><b>Dependencies:</b> Priority Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int kthLargestSum(int arr[], int n, int k) {&#10;    vector&lt;int&gt; sum(n + 1, 0);&#10;    for(int i = 1; i &lt;= n; i++) sum[i] = sum[i - 1] + arr[i - 1];&#10;    priority_queue&lt;int, vector&lt;int&gt;, greater&lt;int&gt;&gt; pq;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = i; j &lt;= n; j++) {&#10;            int x = sum[j] - sum[i - 1];&#10;            if(pq.size() &lt; k) pq.push(x);&#10;            else if(x &gt; pq.top()) {&#10;                pq.pop();&#10;                pq.push(x);&#10;            }&#10;        }&#10;    }&#10;    return pq.top();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Heap 26 Convert BST To Min Heap<br><br></b> <a href="https://www.geeksforgeeks.org/convert-bst-min-heap/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Inorder + Preorder.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Since a BST inorder gives sorted values, store the inorder traversal in an array. The requirement says left subtree elements < right subtree elements, which matches a Preorder traversal (Root, Left, Right) since we want the smallest element at the root. So do a Preorder traversal of the tree and replace nodes with array elements.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void inorder(Node* root, vector&lt;int&gt;&amp; arr) {&#10;    if(!root) return;&#10;    inorder(root-&gt;left, arr);&#10;    arr.push_back(root-&gt;data);&#10;    inorder(root-&gt;right, arr);&#10;}&#10;void preorderFill(Node* root, vector&lt;int&gt;&amp; arr, int&amp; i) {&#10;    if(!root) return;&#10;    root-&gt;data = arr[i++];&#10;    preorderFill(root-&gt;left, arr, i);&#10;    preorderFill(root-&gt;right, arr, i);&#10;}&#10;void convertToMinHeapUtil(Node* root) {&#10;    vector&lt;int&gt; arr;&#10;    inorder(root, arr);&#10;    int i = 0;&#10;    preorderFill(root, arr, i);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Graphs

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
      <td rowspan="1">Graph 01 Number Of Islands<br><br></b> <a href="https://leetcode.com/problems/number-of-islands/" target="_blank">LeetCode 200</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Constraint)</td>
      <td>Iterate through the grid. When a '1' is found, increment island count and use DFS to sink the island (turn connected '1's to '0's).</td>
      <td><b>Edge Cases:</b> <b>In-place Visited Check:</b> Sinking the island by changing '1' to '0' avoids needing a separate `visited` matrix.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid, int i, int j) {&#10;    if(i &lt; 0 || i &gt;= grid.size() || j &lt; 0 || j &gt;= grid[0].size() || grid[i][j] == &#x27;0&#x27;) return;&#10;    grid[i][j] = &#x27;0&#x27;; // Sink&#10;    dfs(grid, i + 1, j);&#10;    dfs(grid, i - 1, j);&#10;    dfs(grid, i, j + 1);&#10;    dfs(grid, i, j - 1);&#10;}&#10;int numIslands(std::vector&lt;std::vector&lt;char&gt;&gt;&amp; grid) {&#10;    int count = 0;&#10;    for(int i = 0; i &lt; grid.size(); i++) {&#10;        for(int j = 0; j &lt; grid[0].size(); j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(grid, i, j);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Graph 02 Course Schedule<br><br></b> <a href="https://leetcode.com/problems/course-schedule/" target="_blank">LeetCode 207</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> numCourses = 2, prerequisites = [[1,0]]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(V + E) (Constraint)<br><b>Space:</b> O(V + E)</td>
      <td>Kahn's Algorithm (BFS). Count in-degrees. Add courses with 0 in-degree to queue. Process queue, reducing in-degrees of neighbors.<br><br><b>Dependencies:</b> <code>std::queue</code></td>
      <td><b>Edge Cases:</b> <b>Graph Building:</b> Convert `prerequisites` edge list into an Adjacency List for fast neighbor lookups.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canFinish(int numCourses, std::vector&lt;std::vector&lt;int&gt;&gt;&amp; prerequisites) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; adj(numCourses);&#10;    std::vector&lt;int&gt; indegree(numCourses, 0);&#10;    for (auto&amp; pre : prerequisites) {&#10;        adj[pre[1]].push_back(pre[0]);&#10;        indegree[pre[0]]++;&#10;    }&#10;    std::queue&lt;int&gt; q;&#10;    for (int i = 0; i &lt; numCourses; i++) {&#10;        if (indegree[i] == 0) q.push(i);&#10;    }&#10;    int count = 0;&#10;    while (!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        count++;&#10;        for (int neighbor : adj[node]) {&#10;            indegree[neighbor]--;&#10;            if (indegree[neighbor] == 0) q.push(neighbor);&#10;        }&#10;    }&#10;    return count == numCourses;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Graph 03 Bipartite Graph<br><br></b> <a href="https://leetcode.com/problems/is-graph-bipartite/" target="_blank">LeetCode 785</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> graph = [[1,2,3],[0,2],[0,1,3],[0,2]]<br><b>Output:</b> false</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>BFS/DFS coloring approach. Color adjacent nodes with alternate colors (0 and 1). If an adjacent node has the SAME color, it's not bipartite.<br><br><b>Dependencies:</b> <code>std::queue</code></td>
      <td><b>Edge Cases:</b> <b>Disconnected Graph:</b> Must loop over all nodes `0` to `V-1` to ensure every disconnected component is checked.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isBipartite(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; graph) {&#10;    int n = graph.size();&#10;    std::vector&lt;int&gt; color(n, -1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(color[i] != -1) continue;&#10;        std::queue&lt;int&gt; q;&#10;        q.push(i);&#10;        color[i] = 0;&#10;        while(!q.empty()) {&#10;            int node = q.front(); q.pop();&#10;            for(int neighbor : graph[node]) {&#10;                if(color[neighbor] == -1) {&#10;                    color[neighbor] = !color[node];&#10;                    q.push(neighbor);&#10;                } else if(color[neighbor] == color[node]) {&#10;                    return false;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Graph 04 Dijkstras Algorithm<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Source = 0<br><b>Output:</b> distances array.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V)</td>
      <td>Min-heap (priority queue) to repeatedly extract the node with the minimum distance and relax its neighbors.<br><br><b>Dependencies:</b> <code>#include &lt;queue&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Disconnected graph:</b> Distances remain infinity.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; dijkstra(int V, vector&lt;vector&lt;int&gt;&gt; adj[], int S) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(V, 1e9);&#10;    dist[S] = 0;&#10;    pq.push({0, S});&#10;    while(!pq.empty()) {&#10;        int d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it[0], weight = it[1];&#10;            if(d + weight &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + weight;&#10;                pq.push({dist[adjNode], adjNode});&#10;            }&#10;        }&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Graph 05 Topological Sort<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/topological-sort/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> V = 4, adj = [[], [0], [0], [0]]<br><b>Output:</b> valid topological sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Kahn's Algorithm (BFS) using in-degrees. Add nodes with 0 in-degree to a queue. Pop, append to result, and decrement in-degrees of neighbors.<br><br><b>Dependencies:</b> <code>#include &lt;queue&gt;</code></td>
      <td><b>Edge Cases:</b> <b>Cycles:</b> If cycle exists, result will not contain all V elements.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; topoSort(int V, vector&lt;int&gt; adj[]) {&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i=0; i&lt;V; ++i) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; ++i) if(indegree[i] == 0) q.push(i);&#10;    vector&lt;int&gt; topo;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo.push_back(node);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Graph 06 Bellman Ford<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> V=3, S=0, Edges=[[0,1,5],[1,2,-2],[2,1,-3]]<br><b>Output:</b> [-1]</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td>Relax all edges V-1 times. To detect a negative cycle, relax one more time; if any distance updates, there's a negative cycle.</td>
      <td><b>Edge Cases:</b> <b>Disconnected Graphs:</b> Elements unreachable from source remain at 1e8.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bellman_ford(int V, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int S) {&#10;    vector&lt;int&gt; dist(V, 1e8);&#10;    dist[S] = 0;&#10;    for(int i=0; i&lt;V-1; i++) {&#10;        for(auto it: edges) {&#10;            int u = it[0], v = it[1], wt = it[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto it: edges) {&#10;        int u = it[0], v = it[1], wt = it[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return {-1};&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Graph 07 Floyd Warshall<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> Shortest paths for all pairs (i, j).</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(1) in-place</td>
      <td>Multi-source shortest path. Try to go from i to j via every possible vertex k. Update `matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])`.</td>
      <td><b>Edge Cases:</b> <b>Unreachable nodes:</b> Represented by -1. Replace with 1e9 before algorithm, then back to -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void shortest_distance(vector&lt;vector&lt;int&gt;&gt;&amp; matrix){&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == -1) matrix[i][j] = 1e9;&#10;            if(i == j) matrix[i][j] = 0;&#10;        }&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(matrix[i][k] != 1e9 &amp;&amp; matrix[k][j] != 1e9) {&#10;                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(matrix[i][j] == 1e9) matrix[i][j] = -1;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Graph 08 Mst Prims<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return the scalar sum of the MST.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(E + V)</td>
      <td>Prim's Algorithm. Use a Min-Heap `(weight, node)`. Always pick the smallest available edge connecting the MST to an unvisited node.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int spanningTree(int V, vector&lt;vector&lt;int&gt;&gt; adj[]) {&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; vis(V, 0);&#10;    pq.push({0, 0});&#10;    int sum = 0;&#10;    while(!pq.empty()) {&#10;        auto it = pq.top(); pq.pop();&#10;        int node = it.second, wt = it.first;&#10;        if(vis[node] == 1) continue;&#10;        vis[node] = 1;&#10;        sum += wt;&#10;        for(auto it: adj[node]) {&#10;            int adjNode = it[0], edW = it[1];&#10;            if(!vis[adjNode]) pq.push({edW, adjNode});&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Graph 09 Strongly Connected Components Kosaraju<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return an integer count.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Kosaraju's Algo: 1) Sort nodes by finish time (Topo Sort DFS). 2) Transpose the graph (reverse edges). 3) DFS on transposed graph in order of finish time.<br><br><b>Dependencies:</b> <code>#include <stack></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt;&amp; vis, vector&lt;vector&lt;int&gt;&gt;&amp; adj, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it: adj[node]) if(!vis[it]) dfs(it, vis, adj, st);&#10;    st.push(node);&#10;}&#10;void dfs3(int node, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adjT[]) {&#10;    vis[node] = 1;&#10;    for(auto it: adjT[node]) if(!vis[it]) dfs3(it, vis, adjT);&#10;}&#10;int kosaraju(int V, vector&lt;vector&lt;int&gt;&gt;&amp; adj) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;V; i++) if(!vis[i]) dfs(i, vis, adj, st);&#10;    vector&lt;int&gt; adjT[V];&#10;    for(int i=0; i&lt;V; i++) {&#10;        vis[i] = 0;&#10;        for(auto it: adj[i]) adjT[it].push_back(i);&#10;    }&#10;    int scc = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top(); st.pop();&#10;        if(!vis[node]) {&#10;            scc++; dfs3(node, vis, adjT);&#10;        }&#10;    }&#10;    return scc;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Graph 10 Detect Cycle Directed BFS<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return true if cycle exists.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>A DAG has a topological sort of exactly V elements. Use Kahn's BFS. If the number of elements pulled from the queue is < V, there's a cycle.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isCyclic(int V, vector&lt;int&gt; adj[]) {&#10;    int indegree[V] = {0};&#10;    for(int i=0; i&lt;V; i++) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;V; i++) if(indegree[i] == 0) q.push(i);&#10;    int cnt = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        cnt++;&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return cnt != V;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Graph 11 Bipartite Graph DFS<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/bipartite-graph/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Return true/false.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>DFS. Color nodes with 0 and 1. If an adjacent node is uncolored, assign the opposite color and recurse. If it's colored and has the same color, it's not bipartite.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool dfs(int node, int col, int color[], vector&lt;int&gt; adj[]) {&#10;    color[node] = col;&#10;    for(auto it: adj[node]) {&#10;        if(color[it] == -1) {&#10;            if(dfs(it, !col, color, adj) == false) return false;&#10;        } else if(color[it] == col) {&#10;            return false;&#10;        }&#10;    }&#10;    return true;&#10;}&#10;bool isBipartite(int V, vector&lt;int&gt;adj[]) {&#10;    int color[V];&#10;    for(int i=0; i&lt;V; i++) color[i] = -1;&#10;    for(int i=0; i&lt;V; i++) {&#10;        if(color[i] == -1) {&#10;            if(dfs(i, 0, color, adj) == false) return false;&#10;        }&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Graph 12 Alien Dictionary<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/alien-dictionary/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> words = ['baa', 'abcd', 'abca', 'cab', 'cad'], K = 4<br><b>Output:</b> 'bdac'</td>
      <td><b>Time:</b> O(N * Len + K + E)<br><b>Space:</b> O(K + E)</td>
      <td>Create a DAG based on mismatching characters between adjacent words. Use Kahn's algorithm (Topological Sort BFS) to find the character order.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string findOrder(string dict[], int N, int K) {&#10;    vector&lt;int&gt; adj[K];&#10;    for(int i=0; i&lt;N-1; i++) {&#10;        string s1 = dict[i], s2 = dict[i+1];&#10;        int len = min(s1.size(), s2.size());&#10;        for(int ptr=0; ptr&lt;len; ptr++) {&#10;            if(s1[ptr] != s2[ptr]) {&#10;                adj[s1[ptr] - &#x27;a&#x27;].push_back(s2[ptr] - &#x27;a&#x27;);&#10;                break;&#10;            }&#10;        }&#10;    }&#10;    vector&lt;int&gt; indegree(K, 0);&#10;    for(int i=0; i&lt;K; i++) {&#10;        for(auto it: adj[i]) indegree[it]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i=0; i&lt;K; i++) if(indegree[i] == 0) q.push(i);&#10;    string topo = &quot;&quot;;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        topo += char(node + &#x27;a&#x27;);&#10;        for(auto it: adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    return topo;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Graph 13 Shortest Path In Directed Acyclic Graph<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Topo Sort.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Perform Topological Sort. Then iterate through the topologically sorted vertices. For each vertex `u`, relax its neighbors: `dist[v] = min(dist[v], dist[u] + weight)`. Return `dist` array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void topoSort(int node, vector&lt;pair&lt;int, int&gt;&gt; adj[], vector&lt;int&gt;&amp; vis, stack&lt;int&gt;&amp; st) {&#10;    vis[node] = 1;&#10;    for(auto it : adj[node]) {&#10;        int v = it.first;&#10;        if(!vis[v]) topoSort(v, adj, vis, st);&#10;    }&#10;    st.push(node);&#10;}&#10;vector&lt;int&gt; shortestPath(int N, int M, vector&lt;vector&lt;int&gt;&gt;&amp; edges) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; adj[N];&#10;    for(int i=0; i&lt;M; i++) {&#10;        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];&#10;        adj[u].push_back({v, wt});&#10;    }&#10;    vector&lt;int&gt; vis(N, 0);&#10;    stack&lt;int&gt; st;&#10;    for(int i=0; i&lt;N; i++) {&#10;        if(!vis[i]) topoSort(i, adj, vis, st);&#10;    }&#10;    vector&lt;int&gt; dist(N, 1e9);&#10;    dist[0] = 0;&#10;    while(!st.empty()) {&#10;        int node = st.top();&#10;        st.pop();&#10;        if(dist[node] != 1e9) {&#10;            for(auto it : adj[node]) {&#10;                int v = it.first, wt = it.second;&#10;                if(dist[node] + wt &lt; dist[v]) {&#10;                    dist[v] = dist[node] + wt;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;N; i++) if(dist[i] == 1e9) dist[i] = -1;&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Graph 14 Shortest Path In Undirected Graph With Unit Distance<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS approach.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Standard BFS starting from source. Distance of neighbors is `dist[u] + 1`.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; shortestPath(vector&lt;vector&lt;int&gt;&gt;&amp; edges, int N, int M, int src){&#10;    vector&lt;int&gt; adj[N];&#10;    for(int i=0; i&lt;M; i++) {&#10;        adj[edges[i][0]].push_back(edges[i][1]);&#10;        adj[edges[i][1]].push_back(edges[i][0]);&#10;    }&#10;    vector&lt;int&gt; dist(N, 1e9);&#10;    dist[src] = 0;&#10;    queue&lt;int&gt; q;&#10;    q.push(src);&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        for(int it : adj[node]) {&#10;            if(dist[node] + 1 &lt; dist[it]) {&#10;                dist[it] = dist[node] + 1;&#10;                q.push(it);&#10;            }&#10;        }&#10;    }&#10;    for(int i=0; i&lt;N; i++) if(dist[i] == 1e9) dist[i] = -1;&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Graph 15 Bridges In Graph<br><br></b> <a href="https://leetcode.com/problems/critical-connections-in-a-network/" target="_blank">LeetCode 1192</a></td>
      <td rowspan="1"><b>Example 1:</b> Tarjan's algorithm.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Tarjan's algorithm. Maintain `tin` (time of insertion) and `low` (lowest time reachable). If `low[neighbor] > tin[node]`, the edge `(node, neighbor)` is a bridge. Update `low[node] = min(low[node], low[neighbor])`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int timer = 1;&#10;void dfs(int node, int parent, vector&lt;int&gt;&amp; vis, vector&lt;int&gt; adj[], int tin[], int low[], vector&lt;vector&lt;int&gt;&gt;&amp; bridges) {&#10;    vis[node] = 1;&#10;    tin[node] = low[node] = timer++;&#10;    for(auto it : adj[node]) {&#10;        if(it == parent) continue;&#10;        if(vis[it] == 0) {&#10;            dfs(it, node, vis, adj, tin, low, bridges);&#10;            low[node] = min(low[node], low[it]);&#10;            if(low[it] &gt; tin[node]) bridges.push_back({node, it});&#10;        } else {&#10;            low[node] = min(low[node], low[it]);&#10;        }&#10;    }&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; criticalConnections(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {&#10;    vector&lt;int&gt; adj[n];&#10;    for(auto it : connections) {&#10;        adj[it[0]].push_back(it[1]);&#10;        adj[it[1]].push_back(it[0]);&#10;    }&#10;    vector&lt;int&gt; vis(n, 0);&#10;    int tin[n];&#10;    int low[n];&#10;    vector&lt;vector&lt;int&gt;&gt; bridges;&#10;    dfs(0, -1, vis, adj, tin, low, bridges);&#10;    return bridges;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Graph 16 Articulation Point I<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/articulation-point-1/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Tarjan's algorithm with discovery times.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Maintain `tin` (insertion time) and `low` (lowest insertion time reachable). A node `u` is an articulation point if `low[v] >= tin[u]` (and it's not root). If root, it's an articulation point if it has >1 children in DFS tree.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int timer = 0;&#10;void dfs(int node, int parent, vector&lt;int&gt; &amp;vis, int tin[], int low[], vector&lt;int&gt; &amp;mark, vector&lt;int&gt;adj[]) {&#10;    vis[node] = 1;&#10;    tin[node] = low[node] = timer++;&#10;    int child = 0;&#10;    for(auto it : adj[node]) {&#10;        if(it == parent) continue;&#10;        if(!vis[it]) {&#10;            dfs(it, node, vis, tin, low, mark, adj);&#10;            low[node] = min(low[node], low[it]);&#10;            if(low[it] &gt;= tin[node] &amp;&amp; parent != -1) {&#10;                mark[node] = 1;&#10;            }&#10;            child++;&#10;        } else {&#10;            low[node] = min(low[node], tin[it]);&#10;        }&#10;    }&#10;    if(child &gt; 1 &amp;&amp; parent == -1) {&#10;        mark[node] = 1;&#10;    }&#10;}&#10;vector&lt;int&gt; articulationPoints(int V, vector&lt;int&gt;adj[]) {&#10;    vector&lt;int&gt; vis(V, 0);&#10;    int tin[V];&#10;    int low[V];&#10;    vector&lt;int&gt; mark(V, 0);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(!vis[i]) {&#10;            dfs(i, -1, vis, tin, low, mark, adj);&#10;        }&#10;    }&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(mark[i] == 1) ans.push_back(i);&#10;    }&#10;    if(ans.size() == 0) return {-1};&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Graph 17 Number Of Provinces Dsu<br><br></b> <a href="https://leetcode.com/problems/number-of-provinces/" target="_blank">LeetCode 547</a></td>
      <td rowspan="1"><b>Example 1:</b> Connect elements, count unique parents.</td>
      <td><b>Time:</b> O(N^2 * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>Create DSU of size `n`. For every edge in `isConnected`, union the two nodes. The number of provinces is the number of nodes where `find(i) == i`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;    vector&lt;int&gt; parent, size;&#10;public:&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int findCircleNum(vector&lt;vector&lt;int&gt;&gt;&amp; isConnected) {&#10;    int n = isConnected.size();&#10;    DisjointSet ds(n);&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(isConnected[i][j] == 1) ds.unionBySize(i, j);&#10;        }&#10;    }&#10;    int cnt = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(ds.findUPar(i) == i) cnt++;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Graph 18 Accounts Merge<br><br></b> <a href="https://leetcode.com/problems/accounts-merge/" target="_blank">LeetCode 721</a></td>
      <td rowspan="1"><b>Example 1:</b> DSU on accounts using emails.</td>
      <td><b>Time:</b> O(N log N * alpha(N)) where N is total emails<br><b>Space:</b> O(N)</td>
      <td>Map each email to an account index. If an email is seen again, union the current account index with the previously mapped account index. Finally, group emails by their root account index, sort them, and attach the name.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;public:&#10;    vector&lt;int&gt; parent, size;&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i = 0; i &lt;= n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u);&#10;        int ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;vector&lt;vector&lt;string&gt;&gt; accountsMerge(vector&lt;vector&lt;string&gt;&gt;&amp; accounts) {&#10;    int n = accounts.size();&#10;    DisjointSet ds(n);&#10;    unordered_map&lt;string, int&gt; mapMailNode;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=1; j&lt;accounts[i].size(); j++) {&#10;            string mail = accounts[i][j];&#10;            if(mapMailNode.find(mail) == mapMailNode.end()) {&#10;                mapMailNode[mail] = i;&#10;            } else {&#10;                ds.unionBySize(i, mapMailNode[mail]);&#10;            }&#10;        }&#10;    }&#10;    vector&lt;string&gt; mergedMail[n];&#10;    for(auto it : mapMailNode) {&#10;        string mail = it.first;&#10;        int node = ds.findUPar(it.second);&#10;        mergedMail[node].push_back(mail);&#10;    }&#10;    vector&lt;vector&lt;string&gt;&gt; ans;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(mergedMail[i].size() == 0) continue;&#10;        sort(mergedMail[i].begin(), mergedMail[i].end());&#10;        vector&lt;string&gt; temp;&#10;        temp.push_back(accounts[i][0]);&#10;        for(auto it : mergedMail[i]) temp.push_back(it);&#10;        ans.push_back(temp);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Graph 19 Number Of Operations To Make Network Connected<br><br></b> <a href="https://leetcode.com/problems/number-of-operations-to-make-network-connected/" target="_blank">LeetCode 1319</a></td>
      <td rowspan="1"><b>Example 1:</b> Extra edges and connected components.</td>
      <td><b>Time:</b> O(E * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>If total edges < n - 1, impossible. Use DSU to count number of connected components `C` and number of extra edges `E`. An edge is extra if `find(u) == find(v)`. We need `C - 1` edges to connect `C` components. Since total edges >= n - 1, we guaranteed have enough extra edges. Answer is `C - 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int makeConnected(int n, vector&lt;vector&lt;int&gt;&gt;&amp; connections) {&#10;    if(connections.size() &lt; n - 1) return -1;&#10;    vector&lt;int&gt; parent(n);&#10;    for(int i=0; i&lt;n; i++) parent[i] = i;&#10;    function&lt;int(int)&gt; find = [&amp;](int i) {&#10;        return parent[i] == i ? i : parent[i] = find(parent[i]);&#10;    };&#10;    int components = n;&#10;    for(auto&amp; edge : connections) {&#10;        int u = find(edge[0]);&#10;        int v = find(edge[1]);&#10;        if(u != v) {&#10;            parent[u] = v;&#10;            components--;&#10;        }&#10;    }&#10;    return components - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Graph 20 Most Stones Removed With Same Row Or Column<br><br></b> <a href="https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/" target="_blank">LeetCode 947</a></td>
      <td rowspan="1"><b>Example 1:</b> Treat rows and columns as nodes.</td>
      <td><b>Time:</b> O(N * alpha(N))<br><b>Space:</b> O(N)</td>
      <td>Imagine rows and columns are nodes in a bipartite graph. A stone at `(r, c)` connects row `r` and column `c`. The answer is `total_stones - number_of_connected_components`. We can map cols to `col + 10001` to use a single DSU.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeStones(vector&lt;vector&lt;int&gt;&gt;&amp; stones) {&#10;    unordered_map&lt;int, int&gt; parent;&#10;    int components = 0;&#10;    function&lt;int(int)&gt; find = [&amp;](int i) {&#10;        if(parent.find(i) == parent.end()) {&#10;            parent[i] = i;&#10;            components++;&#10;        }&#10;        if(parent[i] == i) return i;&#10;        return parent[i] = find(parent[i]);&#10;    };&#10;    auto unionNodes = [&amp;](int u, int v) {&#10;        int root_u = find(u);&#10;        int root_v = find(v);&#10;        if(root_u != root_v) {&#10;            parent[root_u] = root_v;&#10;            components--;&#10;        }&#10;    };&#10;    for(auto&amp; stone : stones) {&#10;        unionNodes(stone[0], ~stone[1]); // ~x makes columns distinct from rows&#10;    }&#10;    return stones.size() - components;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Graph 21 Making A Large Island<br><br></b> <a href="https://leetcode.com/problems/making-a-large-island/" target="_blank">LeetCode 827</a></td>
      <td rowspan="1"><b>Example 1:</b> Component sizes with DSU.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Step 1: Use DSU to connect all adjacent 1s and calculate the size of each component. Step 2: For each 0, check its 4 neighbors. Find the unique roots of those neighbors. The potential new island size is `1 + sum(size[root])` for each unique root. Find max potential size. Handle case where matrix is all 1s.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">class DisjointSet {&#10;public:&#10;    vector&lt;int&gt; parent, size;&#10;    DisjointSet(int n) {&#10;        parent.resize(n + 1);&#10;        size.resize(n + 1, 1);&#10;        for(int i=0; i&lt;=n; i++) parent[i] = i;&#10;    }&#10;    int findUPar(int node) {&#10;        if(node == parent[node]) return node;&#10;        return parent[node] = findUPar(parent[node]);&#10;    }&#10;    void unionBySize(int u, int v) {&#10;        int ulp_u = findUPar(u), ulp_v = findUPar(v);&#10;        if(ulp_u == ulp_v) return;&#10;        if(size[ulp_u] &lt; size[ulp_v]) {&#10;            parent[ulp_u] = ulp_v;&#10;            size[ulp_v] += size[ulp_u];&#10;        } else {&#10;            parent[ulp_v] = ulp_u;&#10;            size[ulp_u] += size[ulp_v];&#10;        }&#10;    }&#10;};&#10;int largestIsland(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    DisjointSet ds(n * n);&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    for(int r=0; r&lt;n; r++) {&#10;        for(int c=0; c&lt;n; c++) {&#10;            if(grid[r][c] == 0) continue;&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n &amp;&amp; grid[nr][nc] == 1) {&#10;                    int nodeNo = r * n + c;&#10;                    int adjNodeNo = nr * n + nc;&#10;                    ds.unionBySize(nodeNo, adjNodeNo);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int mx = 0;&#10;    for(int r=0; r&lt;n; r++) {&#10;        for(int c=0; c&lt;n; c++) {&#10;            if(grid[r][c] == 1) continue;&#10;            set&lt;int&gt; components;&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n &amp;&amp; grid[nr][nc] == 1) {&#10;                    components.insert(ds.findUPar(nr * n + nc));&#10;                }&#10;            }&#10;            int sizeTotal = 0;&#10;            for(auto it : components) sizeTotal += ds.size[it];&#10;            mx = max(mx, sizeTotal + 1);&#10;        }&#10;    }&#10;    for(int cell=0; cell&lt;n*n; cell++) mx = max(mx, ds.size[ds.findUPar(cell)]);&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Graph 22 Swim In Rising Water<br><br></b> <a href="https://leetcode.com/problems/swim-in-rising-water/" target="_blank">LeetCode 778</a></td>
      <td rowspan="1"><b>Example 1:</b> Dijkstra-like or Binary Search + BFS.</td>
      <td><b>Time:</b> O(N^2 log N)<br><b>Space:</b> O(N^2)</td>
      <td>Use a priority queue (Dijkstra variant). The cost to reach a cell is `max(cost_of_previous_cell, grid[r][c])`. Extract min cost cell, relax neighbors.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int swimInWater(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    priority_queue&lt;vector&lt;int&gt;, vector&lt;vector&lt;int&gt;&gt;, greater&lt;vector&lt;int&gt;&gt;&gt; pq;&#10;    vector&lt;vector&lt;int&gt;&gt; dist(n, vector&lt;int&gt;(n, 1e9));&#10;    dist[0][0] = grid[0][0];&#10;    pq.push({grid[0][0], 0, 0});&#10;    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};&#10;    while(!pq.empty()) {&#10;        auto it = pq.top();&#10;        pq.pop();&#10;        int d = it[0], r = it[1], c = it[2];&#10;        if(r == n-1 &amp;&amp; c == n-1) return d;&#10;        for(int i=0; i&lt;4; i++) {&#10;            int nr = r + dr[i], nc = c + dc[i];&#10;            if(nr&gt;=0 &amp;&amp; nr&lt;n &amp;&amp; nc&gt;=0 &amp;&amp; nc&lt;n) {&#10;                int next_d = max(d, grid[nr][nc]);&#10;                if(next_d &lt; dist[nr][nc]) {&#10;                    dist[nr][nc] = next_d;&#10;                    pq.push({next_d, nr, nc});&#10;                }&#10;            }&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Graph 23 Word Ladder I<br><br></b> <a href="https://leetcode.com/problems/word-ladder/" target="_blank">LeetCode 127</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS level by level.</td>
      <td><b>Time:</b> O(N * M * 26) where N is words, M is word length<br><b>Space:</b> O(N)</td>
      <td>BFS. Start from `beginWord`. In each step, change one character from 'a' to 'z' and check if new word is in `wordList`. If yes, push to queue, erase from `wordList` to avoid loops, and continue. Track level/steps.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int ladderLength(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;pair&lt;string, int&gt;&gt; q;&#10;    q.push({beginWord, 1});&#10;    st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        if(word == endWord) return steps;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            char original = word[i];&#10;            for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;                word[i] = ch;&#10;                if(st.find(word) != st.end()) {&#10;                    st.erase(word);&#10;                    q.push({word, steps + 1});&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Graph 24 Word Ladder II<br><br></b> <a href="https://leetcode.com/problems/word-ladder-ii/" target="_blank">LeetCode 126</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS for distance, DFS for paths.</td>
      <td><b>Time:</b> O(V + E + Paths)<br><b>Space:</b> O(V + E)</td>
      <td>BFS to find minimum steps to reach each word. Then DFS starting from `endWord` backwards to `beginWord`, only exploring paths where `dist[next_word] == dist[curr_word] - 1`. Reverse the built paths.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">unordered_map&lt;string, int&gt; mpp;&#10;vector&lt;vector&lt;string&gt;&gt; ans;&#10;string b;&#10;void dfs(string word, vector&lt;string&gt;&amp; seq) {&#10;    if(word == b) {&#10;        reverse(seq.begin(), seq.end());&#10;        ans.push_back(seq);&#10;        reverse(seq.begin(), seq.end());&#10;        return;&#10;    }&#10;    int steps = mpp[word];&#10;    for(int i=0; i&lt;word.size(); i++) {&#10;        char original = word[i];&#10;        for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;            word[i] = ch;&#10;            if(mpp.find(word) != mpp.end() &amp;&amp; mpp[word] + 1 == steps) {&#10;                seq.push_back(word);&#10;                dfs(word, seq);&#10;                seq.pop_back();&#10;            }&#10;        }&#10;        word[i] = original;&#10;    }&#10;}&#10;vector&lt;vector&lt;string&gt;&gt; findLadders(string beginWord, string endWord, vector&lt;string&gt;&amp; wordList) {&#10;    unordered_set&lt;string&gt; st(wordList.begin(), wordList.end());&#10;    queue&lt;string&gt; q;&#10;    b = beginWord;&#10;    q.push({beginWord});&#10;    mpp[beginWord] = 1;&#10;    int sz = beginWord.size();&#10;    st.erase(beginWord);&#10;    while(!q.empty()) {&#10;        string word = q.front();&#10;        int steps = mpp[word];&#10;        q.pop();&#10;        if(word == endWord) break;&#10;        for(int i=0; i&lt;sz; i++) {&#10;            char original = word[i];&#10;            for(char ch=&#x27;a&#x27;; ch&lt;=&#x27;z&#x27;; ch++) {&#10;                word[i] = ch;&#10;                if(st.count(word)) {&#10;                    q.push(word);&#10;                    st.erase(word);&#10;                    mpp[word] = steps + 1;&#10;                }&#10;            }&#10;            word[i] = original;&#10;        }&#10;    }&#10;    if(mpp.find(endWord) != mpp.end()) {&#10;        vector&lt;string&gt; seq;&#10;        seq.push_back(endWord);&#10;        dfs(endWord, seq);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Graph 25 Network Delay Time<br><br></b> <a href="https://leetcode.com/problems/network-delay-time/" target="_blank">LeetCode 743</a></td>
      <td rowspan="1"><b>Example 1:</b> Dijkstra's to find max shortest path.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td>Standard Dijkstra's shortest path from node `k`. Return the maximum value in the distances array. If any node remains unvisited (dist == inf), return -1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int networkDelayTime(vector&lt;vector&lt;int&gt;&gt;&amp; times, int n, int k) {&#10;    vector&lt;pair&lt;int, int&gt;&gt; adj[n+1];&#10;    for(auto t : times) adj[t[0]].push_back({t[1], t[2]});&#10;    priority_queue&lt;pair&lt;int, int&gt;, vector&lt;pair&lt;int, int&gt;&gt;, greater&lt;pair&lt;int, int&gt;&gt;&gt; pq;&#10;    vector&lt;int&gt; dist(n+1, 1e9);&#10;    dist[k] = 0;&#10;    pq.push({0, k});&#10;    while(!pq.empty()) {&#10;        int time = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        for(auto it : adj[node]) {&#10;            int adjNode = it.first;&#10;            int wt = it.second;&#10;            if(time + wt &lt; dist[adjNode]) {&#10;                dist[adjNode] = time + wt;&#10;                pq.push({time + wt, adjNode});&#10;            }&#10;        }&#10;    }&#10;    int mx = 0;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        if(dist[i] == 1e9) return -1;&#10;        mx = max(mx, dist[i]);&#10;    }&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Graph 26 Cheapest Flights Within K Stops<br><br></b> <a href="https://leetcode.com/problems/cheapest-flights-within-k-stops/" target="_blank">LeetCode 787</a></td>
      <td rowspan="1"><b>Example 1:</b> Dijkstra's with Stops / BFS.</td>
      <td><b>Time:</b> O(E)<br><b>Space:</b> O(N + E)</td>
      <td>Use a queue storing `(stops, node, cost)`. We don't need a priority queue because stops increase uniformly by 1. Distance array stores min cost to reach each node. Only push to queue if new cost is cheaper. If `stops > k`, skip.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findCheapestPrice(int n, vector&lt;vector&lt;int&gt;&gt;&amp; flights, int src, int dst, int k) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n);&#10;    for(auto&amp; f : flights) adj[f[0]].push_back({f[1], f[2]});&#10;    queue&lt;vector&lt;int&gt;&gt; q; // {stops, node, cost}&#10;    q.push({0, src, 0});&#10;    vector&lt;int&gt; dist(n, INT_MAX);&#10;    dist[src] = 0;&#10;    while(!q.empty()) {&#10;        auto curr = q.front(); q.pop();&#10;        int stops = curr[0], node = curr[1], cost = curr[2];&#10;        if(stops &gt; k) continue;&#10;        for(auto&amp; neighbor : adj[node]) {&#10;            int nextNode = neighbor.first;&#10;            int edgeWeight = neighbor.second;&#10;            if(cost + edgeWeight &lt; dist[nextNode] &amp;&amp; stops &lt;= k) {&#10;                dist[nextNode] = cost + edgeWeight;&#10;                q.push({stops + 1, nextNode, cost + edgeWeight});&#10;            }&#10;        }&#10;    }&#10;    return dist[dst] == INT_MAX ? -1 : dist[dst];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Graph 27 Minimum Multiplications To Reach End<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS / Dijkstra's with unit weights.</td>
      <td><b>Time:</b> O(100000 * N)<br><b>Space:</b> O(100000)</td>
      <td>Since each multiplication is 1 step, we can use BFS. The 'nodes' are values from 0 to 99999. Use an array `dist` initialized to infinity. Push `start` to queue. For each popped node, multiply by all array elements `% 100000`. If we find a shorter path, push to queue.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumMultiplications(vector&lt;int&gt;&amp; arr, int start, int end) {&#10;    if(start == end) return 0;&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    q.push({start, 0});&#10;    vector&lt;int&gt; dist(100000, 1e9);&#10;    dist[start] = 0;&#10;    int mod = 100000;&#10;    while(!q.empty()) {&#10;        int node = q.front().first;&#10;        int steps = q.front().second;&#10;        q.pop();&#10;        for(int it : arr) {&#10;            int num = (node * it) % mod;&#10;            if(steps + 1 &lt; dist[num]) {&#10;                dist[num] = steps + 1;&#10;                if(num == end) return steps + 1;&#10;                q.push({num, steps + 1});&#10;            }&#10;        }&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Graph 28 Number Of Ways To Arrive At Destination<br><br></b> <a href="https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/" target="_blank">LeetCode 1976</a></td>
      <td rowspan="1"><b>Example 1:</b> Dijkstra's with Ways Count.</td>
      <td><b>Time:</b> O(E log V)<br><b>Space:</b> O(V + E)</td>
      <td>Modify Dijkstra's. Keep `dist` array and `ways` array. When relaxing an edge: if `curr_dist + weight < dist[neighbor]`, update `dist`, push to PQ, and `ways[neighbor] = ways[curr_node]`. If `curr_dist + weight == dist[neighbor]`, `ways[neighbor] = (ways[neighbor] + ways[curr_node]) % MOD`.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPaths(int n, vector&lt;vector&lt;int&gt;&gt;&amp; roads) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n);&#10;    for(auto&amp; r : roads) {&#10;        adj[r[0]].push_back({r[1], r[2]});&#10;        adj[r[1]].push_back({r[0], r[2]});&#10;    }&#10;    priority_queue&lt;pair&lt;long long, int&gt;, vector&lt;pair&lt;long long, int&gt;&gt;, greater&lt;pair&lt;long long, int&gt;&gt;&gt; pq;&#10;    vector&lt;long long&gt; dist(n, 1e18);&#10;    vector&lt;int&gt; ways(n, 0);&#10;    dist[0] = 0;&#10;    ways[0] = 1;&#10;    pq.push({0, 0});&#10;    int mod = 1e9 + 7;&#10;    while(!pq.empty()) {&#10;        long long d = pq.top().first;&#10;        int node = pq.top().second;&#10;        pq.pop();&#10;        if(d &gt; dist[node]) continue;&#10;        for(auto&amp; it : adj[node]) {&#10;            int adjNode = it.first;&#10;            long long edW = it.second;&#10;            if(d + edW &lt; dist[adjNode]) {&#10;                dist[adjNode] = d + edW;&#10;                ways[adjNode] = ways[node];&#10;                pq.push({d + edW, adjNode});&#10;            } else if(d + edW == dist[adjNode]) {&#10;                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;&#10;            }&#10;        }&#10;    }&#10;    return ways[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Graph 29 Find The City With The Smallest Number Of Neighbors At A Threshold Distance<br><br></b> <a href="https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/" target="_blank">LeetCode 1334</a></td>
      <td rowspan="1"><b>Example 1:</b> Floyd-Warshall Algorithm.</td>
      <td><b>Time:</b> O(V^3)<br><b>Space:</b> O(V^2)</td>
      <td>Use Floyd-Warshall to find shortest paths between all pairs of nodes. For each city, count the number of reachable cities within `distanceThreshold`. Return the city with the minimum count (and greatest ID on tie).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTheCity(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int distanceThreshold) {&#10;    vector&lt;vector&lt;int&gt;&gt; dist(n, vector&lt;int&gt;(n, 1e9));&#10;    for(int i=0; i&lt;n; i++) dist[i][i] = 0;&#10;    for(auto&amp; e : edges) {&#10;        dist[e[0]][e[1]] = e[2];&#10;        dist[e[1]][e[0]] = e[2];&#10;    }&#10;    for(int k=0; k&lt;n; k++) {&#10;        for(int i=0; i&lt;n; i++) {&#10;            for(int j=0; j&lt;n; j++) {&#10;                if(dist[i][k] != 1e9 &amp;&amp; dist[k][j] != 1e9) {&#10;                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int minCities = n, ansCity = -1;&#10;    for(int i=0; i&lt;n; i++) {&#10;        int cnt = 0;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(dist[i][j] &lt;= distanceThreshold) cnt++;&#10;        }&#10;        if(cnt &lt;= minCities) {&#10;            minCities = cnt;&#10;            ansCity = i;&#10;        }&#10;    }&#10;    return ansCity;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Graph 30 Find Eventual Safe States<br><br></b> <a href="https://leetcode.com/problems/find-eventual-safe-states/" target="_blank">LeetCode 802</a></td>
      <td rowspan="1"><b>Example 1:</b> Topological Sort using Kahn's Algorithm on reversed graph.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Reverse all edges in the graph. Terminal nodes become sources (indegree 0). Run Kahn's algorithm (BFS topological sort). Any node processed is part of a path that only leads to terminal nodes (safe node). Sort the resulting nodes.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; eventualSafeNodes(vector&lt;vector&lt;int&gt;&gt;&amp; graph) {&#10;    int V = graph.size();&#10;    vector&lt;vector&lt;int&gt;&gt; adjRev(V);&#10;    vector&lt;int&gt; indegree(V, 0);&#10;    for(int i = 0; i &lt; V; i++) {&#10;        for(auto it : graph[i]) {&#10;            adjRev[it].push_back(i);&#10;            indegree[i]++;&#10;        }&#10;    }&#10;    queue&lt;int&gt; q;&#10;    for(int i = 0; i &lt; V; i++) {&#10;        if(indegree[i] == 0) q.push(i);&#10;    }&#10;    vector&lt;int&gt; safeNodes;&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        safeNodes.push_back(node);&#10;        for(auto it : adjRev[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) q.push(it);&#10;        }&#10;    }&#10;    sort(safeNodes.begin(), safeNodes.end());&#10;    return safeNodes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Graph 31 As Far From Land As Possible<br><br></b> <a href="https://leetcode.com/problems/as-far-from-land-as-possible/" target="_blank">LeetCode 1162</a></td>
      <td rowspan="1"><b>Example 1:</b> Multi-source BFS.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Push all land cells (1s) into a queue and mark them as visited. Perform BFS outward. The last water cell processed gives the maximum distance. Track layers/steps during BFS.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxDistance(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(grid[i][j] == 1) q.push({i, j});&#10;        }&#10;    }&#10;    if(q.empty() || q.size() == n*n) return -1;&#10;    int dist = -1;&#10;    int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};&#10;    while(!q.empty()) {&#10;        int sz = q.size();&#10;        while(sz--) {&#10;            auto [r, c] = q.front(); q.pop();&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n &amp;&amp; grid[nr][nc] == 0) {&#10;                    grid[nr][nc] = 1;&#10;                    q.push({nr, nc});&#10;                }&#10;            }&#10;        }&#10;        dist++;&#10;    }&#10;    return dist;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Graph 32 Find Closest Node To Given Two Nodes<br><br></b> <a href="https://leetcode.com/problems/find-closest-node-to-given-two-nodes/" target="_blank">LeetCode 2359</a></td>
      <td rowspan="1"><b>Example 1:</b> Two BFS traversals.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Run BFS from `node1` to get `dist1` array, and BFS from `node2` to get `dist2` array. Then iterate through all nodes `0` to `n-1`. For nodes reachable from both, compute `max(dist1[i], dist2[i])`. Return the node that minimizes this maximum distance. On tie, return the smallest index.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bfs(int start, vector&lt;int&gt;&amp; edges, vector&lt;int&gt;&amp; dist) {&#10;    queue&lt;int&gt; q;&#10;    q.push(start);&#10;    dist[start] = 0;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        int next = edges[node];&#10;        if(next != -1 &amp;&amp; dist[next] == 1e9) {&#10;            dist[next] = dist[node] + 1;&#10;            q.push(next);&#10;        }&#10;    }&#10;}&#10;int closestMeetingNode(vector&lt;int&gt;&amp; edges, int node1, int node2) {&#10;    int n = edges.size();&#10;    vector&lt;int&gt; dist1(n, 1e9), dist2(n, 1e9);&#10;    bfs(node1, edges, dist1);&#10;    bfs(node2, edges, dist2);&#10;    int minDist = 1e9, ans = -1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(dist1[i] != 1e9 &amp;&amp; dist2[i] != 1e9) {&#10;            int maxD = max(dist1[i], dist2[i]);&#10;            if(maxD &lt; minDist) {&#10;                minDist = maxD;&#10;                ans = i;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Graph 33 Minimum Score Of A Path Between Two Cities<br><br></b> <a href="https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/" target="_blank">LeetCode 2492</a></td>
      <td rowspan="1"><b>Example 1:</b> BFS / DSU to find min edge in component.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V + E)</td>
      <td>Since a path can revisit nodes and edges, the minimum score path from 1 to `n` is simply the minimum weight edge in the connected component containing node 1 and `n`. Perform BFS/DFS from node 1 and find the minimum edge weight in the entire component.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minScore(int n, vector&lt;vector&lt;int&gt;&gt;&amp; roads) {&#10;    vector&lt;vector&lt;pair&lt;int, int&gt;&gt;&gt; adj(n + 1);&#10;    for(auto&amp; r : roads) {&#10;        adj[r[0]].push_back({r[1], r[2]});&#10;        adj[r[1]].push_back({r[0], r[2]});&#10;    }&#10;    queue&lt;int&gt; q;&#10;    vector&lt;int&gt; vis(n + 1, 0);&#10;    q.push(1);&#10;    vis[1] = 1;&#10;    int minScore = INT_MAX;&#10;    while(!q.empty()) {&#10;        int node = q.front(); q.pop();&#10;        for(auto&amp; neighbor : adj[node]) {&#10;            minScore = min(minScore, neighbor.second);&#10;            if(!vis[neighbor.first]) {&#10;                vis[neighbor.first] = 1;&#10;                q.push(neighbor.first);&#10;            }&#10;        }&#10;    }&#10;    return minScore;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Graph 34 Shortest Bridge<br><br></b> <a href="https://leetcode.com/problems/shortest-bridge/" target="_blank">LeetCode 934</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS + BFS.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Step 1: Use DFS to find the first island. Mark all its cells (e.g., set to 2) and push them into a queue for BFS. Step 2: Perform multi-source BFS from the queue. Expand the island level by level. The first time we hit a `1` (which belongs to the second island), the number of layers expanded is the shortest bridge.<br><br><b>Dependencies:</b> <code>#include <queue></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int dr[4] = {-1, 0, 1, 0};&#10;int dc[4] = {0, 1, 0, -1};&#10;void dfs(vector&lt;vector&lt;int&gt;&gt;&amp; grid, int r, int c, queue&lt;pair&lt;int, int&gt;&gt;&amp; q) {&#10;    grid[r][c] = 2;&#10;    q.push({r, c});&#10;    int n = grid.size();&#10;    for(int i=0; i&lt;4; i++) {&#10;        int nr = r + dr[i], nc = c + dc[i];&#10;        if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n &amp;&amp; grid[nr][nc] == 1) {&#10;            dfs(grid, nr, nc, q);&#10;        }&#10;    }&#10;}&#10;int shortestBridge(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    queue&lt;pair&lt;int, int&gt;&gt; q;&#10;    bool found = false;&#10;    for(int i=0; i&lt;n &amp;&amp; !found; i++) {&#10;        for(int j=0; j&lt;n &amp;&amp; !found; j++) {&#10;            if(grid[i][j] == 1) {&#10;                dfs(grid, i, j, q);&#10;                found = true;&#10;            }&#10;        }&#10;    }&#10;    int steps = 0;&#10;    while(!q.empty()) {&#10;        int sz = q.size();&#10;        while(sz--) {&#10;            auto [r, c] = q.front(); q.pop();&#10;            for(int i=0; i&lt;4; i++) {&#10;                int nr = r + dr[i], nc = c + dc[i];&#10;                if(nr &gt;= 0 &amp;&amp; nr &lt; n &amp;&amp; nc &gt;= 0 &amp;&amp; nc &lt; n) {&#10;                    if(grid[nr][nc] == 1) return steps;&#10;                    if(grid[nr][nc] == 0) {&#10;                        grid[nr][nc] = 2;&#10;                        q.push({nr, nc});&#10;                    }&#10;                }&#10;            }&#10;        }&#10;        steps++;&#10;    }&#10;    return steps;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Graph 35 Minimum Time Taken By Each Job To Be Completed Given By A Directed Acyclic Graph<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Modified Kahn's Algorithm.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Use Kahn's Algorithm. All nodes with indegree 0 take 1 unit of time. For other nodes `V`, when they are pushed to the queue from `U`, their time is `time[U] + 1`.<br><br><b>Dependencies:</b> Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; minimumTime(int n, vector&lt;vector&lt;int&gt;&gt;&amp; edges, int m) {&#10;    vector&lt;int&gt; adj[n + 1];&#10;    vector&lt;int&gt; indegree(n + 1, 0);&#10;    for(auto it : edges) {&#10;        adj[it[0]].push_back(it[1]);&#10;        indegree[it[1]]++;&#10;    }&#10;    queue&lt;int&gt; q;&#10;    vector&lt;int&gt; ans(n + 1, 0);&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        if(indegree[i] == 0) {&#10;            q.push(i);&#10;            ans[i] = 1;&#10;        }&#10;    }&#10;    while(!q.empty()) {&#10;        int node = q.front();&#10;        q.pop();&#10;        for(auto it : adj[node]) {&#10;            indegree[it]--;&#10;            if(indegree[it] == 0) {&#10;                ans[it] = ans[node] + 1;&#10;                q.push(it);&#10;            }&#10;        }&#10;    }&#10;    ans.erase(ans.begin());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Graph 36 Find The Number Of Islands<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS or BFS.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) worst case stack</td>
      <td>Traverse the grid. When a '1' is found, increment island count and use DFS/BFS to mark all its 8-connected neighbors as '0' (or visited) to avoid recounting.</td>
      <td><b>Edge Cases:</b> Empty grid<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int r, int c, vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    grid[r][c] = &#x27;0&#x27;;&#10;    for(int delrow = -1; delrow &lt;= 1; delrow++) {&#10;        for(int delcol = -1; delcol &lt;= 1; delcol++) {&#10;            int nrow = r + delrow;&#10;            int ncol = c + delcol;&#10;            if(nrow &gt;= 0 &amp;&amp; nrow &lt; n &amp;&amp; ncol &gt;= 0 &amp;&amp; ncol &lt; m &amp;&amp; grid[nrow][ncol] == &#x27;1&#x27;) {&#10;                dfs(nrow, ncol, grid);&#10;            }&#10;        }&#10;    }&#10;}&#10;int numIslands(vector&lt;vector&lt;char&gt;&gt;&amp; grid) {&#10;    int n = grid.size();&#10;    if(n == 0) return 0;&#10;    int m = grid[0].size();&#10;    int count = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(grid[i][j] == &#x27;1&#x27;) {&#10;                count++;&#10;                dfs(i, j, grid);&#10;            }&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Graph 37 Detect Negative Cycle In A Graph<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Bellman Ford variant.</td>
      <td><b>Time:</b> O(V * E)<br><b>Space:</b> O(V)</td>
      <td>Use Bellman Ford algorithm. Relax all edges V-1 times. Then relax one more time. If any shortest path distance updates in the V-th relaxation, it means there is a negative weight cycle.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isNegativeWeightCycle(int n, vector&lt;vector&lt;int&gt;&gt; edges) {&#10;    vector&lt;int&gt; dist(n, 1e8);&#10;    dist[0] = 0;&#10;    for(int i = 0; i &lt; n - 1; i++) {&#10;        for(auto edge : edges) {&#10;            int u = edge[0], v = edge[1], wt = edge[2];&#10;            if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) {&#10;                dist[v] = dist[u] + wt;&#10;            }&#10;        }&#10;    }&#10;    for(auto edge : edges) {&#10;        int u = edge[0], v = edge[1], wt = edge[2];&#10;        if(dist[u] != 1e8 &amp;&amp; dist[u] + wt &lt; dist[v]) return 1;&#10;    }&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Graph 38 Find Bridge In A Graph<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Tarjan's Algorithm / DFS.</td>
      <td><b>Time:</b> O(V + E)<br><b>Space:</b> O(V)</td>
      <td>Remove the given edge `(c, d)` from the graph. Then run a DFS/BFS from `c`. If `d` is not reachable from `c`, then `(c, d)` was a bridge.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void dfs(int node, vector&lt;int&gt; adj[], vector&lt;bool&gt;&amp; vis, int c, int d) {&#10;    vis[node] = true;&#10;    for(int nbr : adj[node]) {&#10;        if((node == c &amp;&amp; nbr == d) || (node == d &amp;&amp; nbr == c)) continue;&#10;        if(!vis[nbr]) dfs(nbr, adj, vis, c, d);&#10;    }&#10;}&#10;int isBridge(int V, vector&lt;int&gt; adj[], int c, int d) {&#10;    vector&lt;bool&gt; vis(V, false);&#10;    dfs(c, adj, vis, c, d);&#10;    if(!vis[d]) return 1;&#10;    return 0;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Dynamic Programming

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
      <td rowspan="1">DP 01 Climbing Stairs<br><br></b> <a href="https://leetcode.com/problems/climbing-stairs/" target="_blank">LeetCode 70</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 3<br><b>Output:</b> 3 (1+1+1, 1+2, 2+1)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Space Optimization (Bottom-Up): Since state `n` only depends on `n-1` and `n-2`, we only need two variables.</td>
      <td><b>Edge Cases:</b> <b>Variable Swapping:</b> `prev2` becomes `prev`, and `prev` becomes the new `curr`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int climbStairs(int n) {&#10;    if (n &lt;= 1) return 1;&#10;    int prev2 = 1, prev = 1;&#10;    for(int i = 2; i &lt;= n; i++) {&#10;        int curr = prev + prev2;&#10;        prev2 = prev;&#10;        prev = curr;&#10;    }&#10;    return prev;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">DP 02 Longest Common Subsequence<br><br></b> <a href="https://leetcode.com/problems/longest-common-subsequence/" target="_blank">LeetCode 1143</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> text1 = "abcde", text2 = "ace"<br><b>Output:</b> 3 ("ace")</td>
      <td><b>Time:</b> O(M * N) (Constraint)<br><b>Space:</b> O(M * N) (Trade-off)</td>
      <td>Tabulation (Bottom-Up). Use a 2D array where `dp[i][j]` represents the LCS of prefixes of length `i` and `j`.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>1-Based Indexing:</b> Shifting indices by 1 prevents out-of-bounds checks and elegantly handles the 0-length prefix base case.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubsequence(std::string text1, std::string text2) {&#10;    int n = text1.length(), m = text2.length();&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; dp(n + 1, std::vector&lt;int&gt;(m + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];&#10;            else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">DP 03 Coin Change<br><br></b> <a href="https://leetcode.com/problems/coin-change/" target="_blank">LeetCode 322</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> coins = [1,2,5], amount = 11<br><b>Output:</b> 3 (5+5+1)</td>
      <td><b>Time:</b> O(Amount * N)<br><b>Space:</b> O(Amount)</td>
      <td>Unbounded Knapsack. State `dp[i]` is the min coins needed to make amount `i`. `dp[i] = min(dp[i], 1 + dp[i - coin])`.<br><br><b>Dependencies:</b> <code>std::min</code></td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Fill array with `Amount + 1` (acting as infinity). If `dp[Amount]` remains `Amount + 1`, return `-1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int coinChange(std::vector&lt;int&gt;&amp; coins, int amount) {&#10;    std::vector&lt;int&gt; dp(amount + 1, amount + 1);&#10;    dp[0] = 0;&#10;    for(int i = 1; i &lt;= amount; i++) {&#10;        for(int coin : coins) {&#10;            if(i - coin &gt;= 0) {&#10;                dp[i] = std::min(dp[i], 1 + dp[i - coin]);&#10;            }&#10;        }&#10;    }&#10;    return dp[amount] &gt; amount ? -1 : dp[amount];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">DP 04 Longest Increasing Subsequence<br><br></b> <a href="https://leetcode.com/problems/longest-increasing-subsequence/" target="_blank">LeetCode 300</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [10,9,2,5,3,7,101,18]<br><b>Output:</b> 4 ([2,3,7,101])</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td>Binary Search Patience Sorting method. Maintain a `temp` array. If current element is larger than `temp.back()`, append. Else, replace the first element >= current.<br><br><b>Dependencies:</b> <code>std::lower_bound</code> / <code>bisect_left</code></td>
      <td><b>Edge Cases:</b> <b>Temp Array:</b> `temp` does NOT store the actual LIS, but its length correctly represents the LIS length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLIS(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; temp;&#10;    for(int num : nums) {&#10;        auto it = std::lower_bound(temp.begin(), temp.end(), num);&#10;        if(it == temp.end()) temp.push_back(num);&#10;        else *it = num;&#10;    }&#10;    return temp.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">DP 05 House Robber<br><br></b> <a href="https://leetcode.com/problems/house-robber/" target="_blank">LeetCode 198</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [1,2,3,1]<br><b>Output:</b> 4 (Rob house 1 and 3)</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Space Optimized DP. Maintain two variables: `prev1` (max up to previous house) and `prev2` (max up to the house before previous). `curr = max(num + prev2, prev1)`.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Array length < 2:</b> Automatically handled if initialized properly and loop condition ensures no out-of-bounds.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int rob(std::vector&lt;int&gt;&amp; nums) {&#10;    int prev1 = 0, prev2 = 0;&#10;    for(int num : nums) {&#10;        int curr = std::max(num + prev2, prev1);&#10;        prev2 = prev1;&#10;        prev1 = curr;&#10;    }&#10;    return prev1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">DP 06 01 Knapsack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N=3, W=4, values[]={1,2,3}, weight[]={4,5,1}<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N * W)<br><b>Space:</b> O(W)</td>
      <td>2D DP or 1D array space-optimized DP. Check take and not-take scenarios.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int knapSack(int W, int wt[], int val[], int n) {&#10;    vector&lt;int&gt; prev(W + 1, 0);&#10;    for(int w = wt[0]; w &lt;= W; w++) prev[w] = val[0];&#10;    for(int ind = 1; ind &lt; n; ind++) {&#10;        for(int w = W; w &gt;= 0; w--) {&#10;            int notTake = prev[w];&#10;            int take = INT_MIN;&#10;            if(wt[ind] &lt;= w) take = val[ind] + prev[w - wt[ind]];&#10;            prev[w] = max(take, notTake);&#10;        }&#10;    }&#10;    return prev[W];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">DP 07 Edit Distance<br><br></b> <a href="https://leetcode.com/problems/edit-distance/" target="_blank">LeetCode 72</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> word1 = 'horse', word2 = 'ros'<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>2D DP. If chars match, dp[i-1][j-1]. Else, 1 + min(insert, delete, replace).</td>
      <td><b>Edge Cases:</b> <b>Empty Strings:</b> Deletions/insertions equal to length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minDistance(string word1, string word2) {&#10;    int n = word1.size(), m = word2.size();&#10;    vector&lt;int&gt; prev(m+1, 0), cur(m+1, 0);&#10;    for(int j=0; j&lt;=m; j++) prev[j] = j;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        cur[0] = i;&#10;        for(int j=1; j&lt;=m; j++) {&#10;            if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];&#10;            else cur[j] = 1 + min({prev[j], cur[j-1], prev[j-1]});&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">DP 08 Matrix Chain Multiplication<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N=5, arr=[40, 20, 30, 10, 30]<br><b>Output:</b> 26000</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>Partition DP. Try partitioning the matrices at every possible split `k` between `i` and `j`. Cost is `arr[i-1]*arr[k]*arr[j]`. Take the minimum.<br><br><b>Dependencies:</b> <code>#include <vector></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int f(int i, int j, vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; dp) {&#10;    if(i == j) return 0;&#10;    if(dp[i][j] != -1) return dp[i][j];&#10;    int mini = 1e9;&#10;    for(int k=i; k&lt;j; k++) {&#10;        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);&#10;        mini = min(mini, steps);&#10;    }&#10;    return dp[i][j] = mini;&#10;}&#10;int matrixMultiplication(int N, vector&lt;int&gt;&amp; arr) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(N, vector&lt;int&gt;(N, -1));&#10;    return f(1, N-1, arr, dp);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">DP 09 Subset Sum Problem<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> set=[3,34,4,12,5,2], sum=9<br><b>Output:</b> True</td>
      <td><b>Time:</b> O(N * Sum)<br><b>Space:</b> O(Sum) space optimized</td>
      <td>DP logic like 0/1 Knapsack. DP state is `dp[index][target]`. At each index, you can take or not take the element if `target >= arr[i]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isSubsetSum(vector&lt;int&gt;arr, int sum) {&#10;    int n = arr.size();&#10;    vector&lt;bool&gt; prev(sum+1, false), cur(sum+1, false);&#10;    prev[0] = cur[0] = true;&#10;    if(arr[0] &lt;= sum) prev[arr[0]] = true;&#10;    for(int ind=1; ind&lt;n; ind++) {&#10;        for(int target=1; target&lt;=sum; target++) {&#10;            bool notTaken = prev[target];&#10;            bool taken = false;&#10;            if(arr[ind] &lt;= target) taken = prev[target - arr[ind]];&#10;            cur[target] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">DP 10 Minimum Path Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-path-sum/" target="_blank">LeetCode 64</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> grid = [[1,3,1],[1,5,1],[4,2,1]]<br><b>Output:</b> 7</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>DP on Grids. Space optimize to 1D. `cur[j] = grid[i][j] + min(up, left)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;int&gt; prev(m, 0);&#10;    for(int i=0; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(m, 0);&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(i==0 &amp;&amp; j==0) cur[j] = grid[i][j];&#10;            else {&#10;                int up = grid[i][j], left = grid[i][j];&#10;                if(i&gt;0) up += prev[j]; else up += 1e9;&#10;                if(j&gt;0) left += cur[j-1]; else left += 1e9;&#10;                cur[j] = min(up, left);&#10;            }&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">DP 11 Triangle<br><br></b> <a href="https://leetcode.com/problems/triangle/" target="_blank">LeetCode 120</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> 11</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Start from bottom row and move upwards. `dp[j] = triangle[i][j] + min(dp[j], dp[j+1])`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minimumTotal(vector&lt;vector&lt;int&gt;&gt;&amp; triangle) {&#10;    int n = triangle.size();&#10;    vector&lt;int&gt; front = triangle[n-1];&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=i; j&gt;=0; j--) {&#10;            cur[j] = triangle[i][j] + min(front[j], front[j+1]);&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">DP 12 Minimum Falling Path Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-falling-path-sum/" target="_blank">LeetCode 931</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> 13</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Similar to minimum path sum, but we can fall diagonally. Space optimize by using previous row.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFallingPathSum(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    vector&lt;int&gt; prev = matrix[0];&#10;    for(int i=1; i&lt;n; i++) {&#10;        vector&lt;int&gt; cur(n, 0);&#10;        for(int j=0; j&lt;n; j++) {&#10;            int up = matrix[i][j] + prev[j];&#10;            int ld = matrix[i][j] + (j&gt;0 ? prev[j-1] : 1e9);&#10;            int rd = matrix[i][j] + (j&lt;n-1 ? prev[j+1] : 1e9);&#10;            cur[j] = min({up, ld, rd});&#10;        }&#10;        prev = cur;&#10;    }&#10;    int mini = 1e9;&#10;    for(int j=0; j&lt;n; j++) mini = min(mini, prev[j]);&#10;    return mini;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">DP 13 Cherry Pickup II<br><br></b> <a href="https://leetcode.com/problems/cherry-pickup-ii/" target="_blank">LeetCode 1463</a></td>
      <td rowspan="1"><b>Example 1:</b> 3D DP.</td>
      <td><b>Time:</b> O(N * M * M * 9)<br><b>Space:</b> O(M * M)</td>
      <td>Robots move simultaneously. State is `dp[row][col1][col2]`. Try all 9 combinations of moves for both robots.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int cherryPickup(vector&lt;vector&lt;int&gt;&gt;&amp; grid) {&#10;    int n = grid.size(), m = grid[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; front(m, vector&lt;int&gt;(m, 0)), cur(m, vector&lt;int&gt;(m, 0));&#10;    for(int j1=0; j1&lt;m; j1++) {&#10;        for(int j2=0; j2&lt;m; j2++) {&#10;            if(j1 == j2) front[j1][j2] = grid[n-1][j1];&#10;            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];&#10;        }&#10;    }&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        for(int j1=0; j1&lt;m; j1++) {&#10;            for(int j2=0; j2&lt;m; j2++) {&#10;                int maxi = -1e9;&#10;                for(int dj1=-1; dj1&lt;=1; dj1++) {&#10;                    for(int dj2=-1; dj2&lt;=1; dj2++) {&#10;                        int val = 0;&#10;                        if(j1 == j2) val = grid[i][j1];&#10;                        else val = grid[i][j1] + grid[i][j2];&#10;                        if(j1+dj1&gt;=0 &amp;&amp; j1+dj1&lt;m &amp;&amp; j2+dj2&gt;=0 &amp;&amp; j2+dj2&lt;m)&#10;                            val += front[j1+dj1][j2+dj2];&#10;                        else val += -1e9;&#10;                        maxi = max(maxi, val);&#10;                    }&#10;                }&#10;                cur[j1][j2] = maxi;&#10;            }&#10;        }&#10;        front = cur;&#10;    }&#10;    return front[0][m-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">DP 14 Partition Equal Subset Sum<br><br></b> <a href="https://leetcode.com/problems/partition-equal-subset-sum/" target="_blank">LeetCode 416</a></td>
      <td rowspan="1"><b>Example 1:</b><br><b>Output:</b> True.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td>If total sum is odd, impossible. Else, find if there's a subset with sum `Total/2` using space-optimized DP.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool canPartition(vector&lt;int&gt;&amp; nums) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum % 2 != 0) return false;&#10;    int target = sum / 2;&#10;    vector&lt;bool&gt; prev(target + 1, false);&#10;    prev[0] = true;&#10;    if(nums[0] &lt;= target) prev[nums[0]] = true;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;bool&gt; cur(target + 1, false);&#10;        cur[0] = true;&#10;        for(int t=1; t&lt;=target; t++) {&#10;            bool notTaken = prev[t];&#10;            bool taken = false;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken || taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[target];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">DP 15 Target Sum<br><br></b> <a href="https://leetcode.com/problems/target-sum/" target="_blank">LeetCode 494</a></td>
      <td rowspan="1"><b>Example 1:</b> Count Subsets with Diff = target.</td>
      <td><b>Time:</b> O(N * Target)<br><b>Space:</b> O(Target)</td>
      <td>Subset sum variation. `S1 - S2 = target`, `S1 + S2 = totalSum`. So, `S1 = (target + totalSum) / 2`. Find subsets with this target sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTargetSumWays(vector&lt;int&gt;&amp; nums, int target) {&#10;    int sum = 0; for(int n : nums) sum += n;&#10;    if(sum - target &lt; 0 || (sum - target) % 2 == 1) return 0;&#10;    int s2 = (sum - target) / 2;&#10;    vector&lt;int&gt; prev(s2 + 1, 0);&#10;    if(nums[0] == 0) prev[0] = 2;&#10;    else prev[0] = 1;&#10;    if(nums[0] != 0 &amp;&amp; nums[0] &lt;= s2) prev[nums[0]] = 1;&#10;    for(int ind=1; ind&lt;nums.size(); ind++) {&#10;        vector&lt;int&gt; cur(s2 + 1, 0);&#10;        for(int t=0; t&lt;=s2; t++) {&#10;            int notTaken = prev[t];&#10;            int taken = 0;&#10;            if(nums[ind] &lt;= t) taken = prev[t - nums[ind]];&#10;            cur[t] = notTaken + taken;&#10;        }&#10;        prev = cur;&#10;    }&#10;    return prev[s2];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">DP 16 Burst Balloons<br><br></b> <a href="https://leetcode.com/problems/burst-balloons/" target="_blank">LeetCode 312</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> nums = [3,1,5,8]<br><b>Output:</b> 167</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>MCM Pattern. Add 1 at the beginning and end. Loop lengths from 1 to N. Iterate start `i` and end `j`. Then iterate `k` from `i` to `j`, meaning balloon `k` is the LAST one to burst in the range `[i, j]`. The coins collected are `nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxCoins(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    nums.insert(nums.begin(), 1);&#10;    nums.push_back(1);&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 2, vector&lt;int&gt;(n + 2, 0));&#10;    for(int i=n; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=n; j++) {&#10;            if(i &gt; j) continue;&#10;            int maxi = INT_MIN;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];&#10;                maxi = max(maxi, cost);&#10;            }&#10;            dp[i][j] = maxi;&#10;        }&#10;    }&#10;    return dp[1][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">DP 17 Palindrome Partitioning II<br><br></b> <a href="https://leetcode.com/problems/palindrome-partitioning-ii/" target="_blank">LeetCode 132</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = 'aab'<br><b>Output:</b> 1</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Front Partitioning. `dp[i]` is the minimum cuts for `s[i...n-1]`. To compute `dp[i]`, iterate `j` from `i` to `n-1`. If `s[i...j]` is a palindrome, then `cost = 1 + dp[j+1]`. `dp[i]` is the minimum of these costs. Return `dp[0] - 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(string&amp; s, int i, int j) {&#10;    while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;    return true;&#10;}&#10;int minCut(string s) {&#10;    int n = s.length();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int minCuts = INT_MAX;&#10;        for(int j=i; j&lt;n; j++) {&#10;            if(isPalindrome(s, i, j)) {&#10;                int cost = 1 + dp[j+1];&#10;                minCuts = min(minCuts, cost);&#10;            }&#10;        }&#10;        dp[i] = minCuts;&#10;    }&#10;    return dp[0] - 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">DP 18 Evaluate Boolean Expression To True<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> MCM DP pattern.</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(N^2)</td>
      <td>MCM DP. `dp[i][j][isTrue]` stores the number of ways to evaluate `S[i..j]` to boolean `isTrue`. Iterate length, start, and partition `k`. Calculate T/F ways based on the operator at `k`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countWays(int N, string S){&#10;    int mod = 1003;&#10;    vector&lt;vector&lt;vector&lt;long long&gt;&gt;&gt; dp(N, vector&lt;vector&lt;long long&gt;&gt;(N, vector&lt;long long&gt;(2, 0)));&#10;    for(int i=N-1; i&gt;=0; i-=2) {&#10;        for(int j=i; j&lt;N; j+=2) {&#10;            if(i == j) {&#10;                dp[i][j][1] = (S[i] == &#x27;T&#x27;);&#10;                dp[i][j][0] = (S[i] == &#x27;F&#x27;);&#10;                continue;&#10;            }&#10;            long long waysT = 0, waysF = 0;&#10;            for(int k=i+1; k&lt;=j-1; k+=2) {&#10;                long long lT = dp[i][k-1][1], lF = dp[i][k-1][0];&#10;                long long rT = dp[k+1][j][1], rF = dp[k+1][j][0];&#10;                if(S[k] == &#x27;&amp;&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;|&#x27;) {&#10;                    waysT = (waysT + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lF * rF) % mod) % mod;&#10;                } else if(S[k] == &#x27;^&#x27;) {&#10;                    waysT = (waysT + (lT * rF) % mod + (lF * rT) % mod) % mod;&#10;                    waysF = (waysF + (lT * rT) % mod + (lF * rF) % mod) % mod;&#10;                }&#10;            }&#10;            dp[i][j][1] = waysT;&#10;            dp[i][j][0] = waysF;&#10;        }&#10;    }&#10;    return dp[0][N-1][1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">DP 19 Count Square Submatrices With All Ones<br><br></b> <a href="https://leetcode.com/problems/count-square-submatrices-with-all-ones/" target="_blank">LeetCode 1277</a></td>
      <td rowspan="1"><b>Example 1:</b> Return total count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M)</td>
      <td>`dp[i][j]` is the size of the largest square ending at `(i, j)`. It also represents the number of squares ending at `(i, j)`. `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1` if `matrix[i][j] == 1`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSquares(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int sum = 0;&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;m; j++) {&#10;            if(matrix[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                sum += dp[i][j];&#10;            }&#10;        }&#10;    }&#10;    return sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">DP 20 Minimum Cost To Cut A Stick<br><br></b> <a href="https://leetcode.com/problems/minimum-cost-to-cut-a-stick/" target="_blank">LeetCode 1547</a></td>
      <td rowspan="1"><b>Example 1:</b> Cost depends on current stick length.</td>
      <td><b>Time:</b> O(C^3) where C is number of cuts<br><b>Space:</b> O(C^2)</td>
      <td>Sort cuts array and prepend 0, append `n`. Use MCM pattern. `dp[i][j]` is the minimum cost to cut the stick between cuts `i` and `j`. `dp[i][j] = min(cost + cuts[j+1] - cuts[i-1])`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minCost(int n, vector&lt;int&gt;&amp; cuts) {&#10;    cuts.push_back(0);&#10;    cuts.push_back(n);&#10;    sort(cuts.begin(), cuts.end());&#10;    int c = cuts.size() - 2;&#10;    vector&lt;vector&lt;int&gt;&gt; dp(c + 2, vector&lt;int&gt;(c + 2, 0));&#10;    for(int i=c; i&gt;=1; i--) {&#10;        for(int j=1; j&lt;=c; j++) {&#10;            if(i &gt; j) continue;&#10;            int mini = INT_MAX;&#10;            for(int k=i; k&lt;=j; k++) {&#10;                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];&#10;                mini = min(mini, cost);&#10;            }&#10;            dp[i][j] = mini;&#10;        }&#10;    }&#10;    return dp[1][c];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">DP 21 Partition Array For Maximum Sum<br><br></b> <a href="https://leetcode.com/problems/partition-array-for-maximum-sum/" target="_blank">LeetCode 1043</a></td>
      <td rowspan="1"><b>Example 1:</b> Front partitioning DP.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N)</td>
      <td>Front partitioning. `dp[i]` is max sum for `arr[i..n-1]`. For each `i`, iterate `j` up to `i+k-1`. Find `maxi` element in this window, and add `maxi * length + dp[j+1]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumAfterPartitioning(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    vector&lt;int&gt; dp(n + 1, 0);&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        int max_val = 0;&#10;        int max_ans = 0;&#10;        int len = 0;&#10;        for(int j=i; j&lt;min(n, i + k); j++) {&#10;            len++;&#10;            max_val = max(max_val, arr[j]);&#10;            int sum = max_val * len + dp[j+1];&#10;            max_ans = max(max_ans, sum);&#10;        }&#10;        dp[i] = max_ans;&#10;    }&#10;    return dp[0];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">DP 22 Distinct Subsequences<br><br></b> <a href="https://leetcode.com/problems/distinct-subsequences/" target="_blank">LeetCode 115</a></td>
      <td rowspan="1"><b>Example 1:</b> Subsequence match count.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>If characters match, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`. If they don't, `dp[i][j] = dp[i-1][j]`. Optimize to 1D array.</td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Use double or long long, or cast to unsigned int.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numDistinct(string s, string t) {&#10;    int n = s.length(), m = t.length();&#10;    vector&lt;double&gt; dp(m + 1, 0);&#10;    dp[0] = 1;&#10;    for(int i=1; i&lt;=n; i++) {&#10;        for(int j=m; j&gt;=1; j--) {&#10;            if(s[i-1] == t[j-1]) {&#10;                dp[j] = dp[j-1] + dp[j];&#10;            }&#10;        }&#10;    }&#10;    return (int)dp[m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">DP 23 Wildcard Matching<br><br></b> <a href="https://leetcode.com/problems/wildcard-matching/" target="_blank">LeetCode 44</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td>Use a 2D DP array where `dp[i][j]` means if `s[0..i-1]` matches `p[0..j-1]`. If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, `dp[i][j] = dp[i-1][j-1]`. If `p[j-1] == '*'`, it can match empty (`dp[i][j-1]`) or match one character (`dp[i-1][j]`).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isMatch(string s, string p) {&#10;    int n = s.length(), m = p.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; dp(n + 1, vector&lt;bool&gt;(m + 1, false));&#10;    dp[0][0] = true;&#10;    for(int j = 1; j &lt;= m; j++) {&#10;        if(p[j-1] == &#x27;*&#x27;) dp[0][j] = dp[0][j-1];&#10;    }&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(p[j-1] == s[i-1] || p[j-1] == &#x27;?&#x27;) {&#10;                dp[i][j] = dp[i-1][j-1];&#10;            } else if(p[j-1] == &#x27;*&#x27;) {&#10;                dp[i][j] = dp[i-1][j] || dp[i][j-1];&#10;            }&#10;        }&#10;    }&#10;    return dp[n][m];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">DP 24 Best Time To Buy And Sell Stock II<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/" target="_blank">LeetCode 122</a></td>
      <td rowspan="1"><b>Example 1:</b> Valley Peak approach.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Add the profit whenever the price is higher than the previous day. This is equivalent to capturing every upward slope.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        if(prices[i] &gt; prices[i-1]) {&#10;            profit += prices[i] - prices[i-1];&#10;        }&#10;    }&#10;    return profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">DP 25 Best Time To Buy And Sell Stock III<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/" target="_blank">LeetCode 123</a></td>
      <td rowspan="1"><b>Example 1:</b> 3D DP / State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain four variables representing the max profit after first buy, first sell, second buy, and second sell. Update them iteratively.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;&#10;    for(int price : prices) {&#10;        buy1 = max(buy1, -price);&#10;        sell1 = max(sell1, buy1 + price);&#10;        buy2 = max(buy2, sell1 - price);&#10;        sell2 = max(sell2, buy2 + price);&#10;    }&#10;    return sell2;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">DP 26 Best Time To Buy And Sell Stock IV<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/" target="_blank">LeetCode 188</a></td>
      <td rowspan="1"><b>Example 1:</b> DP with transactions.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N * K) or O(K)</td>
      <td>If `k >= n/2`, it's equivalent to infinite transactions (Stock II). Else, use a DP array `dp[k][n]` where `dp[i][j]` is max profit using `i` transactions up to day `j`. Optimize inner loop by tracking `maxDiff = max(maxDiff, dp[i-1][j-1] - prices[j-1])`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(int k, vector&lt;int&gt;&amp; prices) {&#10;    int n = prices.size();&#10;    if(n &lt;= 1) return 0;&#10;    if(k &gt;= n / 2) {&#10;        int profit = 0;&#10;        for(int i = 1; i &lt; n; i++) {&#10;            if(prices[i] &gt; prices[i-1]) profit += prices[i] - prices[i-1];&#10;        }&#10;        return profit;&#10;    }&#10;    vector&lt;int&gt; buy(k + 1, INT_MIN), sell(k + 1, 0);&#10;    for(int price : prices) {&#10;        for(int i = 1; i &lt;= k; i++) {&#10;            buy[i] = max(buy[i], sell[i-1] - price);&#10;            sell[i] = max(sell[i], buy[i] + price);&#10;        }&#10;    }&#10;    return sell[k];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">DP 27 Best Time To Buy And Sell Stock With Cooldown<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/" target="_blank">LeetCode 309</a></td>
      <td rowspan="1"><b>Example 1:</b> State Machine DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain 3 states: `hold` (holding a stock), `sold` (just sold, entering cooldown next), `rest` (not holding, not in cooldown). Transitions: `hold = max(hold, rest - price)`, `sold = hold + price`, `rest = max(rest, sold_prev)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices) {&#10;    int hold = INT_MIN, sold = 0, rest = 0;&#10;    for(int price : prices) {&#10;        int prev_sold = sold;&#10;        sold = hold + price;&#10;        hold = max(hold, rest - price);&#10;        rest = max(rest, prev_sold);&#10;    }&#10;    return max(rest, sold);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">DP 28 Best Time To Buy And Sell Stock With Transaction Fee<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/" target="_blank">LeetCode 714</a></td>
      <td rowspan="1"><b>Example 1:</b> DP State Machine.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Similar to Stock II, but subtract `fee` when selling. Maintain `cash` (max profit not holding stock) and `hold` (max profit holding stock). `cash = max(cash, hold + price - fee)`, `hold = max(hold, cash - price)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(vector&lt;int&gt;&amp; prices, int fee) {&#10;    int cash = 0, hold = -prices[0];&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        cash = max(cash, hold + prices[i] - fee);&#10;        hold = max(hold, cash - prices[i]);&#10;    }&#10;    return cash;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">DP 29 Largest Divisible Subset<br><br></b> <a href="https://leetcode.com/problems/largest-divisible-subset/" target="_blank">LeetCode 368</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and LIS variant.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Sort the array. Then use LIS logic: `dp[i]` is max subset ending at `i`. If `nums[i] % nums[j] == 0`, `dp[i] = max(dp[i], dp[j] + 1)`. Also keep a `parent` array to reconstruct the subset.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; largestDivisibleSubset(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return {};&#10;    sort(nums.begin(), nums.end());&#10;    int n = nums.size(), max_len = 1, max_idx = 0;&#10;    vector&lt;int&gt; dp(n, 1), parent(n, -1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] % nums[j] == 0 &amp;&amp; dp[i] &lt; dp[j] + 1) {&#10;                dp[i] = dp[j] + 1;&#10;                parent[i] = j;&#10;            }&#10;        }&#10;        if(dp[i] &gt; max_len) {&#10;            max_len = dp[i];&#10;            max_idx = i;&#10;        }&#10;    }&#10;    vector&lt;int&gt; res;&#10;    while(max_idx != -1) {&#10;        res.push_back(nums[max_idx]);&#10;        max_idx = parent[max_idx];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">DP 30 Longest String Chain<br><br></b> <a href="https://leetcode.com/problems/longest-string-chain/" target="_blank">LeetCode 1048</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort by length and use hash map.</td>
      <td><b>Time:</b> O(N log N + N * L^2) where L is max word length<br><b>Space:</b> O(N * L)</td>
      <td>Sort words by length. Use a hash map `dp` to store the longest chain ending at `word`. For each word, try removing one character at a time to form `prev_word`. `dp[word] = max(dp[word], dp[prev_word] + 1)`.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestStrChain(vector&lt;string&gt;&amp; words) {&#10;    sort(words.begin(), words.end(), [](const string&amp; a, const string&amp; b) {&#10;        return a.length() &lt; b.length();&#10;    });&#10;    unordered_map&lt;string, int&gt; dp;&#10;    int max_len = 1;&#10;    for(const string&amp; word : words) {&#10;        dp[word] = 1;&#10;        for(int i = 0; i &lt; word.length(); i++) {&#10;            string prev = word.substr(0, i) + word.substr(i + 1);&#10;            if(dp.find(prev) != dp.end()) {&#10;                dp[word] = max(dp[word], dp[prev] + 1);&#10;            }&#10;        }&#10;        max_len = max(max_len, dp[word]);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">DP 31 Longest Bitonic Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> LIS from left + LIS from right.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Compute LIS ending at `i` from left to right (`inc[i]`). Compute LIS starting at `i` from right to left (`dec[i]`). The max bitonic subsequence length is `max(inc[i] + dec[i] - 1)` for all `i`. Sometimes pure increasing or pure decreasing is also bitonic depending on definition, adjust if necessary.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int LongestBitonicSequence(vector&lt;int&gt; nums) {&#10;    int n = nums.size();&#10;    vector&lt;int&gt; inc(n, 1), dec(n, 1);&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) inc[i] = max(inc[i], inc[j] + 1);&#10;        }&#10;    }&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        for(int j = n - 1; j &gt; i; j--) {&#10;            if(nums[i] &gt; nums[j]) dec[i] = max(dec[i], dec[j] + 1);&#10;        }&#10;    }&#10;    int max_len = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        // Depending on problem variant, might require both to be &gt; 1 to be valid peak&#10;        max_len = max(max_len, inc[i] + dec[i] - 1);&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">DP 32 Number Of Longest Increasing Subsequence<br><br></b> <a href="https://leetcode.com/problems/number-of-longest-increasing-subsequence/" target="_blank">LeetCode 673</a></td>
      <td rowspan="1"><b>Example 1:</b> Two DP arrays (Length and Count).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Maintain `lengths[i]` (length of LIS ending at i) and `counts[i]` (number of LIS ending at i). If `nums[i] > nums[j]`: if `lengths[j] + 1 > lengths[i]`, then `lengths[i] = lengths[j] + 1` and `counts[i] = counts[j]`. Else if `lengths[j] + 1 == lengths[i]`, then `counts[i] += counts[j]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findNumberOfLIS(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), max_len = 0, res = 0;&#10;    vector&lt;int&gt; len(n, 1), count(n, 1);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(nums[i] &gt; nums[j]) {&#10;                if(len[j] + 1 &gt; len[i]) {&#10;                    len[i] = len[j] + 1;&#10;                    count[i] = count[j];&#10;                } else if(len[j] + 1 == len[i]) {&#10;                    count[i] += count[j];&#10;                }&#10;            }&#10;        }&#10;        if(len[i] &gt; max_len) {&#10;            max_len = len[i];&#10;            res = count[i];&#10;        } else if(len[i] == max_len) {&#10;            res += count[i];&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">DP 33 Longest Alternating Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Two state DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain two lengths: `up` (ending with ascending) and `down` (ending with descending). Iterate array: if `arr[i] > arr[i-1]`, `up = down + 1`. If `arr[i] < arr[i-1]`, `down = up + 1`. Return `max(up, down)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int AlternatingaMaxLength(vector&lt;int&gt;&amp; nums) {&#10;    if(nums.empty()) return 0;&#10;    int up = 1, down = 1;&#10;    for(int i = 1; i &lt; nums.size(); i++) {&#10;        if(nums[i] &gt; nums[i-1]) up = down + 1;&#10;        else if(nums[i] &lt; nums[i-1]) down = up + 1;&#10;    }&#10;    return max(up, down);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">DP 34 Largest Square Formed In A Matrix<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Bottom-up DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) or O(M)</td>
      <td>`dp[i][j]` is side of max square ending at `(i, j)`. If `mat[i][j] == 1`, `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`. Result is max over all `dp[i][j]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSquare(int n, int m, vector&lt;vector&lt;int&gt;&gt; mat) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n, vector&lt;int&gt;(m, 0));&#10;    int ans = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; m; j++) {&#10;            if(mat[i][j] == 1) {&#10;                if(i == 0 || j == 0) dp[i][j] = 1;&#10;                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;&#10;                ans = max(ans, dp[i][j]);&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">DP 35 Pairs With Specific Difference<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and DP or Greedy.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Sort array. Iterate from end. If `arr[i] - arr[i-1] < K`, we pair them, add sum to answer, and `i -= 2`. Else, `i -= 1`. Greedy approach works because pairing larger numbers gives a larger sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {&#10;    sort(arr, arr + N);&#10;    int ans = 0;&#10;    for(int i = N - 1; i &gt; 0; ) {&#10;        if(arr[i] - arr[i-1] &lt; K) {&#10;            ans += arr[i] + arr[i-1];&#10;            i -= 2;&#10;        } else {&#10;            i--;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">DP 36 Maximum Path Sum In Matrix<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Start from bottom row up. `dp[i][j] = matrix[i][j] + max(dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1])`. The answer is max value in `dp[0]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maximumPath(int N, vector&lt;vector&lt;int&gt;&gt; Matrix) {&#10;    vector&lt;int&gt; prev(N, 0), curr(N, 0);&#10;    for(int j = 0; j &lt; N; j++) prev[j] = Matrix[N-1][j];&#10;    for(int i = N - 2; i &gt;= 0; i--) {&#10;        for(int j = 0; j &lt; N; j++) {&#10;            int up = Matrix[i][j] + prev[j];&#10;            int ld = Matrix[i][j] + (j &gt; 0 ? prev[j-1] : 0);&#10;            int rd = Matrix[i][j] + (j &lt; N - 1 ? prev[j+1] : 0);&#10;            curr[j] = max({up, ld, rd});&#10;        }&#10;        prev = curr;&#10;    }&#10;    int ans = 0;&#10;    for(int j = 0; j &lt; N; j++) ans = max(ans, prev[j]);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">DP 37 Maximum Difference Of Zeros And Ones In Binary String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Kadane's Algorithm.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Convert '0' to 1 and '1' to -1. Find the maximum subarray sum using Kadane's algorithm. If max sum is negative, it means string has all 1s, return -1.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubstring(string S) {&#10;    int mx = INT_MIN, curr = 0;&#10;    for(char c : S) {&#10;        int val = c == &#x27;0&#x27; ? 1 : -1;&#10;        curr = max(val, curr + val);&#10;        mx = max(mx, curr);&#10;    }&#10;    return mx;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">DP 38 Minimum Removals From Array To Make Max Min K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-removals3851/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP after sorting.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Sort array. We want to find the longest subarray `arr[i..j]` such that `arr[j] - arr[i] <= K`. `dp[i]` could store the max `j` for index `i`. Or use Binary Search (`upper_bound`) for each `i` to find the valid `j`, maximizing `j - i + 1`. Total removed = `N - max_length`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removals(vector&lt;int&gt;&amp; arr, int k) {&#10;    int n = arr.size();&#10;    sort(arr.begin(), arr.end());&#10;    int maxLen = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int j = upper_bound(arr.begin(), arr.end(), arr[i] + k) - arr.begin() - 1;&#10;        maxLen = max(maxLen, j - i + 1);&#10;    }&#10;    return n - maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">DP 39 Longest Common Substring<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 2D DP.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(M)</td>
      <td>`dp[i][j]` is the length of longest common suffix of `S1[0..i-1]` and `S2[0..j-1]`. If `S1[i-1] == S2[j-1]`, `dp[i][j] = dp[i-1][j-1] + 1`. Else, `dp[i][j] = 0`. Max value in `dp` table is answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestCommonSubstr(string S1, string S2, int n, int m) {&#10;    vector&lt;int&gt; prev(m + 1, 0), curr(m + 1, 0);&#10;    int ans = 0;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= m; j++) {&#10;            if(S1[i-1] == S2[j-1]) {&#10;                curr[j] = prev[j-1] + 1;&#10;                ans = max(ans, curr[j]);&#10;            } else {&#10;                curr[j] = 0;&#10;            }&#10;        }&#10;        prev = curr;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">DP 40 Reach A Given Score<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Unbounded Knapsack.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>`dp[i]` represents number of ways to reach score `i`. Init `dp[0] = 1`. For each score option (3, 5, 10), iterate from option to `n`, `dp[i] += dp[i - option]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int count(long long int n) {&#10;    vector&lt;long long int&gt; dp(n + 1, 0);&#10;    dp[0] = 1;&#10;    vector&lt;int&gt; scores = {3, 5, 10};&#10;    for(int s : scores) {&#10;        for(int i = s; i &lt;= n; i++) {&#10;            dp[i] += dp[i - s];&#10;        }&#10;    }&#10;    return dp[n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">DP 41 Coin Change Maximum Ways<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/coin-change2448/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 1D Tabulation.</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(N)</td>
      <td>Create a `dp` array of size `N + 1` initialized to 0. `dp[0] = 1`. For each coin, iterate through all amounts from `coin` to `N` and update `dp[j] += dp[j - coin]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long int count(int coins[], int N, int sum) {&#10;    vector&lt;long long int&gt; dp(sum + 1, 0);&#10;    dp[0] = 1;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        for(int j = coins[i]; j &lt;= sum; j++) {&#10;            dp[j] += dp[j - coins[i]];&#10;        }&#10;    }&#10;    return dp[sum];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">DP 42 Palindromic Partitioning<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> 1D DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Create a `dp` array where `dp[i]` is min cuts for `str[0..i]`. Also use a 2D boolean DP to check if `str[j..i]` is a palindrome. If it is, `dp[i] = min(dp[i], dp[j-1] + 1)`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int palindromicPartition(string str) {&#10;    int n = str.length();&#10;    vector&lt;vector&lt;bool&gt;&gt; isPal(n, vector&lt;bool&gt;(n, false));&#10;    vector&lt;int&gt; dp(n, 0);&#10;    for(int i = 0; i &lt; n; i++) {&#10;        int minCut = i;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            if(str[i] == str[j] &amp;&amp; (i - j &lt; 2 || isPal[j+1][i-1])) {&#10;                isPal[j][i] = true;&#10;                if(j == 0) minCut = 0;&#10;                else minCut = min(minCut, dp[j-1] + 1);&#10;            }&#10;        }&#10;        dp[i] = minCut;&#10;    }&#10;    return dp[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">DP 43 Maximum Sum Increasing Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP (LIS variant).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Variation of LIS. Create an array `msis` initialized with the given array values. For each `i` from 1 to `n-1`, for each `j` from 0 to `i-1`, if `arr[i] > arr[j]` and `msis[i] < msis[j] + arr[i]`, update `msis[i]`. The max in `msis` is the answer.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSumIS(int arr[], int n) {&#10;    vector&lt;int&gt; msis(arr, arr + n);&#10;    int max_sum = msis[0];&#10;    for(int i = 1; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(arr[i] &gt; arr[j] &amp;&amp; msis[i] &lt; msis[j] + arr[i]) {&#10;                msis[i] = msis[j] + arr[i];&#10;            }&#10;        }&#10;        max_sum = max(max_sum, msis[i]);&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">DP 44 Count All Subsequences Having Product Less Than K<br><br></b> <a href="https://www.geeksforgeeks.org/count-subsequences-product-less-k/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N * K)<br><b>Space:</b> O(N * K)</td>
      <td>Use a 2D DP array where `dp[i][j]` is the number of subsequences of first `i` elements with product less than or equal to `j`. `dp[i][j] = dp[i-1][j] + dp[i-1][j/arr[i-1]] + 1`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSubsequences(vector&lt;int&gt;&amp; a, int k) {&#10;    int n = a.size();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(k + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= k; j++) {&#10;            dp[i][j] = dp[i - 1][j];&#10;            if(a[i - 1] &lt;= j &amp;&amp; a[i - 1] &gt; 0) {&#10;                dp[i][j] += dp[i - 1][j / a[i - 1]] + 1;&#10;            }&#10;        }&#10;    }&#10;    return dp[n][k];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">DP 45 Longest Subsequence Such That Difference Between Adjacents Is One<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP (LIS variant).</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N)</td>
      <td>Use a 1D DP array `dp` where `dp[i]` is the length of the longest subsequence ending at `i`. For each `i`, check all `j < i`. If `abs(A[i] - A[j]) == 1`, update `dp[i] = max(dp[i], dp[j] + 1)`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestSubsequence(int N, int A[]) {&#10;    vector&lt;int&gt; dp(N, 1);&#10;    int ans = 1;&#10;    for(int i = 1; i &lt; N; i++) {&#10;        for(int j = 0; j &lt; i; j++) {&#10;            if(abs(A[i] - A[j]) == 1) {&#10;                dp[i] = max(dp[i], dp[j] + 1);&#10;            }&#10;        }&#10;        ans = max(ans, dp[i]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">DP 46 Maximum Subsequence Sum Such That No Three Are Consecutive<br><br></b> <a href="https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Use a DP array. `dp[i]` is the max sum considering up to index `i`. For `i`, the max sum is `max(dp[i-1] (exclude i), dp[i-2] + arr[i] (exclude i-1), dp[i-3] + arr[i] + arr[i-1] (exclude i-2))`.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSum(vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    if(n == 0) return 0;&#10;    if(n == 1) return arr[0];&#10;    if(n == 2) return arr[0] + arr[1];&#10;    vector&lt;int&gt; dp(n, 0);&#10;    dp[0] = arr[0];&#10;    dp[1] = arr[0] + arr[1];&#10;    dp[2] = max({dp[1], arr[0] + arr[2], arr[1] + arr[2]});&#10;    for(int i = 3; i &lt; n; i++) {&#10;        dp[i] = max({dp[i-1], dp[i-2] + arr[i], dp[i-3] + arr[i] + arr[i-1]});&#10;    }&#10;    return dp[n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">DP 47 Egg Dropping Puzzle<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP + Binary Search / Math.</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td>Use DP. `dp[i][j]` is the min attempts with `i` eggs and `j` floors. Try dropping from every floor `x` from 1 to `j`. `res = 1 + max(dp[i-1][x-1] (breaks), dp[i][j-x] (doesn't break))`. Optimize this nested loop using Binary Search or use a different state `dp[m][k]` = floors checked with `m` moves and `k` eggs.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int eggDrop(int n, int k) {&#10;    vector&lt;vector&lt;int&gt;&gt; dp(k + 1, vector&lt;int&gt;(n + 1, 0));&#10;    int m = 0;&#10;    while(dp[m][n] &lt; k) {&#10;        m++;&#10;        for(int x = 1; x &lt;= n; x++) {&#10;            dp[m][x] = 1 + dp[m-1][x-1] + dp[m-1][x];&#10;        }&#10;    }&#10;    return m;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">DP 48 Maximum Length Chain Of Pairs<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/max-length-chain/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sort and Greedy / DP.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>This is exactly the Activity Selection Problem. Sort the pairs by their second element. Iterate through the sorted pairs and keep track of the end of the last selected pair. If the next pair's start is > last end, select it.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct val {&#10;    int first;&#10;    int second;&#10;};&#10;bool compare(struct val a, struct val b) {&#10;    return a.second &lt; b.second;&#10;}&#10;int maxChainLen(struct val p[], int n) {&#10;    sort(p, p + n, compare);&#10;    int count = 1;&#10;    int last_end = p[0].second;&#10;    for(int i = 1; i &lt; n; i++) {&#10;        if(p[i].first &gt; last_end) {&#10;            count++;&#10;            last_end = p[i].second;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">49</td>
      <td rowspan="1">DP 49 Optimal Strategy For A Game<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>If you pick `i`, opponent picks `i+1` or `j`, leaving you with `(i+2, j)` or `(i+1, j-1)`. Opponent plays optimally to minimize your profit. So you get `A[i] + min(dp(i+2, j), dp(i+1, j-1))`. Similarly for picking `j`. Take the max of these two choices.<br><br><b>Dependencies:</b> DP</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maximumAmount(int arr[], int n) {&#10;    vector&lt;vector&lt;long long&gt;&gt; dp(n, vector&lt;long long&gt;(n, 0));&#10;    for(int gap = 0; gap &lt; n; gap++) {&#10;        for(int i = 0, j = gap; j &lt; n; i++, j++) {&#10;            long long x = ((i + 2) &lt;= j) ? dp[i+2][j] : 0;&#10;            long long y = ((i + 1) &lt;= (j - 1)) ? dp[i+1][j-1] : 0;&#10;            long long z = (i &lt;= (j - 2)) ? dp[i][j-2] : 0;&#10;            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));&#10;        }&#10;    }&#10;    return dp[0][n-1];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">50</td>
      <td rowspan="1">DP 50 Minimum Insertions To Make String Palindrome<br><br></b> <a href="https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/" target="_blank">LeetCode 1312</a></td>
      <td rowspan="1"><b>Example 1:</b> Longest Palindromic Subsequence.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>Find the Longest Palindromic Subsequence (LPS). The minimum insertions required will be `string_length - LPS_length`. LPS is just LCS(s, reverse(s)).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minInsertions(string s) {&#10;    int n = s.length();&#10;    string t = s;&#10;    reverse(t.begin(), t.end());&#10;    vector&lt;vector&lt;int&gt;&gt; dp(n + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];&#10;            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);&#10;        }&#10;    }&#10;    return n - dp[n][n];&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">51</td>
      <td rowspan="1">DP 51 Print Longest Common Subsequence<br><br></b> <a href="https://www.geeksforgeeks.org/printing-longest-common-subsequence/" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> DP table backtracking.</td>
      <td><b>Time:</b> O(M * N)<br><b>Space:</b> O(M * N)</td>
      <td>Build the LCS DP table. Start from `dp[m][n]`. If `s1[i-1] == s2[j-1]`, include this character in the result and move diagonally to `dp[i-1][j-1]`. Otherwise, move to the maximum of `dp[i-1][j]` or `dp[i][j-1]`. Reverse the string at the end.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string printLCS(string s1, string s2) {&#10;    int m = s1.length(), n = s2.length();&#10;    vector&lt;vector&lt;int&gt;&gt; dp(m + 1, vector&lt;int&gt;(n + 1, 0));&#10;    for(int i = 1; i &lt;= m; i++) {&#10;        for(int j = 1; j &lt;= n; j++) {&#10;            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];&#10;            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);&#10;        }&#10;    }&#10;    int i = m, j = n;&#10;    string res = &quot;&quot;;&#10;    while(i &gt; 0 &amp;&amp; j &gt; 0) {&#10;        if(s1[i-1] == s2[j-1]) {&#10;            res += s1[i-1];&#10;            i--; j--;&#10;        } else if(dp[i-1][j] &gt; dp[i][j-1]) i--;&#10;        else j--;&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Tries

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
      <td rowspan="1">Trie 01 Implement Trie Prefix Tree<br><br></b> <a href="https://leetcode.com/problems/implement-trie-prefix-tree/" target="_blank">LeetCode 208</a></td>
      <td rowspan="1"><b>Example 1:</b> `insert("apple")`, `search("apple")` -> true, `search("app")` -> false, `startsWith("app")` -> true.<br><br><b>Note (Constraint):</b> 1 &le; word.length &le; 2000, lowercase English letters.</td>
      <td><b>Time:</b> O(Length of word) (Constraint)<br><b>Space:</b> O(Length * 26) per word</td>
      <td>Use a Tree where each node contains an array of 26 pointers (for 'a'-'z') and a boolean flag `isEnd`.<br><br><b>Dependencies:</b> Custom Node Struct/Class</td>
      <td><b>Edge Cases:</b> <b>startsWith vs search:</b> `startsWith` returns true simply if the traversal succeeds without hitting NULL. `search` requires the final node's `isEnd` flag to be true.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    bool flag = false;&#10;    bool containsKey(char ch) { return (links[ch - &#x27;a&#x27;] != nullptr); }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void setEnd() { flag = true; }&#10;    bool isEnd() { return flag; }&#10;};&#10;&#10;class Trie {&#10;private:&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    &#10;    void insert(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) {&#10;                node-&gt;put(ch, new Node());&#10;            }&#10;            node = node-&gt;get(ch);&#10;        }&#10;        node-&gt;setEnd();&#10;    }&#10;    &#10;    bool search(std::string word) {&#10;        Node* node = root;&#10;        for (char ch : word) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return node-&gt;isEnd();&#10;    }&#10;    &#10;    bool startsWith(std::string prefix) {&#10;        Node* node = root;&#10;        for (char ch : prefix) {&#10;            if (!node-&gt;containsKey(ch)) return false;&#10;            node = node-&gt;get(ch);&#10;        }&#10;        return true;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Trie 02 Implement Trie II<br><br></b> <a href="https://www.codingninjas.com/studio/problems/implement-trie_1387095" target="_blank">Coding Ninjas</a></td>
      <td rowspan="1"><b>Example 1:</b> Specialized Trie functions.</td>
      <td><b>Time:</b> O(len) per operation<br><b>Space:</b> O(N * len)</td>
      <td>Trie Nodes have a `cntEndWith` and `cntPrefix` integers. Increment `cntPrefix` dynamically as you insert, and `cntEndWith` at the final node. Decrement them during erase.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    int cntEndWith = 0;&#10;    int cntPrefix = 0;&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    void increaseEnd() { cntEndWith++; }&#10;    void increasePrefix() { cntPrefix++; }&#10;    void deleteEnd() { cntEndWith--; }&#10;    void reducePrefix() { cntPrefix--; }&#10;};&#10;class Trie {&#10;private: Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(!node-&gt;containsKey(word[i])) node-&gt;put(word[i], new Node());&#10;            node = node-&gt;get(word[i]);&#10;            node-&gt;increasePrefix();&#10;        }&#10;        node-&gt;increaseEnd();&#10;    }&#10;    int countWordsEqualTo(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(node-&gt;containsKey(word[i])) node = node-&gt;get(word[i]);&#10;            else return 0;&#10;        }&#10;        return node-&gt;cntEndWith;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Trie 03 Longest String With All Prefixes<br><br></b> <a href="https://www.codingninjas.com/codestudio/problems/complete-string_2687860" target="_blank">Coding Ninjas</a></td>
      <td rowspan="1"><b>Example 1:</b> Insert all, check each word.</td>
      <td><b>Time:</b> O(N * max_len)<br><b>Space:</b> O(N * max_len)</td>
      <td>Insert all words into a Trie. For each word, check if every prefix exists (i.e., every node from root to end has `isEnd == true`). Keep track of the longest valid word. Resolve ties lexicographically.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node *links[26];&#10;    bool flag = false;&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;    void setEnd() { flag = true; }&#10;    bool isEnd() { return flag; }&#10;};&#10;class Trie {&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(!node-&gt;containsKey(word[i])) node-&gt;put(word[i], new Node());&#10;            node = node-&gt;get(word[i]);&#10;        }&#10;        node-&gt;setEnd();&#10;    }&#10;    bool checkIfPrefixExists(string word) {&#10;        Node* node = root;&#10;        for(int i=0; i&lt;word.length(); i++) {&#10;            if(node-&gt;containsKey(word[i])) {&#10;                node = node-&gt;get(word[i]);&#10;                if(!node-&gt;isEnd()) return false;&#10;            } else return false;&#10;        }&#10;        return true;&#10;    }&#10;};&#10;string completeString(int n, vector&lt;string&gt; &amp;a){&#10;    Trie trie;&#10;    for(auto &amp;word : a) trie.insert(word);&#10;    string longest = &quot;&quot;;&#10;    for(auto &amp;word : a) {&#10;        if(trie.checkIfPrefixExists(word)) {&#10;            if(word.length() &gt; longest.length()) {&#10;                longest = word;&#10;            } else if(word.length() == longest.length() &amp;&amp; word &lt; longest) {&#10;                longest = word;&#10;            }&#10;        }&#10;    }&#10;    if(longest == &quot;&quot;) return &quot;None&quot;;&#10;    return longest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Trie 04 Number Of Distinct Substrings In A String<br><br></b> <a href="https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292" target="_blank">Coding Ninjas</a></td>
      <td rowspan="1"><b>Example 1:</b> Insert all suffixes.</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(N^2)</td>
      <td>To find all substrings, iterate `i` from 0 to N-1, and `j` from `i` to N-1. Each sequence `s[i...j]` is a substring. Insert it into the Trie. Every time we create a new node, it corresponds to a new distinct substring. Increment count. Add 1 for the empty substring.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node *links[26];&#10;    bool containsKey(char ch) { return links[ch - &#x27;a&#x27;] != NULL; }&#10;    void put(char ch, Node* node) { links[ch - &#x27;a&#x27;] = node; }&#10;    Node* get(char ch) { return links[ch - &#x27;a&#x27;]; }&#10;};&#10;int countDistinctSubstrings(string s) {&#10;    Node* root = new Node();&#10;    int count = 0;&#10;    for(int i=0; i&lt;s.length(); i++) {&#10;        Node* node = root;&#10;        for(int j=i; j&lt;s.length(); j++) {&#10;            if(!node-&gt;containsKey(s[j])) {&#10;                node-&gt;put(s[j], new Node());&#10;                count++;&#10;            }&#10;            node = node-&gt;get(s[j]);&#10;        }&#10;    }&#10;    return count + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Trie 05 Maximum Xor Of Two Numbers In An Array<br><br></b> <a href="https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/" target="_blank">LeetCode 421</a></td>
      <td rowspan="1"><b>Example 1:</b> Bit Trie.</td>
      <td><b>Time:</b> O(N * 32)<br><b>Space:</b> O(N * 32)</td>
      <td>Insert binary representation of each number (from MSB to LSB, 31 to 0) into a Trie. To find max XOR for `x`, traverse the Trie aiming for opposite bits (1 for 0, 0 for 1). If opposite bit exists, go that way and add `1 << i` to result. Else go same way.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node *links[2];&#10;    bool containsKey(int bit) { return links[bit] != NULL; }&#10;    void put(int bit, Node* node) { links[bit] = node; }&#10;    Node* get(int bit) { return links[bit]; }&#10;};&#10;class Trie {&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(int num) {&#10;        Node* node = root;&#10;        for(int i=31; i&gt;=0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(!node-&gt;containsKey(bit)) {&#10;                node-&gt;put(bit, new Node());&#10;            }&#10;            node = node-&gt;get(bit);&#10;        }&#10;    }&#10;    int getMax(int num) {&#10;        Node* node = root;&#10;        int maxNum = 0;&#10;        for(int i=31; i&gt;=0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(node-&gt;containsKey(1 - bit)) {&#10;                maxNum = maxNum | (1 &lt;&lt; i);&#10;                node = node-&gt;get(1 - bit);&#10;            } else {&#10;                node = node-&gt;get(bit);&#10;            }&#10;        }&#10;        return maxNum;&#10;    }&#10;};&#10;int findMaximumXOR(vector&lt;int&gt;&amp; nums) {&#10;    Trie trie;&#10;    for(auto &amp;it : nums) trie.insert(it);&#10;    int maxi = 0;&#10;    for(auto &amp;it : nums) {&#10;        maxi = max(maxi, trie.getMax(it));&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Trie 06 Maximum Xor With An Element From Array<br><br></b> <a href="https://leetcode.com/problems/maximum-xor-with-an-element-from-array/" target="_blank">LeetCode 1707</a></td>
      <td rowspan="1"><b>Example 1:</b> Offline Queries.</td>
      <td><b>Time:</b> O(N log N + Q log Q + Q * 32 + N * 32)<br><b>Space:</b> O(N * 32 + Q)</td>
      <td>Sort `nums` array. Store queries as `{m, x, index}` and sort them by `m`. Iterate through queries. While `nums[i] <= m`, insert `nums[i]` into Trie. If Trie is empty, answer is -1. Else, query Trie for max XOR with `x`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node *links[2];&#10;    bool containsKey(int bit) { return links[bit] != NULL; }&#10;    void put(int bit, Node* node) { links[bit] = node; }&#10;    Node* get(int bit) { return links[bit]; }&#10;};&#10;class Trie {&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(int num) {&#10;        Node* node = root;&#10;        for(int i=31; i&gt;=0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(!node-&gt;containsKey(bit)) node-&gt;put(bit, new Node());&#10;            node = node-&gt;get(bit);&#10;        }&#10;    }&#10;    int getMax(int num) {&#10;        Node* node = root;&#10;        int maxNum = 0;&#10;        for(int i=31; i&gt;=0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(node-&gt;containsKey(1 - bit)) {&#10;                maxNum = maxNum | (1 &lt;&lt; i);&#10;                node = node-&gt;get(1 - bit);&#10;            } else {&#10;                node = node-&gt;get(bit);&#10;            }&#10;        }&#10;        return maxNum;&#10;    }&#10;};&#10;vector&lt;int&gt; maximizeXor(vector&lt;int&gt;&amp; nums, vector&lt;vector&lt;int&gt;&gt;&amp; queries) {&#10;    sort(nums.begin(), nums.end());&#10;    vector&lt;pair&lt;int, pair&lt;int, int&gt;&gt;&gt; oQ;&#10;    for(int i=0; i&lt;queries.size(); i++) {&#10;        oQ.push_back({queries[i][1], {queries[i][0], i}});&#10;    }&#10;    sort(oQ.begin(), oQ.end());&#10;    vector&lt;int&gt; ans(queries.size(), 0);&#10;    int ind = 0;&#10;    int n = nums.size();&#10;    Trie trie;&#10;    for(int i=0; i&lt;oQ.size(); i++) {&#10;        int m = oQ[i].first, x = oQ[i].second.first, qInd = oQ[i].second.second;&#10;        while(ind &lt; n &amp;&amp; nums[ind] &lt;= m) {&#10;            trie.insert(nums[ind]);&#10;            ind++;&#10;        }&#10;        if(ind == 0) ans[qInd] = -1;&#10;        else ans[qInd] = trie.getMax(x);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Trie 07 Word Search II<br><br></b> <a href="https://leetcode.com/problems/word-search-ii/" target="_blank">LeetCode 212</a></td>
      <td rowspan="1"><b>Example 1:</b> DFS + Trie.</td>
      <td><b>Time:</b> O(M * N * 4^L)<br><b>Space:</b> O(sum(L))</td>
      <td>Insert all words into a Trie. Store the actual word at the `isEnd` node for easy retrieval. Do DFS from each cell. During DFS, traverse the Trie simultaneously. If a Trie node has a word, add it to results and remove the word from the node to avoid duplicates.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    string word = &quot;&quot;;&#10;};&#10;class Trie {&#10;public:&#10;    Node* root = new Node();&#10;    void insert(string&amp; w) {&#10;        Node* node = root;&#10;        for(char c : w) {&#10;            if(!node-&gt;links[c-&#x27;a&#x27;]) node-&gt;links[c-&#x27;a&#x27;] = new Node();&#10;            node = node-&gt;links[c-&#x27;a&#x27;];&#10;        }&#10;        node-&gt;word = w;&#10;    }&#10;};&#10;void dfs(vector&lt;vector&lt;char&gt;&gt;&amp; board, int i, int j, Node* p, vector&lt;string&gt;&amp; res) {&#10;    char c = board[i][j];&#10;    if(c == &#x27;#&#x27; || !p-&gt;links[c-&#x27;a&#x27;]) return;&#10;    p = p-&gt;links[c-&#x27;a&#x27;];&#10;    if(p-&gt;word != &quot;&quot;) {&#10;        res.push_back(p-&gt;word);&#10;        p-&gt;word = &quot;&quot;;&#10;    }&#10;    board[i][j] = &#x27;#&#x27;;&#10;    if(i &gt; 0) dfs(board, i-1, j, p, res);&#10;    if(j &gt; 0) dfs(board, i, j-1, p, res);&#10;    if(i &lt; board.size()-1) dfs(board, i+1, j, p, res);&#10;    if(j &lt; board[0].size()-1) dfs(board, i, j+1, p, res);&#10;    board[i][j] = c;&#10;}&#10;vector&lt;string&gt; findWords(vector&lt;vector&lt;char&gt;&gt;&amp; board, vector&lt;string&gt;&amp; words) {&#10;    Trie t;&#10;    for(string w : words) t.insert(w);&#10;    vector&lt;string&gt; res;&#10;    for(int i=0; i&lt;board.size(); i++) {&#10;        for(int j=0; j&lt;board[0].size(); j++) {&#10;            dfs(board, i, j, t.root, res);&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Trie 08 Palindrome Pairs<br><br></b> <a href="https://leetcode.com/problems/palindrome-pairs/" target="_blank">LeetCode 336</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie of reversed words.</td>
      <td><b>Time:</b> O(N * L^2)<br><b>Space:</b> O(N * L)</td>
      <td>Insert the REVERSE of every word into a Trie. Store index of word at node. For each word, search the Trie. Three cases: 1. Trie word is longer (current word exhausted, check if rest of Trie branch is palindrome). 2. Current word is longer (Trie exhausted, check if rest of current word is palindrome). 3. Exact match. Store valid indices.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[26];&#10;    int index = -1;&#10;    vector&lt;int&gt; pal_indices;&#10;};&#10;class Trie {&#10;public:&#10;    Node* root = new Node();&#10;    bool isPal(string&amp; s, int i, int j) {&#10;        while(i &lt; j) if(s[i++] != s[j--]) return false;&#10;        return true;&#10;    }&#10;    void insert(string&amp; w, int id) {&#10;        Node* node = root;&#10;        for(int i = w.size()-1; i &gt;= 0; i--) {&#10;            if(isPal(w, 0, i)) node-&gt;pal_indices.push_back(id);&#10;            if(!node-&gt;links[w[i]-&#x27;a&#x27;]) node-&gt;links[w[i]-&#x27;a&#x27;] = new Node();&#10;            node = node-&gt;links[w[i]-&#x27;a&#x27;];&#10;        }&#10;        node-&gt;index = id;&#10;        node-&gt;pal_indices.push_back(id);&#10;    }&#10;};&#10;vector&lt;vector&lt;int&gt;&gt; palindromePairs(vector&lt;string&gt;&amp; words) {&#10;    Trie t;&#10;    for(int i=0; i&lt;words.size(); i++) t.insert(words[i], i);&#10;    vector&lt;vector&lt;int&gt;&gt; res;&#10;    for(int i=0; i&lt;words.size(); i++) {&#10;        Node* node = t.root;&#10;        string w = words[i];&#10;        for(int j=0; j&lt;w.size(); j++) {&#10;            if(node-&gt;index != -1 &amp;&amp; node-&gt;index != i &amp;&amp; t.isPal(w, j, w.size()-1)) {&#10;                res.push_back({i, node-&gt;index});&#10;            }&#10;            if(!node-&gt;links[w[j]-&#x27;a&#x27;]) { node = NULL; break; }&#10;            node = node-&gt;links[w[j]-&#x27;a&#x27;];&#10;        }&#10;        if(node) {&#10;            for(int id : node-&gt;pal_indices) {&#10;                if(i != id) res.push_back({i, id});&#10;            }&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">9</td>
      <td rowspan="1">Trie 09 Print Anagrams Together<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-anagrams-together/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie with sorted string.</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td>Sort each string to form a key. Insert the sorted key into the Trie. At the end node of the key in the Trie, store a list of indices representing the original strings that map to this key.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    vector&lt;int&gt; indices;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class Solution{&#10;    TrieNode* root;&#10;    void insert(string word, int index) {&#10;        TrieNode* node = root;&#10;        for(char c : word) {&#10;            if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;            node = node-&gt;children[c - &#x27;a&#x27;];&#10;        }&#10;        node-&gt;indices.push_back(index);&#10;    }&#10;    void traverse(TrieNode* node, vector&lt;vector&lt;string&gt;&gt;&amp; ans, vector&lt;string&gt;&amp; string_list) {&#10;        if(node-&gt;indices.size() &gt; 0) {&#10;            vector&lt;string&gt; group;&#10;            for(int i : node-&gt;indices) group.push_back(string_list[i]);&#10;            ans.push_back(group);&#10;        }&#10;        for(int i = 0; i &lt; 26; i++) {&#10;            if(node-&gt;children[i]) traverse(node-&gt;children[i], ans, string_list);&#10;        }&#10;    }&#10;  public:&#10;    vector&lt;vector&lt;string&gt;&gt; Anagrams(vector&lt;string&gt;&amp; string_list) {&#10;        root = new TrieNode();&#10;        for(int i = 0; i &lt; string_list.size(); i++) {&#10;            string s = string_list[i];&#10;            sort(s.begin(), s.end());&#10;            insert(s, i);&#10;        }&#10;        vector&lt;vector&lt;string&gt;&gt; ans;&#10;        traverse(root, ans, string_list);&#10;        return ans;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">10</td>
      <td rowspan="1">Trie 10 Maximum Xor Subarray<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-xor-subarray/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie + Prefix XOR.</td>
      <td><b>Time:</b> O(N * 32)<br><b>Space:</b> O(N * 32)</td>
      <td>Compute prefix XORs. For each prefix XOR `curr_xor`, insert it into a Trie. Then, query the Trie to find the maximum XOR of `curr_xor` with any previously inserted prefix XOR (by trying to follow the opposite bit path). The maximum value over all queries is the answer.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Node {&#10;    Node* links[2];&#10;    bool containsKey(int bit) { return links[bit] != NULL; }&#10;    void put(int bit, Node* node) { links[bit] = node; }&#10;    Node* get(int bit) { return links[bit]; }&#10;};&#10;class Trie {&#10;    Node* root;&#10;public:&#10;    Trie() { root = new Node(); }&#10;    void insert(int num) {&#10;        Node* node = root;&#10;        for(int i = 31; i &gt;= 0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(!node-&gt;containsKey(bit)) node-&gt;put(bit, new Node());&#10;            node = node-&gt;get(bit);&#10;        }&#10;    }&#10;    int getMax(int num) {&#10;        Node* node = root;&#10;        int maxNum = 0;&#10;        for(int i = 31; i &gt;= 0; i--) {&#10;            int bit = (num &gt;&gt; i) &amp; 1;&#10;            if(node-&gt;containsKey(1 - bit)) {&#10;                maxNum = maxNum | (1 &lt;&lt; i);&#10;                node = node-&gt;get(1 - bit);&#10;            } else {&#10;                node = node-&gt;get(bit);&#10;            }&#10;        }&#10;        return maxNum;&#10;    }&#10;};&#10;int maxSubarrayXOR(int N, int arr[]) {&#10;    Trie trie;&#10;    trie.insert(0);&#10;    int max_xor = INT_MIN, curr_xor = 0;&#10;    for(int i = 0; i &lt; N; i++) {&#10;        curr_xor ^= arr[i];&#10;        trie.insert(curr_xor);&#10;        max_xor = max(max_xor, trie.getMax(curr_xor));&#10;    }&#10;    return max_xor;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Trie 11 Design Add And Search Words Data Structure<br><br></b> <a href="https://leetcode.com/problems/design-add-and-search-words-data-structure/" target="_blank">LeetCode 211</a></td>
      <td rowspan="1"><b>Example 1:</b> Backtracking with Trie.</td>
      <td><b>Time:</b> O(Word Length) for Add, O(26^Dots * Word Length) for Search<br><b>Space:</b> O(Total Chars)</td>
      <td>Add words normally to the Trie. When searching, if the current character is '.', iterate over all 26 possible children and recursively search the remaining word. If any path returns true, the word is found.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    bool isEnd = false;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class WordDictionary {&#10;    TrieNode* root;&#10;    bool searchInNode(string&amp; word, int i, TrieNode* node) {&#10;        if(node == NULL) return false;&#10;        if(i == word.length()) return node-&gt;isEnd;&#10;        if(word[i] != &#x27;.&#x27;) {&#10;            return searchInNode(word, i + 1, node-&gt;children[word[i] - &#x27;a&#x27;]);&#10;        }&#10;        for(int j = 0; j &lt; 26; j++) {&#10;            if(searchInNode(word, i + 1, node-&gt;children[j])) return true;&#10;        }&#10;        return false;&#10;    }&#10;public:&#10;    WordDictionary() { root = new TrieNode(); }&#10;    void addWord(string word) {&#10;        TrieNode* node = root;&#10;        for(char c : word) {&#10;            if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;            node = node-&gt;children[c - &#x27;a&#x27;];&#10;        }&#10;        node-&gt;isEnd = true;&#10;    }&#10;    bool search(string word) {&#10;        return searchInNode(word, 0, root);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Trie 12 Implement Magic Dictionary<br><br></b> <a href="https://leetcode.com/problems/implement-magic-dictionary/" target="_blank">LeetCode 676</a></td>
      <td rowspan="1"><b>Example 1:</b> Recursive Trie Search.</td>
      <td><b>Time:</b> O(N) Add, O(N * 26) Search<br><b>Space:</b> O(Total Chars)</td>
      <td>Store dictionary in a Trie. For searching, recursively traverse the Trie. Maintain a `modified` boolean flag. If characters mismatch, set `modified` to true and continue. If we reach the end of the word and `modified` is true, return true.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    bool isEnd = false;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class MagicDictionary {&#10;    TrieNode* root;&#10;    bool dfs(string&amp; word, int i, TrieNode* node, bool modified) {&#10;        if(i == word.length()) return modified &amp;&amp; node-&gt;isEnd;&#10;        if(modified) {&#10;            if(node-&gt;children[word[i] - &#x27;a&#x27;]) {&#10;                return dfs(word, i + 1, node-&gt;children[word[i] - &#x27;a&#x27;], true);&#10;            }&#10;            return false;&#10;        }&#10;        for(int j = 0; j &lt; 26; j++) {&#10;            if(node-&gt;children[j]) {&#10;                if(dfs(word, i + 1, node-&gt;children[j], j != (word[i] - &#x27;a&#x27;))) return true;&#10;            }&#10;        }&#10;        return false;&#10;    }&#10;public:&#10;    MagicDictionary() { root = new TrieNode(); }&#10;    void buildDict(vector&lt;string&gt; dictionary) {&#10;        for(string word : dictionary) {&#10;            TrieNode* node = root;&#10;            for(char c : word) {&#10;                if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;                node = node-&gt;children[c - &#x27;a&#x27;];&#10;            }&#10;            node-&gt;isEnd = true;&#10;        }&#10;    }&#10;    bool search(string searchWord) {&#10;        return dfs(searchWord, 0, root, false);&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Trie 13 Find All Words In A Matrix<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-all-words-in-a-matrix/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie + DFS.</td>
      <td><b>Time:</b> O(N * M * 4^L) where L is max word length<br><b>Space:</b> O(Total Chars in Dict)</td>
      <td>Build a Trie from the dictionary. Perform DFS from every cell in the matrix. During DFS, traverse the Trie simultaneously. If `node.word` is found, add it to result and clear `node.word` to prevent duplicates. Mark visited cells to avoid loops.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    string word = &quot;&quot;;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class Solution {&#10;    vector&lt;string&gt; ans;&#10;    void dfs(vector&lt;vector&lt;char&gt;&gt;&amp; board, int i, int j, TrieNode* node) {&#10;        char c = board[i][j];&#10;        if(c == &#x27;#&#x27; || !node-&gt;children[c - &#x27;a&#x27;]) return;&#10;        node = node-&gt;children[c - &#x27;a&#x27;];&#10;        if(node-&gt;word != &quot;&quot;) {&#10;            ans.push_back(node-&gt;word);&#10;            node-&gt;word = &quot;&quot;;&#10;        }&#10;        board[i][j] = &#x27;#&#x27;;&#10;        if(i &gt; 0) dfs(board, i - 1, j, node);&#10;        if(j &gt; 0) dfs(board, i, j - 1, node);&#10;        if(i &lt; board.size() - 1) dfs(board, i + 1, j, node);&#10;        if(j &lt; board[0].size() - 1) dfs(board, i, j + 1, node);&#10;        board[i][j] = c;&#10;    }&#10;public:&#10;    vector&lt;string&gt; findWords(vector&lt;vector&lt;char&gt;&gt;&amp; board, vector&lt;string&gt;&amp; words) {&#10;        TrieNode* root = new TrieNode();&#10;        for(string w : words) {&#10;            TrieNode* node = root;&#10;            for(char c : w) {&#10;                if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;                node = node-&gt;children[c - &#x27;a&#x27;];&#10;            }&#10;            node-&gt;word = w;&#10;        }&#10;        for(int i = 0; i &lt; board.size(); i++) {&#10;            for(int j = 0; j &lt; board[0].size(); j++) {&#10;                dfs(board, i, j, root);&#10;            }&#10;        }&#10;        sort(ans.begin(), ans.end());&#10;        return ans;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Trie 14 Replace Words<br><br></b> <a href="https://leetcode.com/problems/replace-words/" target="_blank">LeetCode 648</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie matching.</td>
      <td><b>Time:</b> O(N * W)<br><b>Space:</b> O(Total Chars in Dict + Sentence Length)</td>
      <td>Insert all dictionary roots into a Trie. For each word in the sentence, search the Trie. If a prefix matches a root (i.e., `isEnd` becomes true), replace the word with the root. If no root matches, keep the original word.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    bool isEnd = false;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class Solution {&#10;    TrieNode* root;&#10;    void insert(string word) {&#10;        TrieNode* node = root;&#10;        for(char c : word) {&#10;            if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;            node = node-&gt;children[c - &#x27;a&#x27;];&#10;        }&#10;        node-&gt;isEnd = true;&#10;    }&#10;    string findRoot(string word) {&#10;        TrieNode* node = root;&#10;        string prefix = &quot;&quot;;&#10;        for(char c : word) {&#10;            if(!node-&gt;children[c - &#x27;a&#x27;]) break;&#10;            prefix += c;&#10;            node = node-&gt;children[c - &#x27;a&#x27;];&#10;            if(node-&gt;isEnd) return prefix;&#10;        }&#10;        return word;&#10;    }&#10;public:&#10;    string replaceWords(vector&lt;string&gt;&amp; dictionary, string sentence) {&#10;        root = new TrieNode();&#10;        for(string w : dictionary) insert(w);&#10;        string ans = &quot;&quot;, word = &quot;&quot;;&#10;        for(char c : sentence) {&#10;            if(c == &#x27; &#x27;) {&#10;                ans += findRoot(word) + &quot; &quot;;&#10;                word = &quot;&quot;;&#10;            } else {&#10;                word += c;&#10;            }&#10;        }&#10;        ans += findRoot(word);&#10;        return ans;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Trie 15 Longest Word In Dictionary<br><br></b> <a href="https://leetcode.com/problems/longest-word-in-dictionary/" target="_blank">LeetCode 720</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie + DFS.</td>
      <td><b>Time:</b> O(Total Chars)<br><b>Space:</b> O(Total Chars)</td>
      <td>Insert all words into a Trie, marking the end of each word. Perform DFS on the Trie. Only proceed to children that are marked as the end of a word (i.e., `isEnd == true`). Keep track of the longest string found during DFS.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[26];&#10;    string word = &quot;&quot;;&#10;    bool isEnd = false;&#10;    TrieNode() { for(int i=0; i&lt;26; i++) children[i] = NULL; }&#10;};&#10;class Solution {&#10;    TrieNode* root;&#10;    string longest = &quot;&quot;;&#10;    void dfs(TrieNode* node) {&#10;        if(node-&gt;isEnd) {&#10;            if(node-&gt;word.length() &gt; longest.length() || (node-&gt;word.length() == longest.length() &amp;&amp; node-&gt;word &lt; longest)) {&#10;                longest = node-&gt;word;&#10;            }&#10;        }&#10;        for(int i = 0; i &lt; 26; i++) {&#10;            if(node-&gt;children[i] &amp;&amp; node-&gt;children[i]-&gt;isEnd) {&#10;                dfs(node-&gt;children[i]);&#10;            }&#10;        }&#10;    }&#10;public:&#10;    string longestWord(vector&lt;string&gt;&amp; words) {&#10;        root = new TrieNode();&#10;        for(string w : words) {&#10;            TrieNode* node = root;&#10;            for(char c : w) {&#10;                if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;                node = node-&gt;children[c - &#x27;a&#x27;];&#10;            }&#10;            node-&gt;isEnd = true;&#10;            node-&gt;word = w;&#10;        }&#10;        for(int i = 0; i &lt; 26; i++) {&#10;            if(root-&gt;children[i] &amp;&amp; root-&gt;children[i]-&gt;isEnd) {&#10;                dfs(root-&gt;children[i]);&#10;            }&#10;        }&#10;        return longest;&#10;    }&#10;};</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Trie 16 Camelcase Matching<br><br></b> <a href="https://leetcode.com/problems/camelcase-matching/" target="_blank">LeetCode 1023</a></td>
      <td rowspan="1"><b>Example 1:</b> Trie matching.</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(1) excluding output</td>
      <td>Build a Trie with the queries (optional, can also be done linearly). Better approach: for each query, match characters with pattern. If characters match, increment pattern index. If characters mismatch and query character is uppercase, it's a mismatch. Finally, check if pattern index reached pattern length.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;bool&gt; camelMatch(vector&lt;string&gt;&amp; queries, string pattern) {&#10;    vector&lt;bool&gt; ans;&#10;    for(string q : queries) {&#10;        int i = 0;&#10;        bool match = true;&#10;        for(char c : q) {&#10;            if(i &lt; pattern.length() &amp;&amp; c == pattern[i]) i++;&#10;            else if(isupper(c)) {&#10;                match = false;&#10;                break;&#10;            }&#10;        }&#10;        if(i &lt; pattern.length()) match = false;&#10;        ans.push_back(match);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Trie 17 Prefix And Suffix Search<br><br></b> <a href="https://leetcode.com/problems/prefix-and-suffix-search/" target="_blank">LeetCode 745</a></td>
      <td rowspan="1"><b>Example 1:</b> Suffix + '{' + Prefix Trie.</td>
      <td><b>Time:</b> O(N * K^2) Insert, O(K) Search<br><b>Space:</b> O(N * K^2)</td>
      <td>For each word, generate all possible suffixes, append a special character '{', and then append the original word. Insert all these combinations into a Trie along with the index. When querying, search for `suffix + '{' + prefix` in the Trie.<br><br><b>Dependencies:</b> Trie</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct TrieNode {&#10;    TrieNode* children[27];&#10;    int index = -1;&#10;    TrieNode() { for(int i=0; i&lt;27; i++) children[i] = NULL; }&#10;};&#10;class WordFilter {&#10;    TrieNode* root;&#10;public:&#10;    WordFilter(vector&lt;string&gt;&amp; words) {&#10;        root = new TrieNode();&#10;        for(int i = 0; i &lt; words.size(); i++) {&#10;            string w = words[i];&#10;            for(int j = 0; j &lt;= w.length(); j++) {&#10;                string s = w.substr(j) + &quot;{&quot; + w;&#10;                TrieNode* node = root;&#10;                for(char c : s) {&#10;                    if(!node-&gt;children[c - &#x27;a&#x27;]) node-&gt;children[c - &#x27;a&#x27;] = new TrieNode();&#10;                    node = node-&gt;children[c - &#x27;a&#x27;];&#10;                    node-&gt;index = i;&#10;                }&#10;            }&#10;        }&#10;    }&#10;    int f(string pref, string suff) {&#10;        string s = suff + &quot;{&quot; + pref;&#10;        TrieNode* node = root;&#10;        for(char c : s) {&#10;            if(!node-&gt;children[c - &#x27;a&#x27;]) return -1;&#10;            node = node-&gt;children[c - &#x27;a&#x27;];&#10;        }&#10;        return node-&gt;index;&#10;    }&#10;};</code></pre></details></td>
    </tr>
  </tbody>
</table>


## Patterns

<p><b>Note:</b> All patterns share a common complexity of <b>Time: O(N<sup>2</sup>)</b> and <b>Space: O(1)</b>. The approach involves standard nested loops for row and column printing.</p>
<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 25%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 40%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Pat 01 Rectangular Star</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;***&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*****&#10;*****&#10;*****&#10;*****&#10;*****</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Pat 02 Right Angled Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*&#10;**&#10;***&#10;****&#10;*****</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Pat 03 Right Angled Number Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;1 2&#10;1 2 3&#10;1 2 3 4&#10;1 2 3 4 5</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Pat 04 Right Angled Number Pyramid II</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1&#10;2 2&#10;3 3 3&#10;4 4 4 4&#10;5 5 5 5 5</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Pat 05 Inverted Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;* * *&#10;* *&#10;*&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;* * * * *&#10;* * * *&#10;* * *&#10;* *&#10;*</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 0; j &lt; n - i + 1; j++) {&#10;            cout &lt;&lt; &quot;* &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Pat 06 Inverted Numbered Right Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1 2 3&#10;1 2&#10;1&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;1 2 3 4 5&#10;1 2 3 4&#10;1 2 3&#10;1 2&#10;1</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= n - i + 1; j++) {&#10;            cout &lt;&lt; j &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Pat 07 Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;    *&#10;   ***&#10;  *****&#10; *******&#10;*********</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Pat 08 Inverted Star Pyramid</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*****&#10; ***&#10;  *&#10;&#10;Example 2:&#10;Input: N = 5&#10;Output:&#10;*********&#10; *******&#10;  *****&#10;   ***&#10;    *</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Pat 09 Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  *&#10; ***&#10;*****&#10;*****&#10; ***&#10;  *&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * i + 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 0; j &lt; 2 * (n - i) - 1; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; i; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Pat 10 Half Diamond Star Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*&#10;**&#10;***&#10;**&#10;*&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 1; i &lt;= 2*n-1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2*n - i;&#10;        for(int j = 1; j &lt;= stars; j++) {&#10;            cout &lt;&lt; &quot;*&quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Pat 11 Binary Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;0 1&#10;1 0 1&#10;</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int start = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i % 2 == 0) start = 1;&#10;        else start = 0;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; start &lt;&lt; &quot; &quot;;&#10;            start = 1 - start;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Pat 12 Number Crown Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1    1&#10;12  21&#10;123321</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int space = 2 * (n - 1);&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; j;&#10;        for(int j = 1; j &lt;= space; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = i; j &gt;= 1; j--) cout &lt;&lt; j;&#10;        cout &lt;&lt; endl;&#10;        space -= 2;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Pat 13 Increasing Number Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;1&#10;2 3&#10;4 5 6</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int num = 1;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) {&#10;            cout &lt;&lt; num &lt;&lt; &quot; &quot;;&#10;            num++;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Pat 14 Increasing Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;A B&#10;A B C</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt;= &#x27;A&#x27; + i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Pat 15 Reverse Letter Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A B C&#10;A B&#10;A</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27;; ch &lt; &#x27;A&#x27; + n - i; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Pat 16 Alpha Ramp Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;A&#10;B B&#10;C C C</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        char ch = &#x27;A&#x27; + i;&#10;        for(int j = 0; j &lt;= i; j++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Pat 17 Alpha Hill Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;  A&#10; ABA&#10;ABCBA</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        char ch = &#x27;A&#x27;;&#10;        int breakpoint = (2 * i + 1) / 2;&#10;        for(int j = 1; j &lt;= 2 * i + 1; j++) {&#10;            cout &lt;&lt; ch;&#10;            if(j &lt;= breakpoint) ch++;&#10;            else ch--;&#10;        }&#10;        for(int j = 0; j &lt; n - i - 1; j++) cout &lt;&lt; &quot; &quot;;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Pat 18 Alpha Triangle</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;C&#10;C B&#10;C B A</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(char ch = &#x27;A&#x27; + n - 1 - i; ch &lt;= &#x27;A&#x27; + n - 1; ch++) {&#10;            cout &lt;&lt; ch &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Pat 19 Symmetric Void Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;******&#10;**  **&#10;*    *&#10;*    *&#10;**  **&#10;******</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int iniSpace = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= n - i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace += 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;    iniSpace = 2 * n - 2;&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 0; j &lt; iniSpace; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= i; j++) cout &lt;&lt; &quot;*&quot;;&#10;        iniSpace -= 2;&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Pat 20 Symmetric Butterfly Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;*    *&#10;**  **&#10;******&#10;**  **&#10;*    *</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    int spaces = 2 * n - 2;&#10;    for(int i = 1; i &lt;= 2 * n - 1; i++) {&#10;        int stars = i;&#10;        if(i &gt; n) stars = 2 * n - i;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        for(int j = 1; j &lt;= spaces; j++) cout &lt;&lt; &quot; &quot;;&#10;        for(int j = 1; j &lt;= stars; j++) cout &lt;&lt; &quot;*&quot;;&#10;        cout &lt;&lt; endl;&#10;        if(i &lt; n) spaces -= 2;&#10;        else spaces += 2;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Pat 21 Hollow Rectangle Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;***&#10;* *&#10;***</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; n; i++) {&#10;        for(int j = 0; j &lt; n; j++) {&#10;            if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {&#10;                cout &lt;&lt; &quot;*&quot;;&#10;            } else {&#10;                cout &lt;&lt; &quot; &quot;;&#10;            }&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>22</td>
      <td>Pat 22 The Number Pattern</td>
      <td><pre style="white-space: pre-wrap; word-wrap: break-word;"><code>Example 1:&#10;Input: N = 3&#10;Output:&#10;3 3 3 3 3&#10;3 2 2 2 3&#10;3 2 1 2 3&#10;3 2 2 2 3&#10;3 3 3 3 3</code></pre><br><br><b>Note (Constraint):</b> 1 &le; N &le; 20</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printPattern(int n) {&#10;    for(int i = 0; i &lt; 2 * n - 1; i++) {&#10;        for(int j = 0; j &lt; 2 * n - 1; j++) {&#10;            int top = i;&#10;            int left = j;&#10;            int right = (2 * n - 2) - j;&#10;            int down = (2 * n - 2) - i;&#10;            cout &lt;&lt; (n - min({top, left, right, down})) &lt;&lt; &quot; &quot;;&#10;        }&#10;        cout &lt;&lt; endl;&#10;    }&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>


