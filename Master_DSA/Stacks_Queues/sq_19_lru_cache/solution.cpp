// Time Complexity: O(1) for get and put
// Space Complexity: O(Capacity)
// Explanation: Use a hash map to store keys to Node pointers. Use a doubly linked list to track the usage history. The head of the DLL represents the most recently used, and the tail represents the least recently used. On `get` or `put`, move the accessed node to the head. If capacity is exceeded, remove the node before the tail.

class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* existingnode = m[key];
            m.erase(key);
            deleteNode(existingnode);
        }
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

