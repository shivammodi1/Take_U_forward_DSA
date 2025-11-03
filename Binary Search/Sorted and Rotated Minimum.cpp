#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize start and end pointers
        int st = 0;
        int end = n - 1;

        // Initialize answer as the first element (default case)
        int ans = arr[0];

        // Perform binary search to find the minimum element
        while (st <= end) {
            // Find the middle index
            int mid = st + (end - st) / 2;

            // If middle element is greater than or equal to the first element,
            // it means the minimum element lies in the right half
            if (arr[mid] >= arr[0]) {
                st = mid + 1;
            } 
            // Otherwise, the minimum element lies in the left half (including mid)
            else {
                ans = arr[mid]; // Update answer
                end = mid - 1;
            }
        }

        // Return the minimum element found
        return ans;
    }
};
