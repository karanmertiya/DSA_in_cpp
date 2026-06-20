// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int buyMaximumProducts(int n, int k, int price[]) {
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) v.push_back({price[i], i + 1});
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int amount = min(v[i].second, k / v[i].first);
        ans += amount;
        k -= amount * v[i].first;
    }
    return ans;
}

// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Optimal: Store pairs of (price, day). Sort by price. Greedily buy as many stocks as possible on the day with the lowest price, bounded by the maximum allowed on that day (which is 'day') and the remaining money.

int buyMaximumProducts(int n, int k, int price[]) {
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) v.push_back({price[i], i + 1});
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int amount = min(v[i].second, k / v[i].first);
        ans += amount;
        k -= amount * v[i].first;
    }
    return ans;
}

