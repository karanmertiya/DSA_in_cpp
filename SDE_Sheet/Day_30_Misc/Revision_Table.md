# Day 30 Misc Revision Table

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
      <td rowspan="1">Math 06 Power Of Two<br><br></b> <a href="https://leetcode.com/problems/power-of-two/" target="_blank">LeetCode 231</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> n = 1<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>If a number is a power of two, it has exactly one bit set in its binary representation. The expression `n & (n - 1)` clears the lowest set bit. Thus, if `n > 0` and `(n & (n - 1)) == 0`, it is a power of two.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwo(int n) {&#10;    return n &gt; 0 &amp;&amp; (n &amp; (n - 1)) == 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Math 07 Pow X N<br><br></b> <a href="https://leetcode.com/problems/powx-n/" target="_blank">LeetCode 50</a></td>
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
      <td rowspan="2">8</td>
      <td rowspan="2">Bit 08 Swap Two Numbers<br><br></b> <a href="https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1" target="_blank">GeeksforGeeks</a></td>
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
      <td rowspan="2">9</td>
      <td rowspan="2">Bit 09 Check Ith Bit Set<br><br></b> <a href="https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1" target="_blank">GeeksforGeeks</a></td>
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
      <td rowspan="1">10</td>
      <td rowspan="1">Bit 10 Operations Set Clear Toggle<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b><br>N=70, i=3 -> Set:78, Clear:62, Toggle:78<br><br><b> </b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.</td>
      <td><b>Edge Cases:</b> **Shift Overflow:** `1LL` used strictly to prevent overflow beyond 31 bits.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bitOperations(int n, int i) {&#10;    int setBit = n | (1LL &lt;&lt; i);&#10;    int clearBit = n &amp; ~(1LL &lt;&lt; i);&#10;    int toggleBit = n ^ (1LL &lt;&lt; i);&#10;    return {setBit, clearBit, toggleBit};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Bit 11 Count Set Bits<br><br></b> <a href="https://leetcode.com/problems/number-of-1-bits/" target="_blank">LeetCode 191</a></td>
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
      <td rowspan="1">12</td>
      <td rowspan="1">Bit 12 Minimum Bit Flips To Convert Number<br><br></b> <a href="https://leetcode.com/problems/minimum-bit-flips-to-convert-number/" target="_blank">LeetCode 2220</a></td>
      <td rowspan="1"><b> </b><br><br><b>Input:</b> start=10 (1010), goal=7 (0111)<br><b>Output:</b> 3 flips</td>
      <td><b>Time:</b> O(Set Bits)<br><b>Space:</b> O(1)</td>
      <td>XOR `start` and `goal` to isolate differing bits, then count the set bits in the result.</td>
      <td><b>Edge Cases:</b> **XOR Magic:** XOR inherently maps identical bits to 0 and different bits to 1, instantly mapping the problem to Hamming Weight.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minBitFlips(int start, int goal) {&#10;    int xor_res = start ^ goal;&#10;    int count = 0;&#10;    // Brian Kernighan&#x27;s algorithm to count the mismatched bits&#10;    while(xor_res != 0) {&#10;        xor_res = xor_res &amp; (xor_res - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Sw 13 Longest Substring Without Repeating Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/" target="_blank">LeetCode 3</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> s = "abcabcbb"<br><b>Output:</b> 3 ("abc")</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(min(N, M))</td>
      <td>Sliding window with a Hash Map storing the latest index of each character. Move `left` pointer to `max(left, map[char] + 1)`.<br><br><b>Dependencies:</b> <code>std::vector</code> for frequency array</td>
      <td><b>Edge Cases:</b> <b>Pointer Leap:</b> `left` can only jump forward, thus `std::max(left, ...)` prevents `left` from going backward if an old duplicate is found.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstring(std::string s) {&#10;    std::vector&lt;int&gt; mpp(256, -1);&#10;    int left = 0, right = 0, max_len = 0;&#10;    while(right &lt; s.length()) {&#10;        if(mpp[s[right]] != -1) {&#10;            left = std::max(left, mpp[s[right]] + 1);&#10;        }&#10;        mpp[s[right]] = right;&#10;        max_len = std::max(max_len, right - left + 1);&#10;        right++;&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Sw 14 Trapping Rain Water<br><br></b> <a href="https://leetcode.com/problems/trapping-rain-water/" target="_blank">LeetCode 42</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> height = [0,1,0,2,1,0,1,3,2,1,2,1]<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Two pointers `left` and `right`. Maintain `left_max` and `right_max`. Move the pointer pointing to the smaller max, adding trapped water.</td>
      <td><b>Edge Cases:</b> <b>Local Maxima:</b> Water trapped at `i` relies on the absolute minimum of the highest bars to its left and right.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trap(std::vector&lt;int&gt;&amp; height) {&#10;    int n = height.size();&#10;    int left = 0, right = n - 1;&#10;    int res = 0, maxLeft = 0, maxRight = 0;&#10;    while (left &lt;= right) {&#10;        if (height[left] &lt;= height[right]) {&#10;            if (height[left] &gt;= maxLeft) maxLeft = height[left];&#10;            else res += maxLeft - height[left];&#10;            left++;&#10;        } else {&#10;            if (height[right] &gt;= maxRight) maxRight = height[right];&#10;            else res += maxRight - height[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Sw 15 Container With Most Water<br><br></b> <a href="https://leetcode.com/problems/container-with-most-water/" target="_blank">LeetCode 11</a></td>
      <td rowspan="1"><b>Example 1:</b> <br><b>Input:</b> height = [1,8,6,2,5,4,8,3,7]<br><b>Output:</b> 49</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Two Pointers from ends. Area is `min(h[left], h[right]) * width`. Move the pointer with the smaller height to seek a potentially taller line.<br><br><b>Dependencies:</b> <code>std::max</code>, <code>std::min</code></td>
      <td><b>Edge Cases:</b> <b>Width vs Height Tradeoff:</b> By starting at maximum width, we only decrease width. Thus, we must only abandon a height if we hope to find a taller one.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxArea(std::vector&lt;int&gt;&amp; height) {&#10;    int left = 0, right = height.size() - 1;&#10;    int max_area = 0;&#10;    while(left &lt; right) {&#10;        int area = std::min(height[left], height[right]) * (right - left);&#10;        max_area = std::max(max_area, area);&#10;        if(height[left] &lt; height[right]) left++;&#10;        else right--;&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Sort 16 Selection Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/selection-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9<br><br><b> </b> In-place sorting.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Find the minimum element in the unsorted array and swap it with the element at the beginning.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> Always `O(N^2)` even if the array is already sorted.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void selectionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt; n - 1; i++) {&#10;        int min_idx = i;&#10;        for (int j = i + 1; j &lt; n; j++) {&#10;            if (arr[j] &lt; arr[min_idx]) {&#10;                min_idx = j;&#10;            }&#10;        }&#10;        std::swap(arr[i], arr[min_idx]);&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Sort 17 Bubble Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bubble-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>Repeatedly swap adjacent elements if they are in the wrong order. Push the maximum element to the end.</td>
      <td><b>Edge Cases:</b> <b>Best Case Check:</b> Adding `did_swap` flag makes Best Case time `O(N)` for already sorted arrays.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void bubbleSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = n - 1; i &gt;= 1; i--) {&#10;        bool did_swap = false;&#10;        for (int j = 0; j &lt;= i - 1; j++) {&#10;            if (arr[j] &gt; arr[j + 1]) {&#10;                std::swap(arr[j], arr[j + 1]);&#10;                did_swap = true;&#10;            }&#10;        }&#10;        if (!did_swap) break;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Sort 18 Insertion Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/insertion-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Takes an element and places it in its correct position within the previously sorted part of the array.</td>
      <td><b>Edge Cases:</b> <b>Online Algorithm:</b> Good for data coming in one by one. `O(N)` best case time.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void insertionSort(std::vector&lt;int&gt;&amp; arr) {&#10;    int n = arr.size();&#10;    for (int i = 0; i &lt;= n - 1; i++) {&#10;        int j = i;&#10;        while (j &gt; 0 &amp;&amp; arr[j - 1] &gt; arr[j]) {&#10;            std::swap(arr[j - 1], arr[j]);&#10;            j--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Sort 19 Merge Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/merge-sort/1" target="_blank">GFG</a> | <a href="https://leetcode.com/problems/sort-an-array/" target="_blank">LC 912</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td>Recursively split array in half, sort them, and merge the sorted halves.<br><br><b>Dependencies:</b> Extra array for merging</td>
      <td><b>Edge Cases:</b> <b>Stable Sort:</b> Maintains relative order of equal elements. Requires `O(N)` extra space to merge.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(std::vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    std::vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i = low; i &lt;= high; i++) arr[i] = temp[i - low];&#10;}&#10;&#10;void mergeSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if (low &gt;= high) return;&#10;    int mid = low + (high - low) / 2;&#10;    mergeSortHelper(arr, low, mid);&#10;    mergeSortHelper(arr, mid + 1, high);&#10;    merge(arr, low, mid, high);&#10;}&#10;&#10;void mergeSort(std::vector&lt;int&gt;&amp; arr) {&#10;    mergeSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Sort 20 Quick Sort<br><br></b> <a href="https://www.geeksforgeeks.org/problems/quick-sort/1" target="_blank">GeeksforGeeks</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {4, 1, 3, 9, 7}<br><b>Output:</b> 1 3 4 7 9</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Pick a pivot. Place smaller elements left and larger right. Recursively sort partitions.</td>
      <td><b>Edge Cases:</b> <b>Worst Case:</b> `O(N^2)` if array is already sorted and pivot is extreme. Avoided by randomized pivot.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int partition(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int pivot = arr[low];&#10;    int i = low, j = high;&#10;    while(i &lt; j) {&#10;        while(arr[i] &lt;= pivot &amp;&amp; i &lt;= high - 1) i++;&#10;        while(arr[j] &gt; pivot &amp;&amp; j &gt;= low + 1) j--;&#10;        if(i &lt; j) std::swap(arr[i], arr[j]);&#10;    }&#10;    std::swap(arr[low], arr[j]);&#10;    return j;&#10;}&#10;&#10;void quickSortHelper(std::vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    if(low &lt; high) {&#10;        int pIndex = partition(arr, low, high);&#10;        quickSortHelper(arr, low, pIndex - 1);&#10;        quickSortHelper(arr, pIndex + 1, high);&#10;    }&#10;}&#10;&#10;void quickSort(std::vector&lt;int&gt;&amp; arr) {&#10;    quickSortHelper(arr, 0, arr.size() - 1);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
