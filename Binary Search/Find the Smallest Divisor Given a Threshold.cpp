#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Calculates the sum of all elements in arr after dividing by 'mid' and rounding up.
     * The parameter 't' (threshold) is not used for calculation but is kept for the original signature.
     */
    int generateSum(vector<int> &arr, int mid, int t)
    {
        long long sum = 0; // Use long long for sum to prevent potential overflow, although 'int' might suffice based on constraints.

        for (int num : arr)
        {
            // Correct implementation of ceiling division: ceil(a / b)

            // 1. Integer division gives the floor (whole number part).
            sum += num / mid;

            // 2. If there is a remainder, we must increment the sum to round up.
            if (num % mid != 0)
            {
                sum++;
            }

            // Alternative efficient way: sum += (num + mid - 1) / mid;
        }
        return (int)sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        // 1. Define the Search Range for the Divisor
        // The smallest possible divisor is 1.
        int st = 1;

        // The largest necessary divisor is the maximum element in nums.
        int end = *max_element(nums.begin(), nums.end());

        // Initialize the answer. Since an answer is guaranteed, we can start with the upper bound.
        int ans = end;

        // 2. Binary Search
        while (st <= end)
        {

            // Correct midpoint calculation to prevent overflow and find the middle divisor.
            int mid = st + (end - st) / 2;

            // Calculate the total sum for the current divisor 'mid'.
            int current_sum = generateSum(nums, mid, threshold);

            // 3. Adjust Search Pointers
            if (current_sum <= threshold)
            {
                // 'mid' is a valid divisor. Store it as a potential answer.
                ans = mid;
                // Try to find an even smaller valid divisor by searching the left half.
                end = mid - 1;
            }
            else
            {
                // 'mid' is too small (sum is too high). Need a larger divisor.
                // Search in the right half.
                st = mid + 1;
            }
        }

        return ans;
    }
};

/*
// Example Usage (for testing purposes)
int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Smallest Divisor for [1,2,5,9] with T=6: " << s.smallestDivisor(nums1, threshold1) << endl; // Output: 5

    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Smallest Divisor for [44,22,33,11,1] with T=5: " << s.smallestDivisor(nums2, threshold2) << endl; // Output: 44

    return 0;
}
*/