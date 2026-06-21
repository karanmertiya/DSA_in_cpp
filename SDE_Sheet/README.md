# SDE Sheet Master README

## Day 30 Misc

### [Math 01 Count Digits](Day_30_Misc/math_01_count_digits)
Given an integer N, return the number of digits in N.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/count-digits5716/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N = 12345
**Output:** 5


---

### [Math 02 Reverse Integer](Day_30_Misc/math_02_reverse_integer)
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range, then return 0.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/reverse-integer/' target='_blank'>LeetCode 7</a>

**Examples:**
**Example 1:** 
**Input:** x = 123
**Output:** 321

**Variants:** Strict 32-bit limit handling.


---

### [Math 03 Palindrome Number](Day_30_Misc/math_03_palindrome_number)
Given an integer x, return true if x is palindrome integer.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/palindrome-number/' target='_blank'>LeetCode 9</a>

**Examples:**
**Example 1:** 
**Input:** x = 121
**Output:** true


---

### [Math 04 Gcd Or Hcf](Day_30_Misc/math_04_gcd_or_hcf)
Find the GCD of two numbers.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/lcm-and-gcd4551/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** A = 4, B = 8
**Output:** 4


---

### [Math 05 Check For Prime](Day_30_Misc/math_05_check_for_prime)
Given a number N, check if it is prime.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/prime-number2314/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N = 5
**Output:** 1


---

### [Math 06 Power Of Two](Day_30_Misc/math_06_power_of_two)
Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2^x.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/power-of-two/' target='_blank'>LeetCode 231</a>

**Examples:**
**Example 1:** 
**Input:** n = 1
**Output:** true


---

### [Math 07 Pow X N](Day_30_Misc/math_07_pow_x_n)
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/powx-n/' target='_blank'>LeetCode 50</a>

**Examples:**
**Example 1:** 
**Input:** x = 2.00000, n = 10
**Output:** 1024.00000


---

### [Bit 08 Swap Two Numbers](Day_30_Misc/bit_08_swap_two_numbers)
Given two numbers a and b. Swap the two numbers without using a third variable.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:**

**Input:** a=5, b=7
**Output:** a=7, b=5

**Note (Constraint):** 1 &le; a, b &le; 10<sup>9</sup>


---

### [Bit 09 Check Ith Bit Set](Day_30_Misc/bit_09_check_ith_bit_set)
Given a number N and a bit number K, check if Kth index bit of N is set or not. A bit is called set if it is 1.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:**

**Input:** N=4 (100 in binary), i=2
**Output:** true

**Note (Constraint):** 1 &le; N &le; 10<sup>9</sup>, 0 &le; i &le; 31


---

### [Bit 10 Operations Set Clear Toggle](Day_30_Misc/bit_10_operations_set_clear_toggle)
Given a number N and a bit number i. Return an array of size 3 containing the modified numbers after setting, clearing, and toggling the ith bit of N.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:**
N=70, i=3 -> Set:78, Clear:62, Toggle:78

**Note (Constraint):** 1 &le; N &le; 10<sup>9</sup>


---

### [Bit 11 Count Set Bits](Day_30_Misc/bit_11_count_set_bits)
Write a function that takes the binary representation of a positive integer and returns the number of set bits it has (also known as the Hamming weight).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/number-of-1-bits/' target='_blank'>LeetCode 191</a>

**Examples:**
**Example 1:**

**Input:** N=11 (1011)
**Output:** 3


---

### [Bit 12 Minimum Bit Flips To Convert Number](Day_30_Misc/bit_12_minimum_bit_flips_to_convert_number)
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0. Return the minimum number of bit flips to convert start to goal.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/minimum-bit-flips-to-convert-number/' target='_blank'>LeetCode 2220</a>

**Examples:**
**Example 1:**

**Input:** start=10 (1010), goal=7 (0111)
**Output:** 3 flips


---

### [Sw 13 Longest Substring Without Repeating Characters](Day_30_Misc/sw_13_longest_substring_without_repeating_characters)
Given a string s, find the length of the longest substring without repeating characters.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-substring-without-repeating-characters/' target='_blank'>LeetCode 3</a>

**Examples:**
**Example 1:** 
**Input:** s = "abcabcbb"
**Output:** 3 ("abc")


---

### [Sw 14 Trapping Rain Water](Day_30_Misc/sw_14_trapping_rain_water)
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/trapping-rain-water/' target='_blank'>LeetCode 42</a>

**Examples:**
**Example 1:** 
**Input:** height = [0,1,0,2,1,0,1,3,2,1,2,1]
**Output:** 6


---

### [Sw 15 Container With Most Water](Day_30_Misc/sw_15_container_with_most_water)
Find two lines that together with the x-axis form a container, such that the container contains the most water.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/container-with-most-water/' target='_blank'>LeetCode 11</a>

**Examples:**
**Example 1:** 
**Input:** height = [1,8,6,2,5,4,8,3,7]
**Output:** 49


---

### [Sort 16 Selection Sort](Day_30_Misc/sort_16_selection_sort)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/selection-sort/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {4, 1, 3, 9, 7}
**Output:** 1 3 4 7 9<br><br>**Note (Constraint):** In-place sorting.


---

### [Sort 17 Bubble Sort](Day_30_Misc/sort_17_bubble_sort)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/bubble-sort/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {4, 1, 3, 9, 7}
**Output:** 1 3 4 7 9


---

### [Sort 18 Insertion Sort](Day_30_Misc/sort_18_insertion_sort)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/insertion-sort/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {4, 1, 3, 9, 7}
**Output:** 1 3 4 7 9


---

### [Sort 19 Merge Sort](Day_30_Misc/sort_19_merge_sort)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/merge-sort/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {4, 1, 3, 9, 7}
**Output:** 1 3 4 7 9


---

### [Sort 20 Quick Sort](Day_30_Misc/sort_20_quick_sort)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/quick-sort/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {4, 1, 3, 9, 7}
**Output:** 1 3 4 7 9


---

## Day 01 to 04 Arrays

