// Time Complexity: O(1) for get and put
// Space Complexity: O(Capacity)
// Explanation: Maintain a `minFreq` variable. Use one hash map to map `key` to its Node. Use another hash map to map `frequency` to a Doubly Linked List of Nodes with that frequency. When accessing an element, increase its frequency and move it to the corresponding DLL. If capacity is reached, remove the least recently used element from the DLL at `minFreq`.

struct Node {
    int key, value, cnt;
    Node *next, *prev;
    Node(int _key, int _value) { key = _key; value = _value; cnt = 1; }
};
struct List {
    int size;
    Node *head, *tail;
    List() { head = new Node(0, 0); tail = new Node(0, 0); head->next = tail; tail->prev = head; size = 0; }
    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp; node->prev = head;
        head->next = node; temp->prev = node;
        size++;
    }
    void removeNode(Node* node) {
        Node* delprev = node->prev; Node* delnext = node->next;
        delprev->next = delnext; delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSizeCache, minFreq, curSize;
public:
    LFUCache(int capacity) { maxSizeCache = capacity; minFreq = 0; curSize = 0; }
    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) minFreq++;
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) nextHigherFreqList = freqListMap[node->cnt + 1];
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(maxSizeCache == 0) return;
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; node->value = value;
            updateFreqListMap(node);
        } else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++; minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) listFreq = freqListMap[minFreq];
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};

