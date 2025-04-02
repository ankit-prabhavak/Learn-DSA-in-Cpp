#include <iostream>
#include <string> 
#include <algorithm> // for reverse function

using namespace std;

int main(){
    // Declare a string
    string str = "hello world";
    // Print the string
    cout << "String: " << str << endl;  // This will print the string "hello world"

    // String are dynamic in nature and can grow and shrink in size but this is not the case with char array

    string str2 =  "Learning C++ is fun!";
    cout << str + " " + str2 << endl; // This will print the string "hello world Learning C++ is fun!"

    cout <<(str == str2)<< endl; // This will print 0 (false) because the strings are not equal. This cannot be done with char arrays
    cout << (str < str2) << endl; // This will print 1 (true) because "hello world" is less than "Learning C++ is fun!"

    cout << str.length() << endl; // This will print the length of the string "hello world" which is 11

    //Input a string from the user
    string word;
    cout << "Enter a string: ";
    cin >> word; // Read a string from the user without spaces
    cout << "You entered: " << word << endl; // This will print the string entered by the user

    string word2;
    cout << "Enter a string with spaces: ";
    getline(cin, word2); // Read a string from the user with spaces
    cout << "You entered: " << word2 << endl; // This will print the string entered by the user


    // Print each character of the string
    for (int i = 0; i < str.length(); i++) {
        cout << str[i]; // This will print each character of the string "hello world"
    }
    cout << endl; // Print a new line

    for(char ch : str2){
        cout << ch; // This will print each character of the string "Learning C++ is fun!"
    }
    cout << endl; // Print a new line

    reverse(word2.begin(), word2.end()); // Reverse the string "Learning C++ is fun!"
    cout << "Reversed string: " << word2 << endl; // This will print the reversed string


    return 0;
}