### [Bit 01 Single Number](Day_01_to_04_Arrays/bit_01_single_number)
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/single-number/' target='_blank'>LeetCode 136</a>

**Examples:**
**Example 1:**

**Input:** nums = [4,1,2,1,2]
**Output:** 4


---

### [Arr 02 Largest Element](Day_01_to_04_Arrays/arr_02_largest_element)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/largest-element-in-array/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** A = [1, 8, 7, 56, 90]
**Output:** 90


---

### [Arr 03 Second Largest Element](Day_01_to_04_Arrays/arr_03_second_largest_element)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/second-largest3735/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** arr = [12, 35, 1, 10, 34, 1]
**Output:** 34<br><br>**Note (Constraint):** Find it in a single pass O(N) time.


---

### [Arr 04 Check If Array Is Sorted And Rotated](Day_01_to_04_Arrays/arr_04_check_if_array_is_sorted_and_rotated)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/' target='_blank'>LeetCode 1752</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,4,5,1,2]
**Output:** true


---

### [Arr 05 Remove Duplicates From Sorted Array](Day_01_to_04_Arrays/arr_05_remove_duplicates_from_sorted_array)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/remove-duplicates-from-sorted-array/' target='_blank'>LeetCode 26</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,1,2]
**Output:** 2, nums = [1,2,_]


---

### [Arr 06 Rotate Array](Day_01_to_04_Arrays/arr_06_rotate_array)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/rotate-array/' target='_blank'>LeetCode 189</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,2,3,4,5,6,7], k = 3
**Output:** [5,6,7,1,2,3,4]


---

### [Arr 07 Move Zeroes](Day_01_to_04_Arrays/arr_07_move_zeroes)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/move-zeroes/' target='_blank'>LeetCode 283</a>

**Examples:**
**Example 1:** 
**Input:** nums = [0,1,0,3,12]
**Output:** [1,3,12,0,0]


---

### [Arr 08 Missing Number](Day_01_to_04_Arrays/arr_08_missing_number)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/missing-number/' target='_blank'>LeetCode 268</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,0,1]
**Output:** 2


---

### [Arr 09 Max Consecutive Ones](Day_01_to_04_Arrays/arr_09_max_consecutive_ones)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/max-consecutive-ones/' target='_blank'>LeetCode 485</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,1,0,1,1,1]
**Output:** 3


---

### [Arr 10 Sort Colors Dnf](Day_01_to_04_Arrays/arr_10_sort_colors_dnf)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/sort-colors/' target='_blank'>LeetCode 75</a>

**Examples:**
**Example 1:** 
**Input:** nums = [2,0,2,1,1,0]
**Output:** [0,0,1,1,2,2]<br><br>**Note (Constraint):** Do not use library sort. Use single pass.


---

### [Arr 11 Majority Element](Day_01_to_04_Arrays/arr_11_majority_element)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/majority-element/' target='_blank'>LeetCode 169</a>

**Examples:**
**Example 1:** 
**Input:** nums = [2,2,1,1,1,2,2]
**Output:** 2


---

### [Arr 12 Kadanes Algorithm Max Subarray Sum](Day_01_to_04_Arrays/arr_12_kadanes_algorithm_max_subarray_sum)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/maximum-subarray/' target='_blank'>LeetCode 53</a>

**Examples:**
**Example 1:** 
**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]
**Output:** 6 (Subarray [4,-1,2,1])


---

### [Arr 13 Best Time To Buy And Sell Stock](Day_01_to_04_Arrays/arr_13_best_time_to_buy_and_sell_stock)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/best-time-to-buy-and-sell-stock/' target='_blank'>LeetCode 121</a>

**Examples:**
**Example 1:** 
**Input:** prices = [7,1,5,3,6,4]
**Output:** 5


---

### [Arr 14 Rearrange Array Elements By Sign](Day_01_to_04_Arrays/arr_14_rearrange_array_elements_by_sign)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/rearrange-array-elements-by-sign/' target='_blank'>LeetCode 2149</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,1,-2,-5,2,-4]
**Output:** [3,-2,1,-5,2,-4]<br><br>**Note (Constraint):** Maintain relative order.


---

### [Arr 15 Next Permutation](Day_01_to_04_Arrays/arr_15_next_permutation)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/next-permutation/' target='_blank'>LeetCode 31</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,2,3]
**Output:** [1,3,2]<br>**Example 2:** 
**Input:** nums = [3,2,1]
**Output:** [1,2,3]


---

### [Arr 16 Pascals Triangle](Day_01_to_04_Arrays/arr_16_pascals_triangle)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/pascals-triangle/' target='_blank'>LeetCode 118</a>

**Examples:**
**Example 1:** 
**Input:** numRows = 5
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]


---

### [Arr 17 Majority Element II](Day_01_to_04_Arrays/arr_17_majority_element_ii)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/majority-element-ii/' target='_blank'>LeetCode 229</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,2,3]
**Output:** [3]<br><br>**Note (Constraint):** Time O(N), Space O(1).


---

### [Arr 18 3Sum](Day_01_to_04_Arrays/arr_18_3sum)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/3sum/' target='_blank'>LeetCode 15</a>

**Examples:**
**Example 1:** 
**Input:** nums = [-1,0,1,2,-1,-4]
**Output:** [[-1,-1,2],[-1,0,1]]<br><br>**Note (Constraint):** Solution set must not contain duplicate triplets.


---

### [Arr 19 Merge Intervals](Day_01_to_04_Arrays/arr_19_merge_intervals)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/merge-intervals/' target='_blank'>LeetCode 56</a>

**Examples:**
**Example 1:** 
**Input:** intervals = [[1,3],[2,6],[8,10],[15,18]]
**Output:** [[1,6],[8,10],[15,18]]


---

### [Arr 20 Leaders In An Array](Day_01_to_04_Arrays/arr_20_leaders_in_an_array)
Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** A = [16,17,4,3,5,2]
**Output:** [17,5,2]


---

