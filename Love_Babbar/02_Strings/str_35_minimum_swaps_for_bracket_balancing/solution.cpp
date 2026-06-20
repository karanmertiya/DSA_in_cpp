// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Keep track of the number of opening and closing brackets, and an `imbalance` counter. When encountering `[`, decrease imbalance. When encountering `]`, increase imbalance. The number of swaps is updated when an imbalance is found and we find the next `[`.

int minimumNumberOfSwaps(string S){
    int open = 0, close = 0, fault = 0, ans = 0;
    for(int i = 0; i < S.length(); i++) {
        if(S[i] == ']') {
            close++;
            fault = close - open;
        } else {
            open++;
            if(fault > 0) {
                ans += fault;
                fault--;
            }
        }
    }
    return ans;
}

