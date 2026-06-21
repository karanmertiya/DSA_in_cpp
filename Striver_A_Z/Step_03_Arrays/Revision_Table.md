# Step 03 Arrays Revision Table

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
      <td rowspan="2">1</td>
      <td rowspan="2">Arr 01 Largest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/largest-element-in-array/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> A = [1, 8, 7, 56, 90]<br><b>Output:</b> 90</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1) or O(N) depending on sort</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array and return the last element.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    std::sort(arr.begin(), arr.end());&#10;    return arr.back();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Iterate through the array maintaining a variable for the maximum element seen so far.</td>
      <td><b>Edge Cases:</b> <b>Initialization:</b> Initialize `max_val` with the first element or negative infinity.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int max_val = arr[0];&#10;    for (int i = 1; i &lt; arr.size(); i++) {&#10;        if (arr[i] &gt; max_val) {&#10;            max_val = arr[i];&#10;        }&#10;    }&#10;    return max_val;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">2</td>
      <td rowspan="2">Arr 02 Second Largest Element<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/second-largest3735/1" target="_blank">GFG</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> arr = [12, 35, 1, 10, 34, 1]<br><b>Output:</b> 34<br><br><b> </b> Find it in a single pass O(N) time.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Sort the array, then iterate from the back to find the first element smaller than the largest.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int print2largest(int arr[], int n) {&#10;    std::sort(arr, arr+n);&#10;    for(int i=n-2; i&gt;=0; i--) {&#10;        if(arr[i] != arr[n-1]) return arr[i];&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Maintain two variables, `largest` and `second_largest`. Update them simultaneously during a single pass.</td>
      <td><b>Edge Cases:</b> <b>No Second Largest:</b> If all elements are same or array size < 2, return -1.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int print2largest(std::vector&lt;int&gt; &amp;arr) {&#10;    int largest = -1, second_largest = -1;&#10;    for (int num : arr) {&#10;        if (num &gt; largest) {&#10;            second_largest = largest;&#10;            largest = num;&#10;        } else if (num &gt; second_largest &amp;&amp; num != largest) {&#10;            second_largest = num;&#10;        }&#10;    }&#10;    return second_largest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">3</td>
      <td rowspan="1">Arr 03 Check If Array Is Sorted And Rotated<br><br></b> <a href="https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/" target="_blank">LeetCode 1752</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,4,5,1,2]<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Count the number of "breaks" where `nums[i] > nums[i+1]`. For a sorted and rotated array, there can be at most 1 break.</td>
      <td><b>Edge Cases:</b> <b>Circular Check:</b> We must also check the boundary between the last and first element `nums[n-1] > nums[0]`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool check(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, n = nums.size();&#10;    for (int i = 0; i &lt; n; i++) {&#10;        if (nums[i] &gt; nums[(i + 1) % n]) {&#10;            count++;&#10;        }&#10;    }&#10;    return count &lt;= 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">4</td>
      <td rowspan="2">Arr 04 Remove Duplicates From Sorted Array<br><br></b> <a href="https://leetcode.com/problems/remove-duplicates-from-sorted-array/" target="_blank">LeetCode 26</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,1,2]<br><b>Output:</b> 2, nums = [1,2,_]</td>
      <td><b>Time:</b> O(N log N) or O(N)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use a HashSet to store unique elements, then put them back into the array.<br><br><b>Dependencies:</b> std::set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeDuplicates(vector&lt;int&gt;&amp; nums) {&#10;    set&lt;int&gt; s;&#10;    for(int x : nums) s.insert(x);&#10;    int i = 0;&#10;    for(int x : s) nums[i++] = x;&#10;    return s.size();&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Two-pointer approach. Pointer `i` keeps track of unique elements, pointer `j` scans the array to find new unique elements.</td>
      <td><b>Edge Cases:</b> <b>Empty Array:</b> Handled automatically if `n=0`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int removeDuplicates(std::vector&lt;int&gt;&amp; nums) {&#10;    if (nums.empty()) return 0;&#10;    int i = 0;&#10;    for (int j = 1; j &lt; nums.size(); j++) {&#10;        if (nums[j] != nums[i]) {&#10;            i++;&#10;            nums[i] = nums[j];&#10;        }&#10;    }&#10;    return i + 1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">5</td>
      <td rowspan="2">Arr 05 Rotate Array<br><br></b> <a href="https://leetcode.com/problems/rotate-array/" target="_blank">LeetCode 189</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [1,2,3,4,5,6,7], k = 3<br><b>Output:</b> [5,6,7,1,2,3,4]</td>
      <td><b>Time:</b> O(N * K) or O(N)<br><b>Space:</b> O(1) or O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Rotate the array one by one, k times. Or use a temporary array of size N.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    vector&lt;int&gt; temp(n);&#10;    for(int i=0; i&lt;n; i++) {&#10;        temp[(i+k)%n] = nums[i];&#10;    }&#10;    nums = temp;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Reverse Algorithm. Reverse the whole array, then reverse the first `k` elements, then reverse the remaining `N-k` elements.<br><br><b>Dependencies:</b> <code>std::reverse</code></td>
      <td><b>Edge Cases:</b> <b>K > N:</b> k might be greater than array length, so perform `k = k % n` first.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(std::vector&lt;int&gt;&amp; nums, int k) {&#10;    int n = nums.size();&#10;    k = k % n;&#10;    std::reverse(nums.begin(), nums.end());&#10;    std::reverse(nums.begin(), nums.begin() + k);&#10;    std::reverse(nums.begin() + k, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">6</td>
      <td rowspan="1">Arr 06 Move Zeroes<br><br></b> <a href="https://leetcode.com/problems/move-zeroes/" target="_blank">LeetCode 283</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [0,1,0,3,12]<br><b>Output:</b> [1,3,12,0,0]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Two-pointer approach (Snowball method). Pointer `i` tracks the first zero found, pointer `j` scans for non-zeroes to swap.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>No zeroes:</b> Swaps element with itself initially, no overhead.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void moveZeroes(std::vector&lt;int&gt;&amp; nums) {&#10;    int i = 0;&#10;    for(int j = 0; j &lt; nums.size(); j++) {&#10;        if(nums[j] != 0) {&#10;            std::swap(nums[i], nums[j]);&#10;            i++;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">7</td>
      <td rowspan="2">Arr 07 Missing Number<br><br></b> <a href="https://leetcode.com/problems/missing-number/" target="_blank">LeetCode 268</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [3,0,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Linear search for each number from 0 to N inside the array.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(vector&lt;int&gt;&amp; nums) {&#10;    for(int i=0; i&lt;=nums.size(); i++) {&#10;        bool found = false;&#10;        for(int x : nums) {&#10;            if(x == i) found = true;&#10;        }&#10;        if(!found) return i;&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Using XOR: XORing a number with itself results in 0. XOR all indices `[0,n]` and all elements in `nums`. The missing number will remain.</td>
      <td><b>Edge Cases:</b> <b>Mathematical Sum alternative:</b> Gaussian sum formula `N*(N+1)/2` can cause integer overflow, XOR completely bypasses overflow risks.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(std::vector&lt;int&gt;&amp; nums) {&#10;    int res = nums.size();&#10;    for(int i = 0; i &lt; nums.size(); i++) {&#10;        res ^= i ^ nums[i];&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">8</td>
      <td rowspan="1">Arr 08 Max Consecutive Ones<br><br></b> <a href="https://leetcode.com/problems/max-consecutive-ones/" target="_blank">LeetCode 485</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,1,0,1,1,1]<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate while counting 1s. If a 0 is found, update max count and reset current count to 0.<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>Trailing Ones:</b> Must perform a final max check outside the loop or update max dynamically inside.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findMaxConsecutiveOnes(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_cnt = 0, current_cnt = 0;&#10;    for(int num : nums) {&#10;        if(num == 1) {&#10;            current_cnt++;&#10;            max_cnt = std::max(max_cnt, current_cnt);&#10;        } else {&#10;            current_cnt = 0;&#10;        }&#10;    }&#10;    return max_cnt;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">9</td>
      <td rowspan="2">Arr 09 Sort Colors Dnf<br><br></b> <a href="https://leetcode.com/problems/sort-colors/" target="_blank">LeetCode 75</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [2,0,2,1,1,0]<br><b>Output:</b> [0,0,1,1,2,2]<br><br><b> </b> Do not use library sort. Use single pass.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use any standard sorting algorithm like Merge Sort.<br><br><b>Dependencies:</b> std::sort</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortColors(vector&lt;int&gt;&amp; nums) {&#10;    sort(nums.begin(), nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Dutch National Flag Algorithm (3 pointers). `low` tracks 0s, `mid` scans array, `high` tracks 2s. Swap elements to maintain sections.<br><br><b>Dependencies:</b> <code>std::swap</code></td>
      <td><b>Edge Cases:</b> <b>Mid pointer increment:</b> When swapping with `high`, we do NOT increment `mid` because the swapped element from `high` needs to be evaluated.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void sortColors(std::vector&lt;int&gt;&amp; nums) {&#10;    int low = 0, mid = 0, high = nums.size() - 1;&#10;    while (mid &lt;= high) {&#10;        if (nums[mid] == 0) {&#10;            std::swap(nums[low], nums[mid]);&#10;            low++; mid++;&#10;        } else if (nums[mid] == 1) {&#10;            mid++;&#10;        } else {&#10;            std::swap(nums[mid], nums[high]);&#10;            high--;&#10;        }&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">10</td>
      <td rowspan="2">Arr 10 Majority Element<br><br></b> <a href="https://leetcode.com/problems/majority-element/" target="_blank">LeetCode 169</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [2,2,1,1,1,2,2]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Use two nested loops to count occurrences of each element.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        int cnt = 0;&#10;        for(int j=0; j&lt;n; j++) {&#10;            if(nums[j] == nums[i]) cnt++;&#10;        }&#10;        if(cnt &gt; n/2) return nums[i];&#10;    }&#10;    return -1;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 2:</b><br>Optimal: Moore's Voting Algorithm. Track a candidate and a counter. Increment if same as candidate, decrement if different. If zero, pick new candidate.</td>
      <td><b>Edge Cases:</b> <b>Verification phase:</b> If it's not guaranteed a majority exists, a second `O(N)` pass is required to count the candidate. (Leetcode guarantees it exists).<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int count = 0, candidate = 0;&#10;    for (int num : nums) {&#10;        if (count == 0) candidate = num;&#10;        if (num == candidate) count++;&#10;        else count--;&#10;    }&#10;    return candidate;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="2">11</td>
      <td rowspan="2">Arr 11 Kadanes Algorithm Max Subarray Sum<br><br></b> <a href="https://leetcode.com/problems/maximum-subarray/" target="_blank">LeetCode 53</a></td>
      <td rowspan="2"><b> </b> <br><b>Input:</b> nums = [-2,1,-3,4,-1,2,1,-5,4]<br><b>Output:</b> 6 (Subarray [4,-1,2,1])</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1)</td>
      <td><b>Approach 1:</b><br>Brute Force: Generate all possible subarrays using three nested loops and find the maximum sum.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubArray(vector&lt;int&gt;&amp; nums) {&#10;    int maxi = INT_MIN;&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=i; j&lt;n; j++) {&#10;            int sum = 0;&#10;            for(int k=i; k&lt;=j; k++) sum += nums[k];&#10;            maxi = max(maxi, sum);&#10;        }&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td><b>Approach 2:</b><br>Optimal: Kadane's Algorithm. Keep a running sum. If sum becomes negative, reset it to 0 (a negative prefix will never help a future subarray).<br><br><b>Dependencies:</b> <code>std::max</code></td>
      <td><b>Edge Cases:</b> <b>All Negative Numbers:</b> Initialize `max_sum` with `INT_MIN` or `nums[0]` so it can correctly return the smallest negative number instead of 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxSubArray(std::vector&lt;int&gt;&amp; nums) {&#10;    int max_sum = INT_MIN;&#10;    int current_sum = 0;&#10;    for(int num : nums) {&#10;        current_sum += num;&#10;        max_sum = std::max(max_sum, current_sum);&#10;        if(current_sum &lt; 0) current_sum = 0;&#10;    }&#10;    return max_sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">12</td>
      <td rowspan="1">Arr 12 Best Time To Buy And Sell Stock<br><br></b> <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/" target="_blank">LeetCode 121</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> prices = [7,1,5,3,6,4]<br><b>Output:</b> 5</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate while keeping track of the minimum price seen so far. Subtract this min from the current price to find potential profit.<br><br><b>Dependencies:</b> <code>std::max</code>, <code>std::min</code></td>
      <td><b>Edge Cases:</b> <b>No Profit Possible:</b> `max_profit` initializes at 0. If price strictly decreases, it never updates and naturally returns 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProfit(std::vector&lt;int&gt;&amp; prices) {&#10;    int min_price = prices[0];&#10;    int max_profit = 0;&#10;    for(int i = 1; i &lt; prices.size(); i++) {&#10;        max_profit = std::max(max_profit, prices[i] - min_price);&#10;        min_price = std::min(min_price, prices[i]);&#10;    }&#10;    return max_profit;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">13</td>
      <td rowspan="1">Arr 13 Rearrange Array Elements By Sign<br><br></b> <a href="https://leetcode.com/problems/rearrange-array-elements-by-sign/" target="_blank">LeetCode 2149</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,1,-2,-5,2,-4]<br><b>Output:</b> [3,-2,1,-5,2,-4]<br><br><b> </b> Maintain relative order.</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(N) (Constraint)</td>
      <td>Optimal: Use two pointers, `pos_idx` starting at 0, `neg_idx` starting at 1. Traverse and place elements directly into a new result array.</td>
      <td><b>Edge Cases:</b> <b>In-Place Attempt:</b> Doing this in-place `O(1)` space while maintaining relative order drops Time to `O(N^2)`. The optimal tradeoff is `O(N)` space.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; rearrangeArray(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;int&gt; ans(nums.size());&#10;    int pos_idx = 0, neg_idx = 1;&#10;    for (int num : nums) {&#10;        if (num &gt; 0) {&#10;            ans[pos_idx] = num;&#10;            pos_idx += 2;&#10;        } else {&#10;            ans[neg_idx] = num;&#10;            neg_idx += 2;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">14</td>
      <td rowspan="1">Arr 14 Next Permutation<br><br></b> <a href="https://leetcode.com/problems/next-permutation/" target="_blank">LeetCode 31</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,2,3]<br><b>Output:</b> [1,3,2]<br><b> </b> <br><b>Input:</b> nums = [3,2,1]<br><b>Output:</b> [1,2,3]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: 1. Find break point (i) where arr[i] < arr[i+1]. 2. Swap it with smallest element > arr[i] from the back. 3. Reverse the right half.<br><br><b>Dependencies:</b> <code>std::reverse</code></td>
      <td><b>Edge Cases:</b> <b>Last Permutation:</b> If break point is not found (`i < 0`), it means the array is sorted descending. Just reverse the entire array to get the lowest permutation.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void nextPermutation(std::vector&lt;int&gt;&amp; nums) {&#10;    int n = nums.size(), i = n - 2;&#10;    while (i &gt;= 0 &amp;&amp; nums[i] &gt;= nums[i + 1]) i--;&#10;    &#10;    if (i &gt;= 0) {&#10;        int j = n - 1;&#10;        while (nums[j] &lt;= nums[i]) j--;&#10;        std::swap(nums[i], nums[j]);&#10;    }&#10;    std::reverse(nums.begin() + i + 1, nums.end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">15</td>
      <td rowspan="1">Arr 15 Pascals Triangle<br><br></b> <a href="https://leetcode.com/problems/pascals-triangle/" target="_blank">LeetCode 118</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> numRows = 5<br><b>Output:</b> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(N<sup>2</sup>) (Constraint)</td>
      <td>Optimal: Generate row by row. Each element `val[i][j]` is the sum of `val[i-1][j-1]` and `val[i-1][j]`.</td>
      <td><b>Edge Cases:</b> <b>Boundary 1s:</b> First and last elements of every row are always 1. Pre-filling row with 1s avoids out-of-bounds checks.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; generate(int numRows) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans(numRows);&#10;    for(int i = 0; i &lt; numRows; i++) {&#10;        ans[i].resize(i + 1, 1);&#10;        for(int j = 1; j &lt; i; j++) {&#10;            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">16</td>
      <td rowspan="1">Arr 16 Majority Element II<br><br></b> <a href="https://leetcode.com/problems/majority-element-ii/" target="_blank">LeetCode 229</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [3,2,3]<br><b>Output:</b> [3]<br><br><b> </b> Time O(N), Space O(1).</td>
      <td><b>Time:</b> O(N) (Constraint)<br><b>Space:</b> O(1) (Constraint)</td>
      <td>Optimal: Extended Moore's Voting Algorithm. At most TWO elements can appear > N/3 times. Track two candidates and two counters.</td>
      <td><b>Edge Cases:</b> <b>Verification phase required:</b> We MUST perform a second pass to count occurrences of `candidate1` and `candidate2` because it's not guaranteed they appear > N/3 times.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;int&gt; majorityElement(std::vector&lt;int&gt;&amp; nums) {&#10;    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;&#10;    for(int num : nums) {&#10;        if(cnt1 == 0 &amp;&amp; num != el2) {&#10;            cnt1 = 1; el1 = num;&#10;        } else if(cnt2 == 0 &amp;&amp; num != el1) {&#10;            cnt2 = 1; el2 = num;&#10;        } else if(num == el1) cnt1++;&#10;        else if(num == el2) cnt2++;&#10;        else {&#10;            cnt1--; cnt2--;&#10;        }&#10;    }&#10;    cnt1 = 0; cnt2 = 0;&#10;    for(int num : nums) {&#10;        if(num == el1) cnt1++;&#10;        if(num == el2) cnt2++;&#10;    }&#10;    std::vector&lt;int&gt; ans;&#10;    if(cnt1 &gt; nums.size() / 3) ans.push_back(el1);&#10;    if(cnt2 &gt; nums.size() / 3) ans.push_back(el2);&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">17</td>
      <td rowspan="1">Arr 17 3Sum<br><br></b> <a href="https://leetcode.com/problems/3sum/" target="_blank">LeetCode 15</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [-1,0,1,2,-1,-4]<br><b>Output:</b> [[-1,-1,2],[-1,0,1]]<br><br><b> </b> Solution set must not contain duplicate triplets.</td>
      <td><b>Time:</b> O(N<sup>2</sup>) (Constraint)<br><b>Space:</b> O(1) (Trade-off)</td>
      <td>Optimal: Sort the array. Use a loop to fix `i`, then use a Two-Pointer approach (`j`, `k`) for the remaining array to find sum `0 - nums[i]`.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Duplicate skipping:</b> To prevent duplicate triplets, skip identical adjacent elements for `i`, `j`, and `k`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; threeSum(std::vector&lt;int&gt;&amp; nums) {&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; ans;&#10;    std::sort(nums.begin(), nums.end());&#10;    int n = nums.size();&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(i &gt; 0 &amp;&amp; nums[i] == nums[i-1]) continue;&#10;        int j = i + 1, k = n - 1;&#10;        while(j &lt; k) {&#10;            int sum = nums[i] + nums[j] + nums[k];&#10;            if(sum &lt; 0) j++;&#10;            else if(sum &gt; 0) k--;&#10;            else {&#10;                ans.push_back({nums[i], nums[j], nums[k]});&#10;                j++; k--;&#10;                while(j &lt; k &amp;&amp; nums[j] == nums[j-1]) j++;&#10;                while(j &lt; k &amp;&amp; nums[k] == nums[k+1]) k--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">18</td>
      <td rowspan="1">Arr 18 Merge Intervals<br><br></b> <a href="https://leetcode.com/problems/merge-intervals/" target="_blank">LeetCode 56</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> intervals = [[1,3],[2,6],[8,10],[15,18]]<br><b>Output:</b> [[1,6],[8,10],[15,18]]</td>
      <td><b>Time:</b> O(N log N) (Constraint)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Sort the intervals based on the start time. Iterate and merge: if current start <= previous end, update previous end to `max(prev_end, curr_end)`.<br><br><b>Dependencies:</b> <code>std::sort</code></td>
      <td><b>Edge Cases:</b> <b>Subsumed Intervals:</b> `[1,4]` and `[2,3]` -> using `max()` prevents shrinking the end time to `3`.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">std::vector&lt;std::vector&lt;int&gt;&gt; merge(std::vector&lt;std::vector&lt;int&gt;&gt;&amp; intervals) {&#10;    if (intervals.empty()) return {};&#10;    std::sort(intervals.begin(), intervals.end());&#10;    std::vector&lt;std::vector&lt;int&gt;&gt; merged;&#10;    merged.push_back(intervals[0]);&#10;    for (int i = 1; i &lt; intervals.size(); i++) {&#10;        if (intervals[i][0] &lt;= merged.back()[1]) {&#10;            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);&#10;        } else {&#10;            merged.push_back(intervals[i]);&#10;        }&#10;    }&#10;    return merged;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">19</td>
      <td rowspan="1">Arr 19 Leaders In An Array<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> A = [16,17,4,3,5,2]<br><b>Output:</b> [17,5,2]</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N) for output</td>
      <td>Optimal: Traverse the array from right to left. Keep track of the maximum element seen so far. If the current element is greater than or equal to the max, it's a leader. Reverse the collected leaders at the end.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><b>Edge Cases:</b> <b>Rightmost element:</b> Always a leader.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; leaders(int a[], int n){&#10;    vector&lt;int&gt; ans;&#10;    int maxi = a[n - 1];&#10;    ans.push_back(maxi);&#10;    for(int i = n - 2; i &gt;= 0; i--) {&#10;        if(a[i] &gt;= maxi) {&#10;            ans.push_back(a[i]);&#10;            maxi = a[i];&#10;        }&#10;    }&#10;    reverse(ans.begin(), ans.end());&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">20</td>
      <td rowspan="1">Arr 20 Set Matrix Zeroes<br><br></b> <a href="https://leetcode.com/problems/set-matrix-zeroes/" target="_blank">LeetCode 73</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,1,1],[1,0,1],[1,1,1]]<br><b>Output:</b> [[1,0,1],[0,0,0],[1,0,1]]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use the first row and first column as marker arrays to save space. We need a separate variable for the first column (or row) to avoid overlapping states.</td>
      <td><b>Edge Cases:</b> <b>Zeros in first row/col:</b> Handled accurately by checking `col0` flag at the end.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void setZeroes(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size(), m = matrix[0].size(), col0 = 1;&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(matrix[i][0] == 0) col0 = 0;&#10;        for(int j=1; j&lt;m; j++)&#10;            if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;&#10;    }&#10;    for(int i=n-1; i&gt;=0; i--) {&#10;        for(int j=m-1; j&gt;=1; j--)&#10;            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;&#10;        if(col0 == 0) matrix[i][0] = 0;&#10;    }&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">21</td>
      <td rowspan="1">Arr 21 Rotate Image<br><br></b> <a href="https://leetcode.com/problems/rotate-image/" target="_blank">LeetCode 48</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,2,3],[4,5,6],[7,8,9]]<br><b>Output:</b> [[7,4,1],[8,5,2],[9,6,3]]</td>
      <td><b>Time:</b> O(N^2)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Transpose the matrix (swap matrix[i][j] with matrix[j][i]), then reverse every row.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void rotate(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    int n = matrix.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        for(int j=0; j&lt;i; j++) std::swap(matrix[i][j], matrix[j][i]);&#10;    }&#10;    for(int i=0; i&lt;n; i++) std::reverse(matrix[i].begin(), matrix[i].end());&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">22</td>
      <td rowspan="1">Arr 22 Spiral Matrix<br><br></b> <a href="https://leetcode.com/problems/spiral-matrix/" target="_blank">LeetCode 54</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,2,3],[4,5,6],[7,8,9]]<br><b>Output:</b> [1,2,3,6,9,8,7,4,5]</td>
      <td><b>Time:</b> O(N * M)<br><b>Space:</b> O(N * M) for output</td>
      <td>Optimal: Maintain 4 pointers: top, bottom, left, right. Traverse Top row, Right col, Bottom row, Left col, shrinking boundaries inwards.</td>
      <td><b>Edge Cases:</b> <b>Single row/col matrix:</b> Internal boundary checks prevent duplicate counting.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; spiralOrder(vector&lt;vector&lt;int&gt;&gt;&amp; matrix) {&#10;    vector&lt;int&gt; ans;&#10;    int top=0, left=0, bottom=matrix.size()-1, right=matrix[0].size()-1;&#10;    while(top&lt;=bottom &amp;&amp; left&lt;=right) {&#10;        for(int i=left; i&lt;=right; i++) ans.push_back(matrix[top][i]);&#10;        top++;&#10;        for(int i=top; i&lt;=bottom; i++) ans.push_back(matrix[i][right]);&#10;        right--;&#10;        if(top&lt;=bottom) {&#10;            for(int i=right; i&gt;=left; i--) ans.push_back(matrix[bottom][i]);&#10;            bottom--;&#10;        }&#10;        if(left&lt;=right) {&#10;            for(int i=bottom; i&gt;=top; i--) ans.push_back(matrix[i][left]);&#10;            left++;&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">23</td>
      <td rowspan="1">Arr 23 4Sum<br><br></b> <a href="https://leetcode.com/problems/4sum/" target="_blank">LeetCode 18</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,0,-1,0,-2,2], target = 0<br><b>Output:</b> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]</td>
      <td><b>Time:</b> O(N^3)<br><b>Space:</b> O(1) auxiliary</td>
      <td>Optimal: Sort array. Use 2 nested loops (i, j) for the first two numbers, and Two Pointers (k, l) for the remaining two. Skip duplicates carefully.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Use `long long` when computing sum of 4 integers.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;vector&lt;int&gt;&gt; fourSum(vector&lt;int&gt;&amp; nums, int target) {&#10;    vector&lt;vector&lt;int&gt;&gt; ans;&#10;    int n = nums.size(); sort(nums.begin(), nums.end());&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(i&gt;0 &amp;&amp; nums[i]==nums[i-1]) continue;&#10;        for(int j=i+1; j&lt;n; j++) {&#10;            if(j&gt;i+1 &amp;&amp; nums[j]==nums[j-1]) continue;&#10;            int k = j+1, l = n-1;&#10;            while(k &lt; l) {&#10;                long long sum = nums[i] + nums[j]; sum += nums[k]; sum += nums[l];&#10;                if(sum == target) {&#10;                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});&#10;                    k++; l--;&#10;                    while(k&lt;l &amp;&amp; nums[k]==nums[k-1]) k++;&#10;                    while(k&lt;l &amp;&amp; nums[l]==nums[l+1]) l--;&#10;                } else if(sum &lt; target) k++;&#10;                else l--;&#10;            }&#10;        }&#10;    }&#10;    return ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">24</td>
      <td rowspan="1">Arr 24 Count Subarrays With Given Xor K<br><br></b> <a href="https://www.interviewbit.com/problems/subarray-with-given-xor/" target="_blank">InterviewBit</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> A = [4, 2, 2, 6, 4], B = 6<br><b>Output:</b> 4</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Use a Hash Map to store the frequency of prefix XORs. For each element, current XOR `xr ^= A[i]`. We need `xr ^ B`. If it exists in map, add its frequency to count.<br><br><b>Dependencies:</b> <code>#include <unordered_map></code></td>
      <td><b>Edge Cases:</b> <b>XOR exactly equals B:</b> Insert `mpp[0] = 1` initially to cover subarrays starting from index 0.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int solve(vector&lt;int&gt; &amp;A, int B) {&#10;    unordered_map&lt;int, int&gt; mpp;&#10;    int xr = 0, count = 0;&#10;    mpp[xr]++;&#10;    for(int i=0; i&lt;A.size(); i++) {&#10;        xr ^= A[i];&#10;        int x = xr ^ B;&#10;        if(mpp.find(x) != mpp.end()) count += mpp[x];&#10;        mpp[xr]++;&#10;    }&#10;    return count;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">25</td>
      <td rowspan="1">Arr 25 Find The Duplicate Number<br><br></b> <a href="https://leetcode.com/problems/find-the-duplicate-number/" target="_blank">LeetCode 287</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,3,4,2,2]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Floyd's Tortoise and Hare (Cycle Detection). Fast and slow pointer. Guaranteed cycle because of Pigeonhole Principle (numbers map to index ranges).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findDuplicate(vector&lt;int&gt;&amp; nums) {&#10;    int slow = nums[0], fast = nums[0];&#10;    do {&#10;        slow = nums[slow];&#10;        fast = nums[nums[fast]];&#10;    } while(slow != fast);&#10;    fast = nums[0];&#10;    while(slow != fast) {&#10;        slow = nums[slow];&#10;        fast = nums[fast];&#10;    }&#10;    return slow;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">26</td>
      <td rowspan="1">Arr 26 Find Missing And Repeating<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 2, Arr[] = {2, 2}<br><b>Output:</b> 2 1</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Mathematical approach. Diff = Sum_N - Sum_Arr = Missing - Repeating. SumSqDiff = SumSq_N - SumSq_Arr = Missing^2 - Repeating^2. Use formulas to solve for both.</td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Summing squares of 10^5 elements exceeds 32-bit INT, requiring long long.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">vector&lt;int&gt; findTwoElement(vector&lt;int&gt; arr, int n) {&#10;    long long N = n;&#10;    long long S_N = (N * (N+1)) / 2;&#10;    long long Sq_N = (N * (N+1) * (2*N+1)) / 6;&#10;    long long S = 0, Sq = 0;&#10;    for(int i=0; i&lt;N; i++) {&#10;        S += arr[i]; Sq += (long long)arr[i] * (long long)arr[i];&#10;    }&#10;    long long val1 = S_N - S; // X - Y&#10;    long long val2 = Sq_N - Sq; // X^2 - Y^2&#10;    val2 = val2 / val1; // X + Y&#10;    long long x = (val1 + val2) / 2;&#10;    long long y = x - val1;&#10;    return {(int)y, (int)x};&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">27</td>
      <td rowspan="1">Arr 27 Merge Two Sorted Arrays Without Extra Space<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> arr1=[1,3,5,7], arr2=[0,2,6,8,9]<br><b>Output:</b> arr1=[0,1,2,3], arr2=[5,6,7,8,9]</td>
      <td><b>Time:</b> O((N+M) log(N+M))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Start pointers at end of arr1 (i) and beginning of arr2 (j). Swap if arr1[i] > arr2[j]. Afterwards, individually sort arr1 and arr2. Time is bounded by sorting.<br><br><b>Dependencies:</b> <code>#include <algorithm></code></td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(long long arr1[], long long arr2[], int n, int m) {&#10;    int left = n - 1, right = 0;&#10;    while(left &gt;= 0 &amp;&amp; right &lt; m) {&#10;        if(arr1[left] &gt; arr2[right]) { swap(arr1[left], arr2[right]); left--; right++; }&#10;        else break;&#10;    }&#10;    sort(arr1, arr1 + n); sort(arr2, arr2 + m);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">28</td>
      <td rowspan="1">Arr 28 Maximum Product Subarray<br><br></b> <a href="https://leetcode.com/problems/maximum-product-subarray/" target="_blank">LeetCode 152</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [2,3,-2,4]<br><b>Output:</b> 6</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Maintain prefix and suffix products. If a 0 is encountered, reset the product to 1. The max overall is the answer since negatives cancel out in pairs.<br><br><b>Dependencies:</b> <code>#include <limits.h></code></td>
      <td><b>Edge Cases:</b> <b>Odd negative numbers:</b> Checking both prefix and suffix elegantly covers the case where we drop one negative.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int maxProduct(vector&lt;int&gt;&amp; nums) {&#10;    double pref = 1, suff = 1, ans = INT_MIN;&#10;    int n = nums.size();&#10;    for(int i=0; i&lt;n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= nums[i];&#10;        suff *= nums[n-i-1];&#10;        ans = max({ans, pref, suff});&#10;    }&#10;    return (int)ans;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">29</td>
      <td rowspan="1">Arr 29 Count Inversions<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> N = 5, arr[] = {2, 4, 1, 3, 5}<br><b>Output:</b> 3</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N) auxiliary</td>
      <td>Optimal: Merge Sort approach. While merging two sorted halves, if left[i] > right[j], it forms an inversion with all remaining elements in the left half (mid - i + 1).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long merge(long long arr[], int low, int mid, int high) {&#10;    vector&lt;long long&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    long long cnt = 0;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else { temp.push_back(arr[right++]); cnt += (mid - left + 1); }&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;    return cnt;&#10;}&#10;long long mergeSort(long long arr[], int low, int high) {&#10;    long long cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;long long int inversionCount(long long arr[], long long N) {&#10;    return mergeSort(arr, 0, N - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">30</td>
      <td rowspan="1">Arr 30 Reverse Pairs<br><br></b> <a href="https://leetcode.com/problems/reverse-pairs/" target="_blank">LeetCode 493</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> nums = [1,3,2,3,1]<br><b>Output:</b> 2</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Modified Merge Sort. Before merging, loop through left and right halves. If left[i] > 2 * right[j], increment j. Number of pairs is (j - (mid+1)).</td>
      <td><b>Edge Cases:</b> <b>Integer Overflow:</b> Use long long when doubling nums[j].<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    vector&lt;int&gt; temp;&#10;    int left = low, right = mid + 1;&#10;    while(left &lt;= mid &amp;&amp; right &lt;= high) {&#10;        if(arr[left] &lt;= arr[right]) temp.push_back(arr[left++]);&#10;        else temp.push_back(arr[right++]);&#10;    }&#10;    while(left &lt;= mid) temp.push_back(arr[left++]);&#10;    while(right &lt;= high) temp.push_back(arr[right++]);&#10;    for(int i=low; i&lt;=high; i++) arr[i] = temp[i - low];&#10;}&#10;int countPairs(vector&lt;int&gt;&amp; arr, int low, int mid, int high) {&#10;    int right = mid + 1, cnt = 0;&#10;    for(int i = low; i &lt;= mid; i++) {&#10;        while(right &lt;= high &amp;&amp; arr[i] &gt; 2LL * arr[right]) right++;&#10;        cnt += (right - (mid + 1));&#10;    }&#10;    return cnt;&#10;}&#10;int mergeSort(vector&lt;int&gt;&amp; arr, int low, int high) {&#10;    int cnt = 0;&#10;    if(low &gt;= high) return cnt;&#10;    int mid = (low + high) / 2;&#10;    cnt += mergeSort(arr, low, mid);&#10;    cnt += mergeSort(arr, mid + 1, high);&#10;    cnt += countPairs(arr, low, mid, high);&#10;    merge(arr, low, mid, high);&#10;    return cnt;&#10;}&#10;int reversePairs(vector&lt;int&gt;&amp; nums) {&#10;    return mergeSort(nums, 0, nums.size() - 1);&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">31</td>
      <td rowspan="1">Arr 31 Grid Unique Paths<br><br></b> <a href="https://leetcode.com/problems/unique-paths/" target="_blank">LeetCode 62</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> m = 3, n = 7<br><b>Output:</b> 28</td>
      <td><b>Time:</b> O(m-1)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Combinatorics approach. The total number of steps to reach the bottom-right corner is (m - 1) + (n - 1) = m + n - 2. Out of these steps, we need to choose (m - 1) downward steps (or n - 1 rightward steps). The number of paths is (m + n - 2) C (m - 1).</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int uniquePaths(int m, int n) {&#10;    int N = n + m - 2;&#10;    int r = m - 1;&#10;    double res = 1;&#10;    for(int i = 1; i &lt;= r; i++) {&#10;        res = res * (N - r + i) / i;&#10;    }&#10;    return (int)res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">32</td>
      <td rowspan="1">Arr 32 Search A 2D Matrix<br><br></b> <a href="https://leetcode.com/problems/search-a-2d-matrix/" target="_blank">LeetCode 74</a></td>
      <td rowspan="1"><b> </b> <br><b>Input:</b> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3<br><b>Output:</b> true</td>
      <td><b>Time:</b> O(log(m * n))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Treat the 2D matrix as a 1D array and apply binary search. The element at `mid` can be accessed using `matrix[mid / cols][mid % cols]`.</td>
      <td><b>Edge Cases:</b> <b>Empty Matrix:</b> Return false.<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool searchMatrix(vector&lt;vector&lt;int&gt;&gt;&amp; matrix, int target) {&#10;    if(!matrix.size()) return false;&#10;    int m = matrix.size(), n = matrix[0].size();&#10;    int low = 0, high = (m * n) - 1;&#10;    while(low &lt;= high) {&#10;        int mid = (low + (high - low) / 2);&#10;        if(matrix[mid/n][mid % n] == target) return true;&#10;        if(matrix[mid/n][mid % n] &lt; target) low = mid + 1;&#10;        else high = mid - 1;&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">33</td>
      <td rowspan="1">Arr 33 Subarray With 0 Sum<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Prefix Sum with HashSet.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Iterate through the array and calculate the prefix sum. If the prefix sum is 0 or it already exists in a hash set, it means a subarray with sum 0 exists.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">bool subArrayExists(int arr[], int n) {&#10;    unordered_set&lt;int&gt; sumSet;&#10;    int sum = 0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        sum += arr[i];&#10;        if(sum == 0 || sumSet.find(sum) != sumSet.end()) return true;&#10;        sumSet.insert(sum);&#10;    }&#10;    return false;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">34</td>
      <td rowspan="1">Arr 34 Maximum Product Subarray<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Prefix and Suffix iteration.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Iterate from left to right calculating prefix product, and right to left calculating suffix product. If either is 0, reset it to 1. The max product will be the max of all prefix and suffix products.</td>
      <td><b>Edge Cases:</b> Zero elements<br><br><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long maxProduct(vector&lt;int&gt; arr, int n) {&#10;    long long max_prod = INT_MIN;&#10;    long long pref = 1, suff = 1;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(pref == 0) pref = 1;&#10;        if(suff == 0) suff = 1;&#10;        pref *= arr[i];&#10;        suff *= arr[n - i - 1];&#10;        max_prod = max({max_prod, pref, suff});&#10;    }&#10;    return max_prod;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">35</td>
      <td rowspan="1">Arr 35 Longest Consecutive Subsequence<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Hash Set.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Insert all elements into a hash set. For each element, check if `element - 1` exists. If not, it's the start of a sequence. Then increment to find consecutive elements.<br><br><b>Dependencies:</b> Hash Set</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findLongestConseqSubseq(int arr[], int N) {&#10;    unordered_set&lt;int&gt; s;&#10;    for(int i = 0; i &lt; N; i++) s.insert(arr[i]);&#10;    int longest = 0;&#10;    for(int num : s) {&#10;        if(s.find(num - 1) == s.end()) {&#10;            int curr = num;&#10;            int count = 1;&#10;            while(s.find(curr + 1) != s.end()) {&#10;                curr++;&#10;                count++;&#10;            }&#10;            longest = max(longest, count);&#10;        }&#10;    }&#10;    return longest;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">36</td>
      <td rowspan="1">Arr 36 Greedy 05 Fractional Knapsack<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort by value/weight ratio.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort items in descending order of value/weight ratio. Greedily pick items with the highest ratio first. If an item cannot fit completely, take the fraction that fits.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">struct Item { int value; int weight; };&#10;bool static comp(Item a, Item b) {&#10;    double r1 = (double)a.value / (double)a.weight;&#10;    double r2 = (double)b.value / (double)b.weight;&#10;    return r1 &gt; r2;&#10;}&#10;double fractionalKnapsack(int W, Item arr[], int n) {&#10;    sort(arr, arr + n, comp);&#10;    double currWeight = 0, finalValue = 0.0;&#10;    for(int i = 0; i &lt; n; i++) {&#10;        if(currWeight + arr[i].weight &lt;= W) {&#10;            currWeight += arr[i].weight;&#10;            finalValue += arr[i].value;&#10;        } else {&#10;            double remain = W - currWeight;&#10;            finalValue += (arr[i].value / (double)arr[i].weight) * remain;&#10;            break;&#10;        }&#10;    }&#10;    return finalValue;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">37</td>
      <td rowspan="1">Arr 37 Greedy 08 Minimum Platforms<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sort arrival and departure times separately.</td>
      <td><b>Time:</b> O(N log N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Sort arrival and departure arrays separately. Use two pointers, one for arrival and one for departure. If arrival < departure, a platform is needed, so increment count. If arrival >= departure, a platform is freed, so decrement count. Track the maximum count.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int findPlatform(int arr[], int dep[], int n) {&#10;    sort(arr, arr + n);&#10;    sort(dep, dep + n);&#10;    int plat_needed = 1, result = 1;&#10;    int i = 1, j = 0;&#10;    while(i &lt; n &amp;&amp; j &lt; n) {&#10;        if(arr[i] &lt;= dep[j]) {&#10;            plat_needed++;&#10;            i++;&#10;        } else if(arr[i] &gt; dep[j]) {&#10;            plat_needed--;&#10;            j++;&#10;        }&#10;        if(plat_needed &gt; result) result = plat_needed;&#10;    }&#10;    return result;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">38</td>
      <td rowspan="1">Arr 38 Trapping Rain Water<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use two pointers, left and right. Maintain left_max and right_max. If `arr[left] <= arr[right]`, the water trapped depends on left_max. If `arr[left] > left_max`, update left_max, else add `left_max - arr[left]` to answer and increment left. Repeat for right.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long trappingWater(int arr[], int n) {&#10;    int left = 0, right = n - 1;&#10;    int left_max = 0, right_max = 0;&#10;    long long res = 0;&#10;    while(left &lt;= right) {&#10;        if(arr[left] &lt;= arr[right]) {&#10;            if(arr[left] &gt;= left_max) left_max = arr[left];&#10;            else res += left_max - arr[left];&#10;            left++;&#10;        } else {&#10;            if(arr[right] &gt;= right_max) right_max = arr[right];&#10;            else res += right_max - arr[right];&#10;            right--;&#10;        }&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">39</td>
      <td rowspan="1">Arr 39 Median Of Two Sorted Arrays Of Different Sizes<br><br></b> <a href="https://leetcode.com/problems/median-of-two-sorted-arrays/" target="_blank">LeetCode 4</a></td>
      <td rowspan="1"><b> </b> Binary Search.</td>
      <td><b>Time:</b> O(log(min(N, M)))<br><b>Space:</b> O(1)</td>
      <td>Optimal: Use Binary Search on the smaller array. Partition both arrays such that the number of elements on the left side is equal to or one more than the right side. Check if `maxLeftX <= minRightY` and `maxLeftY <= minRightX`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">double findMedianSortedArrays(vector&lt;int&gt;&amp; nums1, vector&lt;int&gt;&amp; nums2) {&#10;    if(nums1.size() &gt; nums2.size()) return findMedianSortedArrays(nums2, nums1);&#10;    int x = nums1.size(), y = nums2.size();&#10;    int low = 0, high = x;&#10;    while(low &lt;= high) {&#10;        int partitionX = (low + high) / 2;&#10;        int partitionY = (x + y + 1) / 2 - partitionX;&#10;        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];&#10;        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];&#10;        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];&#10;        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];&#10;        if(maxLeftX &lt;= minRightY &amp;&amp; maxLeftY &lt;= minRightX) {&#10;            if((x + y) % 2 == 0) return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;&#10;            else return max(maxLeftX, maxLeftY);&#10;        } else if(maxLeftX &gt; minRightY) high = partitionX - 1;&#10;        else low = partitionX + 1;&#10;    }&#10;    return 0.0;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">40</td>
      <td rowspan="1">Arr 40 Count More Than N K Occurences<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/count-element-occurences/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> HashMap.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(N)</td>
      <td>Optimal: Store the frequencies of all elements in a hash map. Iterate through the hash map and count the number of elements having frequency greater than `N/k`.<br><br><b>Dependencies:</b> Hash Map</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int countOccurence(int arr[], int n, int k) {&#10;    unordered_map&lt;int, int&gt; count;&#10;    for(int i = 0; i &lt; n; i++) count[arr[i]]++;&#10;    int res = 0;&#10;    int target = n / k;&#10;    for(auto it : count) {&#10;        if(it.second &gt; target) res++;&#10;    }&#10;    return res;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">41</td>
      <td rowspan="1">Arr 41 Find The Missing Number<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sum formula.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Calculate the sum of first N natural numbers using `N*(N+1)/2`. Subtract the sum of all elements in the array from it. The result is the missing number.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int missingNumber(vector&lt;int&gt;&amp; array, int n) {&#10;    long long sum = 0;&#10;    for(int i = 0; i &lt; n - 1; i++) sum += array[i];&#10;    long long expectedSum = (long long)n * (n + 1) / 2;&#10;    return expectedSum - sum;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">42</td>
      <td rowspan="1">Arr 42 Max Sum In Sub Arrays<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Adjacent pairs sum.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: The maximum sum of two smallest elements in any subarray will always be the maximum sum of adjacent elements. So, just iterate and find the max of `arr[i] + arr[i+1]`.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">long long pairWithMaxSum(long long arr[], long long N) {&#10;    long long maxi = 0;&#10;    for(long long i = 0; i &lt; N - 1; i++) {&#10;        maxi = max(maxi, arr[i] + arr[i+1]);&#10;    }&#10;    return maxi;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">43</td>
      <td rowspan="1">Arr 43 Longest Subarray With Sum K Positives<br><br></b> <a href="https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1" target="_blank">GFG</a></td>
      <td rowspan="1"><b> </b> Sliding Window / Two Pointers.</td>
      <td><b>Time:</b> O(N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Since all elements are positive, use two pointers (sliding window). Expand `right` and add to sum. If sum > K, shrink `left` and subtract from sum. If sum == K, update max length.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">int lenOfLongSubarr(int A[],  int N, int K) {&#10;    int left = 0, right = 0;&#10;    long long sum = 0;&#10;    int maxLen = 0;&#10;    while(right &lt; N) {&#10;        sum += A[right];&#10;        while(sum &gt; K &amp;&amp; left &lt;= right) {&#10;            sum -= A[left];&#10;            left++;&#10;        }&#10;        if(sum == K) maxLen = max(maxLen, right - left + 1);&#10;        right++;&#10;    }&#10;    return maxLen;&#10;}</code></pre></details></td>
    </tr>
    <tr>
      <td rowspan="1">44</td>
      <td rowspan="1">Arr 44 Merge Sorted Array Without Extra Space<br><br></b> <a href="https://leetcode.com/problems/merge-sorted-array/" target="_blank">LeetCode 88</a></td>
      <td rowspan="1"><b> </b> Two pointers from end.</td>
      <td><b>Time:</b> O(M + N)<br><b>Space:</b> O(1)</td>
      <td>Optimal: Since `nums1` has enough space at the end, use three pointers: `p1` at the end of valid elements in `nums1` (m-1), `p2` at the end of `nums2` (n-1), and `p` at the very end of `nums1` (m+n-1). Compare elements at `p1` and `p2`, put the larger one at `p`, and decrement pointers.</td>
      <td><details><summary><b>View Code</b></summary><pre style="white-space: pre-wrap; word-wrap: break-word;"><code class="language-cpp">void merge(vector&lt;int&gt;&amp; nums1, int m, vector&lt;int&gt;&amp; nums2, int n) {&#10;    int p1 = m - 1, p2 = n - 1, p = m + n - 1;&#10;    while(p1 &gt;= 0 &amp;&amp; p2 &gt;= 0) {&#10;        if(nums1[p1] &gt; nums2[p2]) nums1[p--] = nums1[p1--];&#10;        else nums1[p--] = nums2[p2--];&#10;    }&#10;    while(p2 &gt;= 0) nums1[p--] = nums2[p2--];&#10;}</code></pre></details></td>
    </tr>
  </tbody>
</table>
