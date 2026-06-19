// Time Complexity: O(N)
// Space Complexity: O(1)
// Explanation: 1) XOR all elements. Result is XOR of the two odd numbers. 2) Find the rightmost set bit in the result. 3) Divide array elements into two buckets based on this set bit. 4) XORing the two buckets individually yields the two numbers.

vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int xor_all = 0;
    for(int i=0; i<N; i++) xor_all ^= Arr[i];
    long long int right_set_bit = xor_all & ~(xor_all - 1);
    long long int x = 0, y = 0;
    for(int i=0; i<N; i++) {
        if(Arr[i] & right_set_bit) x ^= Arr[i];
        else y ^= Arr[i];
    }
    if(x < y) swap(x, y);
    return {x, y};
}

