// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Store the frequencies of all elements in a hash map. Iterate through the hash map and count the number of elements having frequency greater than `N/k`.

int countOccurence(int arr[], int n, int k) {
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++) count[arr[i]]++;
    int res = 0;
    int target = n / k;
    for(auto it : count) {
        if(it.second > target) res++;
    }
    return res;
}

