#include <bits/stdc++.h>
using namespace std;

// this function to set in row 0 to INT_MAX
void markRow(vector<vector<int>> &mat, int i)
{
    int m = mat[0].size();
    for (int j = 0; j < m; j++)
    {
        if (mat[i][j] != 0)
        {
            mat[i][j] = INT_MAX;
        }
    }
}

// this function to set in row 0 to INT_MAX
void markCol(vector<vector<int>> &mat, int i)
{
    int m = mat.size();
    for (int j = 0; j < m; j++)
    {
        if (mat[j][i] != 0)
        {
            mat[j][i] = INT_MAX;
        }
    }
}

void setMatrixZeroes(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                // calling function
                markRow(mat, i);
                markCol(mat, j);
            }
        }
    }

    // now -1 to set 0
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // now converting INT_MAX -> 0
            if (mat[i][j] == INT_MAX)
            {
                mat[i][j] = 0;
            }
        }
    }
}

int main()
{
}
