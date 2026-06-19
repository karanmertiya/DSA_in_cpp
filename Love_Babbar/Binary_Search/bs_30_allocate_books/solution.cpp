// Time Complexity: O(N log(Sum-Max))
// Space Complexity: O(1)
// Explanation: Binary search on max pages from `max(arr)` to `sum(arr)`. For a `mid` value, count how many students are needed. If `students > m`, we need to increase limit `low = mid + 1`. Else, `high = mid - 1`.

int countStudents(int arr[], int n, int pages) {
    int students = 1, pagesStudent = 0;
    for(int i=0; i<n; i++) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(int A[], int N, int M) {
    if(M > N) return -1;
    int low = *max_element(A, A + N);
    int high = accumulate(A, A + N, 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int students = countStudents(A, N, mid);
        if(students > M) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

