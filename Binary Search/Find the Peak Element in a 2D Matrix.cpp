// Find the Peak Element in a 2D Matrix
// A peak element in a 2D matrix is an element that is greater than or equal to its four neighbors (up, down, left, right).

#include <bits/stdc++.h>
using namespace std;


// method 1 : Brute Force
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int curr = mat[i][j];
            bool isPeak = true;

            // check top
            if (i > 0 && mat[i - 1][j] > curr)
                isPeak = false;

            // check bottom
            if (i + 1 < n && mat[i + 1][j] > curr)
                isPeak = false;

            // check left
            if (j > 0 && mat[i][j - 1] > curr)
                isPeak = false;

            // check right
            if (j + 1 < m && mat[i][j + 1] > curr)
                isPeak = false;

            if (isPeak)
                return {i, j};
        }
    }

    return {-1, -1};
}

// method 2 : Binary Search
vector<int> findPeakGridBinarySearch(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int left = 0, right = m - 1;

    while (left <= right)
    {
        int midCol = left + (right - left) / 2;

        // Find the maximum element in the midCol
        int maxRow = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mat[i][midCol] > mat[maxRow][midCol])
                maxRow = i;
        }

        bool isLeftBigger = (midCol - 1 >= 0) && (mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
        bool isRightBigger = (midCol + 1 < m) && (mat[maxRow][midCol + 1] > mat[maxRow][midCol]);

        if (!isLeftBigger && !isRightBigger)
        {
            return {maxRow, midCol};
        }
        else if (isRightBigger)
        {
            left = midCol + 1;
        }
        else
        {
            right = midCol - 1;
        }
    }

    return {-1, -1};
}


int main()
{
}