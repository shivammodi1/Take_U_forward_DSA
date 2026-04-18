#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int ans=0;
        int currSum=0;
        
        // current sum till k window
        for(int i=0;i<k;i++){
            currSum+=arr[i];
        }
        
        ans=currSum; // max sum 
        
        for(int i=k;i<n;i++){
            // from currSum subtract previous element and than add next element
            currSum = currSum - arr[i-k] + arr[i]; 
            ans = max(ans,currSum); // store maxSum
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