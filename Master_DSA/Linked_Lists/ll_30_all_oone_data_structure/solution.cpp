// Time Complexity: O(1) amortized
// Space Complexity: O(N)
// Explanation: Maintain a DLL where each node represents a specific frequency and contains a set of strings. Use a hash map mapping strings to their current bucket. On inc/dec, move the string to the adjacent bucket (create if necessary). Max is tail->prev, Min is head->next.

class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
        Bucket *prev, *next;
        Bucket(int c): count(c), prev(nullptr), next(nullptr) {}
    };
    Bucket *head, *tail;
    unordered_map<string, Bucket*> m;
    void addBucket(Bucket* prev, Bucket* newBucket) {
        newBucket->prev = prev;
        newBucket->next = prev->next;
        prev->next->prev = newBucket;
        prev->next = newBucket;
    }
    void removeBucket(Bucket* bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        delete bucket;
    }
public:
    AllOne() {
        head = new Bucket(0); tail = new Bucket(0);
        head->next = tail; tail->prev = head;
    }
    void inc(string key) {
        if(m.find(key) != m.end()) {
            Bucket* curr = m[key];
            Bucket* nxt = curr->next;
            if(nxt == tail || nxt->count != curr->count + 1) {
                addBucket(curr, new Bucket(curr->count + 1));
                nxt = curr->next;
            }
            nxt->keys.insert(key);
            m[key] = nxt;
            curr->keys.erase(key);
            if(curr->keys.empty()) removeBucket(curr);
        } else {
            Bucket* nxt = head->next;
            if(nxt == tail || nxt->count != 1) {
                addBucket(head, new Bucket(1));
                nxt = head->next;
            }
            nxt->keys.insert(key);
            m[key] = nxt;
        }
    }
    void dec(string key) {
        Bucket* curr = m[key];
        if(curr->count == 1) {
            m.erase(key);
        } else {
            Bucket* prv = curr->prev;
            if(prv == head || prv->count != curr->count - 1) {
                addBucket(curr->prev, new Bucket(curr->count - 1));
                prv = curr->prev;
            }
            prv->keys.insert(key);
            m[key] = prv;
        }
        curr->keys.erase(key);
        if(curr->keys.empty()) removeBucket(curr);
    }
    string getMaxKey() {
        if(tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }
    string getMinKey() {
        if(head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};

