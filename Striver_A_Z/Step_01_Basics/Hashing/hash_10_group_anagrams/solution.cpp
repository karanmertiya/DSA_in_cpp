// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> mpp;
    for(std::string s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        mpp[key].push_back(s);
    }
    std::vector<std::vector<std::string>> ans;
    for(auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

// Time Complexity: O(N * K log K)
// Space Complexity: O(N * K)
// Explanation: Optimal: Use a hash map where the key is the sorted version of the string, and the value is a list of anagrams.

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> mpp;
    for(std::string s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        mpp[key].push_back(s);
    }
    std::vector<std::vector<std::string>> ans;
    for(auto it : mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

