# TCS NQT Coding Mock

**Difficulty:** Easy | **Tags:** `Strings`, `GCD`, `Math`

---

## Problem Statement

For two strings $s$ and $t$, we say that **"$t$ divides $s$"** if and only if $s$ can be formed by concatenating $t$ with itself one or more times.

Given two strings `str1` and `str2`, return the **largest string** $x$ such that $x$ divides both `str1` and `str2`.

If no such string exists, print an empty string.

---

## Input Format

* **First line:** A string `str1`.
* **Second line:** A string `str2`.

---

## Output Format

* Print the largest string that divides both `str1` and `str2`. If no common divisor string exists, print an empty string.

---

## Constraints

* $1 \le \vert{}\text{str1}\vert{}, \vert{}\text{str2}\vert{} \le 1000$
* Both strings consist of uppercase English letters.

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
ABCABC
ABC

```

**Output:**

```text
ABC

```

**Explanation:**

* $\text{ABCABC} = \text{ABC} + \text{ABC}$
* $\text{ABC} = \text{ABC}$

Hence, the greatest common divisor string is **ABC**.

---

### Sample Test Case 2

**Input:**

```text
ABABAB
ABAB

```

**Output:**

```text
AB

```

**Explanation:**

* $\text{ABABAB} = \text{AB} + \text{AB} + \text{AB}$
* $\text{ABAB} = \text{AB} + \text{AB}$

The largest common divisor is **AB**.

---

### Sample Test Case 3

**Input:**

```text
LEET
CODE

```

**Output:**

```text


```

*(Empty String)*

---

### Sample Test Case 4

**Input:**

```text
AAAAAA
AAA

```

**Output:**

```text
AAA

```

---

### Sample Test Case 5

**Input:**

```text
XYZXYZXYZ
XYZ

```

**Output:**

```text
XYZ

```

---

## Approach

A common divisor string exists **if and only if**:

$$\text{str1} + \text{str2} == \text{str2} + \text{str1}$$

If the condition holds true:

1. Calculate the Greatest Common Divisor ($\text{GCD}$) of the lengths of both strings: $L = \gcd(\vert{}\text{str1}\vert{}, \vert{}\text{str2}\vert{})$.
2. The substring of `str1` from index $0$ to $L - 1$ will be the largest string that divides both `str1` and `str2`.

If the condition fails, no common repeating base string exists, so return `""`.

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n + m)$ — String concatenation comparison takes time proportional to the sum of lengths ($n = \vert{}\text{str1}\vert{}, m = \vert{}\text{str2}\vert{}$).
* **Space Complexity:** $\mathcal{O}(1)$ — Auxiliary space used is constant (excluding storage for string operations).

---

## C++ Solution

```cpp
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

string gcdOfStrings(const string& str1, const string& str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }

    int gcdLength = std::gcd(static_cast<int>(str1.length()), static_cast<int>(str2.length()));
    return str1.substr(0, gcdLength);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    if (cin >> str1 >> str2) {
        cout << gcdOfStrings(str1, str2) << "\n";
    }

    return 0;
}

```

---

## Dry Run

**Input:**

```text
str1 = "ABCABC"
str2 = "ABC"

```

1. **Check Concatenation Equality:**
* `str1 + str2` = `"ABCABC"` + `"ABC"` = `"ABCABCABC"`
* `str2 + str1` = `"ABC"` + `"ABCABC"` = `"ABCABCABC"`
* Since `"ABCABCABC" == "ABCABCABC"`, a valid GCD string exists.


2. **Compute GCD of Lengths:**
* $\vert{}\text{str1}\vert{} = 6$
* $\vert{}\text{str2}\vert{} = 3$
* $\gcd(6, 3) = 3$


3. **Extract Substring:**
* Substring of `str1` of length `3` starting at index `0` $\rightarrow$ `"ABC"`



**Output:** `"ABC"`