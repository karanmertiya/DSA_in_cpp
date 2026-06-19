// Time Complexity: O(sqrt(N) + k log k)
// Space Complexity: O(k)
// Explanation: Iterate `i` from 1 to `sqrt(N)`. If `N % i == 0`, add `i` to the list of divisors. If `N / i != i`, also add `N / i`. Sort the list before returning.

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

