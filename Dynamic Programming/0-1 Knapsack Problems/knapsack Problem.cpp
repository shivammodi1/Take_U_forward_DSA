#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
            0-1 KNAPSACK PROBLEM
===========================================================

Given:
    wt[]  = {1, 3, 4, 5}   -> weights
    val[] = {1, 4, 5, 7}   -> values
    W = 7                  -> capacity

Goal:
    Maximum profit find karna hai without exceeding W

NOTE:
    0-1 Knapsack me har item ko sirf ek baar use kar sakte hain
*/




/*
===========================================================
        APPROACH 1: RECURSIVE (BRUTE FORCE)
===========================================================

Idea:
    Har item ke liye 2 choices:
        1. Include karo
        2. Exclude karo

Base Case:
    if(n == 0 || W == 0) return 0;

Time Complexity:
    O(2^n) -> exponential (slow)
*/

int knapsackRecursive(int wt[], int val[], int W, int n) {

    // Base Case
    if (n == 0 || W == 0) {
        return 0;
    }

    // Choice Diagram
    // Agar current item ka weight capacity se kam ya barabar hai to include kar sakte hain
    // Include karne ke baad remaining capacity W - wt[n-1] ho jayegi
    // Exclude karne ke baad capacity same rahegi W
    // n-1 isliye kyunki array 0-based index me hai
    if (wt[n - 1] <= W) {

        // Include current item
        int include = val[n - 1] + knapsackRecursive(wt, val, W - wt[n - 1], n - 1);

        // Exclude current item
        int exclude = knapsackRecursive(wt, val, W, n - 1);

        // Return maximum profit
        return max(include, exclude);
    }

    // Agar weight zyada hai to include nahi kar sakte
    return knapsackRecursive(wt, val, W, n - 1);
}





/*
===========================================================
    APPROACH 2: MEMOIZATION 
===========================================================

Idea:
    Recursive approach me same subproblems baar-baar solve ho rahe hain
    -> unko dp array me store kar lenge

dp[n][W] ka matlab:
    "n items aur capacity W ke liye maximum profit"

Steps:
    1. dp array initialize karo -1 se
    2. agar dp[n][W] already calculated hai -> directly return
    3. warna calculate karo aur store karo

Time Complexity:
    O(n * W)

Space Complexity:
    O(n * W)
*/

// Global dp array
int dp[1001][1001];

int knapsackMemo(int wt[], int val[], int W, int n) {

    // Base Case
    if (n == 0 || W == 0) {
        return 0;
    }

    // Step 1: Check dp
    if (dp[n][W] != -1) {
        return dp[n][W];
    }

    // Step 2: Choice Diagram
    if (wt[n - 1] <= W) {

        int include = val[n - 1] + knapsackMemo(wt, val, W - wt[n - 1], n - 1);
        int exclude = knapsackMemo(wt, val, W, n - 1);

        // Store and return
        return dp[n][W] = max(include, exclude);
    }

    // Agar include nahi kar sakte
    return dp[n][W] = knapsackMemo(wt, val, W, n - 1);
}


/*
===========================================================
                Top Down Approach 
===========================================================
*/
int knapsackTopDown(int wt[], int val[], int W, int n) {

    // Create dp array
    int dp[n + 1][W + 1];

    // Base Case Initialization
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<W+1;j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // case diagram ---->  iterative 
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            // # agar current item ka weight capacity se kam ya barabar hai to include kar sakte hain
            if(wt[i-1] <= j){
                int include = val[i-1] + dp[i-1][j-wt[i-1]]; // # yah toh include karenge toh remaining capacity j-wt[i-1] hogi
                int exclude = dp[i-1][j]; // # exclude karenge toh capacity same rahegi j
                dp[i][j] = max(include, exclude);
            }else{
                // # current item ka weight zyada hai to include nahi kar sakte
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}   
 


/*
===========================================================
                    MAIN FUNCTION
===========================================================
*/

int main() {

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;

    int n = sizeof(wt) / sizeof(wt[0]);

    // Recursive Answer
    cout << "Recursive Answer: ";
    cout << knapsackRecursive(wt, val, W, n) << endl;

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Memoization Answer
    cout << "Memoization Answer: ";
    cout << knapsackMemo(wt, val, W, n) << endl;

    return 0;
}