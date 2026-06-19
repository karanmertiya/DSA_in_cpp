// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Explanation: Use a map (TreeMap in C++) to store frequencies. Iterate through map. If a number has count > 0, we must form a group starting from it. Decrement counts of `num, num+1, ..., num+groupSize-1`.

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size() % groupSize != 0) return false;
    map<int, int> mpp;
    for(int card : hand) mpp[card]++;
    for(auto it : mpp) {
        if(it.second > 0) {
            int count = it.second;
            for(int i=0; i<groupSize; i++) {
                if(mpp[it.first + i] < count) return false;
                mpp[it.first + i] -= count;
            }
        }
    }
    return true;
}

