// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Insert all lengths into a min-heap. While heap size > 1, extract the two minimum elements, add them, add their sum to the total cost, and insert their sum back into the heap.

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; i++) pq.push(arr[i]);
    long long cost = 0;
    while(pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        cost += (a + b);
        pq.push(a + b);
    }
    return cost;
}

