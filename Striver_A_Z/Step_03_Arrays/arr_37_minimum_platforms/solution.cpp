// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: Sort arrival and departure arrays separately. Use two pointers, one for arrival and one for departure. If arrival < departure, a platform is needed, so increment count. If arrival >= departure, a platform is freed, so decrement count. Track the maximum count.

int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while(i < n && j < n) {
        if(arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else if(arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
        if(plat_needed > result) result = plat_needed;
    }
    return result;
}

