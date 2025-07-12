# 🔥 Efficient DFS with Symmetry Optimization

---

## 💡 Intuition

The problem asks for the **earliest and latest round** in which two specific players can meet in a knockout tournament.

In a knockout format:

- Players are paired from the ends inward: 1 vs n, 2 vs n-1, and so on.
- Winners move to the next round, and pairings are formed again in the same manner.

My first thought was to use **DFS** to simulate all valid player progressions and track the rounds in which the two specified players meet. Symmetry in matchups can be used to reduce redundant states.

---

## 🧭 Approach — *DFS with Symmetry Optimization*

1. **Recursive Simulation (DFS):**  
   Use a recursive function `dfs(n, p1, p2)` to simulate rounds, calculate the next matchups, and track when the two players meet.

2. **Base Case:**  
   If `p1 + p2 == n + 1`, they are facing each other this round. Return `{1, 1}`.

3. **Symmetry Reduction:**  
   Mirror positions of the players if they lie closer to the end, which helps avoid recalculating symmetric states.

4. **Recursive Exploration:**
   - **Case A**: Players both in the first half. Explore all combinations of who they could’ve been in the previous round.
   - **Case B**: Players are on opposite ends. Use mirrored logic and offset calculations to trace valid previous-round positions.

5. **Track Rounds:**  
   Collect the earliest and latest rounds when the two players can meet across all explored paths.

---

## ⏱️ Complexity

- **Time complexity:**  
  $$O(n^4)$$  
  Due to recursive branching with nested loops for combinations of positions. Optimization via symmetry reduces some calls.

- **Space complexity:**  
  $$O(n)$$  
  For the recursion stack. Can be improved further with memoization (not included here).

---

## </> Code

```cpp
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    // DFS function to calculate the earliest and latest round where two players meet
    pair<int, int> dfs(int totalPlayers, int player1, int player2) {
        // Step 1: Base case — if players meet in current round
        if (player1 + player2 == totalPlayers + 1) {
            return {1, 1}; // They meet this round
        }

        // Step 2: Normalize the positions for consistent processing
        if (player1 > player2) {
            swap(player1, player2);
        }

        // Step 3: If only 4 or fewer players, they can meet by round 2
        if (totalPlayers <= 4) {
            return {2, 2};
        }

        int nextRoundPlayers = (totalPlayers + 1) / 2;
        int earliestRound = INT_MAX;
        int latestRound = INT_MIN;

        // Step 4: Use symmetry to reduce redundant states
        if (player1 - 1 > totalPlayers - player2) {
            int mirroredPlayer1 = totalPlayers + 1 - player2;
            int mirroredPlayer2 = totalPlayers + 1 - player1;
            player1 = mirroredPlayer1;
            player2 = mirroredPlayer2;
        }

        // Step 5: Simulate all matchups depending on the players' positions
        if (player2 * 2 <= totalPlayers + 1) {
            // Case A: Both players in the first half
            int leftGap = player1 - 1;                 // Players before player1
            int middleGap = player2 - player1 - 1;     // Players between player1 and player2

            for (int i = 0; i <= leftGap; ++i) {
                for (int j = 0; j <= middleGap; ++j) {
                    auto [earliestSub, latestSub] = dfs(nextRoundPlayers, i + 1, i + j + 2);
                    earliestRound = min(earliestRound, earliestSub + 1);
                    latestRound = max(latestRound, latestSub + 1);
                }
            }
        } else {
            // Case B: Players are far apart (possibly across mirrored positions)
            int mirroredPlayer2 = totalPlayers + 1 - player2;
            int leftGap = player1 - 1;
            int middleGap = mirroredPlayer2 - player1 - 1;
            int rightGap = player2 - mirroredPlayer2 - 1;

            for (int i = 0; i <= leftGap; ++i) {
                for (int j = 0; j <= middleGap; ++j) {
                    int offset = i + j + 1 + (rightGap + 1) / 2 + 1;
                    auto [earliestSub, latestSub] = dfs(nextRoundPlayers, i + 1, offset);
                    earliestRound = min(earliestRound, earliestSub + 1);
                    latestRound = max(latestRound, latestSub + 1);
                }
            }
        }

        // Step 6: Return results for this branch
        return {earliestRound, latestRound};
    }

    // Main function to be called
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};
