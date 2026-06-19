// Time Complexity: O(N * L * 26) where L is word length
// Space Complexity: O(N)
// Explanation: Use BFS. Insert words from `wordList` into a hash set for O(1) lookup. Push `{beginWord, 1}` to a queue and remove it from the set. Pop a word, change each character one by one to 'a'-'z'. If the new word is in the set, push `{newWord, steps+1}` and remove from set. If `newWord == endWord`, return `steps+1`.

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);
    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord) return steps;
        for(int i = 0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

