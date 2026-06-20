// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> res;
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2 && k < n3) {
        if(A[i] == B[j] && B[j] == C[k]) {
            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);
            i++; j++; k++;
        } else if(A[i] <= B[j] && A[i] <= C[k]) i++;
        else if(B[j] <= A[i] && B[j] <= C[k]) j++;
        else k++;
    }
    return res;
}

// Time Complexity: O(N1 + N2 + N3)
// Space Complexity: O(1)
// Explanation: Optimal: Use three pointers `i`, `j`, `k` for the three arrays. If `A[i] == B[j] == C[k]`, it's a common element, add it to the result (handling duplicates), and increment all three pointers. Else, increment the pointer that points to the smallest value.

vector<int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> res;
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2 && k < n3) {
        if(A[i] == B[j] && B[j] == C[k]) {
            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);
            i++; j++; k++;
        } else if(A[i] <= B[j] && A[i] <= C[k]) i++;
        else if(B[j] <= A[i] && B[j] <= C[k]) j++;
        else k++;
    }
    return res;
}

