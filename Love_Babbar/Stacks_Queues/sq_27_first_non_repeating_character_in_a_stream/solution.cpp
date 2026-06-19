// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Use a frequency array or hash map to count character occurrences. Use a queue to maintain the order of characters. When a character arrives, increment its count and push to queue. While the queue is not empty and the front element's count > 1, pop it. The front is the answer.

string FirstNonRepeating(string A){
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";
    for(int i = 0; i < A.length(); i++) {
        count[A[i]]++;
        q.push(A[i]);
        while(!q.empty()) {
            if(count[q.front()] > 1) q.pop();
            else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) ans.push_back('#');
    }
    return ans;
}

