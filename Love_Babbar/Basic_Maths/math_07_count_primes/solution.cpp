// Time Complexity: O(N log(log N))
// Space Complexity: O(N)
// Explanation: Use the Sieve of Eratosthenes. Initialize a boolean array of size `n` with `true`. Mark `0` and `1` as `false`. For each `i` from `2` to `sqrt(n)`, if `i` is prime, mark its multiples as `false` starting from `i*i`. Finally, count the number of `true`s.

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

