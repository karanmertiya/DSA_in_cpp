// Time Complexity: O(1) amortized
// Space Complexity: O(Number of elements)
// Explanation: Use an array of linked lists (chaining) for collision resolution. Hash function `key % capacity`. Add: Insert if not present. Remove: Delete node. Contains: Traverse list at `hash(key)`.

class MyHashSet {
    struct Node {
        int val;
        Node* next;
        Node(int v): val(v), next(nullptr) {}
    };
    vector<Node*> buckets;
    int size = 10007;
public:
    MyHashSet() {
        buckets.assign(size, nullptr);
    }
    void add(int key) {
        int idx = key % size;
        Node* curr = buckets[idx];
        while(curr) {
            if(curr->val == key) return;
            curr = curr->next;
        }
        Node* newNode = new Node(key);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
    }
    void remove(int key) {
        int idx = key % size;
        Node* curr = buckets[idx];
        Node* prev = nullptr;
        while(curr) {
            if(curr->val == key) {
                if(prev) prev->next = curr->next;
                else buckets[idx] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    bool contains(int key) {
        int idx = key % size;
        Node* curr = buckets[idx];
        while(curr) {
            if(curr->val == key) return true;
            curr = curr->next;
        }
        return false;
    }
};

