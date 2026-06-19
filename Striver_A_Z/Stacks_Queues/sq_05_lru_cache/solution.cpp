// Time Complexity: O(1) per operation
// Space Complexity: O(Capacity)
// Explanation: Use a Hash Map and a Doubly Linked List. The Map stores `key -> Node*`. The DLL maintains recency (head is most recent, tail is least recent). Update DLL pointers on access/insert.

class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {}
    };
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp; newnode->prev = head;
        head->next = newnode; temp->prev = newnode;
    }
    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev, *delnext = delnode->next;
        delprev->next = delnext; delnext->prev = delprev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity; head->next = tail; tail->prev = head;
    }
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->val;
            m.erase(key); deleteNode(resnode); addNode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* existing = m[key];
            m.erase(key); deleteNode(existing);
        }
        if(m.size() == cap) {
            m.erase(tail->prev->key); deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

