// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: Two Pointers from ends. Area is `min(h[left], h[right]) * width`. Move the pointer with the smaller height to seek a potentially taller line.

#include <vector>
#include <algorithm>
int maxArea(std::vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while(left < right) {
        int area = std::min(height[left], height[right]) * (right - left);
        max_area = std::max(max_area, area);
        if(height[left] < height[right]) left++;
        else right--;
    }
    return max_area;
}

