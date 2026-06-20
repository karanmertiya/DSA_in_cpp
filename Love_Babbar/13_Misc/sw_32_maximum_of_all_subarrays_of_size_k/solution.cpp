// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Use a deque to store indices of elements. The deque will maintain elements in decreasing order. For each element, remove elements from the back of the deque that are smaller than the current element. Also, remove elements from the front that are out of the current window. The front of the deque will always have the maximum element of the current window.

vector <int> max_of_subarrays(int *arr, int n, int k) {
    vector<int> res;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) res.push_back(arr[dq.front()]);
    }
    return res;
}

