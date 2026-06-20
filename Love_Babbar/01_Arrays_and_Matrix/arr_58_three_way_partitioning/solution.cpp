// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
void threeWayPartition(vector<int>& array, int a, int b) {
    int low = 0, mid = 0, high = array.size() - 1;
    while(mid <= high) {
        if(array[mid] < a) {
            swap(array[low], array[mid]);
            low++; mid++;
        } else if(array[mid] > b) {
            swap(array[mid], array[high]);
            high--;
        } else {
            mid++;
        }
    }
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Use three pointers: `low`, `mid`, `high`. If `arr[mid] < a`, swap `arr[low]` and `arr[mid]`, increment both. If `arr[mid] > b`, swap `arr[mid]` and `arr[high]`, decrement `high`. Else increment `mid`.

void threeWayPartition(vector<int>& array, int a, int b) {
    int low = 0, mid = 0, high = array.size() - 1;
    while(mid <= high) {
        if(array[mid] < a) {
            swap(array[low], array[mid]);
            low++; mid++;
        } else if(array[mid] > b) {
            swap(array[mid], array[high]);
            high--;
        } else {
            mid++;
        }
    }
}

