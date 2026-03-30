#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
            PAINT WALLS PROBLEM (KNAPSACK STYLE)
===========================================================

Given:
    cost[] -> paid painter ka cost
    time[] -> kitne time tak wo busy rahega

Concept:
    2 painters hain:
    1. Paid painter:
        - cost[i] pay karte hain
        - 1 wall paint karta hai

    2. Free painter:
        - jab tak paid painter busy hai
        - utne time me 1 wall per unit paint karta hai

👉 Total walls covered:
    1 (paid) + time[i] (free)
    = time[i] + 1

Goal:
    Minimum cost me saari walls paint karni hain

NOTE:
    Ye exactly 0/1 Knapsack jaisa hai
*/




/*
===========================================================
        APPROACH 1: RECURSIVE (BRUTE FORCE)
===========================================================

Idea:
    Har painter ke liye 2 choices:
        1. Include (use karo)
        2. Exclude (skip karo)

Base Case:
    if(walls <= 0) return 0
    if(n == 0) return INF

Time Complexity:
    O(2^n)
*/

int paintWallsRecursive(vector<int>& cost, vector<int>& time, int walls, int n) {

    // Base Case
    if (walls <= 0) {
        return 0;
    }

    if (n == 0) {
        return 1e9; // impossible case
    }

    // Choice Diagram

    // Include current painter
    // walls reduce = time[n-1] + 1
    int include = cost[n - 1] + 
        paintWallsRecursive(cost, time, walls - time[n - 1] - 1, n - 1);

    // Exclude current painter
    int exclude = paintWallsRecursive(cost, time, walls, n - 1);

    return min(include, exclude);
}





/*
===========================================================
    APPROACH 2: MEMOIZATION (TOP-DOWN DP)
===========================================================

dp[n][walls] ka matlab:
    n painters aur walls walls ke liye minimum cost

Time Complexity:
    O(n * n)
*/

int dp[501][501];

int paintWallsMemo(vector<int>& cost, vector<int>& time, int walls, int n) {

    // Base Case
    if (walls <= 0) {
        return 0;
    }

    if (n == 0) {
        return 1e9;
    }

    // Check dp
    if (dp[n][walls] != -1) {
        return dp[n][walls];
    }

    // Include
    int include = cost[n - 1] + 
        paintWallsMemo(cost, time, walls - time[n - 1] - 1, n - 1);

    // Exclude
    int exclude = paintWallsMemo(cost, time, walls, n - 1);

    return dp[n][walls] = min(include, exclude);
}





/*
===========================================================
                    MAIN FUNCTION
===========================================================
*/

int main() {

    vector<int> cost = {1, 2, 3, 4, 5};
    vector<int> time = {1, 2, 3, 4, 5};

    int n = cost.size();
    int walls = n; // total walls

    // Recursive Answer
    cout << "Recursive Answer: ";
    cout << paintWallsRecursive(cost, time, walls, n) << endl;

    // Initialize dp array
    memset(dp, -1, sizeof(dp));

    // Memoization Answer
    cout << "Memoization Answer: ";
    cout << paintWallsMemo(cost, time, walls, n) << endl;

    return 0;
}