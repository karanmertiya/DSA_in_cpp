// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation: Since `encoded[i] = arr[i] ^ arr[i+1]`, it implies `arr[i+1] = arr[i] ^ encoded[i]`. We have `arr[0]`, so we can iteratively find the rest.

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> arr(encoded.size() + 1);
    arr[0] = first;
    for(int i=0; i<encoded.size(); i++) {
        arr[i+1] = arr[i] ^ encoded[i];
    }
    return arr;
}

