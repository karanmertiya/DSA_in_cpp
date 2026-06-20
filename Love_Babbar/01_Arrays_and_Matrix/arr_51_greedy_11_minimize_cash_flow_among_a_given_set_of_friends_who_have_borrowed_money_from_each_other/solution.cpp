// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int getMin(int arr[], int n) {
    int minInd = 0;
    for(int i = 1; i < n; i++) if(arr[i] < arr[minInd]) minInd = i;
    return minInd;
}
int getMax(int arr[], int n) {
    int maxInd = 0;
    for(int i = 1; i < n; i++) if(arr[i] > arr[maxInd]) maxInd = i;
    return maxInd;
}
void minCashFlowRec(int amount[], int n, vector<vector<int>>& ans) {
    int mxCredit = getMax(amount, n), mxDebit = getMin(amount, n);
    if(amount[mxCredit] == 0 && amount[mxDebit] == 0) return;
    int minVal = min(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= minVal;
    amount[mxDebit] += minVal;
    ans[mxDebit][mxCredit] = minVal;
    minCashFlowRec(amount, n, ans);
}
vector<vector<int>> minCashFlow(vector<vector<int>>& graph, int n) {
    int amount[n] = {0};
    for(int p = 0; p < n; p++) {
        for(int i = 0; i < n; i++) {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    minCashFlowRec(amount, n, ans);
    return ans;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Optimal: Calculate the net amount for each person by subtracting incoming debts from outgoing debts. Find the person with maximum net credit and maximum net debit. Settle their amounts, and repeat recursively or iteratively until all net amounts are zero.

int getMin(int arr[], int n) {
    int minInd = 0;
    for(int i = 1; i < n; i++) if(arr[i] < arr[minInd]) minInd = i;
    return minInd;
}
int getMax(int arr[], int n) {
    int maxInd = 0;
    for(int i = 1; i < n; i++) if(arr[i] > arr[maxInd]) maxInd = i;
    return maxInd;
}
void minCashFlowRec(int amount[], int n, vector<vector<int>>& ans) {
    int mxCredit = getMax(amount, n), mxDebit = getMin(amount, n);
    if(amount[mxCredit] == 0 && amount[mxDebit] == 0) return;
    int minVal = min(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= minVal;
    amount[mxDebit] += minVal;
    ans[mxDebit][mxCredit] = minVal;
    minCashFlowRec(amount, n, ans);
}
vector<vector<int>> minCashFlow(vector<vector<int>>& graph, int n) {
    int amount[n] = {0};
    for(int p = 0; p < n; p++) {
        for(int i = 0; i < n; i++) {
            amount[p] += (graph[i][p] - graph[p][i]);
        }
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));
    minCashFlowRec(amount, n, ans);
    return ans;
}

