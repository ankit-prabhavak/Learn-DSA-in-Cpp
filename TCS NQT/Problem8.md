# TCS NQT Coding Mock

## Difficulty
Easy

## Tags
Hash Map, Strings, Simulation

---

# Problem Statement

Write a program to manage expenses from a given total income.

Your program must first read the total income. Then, it repeatedly reads expenses until the user enters **"done"**.

For each expense, read:

- **Category** – A string representing the type of expense (e.g., `Food`, `Shopping`, `Travel`).
- **Expense** – An integer representing the amount spent.

The program must calculate:

1. Total Income
2. Total Expenses
3. Total Savings (`Income - Expenses`)
4. Total expenses for each category.

The categories are **case-sensitive**.

---

# Input Format

- First line contains an integer `income`.
- Each subsequent expense consists of:
  - A string `category`
  - An integer `expense`
- Input terminates when the category is `"done"`.

---

# Output Format

Print the following:

```
Total Income: <income>
Total Expenses: <totalExpenses>
Total Savings: <income-totalExpenses>

<Category1>: <amount>
<Category2>: <amount>
...
```

Print the categories in the order of their first appearance.

---

# Constraints

- `1 ≤ Income ≤ 1,000,000`
- `1 ≤ Expense ≤ 100,000`
- Category names are case-sensitive.
- Number of expense entries ≤ 10^5.

---

# Sample Test Case 1

### Input

```
50000
Food
5000
Travel
3000
Food
2000
Shopping
4000
done
```

### Output

```
Total Income: 50000
Total Expenses: 14000
Total Savings: 36000

Food: 7000
Travel: 3000
Shopping: 4000
```

---

# Sample Test Case 2

### Input

```
30000
Food
5000
Food
2000
done
```

### Output

```
Total Income: 30000
Total Expenses: 7000
Total Savings: 23000

Food: 7000
```

---

# Sample Test Case 3

### Input

```
10000
done
```

### Output

```
Total Income: 10000
Total Expenses: 0
Total Savings: 10000
```

---

# Sample Test Case 4

### Input

```
60000
Travel
15000
Shopping
10000
Bills
8000
Travel
5000
done
```

### Output

```
Total Income: 60000
Total Expenses: 38000
Total Savings: 22000

Travel: 20000
Shopping: 10000
Bills: 8000
```

---

# Sample Test Case 5

### Input

```
20000
Food
5000
food
2000
done
```

### Output

```
Total Income: 20000
Total Expenses: 7000
Total Savings: 13000

Food: 5000
food: 2000
```

---

# Approach

- Read the total income.
- Keep reading categories until `"done"` is encountered.
- Store the total expense for each category using a hash map.
- Maintain a vector storing the order in which categories first appear.
- Compute:
  - Total Expenses
  - Total Savings
- Print the category-wise expense summary.

---

# Time Complexity

```
O(n)
```

where `n` is the number of expense entries.

---

# Space Complexity

```
O(k)
```

where `k` is the number of distinct categories.

---

# C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    int income;
    cin >> income;

    unordered_map<string, int> expenseMap;
    vector<string> order;

    int totalExpense = 0;

    while (true) {

        string category;
        cin >> category;

        if (category == "done")
            break;

        int expense;
        cin >> expense;

        if (expenseMap.find(category) == expenseMap.end())
            order.push_back(category);

        expenseMap[category] += expense;
        totalExpense += expense;
    }

    cout << "Total Income: " << income << endl;
    cout << "Total Expenses: " << totalExpense << endl;
    cout << "Total Savings: " << income - totalExpense << endl;

    cout << endl;

    for (string category : order) {
        cout << category << ": " << expenseMap[category] << endl;
    }

    return 0;
}
```

---

# Dry Run

### Input

```
50000
Food
5000
Travel
3000
Food
2000
Shopping
4000
done
```

Read Income

```
50000
```

Read Expenses

```
Food -> 5000
Travel -> 3000
Food -> +2000
Shopping -> 4000
```

Totals

```
Income = 50000
Expenses = 14000
Savings = 36000
```

Category Totals

```
Food -> 7000
Travel -> 3000
Shopping -> 4000
```

---

# Additional Hidden Test Cases

### Test Case 1

**Input**

```text
10000
done
```

**Output**

```text
Total Income: 10000
Total Expenses: 0
Total Savings: 10000
```

---

### Test Case 2

**Input**

```text
15000
Food
3000
Food
2000
Food
1000
done
```

**Output**

```text
Total Income: 15000
Total Expenses: 6000
Total Savings: 9000

Food: 6000
```

---

### Test Case 3

**Input**

```text
40000
Travel
5000
Food
4000
Bills
7000
Travel
2000
Shopping
3000
done
```

**Output**

```text
Total Income: 40000
Total Expenses: 21000
Total Savings: 19000

Travel: 7000
Food: 4000
Bills: 7000
Shopping: 3000
```

---

### Test Case 4

**Input**

```text
25000
Food
1000
food
2000
FOOD
3000
done
```

**Output**

```text
Total Income: 25000
Total Expenses: 6000
Total Savings: 19000

Food: 1000
food: 2000
FOOD: 3000
```

---

### Test Case 5

**Input**

```text
50000
Rent
15000
Utilities
3000
Rent
5000
Utilities
1000
done
```

**Output**

```text
Total Income: 50000
Total Expenses: 24000
Total Savings: 26000

Rent: 20000
Utilities: 4000
```

---

### Test Case 6

**Input**

```text
100000
Investment
50000
Investment
25000
Travel
10000
done
```

**Output**

```text
Total Income: 100000
Total Expenses: 85000
Total Savings: 15000

Investment: 75000
Travel: 10000
```

---

### Test Case 7

**Input**

```text
5000
A
1000
B
1000
C
1000
D
1000
E
1000
done
```

**Output**

```text
Total Income: 5000
Total Expenses: 5000
Total Savings: 0

A: 1000
B: 1000
C: 1000
D: 1000
E: 1000
```

---

### Test Case 8

**Input**

```text
1000
Misc
999
done
```

**Output**

```text
Total Income: 1000
Total Expenses: 999
Total Savings: 1

Misc: 999
```

---

### Test Case 9

**Input**

```text
70000
Medical
5000
Medical
10000
Medical
7000
done
```

**Output**

```text
Total Income: 70000
Total Expenses: 22000
Total Savings: 48000

Medical: 22000
```

---

### Test Case 10

**Input**

```text
100
Food
40
Travel
20
Shopping
10
Entertainment
5
done
```

**Output**

```text
Total Income: 100
Total Expenses: 75
Total Savings: 25

Food: 40
Travel: 20
Shopping: 10
Entertainment: 5
```

---

## Repository Title

**Expense Manager | Hash Map & String Simulation | TCS NQT Coding Mock | C++**