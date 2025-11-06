// You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

// Examples:

// Input: stalls[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at stalls[0], 
// the second cow can be placed at stalls[2] and 
// the third cow can be placed at stalls[3]. 
// The minimum distance between cows in this case is 3, which is the largest among all possible ways.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // Number of stalls
        int n = arr.size();

        // Sort the stall positions
        sort(arr.begin(), arr.end());
        
        // Search space for minimum distance between cows
        int st = 0;
        int end = arr[n-1] - arr[0]; // maximum possible distance between first and last stall
        int ans;

        // Binary search to find the largest minimum distance
        while (st <= end) {
            int mid = st + (end - st) / 2; // mid represents a possible minimum distance
            
            int cow = 1; // place the first cow at the first stall
            int lastPos = arr[0]; // last placed cow position

            // Try placing the remaining cows
            for (int i = 1; i < n; i++) {
                // If current stall is at least 'mid' distance away from last placed cow
                if (arr[i] - lastPos >= mid) {
                    cow++; // place another cow
                    lastPos = arr[i]; // update last placed position
                }
            }
            
            // If we can place all cows with at least 'mid' distance
            if (cow >= k) {
                ans = mid;     // store the possible answer
                st = mid + 1;  // try for a larger distance
            } else {
                end = mid - 1; // reduce distance
            }
        }
        
        return ans; // return the largest minimum distance
    }
};
int aggressiveCows(vector<int> &stalls, int k) {
    Solution sol;
    return sol.aggressiveCows(stalls, k);
}

