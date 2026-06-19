// Time Complexity: O(1) visit, O(steps) back/forward
// Space Complexity: O(N) for URLs
// Explanation: Use a Doubly Linked List. Each visit creates a new node, clearing forward history. Back and forward operations just traverse the pointers up to `steps` times.

class BrowserHistory {
    struct Node {
        string url;
        Node *prev, *next;
        Node(string u): url(u), prev(nullptr), next(nullptr) {}
    };
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }
    string back(int steps) {
        while(steps > 0 && curr->prev) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    string forward(int steps) {
        while(steps > 0 && curr->next) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

