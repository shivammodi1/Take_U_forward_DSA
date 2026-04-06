#include<bits/stdc++.h>
using namespace std;

/*
==================== APPROACH ====================

Problem: Minimum Subset Sum Difference

Hume ek array diya gaya hai, hume isse 2 subsets me divide karna hai
aisa ki unke sum ka difference minimum ho.

--------------------------------------------------

Step 1: Total Sum
- Sab elements ka sum nikal lo → totalSum

Step 2: Reduce Problem
- Maan lo subset1 ka sum = S1
- subset2 ka sum = totalSum - S1

Difference = |S1 - S2|
           = |S1 - (totalSum - S1)|
           = |totalSum - 2*S1|

👉 Hume aisa S1 chahiye jo difference minimum kare

--------------------------------------------------

Step 3: Subset Sum DP
- Find all possible subset sums using DP
- dp[i][j] = true → agar first i elements se sum j ban sakta hai

--------------------------------------------------

Step 4: Optimization
- Sirf totalSum/2 tak check karo
- Kyuki uske baad values mirror ho jati hain

--------------------------------------------------

Step 5: Answer
- mini = min(mini, totalSum - 2*s)

==================================================
*/

int minSubsetSumDifference(vector<int>& arr) {
    int n = arr.size();
    
    // Step 1: total sum
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }

    // Step 3: DP table
    vector<vector<bool>> dp(n+1, vector<bool>(totalSum+1, false));

    // Initialization
    // sum = 0 is always possible
    for(int i = 0; i <= n; i++){
        dp[i][0] = true;
    }

    // Fill DP table
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= totalSum; j++){
            if(arr[i-1] <= j){
                bool include = dp[i-1][j-arr[i-1]];
                bool exclude = dp[i-1][j];
                dp[i][j] = include || exclude;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Step 5: Find minimum difference
    int mini = INT_MAX;

    for(int s = 0; s <= totalSum/2; s++){
        if(dp[n][s]){
            mini = min(mini, totalSum - 2*s);
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {1, 6, 11, 5};

    int ans = minSubsetSumDifference(arr);

    cout << "Minimum Subset Sum Difference: " << ans << endl;

    return 0;
}