#include <bits/stdc++.h>
using namespace std;

/*
* Count Subsets whose sum is equal to target sum

* Hume 1 array given h and 1 target sum given hai
* Now hume count krna subset jinka sum target sum ke barabar hai
* Example: h = [1, 2, 3, 3], target sum = 6
* Output: 3
* Explanation: The subsets are [1, 2, 3], [1, 3, 2], [2, 3, 1]
*/


/*
* Approach: Dynamic Programming
* 1. So in this problem hume abb count krna hai subset jinka sum target sum ke barabar hai
* 2. So yeh question 0-1 Knapsack problem ka variation hai, jisme hume count krna hai subset jinka sum target sum ke barabar hai
* 3. So iss problem ko solve krne ke liye hume ek 2D array dp[n+1][target+1] banani hogi, jisme n array ka size hai aur target sum hai
* 4. Base case: dp[0][0] = 1, dp[0][j] = 0 for j > 0, dp[i][0] = 1 for i > 0
* 5. Recurrence relation:
*    if(arr[i-1] <= j){
*        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
*    }
*    else{
*        dp[i][j] = dp[i-1][j];
*    }
* 6. Finally, dp[n][target] will give us the count of subsets whose sum is equal to target sum
*/

int countSubssets(vector<int> &arr, int target){
    int n = arr.size();
    int dp[n+1][target+1];
    // Base case
    for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}