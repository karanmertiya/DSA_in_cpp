# Heaps / Priority Queues
## 🧠 Core Intuition
Complete binary trees optimized to dynamically maintain the Maximum (or Minimum) element at the absolute top. Excellent for problems requiring you to find the "Top K" of anything.

## 🛠️ Dependencies & Prerequisites
You must know how to invoke your language's Heap / Priority Queue library and convert between Min-Heaps and Max-Heaps.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <queue>
#include <vector>

int main() {
    // Max-Heap (Default in C++)
    std::priority_queue<int> maxHeap;
    
    // Min-Heap (Requires explicit comparator template)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    minHeap.push(10);
    minHeap.push(5);
    int top = minHeap.top(); // 5
    minHeap.pop(); // removes 5
    
    // Custom Comparator for Pairs
    auto comp = [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first; // Min-Heap based on first element
    };
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> customPQ(comp);
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
import heapq

# Min-Heap (Default in Python)
arr = [10, 5, 20]
heapq.heapify(arr) # O(N) inline conversion

heapq.heappush(arr, 3)
top = arr[0] # 3 (Peek is just index 0)
minimum = heapq.heappop(arr) # 3

# Max-Heap Hack: Python doesn't have a Max-Heap. 
# Multiply values by -1 before pushing, and multiply by -1 after popping.
max_heap = []
heapq.heappush(max_heap, -1 * 10)
heapq.heappush(max_heap, -1 * 20)
maximum = -1 * heapq.heappop(max_heap) # 20
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Find Max/Min** | `O(1)` | `O(1)` |
| **Push/Insert** | `O(log N)` | `O(1)` |
| **Pop/Extract** | `O(log N)` | `O(1)` |
| **Heapify (Array to Heap)**| `O(N)` | `O(N)` |

## 💡 Elite Patterns
- **Top K Elements:** Maintain a Min-Heap of size K. When the heap exceeds K, pop the smallest element. At the end, the heap holds the K largest elements.
- **Merge K Sorted Lists:** Push the first element of all K lists into a Min-Heap. Extract the minimum, attach it to your answer, and push the next element from the extracted node's list.
- **Two Heaps (Median):** Maintain a Max-Heap for the left half of data, and a Min-Heap for the right half. Keep sizes balanced to extract medians in `O(1)`.
