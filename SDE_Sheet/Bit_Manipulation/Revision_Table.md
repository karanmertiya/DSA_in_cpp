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
      <td rowspan="1">1</td>
      <td rowspan="1">Bit 01 Swap Two Numbers<br><br></b> <a href='https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: a=5, b=7, Output: a=7, b=5<br><br><b>Note (Constraint):</b> 1 &le; a, b &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Integer Overflow:</b> Addition `a + b` can overflow if numbers are near `INT_MAX`.</td>
      <td><b>Explanation:</b> Use basic arithmetic (addition and subtraction) to swap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void swapArithmetic(int &amp;a, int &amp;b) {&#10;    // Edge Case: Can overflow for massive 32-bit integers&#10;    a = a + b;&#10;    b = a - b;&#10;    a = a - b;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bit 02 Check Ith Bit Set<br><br></b> <a href='https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=4 (100 in binary), i=2, Output: true<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup>, 0 &le; i &le; 31</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Right shift N by i times and check if the least significant bit is 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBitRightShift(int n, int k) {&#10;    return ((n &gt;&gt; k) &amp; 1) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Bit 03 Operations Set Clear Toggle<br><br></b> <a href='https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="1"><b>Example 1:</b> N=70, i=3 -> Set:78, Clear:62, Toggle:78<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Shift Overflow:</b> `1LL` used strictly to prevent overflow beyond 31 bits.</td>
      <td><b>Explanation:</b> Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;iostream&gt;&#10;&#10;std::vector&lt;long long&gt; bitOperations(long long n, int i) {&#10;    long long setBit = n | (1LL &lt;&lt; i);&#10;    long long clearBit = n &amp; ~(1LL &lt;&lt; i);&#10;    long long toggleBit = n ^ (1LL &lt;&lt; i);&#10;    return {setBit, clearBit, toggleBit};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">4</td>
      <td rowspan="1">Bit 05 Power Of Two<br><br></b> <a href='https://leetcode.com/problems/power-of-two/' target='_blank'>LeetCode 231</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=16, Output: true<br><b>Example 2:</b> Input: N=3, Output: false<br><br><b>Note (Constraint):</b> -2<sup>31</sup> &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(log2(N)) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Zero/Negative Handle:</b> Powers of 2 must be strictly positive.</td>
      <td><b>Explanation:</b> Iteratively divide by 2. If it ever yields an odd number > 1, it is not a power of 2.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool isPowerOfTwoBrute(int n) {&#10;    if (n &lt;= 0) return false;&#10;    while(n % 2 == 0) {&#10;        n /= 2;&#10;    }&#10;    return n == 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">5</td>
      <td rowspan="1">Bit 06 Count Set Bits<br><br></b> <a href='https://leetcode.com/problems/number-of-1-bits/' target='_blank'>LeetCode 191</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: N=11 (1011), Output: 3<br><br><b>Note (Constraint):</b> 1 &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(32) &cong; O(1) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Static Loop Iterations:</b> Loop always runs 32 times regardless of number size.</td>
      <td><b>Explanation:</b> Iterate through all 32 bits and check if each is set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeightBrute(uint32_t n) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        if((n &gt;&gt; i) &amp; 1) {&#10;            count++;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Bit 07 Minimum Bit Flips<br><br></b> <a href='https://leetcode.com/problems/minimum-bit-flips-to-convert-number/' target='_blank'>LeetCode 2220</a></td>
      <td rowspan="1"><b>Example 1:</b> Input: start=10 (1010), goal=7 (0111), Output: 3 flips<br><br><b>Note (Constraint):</b> 0 &le; start, goal &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(Set Bits) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>XOR Magic:</b> XOR inherently maps identical bits to 0 and different bits to 1, instantly mapping the problem to Hamming Weight.</td>
      <td><b>Explanation:</b> XOR `start` and `goal` to isolate differing bits, then count the set bits in the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minBitFlips(int start, int goal) {&#10;    int xor_res = start ^ goal;&#10;    int count = 0;&#10;    // Brian Kernighan&#x27;s algorithm to count the mismatched bits&#10;    while(xor_res != 0) {&#10;        xor_res = xor_res &amp; (xor_res - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">7</td>
      <td rowspan="1">Bit 08 Single Number<br><br></b> <a href='https://leetcode.com/problems/single-number/' target='_blank'>LeetCode 136</a><br><br><b>Variants:</b><br>- What if elements are sorted? (Can use Binary Search `O(log N)` Time).<br>- What if elements are strictly positive? (Can use Array mapping if constraints allow).</td>
      <td rowspan="1"><b>Example 1:</b> Input: nums = [4,1,2,1,2], Output: 4<br><br><b>Note (Constraint):</b> 1 &le; N &le; 3 * 10<sup>4</sup><br>-3 * 10<sup>4</sup> &le; nums[i] &le; 3 * 10<sup>4</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Data Structure:</b><br><code>std::unordered_map</code> / <code>dict</code></td>
      <td><b>Memory Heavy:</b> Fails optimal space constraint due to dynamic hash mapping allocation.</td>
      <td><b>Explanation:</b> Use a Hash Map to count occurrences. Return the element with count 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;&#10;int singleNumberBrute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : nums) freq[num]++;&#10;    for(auto it : freq) {&#10;        if(it.second == 1) return it.first;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
