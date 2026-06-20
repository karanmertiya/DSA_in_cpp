// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Optimal: Sort the candies by price. For minimum cost, buy the cheapest and take K most expensive for free. For maximum cost, buy the most expensive and take K cheapest for free.

vector<int> candyStore(int candies[], int N, int K) {
    sort(candies, candies + N);
    int minCost = 0, maxCost = 0;
    int i = 0, j = N - 1;
    while(i <= j) {
        minCost += candies[i];
        i++; j -= K;
    }
    i = N - 1; j = 0;
    while(j <= i) {
        maxCost += candies[i];
        i--; j += K;
    }
    return {minCost, maxCost};
}

