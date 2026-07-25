# TCS NQT Coding Mock

**Difficulty:** Medium | **Tags:** `Strings`, `Caesar Cipher`, `Character Manipulation`

---

## Problem Statement

You are designing a **custom Caesar Cipher**.

In addition to encrypting alphabetic characters, numeric digits (`0-9`) must also be shifted by the given key.

### Encryption Rules:

* Lowercase letters (`a-z`) are shifted cyclically.
* Uppercase letters (`A-Z`) are shifted cyclically.
* Digits (`0-9`) are shifted cyclically.
* Any other character (such as `-`, `_`, `@`, `#`, spaces, etc.) remains unchanged.
* If the key is **negative**, print **`INVALID INPUT`**.

---

## Input Format

* **First line:** The plaintext string.
* **Second line:** An integer `key`.

---

## Output Format

* Print the encrypted string.
* If $\text{key} < 0$, print `INVALID INPUT`.

---

## Constraints

* $1 \le \text{length}(\text{string}) \le 10^5$
* $-10^9 \le \text{key} \le 10^9$
* The string may contain uppercase letters, lowercase letters, digits, spaces, and special characters.

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
Hello123
2

```

**Output:**

```text
Jgnnq345

```

---

### Sample Test Case 2

**Input:**

```text
xyz XYZ
3

```

**Output:**

```text
abc ABC

```

---

### Sample Test Case 3

**Input:**

```text
Test-69
2

```

**Output:**

```text
Vguv-81

```

---

### Sample Test Case 4

**Input:**

```text
OpenAI2025
5

```

**Output:**

```text
TujsFN7570

```

---

### Sample Test Case 5

**Input:**

```text
Code@123
-1

```

**Output:**

```text
INVALID INPUT

```

---

## Approach

Traverse every character of the string after validating the key:

1. Check if $\text{key} < 0$. If so, return `"INVALID INPUT"`.
2. Compute effective shift values using modulo operations to handle large values of `key`:
* Alphabet shift: $\text{alphaShift} = \text{key} \pmod{26}$
* Digit shift: $\text{digitShift} = \text{key} \pmod{10}$


3. Iterate through each character in the string:
* If it is a lowercase letter (`'a'` to `'z'`), shift cyclically: `'a' + (ch - 'a' + alphaShift) % 26`.
* If it is an uppercase letter (`'A'` to `'Z'`), shift cyclically: `'A' + (ch - 'A' + alphaShift) % 26`.
* If it is a digit (`'0'` to `'9'`), shift cyclically: `'0' + (ch - '0' + digitShift) % 10`.
* Otherwise, keep the character unchanged.



---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$ — Single pass through the string of length $n$.
* **Space Complexity:** $\mathcal{O}(1)$ — In-place character modification using constant auxiliary space.

---

## C++ Solution

```cpp
#include <iostream>
#include <string>

using namespace std;

string encrypt(string s, long long key) {
    if (key < 0) {
        return "INVALID INPUT";
    }

    int alphaShift = key % 26;
    int digitShift = key % 10;

    for (char &ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + alphaShift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + alphaShift) % 26;
        } else if (ch >= '0' && ch <= '9') {
            ch = '0' + (ch - '0' + digitShift) % 10;
        }
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (getline(cin, s)) {
        long long key;
        if (cin >> key) {
            cout << encrypt(s, key) << "\n";
        }
    }

    return 0;
}

```

---

## Dry Run

**Input:**

```text
s = "Hello123"
key = 2

```

1. **Check Key:** `key = 2` $\ge 0$ $\rightarrow$ Valid input.
2. **Calculate Modulo Shifts:**
* `alphaShift` = $2 \pmod{26} = 2$
* `digitShift` = $2 \pmod{10} = 2$


3. **Character Transformations:**
* `'H'` $\rightarrow$ `'A' + ('H' - 'A' + 2) % 26` = `'J'`
* `'e'` $\rightarrow$ `'a' + ('e' - 'a' + 2) % 26` = `'g'`
* `'l'` $\rightarrow$ `'a' + ('l' - 'a' + 2) % 26` = `'n'`
* `'l'` $\rightarrow$ `'a' + ('l' - 'a' + 2) % 26` = `'n'`
* `'o'` $\rightarrow$ `'a' + ('o' - 'a' + 2) % 26` = `'q'`
* `'1'` $\rightarrow$ `'0' + ('1' - '0' + 2) % 10` = `'3'`
* `'2'` $\rightarrow$ `'0' + ('2' - '0' + 2) % 10` = `'4'`
* `'3'` $\rightarrow$ `'0' + ('3' - '0' + 2) % 10` = `'5'`



**Final Output:** `Jgnnq345`