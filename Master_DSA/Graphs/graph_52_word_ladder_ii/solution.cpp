// Time Complexity: O(N * L * 26 + Paths)
// Space Complexity: O(N * L)
// Explanation: First, use BFS to build a map storing the shortest distance from `beginWord` to every reachable word. Then use DFS starting from `endWord` backwards to `beginWord` to reconstruct the paths. In DFS, only traverse to words whose distance is exactly 1 less than the current word's distance.

unordered_map<string, int> mpp;
vector<vector<string>> ans;
string b;
void dfs(string word, vector<string>& seq) {
    if(word == b) {
        vector<string> temp = seq;
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        return;
    }
    int steps = mpp[word];
    for(int i = 0; i < word.size(); i++) {
        char original = word[i];
        for(char c = 'a'; c <= 'z'; c++) {
            word[i] = c;
            if(mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<string> q;
    b = beginWord;
    q.push({beginWord});
    mpp[beginWord] = 1;
    st.erase(beginWord);
    int sz = beginWord.size();
    while(!q.empty()) {
        string word = q.front(); q.pop();
        int steps = mpp[word];
        if(word == endWord) break;
        for(int i = 0; i < sz; i++) {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(st.count(word)) {
                    q.push(word);
                    st.erase(word);
                    mpp[word] = steps + 1;
                }
            }
            word[i] = original;
        }
    }
    if(mpp.find(endWord) != mpp.end()) {
        vector<string> seq;
        seq.push_back(endWord);
        dfs(endWord, seq);
    }
    return ans;
}

