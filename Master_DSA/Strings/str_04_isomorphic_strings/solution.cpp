// Time Complexity: O(N) (Constraint)
// Space Complexity: O(1) (Constraint)
// Explanation: Use two arrays to map characters from `s -> t` and `t -> s` ensuring a 1-to-1 bijective mapping.

#include <string>
#include <vector>

bool isIsomorphic(std::string s, std::string t) {
    if(s.length() != t.length()) return false;
    std::vector<int> mapST(256, -1);
    std::vector<int> mapTS(256, -1);
    
    for(int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];
        if(mapST[c1] != -1 && mapST[c1] != c2) return false;
        if(mapTS[c2] != -1 && mapTS[c2] != c1) return false;
        mapST[c1] = c2;
        mapTS[c2] = c1;
    }
    return true;
}

