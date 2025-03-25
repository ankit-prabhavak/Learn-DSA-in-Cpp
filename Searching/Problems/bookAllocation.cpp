#include <iostream>
#include <vector>

using namespace std;


bool isValid(vector<int> &arr, int n, int m, int k){ // k = maximum allowed pages
    int pages = 0, stu = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k ) {
            return false;
        }

        if(pages + arr[i] <= k) {
            pages += arr[i];
        }else{
                stu++;
                pages = arr[i];
        }
    }

    return stu > m ? false : true;
}

int allocateBooks(vector<int>  &arr, int n, int m){
    int sum = 0;

    for(int i : arr){
        sum += i;
    }

    int st = 0, end = sum, ans = -1;

    while(st <= end){
        int mid = st + (end - st)/2;

        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    
    return ans;
}



int main(){
    vector<int> arr = {1, 2, 3, 4};

    int n = 4, m = 2;
    int result = allocateBooks(arr, n, m);
    cout << result << endl;
    return 0;

}


/*
Time Complexity: O(log N * n )
Space Complexity: O(1)

*/


/*
Problem Statement:

You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
*/