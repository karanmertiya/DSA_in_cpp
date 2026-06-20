// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Use a min-heap. Pop two minimum length ropes, add them up, add sum to total cost, and push the merged rope back to the heap. Repeat until one rope remains.

long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; i++) pq.push(arr[i]);
    long long cost = 0;
    while(pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

