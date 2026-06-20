# Linked Lists
## 🧠 Core Intuition
A linear structure where elements dynamically point to the next via memory addresses. Pointers and reference manipulation are the strict focus here.

## 🛠️ Dependencies & Prerequisites
You must know how to define a Node struct/class and navigate pointers without throwing Null Pointer Exceptions.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
// Standard LeetCode Node Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    
    // Traversal (Always check != nullptr)
    ListNode* curr = head;
    while(curr != nullptr) {
        // Do something with curr->val
        curr = curr->next;
    }
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
# Standard LeetCode Node Definition
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

head = ListNode(1)
head.next = ListNode(2)

# Traversal (Always check is not None)
curr = head
while curr is not None:
    # Do something with curr.val
    curr = curr.next
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Access element** | `O(N)` | `O(1)` |
| **Insert/Delete (at Head)** | `O(1)` | `O(1)` |
| **Insert/Delete (in Middle)**| `O(N)` | `O(1)` |

## 💡 Elite Patterns
- **Fast & Slow Pointers (Tortoise & Hare):** Fast pointer moves 2 steps, Slow pointer moves 1 step. Used to find the Middle Node or detect Cycles.
- **Dummy Node:** Create a dummy head `Dummy -> Head` to seamlessly handle edge cases where the original head is modified or deleted.
- **In-Place Reversal:** Carefully manage `prev`, `curr`, and `next` pointers to reverse a list in `O(N)` time and `O(1)` space.
