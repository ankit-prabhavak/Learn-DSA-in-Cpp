
// LeetCode 146: LRU Cache
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists
// or insert the key-value pair if the key does not exist. When the cache reaches its capacity, 
// it should invalidate the least recently used item before inserting a new item.


// Approach 1: Using a Doubly Linked List and Hash Map
// We can use a doubly linked list to maintain the order of usage of the keys, 
//and a hash map to store the key-value pairs and their corresponding iterators in the linked list.

/*
class LRUCache {
public:
    int cap;

    // key -> {value, iterator}
    list<int> dll;
    unordered_map<int, pair<int, list<int>::iterator>> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        // key not found
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        // move key to front (most recently used)
        dll.erase(mp[key].second);
        dll.push_front(key);

        // update iterator
        mp[key].second = dll.begin();

        return mp[key].first;
    }
    
    void put(int key, int value) {

        // key already exists
        if(mp.find(key) != mp.end()) {

            // remove old position
            dll.erase(mp[key].second);
        }

        // if cache full
        else if(mp.size() == cap) {

            // remove least recently used key
            int lru = dll.back();
            dll.pop_back();
            mp.erase(lru);
        }

        // insert at front
        dll.push_front(key);

        // store value + iterator
        mp[key] = {value, dll.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
