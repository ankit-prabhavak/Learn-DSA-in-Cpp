#include <iostream>
#include <deque>

using namespace std;

class FrontMiddleBackQueue {
public:
    deque<int> left, right;

    FrontMiddleBackQueue() {}

    // Helper to balance the two deques
    void balance() {
        // left can have at most one more element than right
        while (left.size() > right.size() + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
        while (left.size() < right.size()) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        left.push_back(val);
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (left.empty() && right.empty()) return -1;
        int val;
        if (!left.empty()) {
            val = left.front();
            left.pop_front();
        } else {
            val = right.front();
            right.pop_front();
        }
        balance();
        return val;
    }

    int popMiddle() {
        if (left.empty() && right.empty()) return -1;
        int val;
        if (left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = left.back();
            left.pop_back();
        }
        balance();
        return val;
    }

    int popBack() {
        if (left.empty() && right.empty()) return -1;
        int val;
        if (!right.empty()) {
            val = right.back();
            right.pop_back();
        } else {
            val = left.back();
            left.pop_back();
        }
        balance();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */