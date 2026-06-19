// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a recursive function. Print `N` first and then call `f(N-1)`.

void printNos(int N) {
    if(N == 0) return;
    cout << N << " ";
    printNos(N - 1);
}

