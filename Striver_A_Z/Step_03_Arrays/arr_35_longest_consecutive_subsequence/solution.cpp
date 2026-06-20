// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
int findLongestConseqSubseq(int arr[], int N) {
    unordered_set<int> s;
    for(int i = 0; i < N; i++) s.insert(arr[i]);
    int longest = 0;
    for(int num : s) {
        if(s.find(num - 1) == s.end()) {
            int curr = num;
            int count = 1;
            while(s.find(curr + 1) != s.end()) {
                curr++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Optimal: Insert all elements into a hash set. For each element, check if `element - 1` exists. If not, it's the start of a sequence. Then increment to find consecutive elements.

int findLongestConseqSubseq(int arr[], int N) {
    unordered_set<int> s;
    for(int i = 0; i < N; i++) s.insert(arr[i]);
    int longest = 0;
    for(int num : s) {
        if(s.find(num - 1) == s.end()) {
            int curr = num;
            int count = 1;
            while(s.find(curr + 1) != s.end()) {
                curr++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

