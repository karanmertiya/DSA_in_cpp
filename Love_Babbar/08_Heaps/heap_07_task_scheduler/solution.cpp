// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Find max frequency `max_f`. Calculate idle slots `(max_f - 1) * n`. Iterate remaining frequencies and subtract from idle slots. Return `tasks.length + max(0, idle_slots)`.

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    int max_f = 0, count_max = 0;
    for(char c : tasks) {
        freq[c - 'A']++;
        if(freq[c - 'A'] > max_f) {
            max_f = freq[c - 'A'];
            count_max = 1;
        } else if(freq[c - 'A'] == max_f) count_max++;
    }
    int ans = (max_f - 1) * (n + 1) + count_max;
    return max(ans, (int)tasks.size());
}

