// Time Complexity: O(N<sup>2</sup>) (Trade-off)
// Space Complexity: O(N) (Trade-off)
// Explanation: Use two nested loops to count occurrences. Mark visited elements to avoid recounting.

#include <vector>\n#include <iostream>\n\n#include <unordered_map>\nvoid countFreq(std::vector<int>& arr) {\n    std::unordered_map<int, int> freq;\n    for(int num : arr) {\n        freq[num]++;\n    }\n    for(auto it : freq) {\n        std::cout << it.first << \" \" << it.second << \"\\n\";\n    }\n}

