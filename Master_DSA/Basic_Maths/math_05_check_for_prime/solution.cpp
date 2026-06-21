// Time Complexity: O(sqrt(N))
// Space Complexity: O(1)
// Explanation: Check divisibility up to sqrt(N). Iterating up to N (O(N) time) is unnecessary and inefficient since factors always appear in pairs.

int isPrime(int N){
    if(N <= 1) return 0;
    for(int i=2; i*i<=N; i++) {
        if(N % i == 0) return 0;
    }
    return 1;
}

