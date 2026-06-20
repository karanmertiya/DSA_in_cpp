# Basic Maths
## 🧠 Core Intuition
Mathematical concepts form the bedrock of optimal algorithms. Instead of iterating `O(N)` times to find divisors or prime numbers, mathematical tricks often reduce time complexity to `O(sqrt(N))` or even `O(1)`.

## 🛠️ Dependencies & Prerequisites
No special data structures needed, but precision and mathematical libraries are often required to prevent overflow.

<details><summary><b>C++ Syntax & Setup</b></summary>

```cpp
#include <iostream>
#include <cmath>     // For sqrt(), pow(), ceil(), floor()
#include <numeric>   // For std::gcd, std::lcm (C++17)

int main() {
    // Basic Operations
    int a = 12, b = 18;
    int g = std::gcd(a, b);
    
    // Overflow Prevention
    long long overflow_safe = 1LL * a * b; // Multiply with 1LL
    
    // Modulo Arithmetic
    int mod = 1e9 + 7;
    int ans = (1LL * a * b) % mod;
    
    // Digit Extraction (Crucial for palindromes/Armstrong numbers)
    int n = 123;
    while(n > 0) {
        int last_digit = n % 10;
        n /= 10;
    }
}
```
</details>

<details><summary><b>Python Syntax & Setup</b></summary>

```python
import math

# Python handles arbitrarily large integers automatically!
a, b = 12, 18
g = math.gcd(a, b)
l = math.lcm(a, b) # Python 3.9+
sq = math.isqrt(25) # Integer square root

# Modulo Arithmetic
mod = 10**9 + 7
ans = (a * b) % mod

# Digit Extraction
n = 123
# String method (easy in Python)
for digit in str(n):
    d = int(digit)
    
# Math method (if negative numbers exist, use abs(n))
n = abs(n)
while n > 0:
    last_digit = n % 10
    n //= 10
```
</details>

## ⏱️ Complexity Cheatsheet
| Operation | Brute Force | Optimal | Technique |
| :--- | :--- | :--- | :--- |
| **Check Prime** | `O(N)` | `O(sqrt(N))` | Check up to `sqrt(N)` |
| **Prime Factors** | `O(N)` | `O(log N)` | Sieve of Eratosthenes |
| **GCD / HCF** | `O(min(A, B))` | `O(log(min(A, B)))` | Euclidean Algorithm |
| **Trailing Zeroes** | `O(N)` | `O(log N)` | Count factors of 5 |

## 💡 Elite Patterns
- **Euclidean Algorithm:** `gcd(a, b) = gcd(b, a % b)` until `a % b == 0`.
- **Sieve of Eratosthenes:** Use a boolean array to mark non-primes up to `N` iteratively.
- **Modulo Arithmetic:** `(A * B) % M = ((A % M) * (B % M)) % M`. Used strictly to prevent integer overflow.
