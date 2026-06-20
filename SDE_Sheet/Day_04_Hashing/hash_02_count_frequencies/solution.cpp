// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Explanation: Brute Force: Use two nested loops to count frequency of each element, marking visited ones.

void countFreq(vector<int>& arr) {
    int n = arr.size();
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(N) (Trade-off)
// Explanation: Optimal: Use two nested loops to count occurrences. Mark visited elements to avoid recounting.

#include <vector>\n#include <iostream>\n\n#include <unordered_map>\nvoid countFreq(std::vector<int>& arr) {\n    std::unordered_map<int, int> freq;\n    for(int num : arr) {\n        freq[num]++;\n    }\n    for(auto it : freq) {\n        std::cout << it.first << \" \" << it.second << \"\\n\";\n    }\n}

