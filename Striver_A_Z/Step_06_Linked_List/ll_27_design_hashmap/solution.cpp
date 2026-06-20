// Time Complexity: O(1) amortized
// Space Complexity: O(Number of elements)
// Explanation: Similar to HashSet, but each node stores a `(key, value)` pair. On Put, if key exists, update value. Else insert new node. On Get, return value if key found, else -1.

class MyHashMap {
    struct Node {
        int key, val;
        Node* next;
        Node(int k, int v): key(k), val(v), next(nullptr) {}
    };
    vector<Node*> buckets;
    int size = 10007;
public:
    MyHashMap() {
        buckets.assign(size, nullptr);
    }
    void put(int key, int value) {
        int idx = key % size;
        Node* curr = buckets[idx];
        while(curr) {
            if(curr->key == key) { curr->val = value; return; }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }
    int get(int key) {
        int idx = key % size;
        Node* curr = buckets[idx];
        while(curr) {
            if(curr->key == key) return curr->val;
            curr = curr->next;
        }
        return -1;
    }
    void remove(int key) {
        int idx = key % size;
        Node* curr = buckets[idx];
        Node* prev = nullptr;
        while(curr) {
            if(curr->key == key) {
                if(prev) prev->next = curr->next;
                else buckets[idx] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

