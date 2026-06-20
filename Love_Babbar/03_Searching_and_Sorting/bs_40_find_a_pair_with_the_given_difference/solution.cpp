// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);
    int i = 0, j = 1;
    while(i < size && j < size) {
        if(i != j && arr[j] - arr[i] == n) return true;
        else if(arr[j] - arr[i] < n) j++;
        else i++;
    }
    return false;
}

// Time Complexity: O(L log L)
// Space Complexity: O(1)
// Explanation: Optimal: Sort the array. Use two pointers `i = 0` and `j = 1`. If `arr[j] - arr[i] == N` and `i != j`, return true. If difference < N, `j++`. Else `i++`.

bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);
    int i = 0, j = 1;
    while(i < size && j < size) {
        if(i != j && arr[j] - arr[i] == n) return true;
        else if(arr[j] - arr[i] < n) j++;
        else i++;
    }
    return false;
}

