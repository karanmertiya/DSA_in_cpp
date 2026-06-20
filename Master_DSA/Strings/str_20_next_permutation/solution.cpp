// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Traverse from right to find the first element smaller than the element to its right. Then, find the smallest element to its right that is greater than it. Swap them, and reverse the subarray after the first element's index.

vector<int> nextPermutation(int N, vector<int> arr){
    int i = N - 2;
    while(i >= 0 && arr[i] >= arr[i + 1]) i--;
    if(i >= 0) {
        int j = N - 1;
        while(arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
    }
    reverse(arr.begin() + i + 1, arr.end());
    return arr;
}

