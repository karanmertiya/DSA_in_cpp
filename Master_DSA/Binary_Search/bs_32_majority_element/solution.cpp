// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int majorityElement(int a[], int size) {
    int count = 0, candidate = -1;
    for(int i = 0; i < size; i++) {
        if(count == 0) {
            candidate = a[i];
            count = 1;
        } else if(a[i] == candidate) count++;
        else count--;
    }
    count = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] == candidate) count++;
    }
    if(count > size / 2) return candidate;
    return -1;
}

// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Optimal: Use Moore's Voting Algorithm to find a candidate for majority element. Then count the occurrences of the candidate in the array to verify if it appears more than N/2 times.

int majorityElement(int a[], int size) {
    int count = 0, candidate = -1;
    for(int i = 0; i < size; i++) {
        if(count == 0) {
            candidate = a[i];
            count = 1;
        } else if(a[i] == candidate) count++;
        else count--;
    }
    count = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] == candidate) count++;
    }
    if(count > size / 2) return candidate;
    return -1;
}

