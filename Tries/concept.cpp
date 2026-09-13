#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            // Create node if it doesn't exist
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        // Mark the last node as the end of a word
        node->isEnd = true;
    }

    // Search for a complete word
    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return node->isEnd;
    }

    // Check whether any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == nullptr) {
                return false;
            }

            node = node->children[index];
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie;

    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("bat");

    // Search
    cout << trie.search("apple") << endl;   // 1
    cout << trie.search("app") << endl;     // 1
    cout << trie.search("appl") << endl;    // 0
    cout << trie.search("banana") << endl;  // 0

    // Prefix search
    cout << trie.startsWith("app") << endl; // 1
    cout << trie.startsWith("apr") << endl; // 1
    cout << trie.startsWith("cat") << endl; // 0

    return 0;
}