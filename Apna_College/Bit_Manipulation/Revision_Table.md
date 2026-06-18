# Bit Manipulation Revision Table

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
      <td rowspan="2">1</td>
      <td rowspan="2">Bit 01 Swap Two Numbers<br><br></b> <a href='https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: a=5, b=7, Output: a=7, b=5<br><br><b>Note (Constraint):</b> 1 &le; a, b &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Integer Overflow:</b> Addition `a + b` can overflow if numbers are near `INT_MAX`.</td>
      <td><b>Explanation:</b> Use basic arithmetic (addition and subtraction) to swap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void swapArithmetic(int &amp;a, int &amp;b) {&#10;    // Edge Case: Can overflow for massive 32-bit integers&#10;    a = a + b;&#10;    b = a - b;&#10;    a = a - b;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Reference Safety:</b> XOR swap fails to `0` if `a` and `b` point to the exact same memory address.</td>
      <td><b>Explanation:</b> Use XOR bitwise operation. XOR of a number with itself is 0, and with 0 is the number itself.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void swapOptimal(int &amp;a, int &amp;b) {&#10;    // Optimal Bitwise XOR swap. Immune to value overflow.&#10;    if (&amp;a != &amp;b) { // Prevent zeroing out if same memory address&#10;        a = a ^ b;&#10;        b = a ^ b;&#10;        a = a ^ b;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bit 03 Operations Set Clear Toggle<br><br></b> <a href='https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> N=70, i=3 -> Set:78, Clear:62, Toggle:78<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Shift Overflow:</b> `1LL` used strictly to prevent overflow beyond 31 bits.</td>
      <td><b>Explanation:</b> Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;iostream&gt;&#10;&#10;std::vector&lt;long long&gt; bitOperations(long long n, int i) {&#10;    long long setBit = n | (1LL &lt;&lt; i);&#10;    long long clearBit = n &amp; ~(1LL &lt;&lt; i);&#10;    long long toggleBit = n ^ (1LL &lt;&lt; i);&#10;    return {setBit, clearBit, toggleBit};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">3</td>
      <td rowspan="2">Bit 05 Power Of Two<br><br></b> <a href='https://leetcode.com/problems/power-of-two/' target='_blank'>LeetCode 231</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: N=16, Output: true<br><b>Example 2:</b> Input: N=3, Output: false<br><br><b>Note (Constraint):</b> -2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(log2(N)) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Zero/Negative Handle:</b> Powers of 2 must be strictly positive.</td>
      <td><b>Explanation:</b> Iteratively divide by 2. If it ever yields an odd number > 1, it is not a power of 2.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwoBrute(int n) {&#10;    if (n &lt;= 0) return false;&#10;    while(n % 2 == 0) {&#10;        n /= 2;&#10;    }&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Underflow Check:</b> `N > 0` strictly blocks `n=0` or negatives which break the `n & (n-1)` logic.</td>
      <td><b>Explanation:</b> A power of 2 has exactly 1 set bit. Thus `N & (N-1)` must equal 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwoOptimal(int n) {&#10;    // Edge Case: N &gt; 0 handles both 0 and negative inputs inherently&#10;    return (n &gt; 0) &amp;&amp; ((n &amp; (n - 1)) == 0);&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
