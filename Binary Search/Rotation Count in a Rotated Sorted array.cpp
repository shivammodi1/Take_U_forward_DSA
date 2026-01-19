// Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
// Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
// After 1st Rotation : [9, 2, 4, 6]
// After 2nd Rotation : [6, 9, 2, 4]

// Examples:

// Input: arr[] = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // This function returns the number of times a sorted array has been rotated.
        // The number of rotations is equal to the index of the minimum element.

        int n = arr.size();   // Get the size of the array
        int st = 0;           // Initialize start pointer
        int end = n - 1;      // Initialize end pointer
        int ans = 0;          // Variable to store index of minimum element

        // Apply binary search to find the index of the smallest element
        while (st <= end) {
            int mid = st + (end - st) / 2;  // Calculate mid index safely

            // If middle element is greater than or equal to the first element,
            // then we are in the left (sorted) part of the array,
            // so the rotation point must be in the right half.
            if (arr[mid] >= arr[0]) {
                st = mid + 1;
            } 
            // Otherwise, we are in the right (rotated) part,
            // so this mid might be the minimum — store it and move left.
            else {
                ans = mid;
                end = mid - 1;
            }
        }

        // The index 'ans' represents the number of rotations
        return ans;
    }
};

