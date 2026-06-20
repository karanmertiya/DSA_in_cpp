// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Collect all positive numbers in one array and all negative numbers in another. Overwrite the original array by picking elements alternatively from the two arrays.

void rearrange(int arr[], int n) {
    vector<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    int i = 0, j = 0, k = 0;
    while(i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while(i < pos.size()) arr[k++] = pos[i++];
    while(j < neg.size()) arr[k++] = neg[j++];
}

