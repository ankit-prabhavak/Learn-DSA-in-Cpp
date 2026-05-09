/** 
What is Dynamic Programming?
Dynamic Programming is a method for solving complex problems by breaking them down into simpler subproblems.
It is applicable when the problem has overlapping subproblems and optimal substructure properties.

Techniques in Dynamic Programming:
----------------------------------
1. Memoization (Top-Down Approach): 
This technique involves storing the results of expensive function calls and returning the cached result when
the same inputs occur again. It is implemented using recursion and a hash map or an array to store results.

2. Tabulation (Bottom-Up Approach): 
This technique involves solving the problem by filling up a table (usually an array) in a bottom-up manner. 
It starts with the smallest subproblems and iteratively builds up to the solution of the original problem.

**/

#include <iostream>
#include <vector>

// Example of Fibonacci using Memoization
int fib_memo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

// Example of Fibonacci using Tabulation
int fib_tab(int n) {
    if (n <= 1) return n;
    std::vector<int> table(n + 1, 0);
    table[1] = 1;
    for (int i = 2; i <= n; ++i) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

int main () {
    std::vector<int> memo(10, -1);
    std::cout << fib_memo(5, memo) << std::endl;
    std::cout << fib_tab(5) << std::endl;
    return 0;
}






















