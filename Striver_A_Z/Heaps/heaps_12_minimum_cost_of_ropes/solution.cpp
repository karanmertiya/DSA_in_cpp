// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Use a Min Heap to always pick the two smallest ropes. Add their sum to the total cost and insert the merged rope back into the heap. Repeat until one rope is left.

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i = 0; i < n; i++) pq.push(arr[i]);
    long long cost = 0;
    while(pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        cost += (a + b);
        pq.push(a + b);
    }
    return cost;
}

