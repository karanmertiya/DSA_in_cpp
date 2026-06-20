// Time Complexity: O(log N) add, O(1) find
// Space Complexity: O(N)
// Explanation: Maintain two heaps: a max-heap for the smaller half of numbers and a min-heap for the larger half. Balance them such that the max-heap has at most 1 more element than the min-heap.

class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if(maxH.size() < minH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    double findMedian() {
        if(maxH.size() > minH.size()) return maxH.top();
        return (maxH.top() + minH.top()) / 2.0;
    }
};

