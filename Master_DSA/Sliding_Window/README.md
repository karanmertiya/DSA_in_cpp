# Two Pointers & Sliding Window
## 🧠 Core Intuition
The Sliding Window technique avoids redundant work by converting nested loops `O(N^2)` into a single linear loop `O(N)`. We maintain a "window" of elements that expands and shrinks based on given constraints.

## 🛠️ Dependencies & Prerequisites
Same as Arrays. You will primarily use two integer variables (`left` and `right`) to represent the bounds of your window.

<details><summary><b>C++ / Python Universal Concept</b></summary>

```text
Initialize left = 0, right = 0
While right < array_length:
    1. Add array[right] to current window state (e.g., sum += array[right])
    
    2. While window state is INVALID:
        a. Remove array[left] from window state (e.g., sum -= array[left])
        b. Increment left
        
    3. Update maximum/minimum answer using valid window length (right - left + 1)
    
    4. Increment right
```
</details>

## ⏱️ Complexity Cheatsheet
| Pattern | Typical Problem Type | Time Complexity |
| :--- | :--- | :--- |
| **Fixed Size Window** | Max Sum of Subarray Size K | `O(N)` |
| **Variable Size Window** | Longest Substring Without Repeats | `O(N)` |
| **Number of Subarrays** | Exact K elements (AtMost(K) - AtMost(K-1)) | `O(N)` |

## 💡 Elite Patterns
- **Expand & Shrink (Variable):** Move `right` pointer to expand. If the window violates the condition, continuously move `left` pointer to shrink until valid.
- **At Most K Trick:** To find subarrays with EXACTLY K distinct elements, calculate `AtMost(K) - AtMost(K-1)`.
- **Deque for Maximum:** For Sliding Window Maximum, maintain a monotonically decreasing Deque storing indices.
