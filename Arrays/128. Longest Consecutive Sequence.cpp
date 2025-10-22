#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    // If the array is empty, there is no consecutive sequence
    if (nums.empty())
        return 0;

    // Sort the array to bring consecutive numbers next to each other
    sort(nums.begin(), nums.end());

    int longest = 1; // To store the length of the longest sequence
    int current = 1; // To store the length of the current consecutive sequence

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            // If the current number is same as previous, skip it
            // because duplicates should not break the consecutive sequence
            continue;
        }
        else if (nums[i] == nums[i - 1] + 1)
        {
            // If current number is consecutive, increment current sequence length
            current++;
        }
        else
        {
            // If not consecutive, reset current sequence length
            current = 1;
        }

        // Update longest if current sequence is greater
        longest = max(longest, current);
    }

    return longest; // Return the length of the longest consecutive sequence
}

