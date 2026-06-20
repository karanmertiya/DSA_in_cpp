// Time Complexity: O(log(A^B))
// Space Complexity: O(1)
// Explanation: Take the XOR of A and B (`A ^ B`). The number of set bits in the result is the number of bits that need to be flipped. Use Brian Kernighan's algorithm to count.

int countBitsFlip(int a, int b){
    int n = a ^ b;
    int count = 0;
    while(n > 0) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

