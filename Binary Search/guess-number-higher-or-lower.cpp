#include <bits/stdc++.h>
using namespace std;    

// # 🧠 Intuition
// The problem follows the concept of **Binary Search**.

// We are given a range from `1` to `n`, and we need to find a hidden number using the `guess()` API.

// The API tells us:
// - `0` → correct number
// - `-1` → guessed number is too high
// - `1` → guessed number is too low  

// So instead of checking every number, we reduce the search space by half each time.

// ---

// # 🚀 Approach
// 1. Initialize:
//    - `st = 1`
//    - `end = n`

// 2. Run a loop while `st <= end`:
//    - Find middle:
//      ```
//      mid = st + (end - st) / 2
//      ```

// 3. Call `guess(mid)`:
//    - If `guess(mid) == 0` → return `mid`
//    - If `guess(mid) == -1` → search left → `end = mid - 1`
//    - If `guess(mid) == 1` → search right → `st = mid + 1`

// 4. Return `-1` (edge case)

// ---

// # ⏱️ Complexity
// - **Time Complexity:** `O(log n)`
// - **Space Complexity:** `O(1)`

// ---

// # 💻 Code
// ```cpp
// /** 
//  * Forward declaration of guess API.
//  * @param  num   your guess
//  * @return       -1 if num is higher than the picked number
//  *                1 if num is lower than the picked number
//  *                0 if correct
//  * int guess(int num);
//  */

class Solution {
public:
    int guessNumber(int n) {
        int st = 1;
        int end = n;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (guess(mid) == 0) {
                return mid;
            } 
            else if (guess(mid) == -1) {
                end = mid - 1;
            } 
            else {
                st = mid + 1;
            }
        }
        return -1;
    }
};