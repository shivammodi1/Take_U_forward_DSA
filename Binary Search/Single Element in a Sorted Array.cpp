// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // If only one element is present, return it directly
        if (n == 1) {
            return nums[0];
        }

        // Check if the first element is unique
        if (nums[0] != nums[1]) {
            return nums[0];
        }

        // Check if the last element is unique
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int st = 1;        // start from index 1 (since 0 is already checked)
        int end = n - 2;   // end at n-2 (since n-1 is already checked)

        // Binary search for the single element
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If the current element is not equal to neighbors, it’s the answer
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // If mid is even and its pair is on the right,
            // the single element lies on the right half
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                st = mid + 1;
            }
            // Otherwise, the single element lies on the left half
            else {
                end = mid - 1;
            }
        }

        // Fallback (should never reach here)
        return -1;
    }
};
