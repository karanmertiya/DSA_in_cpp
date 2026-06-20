// Time Complexity: O(M log M + N log N)
// Space Complexity: O(1)
// Explanation: Optimal: Sort all vertical and horizontal cuts in descending order. Maintain counts of horizontal and vertical pieces. Greedily pick the cut with the highest cost. If a horizontal cut is made, its total cost is `cut_cost * vertical_pieces`. Update the counts.

int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    int hzntl = 1, vert = 1;
    int i = 0, j = 0, res = 0;
    while(i < M - 1 && j < N - 1) {
        if(X[i] > Y[j]) {
            res += X[i] * vert;
            hzntl++; i++;
        } else {
            res += Y[j] * hzntl;
            vert++; j++;
        }
    }
    int total = 0;
    while(i < M - 1) total += X[i++];
    res += total * vert;
    total = 0;
    while(j < N - 1) total += Y[j++];
    res += total * hzntl;
    return res;
}

