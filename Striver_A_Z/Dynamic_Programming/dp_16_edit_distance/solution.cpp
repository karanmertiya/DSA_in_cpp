// Time Complexity: O(N * M)
// Space Complexity: O(M)
// Explanation: If chars match, move both pointers. Else, try all 3 ops: 1 + min(insert(i, j-1), delete(i-1, j), replace(i-1, j-1)). Space optimized to 1D.

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int j=0; j<=m; j++) prev[j] = j;
    for(int i=1; i<=n; i++) {
        cur[0] = i;
        for(int j=1; j<=m; j++) {
            if(word1[i-1] == word2[j-1]) cur[j] = prev[j-1];
            else cur[j] = 1 + min({prev[j-1], prev[j], cur[j-1]});
        }
        prev = cur;
    }
    return prev[m];
}

