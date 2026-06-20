// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
long long trappingWater(int arr[], int n) {
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    long long res = 0;
    while(left <= right) {
        if(arr[left] <= arr[right]) {
            if(arr[left] >= left_max) left_max = arr[left];
            else res += left_max - arr[left];
            left++;
        } else {
            if(arr[right] >= right_max) right_max = arr[right];
            else res += right_max - arr[right];
            right--;
        }
    }
    return res;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Use two pointers, left and right. Maintain left_max and right_max. If `arr[left] <= arr[right]`, the water trapped depends on left_max. If `arr[left] > left_max`, update left_max, else add `left_max - arr[left]` to answer and increment left. Repeat for right.

long long trappingWater(int arr[], int n) {
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    long long res = 0;
    while(left <= right) {
        if(arr[left] <= arr[right]) {
            if(arr[left] >= left_max) left_max = arr[left];
            else res += left_max - arr[left];
            left++;
        } else {
            if(arr[right] >= right_max) right_max = arr[right];
            else res += right_max - arr[right];
            right--;
        }
    }
    return res;
}

