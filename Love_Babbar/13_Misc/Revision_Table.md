# 13 Misc Revision Table

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
      <td><b>Edge Cases:</b> <b>Overflow:</b> Checked using 64-bit bounds or 32-bit variants.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    long long ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        &#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    /* &#10;     * VARIANT: STRICT 32-BIT OVERFLOW CHECK&#10;     * If 64-bit integers (long long) are strictly forbidden, you must check BEFORE multiplying by 10 inside the loop:&#10;     * if(ans &gt; INT_MAX/10 || ans &lt; INT_MIN/10) return 0;&#10;     * Note: We don&#x27;t need to check the last digit (e.g. ans == INT_MAX/10 &amp;&amp; digit &gt; 7) because the input &#x27;x&#x27; &#10;     * is a valid 32-bit integer, and no valid 32-bit integer reversed will overflow purely on the final digit.&#10;     */&#10;    if(ans &gt; INT_MAX || ans &lt; INT_MIN) return 0;&#10;    return ans;&#10;}</code></pre></details></td>
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
      <td rowspan="2">9</td>
      <td rowspan="2">Math 09 Power Of Three<br><br></b> <a href="https://leetcode.com/problems/power-of-three/" target="_blank">LeetCode 326</a></td>
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
      <td rowspan="1">10</td>
      <td rowspan="1">Math 10 Power Of Four<br><br></b> <a href="https://leetcode.com/problems/power-of-four/" target="_blank">LeetCode 342</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 16<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>A power of 4 is also a power of 2, so `n > 0 && (n & (n-1)) == 0` must hold. Also, the single set bit must be at an even position (0-indexed). The mask `0x55555555` has 1s at all even positions. So `(n & 0x55555555) != 0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfFour(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0 &amp;&amp; (n &amp; 0x55555555) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">11</td>
      <td rowspan="1">Math 11 Add Digits<br><br></b> <a href="https://leetcode.com/problems/add-digits/" target="_blank">LeetCode 258</a><br><br><details><summary>ℹ️ Concept / Details</summary><b>Digital Root:</b> The digital root of a non-negative integer is the single-digit value obtained by an iterative process of summing digits. Formula: `1 + (n - 1) % 9`.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> num = 38<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>This is known as the digital root. The formula is `1 + (n - 1) % 9`. If `n == 0`, return `0`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int addDigits(int num) {&#10;    if(num == 0) return 0;&#10;    return 1 + (num - 1) % 9;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Math 12 Ugly Number<br><br></b> <a href="https://leetcode.com/problems/ugly-number/" target="_blank">LeetCode 263</a><br><br><details><summary>ℹ️ Concept / Details</summary>An ugly number is a number whose only prime factors are 2, 3, and 5.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 6<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>If `n <= 0`, return false. Divide `n` by 2, 3, and 5 as long as it is divisible. If the remaining number is 1, it's an ugly number, else false.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isUgly(int n) {&#10;    if(n &lt;= 0) return false;&#10;    vector&lt;int&gt; primes = {2, 3, 5};&#10;    for(int p : primes) {&#10;        while(n % p == 0) n /= p;&#10;    }&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Math 13 Perfect Number<br><br></b> <a href="https://leetcode.com/problems/perfect-number/" target="_blank">LeetCode 507</a><br><br><details><summary>ℹ️ Concept / Details</summary>A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For example, 28 = 1 + 2 + 4 + 7 + 14.</details></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> num = 28<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td>If `num <= 1`, return false. Iterate up to `sqrt(num)`. If `i` divides `num`, add `i` and `num/i` to the sum. After the loop, compare sum with `num`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPerfectNumber(int num) {&#10;    if(num &lt;= 1) return false;&#10;    int sum = 1;&#10;    for(int i = 2; i * i &lt;= num; i++) {&#10;        if(num % i == 0) {&#10;            sum += i;&#10;            if(i * i != num) sum += num / i;&#10;        }&#10;    }&#10;    return sum == num;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Math 14 Excel Sheet Column Title<br><br></b> <a href="https://leetcode.com/problems/excel-sheet-column-title/" target="_blank">LeetCode 168</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> columnNumber = 28<br><b>Output:</b> "AB"</td>
      <td><b>Time:</b> O(log_26(N))<br><b>Space:</b> O(1)</td>
      <td>This is essentially base 26 conversion, but 1-indexed (A=1, B=2, Z=26). To make it 0-indexed, decrement `columnNumber` by 1 at each step, get the remainder modulo 26, convert to character, and divide by 26.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string convertToTitle(int columnNumber) {&#10;    string res = &quot;&quot;;&#10;    while(columnNumber &gt; 0) {&#10;        columnNumber--;&#10;        res += (char)(&#x27;A&#x27; + (columnNumber % 26));&#10;        columnNumber /= 26;&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Math 15 Sieve Of Eratosthenes<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> N = 10<br><b>Output:</b> 2 3 5 7</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td>Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; sieveOfEratosthenes(int N) {&#10;    vector&lt;int&gt; primes;&#10;    vector&lt;bool&gt; isPrime(N + 1, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt;= N; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    for(int i = 2; i &lt;= N; i++) {&#10;        if(isPrime[i]) primes.push_back(i);&#10;    }&#10;    return primes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">16</td>
      <td rowspan="2">Hash 16 Count Frequencies<br><br></b> <a href="https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1" target="_blank">GeeksforGeeks</a></td>
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
      <td rowspan="1">17</td>
      <td rowspan="1">Hash 17 Highest Lowest Frequency<br><br></b> <a href="https://leetcode.com/problems/sort-array-by-increasing-frequency/" target="_blank">LeetCode 1636</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 10, 15, 10, 5]<br><b>Output:</b> Highest=10, Lowest=15<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Build a frequency map, then iterate through the map to find the max and min frequencies.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Set min_freq to `INT_MAX` properly to allow map values to overwrite it.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void findHighLowFreq(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : arr) freq[num]++;&#10;    &#10;    int max_f = 0, min_f = INT_MAX;&#10;    int max_ele = 0, min_ele = 0;&#10;    &#10;    for(auto it : freq) {&#10;        if(it.second &gt; max_f) { max_f = it.second; max_ele = it.first; }&#10;        if(it.second &lt; min_f) { min_f = it.second; min_ele = it.first; }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">18</td>
      <td rowspan="2">Hash 18 Intersection Of Two Arrays<br><br></b> <a href="https://leetcode.com/problems/intersection-of-two-arrays/" target="_blank">LeetCode 349</a></td>
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
      <td rowspan="1">19</td>
      <td rowspan="1">Hash 19 Union Of Two Arrays<br><br></b> <a href="https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> a = [1, 2, 3], b = [2, 3, 4]<br><b>Output:</b> [1, 2, 3, 4]<br><br><b> </b> Arrays may not be sorted.</td>
      <td><b>Time:</b> O(N + M) (Constraint)<br><b>Space:</b> O(N + M) (Trade-off)</td>
      <td>Optimal: Insert all elements from both arrays into a Hash Set. The Set natively drops duplicates.<br><br><b>Dependencies:</b> <code>std::unordered_set</code> / <code>set()</code></td>
      <td><b>Edge Cases:</b> <b>Unordered Limitation:</b> If the problem expects sorted union, `std::set` must be used increasing time to `O((N+M)log(N+M))`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; findUnion(std::vector&lt;int&gt;&amp; a, std::vector&lt;int&gt;&amp; b) {&#10;    std::unordered_set&lt;int&gt; s;&#10;    for(int num : a) s.insert(num);&#10;    for(int num : b) s.insert(num);&#10;    &#10;    std::vector&lt;int&gt; res(s.begin(), s.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Hash 20 Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [4, 2, -3, 1, 6]<br><b>Output:</b> true (2, -3, 1)<br><br><b> </b> Array contains positive and negative integers.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Use a Prefix Sum and a Hash Set. If a prefix sum repeats, or equals 0, a 0-sum subarray exists between the identical prefix sums.<br><br><b>Dependencies:</b> <code>std::unordered_set</code></td>
      <td><b>Edge Cases:</b> <b>Zero Prefix Edge Case:</b> If `sum == 0` during traversal, the subarray naturally started from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool hasZeroSumSubarray(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_set&lt;int&gt; prefix_sums;&#10;    int sum = 0;&#10;    for(int num : arr) {&#10;        sum += num;&#10;        if(sum == 0 || prefix_sums.find(sum) != prefix_sums.end()) {&#10;            return true;&#10;        }&#10;        prefix_sums.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">21</td>
      <td rowspan="2">Hash 21 Subarray Sum Equals K<br><br></b> <a href="https://leetcode.com/problems/subarray-sum-equals-k/" target="_blank">LeetCode 560</a></td>
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
      <td rowspan="1">22</td>
      <td rowspan="1">Hash 22 Longest Subarray With 0 Sum<br><br></b> <a href="https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [15,-2,2,-8,1,7,10,23]<br><b>Output:</b> 5<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Store `prefix_sum` -> `index` in Hash Map. If sum repeats, calculate distance `i - hash[sum]`.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Longest Policy:</b> We only insert `sum` into the map if it doesn't exist to preserve the earliest index and maximize distance.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(std::vector&lt;int&gt;&amp; arr) {&#10;    std::unordered_map&lt;int, int&gt; prefix_index;&#10;    int max_len = 0, sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == 0) {&#10;            max_len = i + 1;&#10;        } else if(prefix_index.find(sum) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[sum]);&#10;        } else {&#10;            prefix_index[sum] = i; // Store only first occurrence&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Hash 23 Longest Subarray With Sum K<br><br></b> <a href="https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> arr = [10, 5, 2, 7, 1, 9], k = 15<br><b>Output:</b> 4<br><br><b> </b> 1 &le; N &le; 10<sup>5</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Optimal: Prefix Sum Map storing indices. Check if `sum - K` exists in map and calculate index difference.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Zero Elements Rule:</b> Never overwrite existing prefix sums in the map, otherwise arrays with zero elements will shorten the max length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(std::vector&lt;int&gt;&amp; arr, int k) {&#10;    std::unordered_map&lt;long long, int&gt; prefix_index;&#10;    int max_len = 0;&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; arr.size(); i++) {&#10;        sum += arr[i];&#10;        if(sum == k) {&#10;            max_len = i + 1;&#10;        }&#10;        long long needed = sum - k;&#10;        if(prefix_index.find(needed) != prefix_index.end()) {&#10;            max_len = std::max(max_len, i - prefix_index[needed]);&#10;        }&#10;        if(prefix_index.find(sum) == prefix_index.end()) {&#10;            prefix_index[sum] = i;&#10;        }&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Hash 24 Two Sum<br><br></b> <a href="https://leetcode.com/problems/two-sum/" target="_blank">LeetCode 1</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [2,7,11,15], target = 9<br><b>Output:</b> [0,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Iterate while storing numbers and their indices in a hash map. Check if `target - num` already exists.<br><br><b>Dependencies:</b> <code>std::unordered_map</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate Elements:</b> Storing elements as we iterate safely handles duplicates (e.g., target 6, array [3,3]).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; twoSum(std::vector&lt;int&gt;&amp; nums, int target) {&#10;    std::unordered_map&lt;int, int&gt; mpp;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        int needed = target - nums[i];&#10;        if(mpp.find(needed) != mpp.end()) {&#10;            return {mpp[needed], i};&#10;        }&#10;        mpp[nums[i]] = i;&#10;    }&#10;    return {};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Hash 25 Group Anagrams<br><br></b> <a href="https://leetcode.com/problems/group-anagrams/" target="_blank">LeetCode 49</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> strs = ["eat","tea","tan","ate","nat","bat"]<br><b>Output:</b> [["bat"],["nat","tan"],["ate","eat","tea"]]</td>
      <td><b>Time:</b> O(N * K log K)<br><b>Space:</b> O(N * K)</td>
      <td>Optimal: Use a hash map where the key is the sorted version of the string, and the value is a list of anagrams.<br><br><b>Dependencies:</b> <code>std::unordered_map</code>, <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Empty Strings:</b> Safely handled since an empty string sorted is still empty, forming a valid key.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;std::string&gt;&gt; groupAnagrams(std::vector&lt;std::string&gt;&amp; strs) {&#10;    std::unordered_map&lt;std::string, std::vector&lt;std::string&gt;&gt; mpp;&#10;    for(std::string s : strs) {&#10;        std::string key = s;&#10;        std::sort(key.begin(), key.end());&#10;        mpp[key].push_back(s);&#10;    }&#10;    std::vector&lt;std::vector&lt;std::string&gt;&gt; ans;&#10;    for(auto it : mpp) {&#10;        ans.push_back(it.second);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">26</td>
      <td rowspan="2">Hash 26 Longest Consecutive Sequence<br><br></b> <a href="https://leetcode.com/problems/longest-consecutive-sequence/" target="_blank">LeetCode 128</a></td>
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
      <td rowspan="1">27</td>
      <td rowspan="1">Hash 27 Longest Subarray With 0 Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Maintain the prefix sum and a hash map storing the first occurrence index of each prefix sum. If sum is 0, length is `i+1`. If sum is in the map, length is `i - map[sum]`. Update max length.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxLen(vector&lt;int&gt;&amp; A, int n) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    int maxi = 0, sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += A[i];&#10;        if(sum == 0) maxi = i + 1;&#10;        else {&#10;            if(m.find(sum) != m.end()) {&#10;                maxi = max(maxi, i - m[sum]);&#10;            } else {&#10;                m[sum] = i;&#10;            }&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Hash 28 Count Distinct Elements In Every Window<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Optimal: Use a hash map to keep track of element frequencies in the window of size K. The number of distinct elements is the size of the hash map. As window slides, increment frequency of new element, decrement frequency of outgoing element. If frequency becomes 0, remove it from map.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; countDistinct(int A[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 0; i &lt; k; i++) m[A[i]]++;&#10;    ans.push_back(m.size());&#10;    for(int i = k; i &lt; n; i++) {&#10;        m[A[i - k]]--;&#10;        if(m[A[i - k]] == 0) m.erase(A[i - k]);&#10;        m[A[i]]++;&#10;        ans.push_back(m.size());&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Sw 29 Longest Substring Without Repeating Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/" target="_blank">LeetCode 3</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "abcabcbb"<br><b>Output:</b> 3 ("abc")</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(min(N, M))</td>
      <td>Sliding window with a Hash Map storing the latest index of each character. Move `left` pointer to `max(left, map[char] + 1)`.<br><br><b>Dependencies:</b> <code>std::vector</code> for frequency array</td>
      <td><b>Edge Cases:</b> <b>Pointer Leap:</b> `left` can only jump forward, thus `std::max(left, ...)` prevents `left` from going backward if an old duplicate is found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstring(std::string s) {&#10;    std::vector&lt;int&gt; mpp(256, -1);&#10;    int left = 0, right = 0, max_len = 0;&#10;    while(right &lt; s.length()) {&#10;        if(mpp[s[right]] != -1) {&#10;            left = std::max(left, mpp[s[right]] + 1);&#10;        }&#10;        mpp[s[right]] = right;&#10;        max_len = std::max(max_len, right - left + 1);&#10;        right++;&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Sw 30 Trapping Rain Water<br><br></b> <a href="https://leetcode.com/problems/trapping-rain-water/" target="_blank">LeetCode 42</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> height = [0,1,0,2,1,0,1,3,2,1,2,1]<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Two pointers `left` and `right`. Maintain `left_max` and `right_max`. Move the pointer pointing to the smaller max, adding trapped water.</td>
      <td><b>Edge Cases:</b> <b>Local Maxima:</b> Water trapped at `i` relies on the absolute minimum of the highest bars to its left and right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trap(std::vector&lt;int&gt;&amp; height) {&#10;    int n = height.size();&#10;    int left = 0, right = n - 1;&#10;    int res = 0, maxLeft = 0, maxRight = 0;&#10;    while (left &lt;= right) {&#10;        if (height[left] &lt;= height[right]) {&#10;            if (height[left] &gt;= maxLeft) maxLeft = height[left];&#10;            else res += maxLeft - height[left];&#10;            left++;&#10;        } else {&#10;            if (height[right] &gt;= maxRight) maxRight = height[right];&#10;            else res += maxRight - height[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Sw 31 Count Occurrences Of Anagrams<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Fixed window and frequency map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(26) = O(1)</td>
      <td>Maintain a frequency map of the pattern. Use a sliding window of size equal to the length of the pattern. Keep track of the number of characters fully matched (`count`). If `count` equals the number of unique characters in the pattern, an anagram is found.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(string pat, string txt) {&#10;    int k = pat.length(), n = txt.length();&#10;    if(k &gt; n) return 0;&#10;    vector&lt;int&gt; count(26, 0);&#10;    for(char c : pat) count[c - &#x27;a&#x27;]++;&#10;    int i = 0, j = 0, ans = 0;&#10;    int distinct = 0;&#10;    for(int x : count) if(x &gt; 0) distinct++;&#10;    while(j &lt; n) {&#10;        count[txt[j] - &#x27;a&#x27;]--;&#10;        if(count[txt[j] - &#x27;a&#x27;] == 0) distinct--;&#10;        if(j - i + 1 &lt; k) j++;&#10;        else if(j - i + 1 == k) {&#10;            if(distinct == 0) ans++;&#10;            count[txt[i] - &#x27;a&#x27;]++;&#10;            if(count[txt[i] - &#x27;a&#x27;] == 1) distinct++;&#10;            i++; j++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Sw 32 Maximum Of All Subarrays Of Size K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Use a deque to store indices of elements. The deque will maintain elements in decreasing order. For each element, remove elements from the back of the deque that are smaller than the current element. Also, remove elements from the front that are out of the current window. The front of the deque will always have the maximum element of the current window.<br><br><b>Dependencies:</b> <code>#include <deque></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector &lt;int&gt; max_of_subarrays(int *arr, int n, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; arr[dq.back()] &lt;= arr[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(arr[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Sw 33 Minimum Window Substring<br><br></b> <a href="https://leetcode.com/problems/minimum-window-substring/" target="_blank">LeetCode 76</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable sliding window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Maintain a frequency map of `t`. Expand the window by moving `right`. When the window contains all characters of `t`, try to shrink it by moving `left` to find the minimum window. Keep track of the minimum window length and its starting index.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string minWindow(string s, string t) {&#10;    if(s.length() &lt; t.length()) return &quot;&quot;;&#10;    vector&lt;int&gt; count(128, 0);&#10;    for(char c : t) count[c]++;&#10;    int l = 0, r = 0, minLen = INT_MAX, minStart = 0, required = t.length();&#10;    while(r &lt; s.length()) {&#10;        if(count[s[r]] &gt; 0) required--;&#10;        count[s[r]]--;&#10;        r++;&#10;        while(required == 0) {&#10;            if(r - l &lt; minLen) {&#10;                minLen = r - l;&#10;                minStart = l;&#10;            }&#10;            count[s[l]]++;&#10;            if(count[s[l]] &gt; 0) required++;&#10;            l++;&#10;        }&#10;    }&#10;    return minLen == INT_MAX ? &quot;&quot; : s.substr(minStart, minLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Sw 34 Longest K Unique Characters Substring<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable window and hash map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Maintain a hash map of character frequencies. Expand the window by moving `j`. If the number of unique characters exceeds `k`, shrink the window from the left (`i`) until the number of unique characters is `k`. Update the maximum length when exactly `k` unique characters are present.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestKSubstr(string s, int k) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    int i = 0, j = 0, maxLen = -1;&#10;    while(j &lt; s.length()) {&#10;        count[s[j]]++;&#10;        if(count.size() == k) maxLen = max(maxLen, j - i + 1);&#10;        else if(count.size() &gt; k) {&#10;            while(count.size() &gt; k) {&#10;                count[s[i]]--;&#10;                if(count[s[i]] == 0) count.erase(s[i]);&#10;                i++;&#10;            }&#10;        }&#10;        j++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Sw 35 Subarrays With K Different Integers<br><br></b> <a href="https://leetcode.com/problems/subarrays-with-k-different-integers/" target="_blank">LeetCode 992</a></td>
      <td rowspan="1"><b>Example 1:</b> Exact K = atMost(K) - atMost(K-1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Finding exact `k` distinct is hard directly. Instead, find subarrays with at most `k` distinct integers. The number of exact `k` is `atMost(k) - atMost(k - 1)`. The `atMost` function uses a sliding window.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int res = 0, i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(count[nums[j]] == 0) k--;&#10;        count[nums[j]]++;&#10;        while(k &lt; 0) {&#10;            count[nums[i]]--;&#10;            if(count[nums[i]] == 0) k++;&#10;            i++;&#10;        }&#10;        res += j - i + 1;&#10;    }&#10;    return res;&#10;}&#10;int subarraysWithKDistinct(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Sw 36 Minimum Size Subarray Sum<br><br></b> <a href="https://leetcode.com/problems/minimum-size-subarray-sum/" target="_blank">LeetCode 209</a></td>
      <td rowspan="1"><b>Example 1:</b> Variable sliding window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Add elements to the current sum. While the sum is >= target, update the minimum length and shrink the window from the left.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minSubArrayLen(int target, vector&lt;int&gt;&amp; nums) {&#10;    int l = 0, sum = 0, minLen = INT_MAX;&#10;    for(int r = 0; r &lt; nums.size(); r++) {&#10;        sum += nums[r];&#10;        while(sum &gt;= target) {&#10;            minLen = min(minLen, r - l + 1);&#10;            sum -= nums[l++];&#10;        }&#10;    }&#10;    return minLen == INT_MAX ? 0 : minLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Sw 37 Fruits Into Baskets<br><br></b> <a href="https://leetcode.com/problems/fruit-into-baskets/" target="_blank">LeetCode 904</a></td>
      <td rowspan="1"><b>Example 1:</b> Longest subarray with at most 2 distinct elements.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (at most 3 elements in map)</td>
      <td>This translates to finding the longest subarray with at most 2 distinct elements. Maintain a frequency map and use a sliding window. If distinct elements > 2, shrink the window until distinct elements <= 2.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int totalFruit(vector&lt;int&gt;&amp; fruits) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int l = 0, maxFruits = 0;&#10;    for(int r = 0; r &lt; fruits.size(); r++) {&#10;        count[fruits[r]]++;&#10;        while(count.size() &gt; 2) {&#10;            count[fruits[l]]--;&#10;            if(count[fruits[l]] == 0) count.erase(fruits[l]);&#10;            l++;&#10;        }&#10;        maxFruits = max(maxFruits, r - l + 1);&#10;    }&#10;    return maxFruits;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Sw 38 Max Consecutive Ones III<br><br></b> <a href="https://leetcode.com/problems/max-consecutive-ones-iii/" target="_blank">LeetCode 1004</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Expand the right pointer. If the element is 0, increment a zero counter. While the zero counter > k, shrink the window from the left by moving the left pointer and decrementing the zero counter if left element is 0. The max window size is the answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestOnes(vector&lt;int&gt;&amp; nums, int k) {&#10;    int left = 0, right = 0, zeroes = 0, maxLen = 0;&#10;    while(right &lt; nums.size()) {&#10;        if(nums[right] == 0) zeroes++;&#10;        while(zeroes &gt; k) {&#10;            if(nums[left] == 0) zeroes--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Sw 39 Longest Repeating Character Replacement<br><br></b> <a href="https://leetcode.com/problems/longest-repeating-character-replacement/" target="_blank">LeetCode 424</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Max Freq.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window. Maintain the character frequencies and the `max_freq` in the window. The number of replacements needed is `window_size - max_freq`. If this is > k, shrink the window from left and decrement the corresponding frequency.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int characterReplacement(string s, int k) {&#10;    vector&lt;int&gt; count(26, 0);&#10;    int left = 0, maxFreq = 0, maxLen = 0;&#10;    for(int right = 0; right &lt; s.length(); right++) {&#10;        count[s[right] - &#x27;A&#x27;]++;&#10;        maxFreq = max(maxFreq, count[s[right] - &#x27;A&#x27;]);&#10;        if((right - left + 1) - maxFreq &gt; k) {&#10;            count[s[left] - &#x27;A&#x27;]--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Sw 40 Binary Subarrays With Sum<br><br></b> <a href="https://leetcode.com/problems/binary-subarrays-with-sum/" target="_blank">LeetCode 930</a></td>
      <td rowspan="1"><b>Example 1:</b> atMost(goal) - atMost(goal - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use the helper function `atMost(goal)` which finds the number of subarrays with sum <= goal. The answer is `atMost(goal) - atMost(goal - 1)`. In `atMost`, use a sliding window to maintain the sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int goal) {&#10;    if(goal &lt; 0) return 0;&#10;    int left = 0, sum = 0, count = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        sum += nums[right];&#10;        while(sum &gt; goal) {&#10;            sum -= nums[left++];&#10;        }&#10;        count += (right - left + 1);&#10;    }&#10;    return count;&#10;}&#10;int numSubarraysWithSum(vector&lt;int&gt;&amp; nums, int goal) {&#10;    return atMost(nums, goal) - atMost(nums, goal - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Sw 41 Count Number Of Nice Subarrays<br><br></b> <a href="https://leetcode.com/problems/count-number-of-nice-subarrays/" target="_blank">LeetCode 1248</a></td>
      <td rowspan="1"><b>Example 1:</b> atMost(k) - atMost(k - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Replace all odd numbers with 1 and even numbers with 0. The problem then reduces to finding the number of subarrays with a sum equal to k. Use the `atMost(k) - atMost(k - 1)` sliding window approach.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    if(k &lt; 0) return 0;&#10;    int left = 0, count = 0, res = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        if(nums[right] % 2 != 0) count++;&#10;        while(count &gt; k) {&#10;            if(nums[left] % 2 != 0) count--;&#10;            left++;&#10;        }&#10;        res += (right - left + 1);&#10;    }&#10;    return res;&#10;}&#10;int numberOfSubarrays(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Sw 42 Number Of Substrings Containing All Three Characters<br><br></b> <a href="https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/" target="_blank">LeetCode 1358</a></td>
      <td rowspan="1"><b>Example 1:</b> Store last seen indices.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Iterate through the string. Track the last seen indices of 'a', 'b', and 'c'. If all three have been seen, the number of valid substrings ending at the current index `i` is `1 + min(last_a, last_b, last_c)`. Add this to the total count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfSubstrings(string s) {&#10;    int last[3] = {-1, -1, -1};&#10;    int count = 0;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        last[s[i] - &#x27;a&#x27;] = i;&#10;        if(last[0] != -1 &amp;&amp; last[1] != -1 &amp;&amp; last[2] != -1) {&#10;            count += (1 + min({last[0], last[1], last[2]}));&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Sw 43 Maximum Points You Can Obtain From Cards<br><br></b> <a href="https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/" target="_blank">LeetCode 1423</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window on remaining cards.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Instead of picking cards from the ends, find the subarray of length `N - K` that has the minimum sum. Subtract this minimum sum from the total sum of the array. That gives the maximum score.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxScore(vector&lt;int&gt;&amp; cardPoints, int k) {&#10;    int n = cardPoints.size();&#10;    int totalSum = 0, windowSum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        totalSum += cardPoints[i];&#10;        if(i &lt; n - k) windowSum += cardPoints[i];&#10;    }&#10;    int minWindowSum = windowSum;&#10;    for(int i = n - k; i &lt; n; i++) {&#10;        windowSum += cardPoints[i] - cardPoints[i - (n - k)];&#10;        minWindowSum = min(minWindowSum, windowSum);&#10;    }&#10;    return totalSum - minWindowSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Sw 44 Find All Anagrams In A String<br><br></b> <a href="https://leetcode.com/problems/find-all-anagrams-in-a-string/" target="_blank">LeetCode 438</a></td>
      <td rowspan="1"><b>Example 1:</b> Fixed Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Create frequency arrays for `p` and a window of size `p.length()` in `s`. Slide the window across `s`, updating the window frequencies. If the arrays match, add the window's start index to the result.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findAnagrams(string s, string p) {&#10;    vector&lt;int&gt; ans;&#10;    if(p.length() &gt; s.length()) return ans;&#10;    vector&lt;int&gt; countP(26, 0), countS(26, 0);&#10;    for(int i = 0; i &lt; p.length(); i++) {&#10;        countP[p[i] - &#x27;a&#x27;]++;&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;    }&#10;    if(countP == countS) ans.push_back(0);&#10;    for(int i = p.length(); i &lt; s.length(); i++) {&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;        countS[s[i - p.length()] - &#x27;a&#x27;]--;&#10;        if(countP == countS) ans.push_back(i - p.length() + 1);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">45</td>
      <td rowspan="1">Sw 45 Permutation In String<br><br></b> <a href="https://leetcode.com/problems/permutation-in-string/" target="_blank">LeetCode 567</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Frequency Array.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window of size `len(s1)` over `s2`. Maintain frequency arrays for `s1` and the current window in `s2`. Compare arrays at each step.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkInclusion(string s1, string s2) {&#10;    if(s1.length() &gt; s2.length()) return false;&#10;    vector&lt;int&gt; count1(26, 0), count2(26, 0);&#10;    for(int i = 0; i &lt; s1.length(); i++) {&#10;        count1[s1[i] - &#x27;a&#x27;]++;&#10;        count2[s2[i] - &#x27;a&#x27;]++;&#10;    }&#10;    if(count1 == count2) return true;&#10;    for(int i = s1.length(); i &lt; s2.length(); i++) {&#10;        count2[s2[i] - &#x27;a&#x27;]++;&#10;        count2[s2[i - s1.length()] - &#x27;a&#x27;]--;&#10;        if(count1 == count2) return true;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">46</td>
      <td rowspan="1">Sw 46 First Negative Integer In Every Window Of Size K<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Queue.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td>Maintain a queue of negative integers in the current window. While moving the window, add new negative integers, remove old ones out of window. The front of queue is the first negative.<br><br><b>Dependencies:</b> Queue</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; printFirstNegativeInteger(long long int A[], long long int N, long long int K) {&#10;    vector&lt;long long&gt; ans;&#10;    queue&lt;long long&gt; q;&#10;    for(long long i = 0; i &lt; K - 1; i++) {&#10;        if(A[i] &lt; 0) q.push(A[i]);&#10;    }&#10;    for(long long i = K - 1; i &lt; N; i++) {&#10;        if(A[i] &lt; 0) q.push(A[i]);&#10;        if(!q.empty()) ans.push_back(q.front());&#10;        else ans.push_back(0);&#10;        if(A[i - K + 1] &lt; 0 &amp;&amp; !q.empty() &amp;&amp; q.front() == A[i - K + 1]) q.pop();&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">47</td>
      <td rowspan="1">Sw 47 Count Occurrences Of Anagrams<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams1536/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window + Frequency Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Use a sliding window of size `pat.length()`. Keep frequency map of `pat`. Track `count` of distinct characters to match. While moving window, decrease `count` if char frequency matches. If `count == 0`, increment answer.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int search(string pat, string txt) {&#10;    unordered_map&lt;char, int&gt; m;&#10;    for(char c : pat) m[c]++;&#10;    int count = m.size(), ans = 0, k = pat.length();&#10;    int i = 0, j = 0;&#10;    while(j &lt; txt.length()) {&#10;        if(m.find(txt[j]) != m.end()) {&#10;            m[txt[j]]--;&#10;            if(m[txt[j]] == 0) count--;&#10;        }&#10;        if(j - i + 1 &lt; k) j++;&#10;        else if(j - i + 1 == k) {&#10;            if(count == 0) ans++;&#10;            if(m.find(txt[i]) != m.end()) {&#10;                m[txt[i]]++;&#10;                if(m[txt[i]] == 1) count++;&#10;            }&#10;            i++; j++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">48</td>
      <td rowspan="1">Sw 48 Smallest Window In A String Containing All The Characters Of Another String<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b>Example 1:</b> Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Same as Minimum Window Substring. Use frequency map of `P` and a sliding window over `S`. Shrink window from left when all characters match to find the minimum length.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string smallestWindow (string s, string p) {&#10;    if(p.length() &gt; s.length()) return &quot;-1&quot;;&#10;    unordered_map&lt;char, int&gt; m;&#10;    for(char c : p) m[c]++;&#10;    int count = m.size(), i = 0, j = 0, minLen = INT_MAX, start = 0;&#10;    while(j &lt; s.length()) {&#10;        if(m.find(s[j]) != m.end()) {&#10;            m[s[j]]--;&#10;            if(m[s[j]] == 0) count--;&#10;        }&#10;        while(count == 0) {&#10;            if(j - i + 1 &lt; minLen) {&#10;                minLen = j - i + 1;&#10;                start = i;&#10;            }&#10;            if(m.find(s[i]) != m.end()) {&#10;                m[s[i]]++;&#10;                if(m[s[i]] &gt; 0) count++;&#10;            }&#10;            i++;&#10;        }&#10;        j++;&#10;    }&#10;    if(minLen == INT_MAX) return &quot;-1&quot;;&#10;    return s.substr(start, minLen);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
