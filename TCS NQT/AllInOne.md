
---

## **Part 1: Questions by Date & Slot**

### **7th July — Slot 1 (Morning Shift)**

#### **1. Time Conversion**

* **Problem:** Convert a 12-hour format string (`hh:mm:ssAM` or `hh:mm:ssPM`) to 24-hour military format.
* **Logic:**
* Extract the `AM`/`PM` modifier and the hour.
* If `AM`: change hour `12` to `00`.
* If `PM`: add `12` to the hour if it is not `12`.

```cpp
#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    string modifier = s.substr(8, 2);
    int hour = stoi(s.substr(0, 2)); // C++11 std::stoi
    string rest = s.substr(2, 6);

    if (modifier == "AM") {
        if (hour == 12) hour = 0;
    } else {
        if (hour != 12) hour += 12;
    }

    string hourStr = (hour < 10 ? "0" : "") + to_string(hour); // C++11 std::to_string
    return hourStr + rest;
}

int main() {
    string timeStr = "07:05:45PM";
    cout << "Input: " << timeStr << "\n";
    cout << "24-Hour Format: " << timeConversion(timeStr) << "\n";
    return 0;
}
```

---

#### **2. Top K Frequent Elements**

* **Problem:** Find the $K$ most frequent elements in an integer array.
* **Logic:** Use an unordered hash map to store frequencies, then use a min-heap (priority queue) to maintain the top $K$ elements.

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& entry : freq) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: ";
    for (int num : res) cout << num << " ";
    cout << endl;
    return 0;
}

```

---

### **7th July — Slot 2**

#### **1. Rank Transform of an Array**

* **Problem:** Replace each element in an array with its rank from smallest to largest (1-indexed). Duplicates get the same rank.
* **Logic:** Copy the array, sort it, remove duplicate elements, and map each remaining value to its rank index.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> rankMap;
    int rank = 1;
    for (int val : sortedArr) {
        if (rankMap.find(val) == rankMap.end()) {
            rankMap[val] = rank++;
        }
    }

    vector<int> result;
    for (int val : arr) {
        result.push_back(rankMap[val]);
    }
    return result;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};
    vector<int> ranks = arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";
    for (int r : ranks) cout << r << " ";
    cout << endl;
    return 0;
}

```

---

#### **2. Integer to Roman**

* **Problem:** Convert an integer to its corresponding Roman numeral representation.
* **Logic:** Iterate over pre-mapped integer values and their Roman symbol equivalents in descending order, building the string greedily.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> romanMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    string result = "";
    for (auto& pair : romanMap) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    return result;
}

int main() {
    int num = 58;
    cout << "Integer: " << num << endl;
    cout << "Roman Numeral: " << intToRoman(num) << endl;
    return 0;
}

```

---

### **8th July — Slot 1**

#### **1. Prime Factorization**

* **Problem:** Decompose a given integer $n$ into its prime factors.
* **Logic:** Repeatedly divide $n$ by prime numbers starting from $2$. Continue up to $\sqrt{n}$.

```cpp
#include <iostream>
#include <vector>

using namespace std;

void primeFactorization(int n) {
    cout << "Prime factors of " << n << ": ";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) {
        cout << n;
    }
    cout << endl;
}

int main() {
    int n = 48;
    primeFactorization(n);
    return 0;
}

```

---

#### **2. Quick Sort**

* **Problem:** Implement the Quick Sort algorithm to sort an array in ascending order.
* **Logic:** Partition the array around a pivot element so that all elements smaller go left and larger go right, then recursively repeat.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Quick Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

```

---

### **8th July — Additional Questions**

#### **1. Binary Search (Lower Bound)**

* **Problem:** Find the index of the first element in a sorted array that is $\ge \text{target}$.
* **Logic:** Standard binary search tracking the left side boundary whenever `arr[mid] >= target`.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int lowerBound(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6, 8};
    int target = 4;
    cout << "Lower Bound Index of " << target << ": " << lowerBound(arr, target) << endl;
    return 0;
}

```

---

#### **2. Sieve of Eratosthenes**

* **Problem:** Find all prime numbers within a specified range $[L, R]$.
* **Logic:** Precompute primes up to $R$ using a boolean vector, then filter elements $\ge L$.

```cpp
#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int L, int R) {
    vector<bool> isPrime(R + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= R; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= R; i += p) {
                isPrime[i] = false;
            }
        }
    }

    cout << "Primes between " << L << " and " << R << ": ";
    for (int i = max(2, L); i <= R; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    sieveOfEratosthenes(1, 20);
    return 0;
}

```

---

## **Part 2: Core Algorithm Practice Questions**

## **1. Non-Duplicate Element (XOR Approach)**

* **Problem:** Identify the single unique element in an array where every other element appears twice.
* **Logic:** Use bitwise XOR (`^`). $A \oplus A = 0$ and $0 \oplus A = A$.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int findSingleElement(const vector<int>& nums) {
    int singleVal = 0;
    for (int num : nums) {
        singleVal ^= num;
    }
    return singleVal;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Non-duplicate element: " << findSingleElement(nums) << endl;
    return 0;
}

```

