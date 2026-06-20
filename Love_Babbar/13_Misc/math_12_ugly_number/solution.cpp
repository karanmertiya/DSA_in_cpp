// Time Complexity: O(log N)
// Space Complexity: O(1)
// Explanation: If `n <= 0`, return false. Divide `n` by 2, 3, and 5 as long as it is divisible. If the remaining number is 1, it's an ugly number, else false.

bool isUgly(int n) {
    if(n <= 0) return false;
    vector<int> primes = {2, 3, 5};
    for(int p : primes) {
        while(n % p == 0) n /= p;
    }
    return n == 1;
}

