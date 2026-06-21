# Maths Revision Table

<table border="1">
  <thead>
    <tr>
      <th style="width: 5%;">S.No</th>
      <th style="width: 15%;">Problem Name</th>
      <th style="width: 30%;">Example & Constraints</th>
      <th style="width: 15%;">Complexity</th>
      <th style="width: 35%;">Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>Math 01 Count Digits<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-digits5716/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> N = 12345<br><b>Output:</b> 5</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log10 N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 3</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Convert the absolute value of the number to a string and return its length.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    return to_string(abs(n)).length();&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use a while loop to repeatedly divide the number by 10 and increment a counter.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    if (n == 0) return 1;&#10;    int count = 0;&#10;    while(n != 0) {&#10;        count++;&#10;        n /= 10;&#10;    }&#10;    return count;&#10;}</code></pre></details></details><details><summary><b>Approach 3</b></summary><b>Explanation:</b> Use the base-10 logarithm function to find the number of digits mathematically.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigits(int n) {&#10;    if (n == 0) return 1;&#10;    return (int)(log10(abs(n)) + 1);&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Math 02 Reverse Integer<br><br></b> <a href="https://leetcode.com/problems/reverse-integer/" target="_blank">LeetCode 7</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> x = 123<br><b>Output:</b> 321</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log10 x)<br><b>Space:</b> O(log10 x)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Optimal Approach: Use a 64-bit integer to naturally store the reversed number. A variant note explains how to do this strictly with 32-bit integers if long is not allowed.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    long long ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        /* &#10;         * VARIANT: STRICT 32-BIT OVERFLOW CHECK&#10;         * If 64-bit integers are not allowed, you must check before multiplying by 10.&#10;         * if(ans &gt; INT_MAX/10 || ans &lt; INT_MIN/10) return 0;&#10;         * Note: We don&#x27;t need to check if the last digit will cause an overflow &#10;         * (e.g., ans == INT_MAX/10 &amp;&amp; digit &gt; 7) because the input &#x27;x&#x27; is a valid 32-bit integer. &#10;         * No valid 32-bit integer starts with a digit high enough to cause that specific overflow when reversed.&#10;         */&#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    if(ans &gt; INT_MAX || ans &lt; INT_MIN) return 0;&#10;    return ans;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Brute Force / String Approach: Convert to string, reverse, and then parse back to integer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    string s = to_string(abs(x));&#10;    std::reverse(s.begin(), s.end());&#10;    try {&#10;        long long rev = stoll(s);&#10;        if (x &lt; 0) rev = -rev;&#10;        if (rev &gt; INT_MAX || rev &lt; INT_MIN) return 0;&#10;        return rev;&#10;    } catch (...) {&#10;        return 0;&#10;    }&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Math 03 Palindrome Number<br><br></b> <a href="https://leetcode.com/problems/palindrome-number/" target="_blank">LeetCode 9</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> x = 121<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int x) {&#10;    if(x &lt; 0 || (x % 10 == 0 &amp;&amp; x != 0)) return false;&#10;    int reversedHalf = 0;&#10;    while(x &gt; reversedHalf) {&#10;        reversedHalf = reversedHalf * 10 + x % 10;&#10;        x /= 10;&#10;    }&#10;    return x == reversedHalf || x == reversedHalf / 10;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Math 04 Gcd Or Hcf<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> A = 4, B = 8<br><b>Output:</b> 4</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(min(a, b))<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log(min(a, b)))<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Brute Force: Iterate from 1 to min(a, b) and find the highest number that divides both.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; lcmAndGcd(long long a, long long b) {&#10;    long long gcd = 1;&#10;    for(long long i = 1; i &lt;= min(a, b); i++) {&#10;        if(a % i == 0 &amp;&amp; b % i == 0) gcd = i;&#10;    }&#10;    long long lcm = (a / gcd) * b; // Divide first to prevent overflow&#10;    return {lcm, gcd};&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Euclidean Algorithm (Optimal): Repeatedly replace max(a,b) with max(a,b) % min(a,b). The final non-zero value is the GCD. Note: LCM can be found in O(1) extra time using formula: LCM(a,b) = (a*b) / GCD(a,b)<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;long long&gt; lcmAndGcd(long long a, long long b) {&#10;    long long original_a = a, original_b = b;&#10;    while(a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        if(a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    // return (a == 0) ? b : a; can be replaced by a + b since one is always 0&#10;    long long gcd = a + b; &#10;    long long lcm = (original_a / gcd) * original_b; // Divide first to prevent overflow&#10;    return {lcm, gcd};&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Math 05 Check For Prime<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/prime-number2314/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> <br><b>Input:</b> N = 5<br><b>Output:</b> 1</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Brute Force: Iterate from 2 to N-1 and check if N is divisible.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i = 2; i &lt; N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Optimal: Check divisibility up to sqrt(N). Factors appear in pairs.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i=2; i*i&lt;=N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Math 06 Pow X N<br><br></b> <a href="https://leetcode.com/problems/powx-n/" target="_blank">LeetCode 50</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b>Example 1:</b> Binary Exponentiation.</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Brute Force: Loop n times and multiply ans by x.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    for(int i = 0; i &lt; nn; i++) {&#10;        ans *= x;&#10;    }&#10;    return n &lt; 0 ? 1.0 / ans : ans;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Optimal: Binary Exponentiation. If n is even, x = x*x, n = n/2. If odd, ans = ans*x, n = n-1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    while(nn &gt; 0) {&#10;        if(nn % 2 == 1) {&#10;            ans = ans * x;&#10;            nn = nn - 1;&#10;        } else {&#10;            x = x * x;&#10;            nn = nn / 2;&#10;        }&#10;    }&#10;    if(n &lt; 0) ans = (double)(1.0) / (double)(ans);&#10;    return ans;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Math 07 Sieve Of Eratosthenes<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td><b>Example 1:</b> Classic implementation.</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; sieveOfEratosthenes(int N) {&#10;    vector&lt;int&gt; primes;&#10;    vector&lt;bool&gt; isPrime(N + 1, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt;= N; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    for(int i = 2; i &lt;= N; i++) {&#10;        if(isPrime[i]) primes.push_back(i);&#10;    }&#10;    return primes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Math 08 Prime Factors<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/prime-factors5052/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Iterative division.</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1) excluding output</td>
      <td><b>Explanation:</b> Iterate from `i = 2` to `sqrt(N)`. If `N % i == 0`, `i` is a prime factor. Add `i` to result, and repeatedly divide `N` by `i` until it's no longer divisible. After the loop, if `N > 1`, then `N` itself is a prime factor and should be added.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; AllPrimeFactors(int N) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(N % i == 0) {&#10;            ans.push_back(i);&#10;            while(N % i == 0) N /= i;&#10;        }&#10;    }&#10;    if(N &gt; 1) ans.push_back(N);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Math 09 Print All Divisors<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/print-all-divisors-of-a-number/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Iterate up to sqrt(N).</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(sqrt(N) + k log k)<br><b>Space:</b> O(k)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Brute Force: Iterate from 1 to N and check if N % i == 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDivisors(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        if(n % i == 0) cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;    }&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Optimal: Iterate up to sqrt(N). If 'i' divides N, then 'N/i' is also a divisor.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void print_divisors(int n) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            ans.push_back(i);&#10;            if(n / i != i) ans.push_back(n / i);&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    for(int x : ans) cout &lt;&lt; x &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Math 10 Armstrong Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td><b>Example 1:</b> Math.</td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Extract each digit, cube it, and sum them up. If the sum equals the original number, it's an Armstrong number.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string armstrongNumber(int n) {&#10;    int original = n, sum = 0;&#10;    while(n &gt; 0) {&#10;        int digit = n % 10;&#10;        sum += (digit * digit * digit);&#10;        n /= 10;&#10;    }&#10;    return sum == original ? &quot;Yes&quot; : &quot;No&quot;;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
