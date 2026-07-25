# TCS NQT Coding Mock

**Difficulty:** Medium | **Tags:** `Strings`, `Two Pointers`, `Simulation`

---

## Problem Statement

Given an array of characters `chars`, compress it using the following algorithm:

* Begin with an empty result.
* For each group of consecutive repeating characters:
* Append the character once.
* If the character appears more than once consecutively, append its count.


* The count should be represented as individual digits.
* Modify the array in-place and return the new length of the compressed array.

> **Note:** Must use only $\mathcal{O}(1)$ extra space.

---

## Input Format

* **First line:** An integer $n$, representing the number of characters.
* **Second line:** $n$ space-separated lowercase characters.

---

## Output Format

* **First line:** An integer representing the length of the compressed array.
* **Second line:** Print the compressed characters without spaces up to the new length.

---

## Constraints

* $1 \le n \le 2000$
* `chars[i]` is a lowercase English letter, uppercase English letter, digit, or symbol.
* The compression must be performed in-place.

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
7
a a b b c c c

```

**Output:**

```text
6
a2b2c3

```

**Explanation:**

* `aa` $\rightarrow$ `a2`
* `bb` $\rightarrow$ `b2`
* `ccc` $\rightarrow$ `c3`

Compressed array: `a2b2c3` (Length = **6**)

---

### Sample Test Case 2

**Input:**

```text
13
a b b b b b b b b b b b b

```

**Output:**

```text
4
ab12

```

**Explanation:**

* `a` $\rightarrow$ `a`
* `bbbbbbbbbbbb` $\rightarrow$ `b12`

Compressed array: `ab12` (Length = **4**)

---

### Sample Test Case 3

**Input:**

```text
5
x y z p q

```

**Output:**

```text
5
xyzpq

```

---

### Sample Test Case 4

**Input:**

```text
6
a a a a a a

```

**Output:**

```text
2
a6

```

---

### Sample Test Case 5

**Input:**

```text
1
z

```

**Output:**

```text
1
z

```

---

## Approach

Use the **Two Pointers (Read/Write)** technique to compress in-place:

1. Maintain two pointers: `read` to scan through the array and `write` to record compressed results in-place.
2. While `read < n`:
* Note the character `current = chars[read]`.
* Move `read` forward to count how many consecutive occurrences of `current` exist (`count`).
* Write `current` to `chars[write++]`.
* If `count > 1`, convert `count` into its string representation and write each character digit sequentially into `chars[write++]`.


3. Return `write` as the new length of the array.

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$ — Each character is processed at most twice (once by `read` and once during digit expansion).
* **Space Complexity:** $\mathcal{O}(1)$ — In-place modifications using constant extra space.

---

## C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int write = 0;
    int read = 0;
    int n = chars.size();

    while (read < n) {
        char current = chars[read];
        int count = 0;

        // Count consecutive occurrences
        while (read < n && chars[read] == current) {
            read++;
            count++;
        }

        // Write the character
        chars[write++] = current;

        // Write digits of count if count > 1
        if (count > 1) {
            string freq = to_string(count);
            for (char digit : freq) {
                chars[write++] = digit;
            }
        }
    }

    return write;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<char> chars(n);
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    int len = compress(chars);

    cout << len << "\n";
    for (int i = 0; i < len; i++) {
        cout << chars[i];
    }
    cout << "\n";

    return 0;
}

```

---

## Dry Run

**Input:** `n = 7`, `chars = ['a', 'a', 'b', 'b', 'c', 'c', 'c']`

1. **Group 1 (`'a'`):**
* `current = 'a'`, `count = 2`, `read` becomes `2`.
* `chars[0] = 'a'` (`write = 1`).
* Since `count > 1`, append `'2'`: `chars[1] = '2'` (`write = 2`).


2. **Group 2 (`'b'`):**
* `current = 'b'`, `count = 2`, `read` becomes `4`.
* `chars[2] = 'b'` (`write = 3`).
* Append `'2'`: `chars[3] = '2'` (`write = 4`).


3. **Group 3 (`'c'`):**
* `current = 'c'`, `count = 3`, `read` becomes `7`.
* `chars[4] = 'c'` (`write = 5`).
* Append `'3'`: `chars[5] = '3'` (`write = 6`).



**Output:**

* `len = 6`
* `chars[0..5]` = `a2b2c3`