// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.
// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.


#include <bits/stdc++.h>
using namespace std;
// method 1 without binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>ans;
        int n=arr.size();

        int m = *max_element(arr.begin(),arr.end());
        
        int j=0;
        for(int i=1;i<=k+m;i++){
            if(j<n && i==arr[j]){
                j++;
            }
            else {
                ans.push_back(i);
            }
        }

        return ans[k-1];
    }
};