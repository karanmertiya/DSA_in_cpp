# Basic Maths Revision Table

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
