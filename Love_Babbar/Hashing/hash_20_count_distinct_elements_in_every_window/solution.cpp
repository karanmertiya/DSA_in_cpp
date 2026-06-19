// Time Complexity: O(N)
// Space Complexity: O(K)
// Explanation: Use a hash map to keep track of element frequencies in the window of size K. The number of distinct elements is the size of the hash map. As window slides, increment frequency of new element, decrement frequency of outgoing element. If frequency becomes 0, remove it from map.

vector<int> countDistinct(int A[], int n, int k) {
    unordered_map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < k; i++) m[A[i]]++;
    ans.push_back(m.size());
    for(int i = k; i < n; i++) {
        m[A[i - k]]--;
        if(m[A[i - k]] == 0) m.erase(A[i - k]);
        m[A[i]]++;
        ans.push_back(m.size());
    }
    return ans;
}

