// Time Complexity: O(sqrt(N) + k log k)
// Space Complexity: O(k)
// Explanation: Iterate up to sqrt(N). If 'i' divides N, then 'N/i' is also a divisor. Iterating up to N (O(N) time) is unnecessary and inefficient.

void print_divisors(int n) {
    vector<int> ans;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ans.push_back(i);
            if(n / i != i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << " ";
}

