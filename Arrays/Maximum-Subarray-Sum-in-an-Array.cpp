#include <bits/stdc++.h>
using namespace std;

// method 1:
// TC-> O(n^2)
int maxSubSum(vector<int>&nums){
    int n=nums.size();
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[i];
        }
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

// Kadane's Algorithm
// TC ->O(n)
int maxSubArray(vector<int> &nums)
{
    int n=nums.size();
    int preSum=0;
    int maxSum=INT_MIN;

    for(int i=0;i<n;i++){
        // here just calculation prefix sum
        preSum+=nums[i];

        if(preSum>maxSum){
            // storing maxSum means maximum sum till know
            maxSum=preSum;
        }

        if(preSum<0){
            // when ever sum become negative 
            // then reintialize to 0
            preSum=0;
        }
    }
    return maxSum;
}

int main()
{
    int n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxSum = maxSubArray(arr);
    cout<<"Maximum sum: "<<maxSum;
}