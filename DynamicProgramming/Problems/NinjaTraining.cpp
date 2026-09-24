/* 
A matrix points describes merit points for n training days and three available activities. 
Each row represents one day, while columns 0, 1, and 2 represent running, fighting practice, and learning new moves.

Select exactly one activity per day. Consecutive days cannot use the same activity. Return the maximum total merit points across the complete schedule.

Example 1
Input: points = [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Choose points[0][2] = 5 on day 0, points[1][0] = 3 on day 1, and points[2][1] = 3 on day 2. 
The chosen activity indices are 2, 0, and 1, so no two consecutive days use the same activity. The maximum total is 5 + 3 + 3 = 11.

Example 2
Input: points = [[8, 3, 5]]
Output: 8
Explanation: A single training day has no neighboring-day restriction. Activity index 0 gives the largest available score, 8.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive solution
class Solution {
private:
    // Finds the best score for one recursive state.
    int solve(int day, int last, vector<vector<int>>& points) {
        // Stop at day zero because no earlier day remains.
        if (day == 0) {
            int best = 0;

            // Check every activity to find the best valid start.
            for (int activity = 0; activity < 3; activity++) {
                // Skip the blocked activity to prevent repetition.
                if (activity != last) {
                    // Keep the strongest allowed first-day score.
                    best = max(best, points[0][activity]);
                }
            }

            // Return the best valid score for the first day.
            return best;
        }

        int best = 0;

        // Explore every activity because each choice can win.
        for (int activity = 0; activity < 3; activity++) {
            // Skip the blocked activity to preserve validity.
            if (activity != last) {
                // Add the chosen score to the earlier schedule.
                int candidate = points[day][activity]
                              + solve(day - 1, activity, points);

                // Keep the largest complete valid total.
                best = max(best, candidate);
            }
        }

        // Return the strongest schedule for the state.
        return best;
    }

public:
    // Returns the maximum merit points for all days.
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        // Sentinel three leaves the final day unrestricted.
        return solve(n - 1, 3, points);
    }
};


// Memoized solution
class Solution {
private:
    // Finds and stores the best score for one state.
    int solve(
        int day,
        int last,
        vector<vector<int>>& points,
        vector<vector<int>>& dp
    ) {
        // Reuse a saved answer to avoid repeated work.
        if (dp[day][last] != -1) {
            return dp[day][last];
        }

        // Stop at day zero because no earlier day remains.
        if (day == 0) {
            int best = 0;

            // Check every activity to find the best valid start.
            for (int activity = 0; activity < 3; activity++) {
                // Skip the blocked activity to prevent repetition.
                if (activity != last) {
                    // Keep the strongest allowed first-day score.
                    best = max(best, points[0][activity]);
                }
            }

            // Store the base answer for later cache hits.
            dp[day][last] = best;
            return dp[day][last];
        }

        int best = 0;

        // Explore every activity because each choice can win.
        for (int activity = 0; activity < 3; activity++) {
            // Skip the blocked activity to preserve validity.
            if (activity != last) {
                // Add the chosen score to the cached subproblem.
                int candidate = points[day][activity]
                              + solve(day - 1, activity, points, dp);

                // Keep the largest complete valid total.
                best = max(best, candidate);
            }
        }

        // Store the completed state before returning.
        dp[day][last] = best;
        return dp[day][last];
    }

public:
    // Returns the maximum merit points for all days.
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        // Minus one marks every state as uncalculated.
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Sentinel three leaves the final day unrestricted.
        return solve(n - 1, 3, points, dp);
    }
};


// Tabulation solution
class Solution {
public:
    // Returns the maximum merit points with tabulation.
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        // Four columns preserve every forbidden choice.
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Build the base row from valid first-day choices.
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0],
                       max(points[0][1], points[0][2]));

        // Move forward because every earlier row is ready.
        for (int day = 1; day < n; day++) {
            // Calculate all four forbidden-activity states.
            for (int last = 0; last < 4; last++) {
                // Try every activity because any choice can win.
                for (int activity = 0; activity < 3; activity++) {
                    // Skip repetition to keep the schedule valid.
                    if (activity != last) {
                        // Add the score to the matching prior state.
                        int candidate = points[day][activity]
                                      + dp[day - 1][activity];

                        // Keep the largest total for the state.
                        dp[day][last] = max(
                            dp[day][last], candidate
                        );
                    }
                }
            }
        }

        // Sentinel three represents no final restriction.
        return dp[n - 1][3];
    }
};


// Tabulation solution with space optimization
class Solution {
public:
    // Returns the maximum score with two small rows.
    int ninjaTraining(vector<vector<int>>& points) {
        int n = points.size();

        // Previous stores every first-day state.
        vector<int> previous(4, 0);
        previous[0] = max(points[0][1], points[0][2]);
        previous[1] = max(points[0][0], points[0][2]);
        previous[2] = max(points[0][0], points[0][1]);
        previous[3] = max(points[0][0],
                          max(points[0][1], points[0][2]));

        // Move forward because only the prior row is needed.
        for (int day = 1; day < n; day++) {
            vector<int> current(4, 0);

            // Calculate every current state before the shift.
            for (int last = 0; last < 4; last++) {
                // Try every activity because any choice can win.
                for (int activity = 0; activity < 3; activity++) {
                    // Skip repetition to keep the schedule valid.
                    if (activity != last) {
                        // Add the score to the matching prior state.
                        int candidate = points[day][activity]
                                      + previous[activity];

                        // Keep the largest total for the state.
                        current[last] = max(
                            current[last], candidate
                        );
                    }
                }
            }

            // Shift only after every current state is ready.
            previous = current;
        }

        // Sentinel three represents no final restriction.
        return previous[3];
    }
};


// Driver code
int main() {
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    Solution obj;
    cout << obj.ninjaTraining(points) << '\n';
    return 0;
}


/*
Time and space complexity analysis:
1. Recursive solution:
    - Time complexity: O(3^n), where n is the number of days. Each day has 3 choices, leading to an exponential number of combinations.
    - Space complexity: O(n) for the recursion stack.

2. Memoized solution:
    - Time complexity: O(n * 4), where n is the number of days and 4 represents the last activity (0, 1, 2, or 3). Each state is computed only once.
    - Space complexity: O(n * 4) for the dp array and O(n) for the recursion stack.

3. Tabulation solution:
    - Time complexity: O(n * 4 * 3), where n is the number
    of days, 4 represents the last activity, and 3 represents the current activity. Each state is computed iteratively.
    - Space complexity: O(n * 4) for the dp array.

4. Tabulation solution with space optimization:
    - Time complexity: O(n * 4 * 3), similar to the tabulation solution.
    - Space complexity: O(4) for the previous and current arrays, as we only need to store the last row of the dp table at any time.
*/