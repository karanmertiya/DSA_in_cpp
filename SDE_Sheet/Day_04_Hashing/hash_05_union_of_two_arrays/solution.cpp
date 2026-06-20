// Time Complexity: O(N + M) (Constraint)
// Space Complexity: O(N + M) (Trade-off)
// Explanation: Optimal: Insert all elements from both arrays into a Hash Set. The Set natively drops duplicates.

#include <vector>
#include <unordered_set>

std::vector<int> findUnion(std::vector<int>& a, std::vector<int>& b) {
    std::unordered_set<int> s;
    for(int num : a) s.insert(num);
    for(int num : b) s.insert(num);
    
    std::vector<int> res(s.begin(), s.end());
    return res;
}

