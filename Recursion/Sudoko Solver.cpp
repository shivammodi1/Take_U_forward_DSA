// Question :
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A Sudoku solution must satisfy all of the following rules:
// 1. Each of the digits 1-9 must occur exactly once in each row.
// 2. Each of the digits 1-9 must occur exactly once in each column.
// 3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

#include <bits/stdc++.h>
using namespace std;

/*
==================== APPROACH ====================

1. Hum Backtracking ka use kar rahe hain Sudoku solve karne ke liye.

2. Pehle ek function `isSafe()` banaya hai jo check karta hai:
   - Kya given number already us row me exist karta hai
   - Kya given number already us column me exist karta hai
   - Kya given number already us 3x3 sub-grid me exist karta hai

3. Agar number in teeno jagah par nahi milta,
   toh wo number wahan place karna SAFE hota hai.

4. `Solve()` function poore board ko scan karta hai:
   - Jaise hi koi empty cell ('.') milti hai,
     hum wahan '1' se '9' tak try karte hain.

5. Agar koi number safe hota hai:
   - Us number ko board me place kar dete hain
   - Recursively next empty cell solve karne ke liye call lagate hain

6. Agar recursion false return karta hai:
   - Matlab galat number place ho gaya
   - Toh backtrack karte hain aur cell ko dobara '.' bana dete hain

7. Agar kisi empty cell ke liye koi bhi number fit nahi hota:
   - Toh function false return karta hai (important for backtracking)

8. Jab poora board fill ho jata hai:
   - Toh function true return karta hai
   - Matlab Sudoku successfully solve ho gaya

============================================================
*/

bool isSafe(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (board[row][i] == c)
            return false;

        // column check
        if (board[i][col] == c)
            return false;

        // 3x3 sub-grid check
        // 3*(row/3) → box ka starting row
        // 3*(col/3) → box ka starting column
        // i/3 → box ke andar row move
        // i%3 → box ke andar column move
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool Solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.') // empty cell mil gayi
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isSafe(board, i, j, c)) // agar number safe hai
                    {
                        board[i][j] = c;

                        if (Solve(board)) // recursively next cell solve karne ke liye call
                            return true;

                        // backtracking only if recursion false return kare
                        board[i][j] = '.';
                    }
                }
                // agar koi number fit nahi hua
                return false;
            }
        }
    }
    // agar poora board fill ho gaya
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    Solve(board);
}

int main()
{
    return 0;
}
