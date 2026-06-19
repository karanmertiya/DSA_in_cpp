// Time Complexity: O(K) where K! <= N
// Space Complexity: O(K)
// Explanation: Maintain a current factorial value and an index `i`. At each recursive step, compute the next factorial by multiplying by `i`. If the next factorial is `<= n`, add it to the list and recurse.

void findFactorials(long long n, long long i, long long fact, vector<long long>& ans) {
    if(fact > n) return;
    ans.push_back(fact);
    findFactorials(n, i + 1, fact * (i + 1), ans);
}
vector<long long> factorialNumbers(long long N) {
    vector<long long> ans;
    findFactorials(N, 1, 1, ans);
    return ans;
}

