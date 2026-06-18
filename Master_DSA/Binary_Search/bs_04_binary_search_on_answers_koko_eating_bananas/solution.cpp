// Time Complexity: O(N log(Max(Pile))) (Constraint)
// Space Complexity: O(1)
// Explanation: Search space is `1` to `max(piles)`. Calculate total hours for `mid`. If possible, try a slower speed (left half).

#include <vector>
#include <algorithm>
#include <cmath>

int minEatingSpeed(std::vector<int>& piles, int h) {
    auto canEat = [&](int speed) {
        long long hours = 0;
        for(int p : piles) hours += std::ceil((double)p / speed);
        return hours <= h;
    };
    
    int low = 1, high = *std::max_element(piles.begin(), piles.end());
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canEat(mid)) {
            ans = mid;
            high = mid - 1; // Try slower
        } else {
            low = mid + 1; // Need to eat faster
        }
    }
    return ans;
}

