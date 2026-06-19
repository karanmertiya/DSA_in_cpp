// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Use a queue to maintain the order of characters and an array to keep track of their frequencies. For each character, increment its frequency and push it to the queue. Then, while the queue is not empty and the frequency of the front character is greater than 1, pop it. If the queue is empty, append '#', else append the front character.

string FirstNonRepeating(string A) {
    vector<int> freq(26, 0);
    queue<char> q;
    string res = "";
    for(char c : A) {
        freq[c - 'a']++;
        q.push(c);
        while(!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        if(q.empty()) res += '#';
        else res += q.front();
    }
    return res;
}