### [Arr 21 Set Matrix Zeroes](Day_01_to_04_Arrays/arr_21_set_matrix_zeroes)
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/set-matrix-zeroes/' target='_blank'>LeetCode 73</a>

**Examples:**
**Example 1:** 
**Input:** matrix = [[1,1,1],[1,0,1],[1,1,1]]
**Output:** [[1,0,1],[0,0,0],[1,0,1]]


---

### [Arr 22 Rotate Image](Day_01_to_04_Arrays/arr_22_rotate_image)
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/rotate-image/' target='_blank'>LeetCode 48</a>

**Examples:**
**Example 1:** 
**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** [[7,4,1],[8,5,2],[9,6,3]]


---

### [Arr 23 Spiral Matrix](Day_01_to_04_Arrays/arr_23_spiral_matrix)
Given an m x n matrix, return all elements of the matrix in spiral order.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/spiral-matrix/' target='_blank'>LeetCode 54</a>

**Examples:**
**Example 1:** 
**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** [1,2,3,6,9,8,7,4,5]


---

### [Arr 24 4Sum](Day_01_to_04_Arrays/arr_24_4sum)
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that sum is target.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/4sum/' target='_blank'>LeetCode 18</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,0,-1,0,-2,2], target = 0
**Output:** [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


---

### [Arr 25 Count Subarrays With Given Xor K](Day_01_to_04_Arrays/arr_25_count_subarrays_with_given_xor_k)
Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equals to B.<br><br><b>🔗 Practice:</b> <a href='https://www.interviewbit.com/problems/subarray-with-given-xor/' target='_blank'>InterviewBit</a>

**Examples:**
**Example 1:** 
**Input:** A = [4, 2, 2, 6, 4], B = 6
**Output:** 4


---

### [Arr 26 Find The Duplicate Number](Day_01_to_04_Arrays/arr_26_find_the_duplicate_number)
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/find-the-duplicate-number/' target='_blank'>LeetCode 287</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,3,4,2,2]
**Output:** 2


---

### [Arr 27 Find Missing And Repeating](Day_01_to_04_Arrays/arr_27_find_missing_and_repeating)
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, ...N} is missing and one number 'B' occurs twice. Find these two numbers.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N = 2, Arr[] = {2, 2}
**Output:** 2 1


---

### [Arr 28 Merge Two Sorted Arrays Without Extra Space](Day_01_to_04_Arrays/arr_28_merge_two_sorted_arrays_without_extra_space)
Merge two sorted arrays arr1 and arr2 into arr1 without using extra space. (We place first elements in arr1, remaining in arr2 and sort).<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** arr1=[1,3,5,7], arr2=[0,2,6,8,9]
**Output:** arr1=[0,1,2,3], arr2=[5,6,7,8,9]


---

### [Arr 29 Maximum Product Subarray](Day_01_to_04_Arrays/arr_29_maximum_product_subarray)
Given an integer array nums, find a subarray that has the largest product, and return the product.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/maximum-product-subarray/' target='_blank'>LeetCode 152</a>

**Examples:**
**Example 1:** 
**Input:** nums = [2,3,-2,4]
**Output:** 6


---

### [Arr 30 Count Inversions](Day_01_to_04_Arrays/arr_30_count_inversions)
For an array, inversion count indicates how far the array is from being sorted. Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N = 5, arr[] = {2, 4, 1, 3, 5}
**Output:** 3


---

### [Arr 31 Reverse Pairs](Day_01_to_04_Arrays/arr_31_reverse_pairs)
Given an integer array nums, return the number of reverse pairs. A reverse pair is (i, j) where: 0 <= i < j < nums.length and nums[i] > 2 * nums[j].<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/reverse-pairs/' target='_blank'>LeetCode 493</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,3,2,3,1]
**Output:** 2


---

### [Arr 32 Rearrange Array Alternately](Day_01_to_04_Arrays/arr_32_rearrange_array_alternately)
Given a sorted array of positive integers. Your task is to rearrange the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/rearrange-array-alternately-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Math-based encoding O(1) space.


---

### [Arr 33 Maximum Product Subarray](Day_01_to_04_Arrays/arr_33_maximum_product_subarray)
Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Prefix and Suffix iteration.


---

### [Arr 34 Longest Consecutive Subsequence](Day_01_to_04_Arrays/arr_34_longest_consecutive_subsequence)
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Hash Set.


---

### [Arr 35 Greedy 08 Minimum Platforms](Day_01_to_04_Arrays/arr_35_greedy_08_minimum_platforms)
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Sort arrival and departure times separately.


---

### [Arr 36 Trapping Rain Water](Day_01_to_04_Arrays/arr_36_trapping_rain_water)
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Two Pointers.


---

### [Arr 37 Merge Sorted Array Without Extra Space](Day_01_to_04_Arrays/arr_37_merge_sorted_array_without_extra_space)
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order. nums1 has size m + n.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/merge-sorted-array/' target='_blank'>LeetCode 88</a>

**Examples:**
**Example 1:** Two pointers from end.


---

## Day 09 10 Recursion Backtracking

### [Bit 01 Subsets](Day_09_10_Recursion_Backtracking/bit_01_subsets)
Given an integer array nums of unique elements, return all possible subsets (the power set). The solution set must not contain duplicate subsets.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/subsets/' target='_blank'>LeetCode 78</a>

**Examples:**
**Example 1:**

