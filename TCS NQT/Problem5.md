# TCS NQT Coding Mock

**Difficulty:** Medium | **Tags:** `Arrays`, `Prefix Product`, `Suffix Product`

---

## Problem Statement

Given an integer array `nums`, return an array `answer` such that:

$$\text{answer}[i] = \text{product of all elements of } \text{nums} \text{ except } \text{nums}[i]$$

You must write an algorithm that runs in $\mathcal{O}(n)$ time and **without using the division operator**.

---

## Input Format

* **First line:** An integer $n$, representing the size of the array.
* **Second line:** $n$ space-separated integers representing the array `nums`.

---

## Output Format

* Print the resulting array where each element is the product of all elements except itself.
* Print the elements separated by a single space.

---

## Constraints

* $2 \le n \le 10^5$
* $-30 \le \text{nums}[i] \le 30$
* The product of any prefix or suffix fits in a 32-bit signed integer.

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
4
1 2 3 4

```

**Output:**

```text
24 12 8 6

```

**Explanation:**

* $\text{answer}[0] = 2 \times 3 \times 4 = 24$
* $\text{answer}[1] = 1 \times 3 \times 4 = 12$
* $\text{answer}[2] = 1 \times 2 \times 4 = 8$
* $\text{answer}[3] = 1 \times 2 \times 3 = 6$

---

### Sample Test Case 2

**Input:**

```text
5
-1 1 0 -3 3

```

**Output:**

```text
0 0 9 0 0

```

---

### Sample Test Case 3

**Input:**

```text
2
5 10

```

**Output:**

```text
10 5

```

---

### Sample Test Case 4

**Input:**

```text
4
2 2 2 2

```

**Output:**

```text
8 8 8 8

```

---

### Sample Test Case 5

**Input:**

```text
3
3 4 5

```

**Output:**

```text
20 15 12

```

---

## Approach

Since the division operator is strictly forbidden, we compute prefix and suffix products:

1. **Prefix Pass:** Traverse from left to right. Store the running product of all elements to the left of each index $i$ in $\text{answer}[i]$.
2. **Suffix Pass:** Traverse from right to left. Maintain a running `suffix` product of all elements to the right of index $i$, and multiply it with the existing prefix product stored in $\text{answer}[i]$.

This achieves linear time complexity while maintaining $\mathcal{O}(1)$ auxiliary space (excluding the output array).

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$ — Two linear passes over the array.
* **Space Complexity:** $\mathcal{O}(1)$ — In-place computation using the output array (excluding space for output).

---

## C++ Solution

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    int n = nums.size();
    vector<int> answer(n, 1);

    // Prefix products
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
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

    vector<int> ans = productExceptSelf(nums);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}

```

---

## Dry Run

**Input:** `nums = [1, 2, 3, 4]`

1. **Prefix Pass:**
* `i = 0`: `answer[0] = 1`, `prefix = 1 * 1 = 1`
* `i = 1`: `answer[1] = 1`, `prefix = 1 * 2 = 2`
* `i = 2`: `answer[2] = 2`, `prefix = 2 * 3 = 6`
* `i = 3`: `answer[3] = 6`, `prefix = 6 * 4 = 24`
* `answer` array after prefix pass: `[1, 1, 2, 6]`


2. **Suffix Pass:**
* `i = 3`: `answer[3] = 6 * 1 = 6`, `suffix = 1 * 4 = 4`
* `i = 2`: `answer[2] = 2 * 4 = 8`, `suffix = 4 * 3 = 12`
* `i = 1`: `answer[1] = 1 * 12 = 12`, `suffix = 12 * 2 = 24`
* `i = 0`: `answer[0] = 1 * 24 = 24`, `suffix = 24 * 1 = 24`



**Final Output:** `24 12 8 6`