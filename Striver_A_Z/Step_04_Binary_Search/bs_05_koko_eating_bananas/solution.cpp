// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>
#include <algorithm>

bool canEat(std::vector<int>& piles, int k, int h) {
    long long hours = 0;
    for(int pile : piles) {
        hours += (pile + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(std::vector<int>& piles, int h) {
    int low = 1, high = *std::max_element(piles.begin(), piles.end());
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canEat(piles, mid, h)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Time Complexity: O(N log(Max(P))) (Constraint)
// Space Complexity: O(1)
// Explanation: Optimal: Search space is `1` to `max(piles)`. For a mid `k`, calculate hours required. If `hours <= h`, it's a valid answer, but search left for smaller `k`.

#include <vector>
#include <algorithm>

bool canEat(std::vector<int>& piles, int k, int h) {
    long long hours = 0;
    for(int pile : piles) {
        hours += (pile + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(std::vector<int>& piles, int h) {
    int low = 1, high = *std::max_element(piles.begin(), piles.end());
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canEat(piles, mid, h)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

