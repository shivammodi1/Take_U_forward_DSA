#include <bits/stdc++.h>
using namespace std;

/*
    * Partition Equal Subset Sum
    * Array is given we need to check:
    * It is possible to parition the array into two subsets such that the sum of elements in both subsets is same.
    * Example:
    * Input: arr[] = {1, 5, 11, 5}
    * Output: true
    * Explanation: The array can be partitioned as {1, 5, 5} and {11}
    * 
    * Approach:
    * 1. Calculate the total sum of the array.
    * 2. If the total sum is odd then
    *    -> We can not divide the array into two subsets with equal sum, so return false.
    * 3. If the total sum is even then
    *  -> So this problems becomes a subset sum problem where we need to find if there is a subset with sum = total_sum/2
    *   * Time Complexity: O(n*sum)
    *  * Space Complexity: O(n*sum)
    *   * Where n is the number of elements in the array and sum is the total sum of the array.
    *   * Note: This problem is a variation of the subset sum problem.
*/

bool subsetSum(vector<int> &arr,int sum,int n){
    // initialization of dp
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
    // fill the dp table
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                // # agar current element ka value sum se kam ya barabar hai to include kar sakte hain
                bool include=dp[i-1][j-arr[i-1]]; // include current element and check for remaining sum
                bool exclude=dp[i-1][j]; // exclude current element and check for same
                dp[i][j]=include || exclude;
            }
            else{
                // agar current element ka value sum se jyada hai to include nahi kar sakte hain
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(vector<int> &nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    // agar sum odd hai to partition nahi kar sakte hain
    if(sum%2!=0){
        return false;
    }
    return subsetSum(nums,sum/2,nums.size()); // sum = total_sum/2 agar sum even hai to subset sum problem ban jata hai
}