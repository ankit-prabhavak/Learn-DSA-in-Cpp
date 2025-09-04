#include <iostream>
#include <unordered_map>
#include <queue>



using namespace std;

// Function to find the first unique character in a string
char firstUniqueChar(const string& str) {
    unordered_map<char, int> charCount;
    queue<char> charQueue;

    // Count occurrences of each character and maintain their order
    for (char ch : str) {
        
        if(charCount.find(ch) == charCount.end()) {
            charCount[ch] = 1;
            charQueue.push(ch);
        } else {
            charCount[ch]++;
        }
        // Remove characters from the front of the queue that are no longer unique
        while(!charQueue.empty() && charCount[charQueue.front()] > 1) {
            charQueue.pop();
        }

    }

    return charQueue.empty() ? '\0' : charQueue.front();
}

// Example usage
int main() {
    string str = "level";
    char result = firstUniqueChar(str);
    if (result != '\0') {
        cout << "The first unique character is: " << result << endl;
    } else {
        cout << "No unique character found." << endl;
    }
    return 0;
}