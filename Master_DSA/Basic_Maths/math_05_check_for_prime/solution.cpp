// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Brute Force: Iterate from 2 to N-1 and check if N is divisible.

int isPrime(int N){
    if(N <= 1) return 0;
    for(int i = 2; i < N; i++) {
        if(N % i == 0) return 0;
    }
    return 1;
}

// Time Complexity: O(sqrt(N))
// Space Complexity: O(1)
// Explanation: Optimal: Check divisibility up to sqrt(N). Factors appear in pairs.

int isPrime(int N){
    if(N <= 1) return 0;
    for(int i=2; i*i<=N; i++) {
        if(N % i == 0) return 0;
    }
    return 1;
}

