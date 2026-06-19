// Time Complexity: O(N log(log N))
// Space Complexity: O(N)
// Explanation: Use the Sieve of Eratosthenes. Create a boolean array of size `n` initialized to true. Set indices 0 and 1 to false. Iterate from `p=2` to `sqrt(n)`. If `p` is prime, mark all its multiples starting from `p*p` as false. Count the remaining true values.

int countPrimes(int n) {
    if(n <= 2) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) count++;
    }
    return count;
}

