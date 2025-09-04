#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {

    unordered_map<char, int> charCount;
    queue<int> charQueue;

    // Count occurrences of each character and maintain their order
    for (int i = 0; i < s.size(); i++) {
        
        if(charCount.find(s[i]) == charCount.end()) {
            charCount[s[i]] = 1;
            charQueue.push(i);
        } else {
            charCount[s[i]]++;
        }
        // Remove characters from the front of the queue that are no longer unique
        while(!charQueue.empty() && charCount[s[charQueue.front()]] > 1) {
            charQueue.pop();
        }

    }

    return charQueue.empty() ? -1 : charQueue.front();
        
    }
};