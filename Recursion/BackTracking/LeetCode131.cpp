#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

// Leetcode 131. Palindrome Partitioning

/*
Problem Statement: Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

Example:
    Testcase 1:
        


*/
// class Solution {
//     public:

//         bool isPalin(string s){
//             string s2 = s;
//             reverse(s2.begin(), s2.end());
//             return s2 == s;
//         }
        
//         void getAllPart(string s, vector<string> &part, vector<vector<string>> &ans){
//             if(s.size() == 0){
//                 ans.push_back(part);
//                 return;
//             }

//             for(int i = 0; i < s.size(); i++){
//                 string temp = s.substr(0, i + 1);

//                 if(isPalin(temp)){
//                     part.push_back(temp);
//                     getAllPart(s.substr(i + 1), part, ans);
//                     part.pop_back();
//                 }
//             }

//         }
//         vector<vector<string>> partition(string s) {
//             vector<vector<string>> ans;
//             vector<string> part;

//             getAllPart(s, part, ans);

//             return ans;
//         }
//     };


class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {

        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void helper(string &s,
                int idx,
                vector<string> &path,
                vector<vector<string>> &ans) {

        // Base case
        if (idx == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible partition
        for (int i = idx; i < s.size(); i++) {

            // Check if s[idx...i] is palindrome
            if (isPalindrome(s, idx, i)) {

                // Choose
                path.push_back(s.substr(idx, i - idx + 1));

                // Explore
                helper(s, i + 1, path, ans);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        helper(s, 0, path, ans);

        return ans;
    }
};

int main(){
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
            }
            cout << endl;
            }
            return 0;
}