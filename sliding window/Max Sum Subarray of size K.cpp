#include <bits/stdc++.h>
using namespace std;

// method 1: using sliding window (two pointer approach) TC: O(n) SC: O(1)

int maxSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    while (j < n)
    {
        sum += nums[j]; // expand

        // check if window size is k
        if (j - i + 1 == k)
        {
            maxSum = max(maxSum, sum); // calculate

            sum -= nums[i]; // shrink
            i++;
        }
        // agar window size k se chota hai to expand karo
        j++; // always move j
    }

    return maxSum;
}

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int ans = 0;
        int currSum = 0;

        // current sum till k window
        for (int i = 0; i < k; i++)
        {
            currSum += arr[i];
        }

        ans = currSum; // max sum

        for (int i = k; i < n; i++)
        {
            // from currSum subtract previous element and than add next element
            currSum = currSum - arr[i - k] + arr[i];
            ans = max(ans, currSum); // store maxSum
        }

        return ans;

        // for(int i=0;i<n;i++){
        //     int sum=0;
        //   for(int j=i;j<k+i && j<n;j++){
        //       sum+=arr[j];
        //   }
        //   ans = max(ans,sum);
        // }
        // return ans;
    }
};