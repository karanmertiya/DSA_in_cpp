// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: To achieve O(1) space, encode two values into one using `arr[i] += (arr[max_idx] % max_elem) * max_elem`. Iterate with two pointers `max_idx` and `min_idx`. At the end, divide every element by `max_elem`.

void rearrange(long long *arr, int n) {
    int min_idx = 0, max_idx = n - 1;
    long long max_elem = arr[n - 1] + 1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            arr[i] += (arr[max_idx] % max_elem) * max_elem;
            max_idx--;
        } else {
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }
    for(int i = 0; i < n; i++) {
        arr[i] = arr[i] / max_elem;
    }
}

