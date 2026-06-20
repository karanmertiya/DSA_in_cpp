# Maths Revision Table

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
      <td>Math 01 Count Digits<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-digits5716/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 12345, Output: 5</td>
      <td><b>Time:</b> O(log10 N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>N=0:</b> Handled naturally if checking N > 0, otherwise special condition.</td>
      <td><b>Explanation:</b> Convert to string and return length, or repeatedly divide by 10. O(log10 N) time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evenlyDivides(int N){&#10;    if (N == 0) return 1;&#10;    int count = 0, temp = N;&#10;    while(temp &gt; 0) {&#10;        int digit = temp % 10;&#10;        if (digit != 0 &amp;&amp; N % digit == 0) count++;&#10;        temp /= 10;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Math 02 Reverse Integer<br><br></b> <a href='https://leetcode.com/problems/reverse-integer/' target='_blank'>LeetCode 7</a></td>
      <td><b>Example 1:</b> Input: x = 123, Output: 321</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td><code>#include <limits.h></code></td>
      <td><b>Overflow:</b> If ans > INT_MAX/10, return 0.</td>
      <td><b>Explanation:</b> Extract last digit using modulo, multiply answer by 10 and add. Check bounds for 32-bit integer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    int ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        if(ans &gt; INT_MAX/10 || ans &lt; INT_MIN/10) return 0;&#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Math 03 Palindrome Number<br><br></b> <a href='https://leetcode.com/problems/palindrome-number/' target='_blank'>LeetCode 9</a></td>
      <td><b>Example 1:</b> Input: x = 121, Output: true</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Negative Numbers:</b> Instant false. Trailing zeroes instant false.</td>
      <td><b>Explanation:</b> Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int x) {&#10;    if(x &lt; 0 || (x % 10 == 0 &amp;&amp; x != 0)) return false;&#10;    int reversedHalf = 0;&#10;    while(x &gt; reversedHalf) {&#10;        reversedHalf = reversedHalf * 10 + x % 10;&#10;        x /= 10;&#10;    }&#10;    return x == reversedHalf || x == reversedHalf / 10;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Math 04 Gcd Or Hcf<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: A = 4, B = 8, Output: 4</td>
      <td><b>Time:</b> O(log(min(a,b)))<br><b>Space:</b> O(1)</td>
      <td><code>#include <numeric></code></td>
      <td><b>One is 0:</b> Return the other number.</td>
      <td><b>Explanation:</b> Euclidean Algorithm. gcd(a, b) = gcd(b, a % b). Stop when one is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long gcd(long long a, long long b) {&#10;    while (a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        if (a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    return a == 0 ? b : a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Math 05 Check For Prime<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/prime-number2314/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 5, Output: 1</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>N=1:</b> Not prime.</td>
      <td><b>Explanation:</b> Check divisibility up to sqrt(N).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i=2; i*i&lt;=N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Math 06 Count Primes<br><br></b> <a href='https://leetcode.com/problems/count-primes/' target='_blank'>LeetCode 204</a></td>
      <td><b>Example 1:</b> Sieve of Eratosthenes.</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use the Sieve of Eratosthenes. Initialize a boolean array of size `n` with `true`. Mark `0` and `1` as `false`. For each `i` from `2` to `sqrt(n)`, if `i` is prime, mark its multiples as `false` starting from `i*i`. Finally, count the number of `true`s.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPrimes(int n) {&#10;    if(n &lt;= 2) return 0;&#10;    vector&lt;bool&gt; isPrime(n, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt; n; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt; n; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    int count = 0;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(isPrime[i]) count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Math 07 Pow X N<br><br></b> <a href='https://leetcode.com/problems/powx-n/' target='_blank'>LeetCode 50</a></td>
      <td><b>Example 1:</b> Binary Exponentiation.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>Negative power, n = INT_MIN</td>
      <td><b>Explanation:</b> Use binary exponentiation. Initialize `ans = 1.0`. Keep a copy of `n` as a long long `nn`. If `nn < 0`, make it positive. While `nn > 0`, if `nn % 2 == 1`, multiply `ans` by `x` and decrement `nn`. Otherwise, square `x` and halve `nn`. If original `n < 0`, return `1.0 / ans`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    while(nn &gt; 0) {&#10;        if(nn % 2 == 1) {&#10;            ans = ans * x;&#10;            nn = nn - 1;&#10;        } else {&#10;            x = x * x;&#10;            nn = nn / 2;&#10;        }&#10;    }&#10;    if(n &lt; 0) ans = (double)(1.0) / (double)(ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Math 08 Sieve Of Eratosthenes<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Classic implementation.</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; sieveOfEratosthenes(int N) {&#10;    vector&lt;int&gt; primes;&#10;    vector&lt;bool&gt; isPrime(N + 1, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt;= N; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    for(int i = 2; i &lt;= N; i++) {&#10;        if(isPrime[i]) primes.push_back(i);&#10;    }&#10;    return primes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Math 09 Prime Factors<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/prime-factors5052/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Iterative division.</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1) excluding output</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate from `i = 2` to `sqrt(N)`. If `N % i == 0`, `i` is a prime factor. Add `i` to result, and repeatedly divide `N` by `i` until it's no longer divisible. After the loop, if `N > 1`, then `N` itself is a prime factor and should be added.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; AllPrimeFactors(int N) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(N % i == 0) {&#10;            ans.push_back(i);&#10;            while(N % i == 0) N /= i;&#10;        }&#10;    }&#10;    if(N &gt; 1) ans.push_back(N);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Math 10 Print All Divisors<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/print-all-divisors-of-a-number/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Iterate up to sqrt(N).</td>
      <td><b>Time:</b> O(sqrt(N) + k log k)<br><b>Space:</b> O(k)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Iterate `i` from 1 to `sqrt(N)`. If `N % i == 0`, add `i` to the list of divisors. If `N / i != i`, also add `N / i`. Sort the list before returning.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void print_divisors(int n) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            ans.push_back(i);&#10;            if(n / i != i) ans.push_back(n / i);&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    for(int x : ans) cout &lt;&lt; x &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Math 11 Armstrong Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Math.</td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Extract each digit, cube it, and sum them up. If the sum equals the original number, it's an Armstrong number.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string armstrongNumber(int n) {&#10;    int original = n, sum = 0;&#10;    while(n &gt; 0) {&#10;        int digit = n % 10;&#10;        sum += (digit * digit * digit);&#10;        n /= 10;&#10;    }&#10;    return sum == original ? &quot;Yes&quot; : &quot;No&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Math 12 Gcd Or Hcf<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Euclidean Algorithm.</td>
      <td><b>Time:</b> O(log(min(A, B)))<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Use Euclidean algorithm. `gcd(A, B) = gcd(B, A % B)`. Repeat until `B` becomes 0, then `A` is the GCD.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcd(int A, int B) {&#10;    while(A &gt; 0 &amp;&amp; B &gt; 0) {&#10;        if(A &gt; B) A = A % B;&#10;        else B = B % A;&#10;    }&#10;    if(A == 0) return B;&#10;    return A;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
