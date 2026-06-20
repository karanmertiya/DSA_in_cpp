# Tries (Prefix Trees)
## 🧠 Core Intuition
An advanced n-ary tree dedicated strictly to string manipulation and prefix-matching. Every node represents a single character.

## 🛠️ Dependencies & Prerequisites
You must know how to construct a TrieNode class containing a Hash Map (or Array) of children.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
struct TrieNode {
    TrieNode* children[26]; // 26 lowercase letters
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
class TrieNode:
    def __init__(self):
        # Using a dictionary is more flexible than an array of 26
        self.children = {} 
        self.is_end_of_word = False
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Insert Word** | `O(L)` | `O(L)` |
| **Search Word** | `O(L)` | `O(1)` |
| **Search Prefix** | `O(L)` | `O(1)` |
*(Where L is the length of the string)*

## 💡 Elite Patterns
- **Bit Trie (Maximum XOR):** Instead of storing characters, store bits (`0` and `1`). To find the max XOR of a given number, traverse the Trie attempting to pick opposite bits to maximize the result.
- **Word Search II:** Combine DFS Backtracking on a grid with a Trie built from the dictionary to dramatically prune invalid search paths.
