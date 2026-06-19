// Time Complexity: O(E)
// Space Complexity: O(E)
// Explanation: Store the children of the first tree in a stack (LIFO) and the children of the second tree in a queue (FIFO) for each node using hash maps. Then compare if the stack top matches the queue front for all nodes.

int checkMirrorTree(int n, int e, int A[], int B[]) {
    unordered_map<int, stack<int>> s;
    unordered_map<int, queue<int>> q;
    for(int i = 0; i < 2 * e; i += 2) {
        s[A[i]].push(A[i+1]);
        q[B[i]].push(B[i+1]);
    }
    for(auto it : s) {
        int node = it.first;
        while(!s[node].empty() && !q[node].empty()) {
            if(s[node].top() != q[node].front()) return 0;
            s[node].pop();
            q[node].pop();
        }
        if(!s[node].empty() || !q[node].empty()) return 0;
    }
    return 1;
}

