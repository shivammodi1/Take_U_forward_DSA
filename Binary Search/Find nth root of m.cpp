// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

// Examples :

// Input: n = 3, m = 27
// Output: 3
// Explanation: 33 = 27
// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.

#include<bits/stdc++.h>
using namespace std;

//method 1: 
class Solution {
  public:
    int nthRoot(int n, int m) {
      for (int i = 1; i <= m; i++) {
            // Compute i^n
            long long power = pow(i, n);

            // If equal to m, return i
            if (power == m) return i;

            // If exceeds m, break
            if (power > m) break;
        }

        // If not found, return -1
        return -1;
    }
};

// mehtod 2:
//using binary search
class Solution {
public:
    int nthRoot(int n, int m) {
        int st = 1;
        int end = m;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Calculate mid^n carefully (use long long to avoid overflow)
            long long ans = 1;
            for (int i = 1; i <= n; i++) {
                ans *= mid;
                if (ans > m) break;  // Stop early if it exceeds m
            }

            if (ans == m) {
                return mid;  // Found exact nth root
            } 
            else if (ans > m) {
                end = mid - 1;  // mid^n too large → move left
            } 
            else {
                st = mid + 1;  // mid^n too small → move right
            }
        }

        return -1;  // If no integer nth root exists
    }
};

