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

// method 2 with binary search
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        
        // Get the size of the array
        int n = arr.size();
        
        // Binary search boundaries
        int st = 0, end = n - 1;
        
        // Perform binary search to find the position where kth missing number lies
        while (st <= end) {
            int mid = st + (end - st) / 2;  // Calculate mid index
            
            // Calculate how many numbers are missing up to arr[mid]
            // Example: if arr[mid] = 5 and mid = 2 → missing = 5 - 2 - 1 = 2
            // (We subtract 1 because array starts from number 1, not 0)
            int count_missing = arr[mid] - mid - 1;
            
            // If missing numbers till mid are less than k, move right
            if (count_missing < k) {
                st = mid + 1;
            } 
            // Otherwise, move left
            else {
                end = mid - 1;
            }
        }
        
        // After loop ends, 'st' is the number of elements present before kth missing number
        // So actual kth missing number = st + k
        return st + k;
    }
};
