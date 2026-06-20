# Step 10 Sliding Window Revision Table

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
      <td>Sw 01 Longest Substring Without Repeating Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-without-repeating-characters/" target="_blank">LeetCode 3</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Input: s = "abcabcbb", Output: 3 ("abc")</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(min(N, M))</td>
      <td><b>Explanation:</b> Sliding window with a Hash Map storing the latest index of each character. Move `left` pointer to `max(left, map[char] + 1)`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstring(std::string s) {&#10;    std::vector&lt;int&gt; mpp(256, -1);&#10;    int left = 0, right = 0, max_len = 0;&#10;    while(right &lt; s.length()) {&#10;        if(mpp[s[right]] != -1) {&#10;            left = std::max(left, mpp[s[right]] + 1);&#10;        }&#10;        mpp[s[right]] = right;&#10;        max_len = std::max(max_len, right - left + 1);&#10;        right++;&#10;    }&#10;    return max_len;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>2</td>
      <td>Sw 02 Trapping Rain Water<br><br></b> <a href="https://leetcode.com/problems/trapping-rain-water/" target="_blank">LeetCode 42</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, Love Babbar, SDE Sheet</details></td>
      <td>**Example 1:** Input: height = [0,1,0,2,1,0,1,3,2,1,2,1], Output: 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Two pointers `left` and `right`. Maintain `left_max` and `right_max`. Move the pointer pointing to the smaller max, adding trapped water.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int trap(std::vector&lt;int&gt;&amp; height) {&#10;    int n = height.size();&#10;    int left = 0, right = n - 1;&#10;    int res = 0, maxLeft = 0, maxRight = 0;&#10;    while (left &lt;= right) {&#10;        if (height[left] &lt;= height[right]) {&#10;            if (height[left] &gt;= maxLeft) maxLeft = height[left];&#10;            else res += maxLeft - height[left];&#10;            left++;&#10;        } else {&#10;            if (height[right] &gt;= maxRight) maxRight = height[right];&#10;            else res += maxRight - height[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>3</td>
      <td>Sw 03 Container With Most Water<br><br></b> <a href="https://leetcode.com/problems/container-with-most-water/" target="_blank">LeetCode 11</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Input: height = [1,8,6,2,5,4,8,3,7], Output: 49</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Two Pointers from ends. Area is `min(h[left], h[right]) * width`. Move the pointer with the smaller height to seek a potentially taller line.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxArea(std::vector&lt;int&gt;&amp; height) {&#10;    int left = 0, right = height.size() - 1;&#10;    int max_area = 0;&#10;    while(left &lt; right) {&#10;        int area = std::min(height[left], height[right]) * (right - left);&#10;        max_area = std::max(max_area, area);&#10;        if(height[left] &lt; height[right]) left++;&#10;        else right--;&#10;    }&#10;    return max_area;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>4</td>
      <td>Sw 04 Minimum Window Substring<br><br></b> <a href="https://leetcode.com/problems/minimum-window-substring/" target="_blank">LeetCode 76</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Variable sliding window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Maintain a frequency map of `t`. Expand the window by moving `right`. When the window contains all characters of `t`, try to shrink it by moving `left` to find the minimum window. Keep track of the minimum window length and its starting index.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">string minWindow(string s, string t) {&#10;    if(s.length() &lt; t.length()) return &quot;&quot;;&#10;    vector&lt;int&gt; count(128, 0);&#10;    for(char c : t) count[c]++;&#10;    int l = 0, r = 0, minLen = INT_MAX, minStart = 0, required = t.length();&#10;    while(r &lt; s.length()) {&#10;        if(count[s[r]] &gt; 0) required--;&#10;        count[s[r]]--;&#10;        r++;&#10;        while(required == 0) {&#10;            if(r - l &lt; minLen) {&#10;                minLen = r - l;&#10;                minStart = l;&#10;            }&#10;            count[s[l]]++;&#10;            if(count[s[l]] &gt; 0) required++;&#10;            l++;&#10;        }&#10;    }&#10;    return minLen == INT_MAX ? &quot;&quot; : s.substr(minStart, minLen);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>5</td>
      <td>Sw 05 Sliding Window Maximum<br><br></b> <a href="https://leetcode.com/problems/sliding-window-maximum/" target="_blank">LeetCode 239</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Apna College, Striver A Z, SDE Sheet</details></td>
      <td>**Example 1:** Deque.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Use a deque to store indices. The deque maintains elements in decreasing order. Remove elements from the back if they are smaller than the current element. Remove elements from the front if they are out of the window. The front element is the maximum of the current window.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; maxSlidingWindow(vector&lt;int&gt;&amp; nums, int k) {&#10;    vector&lt;int&gt; res;&#10;    deque&lt;int&gt; dq;&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        if(!dq.empty() &amp;&amp; dq.front() == i - k) dq.pop_front();&#10;        while(!dq.empty() &amp;&amp; nums[dq.back()] &lt;= nums[i]) dq.pop_back();&#10;        dq.push_back(i);&#10;        if(i &gt;= k - 1) res.push_back(nums[dq.front()]);&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>6</td>
      <td>Sw 06 Longest K Unique Characters Substring<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1" target="_blank">GFG</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Variable window and hash map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Maintain a hash map of character frequencies. Expand the window by moving `j`. If the number of unique characters exceeds `k`, shrink the window from the left (`i`) until the number of unique characters is `k`. Update the maximum length when exactly `k` unique characters are present.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestKSubstr(string s, int k) {&#10;    unordered_map&lt;char, int&gt; count;&#10;    int i = 0, j = 0, maxLen = -1;&#10;    while(j &lt; s.length()) {&#10;        count[s[j]]++;&#10;        if(count.size() == k) maxLen = max(maxLen, j - i + 1);&#10;        else if(count.size() &gt; k) {&#10;            while(count.size() &gt; k) {&#10;                count[s[i]]--;&#10;                if(count[s[i]] == 0) count.erase(s[i]);&#10;                i++;&#10;            }&#10;        }&#10;        j++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>7</td>
      <td>Sw 07 Subarrays With K Different Integers<br><br></b> <a href="https://leetcode.com/problems/subarrays-with-k-different-integers/" target="_blank">LeetCode 992</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Exact K = atMost(K) - atMost(K-1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Explanation:</b> Finding exact `k` distinct is hard directly. Instead, find subarrays with at most `k` distinct integers. The number of exact `k` is `atMost(k) - atMost(k - 1)`. The `atMost` function uses a sliding window.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int res = 0, i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(count[nums[j]] == 0) k--;&#10;        count[nums[j]]++;&#10;        while(k &lt; 0) {&#10;            count[nums[i]]--;&#10;            if(count[nums[i]] == 0) k++;&#10;            i++;&#10;        }&#10;        res += j - i + 1;&#10;    }&#10;    return res;&#10;}&#10;int subarraysWithKDistinct(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>8</td>
      <td>Sw 08 Fruits Into Baskets<br><br></b> <a href="https://leetcode.com/problems/fruit-into-baskets/" target="_blank">LeetCode 904</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Longest subarray with at most 2 distinct elements.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1) (at most 3 elements in map)</td>
      <td><b>Explanation:</b> This translates to finding the longest subarray with at most 2 distinct elements. Maintain a frequency map and use a sliding window. If distinct elements > 2, shrink the window until distinct elements <= 2.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int totalFruit(vector&lt;int&gt;&amp; fruits) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    int l = 0, maxFruits = 0;&#10;    for(int r = 0; r &lt; fruits.size(); r++) {&#10;        count[fruits[r]]++;&#10;        while(count.size() &gt; 2) {&#10;            count[fruits[l]]--;&#10;            if(count[fruits[l]] == 0) count.erase(fruits[l]);&#10;            l++;&#10;        }&#10;        maxFruits = max(maxFruits, r - l + 1);&#10;    }&#10;    return maxFruits;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>9</td>
      <td>Sw 09 Max Consecutive Ones Iii<br><br></b> <a href="https://leetcode.com/problems/max-consecutive-ones-iii/" target="_blank">LeetCode 1004</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a sliding window. Expand the right pointer. If the element is 0, increment a zero counter. While the zero counter > k, shrink the window from the left by moving the left pointer and decrementing the zero counter if left element is 0. The max window size is the answer.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int longestOnes(vector&lt;int&gt;&amp; nums, int k) {&#10;    int left = 0, right = 0, zeroes = 0, maxLen = 0;&#10;    while(right &lt; nums.size()) {&#10;        if(nums[right] == 0) zeroes++;&#10;        while(zeroes &gt; k) {&#10;            if(nums[left] == 0) zeroes--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>10</td>
      <td>Sw 10 Longest Repeating Character Replacement<br><br></b> <a href="https://leetcode.com/problems/longest-repeating-character-replacement/" target="_blank">LeetCode 424</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Sliding Window + Max Freq.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use a sliding window. Maintain the character frequencies and the `max_freq` in the window. The number of replacements needed is `window_size - max_freq`. If this is > k, shrink the window from left and decrement the corresponding frequency.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int characterReplacement(string s, int k) {&#10;    vector&lt;int&gt; count(26, 0);&#10;    int left = 0, maxFreq = 0, maxLen = 0;&#10;    for(int right = 0; right &lt; s.length(); right++) {&#10;        count[s[right] - &#x27;A&#x27;]++;&#10;        maxFreq = max(maxFreq, count[s[right] - &#x27;A&#x27;]);&#10;        if((right - left + 1) - maxFreq &gt; k) {&#10;            count[s[left] - &#x27;A&#x27;]--;&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>11</td>
      <td>Sw 11 Binary Subarrays With Sum<br><br></b> <a href="https://leetcode.com/problems/binary-subarrays-with-sum/" target="_blank">LeetCode 930</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** atMost(goal) - atMost(goal - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Use the helper function `atMost(goal)` which finds the number of subarrays with sum <= goal. The answer is `atMost(goal) - atMost(goal - 1)`. In `atMost`, use a sliding window to maintain the sum.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int goal) {&#10;    if(goal &lt; 0) return 0;&#10;    int left = 0, sum = 0, count = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        sum += nums[right];&#10;        while(sum &gt; goal) {&#10;            sum -= nums[left++];&#10;        }&#10;        count += (right - left + 1);&#10;    }&#10;    return count;&#10;}&#10;int numSubarraysWithSum(vector&lt;int&gt;&amp; nums, int goal) {&#10;    return atMost(nums, goal) - atMost(nums, goal - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>12</td>
      <td>Sw 12 Count Number Of Nice Subarrays<br><br></b> <a href="https://leetcode.com/problems/count-number-of-nice-subarrays/" target="_blank">LeetCode 1248</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** atMost(k) - atMost(k - 1).</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Replace all odd numbers with 1 and even numbers with 0. The problem then reduces to finding the number of subarrays with a sum equal to k. Use the `atMost(k) - atMost(k - 1)` sliding window approach.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int atMost(vector&lt;int&gt;&amp; nums, int k) {&#10;    if(k &lt; 0) return 0;&#10;    int left = 0, count = 0, res = 0;&#10;    for(int right = 0; right &lt; nums.size(); right++) {&#10;        if(nums[right] % 2 != 0) count++;&#10;        while(count &gt; k) {&#10;            if(nums[left] % 2 != 0) count--;&#10;            left++;&#10;        }&#10;        res += (right - left + 1);&#10;    }&#10;    return res;&#10;}&#10;int numberOfSubarrays(vector&lt;int&gt;&amp; nums, int k) {&#10;    return atMost(nums, k) - atMost(nums, k - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>13</td>
      <td>Sw 13 Number Of Substrings Containing All Three Characters<br><br></b> <a href="https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/" target="_blank">LeetCode 1358</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Store last seen indices.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Iterate through the string. Track the last seen indices of 'a', 'b', and 'c'. If all three have been seen, the number of valid substrings ending at the current index `i` is `1 + min(last_a, last_b, last_c)`. Add this to the total count.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int numberOfSubstrings(string s) {&#10;    int last[3] = {-1, -1, -1};&#10;    int count = 0;&#10;    for(int i = 0; i &lt; s.length(); i++) {&#10;        last[s[i] - &#x27;a&#x27;] = i;&#10;        if(last[0] != -1 &amp;&amp; last[1] != -1 &amp;&amp; last[2] != -1) {&#10;            count += (1 + min({last[0], last[1], last[2]}));&#10;        }&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>14</td>
      <td>Sw 14 Maximum Points You Can Obtain From Cards<br><br></b> <a href="https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/" target="_blank">LeetCode 1423</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Sliding Window on remaining cards.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Instead of picking cards from the ends, find the subarray of length `N - K` that has the minimum sum. Subtract this minimum sum from the total sum of the array. That gives the maximum score.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxScore(vector&lt;int&gt;&amp; cardPoints, int k) {&#10;    int n = cardPoints.size();&#10;    int totalSum = 0, windowSum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        totalSum += cardPoints[i];&#10;        if(i &lt; n - k) windowSum += cardPoints[i];&#10;    }&#10;    int minWindowSum = windowSum;&#10;    for(int i = n - k; i &lt; n; i++) {&#10;        windowSum += cardPoints[i] - cardPoints[i - (n - k)];&#10;        minWindowSum = min(minWindowSum, windowSum);&#10;    }&#10;    return totalSum - minWindowSum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>15</td>
      <td>Sw 15 Find All Anagrams In A String<br><br></b> <a href="https://leetcode.com/problems/find-all-anagrams-in-a-string/" target="_blank">LeetCode 438</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Love Babbar, Striver A Z</details></td>
      <td>**Example 1:** Fixed Window + Hash Map.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td><b>Explanation:</b> Create frequency arrays for `p` and a window of size `p.length()` in `s`. Slide the window across `s`, updating the window frequencies. If the arrays match, add the window's start index to the result.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findAnagrams(string s, string p) {&#10;    vector&lt;int&gt; ans;&#10;    if(p.length() &gt; s.length()) return ans;&#10;    vector&lt;int&gt; countP(26, 0), countS(26, 0);&#10;    for(int i = 0; i &lt; p.length(); i++) {&#10;        countP[p[i] - &#x27;a&#x27;]++;&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;    }&#10;    if(countP == countS) ans.push_back(0);&#10;    for(int i = p.length(); i &lt; s.length(); i++) {&#10;        countS[s[i] - &#x27;a&#x27;]++;&#10;        countS[s[i - p.length()] - &#x27;a&#x27;]--;&#10;        if(countP == countS) ans.push_back(i - p.length() + 1);&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td>16</td>
      <td>Sw 16 Longest Substring With At Most K Distinct Characters<br><br></b> <a href="https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/" target="_blank">LeetCode 340</a><br><br><details><summary>ℹ️</summary><b>Tags:</b> Striver A Z</details></td>
      <td>**Example 1:** Sliding Window.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(K)</td>
      <td><b>Explanation:</b> Sliding window with hash map to count characters. While map size > k, shrink window from left.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lengthOfLongestSubstringKDistinct(string s, int k) {&#10;    unordered_map&lt;char, int&gt; m;&#10;    int left = 0, right = 0, maxLen = 0;&#10;    while(right &lt; s.length()) {&#10;        m[s[right]]++;&#10;        while(m.size() &gt; k) {&#10;            m[s[left]]--;&#10;            if(m[s[left]] == 0) m.erase(s[left]);&#10;            left++;&#10;        }&#10;        maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
