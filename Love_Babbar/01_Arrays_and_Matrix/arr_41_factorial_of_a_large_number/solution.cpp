// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
vector<int> factorial(int N) {
    vector<int> res;
    res.push_back(1);
    for(int x = 2; x <= N; x++) {
        int carry = 0;
        for(int i = 0; i < res.size(); i++) {
            int prod = res[i] * x + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }
        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// Time Complexity: O(N^2)
// Space Complexity: O(N log(N!))
// Explanation: Optimal: Use an array to store the result. Initially, it holds 1. Multiply the array by numbers from 2 to N. The multiplication is done school-style by carrying over remainders to the next index.

vector<int> factorial(int N) {
    vector<int> res;
    res.push_back(1);
    for(int x = 2; x <= N; x++) {
        int carry = 0;
        for(int i = 0; i < res.size(); i++) {
            int prod = res[i] * x + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }
        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

