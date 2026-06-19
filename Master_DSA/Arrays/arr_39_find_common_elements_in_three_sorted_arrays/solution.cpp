// Time Complexity: O(N1 + N2 + N3)
// Space Complexity: O(1) extra space
// Explanation: Maintain three pointers `i`, `j`, `k` for the three arrays. If `A[i] == B[j] == C[k]`, add to result and increment all three. Otherwise, increment the pointer of the smallest element. Skip duplicates.

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
    int i = 0, j = 0, k = 0;
    vector<int> res;
    while(i < n1 && j < n2 && k < n3) {
        if(A[i] == B[j] && B[j] == C[k]) {
            if(res.empty() || res.back() != A[i]) res.push_back(A[i]);
            i++; j++; k++;
        } else if(A[i] < B[j]) i++;
        else if(B[j] < C[k]) j++;
        else k++;
    }
    return res;
}

