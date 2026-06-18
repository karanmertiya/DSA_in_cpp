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
      <td rowspan="2">Bit 02 Check Ith Bit Set<br><br></b> <a href='https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1' target='_blank'>GeeksforGeeks</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: N=4 (100 in binary), i=2, Output: true<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup>, 0 &le; i &le; 31</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td>-</td>
      <td><b>Explanation:</b> Right shift N by i times and check if the least significant bit is 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBitRightShift(int n, int k) {&#10;    return ((n &gt;&gt; k) &amp; 1) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Shift Overflow:</b> If checking bits > 30, `1 << k` overflows a 32-bit signed int. Requires `1LL << k`.</td>
      <td><b>Explanation:</b> Left shift 1 by i times to create a mask, then bitwise AND with N.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBitLeftShift(int n, int k) {&#10;    // Edge Case: 1LL prevents overflow if k &gt;= 31&#10;    return (n &amp; (1LL &lt;&lt; k)) != 0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">2</td>
      <td rowspan="1">Bit 04 Remove Last Set Bit</td>
      <td rowspan="1"><b>Example 1:</b> Input: N=12 (1100), Output: 8 (1000)<br><br><b>Note (Constraint):</b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Zero Bound Check:</b> `N-1` when N=0 causes integer underflow, yielding invalid binary logic.</td>
      <td><b>Explanation:</b> Bitwise AND between N and N-1 naturally flips the lowest set bit to 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeLastSetBit(int n) {&#10;    // Edge Case check for zero underflow&#10;    if (n &lt;= 0) return 0;&#10;    return n &amp; (n - 1);&#10;}</code></pre></details></td>
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
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Bit 06 Count Set Bits<br><br></b> <a href='https://leetcode.com/problems/number-of-1-bits/' target='_blank'>LeetCode 191</a></td>
      <td rowspan="2"><b>Example 1:</b> Input: N=11 (1011), Output: 3<br><br><b>Note (Constraint):</b> 1 &le; N &le; 2<sup>31</sup> - 1</td>
      <td><b>Time:</b> O(32) &cong; O(1) (Trade-off)<br><b>Space:</b> O(1)</td>
      <td>-</td>
      <td><b>Static Loop Iterations:</b> Loop always runs 32 times regardless of number size.</td>
      <td><b>Explanation:</b> Iterate through all 32 bits and check if each is set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeightBrute(uint32_t n) {&#10;    int count = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        if((n &gt;&gt; i) &amp; 1) {&#10;            count++;&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(Set Bits) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Built-in Lib (Alternative):</b><br><code>__builtin_popcount(n)</code></td>
      <td><b>Dynamic Efficiency:</b> Time complexity is tightly bound strictly to the number of 1s, bypassing zeros completely.</td>
      <td><b>Explanation:</b> Brian Kernighan's Algorithm: Strip the lowest set bit using `N & (N-1)` until N reaches 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeightOptimal(uint32_t n) {&#10;    int count = 0;&#10;    while (n != 0) {&#10;        // Strips the rightmost set bit dynamically&#10;        n = n &amp; (n - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">5</td>
      <td rowspan="2">Bit 08 Single Number<br><br></b> <a href='https://leetcode.com/problems/single-number/' target='_blank'>LeetCode 136</a><br><br><b>Variants:</b><br>- What if elements are sorted? (Can use Binary Search `O(log N)` Time).<br>- What if elements are strictly positive? (Can use Array mapping if constraints allow).</td>
      <td rowspan="2"><b>Example 1:</b> Input: nums = [4,1,2,1,2], Output: 4<br><br><b>Note (Constraint):</b> 1 &le; N &le; 3 * 10<sup>4</sup><br>-3 * 10<sup>4</sup> &le; nums[i] &le; 3 * 10<sup>4</sup></td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Trade-off)</td>
      <td><b>Data Structure:</b><br><code>std::unordered_map</code> / <code>dict</code></td>
      <td><b>Memory Heavy:</b> Fails optimal space constraint due to dynamic hash mapping allocation.</td>
      <td><b>Explanation:</b> Use a Hash Map to count occurrences. Return the element with count 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;#include &lt;unordered_map&gt;&#10;&#10;int singleNumberBrute(std::vector&lt;int&gt;&amp; nums) {&#10;    std::unordered_map&lt;int, int&gt; freq;&#10;    for(int num : nums) freq[num]++;&#10;    for(auto it : freq) {&#10;        if(it.second == 1) return it.first;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>-</td>
      <td><b>Commutativity:</b> XOR order doesn't matter, natively eliminating negative numbers constraints seamlessly.</td>
      <td><b>Explanation:</b> XOR all elements. Identical pairs cancel out (A ^ A = 0), leaving only the unique element (0 ^ B = B).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">#include &lt;vector&gt;&#10;&#10;int singleNumberOptimal(std::vector&lt;int&gt;&amp; nums) {&#10;    int xor_res = 0;&#10;    for(int num : nums) {&#10;        xor_res ^= num;&#10;    }&#10;    return xor_res;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
