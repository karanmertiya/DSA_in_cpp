# Basic Maths Revision Table

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
      <td>Math 01 Count Digits<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/count-digits5716/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 12345, Output: 5</td>
      <td><b>Time:</b> O(log10 N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Convert to string and return length, or repeatedly divide by 10. O(log10 N) time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int evenlyDivides(int N){&#10;    if (N == 0) return 1;&#10;    int count = 0, temp = N;&#10;    while(temp &gt; 0) {&#10;        int digit = temp % 10;&#10;        if (digit != 0 &amp;&amp; N % digit == 0) count++;&#10;        temp /= 10;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Math 02 Reverse Integer<br><br></b> <a href='https://leetcode.com/problems/reverse-integer/' target='_blank'>LeetCode 7</a></td>
      <td><b>Example 1:</b> Input: x = 123, Output: 321</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Extract last digit using modulo, multiply answer by 10 and add. Check bounds for 32-bit integer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverse(int x) {&#10;    int ans = 0;&#10;    while(x != 0) {&#10;        int digit = x % 10;&#10;        if(ans &gt; INT_MAX/10 || ans &lt; INT_MIN/10) return 0;&#10;        ans = ans * 10 + digit;&#10;        x /= 10;&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Math 03 Palindrome Number<br><br></b> <a href='https://leetcode.com/problems/palindrome-number/' target='_blank'>LeetCode 9</a></td>
      <td><b>Example 1:</b> Input: x = 121, Output: true</td>
      <td><b>Time:</b> O(log10 x)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Negative numbers are false. Reverse half the number. If original equals reversed, it is a palindrome.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindrome(int x) {&#10;    if(x &lt; 0 || (x % 10 == 0 &amp;&amp; x != 0)) return false;&#10;    int reversedHalf = 0;&#10;    while(x &gt; reversedHalf) {&#10;        reversedHalf = reversedHalf * 10 + x % 10;&#10;        x /= 10;&#10;    }&#10;    return x == reversedHalf || x == reversedHalf / 10;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Math 04 Gcd Or Hcf<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: A = 4, B = 8, Output: 4</td>
      <td><b>Time:</b> O(log(min(a,b)))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Euclidean Algorithm. gcd(a, b) = gcd(b, a % b). Stop when one is 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long gcd(long long a, long long b) {&#10;    while (a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        if (a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    return a == 0 ? b : a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Math 05 Check For Prime<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/prime-number2314/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Input: N = 5, Output: 1</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Check divisibility up to sqrt(N).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int isPrime(int N){&#10;    if(N &lt;= 1) return 0;&#10;    for(int i=2; i*i&lt;=N; i++) {&#10;        if(N % i == 0) return 0;&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Math 06 Factorial Trailing Zeroes<br><br></b> <a href='https://leetcode.com/problems/factorial-trailing-zeroes/' target='_blank'>LeetCode 172</a></td>
      <td><b>Example 1:</b> Counting 5s.</td>
      <td><b>Time:</b> O(log_5(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Trailing zeroes are produced by 10s, which are pairs of 2 and 5. Since 2s are more frequent, we just count the number of 5s in prime factors of numbers up to N. This is `N/5 + N/25 + N/125 + ...`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trailingZeroes(int n) {&#10;    int count = 0;&#10;    while(n &gt; 0) {&#10;        count += n / 5;&#10;        n /= 5;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Math 07 Count Primes<br><br></b> <a href='https://leetcode.com/problems/count-primes/' target='_blank'>LeetCode 204</a></td>
      <td><b>Example 1:</b> Sieve of Eratosthenes.</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Use the Sieve of Eratosthenes. Initialize a boolean array of size `n` with `true`. Mark `0` and `1` as `false`. For each `i` from `2` to `sqrt(n)`, if `i` is prime, mark its multiples as `false` starting from `i*i`. Finally, count the number of `true`s.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countPrimes(int n) {&#10;    if(n &lt;= 2) return 0;&#10;    vector&lt;bool&gt; isPrime(n, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt; n; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt; n; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    int count = 0;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(isPrime[i]) count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Math 08 Valid Perfect Square<br><br></b> <a href='https://leetcode.com/problems/valid-perfect-square/' target='_blank'>LeetCode 367</a></td>
      <td><b>Example 1:</b> Binary Search.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use binary search from `1` to `num/2` or up to `46340` (sqrt of INT_MAX). If `mid * mid == num`, return true. Else if `mid * mid < num`, `low = mid + 1`. Else `high = mid - 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPerfectSquare(int num) {&#10;    if(num == 1) return true;&#10;    long long low = 1, high = num / 2;&#10;    while(low &lt;= high) {&#10;        long long mid = low + (high - low) / 2;&#10;        if(mid * mid == num) return true;&#10;        else if(mid * mid &lt; num) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Math 09 Power Of Two<br><br></b> <a href='https://leetcode.com/problems/power-of-two/' target='_blank'>LeetCode 231</a></td>
      <td><b>Example 1:</b> Bit Manipulation.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> If a number is a power of two, it has exactly one bit set in its binary representation. The expression `n & (n - 1)` clears the lowest set bit. Thus, if `n > 0` and `(n & (n - 1)) == 0`, it is a power of two.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwo(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Math 10 Power Of Three<br><br></b> <a href='https://leetcode.com/problems/power-of-three/' target='_blank'>LeetCode 326</a></td>
      <td><b>Example 1:</b> Modulo with largest power.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Since `n` is a 32-bit signed integer, the largest power of 3 that fits is `3^19 = 1162261467`. A number `n` is a power of 3 if `n > 0` and `1162261467 % n == 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfThree(int n) {&#10;    return n &gt; 0 &amp;&amp; 1162261467 % n == 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Math 11 Power Of Four<br><br></b> <a href='https://leetcode.com/problems/power-of-four/' target='_blank'>LeetCode 342</a></td>
      <td><b>Example 1:</b> Bit Manipulation.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> A power of 4 is also a power of 2, so `n > 0 && (n & (n-1)) == 0` must hold. Also, the single set bit must be at an even position (0-indexed). The mask `0x55555555` has 1s at all even positions. So `(n & 0x55555555) != 0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfFour(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0 &amp;&amp; (n &amp; 0x55555555) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Math 12 Add Digits<br><br></b> <a href='https://leetcode.com/problems/add-digits/' target='_blank'>LeetCode 258</a></td>
      <td><b>Example 1:</b> Digital Root.</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> This is known as the digital root. The formula is `1 + (n - 1) % 9`. If `n == 0`, return `0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int addDigits(int num) {&#10;    if(num == 0) return 0;&#10;    return 1 + (num - 1) % 9;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Math 13 Ugly Number<br><br></b> <a href='https://leetcode.com/problems/ugly-number/' target='_blank'>LeetCode 263</a></td>
      <td><b>Example 1:</b> Division.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> If `n <= 0`, return false. Divide `n` by 2, 3, and 5 as long as it is divisible. If the remaining number is 1, it's an ugly number, else false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isUgly(int n) {&#10;    if(n &lt;= 0) return false;&#10;    vector&lt;int&gt; primes = {2, 3, 5};&#10;    for(int p : primes) {&#10;        while(n % p == 0) n /= p;&#10;    }&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Math 14 Perfect Number<br><br></b> <a href='https://leetcode.com/problems/perfect-number/' target='_blank'>LeetCode 507</a></td>
      <td><b>Example 1:</b> Sum of divisors.</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> If `num <= 1`, return false. Iterate up to `sqrt(num)`. If `i` divides `num`, add `i` and `num/i` to the sum. After the loop, compare sum with `num`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPerfectNumber(int num) {&#10;    if(num &lt;= 1) return false;&#10;    int sum = 1;&#10;    for(int i = 2; i * i &lt;= num; i++) {&#10;        if(num % i == 0) {&#10;            sum += i;&#10;            if(i * i != num) sum += num / i;&#10;        }&#10;    }&#10;    return sum == num;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Math 15 Excel Sheet Column Title<br><br></b> <a href='https://leetcode.com/problems/excel-sheet-column-title/' target='_blank'>LeetCode 168</a></td>
      <td><b>Example 1:</b> Base 26 conversion.</td>
      <td><b>Time:</b> O(log_26(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> This is essentially base 26 conversion, but 1-indexed (A=1, B=2, Z=26). To make it 0-indexed, decrement `columnNumber` by 1 at each step, get the remainder modulo 26, convert to character, and divide by 26.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string convertToTitle(int columnNumber) {&#10;    string res = &quot;&quot;;&#10;    while(columnNumber &gt; 0) {&#10;        columnNumber--;&#10;        res += (char)(&#x27;A&#x27; + (columnNumber % 26));&#10;        columnNumber /= 26;&#10;    }&#10;    reverse(res.begin(), res.end());&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Math 16 Pow X N<br><br></b> <a href='https://leetcode.com/problems/powx-n/' target='_blank'>LeetCode 50</a></td>
      <td><b>Example 1:</b> Binary Exponentiation.</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use binary exponentiation. Initialize `ans = 1.0`. Keep a copy of `n` as a long long `nn`. If `nn < 0`, make it positive. While `nn > 0`, if `nn % 2 == 1`, multiply `ans` by `x` and decrement `nn`. Otherwise, square `x` and halve `nn`. If original `n < 0`, return `1.0 / ans`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double myPow(double x, int n) {&#10;    double ans = 1.0;&#10;    long long nn = n;&#10;    if(nn &lt; 0) nn = -1 * nn;&#10;    while(nn &gt; 0) {&#10;        if(nn % 2 == 1) {&#10;            ans = ans * x;&#10;            nn = nn - 1;&#10;        } else {&#10;            x = x * x;&#10;            nn = nn / 2;&#10;        }&#10;    }&#10;    if(n &lt; 0) ans = (double)(1.0) / (double)(ans);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Math 17 Sieve Of Eratosthenes<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Classic implementation.</td>
      <td><b>Time:</b> O(N log(log N))<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; sieveOfEratosthenes(int N) {&#10;    vector&lt;int&gt; primes;&#10;    vector&lt;bool&gt; isPrime(N + 1, true);&#10;    isPrime[0] = isPrime[1] = false;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(isPrime[i]) {&#10;            for(int j = i * i; j &lt;= N; j += i) {&#10;                isPrime[j] = false;&#10;            }&#10;        }&#10;    }&#10;    for(int i = 2; i &lt;= N; i++) {&#10;        if(isPrime[i]) primes.push_back(i);&#10;    }&#10;    return primes;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Math 18 Prime Factors<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/prime-factors5052/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Iterative division.</td>
      <td><b>Time:</b> O(sqrt(N))<br><b>Space:</b> O(1) excluding output</td>
      <td><b>Explanation:</b> Iterate from `i = 2` to `sqrt(N)`. If `N % i == 0`, `i` is a prime factor. Add `i` to result, and repeatedly divide `N` by `i` until it's no longer divisible. After the loop, if `N > 1`, then `N` itself is a prime factor and should be added.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; AllPrimeFactors(int N) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 2; i * i &lt;= N; i++) {&#10;        if(N % i == 0) {&#10;            ans.push_back(i);&#10;            while(N % i == 0) N /= i;&#10;        }&#10;    }&#10;    if(N &gt; 1) ans.push_back(N);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Math 19 Print All Divisors<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/print-all-divisors-of-a-number/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Iterate up to sqrt(N).</td>
      <td><b>Time:</b> O(sqrt(N) + k log k)<br><b>Space:</b> O(k)</td>
      <td><b>Explanation:</b> Iterate `i` from 1 to `sqrt(N)`. If `N % i == 0`, add `i` to the list of divisors. If `N / i != i`, also add `N / i`. Sort the list before returning.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void print_divisors(int n) {&#10;    vector&lt;int&gt; ans;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            ans.push_back(i);&#10;            if(n / i != i) ans.push_back(n / i);&#10;        }&#10;    }&#10;    sort(ans.begin(), ans.end());&#10;    for(int x : ans) cout &lt;&lt; x &lt;&lt; &quot; &quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Math 20 Armstrong Number<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Math.</td>
      <td><b>Time:</b> O(log10(N))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Extract each digit, cube it, and sum them up. If the sum equals the original number, it's an Armstrong number.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string armstrongNumber(int n) {&#10;    int original = n, sum = 0;&#10;    while(n &gt; 0) {&#10;        int digit = n % 10;&#10;        sum += (digit * digit * digit);&#10;        n /= 10;&#10;    }&#10;    return sum == original ? &quot;Yes&quot; : &quot;No&quot;;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Math 21 Gcd Or Hcf<br><br></b> <a href='https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1' target='_blank'>GFG</a></td>
      <td><b>Example 1:</b> Euclidean Algorithm.</td>
      <td><b>Time:</b> O(log(min(A, B)))<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use Euclidean algorithm. `gcd(A, B) = gcd(B, A % B)`. Repeat until `B` becomes 0, then `A` is the GCD.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcd(int A, int B) {&#10;    while(A &gt; 0 &amp;&amp; B &gt; 0) {&#10;        if(A &gt; B) A = A % B;&#10;        else B = B % A;&#10;    }&#10;    if(A == 0) return B;&#10;    return A;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
