#include <bits/stdc++.h>
using namespace std;

// Function to solve N-Queens problem using backtracking
vector<vector<string>> solveNQueens(int n)
{
}

int main()
{
    return 0;
}


// Approach:
// 1. Isko solve karne ke liye hum backtracking ka use karenge.
// 2. Hum ek helper function banayenge jo board par queens place karega aur valid configurations ko store karega.
// 3. Har step par hum check karenge ki kya queen ko current position par rakhna safe hai ya nahi.
// 4. Agar safe hai, to queen ko place karenge aur next row ke liye recursive call karenge.
// 5. Agar queen ko place karna safe nahi hai, to backtrack karenge aur next column try karenge.
// 6. Jab hum last row tak pahunch jaate hain, to current configuration ko result mein add karenge.
// 7. Finally, result return karenge.
// 8. Time Complexity: O(N!), Space Complexity: O(N^2) for the board storage.
// Row 0
// │
// ├── Q . . .   (col 0)
// │   │
// │   ├── . . Q .   (col 2)
// │   │   │
// │   │   └── . Q . .   ❌ (no safe place in next row → backtrack)
// │   │
// │   └── . . . Q   (col 3)
// │       │
// │       └── . Q . .   (col 1)
// │           │
// │           └── . . Q .   ❌ (no safe place → backtrack)
// │
// ├── . Q . .   (col 1)
// │   │
// │   └── . . . Q   (col 3)
// │       │
// │       └── Q . . .   (col 0)
// │           │
// │           └── . . Q .   ✅ SOLUTION
// │
// ├── . . Q .   (col 2)
// │   │
// │   └── Q . . .   (col 0)
// │       │
// │       └── . . . Q   (col 3)
// │           │
// │           └── . Q . .   ✅ SOLUTION
// │
// └── . . . Q   (col 3)
//     │
//     ├── Q . . .   (col 0)
//     │   │
//     │   └── . . Q .   ❌
//     │
//     └── . Q . .   (col 1)
//         │
//         └── . . . Q   ❌
