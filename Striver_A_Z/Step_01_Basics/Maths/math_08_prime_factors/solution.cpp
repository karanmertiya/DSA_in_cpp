// Time Complexity: O(sqrt(N))
// Space Complexity: O(1) excluding output
// Explanation: Iterate from `i = 2` to `sqrt(N)`. If `N % i == 0`, `i` is a prime factor. Add `i` to result, and repeatedly divide `N` by `i` until it's no longer divisible. After the loop, if `N > 1`, then `N` itself is a prime factor and should be added.

vector<int> AllPrimeFactors(int N) {
    vector<int> ans;
    for(int i = 2; i * i <= N; i++) {
        if(N % i == 0) {
            ans.push_back(i);
            while(N % i == 0) N /= i;
        }
    }
    if(N > 1) ans.push_back(N);
    return ans;
}

