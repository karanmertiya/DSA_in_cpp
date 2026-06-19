// Time Complexity: O(4^N)
// Space Complexity: O(N)
// Explanation: Calculate sum. If sum % 4 != 0, return false. Target side length is sum / 4. Sort matchsticks in descending order to optimize. Create an array `sides` of size 4. For each matchstick, try adding it to one of the 4 sides. If a side equals the target or is less, recurse.

bool solve(vector<int>& arr, vector<int>& sides, int target, int ind) {
    if(ind == arr.size()) {
        return sides[0] == target && sides[1] == target && sides[2] == target;
    }
    for(int i = 0; i < 4; i++) {
        if(sides[i] + arr[ind] <= target) {
            sides[i] += arr[ind];
            if(solve(arr, sides, target, ind + 1)) return true;
            sides[i] -= arr[ind];
        }
        if(sides[i] == 0) break;
    }
    return false;
}
bool makesquare(vector<int>& matchsticks) {
    long long sum = 0;
    for(int m : matchsticks) sum += m;
    if(sum % 4 != 0 || matchsticks.size() < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    vector<int> sides(4, 0);
    return solve(matchsticks, sides, sum / 4, 0);
}

