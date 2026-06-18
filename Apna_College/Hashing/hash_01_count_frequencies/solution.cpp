// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use two nested loops to count occurrences. Mark visited elements to avoid recounting.

#include <vector>
#include <iostream>

void countFreqBrute(std::vector<int>& arr) {
    std::vector<bool> visited(arr.size(), false);
    for(int i=0; i<arr.size(); i++) {
        if(visited[i]) continue;
        int count = 1;
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
    }
}

// Time Complexity: O(N) (Constraint)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use a Hash Map to store the frequencies in a single pass.

#include <vector>
#include <unordered_map>

void countFreqOptimal(std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    for(int num : arr) {
        freq[num]++;
    }
}

