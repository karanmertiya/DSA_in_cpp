// Time Complexity: O(N^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void printPattern(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    printPattern(5);
    return 0;
}

