// Time Complexity: O(N^2) or worse
// Space Complexity: O(N) or O(1)
// Explanation: Brute Force: Standard unoptimized approach. (TODO: Implement specific logic)

// TODO: Implement Brute Force
class MyHashSet {
    vector<list<int>> buckets;
    int size = 10000;
public:
    MyHashSet() {
        buckets.resize(size);
    }
    void add(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it == buckets[i].end()) buckets[i].push_back(key);
    }
    void remove(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end()) buckets[i].erase(it);
    }
    bool contains(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        return it != buckets[i].end();
    }
};

// Time Complexity: O(1) average, O(N) worst case
// Space Complexity: O(N)
// Explanation: Optimal: Use a large array (e.g., size 10000) of linked lists or vectors. The hash function maps `key` to `key % 10000`. To add, if not present in the bucket, append it. To remove, find and erase. To contain, iterate through bucket.

class MyHashSet {
    vector<list<int>> buckets;
    int size = 10000;
public:
    MyHashSet() {
        buckets.resize(size);
    }
    void add(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it == buckets[i].end()) buckets[i].push_back(key);
    }
    void remove(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        if(it != buckets[i].end()) buckets[i].erase(it);
    }
    bool contains(int key) {
        int i = key % size;
        auto it = find(buckets[i].begin(), buckets[i].end(), key);
        return it != buckets[i].end();
    }
};

