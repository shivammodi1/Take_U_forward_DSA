#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if we can make 'm' bouquets in 'mid' days
    bool possibleBloom(vector<int>& Bloom, int mid, int m, int k) {
        int count = 0;  // Count of consecutive flowers ready to bloom
        int NOB = 0;    // Number of bouquets formed
        int n = Bloom.size();

        // Traverse each flower
        for (int i = 0; i < n; i++) {
            // If flower blooms on or before 'mid' day
            if (Bloom[i] <= mid) {
                count++; // Increment count of consecutive flowers
            } else {
                // When a flower is not ready, count how many bouquets formed
                NOB += (count / k);
                count = 0; // Reset count for next possible bouquet
            }
        }

        // After loop, check if last sequence can form bouquets
        NOB += (count / k);

        // Return true if we can form at least 'm' bouquets
        return NOB >= m;
    }

    // Function to find the minimum number of days to make 'm' bouquets
    int minDays(vector<int>& Bloom, int m, int k) {
        int n = Bloom.size();

        // If total flowers required > available flowers → not possible
        // Use 1LL to avoid integer overflow (convert to long long)
        if (1LL * m * k > n) {
            return -1;
        }

        int ans = -1;

        // Search space: minimum and maximum days in Bloom array
        int st = *min_element(Bloom.begin(), Bloom.end());
        int end = *max_element(Bloom.begin(), Bloom.end());

        // Binary search to find minimum day
        while (st <= end) {
            int mid = st + (end - st) / 2; // Midpoint of days

            // If it is possible to make bouquets in 'mid' days
            if (possibleBloom(Bloom, mid, m, k)) {
                ans = mid;       // Store answer
                end = mid - 1;   // Try for fewer days
            } else {
                st = mid + 1;    // Need more days
            }
        }

        // Return the minimum number of days required
        return ans;
    }
};
