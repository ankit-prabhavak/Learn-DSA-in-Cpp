#include <iostream>

using namespace std;

int main(){
    // Declare a character array
    char str[] = {'a', 'b', 'c', 'd', 'e'};
    // Print the character array
    cout << "Character array: " << str << endl;  //Not a string, just a char array


    int arr[] = {1, 2, 3, 4, 5};
    cout << arr << endl; // This will print the address of the array
     
    char str2[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    cout << str2 << endl; // This will print the string "abcde"

    char word[] = "hello"; // string literal
    cout << word << endl; // This will print the string "hello"

    cout << word[5] << endl; // This will print the null terminator '\0'


    char word2[100];
    cout << "Enter a string: ";
    cin >> word2; // Read a string from the user without spaces
    cout << "You entered: " << word2 << endl; // This will print the string entered by the user

    char word3[100];
    cout << "Enter a string with spaces: ";
    cin.getline(word3, 100, '$'); // Read a string from the user with spaces and stop at '$'
    


    for(char ch : word3){
        cout << ch; // This will print the string entered by the user
    }
    cout << endl; // Print a new line

    

    return 0;
}