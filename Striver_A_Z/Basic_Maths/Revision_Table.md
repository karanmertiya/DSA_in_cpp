# Striver A Z - Basic Maths Revision Table

<table border="1">
  <thead>
    <tr>
      <th>S.No</th>
      <th>Problem Name</th>
      <th>Example</th>
      <th>Common Constraints</th>
      <th>Approach Type</th>
      <th>Time</th>
      <th>Space</th>
      <th>Specific Conditions / Edge Cases</th>
      <th>Logic</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td rowspan="3">1</td>
      <td rowspan="3">Math 01 Count Digits</td>
      <td rowspan="3"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 12345&#10;Output: 5&#10;&#10;Example 2:&#10;Input: N = 8394&#10;Output: 4</code></pre></td>
      <td rowspan="3">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Sign Edge Case:</b> Fails on N=0. Requires explicit check.</td>
      <td><details><summary>View Code</summary><br><i>Note: Divide by 10 continuously until N becomes 0.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if(n &lt;= 0) return 1;</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsBrute(int n) {&#10;    // Edge Case: Handle N=0 specifically&#10;    if (n &lt;= 0) return 1;&#10;    int cnt = 0;&#10;    while(n &gt; 0) {&#10;        cnt++;&#10;        n = n / 10;&#10;    }&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Better</b></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><b>Memory Trade-off:</b> String allocation required. Avoid for strictly O(1) space constraints.</td>
      <td><details><summary>View Code</summary><br><i>Note: Convert number to string and return length.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsBetter(int n) {&#10;    // Trade-off: Allocates string memory proportional to digit count&#10;    string s = to_string(n);&#10;    return s.length();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Library Requirement:</b> Must use math library. Fails if standard libraries are restricted.</td>
      <td><details><summary>View Code</summary><br><i>Note: Use base-10 logarithm to find digit count mathematically.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countDigitsOptimal(int n) {&#10;    // Edge Case check for zero&#10;    if (n &lt;= 0) return 1;&#10;    int cnt = (int)(log10(n) + 1);&#10;    return cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Math 02 Reverse A Number</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 1234&#10;Output: 4321&#10;&#10;Example 2:&#10;Input: N = 10400&#10;Output: 401</code></pre></td>
      <td rowspan="2">-2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Brute Force</b></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><code>O(log10(N))</code><br><i>Trade-off</i></td>
      <td><b>Negative Signs:</b> Reversing a string with '-' results in invalid parsing.</td>
      <td><details><summary>View Code</summary><br><i>Note: Convert to string, reverse the string, and parse back to integer.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverseNumberBrute(int n) {&#10;    // Edge Case: Explicitly store and remove sign before string conversion&#10;    bool isNeg = n &lt; 0;&#10;    string s = to_string(abs(n));&#10;    reverse(s.begin(), s.end());&#10;    int res = stoi(s);&#10;    return isNeg ? -res : res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Overflow Risk:</b> Number fits in 32-bit int, but its reverse might not. Forces explicit checks.</td>
      <td><details><summary>View Code</summary><br><i>Note: Extract digits using modulo 10 and build the reversed number mathematically.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if (revNum &gt; INT_MAX / 10 || revNum &lt; INT_MIN / 10) return 0;</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int reverseNumberOptimal(int n) {&#10;    int revNum = 0;&#10;    while(n != 0) {&#10;        int ld = n % 10;&#10;        // Edge Case: Strict 32-bit overflow check before multiplication&#10;        if (revNum &gt; INT_MAX / 10 || revNum &lt; INT_MIN / 10) return 0;&#10;        revNum = (revNum * 10) + ld;&#10;        n = n / 10;&#10;    }&#10;    return revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Math 03 Check Palindrome</td>
      <td rowspan="1"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 121&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 123&#10;Output: false</code></pre></td>
      <td rowspan="1">-2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Variable Requirement:</b> Number is destroyed during loop, requires `dup` variable for final check.</td>
      <td><details><summary>View Code</summary><br><i>Note: Reverse the number mathematically and compare it to the original.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPalindromeOptimal(int n) {&#10;    // Edge Case: Negative numbers are strictly not palindromes&#10;    if (n &lt; 0) return false;&#10;    &#10;    int dup = n;&#10;    long long revNum = 0;&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        revNum = (revNum * 10) + ld;&#10;        n = n / 10;&#10;    }&#10;    return dup == revNum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Math 04 Gcd Or Hcf</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N1 = 9, N2 = 12&#10;Output: 3&#10;&#10;Example 2:&#10;Input: N1 = 20, N2 = 15&#10;Output: 5</code></pre></td>
      <td rowspan="2">1 &le; N1, N2 &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(min(N1, N2))</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Risk:</b> ~10<sup>9</sup> ops heavily exceeds 1 sec limit.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from min(N1, N2) down to 1. The first number dividing both is the GCD.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcdBrute(int n1, int n2) {&#10;    for(int i = min(n1, n2); i &gt;= 1; i--) {&#10;        if(n1 % i == 0 &amp;&amp; n2 % i == 0) {&#10;            return i;&#10;        }&#10;    }&#10;    return 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(log(&Phi;)(min(N1, N2)))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Modulo Safety:</b> Euclidean Algorithm easily passes 10<sup>9</sup> via log-scale modulo operations.</td>
      <td><details><summary>View Code</summary><br><i>Note: Euclidean algorithm: gcd(a, b) = gcd(b, a % b) until one becomes 0.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int gcdOptimal(int a, int b) {&#10;    while(a &gt; 0 &amp;&amp; b &gt; 0) {&#10;        // Uses modulo rather than subtraction for logarithmic time complexity&#10;        if(a &gt; b) a = a % b;&#10;        else b = b % a;&#10;    }&#10;    if(a == 0) return b;&#10;    return a;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Math 05 Armstrong Numbers</td>
      <td rowspan="1"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 153&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 170&#10;Output: false</code></pre></td>
      <td rowspan="1">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Optimal</b></td>
      <td><code>O(log10(N))</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Two-Pass Logic:</b> Requires digit count upfront before processing sum of powers.</td>
      <td><details><summary>View Code</summary><br><i>Note: Calculate digit count first, then mathematically extract digits and compute power sums.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isArmstrong(int n) {&#10;    int dup = n;&#10;    int sum = 0;&#10;    int digits = (int)(log10(n) + 1);&#10;    while(n &gt; 0) {&#10;        int ld = n % 10;&#10;        // Uses floating math, convert to int safely&#10;        sum += round(pow(ld, digits));&#10;        n = n / 10;&#10;    }&#10;    return sum == dup;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">6</td>
      <td rowspan="2">Math 06 Print All Divisors</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 36&#10;Output: 1 2 3 4 6 9 12 18 36</code></pre></td>
      <td rowspan="2">1 &le; N &le; 10<sup>6</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(N)</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Risk:</b> N=10^6 takes ~10<sup>6</sup> ops. Highly inefficient compared to optimal.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 1 to N and check for divisibility.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDivisorsBrute(int n) {&#10;    for(int i = 1; i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            std::cout &lt;&lt; i &lt;&lt; &quot; &quot;;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(&radic;N * log(&radic;N))</code><br><i>Constraint</i></td>
      <td><code>O(&radic;N)</code><br><i>Trade-off</i></td>
      <td><b>Perfect Squares:</b> Checking `(n / i) != i` explicitly prevents duplicate divisor entries.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate up to sqrt(N) to find pairs of divisors, then sort.</i><br><br><b>Edge Case Code:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">if((n / i) != i) divisors.push_back(n / i);</code></pre><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void printDivisorsOptimal(int n) {&#10;    std::vector&lt;int&gt; divisors;&#10;    for(int i = 1; i * i &lt;= n; i++) {&#10;        if(n % i == 0) {&#10;            divisors.push_back(i);&#10;            // Edge Case: Avoid duplicate addition for perfect square roots&#10;            if((n / i) != i) {&#10;                divisors.push_back(n / i);&#10;            }&#10;        }&#10;    }&#10;    std::sort(divisors.begin(), divisors.end());&#10;    for(auto it : divisors) {&#10;        std::cout &lt;&lt; it &lt;&lt; &quot; &quot;;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Math 07 Check For Prime</td>
      <td rowspan="2"><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-text">Example 1:&#10;Input: N = 11&#10;Output: true&#10;&#10;Example 2:&#10;Input: N = 15&#10;Output: false</code></pre></td>
      <td rowspan="2">1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Brute Force</b></td>
      <td><code>O(N)</code><br><i>Trade-off</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>TLE Guarantee:</b> N=10^9 takes ~10<sup>9</sup> ops. Guaranteed TLE on any modern platform.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 2 to N-1 and check divisibility.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeBrute(int n) {&#10;    if (n &lt;= 1) return false;&#10;    for(int i = 2; i &lt; n; i++) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Optimal</b></td>
      <td><code>O(&radic;N)</code><br><i>Constraint</i></td>
      <td><code>O(1)</code><br><i>Constraint</i></td>
      <td><b>Loop Optimization:</b> `i * i <= n` is far superior to computing `sqrt(n)` repeatedly.</td>
      <td><details><summary>View Code</summary><br><i>Note: Iterate from 2 up to sqrt(N) since divisors come in pairs.</i><br><br><b>Implementation:</b><br><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkPrimeOptimal(int n) {&#10;    if(n &lt;= 1) return false;&#10;    // Edge Case Optimization: Avoid floating point sqrt overhead by squaring i&#10;    for(int i = 2; i * i &lt;= n; i++) {&#10;        if(n % i == 0) return false;&#10;    }&#10;    return true;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
