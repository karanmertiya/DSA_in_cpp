// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Same as LeetCode 239. Use a deque to maintain decreasing order of elements in the current window.

vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}

