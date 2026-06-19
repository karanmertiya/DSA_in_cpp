// Time Complexity: O(2^(N/2) * log(2^(N/2)))
// Space Complexity: O(2^(N/2))
// Explanation: Divide the array into two halves. Find all possible subset sums for both halves (`sum1` and `sum2`). Sort `sum2`. For each sum in `sum1`, we need to find the number of elements in `sum2` that satisfy `A - sum <= x <= B - sum`. This can be done using Binary Search (`upper_bound` - `lower_bound`).

void getSubsetSums(vector<int>& arr, int st, int end, long long sum, vector<long long>& res) {
    if(st > end) {
        res.push_back(sum);
        return;
    }
    getSubsetSums(arr, st + 1, end, sum + arr[st], res);
    getSubsetSums(arr, st + 1, end, sum, res);
}
long long solve(vector<int>& arr, long long A, long long B) {
    int n = arr.size();
    vector<long long> left, right;
    getSubsetSums(arr, 0, n / 2 - 1, 0, left);
    getSubsetSums(arr, n / 2, n - 1, 0, right);
    sort(right.begin(), right.end());
    long long count = 0;
    for(long long x : left) {
        auto low = lower_bound(right.begin(), right.end(), A - x);
        auto high = upper_bound(right.begin(), right.end(), B - x);
        count += (high - low);
    }
    return count;
}

