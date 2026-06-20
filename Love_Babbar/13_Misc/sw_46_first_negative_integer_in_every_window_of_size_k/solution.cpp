// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Maintain a queue of negative integers in the current window. While moving the window, add new negative integers, remove old ones out of window. The front of queue is the first negative.

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> q;
    for(long long i = 0; i < K - 1; i++) {
        if(A[i] < 0) q.push(A[i]);
    }
    for(long long i = K - 1; i < N; i++) {
        if(A[i] < 0) q.push(A[i]);
        if(!q.empty()) ans.push_back(q.front());
        else ans.push_back(0);
        if(A[i - K + 1] < 0 && !q.empty() && q.front() == A[i - K + 1]) q.pop();
    }
    return ans;
}

