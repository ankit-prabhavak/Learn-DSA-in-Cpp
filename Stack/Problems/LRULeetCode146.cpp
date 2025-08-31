#include <iostream>
#include <unordered_map>
using namespace std;

// Doubly linked list node
struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }

};

class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node* head; // dummy head
    Node* tail; // dummy tail

    // Add node right after head
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove node from list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            removeNode(node);
            addToFront(node); // move to front (most recently used)
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        } else {
            if (cache.size() == cap) {
                // Remove least recently used node (before tail)
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            addToFront(node);
        }
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

/*
Intuition:
- Use a doubly linked list to keep track of usage order (most recent at front).
- Use a hashmap for O(1) access to nodes.
- On get/put, move the node to the front.
- If capacity exceeded, remove the least recently used node (at the back).
*/