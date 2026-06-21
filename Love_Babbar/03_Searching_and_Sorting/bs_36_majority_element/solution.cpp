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

