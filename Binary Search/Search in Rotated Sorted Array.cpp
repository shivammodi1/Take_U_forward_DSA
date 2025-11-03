#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int mid;

        // Perform binary search on a rotated sorted array
        while (low <= high) {
            mid = (low + high) / 2;

            // If the middle element is the key, return its index
            if (arr[mid] == key)
                return mid;

            // Check if the left half [low...mid] is sorted
            else if (arr[mid] >= arr[low]) {
                // If key lies within the left sorted half
                if (arr[low] <= key && arr[mid] > key) {
                    high = mid - 1;  // search in left half
                } else {
                    low = mid + 1;   // otherwise search in right half
                }
            } 
            // Otherwise, the right half [mid...high] is sorted
            else {
                // If key lies within the right sorted half
                if (arr[mid] < key && arr[high] >= key) {
                    low = mid + 1;   // search in right half
                } else {
                    high = mid - 1;  // otherwise search in left half
                }
            }
        }

        // If the key is not found
        return -1;
    }
};
