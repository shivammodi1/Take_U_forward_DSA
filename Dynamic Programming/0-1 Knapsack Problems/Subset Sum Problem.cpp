#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
            SUBSET SUM PROBLEM (KNAPSACK STYLE)
===========================================================

Given:
    arr[] = {2, 3, 7, 8, 10}
    sum = 11

Goal:
    Check karo kya koi subset exist karta hai jiska sum = given sum ho

NOTE:
    Ye 0/1 Knapsack ka boolean version hai

Mapping:
    wt[] = arr[]
    val[] = not needed
    W = sum

    Instead of max profit -> TRUE/FALSE return karna hai
*/

/*
===========================================================
        APPROACH 1: RECURSIVE (BRUTE FORCE)
===========================================================

Idea:
    Har element ke liye 2 choices:
        1. Include karo
        2. Exclude karo

Base Case:
    if(sum == 0) return true
    if(n == 0) return false
*/

bool subsetRecursive(int arr[], int sum, int n)
{

    // Base Case
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // Choice Diagram
    if (arr[n - 1] <= sum)
    {

        // Include
        bool include = subsetRecursive(arr, sum - arr[n - 1], n - 1);

        // Exclude
        bool exclude = subsetRecursive(arr, sum, n - 1);

        return include || exclude;
    }

    return subsetRecursive(arr, sum, n - 1);
}

/*
===========================================================
    APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

dp[n][sum] ka matlab:
    "n elements aur sum ke liye subset possible hai ya nahi"
*/

int dp[1001][1001]; // -1 = unvisited, 0 = false, 1 = true

bool subsetMemo(int arr[], int sum, int n)
{

    // Base Case
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // Check dp
    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n - 1] <= sum)
    {

        bool include = subsetMemo(arr, sum - arr[n - 1], n - 1);
        bool exclude = subsetMemo(arr, sum, n - 1);

        return dp[n][sum] = include || exclude;
    }

    return dp[n][sum] = subsetMemo(arr, sum, n - 1);
}

/*
===========================================================
        APPROACH 3: TOP-DOWN (TABULATION)
===========================================================

dp[i][j] ka matlab:
    "first i elements se sum j banana possible hai ya nahi"
*/

bool subsetTopDown(int arr[], int sum, int n)
{

    int dp[n + 1][10001];
    // Base Case Initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // # agar current elemeny=t ka value sum se kam ya barabar hai to include kar sakte hain
            if (arr[i - 1] <= j)
            {

                bool include = dp[i - 1][j - arr[i - 1]]; // include current element and check for remaining sum
                bool exclude = dp[i - 1][j];              // exclude current element and check for same sum

                dp[i][j] = include || exclude; // if either include or exclude is true, then dp[i][j] is true
            }
            else
            {
                dp[i][j] = dp[i - 1][j]; // current element can't be included, so just take the value from the previous row
            }
        }
    }

    return dp[n][sum];
}

/*
===========================================================
                    MAIN FUNCTION
===========================================================
*/

int main()
{

    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;

    int n = sizeof(arr) / sizeof(arr[0]);

    // Recursive
    cout << "Recursive Answer: ";
    cout << subsetRecursive(arr, sum, n) << endl;

    // Memoization
    memset(dp, -1, sizeof(dp));
    cout << "Memoization Answer: ";
    cout << subsetMemo(arr, sum, n) << endl;

    // Top Down
    cout << "Top Down Answer: ";
    cout << subsetTopDown(arr, sum, n) << endl;

    return 0;
}