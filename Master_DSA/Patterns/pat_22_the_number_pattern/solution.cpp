// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void printPattern(int n) {
    for(int i = 0; i < 2 * n - 1; i++) {
        for(int j = 0; j < 2 * n - 1; j++) {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << (n - min({top, left, right, down})) << " ";
        }
        cout << endl;
    }
}

int main() {
    printPattern(4);
    return 0;
}

