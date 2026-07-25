# TCS NQT Coding Mock

**Difficulty:** Medium | **Tags:** `Two Pointers`, `Greedy`, `Arrays`

---

## Problem Statement

You are given an integer array `height` of length $n$.

There are $n$ vertical lines drawn such that the endpoints of the $i^{\text{th}}$ line are $(i, 0)$ and $(i, \text{height}[i])$.

Choose any two lines which, together with the x-axis, form a container.

Return the **maximum amount of water** that the container can store.

The container's capacity is calculated as:

$$\text{Area} = \min(\text{height}[\text{left}], \text{height}[\text{right}]) \times (\text{right} - \text{left})$$

---

## Input Format

* **First line:** An integer $n$, representing the number of vertical lines.
* **Second line:** $n$ space-separated integers representing the array `height`.

---

## Output Format

* Print a single integer representing the maximum amount of water that can be stored.

---

## Constraints

* $2 \le n \le 10^5$
* $0 \le \text{height}[i] \le 10^4$

---

## Sample Test Cases

### Sample Test Case 1

**Input:**

```text
9
1 8 6 2 5 4 8 3 7

```

**Output:**

```text
49

```

**Explanation:**

Choose heights `8` (at index 1) and `7` (at index 8).

* $\text{Width} = 8 - 1 = 7$
* $\text{Area} = \min(8, 7) \times 7 = 49$

---

### Sample Test Case 2

**Input:**

```text
2
1 1

```

**Output:**

```text
1

```

---

### Sample Test Case 3

**Input:**

```text
5
4 3 2 1 4

```

**Output:**

```text
16

```

---

### Sample Test Case 4

**Input:**

```text
3
1 2 1

```

**Output:**

```text
2

```

---

### Sample Test Case 5

**Input:**

```text
7
2 3 10 5 7 8 9

```

**Output:**

```text
36

```

---

## Approach

Use the **Two Pointer** technique:

1. Place the `left` pointer at the beginning (`0`) and the `right` pointer at the end ($n - 1$).
2. Calculate the area formed by the current `left` and `right` pointers.
3. Update the maximum area variable.
4. Move the pointer pointing to the smaller height inward (if `height[left] < height[right]`, increment `left`; otherwise, decrement `right`). *Reason:* The area is limited by the shorter line, so moving the taller line while the width decreases can never increase the area.
5. Repeat until the two pointers meet.

---

## Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n)$ — Single pass using two pointers.
* **Space Complexity:** $\mathcal{O}(1)$ — Auxiliary space used is constant.

---

## C++ Solution

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWater(const vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int width = right - left;
        int current_area = min(height[left], height[right]) * width;
        max_area = max(max_area, current_area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << maxWater(height) << "\n";

    return 0;
}

```

---

## Dry Run

**Input Array:** `[1, 8, 6, 2, 5, 4, 8, 3, 7]`

1. **Initial State:**
* `left = 0` (height `1`), `right = 8` (height `7`)
* $\text{Area} = \min(1, 7) \times (8 - 0) = 8$
* `max_area = 8`
* Since `height[left] < height[right]` ($1 < 7$), increment `left`.


2. **Step 2:**
* `left = 1` (height `8`), `right = 8` (height `7`)
* $\text{Area} = \min(8, 7) \times (8 - 1) = 49$
* `max_area = max(8, 49) = 49`
* Since `height[left] > height[right]` ($8 > 7$), decrement `right`.


3. **Subsequent Steps:**
* Move `right` inward; no subsequent combination exceeds $49$.


**Final Answer:** `49`