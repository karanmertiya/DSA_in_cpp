// Time Complexity: O(log N) add, O(1) find
// Space Complexity: O(N)
// Explanation: Maintain two heaps: a max-heap for the smaller half of the numbers, and a min-heap for the larger half. Ensure the max-heap has either the same size or one more element than the min-heap. The median is either the top of the max-heap or the average of the tops.

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {}
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

