// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Brute Force: Iterate from 1 to N and check if N % i == 0.

void printDivisors(int n) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) cout << i << " ";
    }
}

// Time Complexity: O(sqrt(N) + k log k)
// Space Complexity: O(k)
// Explanation: Optimal: Iterate up to sqrt(N). If 'i' divides N, then 'N/i' is also a divisor.

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

