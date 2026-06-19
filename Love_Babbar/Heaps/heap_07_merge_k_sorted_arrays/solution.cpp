// Time Complexity: O(K^2 log K)
// Space Complexity: O(K)
// Explanation: Create a min-heap that stores a tuple: (value, array_index, element_index). Push the first element of each of the K arrays into the heap. While the heap is not empty, pop the minimum element, add it to the result, and if the array from which it was popped has more elements, push the next element to the heap.

class Element {
public:
    int val, row, col;
    Element(int v, int r, int c) : val(v), row(r), col(c) {}
};
struct Compare {
    bool operator()(Element a, Element b) {
        return a.val > b.val;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<Element, vector<Element>, Compare> pq;
    vector<int> res;
    for(int i = 0; i < K; i++) {
        pq.push(Element(arr[i][0], i, 0));
    }
    while(!pq.empty()) {
        Element curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        if(curr.col + 1 < K) {
            pq.push(Element(arr[curr.row][curr.col + 1], curr.row, curr.col + 1));
        }
    }
    return res;
}

