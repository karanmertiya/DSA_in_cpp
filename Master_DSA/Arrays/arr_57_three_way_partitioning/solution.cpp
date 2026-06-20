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

