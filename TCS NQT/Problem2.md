# TCS NQT Coding Mock

**Difficulty:** Easy | **Tags:** `Greedy`, `Arrays`

---

## Problem Statement

You have a long flowerbed where some plots are planted (`1`) and some are empty (`0`).

Flowers cannot be planted in adjacent plots.

Given an integer array `flowerbed` and an integer $n$, determine whether it is possible to plant $n$ new flowers in the flowerbed without violating the no-adjacent-flowers rule.

Return **true** if possible; otherwise, return **false**.

---

## Input Format

* **First line:** An integer $m$, representing the size of the flowerbed.
* **Second line:** $m$ space-separated integers (`0` or `1`) representing the flowerbed.
* **Third line:** An integer $n$, representing the number of flowers to plant.

---

## Output Format

* Print `true` if it is possible to plant $n$ flowers, or `false` otherwise.

---

## Constraints

* $1 \le m \le 2 \times 10^4$
* `flowerbed[i]` is either `0` or `1`
* $0 \le n \le m$

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
5
1 0 0 0 1
1

```

**Output:**

```text
true

```

**Explanation:**

The flower can be planted at index 2.

Final flowerbed: `1 0 1 0 1`

Hence, the answer is **true**.

---

### Sample Test Case 2

**Input:**

```text
5
1 0 0 0 1
2

```

**Output:**

```text
false

```

**Explanation:**

Only one flower can be planted without violating the adjacent rule.

---

### Sample Test Case 3

**Input:**

```text
6
0 0 0 0 0 0
3

```

**Output:**

```text
true

```

---

### Sample Test Case 4

**Input:**

```text
1
0
1

```

**Output:**

```text
true

```

---

### Sample Test Case 5

**Input:**

```text
3
1 0 1
1

```

**Output:**

```text
false

```

---

## Approach

Traverse the flowerbed greedily from left to right:

1. For every empty plot (`0` at index $i$):
* Check if the left plot is empty or out of bounds ($i == 0$ or $\text{flowerbed}[i - 1] == 0$).
* Check if the right plot is empty or out of bounds ($i == m - 1$ or $\text{flowerbed}[i + 1] == 0$).


2. If both conditions are satisfied, plant a flower at index $i$ ($\text{flowerbed}[i] = 1$) and decrement $n$ (or increment the planted counter).
3. **Early Exit:** If $n$ becomes $\le 0$ at any point, return `true` immediately.
4. If the loop finishes and $n > 0$, return `false`.

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(m)$ — Single pass through the array.
* **Space Complexity:** $\mathcal{O}(1)$ — Auxiliary space used is constant.

---

## C++ Solution

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    
    int m = flowerbed.size();
    int planted = 0;

    for (int i = 0; i < m; i++) {
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
            bool rightEmpty = (i == m - 1 || flowerbed[i + 1] == 0);

            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                planted++;

                if (planted >= n) {
                    return true;
                }
            }
        }
    }

    return planted >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    vector<int> flowerbed(m);
    for (int i = 0; i < m; i++) {
        cin >> flowerbed[i];
    }

    int n;
    cin >> n;

    cout << (canPlaceFlowers(flowerbed, n) ? "true" : "false") << "\n";

    return 0;
}

```

---

## Dry Run

**Input:**

```text
m = 5
flowerbed = [1, 0, 0, 0, 1]
n = 1

```

1. **`i = 0`:** `flowerbed[0] = 1` $\rightarrow$ Skip.
2. **`i = 1`:** `flowerbed[1] = 0`
* `leftEmpty` ($i=0$ check): `flowerbed[0] == 1` $\rightarrow$ `false`.
* Cannot plant here.


3. **`i = 2`:** `flowerbed[2] = 0`
* `leftEmpty` ($i=1$ check): `flowerbed[1] == 0` $\rightarrow$ `true`.
* `rightEmpty` ($i=3$ check): `flowerbed[3] == 0` $\rightarrow$ `true`.
* Plant flower: set `flowerbed[2] = 1`, `planted = 1`.
* Check: `planted >= n` ($1 \ge 1$) $\rightarrow$ Return `true`.



**Final Answer:** `true`