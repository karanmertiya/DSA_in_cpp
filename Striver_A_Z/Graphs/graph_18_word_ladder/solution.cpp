// Time Complexity: O(N * M * 26)
// Space Complexity: O(N * M)
// Explanation: Use BFS to find the shortest path. Put the `beginWord` in a queue. For each word popped from the queue, try changing every character to all 26 lowercase letters. If the new word is in the dictionary, push it to the queue with level + 1 and remove it from dictionary to avoid cycles.

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    if(st.find(beginWord) != st.end()) st.erase(beginWord);
    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        for(int i = 0; i < word.length(); i++) {
            char orig = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = orig;
        }
    }
    return 0;
}