---

## **2. Maximum Sum Subarray of Size K**

* **Problem:** Compute the maximum sum of any contiguous window of size $K$.
* **Logic:** Compute the sum of the first window, then slide it across the array by adding the incoming element and subtracting the outgoing element.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    int maxSum = currentSum;
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max Sum Subarray of size " << k << ": " << maxSubarraySum(arr, k) << endl;
    return 0;
}

```

---

## **3. Anagram Check**

* **Problem:** Verify if two given strings contain identical character counts.
* **Logic:** Count character frequencies using a fixed array of size 26.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> count(26, 0);
    for (int i = 0; i < s.length(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int val : count) {
        if (val != 0) return false;
    }
    return true;
}

int main() {
    string str1 = "listen", str2 = "silent";
    cout << "Are '" << str1 << "' and '" << str2 << "' anagrams? " 
         << (isAnagram(str1, str2) ? "Yes" : "No") << endl;
    return 0;
}

```

---

## **4. Pair with Given Sum in a Sorted Array**

* **Problem:** Search for two numbers in a sorted array that sum to a target value.
* **Logic:** Two-pointer approach from opposing ends (`left` at index 0, `right` at index $N-1$).

```cpp
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findPairWithSum(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {arr[left], arr[right]};
        else if (sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int target = 6;
    pair<int, int> result = findPairWithSum(arr, target);

    if (result.first != -1) {
        cout << "Pair found: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "No pair found." << endl;
    }
    return 0;
}

```

---

## **5. Minimum Platforms Required**

* **Problem:** Determine the minimum platforms required for overlapping train schedules.
* **Logic:** Sort arrival and departure arrays independently, then track active overlaps via two pointers.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPlatformCount(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platformsNeeded = 1, maxPlatforms = 1;
    int i = 1, j = 0;
    int n = arr.size();

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platformsNeeded++;
            i++;
        } else {
            platformsNeeded--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }
    return maxPlatforms;
}

int main() {
    vector<int> arr = {900, 940, 950};
    vector<int> dep = {910, 1200, 1120};

    cout << "Minimum Platforms Needed: " << findPlatformCount(arr, dep) << endl;
    return 0;
}

```

---

## **Part 3: Model Mock Sets**

### **Set 1: String & Subarray Focus**

#### **Question 1 (Easy - 35 Mins): Move Special Characters to End**

* **Problem:** Shift non-alphanumeric characters to the end while keeping letters/numbers in relative order.
* **Logic:** Traverse string once, partition normal and special characters into separate buffers, and merge them.

```cpp
#include <iostream>
#include <string>

using namespace std;

string moveSpecialChars(string s) {
    string alphaNum = "";
    string special = "";

    for (char c : s) {
        if (isalnum(c)) {
            alphaNum += c;
        } else {
            special += c;
        }
    }
    return alphaNum + special;
}

int main() {
    string inputStr = "a#b@c*d";
    cout << "Shifted Result: " << moveSpecialChars(inputStr) << endl;
    return 0;
}

```

---

#### **Question 2 (Medium - 55 Mins): Longest Substring Without Repeating Characters**

* **Problem:** Find the maximum length of a substring without duplicate characters.
* **Logic:** Use a sliding window with an index array tracking the last seen position of each character.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIdx(256, -1);
    int maxLength = 0, left = 0;

    for (int right = 0; right < s.length(); right++) {
        if (lastIdx[s[right]] >= left) {
            left = lastIdx[s[right]] + 1;
        }
        lastIdx[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

int main() {
    string input = "abcabcbb";
    cout << "Longest Unique Substring Length: " << lengthOfLongestSubstring(input) << endl;
    return 0;
}

```

---

### **Set 2: Math & Greedy Focus**

#### **Question 1 (Easy - 35 Mins): Check Strong Number**

* **Problem:** A number is Strong if the sum of factorials of its digits equals the number.
* **Logic:** Precompute factorials 0–9, pull digits with `% 10`, sum factorials, and verify equivalence.

```cpp
#include <iostream>

using namespace std;

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) fact *= i;
    return fact;
}

bool isStrongNumber(int num) {
    int temp = num, sum = 0;
    while (temp > 0) {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
    return sum == num;
}

int main() {
    int num = 145;
    cout << num << " is Strong Number? " << (isStrongNumber(num) ? "Yes" : "No") << endl;
    return 0;
}

```

---

#### **Question 2 (Medium - 55 Mins): Chocolate Distribution Problem**

* **Problem:** Distribute $m$ packets among students such that min/max packet difference is minimized.
* **Logic:** Sort array, then check sliding window differences of size $m$.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinDiff(vector<int>& arr, int m) {
    int n = arr.size();
    if (m == 0 || n == 0 || n < m) return 0;

    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;

    for (int i = 0; i + m - 1 < n; i++) {
        int diff = arr[i + m - 1] - arr[i];
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}

int main() {
    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
    cout << "Minimum Difference: " << findMinDiff(arr, m) << endl;
    return 0;
}

```
