// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<vector<int>> fourSum(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && arr[j] == arr[j-1]) continue;
            int left = j + 1, right = n - 1;
            while(left < right) {
                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                if(sum == k) {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left++; right--;
                    while(left < right && arr[left] == arr[left-1]) left++;
                    while(left < right && arr[right] == arr[right+1]) right--;
                } else if(sum < k) left++;
                else right--;
            }
        }
    }
    return ans;
}

// Time Complexity: O(N^3)
// Space Complexity: O(1)
// Explanation: Optimal: Sort the array. Use two nested loops for the first two elements. Then use two pointers for the remaining two elements to find the target sum. Skip duplicates at all levels.

vector<vector<int>> fourSum(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && arr[j] == arr[j-1]) continue;
            int left = j + 1, right = n - 1;
            while(left < right) {
                long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                if(sum == k) {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left++; right--;
                    while(left < right && arr[left] == arr[left-1]) left++;
                    while(left < right && arr[right] == arr[right+1]) right--;
                } else if(sum < k) left++;
                else right--;
            }
        }
    }
    return ans;
}

