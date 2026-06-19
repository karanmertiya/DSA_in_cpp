// Time Complexity: O(N log(log N))
// Space Complexity: O(N)
// Explanation: Same as `countPrimes`, but return the actual prime numbers in a list instead of just the count.

vector<int> sieveOfEratosthenes(int N) {
    vector<int> primes;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    return primes;
}

