# Bit Manipulation Revision Table

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
      <td>Bit 01 Swap Two Numbers<br><br></b> <a href="https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1" target="_blank">GeeksforGeeks</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b></b><br><br><b>Input:</b> a=5, b=7<br><b>Output:</b> a=7, b=5<br><br><b></b> 1 &le; a, b &le; 10<sup>9</sup></td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Use basic arithmetic (addition and subtraction) to swap.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void swapArithmetic(int &amp;a, int &amp;b) {&#10;    // Edge Case: Can overflow for massive 32-bit integers&#10;    a = a + b;&#10;    b = a - b;&#10;    a = a - b;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use XOR bitwise operation. XORing a number with itself is 0, and XORing with 0 is the number itself.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; get(int a, int b) {&#10;    a = a ^ b;&#10;    b = a ^ b;&#10;    a = a ^ b;&#10;    return {a, b};&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Bit 02 Check Ith Bit Set<br><br></b> <a href="https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1" target="_blank">GeeksforGeeks</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b></b><br><br><b>Input:</b> N=4 (100 in binary), i=2<br><b>Output:</b> true<br><br><b></b> 1 &le; N &le; 10<sup>9</sup>, 0 &le; i &le; 31</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Right shift N by K times and check if the least significant bit is 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBitRightShift(int n, int k) {&#10;    return ((n &gt;&gt; k) &amp; 1) != 0;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Create a mask by left shifting 1 by K times and check if the bitwise AND with N is non-zero.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool checkKthBit(int n, int k) {&#10;    return (n &amp; (1LL &lt;&lt; k)) != 0;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Bit 03 Operations Set Clear Toggle<br><br></b> <a href="https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1" target="_blank">GeeksforGeeks</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b></b><br>N=70, i=3 -> Set:78, Clear:62, Toggle:78<br><br><b></b> 1 &le; N &le; 10<sup>9</sup></td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use OR (`|`) to set, AND with NOT (`& ~`) to clear, and XOR (`^`) to toggle.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; bitOperations(int n, int i) {&#10;    int setBit = n | (1LL &lt;&lt; i);&#10;    int clearBit = n &amp; ~(1LL &lt;&lt; i);&#10;    int toggleBit = n ^ (1LL &lt;&lt; i);&#10;    return {setBit, clearBit, toggleBit};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Bit 04 Copy Set Bits In Range<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td><b></b><br>X=44, Y=3, L=1, R=5<br><b>Output:</b> 47</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Create a mask of length (R - L + 1) with all 1s. Shift this mask to the left by (L - 1). AND this mask with Y to isolate the bits to be copied. Finally, OR this isolated value with X.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int setSetBit(int x, int y, int l, int r){&#10;    int mask = (1 &lt;&lt; (r - l + 1)) - 1;&#10;    mask = (mask &lt;&lt; (l - 1));&#10;    mask = mask &amp; y;&#10;    return x | mask;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Bit 05 Divide Two Integers<br><br></b> <a href="https://leetcode.com/problems/divide-two-integers/" target="_blank">LeetCode 29</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> dividend = 10, divisor = 3<br><b>Output:</b> 3</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log^2 N)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Iterative subtraction. Subtract divisor from dividend until dividend is smaller than divisor. Count the number of subtractions.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int divideBrute(int dividend, int divisor) {&#10;    if (dividend == INT_MIN &amp;&amp; divisor == -1) return INT_MAX;&#10;    long long a = abs((long long)dividend);&#10;    long long b = abs((long long)divisor);&#10;    int res = 0;&#10;    while(a &gt;= b) {&#10;        a -= b;&#10;        res++;&#10;    }&#10;    return (dividend &gt; 0) == (divisor &gt; 0) ? res : -res;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use left shift to find the largest multiple of divisor that fits into dividend. Subtract it and add the shifted value to quotient. Repeat until dividend < divisor.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int divide(int dividend, int divisor) {&#10;    if(dividend == INT_MIN &amp;&amp; divisor == -1) return INT_MAX;&#10;    long long n = abs(dividend), d = abs(divisor), quotient = 0;&#10;    bool sign = (dividend &lt; 0) == (divisor &lt; 0);&#10;    while(n &gt;= d) {&#10;        long long temp = d, multiple = 1;&#10;        while(n &gt;= (temp &lt;&lt; 1)) {&#10;            temp &lt;&lt;= 1;&#10;            multiple &lt;&lt;= 1;&#10;        }&#10;        n -= temp;&#10;        quotient += multiple;&#10;    }&#10;    return sign ? quotient : -quotient;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Bit 06 Calculate Square<br><br></b> <a href="https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/" target="_blank">GeeksforGeeks</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> n = 5<br><b>Output:</b> 25</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log N)<br><b>Space:</b> O(log N) (Call stack)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Repeated addition. Add `n` to a sum `n` times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int squareBrute(int n) {&#10;    int sum = 0;&#10;    for(int i=0; i&lt;abs(n); i++) sum += abs(n);&#10;    return sum;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> If `n` is even, `n = 2*x`, then `n^2 = 4*x^2 = (x^2) << 2`. If `n` is odd, `n = 2*x + 1`, then `n^2 = 4*x^2 + 4*x + 1 = ((x^2 + x) << 2) + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int square(int n) {&#10;    if(n == 0) return 0;&#10;    if(n &lt; 0) n = -n;&#10;    int x = n &gt;&gt; 1;&#10;    if(n &amp; 1) return ((square(x) &lt;&lt; 2) + (x &lt;&lt; 2) + 1);&#10;    else return (square(x) &lt;&lt; 2);&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Bit 07 Find Position Of Only Set Bit<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> N = 2<br><b>Output:</b> 2</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(32)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(1)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Loop through all 32 bits, count set bits, and record the position. If count is strictly 1, return position, else -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPositionBrute(int N) {&#10;    int count = 0, pos = -1, curr = 1;&#10;    while(N &gt; 0) {&#10;        if(N &amp; 1) {&#10;            count++;&#10;            pos = curr;&#10;        }&#10;        N &gt;&gt;= 1;&#10;        curr++;&#10;    }&#10;    return count == 1 ? pos : -1;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> First, check if `N` is a power of 2 using `N & (N - 1) == 0`. If yes, the position is `log2(N) + 1`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPosition(int N) {&#10;    if(N == 0 || (N &amp; (N - 1)) != 0) return -1;&#10;    return log2(N) + 1;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Bit 08 Count Set Bits<br><br></b> <a href="https://leetcode.com/problems/number-of-1-bits/" target="_blank">LeetCode 191</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b></b><br><br><b>Input:</b> N=11 (1011)<br><b>Output:</b> 3</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(32) &cong; O(1)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(Set Bits)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Iterate through all 32 bits and check if each is set by right shifting N and checking the 0th bit.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeightLoop(uint32_t n) {&#10;    int count = 0;&#10;    while (n) {&#10;        count += (n &amp; 1);&#10;        n &gt;&gt;= 1;&#10;    }&#10;    return count;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use Brian Kernighan's algorithm: `n = n & (n - 1)` unsets the rightmost set bit. Keep doing this until `n` becomes 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int hammingWeight(uint32_t n) {&#10;    int count = 0;&#10;    while (n) {&#10;        n &amp;= (n - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Bit 09 Minimum Bit Flips To Convert Number<br><br></b> <a href="https://leetcode.com/problems/minimum-bit-flips-to-convert-number/" target="_blank">LeetCode 2220</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td><b></b><br><br><b>Input:</b> start=10 (1010), goal=7 (0111)<br><b>Output:</b> 3 flips</td>
      <td><b>Time:</b> O(Set Bits)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> XOR `start` and `goal` to isolate differing bits, then count the set bits in the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minBitFlips(int start, int goal) {&#10;    int xor_res = start ^ goal;&#10;    int count = 0;&#10;    // Brian Kernighan&#x27;s algorithm to count the mismatched bits&#10;    while(xor_res != 0) {&#10;        xor_res = xor_res &amp; (xor_res - 1);&#10;        count++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Bit 10 Single Number<br><br></b> <a href="https://leetcode.com/problems/single-number/" target="_blank">LeetCode 136</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> nums = [4,1,2,1,2]<br><b>Output:</b> 4</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(N)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Use a Hash Map to count occurrences. Return the element with count 1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumberHash(vector&lt;int&gt;&amp; nums) {&#10;    unordered_map&lt;int, int&gt; counts;&#10;    for(int num : nums) counts[num]++;&#10;    for(auto it : counts) {&#10;        if(it.second == 1) return it.first;&#10;    }&#10;    return -1;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use XOR bitwise operation. `X ^ X = 0` and `X ^ 0 = X`. XORing all elements pairs up the duplicates to 0, leaving the single element.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    int ans = 0;&#10;    for(int num : nums) {&#10;        ans ^= num;&#10;    }&#10;    return ans;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Bit 11 Single Number II<br><br></b> <a href="https://leetcode.com/problems/single-number-ii/" target="_blank">LeetCode 137</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> nums = [2,2,3,2]<br><b>Output:</b> 3</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(32 * N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(N)<br><b>Space:</b> O(1)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Count bits: For each bit position, count how many numbers have it set. If count is not divisible by 3, the single number has this bit set.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumberCount(vector&lt;int&gt;&amp; nums) {&#10;    int ans = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        int sum = 0;&#10;        for(int num : nums) {&#10;            if((num &gt;&gt; i) &amp; 1) sum++;&#10;        }&#10;        if(sum % 3 != 0) ans |= (1 &lt;&lt; i);&#10;    }&#10;    return ans;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Use bitmask magic with `ones` and `twos`. `ones` keeps track of bits that appeared exactly once. `twos` tracks bits that appeared exactly twice. When a bit appears 3 times, both `ones` and `twos` are cleared.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    int ones = 0, twos = 0;&#10;    for(int n : nums) {&#10;        ones = (ones ^ n) &amp; ~twos;&#10;        twos = (twos ^ n) &amp; ~ones;&#10;    }&#10;    return ones;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Bit 12 Single Number III<br><br></b> <a href="https://leetcode.com/problems/single-number-iii/" target="_blank">LeetCode 260</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> nums = [1,2,1,3,2,5]<br><b>Output:</b> [3,5]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> XOR all elements to get `x ^ y`. Find the rightmost set bit in this XOR result. This bit distinguishes `x` and `y`. Iterate through array again, divide numbers into two groups based on this bit, and XOR each group. The results are `x` and `y`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; singleNumber(vector&lt;int&gt;&amp; nums) {&#10;    long long xor_all = 0;&#10;    for(int n : nums) xor_all ^= n;&#10;    long long rightmost_set_bit = xor_all &amp; -xor_all;&#10;    int x = 0, y = 0;&#10;    for(int n : nums) {&#10;        if(n &amp; rightmost_set_bit) x ^= n;&#10;        else y ^= n;&#10;    }&#10;    return {x, y};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Bit 13 Subsets<br><br></b> <a href="https://leetcode.com/problems/subsets/" target="_blank">LeetCode 78</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> nums = [1,2,3]<br><b>Output:</b> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * 2^N)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(N * 2^N)<br><b>Space:</b> O(N * 2^N)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Recursive backtracking (include/exclude pattern).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void solve(int idx, vector&lt;int&gt;&amp; nums, vector&lt;int&gt;&amp; curr, vector&lt;vector&lt;int&gt;&gt;&amp; ans) {&#10;    if(idx == nums.size()) {&#10;        ans.push_back(curr);&#10;        return;&#10;    }&#10;    curr.push_back(nums[idx]);&#10;    solve(idx + 1, nums, curr, ans);&#10;    curr.pop_back();&#10;    solve(idx + 1, nums, curr, ans);&#10;}&#10;vector&lt;vector&lt;int&gt;&gt; subsetsRec(vector&lt;int&gt;&amp; nums) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    vector&lt;int&gt; curr;&#10;    solve(0, nums, curr, ans);&#10;    return ans;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Bit manipulation technique. For N elements, there are 2^N subsets. Count from 0 to 2^N - 1. For each number, its binary representation indicates which elements to include.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; subsets(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    int subsetsCount = 1 &lt;&lt; n;&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    for(int i=0; i&lt;subsetsCount; i++) {&#10;        vector&lt;int&gt; subset;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(i &amp; (1 &lt;&lt; j)) subset.push_back(nums[j]);&#10;        }&#10;        ans.push_back(subset);&#10;    }&#10;    return ans;&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Bit 14 Count Total Set Bits 1 To N<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> N=4<br><b>Output:</b> 5<br>Explanation: 1(01) + 2(10) + 3(11) + 4(100) -> 1+1+2+1 = 5</td>
      <td><details><summary><b>Approach 1</b></summary><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</details><details><summary><b>Approach 2</b></summary><b>Time:</b> O(log N)<br><b>Space:</b> O(log N)</details></td>
      <td><details><summary><b>Approach 1</b></summary><b>Explanation:</b> Loop from 1 to N and count set bits using Brian Kernighan's.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countSetBitsBrute(int N) {&#10;    int total = 0;&#10;    for(int i=1; i&lt;=N; i++) {&#10;        int temp = i;&#10;        while(temp) {&#10;            temp &amp;= (temp - 1);&#10;            total++;&#10;        }&#10;    }&#10;    return total;&#10;}</code></pre></details></details><details><summary><b>Approach 2</b></summary><b>Explanation:</b> Find largest power of 2 <= n (`x`). Bits up to `2^x - 1` are `x * 2^(x-1)`. The MSB of remaining numbers is `n - 2^x + 1`. Then recursively call for `n - 2^x`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largestPowerOf2inRange(int n) {&#10;    int x = 0;&#10;    while((1 &lt;&lt; x) &lt;= n) x++;&#10;    return x - 1;&#10;}&#10;int countSetBits(int n) {&#10;    if(n &lt;= 0) return 0;&#10;    int x = largestPowerOf2inRange(n);&#10;    int bitsUpTo2x = x * (1 &lt;&lt; (x - 1));&#10;    int msbOfRest = n - (1 &lt;&lt; x) + 1;&#10;    int rest = n - (1 &lt;&lt; x);&#10;    return bitsUpTo2x + msbOfRest + countSetBits(rest);&#10;}</code></pre></details></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Bit 15 Find The Original Array Of Prefix Xor<br><br></b> <a href="https://leetcode.com/problems/find-the-original-array-of-prefix-xor/" target="_blank">LeetCode 2433</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b> `pref = [5,2,0,3,1]`.<br><b>Output:</b> `[5,7,2,3,2]`.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Since `pref[i] = pref[i-1] ^ arr[i]`, we can find `arr[i]` by doing `pref[i-1] ^ pref[i]`. `arr[0] = pref[0]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findArray(vector&lt;int&gt;&amp; pref) {&#10;    vector&lt;int&gt; arr(pref.size());&#10;    arr[0] = pref[0];&#10;    for(int i=1; i&lt;pref.size(); i++) {&#10;        arr[i] = pref[i-1] ^ pref[i];&#10;    }&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Bit 16 Maximum Xor For Each Query<br><br></b> <a href="https://leetcode.com/problems/maximum-xor-for-each-query/" target="_blank">LeetCode 1829</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b> `nums = [0,1,1,3], maximumBit = 2`.<br><b>Output:</b> `[0,3,2,3]`.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> The maximum possible value is `(1 << maximumBit) - 1`. If current running XOR is `curr`, we want `k` such that `curr ^ k = max_val`. Thus `k = curr ^ max_val`. Do this iteratively backwards.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; getMaximumXor(vector&lt;int&gt;&amp; nums, int maximumBit) {&#10;    int curr = 0;&#10;    for(int n : nums) curr ^= n;&#10;    int max_val = (1 &lt;&lt; maximumBit) - 1;&#10;    vector&lt;int&gt; ans;&#10;    for(int i=nums.size()-1; i&gt;=0; i--) {&#10;        ans.push_back(curr ^ max_val);&#10;        curr ^= nums[i];&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>17</td>
      <td>Bit 17 Minimum Flips To Make A Or B Equal To C<br><br></b> <a href="https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/" target="_blank">LeetCode 1318</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> a=2, b=6, c=5<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(1)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Iterate through 32 bits. If bit in `c` is 1, at least one of `a` or `b` needs to be 1. If both are 0, flip one (1 flip). If bit in `c` is 0, both `a` and `b` must be 0. Flips needed = bit of `a` + bit of `b`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int minFlips(int a, int b, int c) {&#10;    int flips = 0;&#10;    for(int i=0; i&lt;32; i++) {&#10;        int bit_a = (a &gt;&gt; i) &amp; 1;&#10;        int bit_b = (b &gt;&gt; i) &amp; 1;&#10;        int bit_c = (c &gt;&gt; i) &amp; 1;&#10;        if(bit_c == 1) {&#10;            if(bit_a == 0 &amp;&amp; bit_b == 0) flips += 1;&#10;        } else {&#10;            flips += bit_a + bit_b;&#10;        }&#10;    }&#10;    return flips;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>18</td>
      <td>Bit 18 Number Of Steps To Reduce To Zero<br><br></b> <a href="https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/" target="_blank">LeetCode 1342</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> num = 14<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(log N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> If `num` is odd, subtract 1 (equivalent to clearing rightmost bit). If even, divide by 2 (equivalent to right shift).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfSteps(int num) {&#10;    if(num == 0) return 0;&#10;    int steps = 0;&#10;    while(num &gt; 0) {&#10;        if(num &amp; 1) num--;&#10;        else num &gt;&gt;= 1;&#10;        steps++;&#10;    }&#10;    return steps;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>19</td>
      <td>Bit 19 Decode Xored Array<br><br></b> <a href="https://leetcode.com/problems/decode-xored-array/" target="_blank">LeetCode 1720</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> encoded=[1,2,3], first=1<br><b>Output:</b> [1,0,2,1]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Since `encoded[i] = arr[i] ^ arr[i+1]`, it implies `arr[i+1] = arr[i] ^ encoded[i]`. We have `arr[0]`, so we can iteratively find the rest.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; decode(vector&lt;int&gt;&amp; encoded, int first) {&#10;    vector&lt;int&gt; arr(encoded.size() + 1);&#10;    arr[0] = first;&#10;    for(int i=0; i&lt;encoded.size(); i++) {&#10;        arr[i+1] = arr[i] ^ encoded[i];&#10;    }&#10;    return arr;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>20</td>
      <td>Bit 20 Longest Substring Vowels Even Counts<br><br></b> <a href="https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/" target="_blank">LeetCode 1371</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> s = "eleetminicoworoep"<br><b>Output:</b> 13</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(32) since only 5 bits used</td>
      <td><b>Explanation:</b> Use a 5-bit mask to represent the parity of counts for 'a','e','i','o','u'. If we encounter a vowel, flip its bit. If the same mask is seen again at index `i` (was previously seen at `j`), then the substring `s[j+1...i]` has even vowel counts. Use a hash map to store first occurrence of each mask.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findTheLongestSubstring(string s) {&#10;    unordered_map&lt;int, int&gt; m;&#10;    m[0] = -1;&#10;    int mask = 0, maxLen = 0;&#10;    for(int i=0; i&lt;s.length(); i++) {&#10;        if(s[i] == &#x27;a&#x27;) mask ^= (1 &lt;&lt; 0);&#10;        else if(s[i] == &#x27;e&#x27;) mask ^= (1 &lt;&lt; 1);&#10;        else if(s[i] == &#x27;i&#x27;) mask ^= (1 &lt;&lt; 2);&#10;        else if(s[i] == &#x27;o&#x27;) mask ^= (1 &lt;&lt; 3);&#10;        else if(s[i] == &#x27;u&#x27;) mask ^= (1 &lt;&lt; 4);&#10;        if(m.count(mask)) {&#10;            maxLen = max(maxLen, i - m[mask]);&#10;        } else {&#10;            m[mask] = i;&#10;        }&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>21</td>
      <td>Bit 21 Xor Queries Of A Subarray<br><br></b> <a href="https://leetcode.com/problems/xor-queries-of-a-subarray/" target="_blank">LeetCode 1310</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar</details></td>
      <td><b></b><br><br><b>Input:</b> arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]<br><b>Output:</b> [2,7,14,8]</td>
      <td><b>Time:</b> O(N + Q)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Create a prefix XOR array. Query answer for `[L, R]` is `prefix[R] ^ prefix[L-1]`. If `L == 0`, answer is `prefix[R]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; xorQueries(vector&lt;int&gt;&amp; arr, vector&lt;vector&lt;int&gt;&gt;&amp; queries) {&#10;    vector&lt;int&gt; pref(arr.size());&#10;    pref[0] = arr[0];&#10;    for(int i=1; i&lt;arr.size(); i++) pref[i] = pref[i-1] ^ arr[i];&#10;    vector&lt;int&gt; ans;&#10;    for(auto q : queries) {&#10;        if(q[0] == 0) ans.push_back(pref[q[1]]);&#10;        else ans.push_back(pref[q[1]] ^ pref[q[0]-1]);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
