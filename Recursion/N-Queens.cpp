#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

// Ye function check karta hai ki
// (row, col) par queen rakhna safe hai ya nahi
bool canPlace(int row, int col, vector<string> &board, int n)
{
    // Kyunki hum queens ko LEFT → RIGHT place kar rahe hain,
    // isliye hume sirf LEFT side check karna hota hai

    // Queen attack kar sakti hai:
    // 1. Same row me (left side)
    // 2. Upper left diagonal me
    // 3. Lower left diagonal me

    int c = col;
    int r = row;

    // 1️⃣ Same row – left side check
    while (c >= 0)
    {
        // Agar same row ke left side me queen mil jaye
        // toh placement unsafe hai
        if (board[row][c] == 'Q')
        {
            return false;
        }
        c--;
    }

    // 2️⃣ Upper diagonal – left side check
    col = c = col;
    row = r;

    while (row >= 0 && col >= 0)
    {
        // Agar upper diagonal me queen mil jaye
        // toh placement unsafe
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    // 3️⃣ Lower diagonal – left side check
    row = r;
    col = c = col;

    while (row < n && col >= 0)
    {
        // Agar lower diagonal me queen mil jaye
        // toh placement unsafe
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }

    // Agar kahin bhi queen attack nahi kar rahi
    // toh placement safe hai
    return true;
}

// Recursive backtracking function
// Jo column by column queens place karta hai
void Solve(int col, int n, vector<string> &board, vector<vector<string>> &ans)
{
    // 🟢 Base Case:
    // Agar saare columns me queen place ho chuki hai
    if (col == n)
    {
        // Current board ek valid solution hai
        ans.push_back(board);
        return;
    }

    // Har column ke liye hum saari rows try karte hain
    for (int row = 0; row < n; row++)
    {
        // Check karo queen rakhna safe hai ya nahi
        if (canPlace(row, col, board, n))
        {
            // Queen place karo
            board[row][col] = 'Q';

            // Next column ke liye recursive call
            Solve(col + 1, n, board, ans);

            // 🔙 Backtracking step:
            // Queen hata do taaki next option try ho sake
            board[row][col] = '.';
        }
    }
}

// Main function jo N-Queens solve karta hai
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;   // Saare valid solutions store karega
    vector<string> board(n);      // Chessboard
    string s(n, '.');             // Empty row (....)

    // Board ko empty initialize karo
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    // Start placing queens from column 0
    Solve(0, n, board, ans);

    // Final result return karo
    return ans;
}
};


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
