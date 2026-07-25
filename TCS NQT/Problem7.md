# TCS NQT Coding Mock

**Difficulty:** Medium | **Tags:** `Arrays`, `Greedy`

---

## Problem Statement

Given an integer array `nums`, return **true** if there exists a triplet of indices $(i, j, k)$ such that:

* $i < j < k$
* $\text{nums}[i] < \text{nums}[j] < \text{nums}[k]$

Otherwise, return **false**.

Your task is to determine whether the array contains an **increasing subsequence of length 3**.

---

## Input Format

* **First line:** An integer $n$, representing the size of the array.
* **Second line:** $n$ space-separated integers representing the array `nums`.

---

## Output Format

* Print `true` if an increasing triplet exists; otherwise, print `false`.

---

## Constraints

* $1 \le n \le 5 \times 10^5$
* $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
5
1 2 3 4 5

```

**Output:**

```text
true

```

**Explanation:**

One increasing triplet is $1 < 2 < 3$.

---

### Sample Test Case 2

**Input:**

```text
5
5 4 3 2 1

```

**Output:**

```text
false

```

**Explanation:**

The array is strictly decreasing, so no increasing triplet exists.

---

### Sample Test Case 3

**Input:**

```text
6
2 1 5 0 4 6

```

**Output:**

```text
true

```

**Explanation:**

One valid triplet is $0 < 4 < 6$.

---

### Sample Test Case 4

**Input:**

```text
5
2 4 1 5 6

```

**Output:**

```text
true

```

---

### Sample Test Case 5

**Input:**

```text
4
2 1 2 1

```

**Output:**

```text
false

```

---

## Approach

Maintain two variables:

* `first` $\rightarrow$ Smallest element encountered so far.
* `second` $\rightarrow$ Second smallest element encountered so far (strictly greater than `first`).

Traverse the array linearly:

1. If the current element $\le \text{first}$, update `first = num`.
2. Else if the current element $\le \text{second}$, update `second = num`.
3. Else, we have found an element strictly greater than both `first` and `second`, satisfying $\text{first} < \text{second} < \text{num}$. Return `true`.

If the loop finishes without finding such an element, return `false`.

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$ — Single pass through the array.
* **Space Complexity:** $\mathcal{O}(1)$ — Uses constant extra memory.

---

## C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool increasingTriplet(const vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << (increasingTriplet(nums) ? "true" : "false") << "\n";

    return 0;
}

```

---

## Dry Run

**Input:** `nums = [2, 1, 5, 0, 4, 6]`

1. **Initial State:** `first = ∞`, `second = ∞`
2. **`num = 2`:** `2 <= ∞` $\rightarrow$ `first = 2`
3. **`num = 1`:** `1 <= 2` $\rightarrow$ `first = 1`
4. **`num = 5`:** `5 > 1` and `5 <= ∞` $\rightarrow$ `second = 5`
5. **`num = 0`:** `0 <= 1` $\rightarrow$ `first = 0`
6. **`num = 4`:** `4 > 0` and `4 <= 5` $\rightarrow$ `second = 4`
7. **`num = 6`:** `6 > 0` and `6 > 4` $\rightarrow$ Triplet found (`0 < 4 < 6`).

**Output:** `true`