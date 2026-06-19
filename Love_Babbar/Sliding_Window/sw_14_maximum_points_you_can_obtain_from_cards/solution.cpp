// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Instead of picking cards from the ends, find the subarray of length `N - K` that has the minimum sum. Subtract this minimum sum from the total sum of the array. That gives the maximum score.

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int totalSum = 0, windowSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += cardPoints[i];
        if(i < n - k) windowSum += cardPoints[i];
    }
    int minWindowSum = windowSum;
    for(int i = n - k; i < n; i++) {
        windowSum += cardPoints[i] - cardPoints[i - (n - k)];
        minWindowSum = min(minWindowSum, windowSum);
    }
    return totalSum - minWindowSum;
}

