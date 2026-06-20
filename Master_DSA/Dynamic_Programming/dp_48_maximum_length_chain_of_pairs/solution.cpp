// Time Complexity: O(N log N)
// Space Complexity: O(1)
// Explanation: This is exactly the Activity Selection Problem. Sort the pairs by their second element. Iterate through the sorted pairs and keep track of the end of the last selected pair. If the next pair's start is > last end, select it.

struct val {
    int first;
    int second;
};
bool compare(struct val a, struct val b) {
    return a.second < b.second;
}
int maxChainLen(struct val p[], int n) {
    sort(p, p + n, compare);
    int count = 1;
    int last_end = p[0].second;
    for(int i = 1; i < n; i++) {
        if(p[i].first > last_end) {
            count++;
            last_end = p[i].second;
        }
    }
    return count;
}