**Input:** nums = [1,2,3]
**Output:** [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


---

### [Rec 02 Combination Sum](Day_09_10_Recursion_Backtracking/rec_02_combination_sum)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/combination-sum/' target='_blank'>LeetCode 39</a>

**Examples:**
**Example 1:** 
**Input:** candidates = [2,3,6,7], target = 7
**Output:** [[2,2,3],[7]]<br><br>**Note (Constraint):** The same number may be chosen unlimited number of times.


---

### [Rec 03 N Queens](Day_09_10_Recursion_Backtracking/rec_03_n_queens)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/n-queens/' target='_blank'>LeetCode 51</a>

**Examples:**
**Example 1:** 
**Input:** n = 4
**Output:** [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]<br><br>**Note (Constraint):** 1 &le; n &le; 9


---

### [Rec 04 Permutations](Day_09_10_Recursion_Backtracking/rec_04_permutations)
Given an array nums of distinct integers, return all the possible permutations.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/permutations/' target='_blank'>LeetCode 46</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,2,3]
**Output:** [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


---

### [Rec 05 Print All Permutations Of A String](Day_09_10_Recursion_Backtracking/rec_05_print_all_permutations_of_a_string)
Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Recursive Backtracking.


---

## Day 11 Binary Search

### [Arr 01 Search A 2D Matrix](Day_11_Binary_Search/arr_01_search_a_2d_matrix)
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties: Integers in each row are sorted from left to right. The first integer of each row is greater than the last integer of the previous row.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/search-a-2d-matrix/' target='_blank'>LeetCode 74</a>

**Examples:**
**Example 1:** 
**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
**Output:** true


---

### [Arr 02 Median Of Two Sorted Arrays Of Different Sizes](Day_11_Binary_Search/arr_02_median_of_two_sorted_arrays_of_different_sizes)
Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/median-of-two-sorted-arrays/' target='_blank'>LeetCode 4</a>

**Examples:**
**Example 1:** Binary Search.


---

### [Bs 03 Binary Search](Day_11_Binary_Search/bs_03_binary_search)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/binary-search/' target='_blank'>LeetCode 704</a>

**Examples:**
**Example 1:** 
**Input:** nums = [-1,0,3,5,9,12], target = 9
**Output:** 4


---

### [Bs 04 Lower Bound](Day_11_Binary_Search/bs_04_lower_bound)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** arr = [1,2,8,10,11,12,19], target = 0
**Output:** 0


---

### [Bs 05 Find First And Last Position Of Element](Day_11_Binary_Search/bs_05_find_first_and_last_position_of_element)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/' target='_blank'>LeetCode 34</a>

**Examples:**
**Example 1:** 
**Input:** nums = [5,7,7,8,8,10], target = 8
**Output:** [3,4]


---

### [Bs 06 Search In Rotated Sorted Array](Day_11_Binary_Search/bs_06_search_in_rotated_sorted_array)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/search-in-rotated-sorted-array/' target='_blank'>LeetCode 33</a>

**Examples:**
**Example 1:** 
**Input:** nums = [4,5,6,7,0,1,2], target = 0
**Output:** 4


---

### [Bs 07 Koko Eating Bananas](Day_11_Binary_Search/bs_07_koko_eating_bananas)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/koko-eating-bananas/' target='_blank'>LeetCode 875</a>

**Examples:**
**Example 1:** 
**Input:** piles = [3,6,7,11], h = 8
**Output:** 4<br><br>**Note (Constraint):** Binary Search on Answers.


---

### [Bs 08 Find Minimum In Rotated Sorted Array](Day_11_Binary_Search/bs_08_find_minimum_in_rotated_sorted_array)
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated array nums of unique elements, return the minimum element of this array.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/' target='_blank'>LeetCode 153</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,4,5,1,2]
**Output:** 1


---

### [Bs 09 Find Peak Element](Day_11_Binary_Search/bs_09_find_peak_element)
A peak element is an element that is strictly greater than its neighbors. Given an integer array nums, find a peak element, and return its index.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/find-peak-element/' target='_blank'>LeetCode 162</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,2,3,1]
**Output:** 2


---

### [Bs 10 Kth Element Of Two Sorted Arrays](Day_11_Binary_Search/bs_10_kth_element_of_two_sorted_arrays)
Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 5
**Output:** 6


---

### [Bs 11 Majority Element](Day_11_Binary_Search/bs_11_majority_element)
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Moore's Voting Algorithm.


---

### [Bs 12 Find Four Elements That Sum To A Given Value](Day_11_Binary_Search/bs_12_find_four_elements_that_sum_to_a_given_value)
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Two loops and two pointers.


---

### [Bs 13 Find Nth Root Of M](Day_11_Binary_Search/bs_13_find_nth_root_of_m)
You are given 2 numbers (n , m); the task is to find n√m (nth root of m). If the root is not integer then returns -1.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Binary Search.


---

## Day 04 Hashing

### [Arr 01 Subarray With 0 Sum](Day_04_Hashing/arr_01_subarray_with_0_sum)
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Prefix Sum with HashSet.


---

### [Hash 02 Count Frequencies](Day_04_Hashing/hash_02_count_frequencies)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** arr = [10, 5, 10, 15, 10, 5]
**Output:** 10->3, 5->2, 15->1<br><br>**Note (Constraint):** 1 &le; N &le; 10<sup>5</sup>


---

### [Hash 03 Highest Lowest Frequency](Day_04_Hashing/hash_03_highest_lowest_frequency)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/sort-array-by-increasing-frequency/' target='_blank'>LeetCode 1636</a>

**Examples:**
**Example 1:** 
**Input:** arr = [10, 5, 10, 15, 10, 5]
**Output:** Highest=10, Lowest=15<br><br>**Note (Constraint):** 1 &le; N &le; 10<sup>5</sup>


---

### [Hash 04 Intersection Of Two Arrays](Day_04_Hashing/hash_04_intersection_of_two_arrays)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/intersection-of-two-arrays/' target='_blank'>LeetCode 349</a>

**Examples:**
**Example 1:** 
**Input:** nums1 = [1,2,2,1], nums2 = [2,2]
**Output:** [2]<br><br>**Note (Constraint):** 1 &le; N, M &le; 1000


---

### [Hash 05 Union Of Two Arrays](Day_04_Hashing/hash_05_union_of_two_arrays)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** a = [1, 2, 3], b = [2, 3, 4]
**Output:** [1, 2, 3, 4]<br><br>**Note (Constraint):** Arrays may not be sorted.


---

### [Hash 06 Subarray With 0 Sum](Day_04_Hashing/hash_06_subarray_with_0_sum)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** arr = [4, 2, -3, 1, 6]
**Output:** true (2, -3, 1)<br><br>**Note (Constraint):** Array contains positive and negative integers.


---

### [Hash 07 Subarray Sum Equals K](Day_04_Hashing/hash_07_subarray_sum_equals_k)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/subarray-sum-equals-k/' target='_blank'>LeetCode 560</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,1,1], k = 2
**Output:** 2<br><br>**Note (Constraint):** Negative numbers allowed, preventing pure Sliding Window approaches.


---

### [Hash 08 Longest Subarray With 0 Sum](Day_04_Hashing/hash_08_longest_subarray_with_0_sum)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** arr = [15,-2,2,-8,1,7,10,23]
**Output:** 5<br><br>**Note (Constraint):** 1 &le; N &le; 10<sup>5</sup>


---

### [Hash 09 Longest Subarray With Sum K](Day_04_Hashing/hash_09_longest_subarray_with_sum_k)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1' target='_blank'>GeeksforGeeks</a>

**Examples:**
**Example 1:** 
**Input:** arr = [10, 5, 2, 7, 1, 9], k = 15
**Output:** 4<br><br>**Note (Constraint):** 1 &le; N &le; 10<sup>5</sup>


---

### [Hash 10 Two Sum](Day_04_Hashing/hash_10_two_sum)
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/two-sum/' target='_blank'>LeetCode 1</a>

**Examples:**
**Example 1:** 
**Input:** nums = [2,7,11,15], target = 9
**Output:** [0,1]


---

### [Hash 11 Group Anagrams](Day_04_Hashing/hash_11_group_anagrams)
Given an array of strings strs, group the anagrams together. You can return the answer in any order.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/group-anagrams/' target='_blank'>LeetCode 49</a>

**Examples:**
**Example 1:** 
**Input:** strs = ["eat","tea","tan","ate","nat","bat"]
**Output:** [["bat"],["nat","tan"],["ate","eat","tea"]]


---

### [Hash 12 Longest Consecutive Sequence](Day_04_Hashing/hash_12_longest_consecutive_sequence)
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-consecutive-sequence/' target='_blank'>LeetCode 128</a>

**Examples:**
**Example 1:** 
**Input:** nums = [100,4,200,1,3,2]
**Output:** 4 (The sequence is [1, 2, 3, 4])


---

### [Hash 13 Longest Subarray With 0 Sum](Day_04_Hashing/hash_13_longest_subarray_with_0_sum)
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Hash Map.


---

## Day 15 16 Strings

### [Str 01 Valid Palindrome](Day_15_16_Strings/str_01_valid_palindrome)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/valid-palindrome/' target='_blank'>LeetCode 125</a>

**Examples:**
**Example 1:** 
**Input:** s = "A man, a plan, a canal: Panama"
**Output:** true


---

### [Str 02 Valid Anagram](Day_15_16_Strings/str_02_valid_anagram)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/valid-anagram/' target='_blank'>LeetCode 242</a>

**Examples:**
**Example 1:** 
**Input:** s = "anagram", t = "nagaram"
**Output:** true


---

### [Str 03 Longest Common Prefix](Day_15_16_Strings/str_03_longest_common_prefix)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-common-prefix/' target='_blank'>LeetCode 14</a>

**Examples:**
**Example 1:** 
**Input:** strs = ["flower","flow","flight"]
**Output:** "fl"


---

### [Str 04 Longest Palindromic Substring](Day_15_16_Strings/str_04_longest_palindromic_substring)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-palindromic-substring/' target='_blank'>LeetCode 5</a>

**Examples:**
**Example 1:** 
**Input:** s = "babad"
**Output:** "bab"


---

### [Str 05 Next Permutation](Day_15_16_Strings/str_05_next_permutation)
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/next-permutation5226/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Swap and Reverse.


---

### [Str 06 Parenthesis Checker](Day_15_16_Strings/str_06_parenthesis_checker)
Given an expression string x. Examine whether the pairs and the orders of "{", "}", "(", ")", "[", "]" are correct in exp.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Stack approach.


---

### [Str 07 Word Break](Day_15_16_Strings/str_07_word_break)
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/word-break1352/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** DP.


---

### [Str 08 Rabin Karp Algorithm](Day_15_16_Strings/str_08_rabin_karp_algorithm)
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurrences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Rolling Hash.


---

### [Str 09 Kmp Algorithm](Day_15_16_Strings/str_09_kmp_algorithm)
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurrences of pattern string in the text string. Use KMP algorithm.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/search-pattern0205/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** LPS Array.


---

### [Str 10 Roman Number To Integer](Day_15_16_Strings/str_10_roman_number_to_integer)
Given a string in roman no format (s)  your task is to convert it to an integer.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Value mapping.


---

### [Str 11 Reverse Words In A String](Day_15_16_Strings/str_11_reverse_words_in_a_string)
Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/reverse-words-in-a-string/' target='_blank'>LeetCode 151</a>

**Examples:**
**Example 1:** Two Pointers.


---

### [Str 12 String To Integer Atoi](Day_15_16_Strings/str_12_string_to_integer_atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/string-to-integer-atoi/' target='_blank'>LeetCode 8</a>

**Examples:**
**Example 1:** Step-by-step parsing.


---

## Day 13 14 Stacks Queues

### [Sw 01 Sliding Window Maximum](Day_13_14_Stacks_Queues/sw_01_sliding_window_maximum)
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/sliding-window-maximum/' target='_blank'>LeetCode 239</a>

**Examples:**
**Example 1:** Deque.


---

### [Ll 02 Lru Cache Ll](Day_13_14_Stacks_Queues/ll_02_lru_cache_ll)
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache (using specifically Doubly Linked List logic emphasis).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/lru-cache/' target='_blank'>LeetCode 146</a>

**Examples:**
**Example 1:** Duplicate logic entry to ensure coverage.


---

### [Ll 03 Lfu Cache Ll](Day_13_14_Stacks_Queues/ll_03_lfu_cache_ll)
Design and implement a data structure for a Least Frequently Used (LFU) cache (using specifically Doubly Linked List logic emphasis).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/lfu-cache/' target='_blank'>LeetCode 460</a>

**Examples:**
**Example 1:** Duplicate logic entry to ensure coverage.


---

### [Sq 04 Valid Parentheses](Day_13_14_Stacks_Queues/sq_04_valid_parentheses)
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/valid-parentheses/' target='_blank'>LeetCode 20</a>

**Examples:**
**Example 1:** 
**Input:** s = "()[]{}"
**Output:** true


---

### [Sq 05 Next Greater Element I](Day_13_14_Stacks_Queues/sq_05_next_greater_element_i)
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/next-greater-element-i/' target='_blank'>LeetCode 496</a>

**Examples:**
**Example 1:** 
**Input:** nums1 = [4,1,2], nums2 = [1,3,4,2]
**Output:** [-1,3,-1]


---

### [Sq 06 Min Stack](Day_13_14_Stacks_Queues/sq_06_min_stack)
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/min-stack/' target='_blank'>LeetCode 155</a>

**Examples:**
**Example 1:** MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0); minStack.push(-3); minStack.getMin(); // return -3


---

### [Sq 07 Largest Rectangle In Histogram](Day_13_14_Stacks_Queues/sq_07_largest_rectangle_in_histogram)
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/largest-rectangle-in-histogram/' target='_blank'>LeetCode 84</a>

**Examples:**
**Example 1:** 
**Input:** heights = [2,1,5,6,2,3]
**Output:** 10


---

### [Sq 08 Online Stock Span](Day_13_14_Stacks_Queues/sq_08_online_stock_span)
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/online-stock-span/' target='_blank'>LeetCode 901</a>

**Examples:**
**Example 1:** Monotonic Stack.


---

### [Sq 09 Rotten Oranges](Day_13_14_Stacks_Queues/sq_09_rotten_oranges)
You are given an m x n grid where each cell can have one of three values: 0 representing an empty cell, 1 representing a fresh orange, or 2 representing a rotten orange. Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/rotting-oranges/' target='_blank'>LeetCode 994</a>

**Examples:**
**Example 1:** BFS.


---

## Day 25 to 27 DP

### [Rec 01 Word Break](Day_25_to_27_DP/rec_01_word_break)
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/word-break/' target='_blank'>LeetCode 139</a>

**Examples:**
**Example 1:** 
**Input:** s = 'leetcode', wordDict = ['leet','code']
**Output:** true


---

### [DP 02 Climbing Stairs](Day_25_to_27_DP/dp_02_climbing_stairs)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/climbing-stairs/' target='_blank'>LeetCode 70</a>

**Examples:**
**Example 1:** 
**Input:** n = 3
**Output:** 3 (1+1+1, 1+2, 2+1)


---

### [DP 03 Longest Common Subsequence](Day_25_to_27_DP/dp_03_longest_common_subsequence)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-common-subsequence/' target='_blank'>LeetCode 1143</a>

**Examples:**
**Example 1:** 
**Input:** text1 = "abcde", text2 = "ace"
**Output:** 3 ("ace")


---

### [DP 04 Coin Change](Day_25_to_27_DP/dp_04_coin_change)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/coin-change/' target='_blank'>LeetCode 322</a>

**Examples:**
**Example 1:** 
**Input:** coins = [1,2,5], amount = 11
**Output:** 3 (5+5+1)


---

### [DP 05 Longest Increasing Subsequence](Day_25_to_27_DP/dp_05_longest_increasing_subsequence)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/longest-increasing-subsequence/' target='_blank'>LeetCode 300</a>

**Examples:**
**Example 1:** 
**Input:** nums = [10,9,2,5,3,7,101,18]
**Output:** 4 ([2,3,7,101])


---

### [DP 06 House Robber](Day_25_to_27_DP/dp_06_house_robber)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/house-robber/' target='_blank'>LeetCode 198</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,2,3,1]
**Output:** 4 (Rob house 1 and 3)


---

### [DP 07 01 Knapsack](Day_25_to_27_DP/dp_07_01_knapsack)
0-1 Knapsack problem.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N=3, W=4, values[]={1,2,3}, weight[]={4,5,1}
**Output:** 3


---

### [DP 08 Edit Distance](Day_25_to_27_DP/dp_08_edit_distance)
Find the minimum number of operations to convert word1 to word2.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/edit-distance/' target='_blank'>LeetCode 72</a>

**Examples:**
**Example 1:** 
**Input:** word1 = 'horse', word2 = 'ros'
**Output:** 3


---

### [DP 09 Matrix Chain Multiplication](Day_25_to_27_DP/dp_09_matrix_chain_multiplication)
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** N=5, arr=[40, 20, 30, 10, 30]
**Output:** 26000


---

### [DP 10 Subset Sum Problem](Day_25_to_27_DP/dp_10_subset_sum_problem)
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** set=[3,34,4,12,5,2], sum=9
**Output:** True


---

## Day 05 06 Linked List

### [Ll 01 Reverse Linked List](Day_05_06_Linked_List/ll_01_reverse_linked_list)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/reverse-linked-list/' target='_blank'>LeetCode 206</a>

**Examples:**
**Example 1:** 
**Input:** head = [1,2,3,4,5]
**Output:** [5,4,3,2,1]


---

### [Ll 02 Middle Of The Linked List](Day_05_06_Linked_List/ll_02_middle_of_the_linked_list)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/middle-of-the-linked-list/' target='_blank'>LeetCode 876</a>

**Examples:**
**Example 1:** 
**Input:** head = [1,2,3,4,5,6]
**Output:** [4,5,6]


---

### [Ll 03 Linked List Cycle](Day_05_06_Linked_List/ll_03_linked_list_cycle)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/linked-list-cycle/' target='_blank'>LeetCode 141</a>

**Examples:**
**Example 1:** 
**Input:** head = [3,2,0,-4], pos = 1
**Output:** true


---

### [Ll 04 Merge Two Sorted Lists](Day_05_06_Linked_List/ll_04_merge_two_sorted_lists)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/merge-two-sorted-lists/' target='_blank'>LeetCode 21</a>

**Examples:**
**Example 1:** 
**Input:** list1 = [1,2,4], list2 = [1,3,4]
**Output:** [1,1,2,3,4,4]


---

### [Ll 05 Remove Nth Node From End Of List](Day_05_06_Linked_List/ll_05_remove_nth_node_from_end_of_list)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/remove-nth-node-from-end-of-list/' target='_blank'>LeetCode 19</a>

**Examples:**
**Example 1:** 
**Input:** head = [1,2,3,4,5], n = 2
**Output:** [1,2,3,5]


---

### [Ll 06 Add Two Numbers](Day_05_06_Linked_List/ll_06_add_two_numbers)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/add-two-numbers/' target='_blank'>LeetCode 2</a>

**Examples:**
**Example 1:** 
**Input:** l1 = [2,4,3], l2 = [5,6,4]
**Output:** [7,0,8]


---

### [Ll 07 Intersection Of Two Linked Lists](Day_05_06_Linked_List/ll_07_intersection_of_two_linked_lists)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/intersection-of-two-linked-lists/' target='_blank'>LeetCode 160</a>

**Examples:**
**Example 1:** 
**Input:** intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
**Output:** Intersected at '8'


---

### [Ll 08 Reverse Nodes In K Group](Day_05_06_Linked_List/ll_08_reverse_nodes_in_k_group)
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. If the number of nodes is not a multiple of k then left-out nodes remain as is.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/reverse-nodes-in-k-group/' target='_blank'>LeetCode 25</a>

**Examples:**
**Example 1:** 
**Input:** head = [1,2,3,4,5], k = 2
**Output:** [2,1,4,3,5]


---

### [Ll 09 Reverse A Linked List In Groups Of Given Size](Day_05_06_Linked_List/ll_09_reverse_a_linked_list_in_groups_of_given_size)
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Recursive grouping.


---

### [Ll 10 Detect Loop In Linked List](Day_05_06_Linked_List/ll_10_detect_loop_in_linked_list)
Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Floyd's Cycle Detection.


---

### [Ll 11 Add Two Numbers Represented By Linked Lists](Day_05_06_Linked_List/ll_11_add_two_numbers_represented_by_linked_lists)
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Reverse, Add, Reverse.


---

### [Ll 12 Intersection Point In Y Shaped Linked Lists](Day_05_06_Linked_List/ll_12_intersection_point_in_y_shaped_linked_lists)
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Two Pointers.


---

## Day 17 to 22 Trees BST

### [Tree 01 Binary Tree Inorder Traversal](Day_17_to_22_Trees_BST/tree_01_binary_tree_inorder_traversal)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/binary-tree-inorder-traversal/' target='_blank'>LeetCode 94</a>

**Examples:**
**Example 1:** 
**Input:** root = [1,null,2,3]
**Output:** [1,3,2]


---

### [Tree 02 Maximum Depth Of Binary Tree](Day_17_to_22_Trees_BST/tree_02_maximum_depth_of_binary_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/maximum-depth-of-binary-tree/' target='_blank'>LeetCode 104</a>

**Examples:**
**Example 1:** 
**Input:** root = [3,9,20,null,null,15,7]
**Output:** 3


---

### [Tree 03 Lowest Common Ancestor Of A Binary Tree](Day_17_to_22_Trees_BST/tree_03_lowest_common_ancestor_of_a_binary_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/' target='_blank'>LeetCode 236</a>

**Examples:**
**Example 1:** 
**Input:** root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
**Output:** 3


---

### [Tree 04 Same Tree](Day_17_to_22_Trees_BST/tree_04_same_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/same-tree/' target='_blank'>LeetCode 100</a>

**Examples:**
**Example 1:** 
**Input:** p = [1,2,3], q = [1,2,3]
**Output:** true


---

### [Tree 05 Invert Binary Tree](Day_17_to_22_Trees_BST/tree_05_invert_binary_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/invert-binary-tree/' target='_blank'>LeetCode 226</a>

**Examples:**
**Example 1:** 
**Input:** root = [4,2,7,1,3,6,9]
**Output:** [4,7,2,9,6,3,1]


---

### [Tree 06 Diameter Of Binary Tree](Day_17_to_22_Trees_BST/tree_06_diameter_of_binary_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/diameter-of-binary-tree/' target='_blank'>LeetCode 543</a>

**Examples:**
**Example 1:** 
**Input:** root = [1,2,3,4,5]
**Output:** 3 (Path is [4,2,1,3] or [5,2,1,3])


---

### [Tree 07 Balanced Binary Tree](Day_17_to_22_Trees_BST/tree_07_balanced_binary_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/balanced-binary-tree/' target='_blank'>LeetCode 110</a>

**Examples:**
**Example 1:** 
**Input:** root = [3,9,20,null,null,15,7]
**Output:** true


---

### [Tree 08 Binary Search Tree Iterator](Day_17_to_22_Trees_BST/tree_08_binary_search_tree_iterator)
Implement the BSTIterator class that represents an iterator over the in-order traversal of a BST.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/binary-search-tree-iterator/' target='_blank'>LeetCode 173</a>

**Examples:**
**Example 1:** next() returns smallest element.


---

### [Tree 09 Validate Binary Search Tree](Day_17_to_22_Trees_BST/tree_09_validate_binary_search_tree)
Determine if it is a valid BST.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/validate-binary-search-tree/' target='_blank'>LeetCode 98</a>

**Examples:**
**Example 1:** 
**Input:** root = [2,1,3]
**Output:** true


---

### [Tree 10 Construct Tree From Preorder And Inorder](Day_17_to_22_Trees_BST/tree_10_construct_tree_from_preorder_and_inorder)
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/' target='_blank'>LeetCode 105</a>

**Examples:**
**Example 1:** 
**Input:** preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
**Output:** [3,9,20,null,null,15,7]


---

### [Tree 11 Maximum Path Sum](Day_17_to_22_Trees_BST/tree_11_maximum_path_sum)
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. Find the maximum path sum of any non-empty path.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/binary-tree-maximum-path-sum/' target='_blank'>LeetCode 124</a>

**Examples:**
**Example 1:** 
**Input:** root = [-10,9,20,null,null,15,7]
**Output:** 42


---

### [Tree 12 Boundary Traversal](Day_17_to_22_Trees_BST/tree_12_boundary_traversal)
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: Left boundary, Leaves, Right boundary in reverse.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Return array of boundary nodes.


---

### [Tree 13 Zigzag Traversal](Day_17_to_22_Trees_BST/tree_13_zigzag_traversal)
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/' target='_blank'>LeetCode 103</a>

**Examples:**
**Example 1:** 
**Input:** root = [3,9,20,null,null,15,7]
**Output:** [[3],[20,9],[15,7]]


---

### [Tree 14 Symmetric Tree](Day_17_to_22_Trees_BST/tree_14_symmetric_tree)
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/symmetric-tree/' target='_blank'>LeetCode 101</a>

**Examples:**
**Example 1:** Recursive.


---

## Day 12 Heaps

### [Heap 01 Kth Largest Element In An Array](Day_12_Heaps/heap_01_kth_largest_element_in_an_array)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/kth-largest-element-in-an-array/' target='_blank'>LeetCode 215</a>

**Examples:**
**Example 1:** 
**Input:** nums = [3,2,1,5,6,4], k = 2
**Output:** 5<br><br>**Note (Constraint):** Can you solve it without sorting?


---

### [Heap 02 Merge K Sorted Lists](Day_12_Heaps/heap_02_merge_k_sorted_lists)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/merge-k-sorted-lists/' target='_blank'>LeetCode 23</a>

**Examples:**
**Example 1:** 
**Input:** lists = [[1,4,5],[1,3,4],[2,6]]
**Output:** [1,1,2,3,4,4,5,6]


---

### [Heap 03 Top K Frequent Elements](Day_12_Heaps/heap_03_top_k_frequent_elements)
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/top-k-frequent-elements/' target='_blank'>LeetCode 347</a>

**Examples:**
**Example 1:** 
**Input:** nums = [1,1,1,2,2,3], k = 2
**Output:** [1,2]


---

## Day 23 24 Graphs

### [Graph 01 Number Of Islands](Day_23_24_Graphs/graph_01_number_of_islands)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/number-of-islands/' target='_blank'>LeetCode 200</a>

**Examples:**
**Example 1:** 
**Input:** grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
**Output:** 3


---

### [Graph 02 Course Schedule](Day_23_24_Graphs/graph_02_course_schedule)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/course-schedule/' target='_blank'>LeetCode 207</a>

**Examples:**
**Example 1:** 
**Input:** numCourses = 2, prerequisites = [[1,0]]
**Output:** true


---

### [Graph 03 Bipartite Graph](Day_23_24_Graphs/graph_03_bipartite_graph)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/is-graph-bipartite/' target='_blank'>LeetCode 785</a>

**Examples:**
**Example 1:** 
**Input:** graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
**Output:** false


---

### [Graph 04 Dijkstras Algorithm](Day_23_24_Graphs/graph_04_dijkstras_algorithm)
Find shortest paths from the source to all vertices in the given graph.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Source = 0
**Output:** distances array.


---

### [Graph 05 Topological Sort](Day_23_24_Graphs/graph_05_topological_sort)
Return the topological sorting of a DAG.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/topological-sort/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** V = 4, adj = [[], [0], [0], [0]]
**Output:** valid topological sort.


---

### [Graph 06 Bellman Ford](Day_23_24_Graphs/graph_06_bellman_ford)
Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S. If the Graph contains a negative cycle then return an array consisting of only -1.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0' target='_blank'>GFG</a>

**Examples:**
**Example 1:** 
**Input:** V=3, S=0, Edges=[[0,1,5],[1,2,-2],[2,1,-3]]
**Output:** [-1]


---

### [Graph 07 Floyd Warshall](Day_23_24_Graphs/graph_07_floyd_warshall)
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed Graph. The Graph is represented as an adjacency matrix.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:
**Output:** Shortest paths for all pairs (i, j).


---

### [Graph 08 Mst Prims](Day_23_24_Graphs/graph_08_mst_prims)
Given a weighted, undirected and connected graph of V vertices and E edges. Find the sum of weights of the edges of the Minimum Spanning Tree.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Return the scalar sum of the MST.


---

### [Graph 09 Strongly Connected Components Kosaraju](Day_23_24_Graphs/graph_09_strongly_connected_components_kosaraju)
Given a Directed Graph with V vertices and E edges, Find the number of strongly connected components in the graph.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Return an integer count.


---

### [Graph 10 Bipartite Graph DFS](Day_23_24_Graphs/graph_10_bipartite_graph_dfs)
Given an adjacency list of a graph adj of V no. of vertices. Check whether the graph is Bipartite or not.<br><br><b>🔗 Practice:</b> <a href='https://practice.geeksforgeeks.org/problems/bipartite-graph/1' target='_blank'>GFG</a>

**Examples:**
**Example 1:** Return true/false.


---

## Day 28 29 Tries

### [Trie 01 Implement Trie Prefix Tree](Day_28_29_Tries/trie_01_implement_trie_prefix_tree)
Restored problem.<br><br><b>🔗 Practice:</b> <a href='https://leetcode.com/problems/implement-trie-prefix-tree/' target='_blank'>LeetCode 208</a>

**Examples:**
**Example 1:** `insert("apple")`, `search("apple")` -> true, `search("app")` -> false, `startsWith("app")` -> true.<br><br>**Note (Constraint):** 1 &le; word.length &le; 2000, lowercase English letters.


---

### [Trie 02 Implement Trie II](Day_28_29_Tries/trie_02_implement_trie_ii)
Implement a Trie with insert, countWordsEqualTo, countWordsStartingWith, and erase functions.<br><br><b>🔗 Practice:</b> <a href='https://www.codingninjas.com/studio/problems/implement-trie_1387095' target='_blank'>Coding Ninjas</a>

**Examples:**
**Example 1:** Specialized Trie functions.


---

