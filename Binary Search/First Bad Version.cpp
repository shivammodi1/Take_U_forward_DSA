#include<bits/stdc++.h>
using namespace std;


// # 🧠 Intuition
// This problem is a variation of **Binary Search**.

// We are given versions from `1` to `n`, and we need to find the **first bad version**.  
// Once a version becomes bad, all versions after it are also bad.

// So the array looks like:


// Our goal is to find the **first occurrence of "bad"**, which is a classic binary search pattern.

// ---

// # 🚀 Approach
// 1. Initialize:
//    - `st = 1`
//    - `end = n`
//    - `ans = n` (to store the first bad version)

// 2. Run a loop while `st < end`:
//    - Compute mid:
//      ```
//      mid = st + (end - st) / 2
//      ```

// 3. Check:
//    - If `isBadVersion(mid)` is `true`:
//      - Store `mid` as a possible answer
//      - Move left → `end = mid`
//    - Else:
//      - Move right → `st = mid + 1`

// 4. Return `ans`

// ---

// # ⏱️ Complexity
// - **Time complexity:** `O(log n)`
// - **Space complexity:** `O(1)`

// ---

// # 💻 Code
// ```cpp
// // The API isBadVersion is defined for you.
// // bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
        int end = n;
        int ans = n;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (isBadVersion(mid)) {
                ans = mid;
                end = mid;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};